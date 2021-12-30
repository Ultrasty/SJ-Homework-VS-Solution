/* 1851521 软工 沈天宇 */
//放cmd伪图形界面方式实现的各函数

#include"90-b2.h"

void print_background(int max_x,int max_y)
{
	cout << " ";
	for (int i = 0; i < max_x; i++) {
		cout << setw(6) << i + 1;
	}

	for (int i = 0; i < max_y; i++){
		cct_gotoxy(0, i * 3 + 3);
		cout << char('A' + i);
	}

	
	cct_setcolor(COLOR_WHITE, COLOR_BLACK);
	cct_gotoxy(2, 1);
	cout << "┏";

	for (int i = 0; i < max_x; i++) {
		cout << "━━━";
	}

	cout << "┓";
	for (int j = 2; j < 3 * max_y + 2; j++) {
		cct_gotoxy(2, j);
		cout << "┃";
		for (int i = 0; i < max_x; i++) {
			Sleep(1);
			cout << "      ";
		}
		cout << "┃";
	}

	cct_gotoxy(2, 3 * max_y + 2);
	cout << "┗";
	for (int i = 0; i < max_x; i++) {
		cout << "━━━";
	}
	cout << "┛";

	cct_setcolor();
}