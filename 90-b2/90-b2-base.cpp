/* 1851521 软工 沈天宇 */
//放内部数组方式实现的各函数

#include "90-b2.h"

void change_find_result_to_zero(int data[10][10], int max_x,int max_y,int find_result[10][10])
{
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (data[i][j] == 0) {
				find_result[i][j] = 1;
			}
			else {
				find_result[i][j] = 0;
			}
		}
	}
}

void input_select(char select[100],int max_x,int max_y)
{
	while (1) {
		cout << "\n请以字母+数字形式[例：c2]输入矩阵坐标：" << endl;
		cin >> select;

		if (select[0] >= 'A' && select[0] <= 'Z') {
			select[0] += 0x20;
		}

		char c;
		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (select[0] < 'a' || select[0] > 'a' + max_y - 1 || select[1] < '1' || select[1] > '1' + max_x - 1) {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			break;
		}
	}
}


//通用输入输出错误处理
template <class T>
void input(T &in,T lower_limits,T upper_limits,const char * prompt)
{
	char c;
	while (1) {
		cout << prompt;
		cin >> in;
		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (in < lower_limits || in > upper_limits) {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			break;
		}
	}
}

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

		input(max_y, 5, 8,"请输入行数(5-8)：\n");
		input(max_x, 5, 10,"请输入列数(5-10)：\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		char select[100];

		input_select(select, max_x, max_y);

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



		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		char select[100];

		input_select(select, max_x, max_y);

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

		int score = 0;

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");
		input(target, 5, 20, "请输入合成目标(5-20)\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		while (1) {

			char select[100];

			input_select(select, max_x, max_y);
			

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

				int temp_score = merge(data, max_x, max_y, select_x, select_y, find_result);
				score += temp_score;

				cout << "\n相同值归并后的数组(不同色标识)：" << endl;
				print_data_with_color(data, max_x, max_y, find_result);
				
				cout << " 本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << target << endl;

				cout << "按任意键进行数组下落除0操作..." << endl;
				system("pause");

				fall(data, max_x, max_y);

				change_find_result_to_zero(data, max_x, max_y,find_result);
				print_data_with_color(data, max_x, max_y,find_result);

				cout << "按任意键进行新值填充..." << endl;
				system("pause");

				generate_data(data, max_x, max_y);
				print_data_with_color(data, max_x, max_y, find_result);

				break;
			}
			
		}

		system("pause");
	}

	if (choice == 4) {
		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");
		input(target, 5, 20, "请输入合成目标(5-20)\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		while (1) {

			char select[100];

			input_select(select, max_x, max_y);


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

				int temp_score = merge(data, max_x, max_y, select_x, select_y, find_result);
				score += temp_score;

				cout << "\n相同值归并后的数组(不同色标识)：" << endl;
				print_data_with_color(data, max_x, max_y, find_result);

				cout << " 本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << target << endl;
				if (get_max_num(data, max_x, max_y) >= target) {
					cout << "您已达到合成目标！您可以继续往更高的目标合成" << endl;
				}

				cout << "按任意键进行数组下落除0操作..." << endl;
				system("pause");

				fall(data, max_x, max_y);

				change_find_result_to_zero(data, max_x, max_y, find_result);
				print_data_with_color(data, max_x, max_y, find_result);

				cout << "按任意键进行新值填充..." << endl;
				system("pause");

				generate_data(data, max_x, max_y);
				print_data_with_color(data, max_x, max_y, find_result);

			}

		}
		system("pause");
	}

	if (choice == 5) {

		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");
		input(target, 5, 20, "请输入合成目标(5-20)\n");

		generate_data(data, max_x, max_y);

		cct_setconsoleborder(6 * max_x + 7, 3 * max_y + 8);
		cct_cls();

		print_background(max_x, max_y);

		system("pause");
	}
}