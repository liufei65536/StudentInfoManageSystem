#pragma once
#include<iostream>
#include<iomanip>
#include<string>
using std::string;

// StudentScore �洢ѧ���ɼ�
class StudentScore
{
private:
	int ID;  //ѧ��
	string lesson_number; //�γ̱��
	string lesson_name; //�γ�����
	int credit;  //ѧ��
	int daily_score;  //ƽʱ�ɼ�
	int exp_score;  //ʵ��ɼ�
	int exam_score; //����ɼ�
	double total_score;  //�ۺϳɼ�, ����õ�
	double actual_score; // ʵ�ʵ÷֣� ����õ�

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

//Student�࣬�洢ѧ����Ϣ
class Student
{
private:
	int ID;  //ѧ��
	string name; //����
	string sex; //�Ա�
	int dor_number; //�������
	int phone; //�绰

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



