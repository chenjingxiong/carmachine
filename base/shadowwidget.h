#ifndef NBASESHOWDOWWIDGET_H
#define NBASESHOWDOWWIDGET_H


#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

/**
 * @brief The NBaseShowdowWidget class 阴影widget基类
 */
class shadowWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief NBaseShowdowWidget 构造函数
     * @param parent
     */
    explicit shadowWidget(QWidget *parent = 0);

protected:
    /**
     * @brief changeEvent 改变事件处理函数
     * @param event
     */
    void changeEvent(QEvent *event);

    /**
     * @brief paintEvent 绘制事件处理函数
     * @param e
     */
    void paintEvent(QPaintEvent *e);

private:
    /**
     * @brief drawShadowPlanA 阴影绘制方案A
     */
    void drawShadowPlanA();

    /**
     * @brief drawShadowPlanB 阴影绘制方案B
     */
    void drawShadowPlanB();

private:
    QPixmap m_shadow;
};

#endif // NBASESHOWDOWWIDGET_H
