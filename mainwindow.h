#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>

#include <QVBoxLayout>
#include "views/drawingpapereditor/drawingpapereditor.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUi(QMainWindow *MainWindow);
    void retranslateUi(QMainWindow *MainWindow);

private:


    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
};
#endif // MAINWINDOW_H
