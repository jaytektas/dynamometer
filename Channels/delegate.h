#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>

class DDelegate : public QStyledItemDelegate
{
public:
    DDelegate(QWidget * parent = nullptr);

    // delegate
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // DELEGATE_H
