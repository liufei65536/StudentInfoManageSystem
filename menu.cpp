#include<iostream>
#include"student.h"
#include"func.h"

using std::cout;
using std::cin;
//��ʾ���˵�
void show_menu() {
	cout<<"############################\n";
	cout<<"   ѧ����Ϣ����ϵͳ\n"
		<<"      ѡ����\n"
		<<"1.���ݵ�¼��ͼ���\n"
		<<"2.��ѯ����\n"
		<<"3.ɾ������\n"
		<<"4.������\n"
		<<"q.�˳�����\n";
}

//����ѡ��ִ�й���
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
		cout << "��Ч����\n";
	}
    return active;
}
