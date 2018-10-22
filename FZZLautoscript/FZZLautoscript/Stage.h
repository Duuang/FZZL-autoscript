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
  int StartPlay();  //��ʼˢ
  int StopPlay();  //TODO ֹͣˢ

private:
  int ClearBag();  //TODO �Զ�����
  void Click(int x, int y);  //ǰ̨��������������ȥ�ˣ�Ŀǰ�ò���
  void SendClick(int x, int y); //��̨��������������ȥ��
  string stage_descr;  //�ؿ��������磺3-10
  int stage_map, stage_num;  //�ؿ����ͼ��š��ؿ����
  int stage_type;   //�ؿ�����
  int ifauto;    //�Ƿ����Զ�
  float zoom;    //windowsϵͳ���ű���
  HWND mainhwnd, subhwnd, subwinhwnd;  //�����ڡ��Ӵ��ڡ���ʾͼ���subwin
  static int stage_clickpos[10][10][20][2];  //����ÿ�ؿ�ʼʱ���Ҫ���ģ� pos[stagetype][stagenum][(x, y)];
};
