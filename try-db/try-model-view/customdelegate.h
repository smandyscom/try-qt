#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H
#include<QStyledItemDelegate>
class customdelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    customdelegate(QObject* parent=0);

   QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   void setEditorData(QWidget* editor,const QModelIndex &index) const;
   void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   void setModelData(QWidget* editor,QAbstractItemModel* model,const QModelIndex &index) const;
};


#endif // CUSTOMDELEGATE_H
