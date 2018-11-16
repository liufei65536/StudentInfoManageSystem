/*
·File name:	 func.cpp
·Description:   实现菜单的4项功能：1.读入数据; 2.查找; 3.删除; 4.成绩排序
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"student.h"
#include"func.h"

using std::string;
using std::cin;
using std::cout;

/*
read_data_and_calcu()
功能：从键盘读入成绩相关的7项数据，并根据公式计算出综合成绩和实得学分。
传入参数：StudentScore*（分数数组地址）， &n（已有的成绩条数）
返回值：写入的条数
*/
int read_data_and_calcu(StudentScore* stu_score, int & n) {
	int Max_read = 1;       //每次最多读入的条数
	bool flag_input = true;// 用来判断是否正常输入
	int id = 0;           //学号
	string lesson_number;//课程编号
	string lesson_name; //课程名称
	int credit;        //学分
	int daily_score;  //平时成绩
	int exp_score;   //实验成绩
	int exam_score; //卷面成绩
	int i = 0;
	for (i = n; i < n + Max_read && flag_input; i++) {
		cout << "开始输入学生数据：\n";
		cout << "学号," << " 课程编号, " << " 课程名称: \n";
		cin >> id >> lesson_number >> lesson_name;
		cout << "学分, " << " 平时成绩, " << " 实验成绩," << " 卷面成绩:\n";
		cin >> credit >> daily_score >> exp_score >> exam_score;
		stu_score[i] = StudentScore(id, lesson_number, lesson_name, credit, daily_score,exp_score, exam_score);
		cout << "录入该学生数据成功";
	}
	cout << "\n";
	n += i;
	return i;
}


/*
find()
查询（总）,通过用户选择查询类型调用find_baseinfo()或find_score()，显示对应的信息。
传入参数：Student*(学生数组地址), StudentScore*（分数数组地址）,int m（学生信息条数）, int n（分数条数）
返回参数：0
*/
int find(Student * stu, StudentScore* stu_score, int m, int n)
{
	cout << "输入查询类型：1.学生基本情况查询； 2.成绩查询：";
	char find_kind;
	cin >> find_kind;
	switch (find_kind) {
	case '1':
		//学生基本情况查询
		find_baseinfo(stu, m);
		break;
	case '2':
		//成绩查询
		find_score(stu, stu_score, m, n);
		break;
	default:
		cout << "无效选择\n";
		break;
	}
	cout << "\n";
	return 0;
};

/*
find_baseinfo()
查询_学生基本信息,被find()调用，显示对应的学生信息
传入参数：Student*, m
*/
void find_baseinfo(Student* stu, int m) {
	cout << "输入查询方式：1.按学号或姓名查询   2.按宿舍查询: ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		find_baseinfo_by_id_name(stu, m);
		break;
	case 2:
		find_baseinfo_by_dor(stu, m);
		break;
	}
}


/*
find_baseinfo_by_id_name()
查询_学生基本信息_通过_id或name,被find_baseinfo()调用
传入参数:Student*, m
*/
void find_baseinfo_by_id_name(Student* stu, int m) {
	cout << "选择：1.使用学号查询  2.使用姓名: ";
	int choice_2;
	cin >> choice_2;
	switch (choice_2) {
	case 1:
		find_baseinfo_by_id(stu, m);
	break;
	case 2:
		find_baseinfo_by_name( stu, m);
		break;
	}
}

void find_baseinfo_by_id(Student* stu, int m) {
	//按学号查询，打印结果
	cout << "输入学号: ";
	int id;
	cin >> id;
	bool flag_find_id = false;
	for (int i = 0; i < m; i++) {
		if (id == stu[i].get_ID()) {
			flag_find_id = true;
			cout << "学号 姓名    性别  宿舍号码  电话号码\n";
			cout << stu[i];
			break;
		}
		if (i == m - 1 && !flag_find_id)
			cout << "  此ID记录不存在\n";
	}
}

void find_baseinfo_by_name(Student* stu, int m) {
	//使用姓名查询，打印结果
	cout << "输入姓名: ";
	string name;
	cin >> name;
	bool flag_find_name = false;
	for (int i = 0; i < m; i++) {
		if (name == stu[i].get_name() ) {
			flag_find_name = true;
			cout << "学号  姓名  性别   宿舍号码  电话号码\n";
			cout << stu[i];
			break;
		}
		if (i == m - 1 && !flag_find_name)
			cout << "  此姓名记录不存在\n";
	}
}

/*
find_baseinfo_by_dor()
查询_学生基本信息_通过_宿舍,被find_baseinfo()调用
传入参数Stuent*, m
*/
void find_baseinfo_by_dor(Student* stu, int m) {
	//按宿舍查询，打印结果
	cout << "输入宿舍号: ";
	int dor_number;
	cin >> dor_number;
	cout << "学号  姓名  性别   宿舍号码  电话号码\n";
	bool flag_find_dor = false;
	for (int i = 0; i < m; i++) {
		if (dor_number == stu[i].get_dor_number()) {
			flag_find_dor = true;
			cout << stu[i];
			cout << "\n";
		}
		if (i == m - 1 && !flag_find_dor)
			cout << "    宿舍记录不存在\n";
	}
}

/*查询_分数,被find()调用，显示对应的分数信息
传入参数：Student*, StudentScore*,m(学生信息条数),n(分数信息条数)
*/
void find_score(Student* stu, StudentScore* stu_score, int m, int n) {
	cout << "输入该学生的学号:";
	int id;
	cin >> id;
	bool flag_find_id = false;
	for (int i = 0; i < m; i++) {
		if (id == stu[i].get_ID()) {
			flag_find_id = true;
			cout << "\t\t\t\t学号: " << std::setiosflags(std::ios::left)
				<< std::setw(10) << stu[i].get_ID() << "姓名: "
				<< std::setw(10) << stu[i].get_name();
			break;
		}
		if (i == m - 1 && !flag_find_id) {
			cout << "\n\t\t此ID学生信息记录不存在\n";
		}
	}
	bool flag_find_score = false;
	int lesson_n = 0;
	double all_credit = 0;
	for (int i = 0; i < n; i++) {
		if (id == stu_score[i].get_ID()) {
			flag_find_score = true;
			cout << "\n" << stu_score[i];
			lesson_n++;
			all_credit += stu_score[i].get_actual_score();
		}
		if (i == n - 1 && !flag_find_score) {
			cout << "\n\t\t此ID成绩记录不存在\n";
		}
	}
	cout << "\n\t\t共修: " << lesson_n << "科，实得总学分为: " << all_credit;
}

/*
delete_by_ID()
删除和ID相关的信息
*/
int delete_by_ID(Student * stu, StudentScore * stu_score, int &m, int &n) {
	cout << "删除该学号的所有相关信息：\n输入学号：";
	int ID;
	cin >> ID;
	//删除ID相关的学生基本信息
	for (int i = 0; i < m; i++) {
		if (stu[i].get_ID() == ID) {
			int k = i;
			if (k == m - 1) {
				stu[i] = Student(); //使其为空
				m--;
			}
			else {
				for (int j = k + 1; j < m; j++) {
					stu[j - 1] = stu[j];
				}
				m--;
			}
		}
	}
	//删除ID相关的成绩信息
	for (int i = n - 1; i >= 0; i--) {
		if (stu_score[i].get_ID() == ID) {
			int k = i;
			if (k == n - 1) {
				stu_score[i] = StudentScore(); //使其为空
				n--;
			}
			else{
				for (int j = k + 1; j < n; j++) {
					stu_score[j - 1] = stu_score[j];
				}
				n--;
			}
		}
	}
	cout << "该学生所有相关信息删除成功\n";
	return 0;
};

/*按分数排序,(降序)。
传入参数：StudentScore*, n(成绩条数)
*/
int sort_score(StudentScore * stu_score, int n)
{
	int choice;
	cout << "选择：1.按综合成绩排序   2.按实得学分排序";
	cin >> choice;
	switch (choice) {
	case 1: {
		StudentScore temp;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (stu_score[j].get_total_score() < stu_score[j + 1].get_total_score()) {
					temp = stu_score[j];
					stu_score[j] = stu_score[j + 1];
					stu_score[j + 1] = temp;
				}
			}
		}
		break;
	}
	case 2: {
		StudentScore temp;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (stu_score[j].get_actual_score() < stu_score[j + 1].get_actual_score()) {
					temp = stu_score[j];
					stu_score[j] = stu_score[j + 1];
					stu_score[j + 1] = temp;
				}
			}
		}
		break;
	}
	}

	for (int i = 0; i < n; i++) {
		cout << "学号: " << std::setiosflags(std::ios::left) << std::setw(4)
			<< stu_score[i].get_ID() << stu_score[i] << "\n";
	}
	return n;
};
