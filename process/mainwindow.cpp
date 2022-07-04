#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]创建一个进程对象
    QProcess *process = new QProcess(this);

    // [2]程序路径
    QString path("bash");

    // [3]设置命令,参数
    QStringList arguments;
    arguments << "-c" << "cat ../file_io/*.txt";

    // [4]启动并设置参数
    process->start(path, arguments);

    // [5]输出命令执行后得到的信息
    /*
     * 函数原型:connect(const QObject *sender, PointerToMemberFunction signal, Functor functor)
     * [=] () { } :这是一个lambda函数，原型是[capture list] (parameter list) -> return type { function body }
     *             其中，[capture list]：捕捉列表
     *                  (parameter list)：参数列表
     *                  ->return-type：返回类型，在不需要返回值的时候也可以连同符号”->”一起省略
     *             另外，[=]表示值传递方式捕捉所有父作用域的变量（包括this）
     *
    */
    connect(process, &QProcess::readyRead, [=] () {
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QString outinformation = codec->toUnicode(process->readAll());
        qDebug() << outinformation;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
