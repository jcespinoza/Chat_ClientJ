/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Fri 4. Dec 02:04:02 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include < QAction>
#include < QApplication>
#include < QButtonGroup>
#include < QGridLayout>
#include < QHeaderView>
#include < QLabel>
#include < QLineEdit>
#include < QListWidget>
#include < QMainWindow>
#include < QMenuBar>
#include < QPushButton>
#include < QStatusBar>
#include < QTabWidget>
#include < QTextEdit>
#include < QToolBar>
#include < QWidget>
//#include <QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_Mensaje;
    QListWidget *listWidget;
    QLineEdit *lineEdit_Server;
    QLineEdit *lineEdit_Port;
    QPushButton *btnConnect;
    QPushButton *btnDisconnect;
    QLineEdit *lineEdit_Nick;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *tab_2;
    //QWebView *webView;
    QLineEdit *lineEdit;
    QPushButton *btnSalir;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(923, 706);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 891, 631));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(560, 180, 321, 381));
        textEdit->setReadOnly(true);
        lineEdit_Mensaje = new QLineEdit(tab);
        lineEdit_Mensaje->setObjectName(QString::fromUtf8("lineEdit_Mensaje"));
        lineEdit_Mensaje->setGeometry(QRect(570, 570, 301, 20));
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(760, 10, 111, 161));
        lineEdit_Server = new QLineEdit(tab);
        lineEdit_Server->setObjectName(QString::fromUtf8("lineEdit_Server"));
        lineEdit_Server->setGeometry(QRect(20, 30, 221, 20));
        lineEdit_Port = new QLineEdit(tab);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));
        lineEdit_Port->setGeometry(QRect(250, 30, 61, 20));
        btnConnect = new QPushButton(tab);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(320, 10, 75, 23));
        btnDisconnect = new QPushButton(tab);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));
        btnDisconnect->setEnabled(false);
        btnDisconnect->setGeometry(QRect(320, 30, 75, 23));
        lineEdit_Nick = new QLineEdit(tab);
        lineEdit_Nick->setObjectName(QString::fromUtf8("lineEdit_Nick"));
        lineEdit_Nick->setGeometry(QRect(60, 10, 113, 20));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 31, 16));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 60, 541, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
//        webView = new QWebView(tab_2);
//        webView->setObjectName(QString::fromUtf8("webView"));
//        webView->setGeometry(QRect(20, 50, 841, 491));
//        webView->setUrl(QUrl("http://www.google.hn/"));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 10, 481, 20));
        tabWidget->addTab(tab_2, QString());
        btnSalir = new QPushButton(centralWidget);
        btnSalir->setObjectName(QString::fromUtf8("btnSalir"));
        btnSalir->setGeometry(QRect(810, 0, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 0, 221, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 0, 0);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 923, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0 ));
        btnConnect->setText(QApplication::translate("MainWindow", "Conectarse", 0 ));
        btnDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0 ));
        label->setText(QApplication::translate("MainWindow", "NICK:", 0 ));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Chat", 0 ));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Browser", 0 ));
        btnSalir->setText(QApplication::translate("MainWindow", "Salir", 0 ));
        label_2->setText(QApplication::translate("MainWindow", "CHICKENPOX GAME", 0 ));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
