/* 1851521 �� ������ */
//���ڲ����鷽ʽʵ�ֵĸ�����

#include "90-b2.h"
//��main���ã�������choice
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

		

		cout << "����������(5-8)��" << endl;
		cin >> max_y;
		cout << "����������(5-10)��" << endl;
		cin >> max_x;
		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		cout << "\n����Сд��ĸ+������ʽ[����c2]����������꣺" << endl;

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
}