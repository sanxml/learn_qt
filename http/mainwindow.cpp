#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [5]发送http请求
    startRequest( QUrl("http://www.bing.com"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// [6]发起HTTP请求
/*
 * 功能描述：发送HTTP请求，并与请求响应的槽绑定
 *  @param requestedUrl：请求需要的URL地址
 */
void MainWindow::startRequest(const QUrl &requestedUrl)
{
    url = requestedUrl;
    manager = new QNetworkAccessManager(this);
    req.setUrl(url);
    req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    req.setRawHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");
    req.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.198 Safari/537.36");
    reply = manager->get(req);
    connect(reply, &QNetworkReply::finished, this, &MainWindow::replyFinished);
}

// [7]获取HTTP的请求响应
/*
 * 功能描述：HTTP请求后，接收服务器的请求信息
 * 1 检测请求响应是否有错误
 * 2 获取请求响应的状态码
 * 3 判断是否需要重定向
 *   - 不需要，则保存数据
 *   - 需要重定向，则获取重定向的URL，然后通过这个URL再次发起请求
 */
void MainWindow::replyFinished()
{

    // <1>判断有没有错误
    if (reply->error())
    {
        qDebug() << reply->errorString();
        reply->deleteLater();
        return;
    }

    // <2>检测状态码
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "statusCode:" << statusCode;

    // <3>判断是否需要重定向
    if (statusCode >= 200 && statusCode < 300)
    {
        // ok

        // 准备读数据
        QTextCodec *codec = QTextCodec::codecForName("utf8");
        QString all = codec->toUnicode(reply->readAll());
        qDebug() << all;

        // 保存HTTP响应内容
        // 组装保存的文件名 文件名格式： 路径/年_月_日 小时_分_秒 httpfile.html
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy_MM_dd hh_mm_ss");
        QString filePath = "/home/geo/Desktop/learn_qt/http";
        QString fileName = filePath + '/' + current_date + " httpfile" + ".html";

        QFile file(fileName);
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            qDebug() << "file open error!";
            return;
        }
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << all << endl;
        file.close();

        // 数据读取完成之后，清除reply
        reply->deleteLater();
        reply = nullptr;
    }
    else if (statusCode >= 300 && statusCode < 400)
    {
        // redirect

        // 获取重定向信息
        const QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
        // 检测是否需要重定向，如果不需要则读数据
        if (!redirectionTarget.isNull())
        {
            const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());

            reply->deleteLater();
            reply = nullptr;

            startRequest(redirectedUrl);
            qDebug() << "http redirect to " << redirectedUrl.toString();
            return;
        }
    }
}