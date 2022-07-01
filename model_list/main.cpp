#include "mainwindow.h"
#include <QApplication>
#include <QStringListModel>     // ģ����
#include <QListView>            // ��ͼ��

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    // ׼���ַ����б�����
    QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    // �����б�ģ��
    QStringListModel *model = new QStringListModel(numbers);

    // ������ͼ
    QListView *view = new QListView;
    // Ϊ��ͼ����ģ��
    view->setModel(model);
    // ��ʾ��ͼ
    view->show();

    return a.exec();
}
