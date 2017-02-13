#ifndef IMAGESHOWWIDGET_H
#define IMAGESHOWWIDGET_H

#include "basewidget.h"

#include <QListWidget>
#include <QImage>
#include <QLabel>
#include <QScrollArea>

class imageShowWidget:public QScrollArea
{
public:
    imageShowWidget(QWidget *parent);
private:
    void initLayout();
private:
    QList<QImage> m_images;

public:
    void updateList(QList<QImage>);
};


class ImageItemHeader:public baseWidget
{
public:
    ImageItemHeader(QWidget *parent,QString titleText);

    void updateTitleText(int size);
private:
    QLabel *m_titleText;


};

// the images_item_show with catlog
class imagesItemWidget:public baseWidget
{
public:
    imagesItemWidget(QWidget *parent,QString catalog,QList<QImage> imageList);

private:
    void initLayout();
    void updateWidget(QList<QImage> imageList);
private:
    QString m_catalog;
    QList<QImage> m_imageList;

    ImageItemHeader *m_header;
    QListWidget *m_imageListWid;
};

#endif // IMAGESHOWWIDGET_H
