#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QString data;
    void setdata(QString data);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    
private slots:
    void on_commandLinkButton_clicked();
    void say();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
