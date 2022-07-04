#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]����һ�����̶���
    QProcess *process = new QProcess(this);

    // [2]����·��
    QString path("bash");

    // [3]��������,����
    QStringList arguments;
    arguments << "-c" << "cat ../file_io/*.txt";

    // [4]���������ò���
    process->start(path, arguments);

    // [5]�������ִ�к�õ�����Ϣ
    /*
     * ����ԭ��:connect(const QObject *sender, PointerToMemberFunction signal, Functor functor)
     * [=] () { } :����һ��lambda������ԭ����[capture list] (parameter list) -> return type { function body }
     *             ���У�[capture list]����׽�б�
     *                  (parameter list)�������б�
     *                  ->return-type���������ͣ��ڲ���Ҫ����ֵ��ʱ��Ҳ������ͬ���š�->��һ��ʡ��
     *             ���⣬[=]��ʾֵ���ݷ�ʽ��׽���и�������ı���������this��
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
