#include<iostream>
#include"student.h"
#include"func.h"

using std::cout;
using std::cin;
//显示主菜单
void show_menu() {
	cout<<"############################\n";
	cout<<"   学生信息管理系统\n"
		<<"      选择功能\n"
		<<"1.数据的录入和计算\n"
		<<"2.查询功能\n"
		<<"3.删除功能\n"
		<<"4.排序功能\n"
		<<"q.退出程序。\n";
}

//读入选择，执行功能
bool choose_func(char choice, bool & active,StudentScore * stu_score,Student * stu,
	int & m, int& n ) {
	switch(choice) {
	case '1' : 
		n = read_data_and_calcu(stu_score,n);
		break;
	case '2':
	    find( stu, stu_score,m, n);
		break;
	case '3':
		delete_by_ID(stu, stu_score, m, n);
		break;
	case '4':
		sort_score(stu_score, n);
		break;
	case 'q':
		cout<<"quit~\n";
		active = false;
		break;
	default:
		cout << "无效输入\n";
	}
    return active;
}
