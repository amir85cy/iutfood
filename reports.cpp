#include "reports.h"
#include "ui_reports.h"
#include "adminpage.h"

Reports::Reports(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reports)
{
    ui->setupUi(this);
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        Adminpage *adminWin = new Adminpage();
        adminWin->setAttribute(Qt::WA_DeleteOnClose);
        adminWin->show();
        this->close();
    });
    ui->orderlist->setStyleSheet(R"(
        QListWidget {
            border: 2px solid #aaaaaa;
            border-radius: 12px;
            border-image: url(:/new/images/listbg.jpg);
            font-family:iranyekan;
            padding: 30px;
        }

        QListWidget::item {
            background-color: #ffb48a;
            padding: 0px;
            border-radius: 8px;
            color: #333;
        }
        QListWidget::item:selected {
            background-color: #3399ff;
            color: white;
        }
        QListWidget::item:hover {
            background-color: #3399ff;
            color: black;
        }
        )");
    ui->reportlist->setStyleSheet(R"(
        QListWidget {
            border: 2px solid #aaaaaa;
            border-radius: 12px;
            border-image: url(:/new/images/listbg.jpg);
            font-family:iranyekan;
            padding: 30px;
        }

        QListWidget::item {
            background-color: #ffb48a;
            margin: 4px;
            padding: 8px;
            border-radius: 8px;
            color: #333;
        }

        QListWidget::item:selected {
            background-color: #3399ff;
            color: white;
        }

        QListWidget::item:hover {
            background-color: #3399ff;
            color: black;
        }
        )");
}

Reports::~Reports()
{
    delete ui;
}
