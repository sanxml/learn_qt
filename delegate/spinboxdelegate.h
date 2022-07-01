#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QStyledItemDelegate>
#include <QSpinBox>

class SpinBoxDelegate : public QStyledItemDelegate
{
public:
    // 构造函数
    explicit SpinBoxDelegate(QObject *parent = nullptr);
    // 创建编辑器组件
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    // 获取原始数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    // 将新数据写入模型
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    // 更新编辑器位置和大小
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // SPINBOXDELEGATE_H
