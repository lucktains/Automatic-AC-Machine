#include <bits/stdc++.h>
#include<windows.h>
#include <stdlib.h>
using namespace std;
void ctrl_v(int x = 86) { //模拟ctrl+v
	keybd_event(VK_CONTROL, 0, 0, 0); //按下ctrl
	keybd_event(x, 0, 0, 0); //按下v
	keybd_event(x, 0, KEYEVENTF_KEYUP, 0); //弹起v
	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0); //弹起ctrl
}
void ctrl_c(int x = 67) { //模拟ctrl+v
	keybd_event(VK_CONTROL, 0, 0, 0); //按下ctrl
	keybd_event(x, 0, 0, 0); //按下v
	keybd_event(x, 0, KEYEVENTF_KEYUP, 0); //弹起v
	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0); //弹起ctrl
}
void ctrl_a(int x = 65) { //模拟ctrl+v
	keybd_event(VK_CONTROL, 0, 0, 0); //按下ctrl
	keybd_event(x, 0, 0, 0); //按下v
	keybd_event(x, 0, KEYEVENTF_KEYUP, 0); //弹起v
	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0); //弹起ctrl
}
int mouseclick(int x, int y) {
	// 模拟鼠标左键单击
	INPUT input;                //创建一个INPUT类型结构体
	input.type = INPUT_MOUSE;   //指定输入事件类型为鼠标事件
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP; // 模拟鼠标左键按下和抬起的动作
	//mi是结构体INPUT的一个成员属性，mi是MOUSEINPUT类型
	//MOUSEINPUT 结构体用于描述鼠标事件，例如鼠标左键单击、双击、右键单击、移动等操作。
	SetCursorPos(x, y);
	input.mi.dx = 0;            //设置鼠标事件发生的x坐标
	input.mi.dy = 0;            //设置鼠标事件发生的y坐标
	input.mi.mouseData = 0;     //设置鼠标滚轮的滚动距离
	input.mi.dwExtraInfo = 0;   //将 dwExtraInfo 字段设置为 0，表示不传递任何附加的输入数据。
	input.mi.time = 0;          //time字段是用来设置时间戳的，0表示使用系统的时间戳
	SendInput(1, &input, sizeof(INPUT));
	/*SendInput函数是 Win32 API 中用于模拟输入事件的函数，可以模拟鼠标事件、键盘事件、硬件事件
	等。
	其函数原型如下：
	UINT SendInput(UINT nInputs, LPINPUT pInputs, int cbSize);
	其中，nInputs 参数指定输入事件的数量，pInputs 参数指向输入事件数组的指针，cbSize 参数指定输
	入事件数组的大小（单位为字节）。*/
	return 0;
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	//记得全屏浏览器再打开，不要有缩放
	string ss, sss, s1 = "https://www.luogu.com.cn/problem/", s2 = "#submit", s3 = "http://222.203.110.13/d/luogu/p/", s4 = "/submit";
	vector<string>ves;
	cin >> ss;
	for (char c : ss) {
		if (c == 'P') {
			if (sss != "") {
				ves.push_back(sss);
			}
			sss.clear();
		}
		sss += c;
	}
	ves.push_back(sss);
	for (string s : ves) {
		ShellExecute(NULL, "open", (s1 + s + s2).c_str(), NULL, NULL, SW_SHOWNORMAL);
		Sleep(2500);
		mouseclick(644, 717);
		ctrl_a();
		ctrl_c();
		ShellExecute(NULL, "open", (s3 + s + s4).c_str(), NULL, NULL, SW_SHOWNORMAL);
		Sleep(2500);
		mouseclick(548, 553);
		ctrl_v();
		mouseclick(424, 756);
	}
	return 0;
}

