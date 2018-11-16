#include"student.h"

//分数的默认构造函数。初始化ID = 0，分数为负数，表示无效成绩;
StudentScore::StudentScore() : ID(0),lesson_number("None"),lesson_name("None"),credit(-1),
	daily_score(-1),exp_score(-1),exam_score(-1)
{

}
//分数的构造函数2，传入参数进行初始化，自动调用calcu_total_score，calcu_actual_score计算 综合成绩和实得学分
StudentScore::StudentScore(int m_ID, string m_lesson_number, string m_lesson_name, int m_credit,
  int m_daily_score, int m_exp_score, int m_exam_score) :  ID(m_ID),lesson_number(m_lesson_number),
  lesson_name(m_lesson_name),credit(m_credit),daily_score(m_daily_score),
	exp_score(m_exp_score),exam_score(m_exam_score)
{
	total_score = calcu_total_score( m_exp_score, m_exam_score, m_daily_score);
	actual_score = calcu_actual_score( total_score,  m_credit);
}
//分数的析构函数，暂无工作要做
StudentScore::~StudentScore()
{

}

//分数的友元函数<<，用于显示
std::ostream& operator<<(std::ostream& os, const StudentScore& stu_score)
{
	os  << std::setiosflags(std::ios::left)
		<<"课程编号: " <<std::setw(8)<< stu_score.lesson_number 
		<< "课程名称: "<<std::setw(12) << stu_score.lesson_name 
		<< "综合成绩: "<<std::setw(8) << stu_score.total_score 
		<< "实得学分: " << stu_score.actual_score;

	return os;
}


//学生的默认构造函数，初始化0
Student::Student(): ID(0), name("None"), sex("None"), dor_number(0), phone(0)
{

}

//学生的析构函数，暂无工作要做
Student::~Student()
{

}

//学生的友元函数<< 用于打印输出.
std::ostream & operator<<(std::ostream & os, const Student& stu)
{
	os <<std::setiosflags(std::ios::left)
		<<std::setw(5)<< stu.ID 
		<<std::setw(8)<< stu.name 
		<< stu.sex << "      " << stu.dor_number << "     "
		<< stu.phone;
	return os;
}




/*
计算实得学分，返回实得学分
传入参数: total_score, credit
返回值:   actual_score
*/
double StudentScore::calcu_actual_score(double total_score, int credit)
{
	double actual_score;
	int flag_total =total_score/10;
	switch (flag_total)
	{
	case 10: case 9: actual_score = credit;
		break;
	case 8: actual_score = credit * 0.8;
		break;
	case 7: actual_score = credit * 0.75;
		break;
	case 6: actual_score = credit * 0.6;
		break;
	default: actual_score = 0;
		break;
	}
	return actual_score ;
}
/*
计算综合成绩，返回综合成绩。
传入参数: exp_score,  exam_score, daily_score
返回值:   total_score
*/
double StudentScore::calcu_total_score(int exp_score, int exam_score, int daily_score)
{
	double total_score;
	if(exp_score == -1)
		total_score = daily_score * 0.3 + exam_score * 0.7;
	else
		total_score = daily_score * 0.15 + exp_score * 0.15 + exam_score * 0.7;
	return total_score;
}
