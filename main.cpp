/*
# File name:    main.cpp
# Author:       ����, ��Ⱥ�ܣ� ����Ӣ
# Date:         2018/9/6
# Description:  ѧ����Ϣ����ϵͳ��������
*/

#include<iostream>
#include"menu.h"
#include"student.h"
#include"file.h"

int main()
{		
	char choice = 0;	//choice�����û�����ѡ��
	bool active = true;	//active,�����жϳ�������״̬��true���������У�false�������	
	int	m = 0; //ѧ��������Ϣ ����
	int n = 0; //�ɼ���Ϣ ����
	read_record(m, n);//�õ�ѧ��������Ϣ���ɼ���Ϣ����
	Student * stu =  new Student[m+10];	//ѧ������stu���洢ѧ����Ϣ
	StudentScore * stu_score = new StudentScore[n+400];//��������stu_score���洢�ɼ���Ϣ

	read_to_stu(stu, m); //��student.txt�������ݵ�������
	read_to_stu_score(stu_score, n); //��score.dat�������ݵ�������

	//��ʾ���˵�
	show_menu();
	//����ѭ�����û�ѡ��˵��ϵĹ��ܡ�ֱ��activeΪfalse�����򼴽�����ʱ���˳�ѭ��
	while(active)
	{ 
		std::cin>>choice;
		choose_func(choice,active,stu_score,stu,m,n);
		if(active)
		  show_menu();
	}
	/*
	���򼴽���������ѧ����Ϣд��student.txt;��������Ϣд��score.dat;
	д����Ϣ������record.txt��;
	*/
	save_stu(stu, m);
	save_score(stu_score, n);
	write_record(m, n);
	//�黹ʹ�õ��ڴ�
	delete[] stu;
	delete[] stu_score;
	system("pause"); //��ͣ
	return 0;
}