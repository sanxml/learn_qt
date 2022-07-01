#include "mainwindow.h"
#include <QApplication>
#include <QStandardItemModel>   // ģ����
#include <QTreeView>            // ��ͼ��

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    // step1 ������׼��ģ��
    QStandardItemModel model;
    // step2 ��ȡģ�͵ĸ��Root Item���������ǲ��ɼ���
    QStandardItem *parentItem = model.invisibleRootItem();
    for (int i = 0; i < 4; ++i) {
        // step3 ������׼��
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        // step4 �������ı�׼����Ϊ���������
        parentItem->appendRow(item);
        // �������ı�׼����Ϊ�µĸ���
        parentItem = item;
    }

    // ������ͼ
    QTreeView view;
    // Ϊ��ͼ����ģ��
    view.setModel(&model);
    // ��ʾ��ͼ
    view.show();

    return a.exec();
}
