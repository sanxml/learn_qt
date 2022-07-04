#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTextCodec>

#include <QFile>
#include <QTextStream>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QUrl url;
    QNetworkRequest req;
    QNetworkReply *reply;
    QNetworkAccessManager *manager;

private slots:
    void startRequest(const QUrl &requestedUrl);
    void replyFinished();
};

#endif // MAINWINDOW_H
