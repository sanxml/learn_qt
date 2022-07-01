#include "mainwindow.h"
#include <QApplication>
#include <QStringListModel>     // 模型类
#include <QListView>            // 视图类

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    // 准备字符串列表数据
    QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    // 创建列表模型
    QStringListModel *model = new QStringListModel(numbers);

    // 创建视图
    QListView *view = new QListView;
    // 为视图设置模型
    view->setModel(model);
    // 显示视图
    view->show();

    return a.exec();
}
