#ifndef GLOBAL_VALUE_H
#define GLOBAL_VALUE_H

#include "mainwindow.h"
#include <QStandardPaths>

extern mainWindow *mainwid;
extern rightStackedWidgets0 *wifiWid;

// music
//const QString MUSIC_SEARCH_PATH = QStandardPaths::writableLocation(QStandardPaths::HomeLocation).append("/mnt");
//const QString str_add_song= "添加音乐";
//const QString str_clear_list= "清空列表";
//const QString str_song_list= "歌曲列表";
//const QString str_song_playing= "正在播放中";
//const QString str_playmode_list= "列表循环";
//const QString str_playmode_random= "随机播放";
//const QString str_playmode_single= "单曲循环";
//const QString str_origin_move_songname = "请先指定曲目";
//// video
//const QString VIDEO_SEARCH_PATH = QStandardPaths::writableLocation(QStandardPaths::HomeLocation).append("/mnt");
//const QString str_listheader_local_video = "本地视频";
//const QString str_listheader_net_video = "网络视频";
//const QString str_video_playing = "播放中";
//const QString str_videoName_default = "视频播放器";
//const QString str_videoTime_minite= "分钟";
//// setting
//const QString str_net_manager= "网络管理";
//const QString str_bt_manager= "蓝牙管理";
//const QString str_common_setting= "通用设置";
//const QString str_system_setting= "系统设置";
//const QString str_open_wifi= "打开WLAN";
//const QString str_wifi_adapter= "网卡适配器:";
//const QString str_current_net= " 当前网络:";
//const QString str_current_no_net_tip= "无网络连接";


const QString MUSIC_SEARCH_PATH = QStandardPaths::writableLocation(QStandardPaths::HomeLocation).append("/mnt");
const QString str_add_song= "Add music";
const QString str_clear_list= "Clear list";
const QString str_song_list= "Music List";
const QString str_song_playing= "Playing..";
const QString str_playmode_list= "List";
const QString str_playmode_random= "Random";
const QString str_playmode_single= "Single";
const QString str_origin_move_songname = "Please first select one music";
// video
const QString VIDEO_SEARCH_PATH = QStandardPaths::writableLocation(QStandardPaths::HomeLocation).append("/mnt");
const QString str_listheader_local_video = "Local Video";
const QString str_listheader_net_video = "Net Video";
const QString str_video_playing = "Playing..";
const QString str_videoName_default = "Video Player";
const QString str_videoTime_minite= "min";
// setting
const QString str_net_manager= "Wlan";
const QString str_bt_manager= "BlueTooth";
const QString str_common_setting= "General";
const QString str_system_setting= "System";
const QString str_open_wifi= "WLAN";
const QString str_wifi_adapter= "Adapter:";
const QString str_current_net= "Network:";
const QString str_current_no_net_tip= "no connection";


#endif
