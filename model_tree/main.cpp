#include "mainwindow.h"
#include <QApplication>
#include <QStandardItemModel>   // 模型类
#include <QTreeView>            // 视图类

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    // step1 创建标准项模型
    QStandardItemModel model;
    // step2 获取模型的根项（Root Item），根项是不可见的
    QStandardItem *parentItem = model.invisibleRootItem();
    for (int i = 0; i < 4; ++i) {
        // step3 创建标准项
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        // step4 将创建的标准项作为根项的子项
        parentItem->appendRow(item);
        // 将创建的标准项作为新的父项
        parentItem = item;
    }

    // 创建视图
    QTreeView view;
    // 为视图设置模型
    view.setModel(&model);
    // 显示视图
    view.show();

    return a.exec();
}
