#ifndef VIDEOWIDGETS_H
#define VIDEOWIDGETS_H

#include <QObject>

#include "basepushbutton.h"
#include "basewidget.h"
#include "topWidget/videotopwidgets.h"
#include "middleWidget/videomiddlewidgets.h"
#include "bottomWidget/videobottomwidgets.h"

#include <QMediaPlayer>
#include <QVideoWidget>
#include "middleWidget/videocontentwidget.h"

class videoWidgets:public baseWidget
{
    Q_OBJECT
public:
    videoWidgets(QWidget *parent = 0);

    videoTopWidgets *m_topWid;
    videoMiddleWidgets *m_middleWid;
    videoBottomWidgets *m_bottomWid;

    void savaSetting();
    void updateVolume(bool volumeAdd);
private:
    QMediaPlayer *m_player;

    void initLayout();
    void initPlayerAndConnection();
    void readSetting();
    void setOriginState();
private slots:
    void slot_onMediaStateChanged(QMediaPlayer::MediaStatus);
    void slot_onPlayerStateChanged(QMediaPlayer::State);
    void slot_onCurrentMediaChanged(QMediaContent);
    void slot_onMediaPositionChanged(qint64);
    void slot_onDurationChanged(qint64);
    void slot_onSliderPositionChanged(int);

    void slot_onLocalListItemDoubleClick(int,int);
    void slot_setPlayPause();
    void slot_nextVideo();
    void slot_lastVideo();
    void slot_addVideo();
    void slot_volumeChanged(int);
    void slot_setPause();

    void slot_onContentDoubleClick(); // 双击videoWidget,设置全屏或者取消全屏
};

#endif // VIDEOWIDGETS_H
