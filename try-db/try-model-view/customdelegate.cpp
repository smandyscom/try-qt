#include "customdelegate.h"
#include <QDateEdit>

customdelegate::customdelegate(QObject *parent):QStyledItemDelegate(parent)
{

}


QWidget* customdelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //create sepecify ui editor
    QDateEdit* editor = new QDateEdit(parent);

    return editor;
}

void customdelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    //model -> editor
    QDateEdit* date_editor = static_cast<QDateEdit*>(editor);
    date_editor->setDateTime(index.model()->data(index,Qt::EditRole).toDateTime());
}

void customdelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    //editor -> model
       QDateEdit* date_editor = static_cast<QDateEdit*>(editor);
       //QVariant value = date_editor->time();
       model->setData(index,QVariant(date_editor->dateTime()));
}

void customdelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

