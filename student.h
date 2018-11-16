#pragma once
#include<iostream>
#include<iomanip>
#include<string>
using std::string;

// StudentScore 存储学生成绩
class StudentScore
{
private:
	int ID;  //学号
	string lesson_number; //课程编号
	string lesson_name; //课程名称
	int credit;  //学分
	int daily_score;  //平时成绩
	int exp_score;  //实验成绩
	int exam_score; //卷面成绩
	double total_score;  //综合成绩, 计算得到
	double actual_score; // 实际得分， 计算得到

public:
	StudentScore() ;
	StudentScore(int ID, string lesson_number,string lesson_name,int credit,
                 int daily_score,int exp_score,int exam_score);
	~StudentScore() ;
	int get_ID() { return ID; }
	double calcu_actual_score(double total_score, int credit);
	double calcu_total_score(int exp_score, int exam_score, int daily_score);
	double get_total_score() { return total_score; }
	double get_actual_score() { return actual_score; }

	friend std::ostream& operator<<(std::ostream& os, const StudentScore& score);
	friend void save_score(StudentScore* stu_score, int n);
	friend int read_to_stu_score(StudentScore* stu_score, int &n);
};

//Student类，存储学生信息
class Student
{
private:
	int ID;  //学号
	string name; //姓名
	string sex; //性别
	int dor_number; //宿舍号码
	int phone; //电话

public:
	Student();
	~Student();
	int get_ID() { return ID; }
	string get_name() { return name; }
	int get_dor_number() { return dor_number; }

	friend std::ostream & operator<<(std::ostream & os, const Student& stu);
	friend int read_to_stu(Student* stu, int &m);
	friend void save_stu(Student* stu, int m);
};



