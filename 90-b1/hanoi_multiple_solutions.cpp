/* �� 1851521 ������ */
#include"hanoi.h"

/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

static int countt = 0;
static int stackA[] = { 0,0,0,0,0,0,0,0,0,0 };
static int stackB[] = { 0,0,0,0,0,0,0,0,0,0 };
static int stackC[] = { 0,0,0,0,0,0,0,0,0,0 };
static int A = 0, B = 0, C = 0;
static int delay;

void draw_column()
{
	cct_showch(0, 15, ' ', COLOR_YELLOW, COLOR_YELLOW, 25);
	cct_showch(45, 15, ' ', COLOR_YELLOW, COLOR_YELLOW, 25);
	cct_showch(90, 15, ' ', COLOR_YELLOW, COLOR_YELLOW, 25);
	delay = 5;
	for (int i = 0; i < 3; i++) {
		for (int j = 14; j >= 5; j--) {
			cct_showch(i*45 + 12 , j, ' ', COLOR_YELLOW, COLOR_YELLOW, 1);
			delay_sometime();
		}
	}
	cct_gotoxy(0, 30);
}

//����ȫ�ֱ���
void clear_global()
{
	countt = 0;

	for (int i = 0; i < 10; i++) {
		stackA[i] = 0;
		stackB[i] = 0;
		stackC[i] = 0;
	}

	A = 0;
	B = 0;
	C = 0;
}

//��ʱ
void delay_sometime()
{
	if (delay == 0) {
		_getch();
	}
	else if (delay == 1) {
		Sleep(2000);
	}
	else if (delay == 2) {
		Sleep(1000);
	}
	else if (delay == 3) {
		Sleep(500);
	}
	else if (delay == 4) {
		Sleep(200);
	}
	else if (delay == 5) {
		Sleep(50);
	}
}

//����
void get_input(int* n, char* src, char* tmp, char* dst, int* display_stack, char choice)
{

	char c;
	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
		cin >> *n;

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (*n < 1 || *n>10) {
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

	while (1) {
		cout << "��������ʼ��(A-C)��" << endl;
		cin >> *src;

		//תΪ��д
		if (*src == 'a' || *src == 'b' || *src == 'c') {
			*src -= 0x20;
		}

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (*src < 'A' || *src>'C') {
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

	while (1) {
		cout << "������Ŀ����(A-C)��" << endl;
		cin >> *dst;

		//תΪ��д
		if (*dst == 'a' || *dst == 'b' || *dst == 'c') {
			*dst -= 0x20;
		}

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (*dst < 'A' || *dst>'C') {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (*dst == *src) {
			cout << "Ŀ����(" << *dst << ")��������ʼ��(" << *src << ")��ͬ" << endl;
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


	//��������� �ò�������
	if (choice == '4') {
		while (1) {
			cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
			cin >> delay;
			if (cin.fail()) {
				cin.clear();
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			else if (delay < 0 || delay > 5) {
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

		while (1) {
			cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
			cin >> *display_stack;
			if (cin.fail()) {
				cin.clear();
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			else if (*display_stack < 0 || *display_stack > 1) {
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
	

	*tmp = 3 * 'B' - *src - *dst;

	//��ʼ��ջ
	if (*src == 'A') {
		for (int i = 0; i < *n; i++) {
			stackA[i] = *n - i;
		}
		A = *n;
	}
	if (*src == 'B') {
		for (int i = 0; i < *n; i++) {
			stackB[i] = *n - i;
		}
		B = *n;
	}
	if (*src == 'C') {
		for (int i = 0; i < *n; i++) {
			stackC[i] = *n - i;
		}
		C = *n;
	}
}

void push(char i, int j)
{
	if (i == 'A') {
		stackA[A++] = j;
	}
	if (i == 'B') {
		stackB[B++] = j;
	}
	if (i == 'C') {
		stackC[C++] = j;
	}
}

int pop(char i)
{
	int temp = 0;
	if (i == 'A') {

		temp = stackA[--A];
		stackA[A] = 0;
	}
	if (i == 'B') {

		temp = stackB[--B];
		stackB[B] = 0;
	}
	if (i == 'C') {

		temp = stackC[--C];
		stackC[C] = 0;
	}
	return temp;
}

//�����ӡstack��������
void print_stack(char choice)
{
	if (choice == '4') {
		cct_gotoxy(20, 17);
	}
	
	cout << " A:";
	for (int i = 0; i < 10; i++) {
		if (stackA[i] == 10)
			cout << 10;
		if (stackA[i] < 10 && stackA[i]>0)
			cout << " " << stackA[i];
		if (stackA[i] == 0)
			cout << "  ";
	}
	cout << " ";


	cout << "B:";
	for (int i = 0; i < 10; i++) {
		if (stackB[i] == 10)
			cout << 10;
		if (stackB[i] < 10 && stackB[i]>0)
			cout << " " << stackB[i];
		if (stackB[i] == 0)
			cout << "  ";
	}
	cout << " ";


	cout << "C:";
	for (int i = 0; i < 10; i++) {
		if (stackC[i] == 10)
			cout << 10;
		if (stackC[i] < 10 && stackC[i]>0)
			cout << " " << stackC[i];
		if (stackC[i] == 0)
			cout << "  ";
	}
	cout << endl;
	if (choice == '4') {
		delay_sometime();
	}
	
}

//��ӡ�ڼ���
void print_step(int n, char src, char dst,char choice)
{
	if (choice == '4') {
		cct_gotoxy(0, 17);
	}
	
	cout << "��" << setfill(' ') << setw(4) << countt << " ��(";
	if (n < 10) {
		cout << " ";
	}
	cout << n << "): " << src << "-->" << dst;
	push(dst, pop(src));
}

//�����ӡstack��������
void print_stack_vertical()
{
	int x = 11;
	int y = 11;
	for (int i = 0; i < 10; i++) {
		cct_gotoxy(x, y - i);
		if (stackA[i] != 0)
			cout << stackA[i];
		else
			cout << " ";
	}
	for (int i = 0; i < 10; i++) {
		cct_gotoxy(x + 10, y - i);
		if (stackB[i] != 0)
			cout << stackB[i];
		else
			cout << " ";
	}
	for (int i = 0; i < 10; i++) {
		cct_gotoxy(x + 20, y - i);
		if (stackC[i] != 0)
			cout << stackC[i];
		else
			cout << " ";
	}
	delay_sometime();
}

//�ƶ�
void move(int n, char src, char tmp, char dst, int display_stack, char way)
{
	countt++;
	if (way == '1') {
		cout << n << "# " << src << "---->" << dst << endl;
	}
	if (way == '2') {
		cout << "��" << setfill(' ') << setw(4) << countt << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
	}
	if (way == '3') {
		print_step(n, src, dst,way);
		print_stack(way);
	}
	if (way == '4') {
		print_step(n, src, dst,way);
		if (display_stack)
			print_stack(way);
		print_stack_vertical();
	}
}

//ֻ����һ���ݹ麯��
void hanoi(int n, char src, char tmp, char dst, int display_stack, char way)
{
	if (n == 1) {
		move(n, src, tmp, dst, display_stack, way);
	}
	else {
		hanoi(n - 1, src, dst, tmp, display_stack, way);
		move(n, src, tmp, dst, display_stack, way);
		hanoi(n - 1, tmp, src, dst, display_stack, way);
	}
}

//��main���ã�������choice
void play(char choice)
{
	int n;
	char src, tmp, dst;
	int display_stack;

	clear_global();

	if (choice != '5') {
		get_input(&n, &src, &tmp, &dst, &display_stack, choice);
	}
	

	if (choice == '1') {
		hanoi(n, src, tmp, dst, display_stack, choice);
	}

	if (choice == '2') {
		hanoi(n, src, tmp, dst, display_stack, choice);
	}

	if (choice == '3') {
		hanoi(n, src, tmp, dst, display_stack, choice);
	}

	if (choice == '4') {
		cct_cls();
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << delay << "��" << (display_stack ? "" : "��") << "��ʾ�ڲ�����ֵ" << endl;
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "         =========================" << endl;
		cout << "           A         B         C" << endl;
		cout << endl << endl << endl;

		cct_gotoxy(0, 17);


		if (display_stack) {
			cout << "��ʼ:                ";
			print_stack(choice);
		}

		print_stack_vertical();
		hanoi(n, src, tmp, dst, display_stack, choice);
	}

	if (choice == '5') {
		cct_cls();
		draw_column();
	}

	if (choice == '6') {

	}

	if (choice == '7') {

	}

	if (choice == '8') {

	}

	if (choice == '9') {

	}

	cct_setcolor();
	cout << endl;
	system("pause");
}