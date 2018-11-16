#pragma once
#include"student.h"
void show_menu();
bool choose_func(char choice, bool & active, StudentScore * stu_score, Student * stu,
	int & m, int& n);