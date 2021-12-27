/* 1851521 软工 沈天宇 */
//放一些内部数组/图形方式公用的函数，如判断结束等

#include"90-b2.h"

void generate_data(int data[10][10], int max_x, int max_y)
{
	int max_num = 0;
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (max_num < data[i][j]) {
				max_num = data[i][j];
			}
		}
	}

	srand((unsigned)time(NULL));
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (data[i][j] == 0) {
				int temp = 0;
				if (max_num <= 3){
					temp = rand() % 3 + 1;
				}
				if (max_num == 4) {
					temp = rand() % 10;
					if (temp == 9) {
						temp = 4;
					}
					else {
						temp = temp % 3 + 1;
					}
				}
				if (max_num == 5) {
					temp = rand() % 100;
					if (temp >= 90) {
						temp = 5;
					}
					else if(temp >=75 && temp < 90){
						temp = 4;
					}
					else {
						temp = temp % 3 + 1;
					}
				}
				if (max_num == 6) {
					temp = rand() % 100;
					if (temp >= 95) {
						temp = 6;
					}
					else if (temp >= 80 && temp < 95) {
						temp = 5;
					}
					else {
						temp = temp % 4 + 1;
					}
				}
				if (max_num > 6) {
					temp = rand() % 100;
					if (temp >= 95) {
						temp = max_num;
					}
					else if (temp >= 90 && temp < 95) {
						temp = max_num - 1;
					}
					else if (temp >= 80 && temp < 90) {
						temp = max_num - 2;
					}
					else {
						temp = rand() % (max_num - 3) + 1;
					}
				}
				data[i][j] = temp;
			}
		}
	}
}


void print_data(int data[10][10], int max_x, int max_y)
{
	cout << endl;
	cout << "当前数组：" << endl;
	cout << "  |";
	for (int i = 0; i < max_x; i++) {
		cout << setw(3) << i + 1;
	}
	cout << endl;
	cout << "--+";
	for (int i = 0; i < max_x; i++) {
		cout << "---";
	}
	cout << endl;
	for (int j = 0; j < max_y; j++) {
		cout << char('A' + j) << " |";
		for (int i = 0; i < max_x; i++) {
			cout << setw(3) << data[i][j];
		}
		cout << endl;
	}
}