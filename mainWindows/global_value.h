#ifndef GLOBAL_VALUE_H
#define GLOBAL_VALUE_H

#include <QStandardPaths>
#include "mainwindow.h"

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
//const QString str_wifi_adapter= "网卡适配器";

#ifdef DEVICE_EVB
const int font_size = 30;
const int font_size_big = 35;
// top part
const QString return_resource_str = ":/image/main/return_big.png";
const int return_icon_width = 212;
const int return_icon_height = 70;
const int top_icon_size = 60;
#else
const int font_size = 13;
const int font_size_big = 16;
// top part
const QString return_resource_str = ":/image/main/return.png";
const int return_icon_width = 115;
const int return_icon_height = 40;
const int top_icon_size = 40;
#endif

const QString MUSIC_SEARCH_PATH = QStandardPaths::writableLocation(QStandardPaths::HomeLocation).append("/mnt");
const QString str_add_song= "Add music";
const QString str_clear_list= "Clear list";
const QString str_song_list= "musicPlay";
const QString str_song_playing= "Playing";
const QString str_playmode_list= "List";
const QString str_playmode_random= "Random";
const QString str_playmode_single= "Single";
const QString str_origin_move_songname = "Please first select one music";
// video
const QString VIDEO_SEARCH_PATH = QStandardPaths::writableLocation(QStandardPaths::HomeLocation).append("/mnt");
const QString str_listheader_local_video = "Local Video";
const QString str_listheader_net_video = "Net Video";
const QString str_video_playing = "Playing";
const QString str_videoName_default = "videoPlayer";
const QString str_videoTime_minite= "min";
// setting
const QString str_net_manager= "Wlan";
const QString str_bt_manager= "BlueTooth";
const QString str_common_setting= "General";
const QString str_system_setting= "System";
const QString str_open_wifi= "WLAN";
const QString str_wifi_adapter= "adapter";
// gallery
const QString str_gallery_empty_tip1= "All in the family";
const QString str_gallery_empty_tip2= "Take a picture & Photo saved on this device appear here.";


#endif
