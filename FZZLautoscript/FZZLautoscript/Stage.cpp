#include "Stage.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <signal.h>


//#include <QtWidgets>

using namespace std;

int Stage::stage_clickpos[10][10][20][2] = {};  //TODO  之后把这补上

Stage::Stage(const string &stagedescr, int stagetype, int ifauto, float zoom) {
  stage_descr = stagedescr;
  stage_map = stage_descr[0] - 48;
  stage_num = stage_descr[3] - 48 + (stage_descr[2] - 48) * 10;
  stage_type = stagetype;
  this->ifauto = ifauto;
  this->zoom = zoom;
  mainhwnd = FindWindowA(NULL, "方舟指令 - MuMu模拟器");  //主窗口
  subhwnd = FindWindowExA(mainhwnd, NULL, NULL, NULL);  //子窗口
  subwinhwnd = FindWindowExA(subhwnd, NULL, NULL, NULL);  //显示图像的subwin
  cout << subwinhwnd << endl;
}

int Stage::StartPlay() {
  if (stage_type == 0) {
    stage_clickpos[0][3][4][0] = 1042;   //TODO  之后要去掉。。stage_clickpos要初始化
    stage_clickpos[0][3][4][1] = 307;    //................
    while (true) {  //刷3-4
      SendClick(stage_clickpos[stage_type][stage_map][stage_num][0],
                stage_clickpos[stage_type][stage_map][stage_num][1]); //点3-4
      Sleep(500);
      SendClick(991, 570);//进入副本
      Sleep(500);
      SendClick(991, 570);//选择队伍
      Sleep(1000);
      
      HDC hdc = GetDC(subwinhwnd);
      COLORREF clr;
      while (true) {
        clr = GetPixel(hdc, (int)(1042 / zoom), (int)(307 / zoom));

        if ((int)GetRValue(clr) == 3 && (int)GetGValue(clr) == 100 && (int)GetBValue(clr) == 219) {
          break;
        }
        SendClick(1092, 599);//战斗
        Sleep(500);
        clr = GetPixel(hdc, (int)(826 / zoom), (int)(471 / zoom));
        if ((int)GetRValue(clr) == 63 && (int)GetGValue(clr) == 70 && (int)GetBValue(clr) == 77) {
          ClearBag();
          SendClick(1092, 599);
        }
        
        SendClick(1193, 284);
        Sleep(500);
        SendClick(1193, 284);
          //选助战
      }
    }
  }

  return 0;
}

int Stage::ClearBag() {
  Sleep(1000);
  SendClick(826, 471);
  Sleep(1000);
  for (float x = 112; x < 1174; x += (1173 - 112) / 6)
    for (float y = 257; y < 625; y += (624 - 257) / 2) {
      SendClick(x, y);
      Sleep(500);
    }
  SendClick(1190, 689);
  Sleep(500);
  SendClick(831, 540);
  Sleep(500);
  return 1;
}


void Stage::Click(int x, int y) {
  SetCursorPos((int)(x / zoom), (int)(y / zoom));
  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void Stage::SendClick(int x, int y) {
  x = (int)(x / zoom);
  y = (int)(y / zoom);
  SendMessage(subhwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(x, y));
  SendMessage(subhwnd, WM_LBUTTONUP, 0, MAKELPARAM(x, y));
}



  /*
  POINT p;
  HWND mainhwnd = FindWindowA(NULL, "方舟指令 - MuMu模拟器");  //主窗口
  HWND subhwnd = FindWindowExA(mainhwnd, NULL, NULL, NULL);  //子窗口
  HWND subwinhwnd = FindWindowExA(subhwnd, NULL, NULL, NULL);  //显示图像的subwin
  cout << subwinhwnd << endl;

  Sleep(5000);
  //SendMessage(subhwnd,WM_LBUTTONDOWN,MK_LBUTTON,MAKELPARAM(10,10));
  //SendMessage(subhwnd,WM_LBUTTONUP,0,MAKELPARAM(10, 10));
  cout << mainhwnd << endl;
  //HDC hdc = GetDC(subwinhwnd);
  //COLORREF clr = GetPixel(hdc, 918, 563);
  //cout << (int)GetRValue(clr) << ", " << (int)GetGValue(clr) << ", " << (int)GetBValue(clr) << endl;
  system("pause");
  //HWND hq = FindWindowA(NULL, "新标签页 - Google Chrome");
  RECT rect;
  GetWindowRect(mainhwnd,&rect);
  int w=rect.right-rect.left,h=rect.bottom-rect.top;
  cout<<"宽:"<<w<<" "<<"高:"<<h<<endl;
  //MoveWindow(mainhwnd,100,100, w, h, false);
  Sleep(1000);


  /*
  //hq = (HWND)(0x00060330);
  GetCursorPos(&p);
  SendMessage(hq,WM_LBUTTONDOWN,MK_LBUTTON,MAKELPARAM(1637,812));
  00705BC
001204DE
  SendMessage(hq,WM_LBUTTONUP,0,MAKELPARAM(1637,812));
  Sleep(20000);
  system("pause");

 //1058, 750
   //705, 500
   //245, 234, 110
  HDC hdc = GetDC(NULL);
  COLORREF clr = ::GetPixel(hdc, 1007, 700);
  cout << (int)GetRValue(clr) << ", " << (int)GetGValue(clr) << ", " << (int)GetBValue(clr) << endl;
  system("pause");
  */
  /*
  while (true) {  //刷1-10
    //break;
    SendClick(subhwnd, 1149/1.5, 317/1.5); //点1-10
    Sleep(500);
    SendClick(subhwnd, 991/1.5, 570/1.5);//进入副本
    Sleep(4000);
    SendClick(subhwnd, 1092/1.5, 599/1.5);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193/1.5, 284/1.5);//选助战
    Sleep(10000);
    //SendClick(subhwnd, 1155, 670);
    Sleep(500);
    //SendClick(subhwnd, 1155, 670);//技能3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 1028/1.5, 460/1.5);

      if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
        break;
      }
      SendClick(subhwnd, 945/1.5, 667/1.5);
      Sleep(500);  //技能2
      SendClick(subhwnd, 945/1.5, 667/1.5);
    }
  }

  while (true) {  //刷3-4
    break;
    SendClick(subhwnd, 1042, 307); //点3-10
    Sleep(500);
    SendClick(subhwnd, 991, 570);//进入副本
    Sleep(500);
    SendClick(subhwnd, 991, 570);//选择队伍
    Sleep(1000);
    SendClick(subhwnd, 1178, 672);//自动寻路
    Sleep(4000);
    SendClick(subhwnd, 1092, 599);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193, 284);//选助战
    //Sleep(10000);
    //SendClick(subhwnd, 1155, 670);
    //Sleep(500);
    //SendClick(subhwnd, 1155, 670);//技能3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 1042, 307);

      if ((int)GetRValue(clr) == 3 && (int)GetGValue(clr) == 100 && (int)GetBValue(clr) == 219) {
        break;
      }
      SendClick(subhwnd, 1092, 599);//战斗
      Sleep(500);
      SendClick(subhwnd, 1193, 284);
      Sleep(500);
      SendClick(subhwnd, 1193, 284);//选助战
      //SendClick(subhwnd, 945, 667);
      //Sleep(500);  //技能2
      //SendClick(subhwnd, 945, 667);
    }
  }


  while (true) {  //刷3-10
    break;
    SendClick(subhwnd, 1113, 454); //点3-10
    Sleep(500);
    SendClick(subhwnd, 991, 570);//进入副本
    Sleep(4000);
    SendClick(subhwnd, 1092, 599);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193, 284);//选助战
    Sleep(10000);
    //SendClick(subhwnd, 1155, 670);
    Sleep(500);
    //SendClick(subhwnd, 1155, 670);//技能3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 918, 563);

      if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
        break;
      }
      SendClick(subhwnd, 945, 667);
      Sleep(500);  //技能2
      SendClick(subhwnd, 945, 667);
    }
  }
  while (true) {  //刷1-10
    //break;
    SendClick(subhwnd, 1149, 317); //点1-10
    Sleep(500);
    SendClick(subhwnd, 991, 570);//进入副本
    Sleep(4000);
    SendClick(subhwnd, 1092, 599);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193, 284);//选助战
    Sleep(10000);
    //SendClick(subhwnd, 1155, 670);
    Sleep(500);
    //SendClick(subhwnd, 1155, 670);//技能3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 1028, 460);

      if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
        break;
      }
      SendClick(subhwnd, 945, 667);
      Sleep(500);  //技能2
      SendClick(subhwnd, 945, 667);
    }
  }

  while (true) {  //刷高难本
    SendClick(subhwnd, 1015, 344); //选60级难度
    Sleep(500);
    SendClick(subhwnd, 630, 607);//点挑战
    Sleep(4000);
    SendClick(subhwnd, 1092, 599);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193, 284);//选助战
    Sleep(20000);

    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      SendClick(subhwnd, 945, 667);
      Sleep(500);
      SendClick(subhwnd, 945, 667);//技能2
      COLORREF clr = ::GetPixel(hdc, 737, 589);

      if ((int)GetRValue(clr) == 255 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 0) {
        break;
      }

    }
  }

*/

