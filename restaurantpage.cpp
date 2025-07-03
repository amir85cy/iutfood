#include "restaurantpage.h"
#include "shoppage.h"
#include "ui_restaurantpage.h"

#include "global.h"
#include "cart.h"
#include "panel.h"
#include "history.h"
#include "peygiri.h"

#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QItemSelectionModel>

Restaurantpage::Restaurantpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Restaurantpage)
{
    ui->setupUi(this);
    loadRestaurantInfo();
    loadData();
    connect(ui->cartbtn, &QPushButton::clicked, this, [=]() {
        cart *cartwin = new cart();
        cartwin->setAttribute(Qt::WA_DeleteOnClose);
        cartwin->show();
        this->close();
    });
    connect(ui->panelbtn, &QPushButton::clicked, this, [=]() {
        panel *panelwin = new panel(loggedInUsername);
        panelwin->setAttribute(Qt::WA_DeleteOnClose);
        panelwin->show();
        this->close();
    });
    connect(ui->historybtn, &QPushButton::clicked, this, [=]() {
        history *historywin = new history();
        historywin->setAttribute(Qt::WA_DeleteOnClose);
        historywin->show();
        this->close();
    });
    connect(ui->orderbtn, &QPushButton::clicked, this, [=]() {
        peygiri *peygiriwin = new peygiri();
        peygiriwin->setAttribute(Qt::WA_DeleteOnClose);
        peygiriwin->show();
        this->close();
    });
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        ShopPage *shopwin = new ShopPage();
        shopwin->setAttribute(Qt::WA_DeleteOnClose);
        shopwin->show();
        this->close();
    });
    connect(ui->likebtn, &QPushButton::clicked, this, &Restaurantpage::likeSelectedComment);
    // تنظیم آیکون دکمه‌ها
    ui->panelbtn->setIcon(QIcon(":/new/images/usericon.svg"));
    ui->panelbtn->setIconSize(QSize(32, 32));
    ui->panelbtn->setText("");

    ui->historybtn->setIcon(QIcon(":/new/images/historyicon.png"));
    ui->historybtn->setIconSize(QSize(32, 32));
    ui->historybtn->setText("");

    ui->orderbtn->setIcon(QIcon(":/new/images/ordertrackingicon.png"));
    ui->orderbtn->setIconSize(QSize(32, 32));
    ui->orderbtn->setText("");

    ui->cartbtn->setIcon(QIcon(":/new/images/carticon.png"));
    ui->cartbtn->setIconSize(QSize(32, 32));
    ui->cartbtn->setText("");
    connect(ui->addtocartbtn, &QPushButton::clicked, this, &Restaurantpage::addSelectedFoodToCart);
    QString restaurantusername;
    // بارگذاری داده‌ها از دیتابیس
    loadData();
}

Restaurantpage::~Restaurantpage()
{
    delete ui;
}
void Restaurantpage::loadRestaurantInfo()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "RestInfoConnection");
    db.setDatabaseName("restaurant.db");

    if (!db.open()) {
        qDebug() << "Database Error:" << db.lastError().text();
        QMessageBox::critical(this, "خطا", "اتصال به دیتابیس برقرار نشد.");
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT name, address, rate, type,username FROM restaurant WHERE ID = :id");
    query.bindValue(":id", selectedRestaurantId);
    qDebug()<<selectedRestaurantId;
    if (!query.exec()) {
        qDebug() << "Query Error:" << query.lastError().text();
        QMessageBox::critical(this, "خطا", "خواندن اطلاعات رستوران با مشکل مواجه شد.");
        return;
    }

    if (query.next()) {
        QString name = query.value("name").toString();
        QString address = query.value("address").toString();
        int rate = query.value("rate").toInt();
        QString type = query.value("type").toString();
        restaurantusername = query.value("username").toString();
        qDebug()<<restaurantusername;
        // ست کردن روی labelها (به فرض این labelها در UI تعریف شدن)
        ui->label_3->setText(name); // عنوان بزرگ بالا
        // می‌تونی بقیه اطلاعات رو هم در لیبل‌های جدا یا جای مناسب بذاری
        //qDebug() << "Loaded restaurant:" << name << address << rate << type;
    } else {
        QMessageBox::warning(this, "یافت نشد", "رستورانی با این ID پیدا نشد.");
    }

    db.close();
}
void Restaurantpage::loadData()
{
    // بارگذاری غذاها از foods.db
    QSqlDatabase dbFoods = QSqlDatabase::addDatabase("QSQLITE", "foods_connection");
    dbFoods.setDatabaseName("foods.db");
    qDebug()<<restaurantusername;
    if (!dbFoods.open()) {
        QMessageBox::warning(this, "خطا", "باز کردن دیتابیس foods.db امکان‌پذیر نیست!");
        return;
    }

    QSqlQuery queryFoods(dbFoods);
    queryFoods.prepare("SELECT foodname, foodtype, rating, price FROM foods WHERE restaurantusername = :username");
    queryFoods.bindValue(":username", restaurantusername);

    if (!queryFoods.exec()) {
        QMessageBox::warning(this, "خطا", "اجرای کوئری غذاها موفق نبود: " + queryFoods.lastError().text());
        dbFoods.close();
        QSqlDatabase::removeDatabase("foods_connection");
        return;
    }

    // بررسی وجود غذا
    if (!queryFoods.next()) {
        QMessageBox::information(this, "بدون غذا", "این رستوران غذایی برای فروش ندارد.");
        dbFoods.close();
        QSqlDatabase::removeDatabase("foods_connection");
        return;
    }

    QStandardItemModel *foodModel = new QStandardItemModel(this);
    foodModel->setHorizontalHeaderLabels({" نام غذا", "نوع غذا", "نمره غذا", " قیمت"});

    // سطر اول
    QList<QStandardItem*> firstRow;
    firstRow.append(new QStandardItem(queryFoods.value(0).toString()));
    firstRow.append(new QStandardItem(queryFoods.value(1).toString()));
    firstRow.append(new QStandardItem(queryFoods.value(2).toString()));
    firstRow.append(new QStandardItem(queryFoods.value(3).toString()));
    foodModel->appendRow(firstRow);

    // سطرهای بعدی
    while (queryFoods.next()) {
        QList<QStandardItem*> rowItems;
        rowItems.append(new QStandardItem(queryFoods.value(0).toString()));
        rowItems.append(new QStandardItem(queryFoods.value(1).toString()));
        rowItems.append(new QStandardItem(queryFoods.value(2).toString()));
        rowItems.append(new QStandardItem(queryFoods.value(3).toString()));
        foodModel->appendRow(rowItems);
    }

    ui->foodstable->setModel(foodModel);
    ui->foodstable->resizeColumnsToContents();
    ui->foodstable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->foodstable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->foodstable->setEditTriggers(QAbstractItemView::NoEditTriggers);


    dbFoods.close();
    QSqlDatabase::removeDatabase("foods_connection");


    // بارگذاری کامنت‌ها از comments.db
    QSqlDatabase dbComments = QSqlDatabase::addDatabase("QSQLITE", "comments_connection");
    dbComments.setDatabaseName("comments.db");

    if (!dbComments.open()) {
        QMessageBox::warning(this, "خطا", "باز کردن دیتابیس comments.db امکان‌پذیر نیست!");
        return;
    }

    QSqlQuery queryComments(dbComments);
    queryComments.prepare("SELECT username, comment, likes FROM comments WHERE restaurantusername = :username");
    queryComments.bindValue(":username", restaurantusername);

    if (!queryComments.exec()) {
        QMessageBox::warning(this, "خطا", "اجرای کوئری کامنت‌ها موفق نبود: " + queryComments.lastError().text());
        dbComments.close();
        QSqlDatabase::removeDatabase("comments_connection");
        return;
    }

    QStandardItemModel *commentModel = new QStandardItemModel(this);
    commentModel->setHorizontalHeaderLabels({"نام کاربر", "نظر", "تعداد لایک"});

    while (queryComments.next()) {
        QList<QStandardItem*> rowItems;
        rowItems.append(new QStandardItem(queryComments.value(0).toString())); // username
        rowItems.append(new QStandardItem(queryComments.value(1).toString())); // comment
        rowItems.append(new QStandardItem(queryComments.value(2).toString())); // likes
        commentModel->appendRow(rowItems);
    }

    ui->commenttable->setModel(commentModel);
    ui->commenttable->resizeColumnsToContents();
    ui->commenttable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->commenttable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->commenttable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    dbComments.close();
    QSqlDatabase::removeDatabase("comments_connection");
}


void Restaurantpage::addSelectedFoodToCart()
{
    QItemSelectionModel *selectionModel = ui->foodstable->selectionModel();

    if (!selectionModel->hasSelection()) {
        QMessageBox::information(this, "توجه", "لطفاً یک غذا را انتخاب کنید.");
        return;
    }

    QModelIndex selectedIndex = selectionModel->selectedRows().first();
    QString foodName       = ui->foodstable->model()->index(selectedIndex.row(), 0).data().toString(); // نام غذا
    QString foodPriceStr   = ui->foodstable->model()->index(selectedIndex.row(), 3).data().toString(); // قیمت
    QString restaurantName = ui->label_3->text();
    int price = foodPriceStr.toInt();
    int count = 1;
    QFile file("cart.txt");

    // داده‌های جدید را نگه می‌داریم
    QStringList lines;
    bool found = false;

    // خواندن فایل
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (line.isEmpty()) continue;

            QStringList parts = line.split(',');
            if (parts.size() != 4) continue;

            if (parts[0] == foodName && parts[1] == restaurantName) {
                // غذا قبلاً اضافه شده: افزایش تعداد
                int oldCount = parts[2].toInt();
                int newCount = oldCount + count;
                parts[2] = QString::number(newCount);
                line = parts.join(',');
                found = true;
            }

            lines << line;
        }
        file.close();
    }

    // اگر غذا نبود، اضافه کنیم
    if (!found) {
        lines << QString("%1,%2,%3,%4").arg(foodName, restaurantName).arg(count).arg(price);
    }

    // بازنویسی فایل
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const QString &line : lines)
            out << line << "\n";
        file.close();
        QMessageBox::information(this, "موفق", "غذا با موفقیت به سبد خرید اضافه شد.");
    } else {
        QMessageBox::warning(this, "خطا", "نوشتن در فایل cart.txt ممکن نیست.");
    }
}
void Restaurantpage::likeSelectedComment()
{
    QItemSelectionModel *selectionModel = ui->commenttable->selectionModel();

    if (!selectionModel->hasSelection()) {
        QMessageBox::information(this, "توجه", "لطفاً یک کامنت را انتخاب کنید.");
        return;
    }

    QModelIndex selectedIndex = selectionModel->selectedRows().first();
    QString username = ui->commenttable->model()->index(selectedIndex.row(), 0).data().toString();

    // اتصال به دیتابیس
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "like_connection");
    db.setDatabaseName("comments.db");

    if (!db.open()) {
        QMessageBox::warning(this, "خطا", "باز کردن دیتابیس comments.db ممکن نیست.");
        return;
    }

    QSqlQuery query(db);
    query.prepare(R"(
        UPDATE comments
        SET likes = likes + 1
        WHERE username = :username AND restaurantusername = :restuser
    )");
    query.bindValue(":username", username);
    query.bindValue(":restuser", restaurantusername);

    if (!query.exec()) {
        QMessageBox::warning(this, "خطا", "لایک کردن با خطا مواجه شد:\n" + query.lastError().text());
        db.close();
        QSqlDatabase::removeDatabase("like_connection");
        return;
    }

    db.close();
    QSqlDatabase::removeDatabase("like_connection");

    QMessageBox::information(this, "موفق", "کامنت لایک شد!");

    // دوباره بارگذاری شود
    loadData();
}
