#include "bottomWidgets.h"
#include <QHBoxLayout>
#include <QTime>

#include <QMediaPlayer>
#include "global_value.h"

bottomWidgets::bottomWidgets(QWidget *parent) : baseWidget(parent)
{
    init();
    setMouseTracking(true);
}

void bottomWidgets::init()
{
    setStyleSheet("bottomWidgets{background:transparent;}");
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    QHBoxLayout *mainlyout=new QHBoxLayout;

    // first layout
    QHBoxLayout *layout1=new QHBoxLayout;

    m_btnnext=new flatButton(this);
    m_btnprevious=new flatButton(this);
    m_btnPlay=new flatButton(this);

    m_btnnext->setFixedSize(50,50);
    m_btnprevious->setFixedSize(50,50);
    m_btnPlay->setFixedSize(50,50);

    m_btnnext->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_next (1).png);}"
                             "QPushButton::hover{border-image:url(:/image/music/btn_next (2).png);}"
                             "QPushButton::pressed{border-image:url(:/image/music/btn_next (3).png);}");
    m_btnprevious->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_previous (1).png);}"
                                 "QPushButton::hover{border-image:url(:/image/music/btn_previous (2).png);}"
                                 "QPushButton::pressed{border-image:url(:/image/music/btn_previous (3).png);}");
    m_btnPlay->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_play (1).png);}"
                             "QPushButton::hover{border-image:url(:/image/music/btn_play (2).png);}"
                             "QPushButton::pressed{border-image:url(:/image/music/btn_play (3).png);}");

    layout1->addWidget(m_btnprevious);
    layout1->addWidget(m_btnPlay);
    layout1->addWidget(m_btnnext);
    layout1->setSpacing(15);
    layout1->setContentsMargins(0,0,0,0);
    //////////////////////////////////////////////////////////////

    // second layput
    QHBoxLayout *layout2=new QHBoxLayout;
    m_mainslider=new mySlider(Qt::Horizontal,this);
    m_mainslider->installEventFilter(this);
    m_mainslider->setRange(0,1000);
    m_mainslider->setMinimumSize(403,12);
    m_mainslider->setMaximumHeight(12);
    m_mainslider->setStyleSheet("QSlider::groove:horizontal{border-radius:2px;height:3px;}"
                                "QSlider::sub-page:horizontal{background:rgb(255, 255, 160);}"
                                "QSlider::add-page:horizontal{background:rgb(200,200,209);}"
                                "QSlider::handle:horizontal{background:rgb(255, 255, 160);width:8px;border-radius:4px;margin:-3px 0px -3px 0px;}");

    QFont font;
    font.setFamily("微软雅黑");
    font.setPixelSize(16);
    font.setBold(true);

    QHBoxLayout *layout2_1=new QHBoxLayout;
    m_labnowPlayname=new TextMovingWidget(str_origin_move_songname,this);
    m_labnowPlayname->setMinimumWidth(250);
    m_labnowPlayname->setFixedHeight(30);
    m_labnowPlayname->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    m_labnowPlayname->setFont(font);

    font.setPixelSize(14);
    font.setBold(false);
    m_labposition=new QLabel("00:00/00:00",this);
    m_labposition->setAlignment(Qt::AlignRight|Qt::AlignBottom);
    m_labposition->setFixedSize(80,24);
    m_labposition->setFont(font);

    layout2_1->addWidget(m_labnowPlayname);
    layout2_1->addWidget(m_labposition);

    QVBoxLayout *vlayout=new QVBoxLayout;
    vlayout->addLayout(layout2_1);
    vlayout->addWidget(m_mainslider);
    vlayout->setSpacing(0);
    vlayout->setContentsMargins(0,0,0,10);
    layout2->addLayout(vlayout);
    /////////////////////////////////////////////

    // third layout
    QHBoxLayout *layout3=new QHBoxLayout;

    m_btnlrc=new flatButton(this);
    m_volwid=new volWidget(this);
    m_btnplaymode=new flatButton(this);

    m_btnlrc->setFixedSize(20,20);
    //    m_volwid->setFixedSize(20,20);
    m_btnplaymode->setFixedSize(20,20);


    m_btnlrc->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_lrc (1).png);}"
                            "QPushButton::hover{border-image:url(:/image/music/btn_lrc (2).png);}"
                            "QPushButton::pressed{border-image:url(:/image/music/btn_lrc (3).png);}");


    m_btnplaymode->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_listrandom (1).png);}"
                                 "QPushButton::hover{border-image:url(:/image/music/btn_listrandom (2).png);}" );


    layout3->addWidget(m_btnplaymode);
    layout3->addWidget(m_volwid);
    layout3->addWidget(m_btnlrc);

    layout3->setSpacing(18);
    layout3->setContentsMargins(0,0,0,0);
    ////////////////////////////////////////
    mainlyout->addLayout(layout1);
    mainlyout->addLayout(layout2);
    mainlyout->addLayout(layout3);
    mainlyout->setSpacing(30);
    mainlyout->setContentsMargins(20,10,20,10);
    setLayout(mainlyout);
}

void bottomWidgets::setRandomStyle()
{
    m_btnplaymode->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_listrandom (1).png);}"
                                 "QPushButton:hover{border-image:url(:/image/music/btn_listrandom (2).png);}");
}

void bottomWidgets::setInOrderStyle()
{
    m_btnplaymode->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_listcircle (1).png);}"
                                 "QPushButton:hover{border-image:url(:/image/music/btn_listcircle (2).png);}");
}

void bottomWidgets::setOneCycleStyle()
{
    m_btnplaymode->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_listscircle_single (1).png);}"
                                 "QPushButton:hover{border-image:url(:/image/music/btn_listscircle_single (2).png);}");
}

void bottomWidgets::setPlayModeBtnStyle(PlayMode mode)
{
    if(mode==PlayMode::playInOrder)
    {
        setInOrderStyle();
    }
    else if(mode==PlayMode::playRandom)
    {
        setRandomStyle();
    }
    else if(mode==PlayMode::playOneCircle)
    {
        setOneCycleStyle();
    }
    else
    {
        setInOrderStyle();
    }
}

void bottomWidgets::setPauseStyle()
{
    m_btnPlay->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_pause (1).png);}"
                             "QPushButton::hover{border-image:url(:/image/music/btn_pause (2).png);}"
                             "QPushButton::pressed{border-image:url(:/image/music/btn_pause (3).png);}");
    m_labnowPlayname->setText(m_labnowPlayname->Text().remove("缓冲中---->> "));

}

void bottomWidgets::setPlayStyle()
{
    m_btnPlay->setStyleSheet("QPushButton{border-image:url(:/image/music/btn_play (1).png);}"
                             "QPushButton::hover{border-image:url(:/image/music/btn_play (2).png);}"
                             "QPushButton::pressed{border-image:url(:/image/music/btn_play (3).png);}");
    m_labnowPlayname->setText(m_labnowPlayname->Text().remove("缓冲中---->> "));
}

void bottomWidgets::setBufferStaus()
{
    if(!m_labnowPlayname->Text().contains(QString("缓冲中---->> ")))
        m_labnowPlayname->setText(QString("缓冲中---->> ")+m_labnowPlayname->Text());
}

void bottomWidgets::setCurrentSongName(const QString& str)
{
    m_labnowPlayname->setText(str);
}

void bottomWidgets::setPositionLabel(const QString &str)
{
    m_labposition->setText(str);
}

bool bottomWidgets::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==m_mainslider)
    {
        if (event->type()==QEvent::MouseButtonPress){
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton)	{
                int dur = m_mainslider->maximum() - m_mainslider->minimum();
                int pos = m_mainslider->minimum() + dur * ((double)mouseEvent->x() / m_mainslider->width());
                if(pos != m_mainslider->sliderPosition()){
                    m_mainslider->setValue(pos);
                    m_mainWid->getPlayer()->setPosition(pos);
                }
            }
        }
    }
    return QObject::eventFilter(obj,event);
}

void bottomWidgets::mouseMoveEvent(QMouseEvent *e)
{
    baseWidget::mouseMoveEvent(e);
}

