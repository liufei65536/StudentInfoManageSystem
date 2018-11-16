/*
��File name:	file.h
��Description:	���к��ļ���д��صĲ���
*/

#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"student.h"

/*
read_record()
��record.txt�����¼���õ����еļ�¼����
����:&m, &n������д��ѧ����Ϣ��¼�����ͳɼ�����
����ֵ1
*/
int read_record(int &m, int &n) {
	std::ifstream fin("record.txt");
	fin >> m;
	fin >> n;
	return 1;
}

/*
write_record
д���¼��record.txt�����¼�¼����
����:m ,n
����ֵ: 0
*/
int write_record(int m, int n) {
	std::ofstream fout("record.txt");
	fout << m;
	fout << " ";
	fout << n;
	return 1;
}
/*
save_score()
�����ļ���score.dat
����: StudentScore*, n
*/
void save_score(StudentScore* stu_score,int n) {
	using namespace std;
	ofstream fout("score.dat", ios::binary);
	if (!fout) {
		cout << "�����ļ�ʧ��\n";
		return;
	}
	int i = 0;
	for (int i = 0; i < n; i++) {
		fout << stu_score[i].ID << "  " << stu_score[i].lesson_number << "  "
			<< stu_score[i].lesson_name << "  " << stu_score[i].credit<< "  "
			<< stu_score[i].daily_score << "  " << stu_score[i].exp_score<< "  " 
			<< stu_score[i].exam_score << "  " << stu_score[i].total_score<< "  "
			<< stu_score[i].actual_score << "\n";
	}
	fout.close();
}
/*
read_to_stu_score()
���ļ�score.dat�������������
����StudentScore*, &n
*/
int read_to_stu_score(StudentScore* stu_score, int &n) {
	using namespace std;
	int i = 0;
	ifstream fin("score.dat", ios::binary);
	if (!fin) {
		cout << "��ȡ�ɼ��ļ�score.datʧ��" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		fin >> stu_score[i].ID >> stu_score[i].lesson_number
			>> stu_score[i].lesson_name >> stu_score[i].credit
			>> stu_score[i].daily_score >> stu_score[i].exp_score
			>> stu_score[i].exam_score >> stu_score[i].total_score
			>> stu_score[i].actual_score;
	}
	fin.close();
	return i;
}

/*
read_to_stu()
���ļ�student.txt����ѧ����Ϣ������
����:Student*, &m
*/
int read_to_stu(Student* stu, int &m) {
	using namespace std;
	int i = 0;
	ifstream fin("student.txt");
	if (!fin) {
		cout << "��ȡѧ�������ļ�student.txtʧ��" << endl;
		return 0;
	}
	string temp;//��ʱstring�������һ�е�5���ַ���
	for (int i = 0; i < 5; i++) {
		fin >> temp;
	}
	for (int i = 0; i < m; i++) {
		fin >> stu[i].ID >> stu[i].name >> stu[i].sex >> stu[i].dor_number
			>> stu[i].phone;
	}
	fin.close();
	return 1;
}
/*
save_stu
д��ѧ����Ϣ��student.txt
����Student*,m
*/
void save_stu(Student* stu, int m) {
	using namespace std;
	ofstream fout("student.txt");
	if (!fout) {
		cout << "�����ļ�ʧ��\n";
		return;
	}
	fout << "ѧ�� ����  �Ա�  �������  �绰����\n";
	for (int i = 0; i < m; i++) {
		fout << stu[i].ID << "  " << stu[i].name << "  " << stu[i].sex << "  "
			<< stu[i].dor_number << "     " << stu[i].phone<<"\n";
	}
	fout.close();
}

