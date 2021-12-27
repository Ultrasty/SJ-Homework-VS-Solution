/* 1851521 软工 沈天宇 */
//放内部数组方式实现的各函数

#include "90-b2.h"
//被main调用，并传入choice
void play(int choice)
{
	int max_x;
	int max_y;
	int data[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			data[i][j] = 0;
		}
	}
	if (choice == 1) {
		cct_cls();
		cout << "请输入行数(5-8)：" << endl;
		cin >> max_y;
		cout << "请输入列数(5-10)：" << endl;
		cin >> max_x;
		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);
		system("pause");
	}
}