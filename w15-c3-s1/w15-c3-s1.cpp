/* 1851521 沈天宇 软工 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（全局只读变量或宏定义不受此限制）
   3、不允许添加其它函数
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//某课程的成绩（百分制）
	float weight;	//某课程的学分（权重）
};

struct student {
	int   no;               //学号（虽然用int不够合理，此处不考虑）
	char  name[9];          //假设姓名最长4个汉字
	struct course score[3]; //数组放三门课的成绩（未使用宏定义，函数实现时，直接写3即可）
	float average;                     //可增加其它你认为需要增加的结构体成员（限一个），不要则删除本行
};

/***************************************************************************
  函数名称：
  功    能：输入10个学生的信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* 除这两个整型变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	int i, j;
	for (i = 0; i < num; i++){
		cout << setiosflags(ios::right);
		cout << "请输入第"<< setfill(' ') <<setw(2) << i+1 << "个学生的信息 : ";
		cout << resetiosflags(ios::right);

		cin >> stu[i].no;
		cin >> stu[i].name;
		for (j = 0; j < 3; j++) {
			cin >> stu[i].score[j].value;
			cin >> stu[i].score[j].weight;
		}
	}

	/* 函数的实现部分 */
}

/***************************************************************************
  函数名称：
  功    能：输出10个学生的基本信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* 除这两个指针变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	struct student* ps;
	struct course* pc;

	ps = stu;
	cout << "\n";
	cout << num << "个学生的成绩为" << endl;
	cout << "序号 学号    姓名     成绩1 权重1 成绩2 权重2 成绩3 权重3 加权平均成绩" << endl;
	cout << "======================================================================" << endl;

	cout << setiosflags(ios::left) << setfill(' ');
	while (ps - stu != num) {
		
		cout << setw(5) << ps - stu + 1 << setw(8) << ps->no << setw(9) << ps->name;
		for (pc = ps->score; pc < ps->score + 3; pc++) {
			cout << setw(6)<< pc->value <<setw(6) << pc->weight;
		}
		cout << setiosflags(ios::fixed) << setprecision(2);
		ps->average = (ps->score[0].value * ps->score[0].weight + ps->score[1].value * ps->score[1].weight + ps->score[2].value * ps->score[2].weight) / (ps->score[0].weight + ps->score[1].weight + ps->score[2].weight);
		cout << ps -> average;
		cout << resetiosflags(ios::fixed) << setprecision(6);
		cout << endl;
		ps++;
	}
	
	/* 函数的实现部分，不允许任何形式的[]出现 */
}

/***************************************************************************
  函数名称：
  功    能：输出绩点最高的学生（可能有并列）
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* 本函数中允许定义各种类型的简单变量，但不允许定义数组 */
	float max = 0;
	student* ps = stu;
	course* pc;

	cout << "\n成绩最高的学生为" << endl;
	cout << "序号 学号    姓名     成绩1 权重1 成绩2 权重2 成绩3 权重3 加权平均成绩" << endl;
	cout << "======================================================================" << endl;

	for (int i = 0; i < num; i++) {
		if (ps->average > max) {
			max = ps -> average;
		}
		ps++;
	}

	ps = stu;
	for (int i = 0; i < num; i++) {
		if (ps->average == max) {
			cout << setw(5) << ps - stu + 1 << setw(8) << ps->no << setw(9) << ps->name;
			for (pc = ps->score; pc < ps->score + 3; pc++) {
				cout << setw(6) << pc->value << setw(6) << pc->weight;
			}
			cout << setiosflags(ios::fixed) << setprecision(2);
			ps->average = (ps->score[0].value * ps->score[0].weight + ps->score[1].value * ps->score[1].weight + ps->score[2].value * ps->score[2].weight) / (ps->score[0].weight + ps->score[1].weight + ps->score[2].weight);
			cout << ps->average;
			cout << resetiosflags(ios::fixed) << setprecision(6);
			cout << endl;
		}
		ps++;
	}

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, 10);		//输入10个学生的信息
	output_base(stu, 10);	//输出10个学生的基本信息
	output_max(stu, 10);	//输出最高（可能有多个）

	return 0;
}

/*
测试数据，复制到cmd即可（测试时，不限于这一组）


2153171 曾明宇 76.5 4 82 5 52 2
2154063 刘佳昊 63 4 49 1 87 6
2151626 杜镇宇 56 3 76 4 69 5
2153178 席昌林 44.5 2 83.5 4 87 6
2153482 张羽 91 4 63.5 1 56 3
2151931 徐雄 79 6 85.5 3 62 2
2151282 梁阳 86 3 63 3 77.5 4
2153047 张佳木 49.5 3 86 6 93.5 3
2151405 孟维清 68 2 74.5 3 60 5
2152505 栾学禹 73 3 62 2 85 5

*/