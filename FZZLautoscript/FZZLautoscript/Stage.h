#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <signal.h>
//#include <QtWidgets>

using namespace std;


class Stage {
public:
  Stage(const string &stagedescr, int stagetype, int ifauto, float zoom);
  int StartPlay();  //开始刷
  int StopPlay();  //TODO 停止刷

private:
  int ClearBag();  //TODO 自动贩卖
  void Click(int x, int y);  //前台点击，把缩放算进去了，目前用不上
  void SendClick(int x, int y); //后台点击，把缩放算进去了
  string stage_descr;  //关卡描述，如：3-10
  int stage_map, stage_num;  //关卡大地图编号、关卡编号
  int stage_type;   //关卡种类
  int ifauto;    //是否开了自动
  float zoom;    //windows系统缩放比例
  HWND mainhwnd, subhwnd, subwinhwnd;  //主窗口、子窗口、显示图像的subwin
  static int stage_clickpos[10][10][20][2];  //代表每关开始时鼠标要点哪， pos[stagetype][stagenum][(x, y)];
};
