/* 软工 1851521 沈天宇 */
#include"hanoi.h"

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

static int countt = 0;
static int stackA[] = { 0,0,0,0,0,0,0,0,0,0 };
static int stackB[] = { 0,0,0,0,0,0,0,0,0,0 };
static int stackC[] = { 0,0,0,0,0,0,0,0,0,0 };
static int A = 0, B = 0, C = 0;
static int delay = 50;
static int display_stack;

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

void print_stack()
{
	cct_gotoxy(20, 17);
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

void print_step(int n, char src, char dst)
{
	cct_gotoxy(0, 17);
	countt++;
	cout << "第" << setfill(' ') << setw(4) << countt << " 步(";
	if (n < 10) {
		cout << " ";
	}
	cout << n << "): " << src << "-->" << dst;
	push(dst, pop(src));
}

//竖向打印数组
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

void move(int n,char src,char tmp,char dst,int way) 
{
	print_step(n, src, dst);
	if (display_stack)
		print_stack();
	print_stack_vertical();
}

void hanoi(int n, char src, char tmp, char dst,int way)
{
	if (n == 1) {
		move(n, src, tmp, dst, way);
	}
	else {
		hanoi(n - 1, src, dst, tmp, way);
		move(n, src, tmp, dst, way);
		hanoi(n - 1, tmp, src, dst, way);
	}
}


void play() 
{
	int n;
	char src, tmp, dst;
	//用于清空缓冲区的临时变量
	char c;

	while (1) {
		cout << "请输入汉诺塔的层数(1-10)：" << endl;
		cin >> n;

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (n < 1 || n>10) {
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
		cout << "请输入起始柱(A-C)：" << endl;
		cin >> src;

		//转为大写
		if (src == 'a' || src == 'b' || src == 'c') {
			src -= 0x20;
		}

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (src < 'A' || src>'C') {
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
		cout << "请输入目标柱(A-C)：" << endl;
		cin >> dst;

		//转为大写
		if (dst == 'a' || dst == 'b' || dst == 'c') {
			dst -= 0x20;
		}

		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (dst < 'A' || dst>'C') {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (dst == src) {
			cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
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
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
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
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> display_stack;
		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (display_stack < 0 || display_stack > 1) {
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

	tmp = 3 * 'B' - src - dst;

	//初始化栈
	if (src == 'A') {
		for (int i = 0; i < n; i++) {
			stackA[i] = n - i;
		}
		A = n;
	}
	if (src == 'B') {
		for (int i = 0; i < n; i++) {
			stackB[i] = n - i;
		}
		B = n;
	}
	if (src == 'C') {
		for (int i = 0; i < n; i++) {
			stackC[i] = n - i;
		}
		C = n;
	}



	cct_cls();
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay << "，" << (display_stack ? "" : "不") << "显示内部数组值" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "         =========================" << endl;
	cout << "           A         B         C" << endl;
	cout << endl << endl << endl;

	cct_gotoxy(0, 17);


	if (display_stack) {
		cout << "初始:                ";
		print_stack();
	}
	print_stack_vertical();
	hanoi(n, src, tmp, dst,1);

	cct_gotoxy(0, 27);
}