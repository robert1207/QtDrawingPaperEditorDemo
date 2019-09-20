#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    QVBoxLayout *centralLayout;
    centralLayout = new QVBoxLayout(centralwidget);//this layout represent the layout of "centralwidget"
    centralLayout->setObjectName(QString::fromUtf8("centralLayout"));

    QtDrawingPaperEditor *drawing_paper_editor;
    drawing_paper_editor = new QtDrawingPaperEditor(centralwidget);
    drawing_paper_editor->setObjectName(QString::fromUtf8("drawing_paper_editor"));
    centralLayout->addWidget(drawing_paper_editor);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupUi(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 600);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    MainWindow->setCentralWidget(centralwidget);

    //MENU
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    MainWindow->setMenuBar(menubar);
    //STATUS
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
} // setupUi

void MainWindow::retranslateUi(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
} // retranslateUi

