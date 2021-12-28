/* 1851521 软工 沈天宇 */
//放内部数组方式实现的各函数

#include "90-b2.h"
//被main调用，并传入choice
void play(int choice)
{
	
	int max_x;
	int max_y;
	int target;
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

		cout << "\n请以【小写】字母+数字形式[例：c2]输入矩阵坐标：" << endl;

		char select[10];
		cin >> select;

		cout << "输入为" << select[0] << "行" << select[1] << "列" << endl;

		int select_x = select[1] - '1';
		int select_y = select[0] - 'a';

		int find_result[10][10];
		find_congener(data, max_x, max_y,select_x,select_y ,find_result);
		print_find_result(find_result, max_x, max_y);
		print_data_with_color(data, max_x,max_y,find_result);

		system("pause");
	}

	if (choice == 2) {
		cct_cls();



		cout << "请输入行数(5-8)：" << endl;
		cin >> max_y;
		cout << "请输入列数(5-10)：" << endl;
		cin >> max_x;
		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		cout << "\n请以【小写】字母+数字形式[例：c2]输入矩阵坐标：" << endl;

		char select[10];
		cin >> select;

		cout << "输入为" << select[0] << "行" << select[1] << "列" << endl;

		int select_x = select[1] - '1';
		int select_y = select[0] - 'a';

		int find_result[10][10];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				find_result[i][j] = 0;
			}
		}
		find_result[select_x][select_y] = 1;
		find_congener_recursion(data, max_x, max_y, select_x, select_y, find_result);
		print_find_result(find_result, max_x, max_y);
		print_data_with_color(data, max_x, max_y, find_result);

		system("pause");
	}

	if (choice == 3) {
		cct_cls();



		cout << "请输入行数(5-8)：" << endl;
		cin >> max_y;
		cout << "请输入列数(5-10)：" << endl;
		cin >> max_x;
		cout << "请输入合成目标(5-20)" << endl;
		cin >> target;

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		while (1) {
			cout << "\n请以【小写】字母+数字形式[例：c2]输入矩阵坐标：" << endl;

			char select[10];
			cin >> select;

			cout << "输入为" << select[0] << "行" << select[1] << "列" << endl;

			int select_x = select[1] - '1';
			int select_y = select[0] - 'a';

			int find_result[10][10];
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					find_result[i][j] = 0;
				}
			}
			find_result[select_x][select_y] = 1;
			find_congener_recursion(data, max_x, max_y, select_x, select_y, find_result);
			print_find_result(find_result, max_x, max_y);
			print_data_with_color(data, max_x, max_y, find_result);

			cout << "请确认是否把相邻的相同值合并到" << select[0] << select[1] << "中(【小写】：y/n/q)：";

			char choice;
			while (1) {
				choice = _getche();
				if (choice != 'y' && choice != 'n' && choice != 'q') {
					continue;
				}
				else
					break;
			}

			if (choice == 'q') {
				break;
			}
			if (choice == 'n') {
				continue;
			}
			if (choice == 'y') {
				//处理逻辑
				cout << "相同值归并后的数组(不同色标识)：" << endl;
				
				break;
			}
			
		}

		system("pause");
	}
}