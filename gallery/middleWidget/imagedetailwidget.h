#ifndef IMAGEDETAILWIDGET_H
#define IMAGEDETAILWIDGET_H


#include <QWidget>
#include <QLabel>

//#include "moveablewidget.h"
#include "basepushbutton.h"

class ImageItem:public QWidget
{
public:
    ImageItem(QWidget *parent=0);
    void updateItem(QString title,QString text);
private:
    QLabel *titleLabel;
    QLabel *textLabel;
};

class ImageDetailWidget:public QWidget
{
    Q_OBJECT
public:
    ImageDetailWidget(QWidget *parent=0);

    void updateImageInfo(QString imagePath);
private:
    void initLayout();
    void initConnection();
private:
    flatButton *m_btnClose;
    flatButton *m_btnConfirm;

    ImageItem *nameItem;
    ImageItem *patternItem;
    ImageItem *resolutionItem;
    ImageItem *locationItem;
    ImageItem *sizeItem;
    ImageItem *createTimeItem;

};

#endif // IMAGEDETAILWIDGET_H
