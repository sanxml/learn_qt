#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [5]����http����
    startRequest( QUrl("http://www.bing.com"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// [6]����HTTP����
/*
 * ��������������HTTP���󣬲���������Ӧ�Ĳ۰�
 *  @param requestedUrl��������Ҫ��URL��ַ
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

// [7]��ȡHTTP��������Ӧ
/*
 * ����������HTTP����󣬽��շ�������������Ϣ
 * 1 ���������Ӧ�Ƿ��д���
 * 2 ��ȡ������Ӧ��״̬��
 * 3 �ж��Ƿ���Ҫ�ض���
 *   - ����Ҫ���򱣴�����
 *   - ��Ҫ�ض������ȡ�ض����URL��Ȼ��ͨ�����URL�ٴη�������
 */
void MainWindow::replyFinished()
{

    // <1>�ж���û�д���
    if (reply->error())
    {
        qDebug() << reply->errorString();
        reply->deleteLater();
        return;
    }

    // <2>���״̬��
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "statusCode:" << statusCode;

    // <3>�ж��Ƿ���Ҫ�ض���
    if (statusCode >= 200 && statusCode < 300)
    {
        // ok

        // ׼��������
        QTextCodec *codec = QTextCodec::codecForName("utf8");
        QString all = codec->toUnicode(reply->readAll());
        qDebug() << all;

        // ����HTTP��Ӧ����
        // ��װ������ļ��� �ļ�����ʽ�� ·��/��_��_�� Сʱ_��_�� httpfile.html
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

        // ���ݶ�ȡ���֮�����reply
        reply->deleteLater();
        reply = nullptr;
    }
    else if (statusCode >= 300 && statusCode < 400)
    {
        // redirect

        // ��ȡ�ض�����Ϣ
        const QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
        // ����Ƿ���Ҫ�ض����������Ҫ�������
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