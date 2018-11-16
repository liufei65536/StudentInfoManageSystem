/*
# File name:    main.cpp
# Author:       刘飞, 刘群杰， 邱世英
# Date:         2018/9/6
# Description:  学生信息管理系统的主函数
*/

#include<iostream>
#include"menu.h"
#include"student.h"
#include"file.h"

int main()
{		
	char choice = 0;	//choice，让用户输入选择
	bool active = true;	//active,用来判断程序运行状态，true代表运行中，false代表结束	
	int	m = 0; //学生基本信息 数量
	int n = 0; //成绩信息 数量
	read_record(m, n);//得到学生基本信息、成绩信息条数
	Student * stu =  new Student[m+10];	//学生数组stu，存储学生信息
	StudentScore * stu_score = new StudentScore[n+400];//分数数组stu_score，存储成绩信息

	read_to_stu(stu, m); //从student.txt读入数据到数组中
	read_to_stu_score(stu_score, n); //从score.dat读入数据到数组中

	//显示主菜单
	show_menu();
	//进入循环，用户选择菜单上的功能。直到active为false，程序即将结束时，退出循环
	while(active)
	{ 
		std::cin>>choice;
		choose_func(choice,active,stu_score,stu,m,n);
		if(active)
		  show_menu();
	}
	/*
	程序即将结束，将学生信息写入student.txt;将分数信息写入score.dat;
	写入信息数量到record.txt中;
	*/
	save_stu(stu, m);
	save_score(stu_score, n);
	write_record(m, n);
	//归还使用的内存
	delete[] stu;
	delete[] stu_score;
	system("pause"); //暂停
	return 0;
}