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
		system("pause");
	}
}