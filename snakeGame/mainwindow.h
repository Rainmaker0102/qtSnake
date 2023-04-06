#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_easyRadioButton_clicked();

    void on_normalRadioButton_clicked();

    void on_hardRadioButton_clicked();

    void on_singleplayerRadioButton_clicked();

    void on_multiplayerRadioButton_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
