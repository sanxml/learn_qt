#include "mainwindow.h"
#include "spinboxdelegate.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    // �������ģ��
    QStandardItemModel model(4, 4);
    for (int row = 0; row < model.rowCount(); ++row) {
        for (int column = 0; column < model.columnCount(); ++column) {
            QStandardItem *item = new QStandardItem(QString("%1").arg(row + column));
            model.setItem(row, column, item);
        }
    }

    // ������ͼ
    QTableView *tableView = new QTableView;
    tableView->setModel(&model);
    tableView->resize(420,200);
    tableView->setWindowTitle("delegate test");
    tableView->show();

    // ʹ��ί��
    SpinBoxDelegate *delegate = new SpinBoxDelegate;
    tableView->setItemDelegate(delegate);

    return a.exec();
}
