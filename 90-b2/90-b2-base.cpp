/* 1851521 �� ������ */
//���ڲ����鷽ʽʵ�ֵĸ�����

#include "90-b2.h"
//��main���ã�������choice
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

		

		cout << "����������(5-8)��" << endl;
		cin >> max_y;
		cout << "����������(5-10)��" << endl;
		cin >> max_x;
		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		cout << "\n���ԡ�Сд����ĸ+������ʽ[����c2]����������꣺" << endl;

		char select[10];
		cin >> select;

		cout << "����Ϊ" << select[0] << "��" << select[1] << "��" << endl;

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



		cout << "����������(5-8)��" << endl;
		cin >> max_y;
		cout << "����������(5-10)��" << endl;
		cin >> max_x;
		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		cout << "\n���ԡ�Сд����ĸ+������ʽ[����c2]����������꣺" << endl;

		char select[10];
		cin >> select;

		cout << "����Ϊ" << select[0] << "��" << select[1] << "��" << endl;

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



		cout << "����������(5-8)��" << endl;
		cin >> max_y;
		cout << "����������(5-10)��" << endl;
		cin >> max_x;
		cout << "������ϳ�Ŀ��(5-20)" << endl;
		cin >> target;

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		while (1) {
			cout << "\n���ԡ�Сд����ĸ+������ʽ[����c2]����������꣺" << endl;

			char select[10];
			cin >> select;

			cout << "����Ϊ" << select[0] << "��" << select[1] << "��" << endl;

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

			cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << select[0] << select[1] << "��(��Сд����y/n/q)��";

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
				//�����߼�
				cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
				
				break;
			}
			
		}

		system("pause");
	}
}