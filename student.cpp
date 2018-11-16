#include"student.h"

//������Ĭ�Ϲ��캯������ʼ��ID = 0������Ϊ��������ʾ��Ч�ɼ�;
StudentScore::StudentScore() : ID(0),lesson_number("None"),lesson_name("None"),credit(-1),
	daily_score(-1),exp_score(-1),exam_score(-1)
{

}
//�����Ĺ��캯��2������������г�ʼ�����Զ�����calcu_total_score��calcu_actual_score���� �ۺϳɼ���ʵ��ѧ��
StudentScore::StudentScore(int m_ID, string m_lesson_number, string m_lesson_name, int m_credit,
  int m_daily_score, int m_exp_score, int m_exam_score) :  ID(m_ID),lesson_number(m_lesson_number),
  lesson_name(m_lesson_name),credit(m_credit),daily_score(m_daily_score),
	exp_score(m_exp_score),exam_score(m_exam_score)
{
	total_score = calcu_total_score( m_exp_score, m_exam_score, m_daily_score);
	actual_score = calcu_actual_score( total_score,  m_credit);
}
//�������������������޹���Ҫ��
StudentScore::~StudentScore()
{

}

//��������Ԫ����<<��������ʾ
std::ostream& operator<<(std::ostream& os, const StudentScore& stu_score)
{
	os  << std::setiosflags(std::ios::left)
		<<"�γ̱��: " <<std::setw(8)<< stu_score.lesson_number 
		<< "�γ�����: "<<std::setw(12) << stu_score.lesson_name 
		<< "�ۺϳɼ�: "<<std::setw(8) << stu_score.total_score 
		<< "ʵ��ѧ��: " << stu_score.actual_score;

	return os;
}


//ѧ����Ĭ�Ϲ��캯������ʼ��0
Student::Student(): ID(0), name("None"), sex("None"), dor_number(0), phone(0)
{

}

//ѧ�����������������޹���Ҫ��
Student::~Student()
{

}

//ѧ������Ԫ����<< ���ڴ�ӡ���.
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
����ʵ��ѧ�֣�����ʵ��ѧ��
�������: total_score, credit
����ֵ:   actual_score
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
�����ۺϳɼ��������ۺϳɼ���
�������: exp_score,  exam_score, daily_score
����ֵ:   total_score
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
