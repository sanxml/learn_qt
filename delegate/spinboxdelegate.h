#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QStyledItemDelegate>
#include <QSpinBox>

class SpinBoxDelegate : public QStyledItemDelegate
{
public:
    // ���캯��
    explicit SpinBoxDelegate(QObject *parent = nullptr);
    // �����༭�����
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    // ��ȡԭʼ����
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    // ��������д��ģ��
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    // ���±༭��λ�úʹ�С
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // SPINBOXDELEGATE_H
