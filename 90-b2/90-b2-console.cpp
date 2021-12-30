/* 1851521 软工 沈天宇 */
//放cmd伪图形界面方式实现的各函数

#include"90-b2.h"

void print_one_block(int number, int x, int y)
{
	cct_setcolor(number,COLOR_BLACK);
	cct_gotoxy(x, y);
	cout << "┏━┓";
	cct_gotoxy(x, y+1);
	cout << "┃  ┃";
	cct_gotoxy(x, y+2);
	cout << "┗━┛";
	cct_gotoxy(x + 2, y + 1);
	cout << number;
	cct_setcolor();
}

void print_data_block(int data[10][10], int max_x, int max_y)
{
	for (int j = 0; j < max_y; j++) {
		for (int i = 0; i < max_x; i++) {
			print_one_block(data[i][j], i * 6 + 4, j * 3 + 2);
		}
	}
}

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

	
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
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