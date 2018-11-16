#pragma once
#include<string>
#include"student.h"

int read_data_and_calcu(StudentScore* stu_score, int & n);
int find(Student * stu, StudentScore* stu_score,int m, int n);
void find_baseinfo(Student* stu, int n);
void find_baseinfo_by_id_name(Student* stu, int m);
void find_baseinfo_by_id(Student * stu, int m);
void find_baseinfo_by_name(Student * stu, int m);
void find_baseinfo_by_dor(Student* stu, int m);
void find_score(Student* stu, StudentScore * stu_score,int m, int n);
int sort_score(StudentScore * stu_score, int n);
int delete_by_ID(Student * stu, StudentScore * stu_score, int &m, int &n);

