/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_URL;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QListWidget *lw_device;
    QGroupBox *groupBox_2;
    QLineEdit *le_url;
    QPushButton *pb_get;
    QLabel *label;
    QLineEdit *le_name;
    QLineEdit *le_mac;
    QCheckBox *cb_name;
    QCheckBox *cb_mac;
    QGroupBox *groupBox_3;
    QTextBrowser *tb_msg;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(722, 386);
        action_URL = new QAction(MainWindow);
        action_URL->setObjectName(QString::fromUtf8("action_URL"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 141, 321));
        lw_device = new QListWidget(groupBox);
        lw_device->setObjectName(QString::fromUtf8("lw_device"));
        lw_device->setGeometry(QRect(0, 20, 141, 301));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(160, 10, 551, 101));
        le_url = new QLineEdit(groupBox_2);
        le_url->setObjectName(QString::fromUtf8("le_url"));
        le_url->setGeometry(QRect(120, 20, 301, 20));
        pb_get = new QPushButton(groupBox_2);
        pb_get->setObjectName(QString::fromUtf8("pb_get"));
        pb_get->setGeometry(QRect(440, 20, 75, 23));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 54, 12));
        le_name = new QLineEdit(groupBox_2);
        le_name->setObjectName(QString::fromUtf8("le_name"));
        le_name->setGeometry(QRect(130, 60, 121, 20));
        le_mac = new QLineEdit(groupBox_2);
        le_mac->setObjectName(QString::fromUtf8("le_mac"));
        le_mac->setGeometry(QRect(350, 60, 121, 20));
        cb_name = new QCheckBox(groupBox_2);
        cb_name->setObjectName(QString::fromUtf8("cb_name"));
        cb_name->setGeometry(QRect(50, 60, 71, 21));
        cb_mac = new QCheckBox(groupBox_2);
        cb_mac->setObjectName(QString::fromUtf8("cb_mac"));
        cb_mac->setGeometry(QRect(270, 64, 71, 16));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(160, 120, 551, 211));
        tb_msg = new QTextBrowser(groupBox_3);
        tb_msg->setObjectName(QString::fromUtf8("tb_msg"));
        tb_msg->setGeometry(QRect(0, 12, 551, 201));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 722, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_URL);
        menu_2->addAction(action);
        menu_2->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_URL->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271URL", nullptr));
        action->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\266\210\346\201\257\345\210\227\350\241\250", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\350\256\276\345\244\207\345\210\227\350\241\250", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\350\256\276\345\244\207\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\256\276\345\244\207\345\210\227\350\241\250", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\216\245\345\217\243", nullptr));
        pb_get->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\216\245\345\217\243URL\357\274\232", nullptr));
        cb_name->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        cb_mac->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\345\234\260\345\235\200", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\266\210\346\201\257\345\210\227\350\241\250", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
