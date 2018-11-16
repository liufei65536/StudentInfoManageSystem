/*
��File name:	 func.cpp
��Description:   ʵ�ֲ˵���4��ܣ�1.��������; 2.����; 3.ɾ��; 4.�ɼ�����
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"student.h"
#include"func.h"

using std::string;
using std::cin;
using std::cout;

/*
read_data_and_calcu()
���ܣ��Ӽ��̶���ɼ���ص�7�����ݣ������ݹ�ʽ������ۺϳɼ���ʵ��ѧ�֡�
���������StudentScore*�����������ַ���� &n�����еĳɼ�������
����ֵ��д�������
*/
int read_data_and_calcu(StudentScore* stu_score, int & n) {
	int Max_read = 1;       //ÿ�������������
	bool flag_input = true;// �����ж��Ƿ���������
	int id = 0;           //ѧ��
	string lesson_number;//�γ̱��
	string lesson_name; //�γ�����
	int credit;        //ѧ��
	int daily_score;  //ƽʱ�ɼ�
	int exp_score;   //ʵ��ɼ�
	int exam_score; //����ɼ�
	int i = 0;
	for (i = n; i < n + Max_read && flag_input; i++) {
		cout << "��ʼ����ѧ�����ݣ�\n";
		cout << "ѧ��," << " �γ̱��, " << " �γ�����: \n";
		cin >> id >> lesson_number >> lesson_name;
		cout << "ѧ��, " << " ƽʱ�ɼ�, " << " ʵ��ɼ�," << " ����ɼ�:\n";
		cin >> credit >> daily_score >> exp_score >> exam_score;
		stu_score[i] = StudentScore(id, lesson_number, lesson_name, credit, daily_score,exp_score, exam_score);
		cout << "¼���ѧ�����ݳɹ�";
	}
	cout << "\n";
	n += i;
	return i;
}


/*
find()
��ѯ���ܣ�,ͨ���û�ѡ���ѯ���͵���find_baseinfo()��find_score()����ʾ��Ӧ����Ϣ��
���������Student*(ѧ�������ַ), StudentScore*�����������ַ��,int m��ѧ����Ϣ������, int n������������
���ز�����0
*/
int find(Student * stu, StudentScore* stu_score, int m, int n)
{
	cout << "�����ѯ���ͣ�1.ѧ�����������ѯ�� 2.�ɼ���ѯ��";
	char find_kind;
	cin >> find_kind;
	switch (find_kind) {
	case '1':
		//ѧ�����������ѯ
		find_baseinfo(stu, m);
		break;
	case '2':
		//�ɼ���ѯ
		find_score(stu, stu_score, m, n);
		break;
	default:
		cout << "��Чѡ��\n";
		break;
	}
	cout << "\n";
	return 0;
};

/*
find_baseinfo()
��ѯ_ѧ��������Ϣ,��find()���ã���ʾ��Ӧ��ѧ����Ϣ
���������Student*, m
*/
void find_baseinfo(Student* stu, int m) {
	cout << "�����ѯ��ʽ��1.��ѧ�Ż�������ѯ   2.�������ѯ: ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		find_baseinfo_by_id_name(stu, m);
		break;
	case 2:
		find_baseinfo_by_dor(stu, m);
		break;
	}
}


/*
find_baseinfo_by_id_name()
��ѯ_ѧ��������Ϣ_ͨ��_id��name,��find_baseinfo()����
�������:Student*, m
*/
void find_baseinfo_by_id_name(Student* stu, int m) {
	cout << "ѡ��1.ʹ��ѧ�Ų�ѯ  2.ʹ������: ";
	int choice_2;
	cin >> choice_2;
	switch (choice_2) {
	case 1:
		find_baseinfo_by_id(stu, m);
	break;
	case 2:
		find_baseinfo_by_name( stu, m);
		break;
	}
}

void find_baseinfo_by_id(Student* stu, int m) {
	//��ѧ�Ų�ѯ����ӡ���
	cout << "����ѧ��: ";
	int id;
	cin >> id;
	bool flag_find_id = false;
	for (int i = 0; i < m; i++) {
		if (id == stu[i].get_ID()) {
			flag_find_id = true;
			cout << "ѧ�� ����    �Ա�  �������  �绰����\n";
			cout << stu[i];
			break;
		}
		if (i == m - 1 && !flag_find_id)
			cout << "  ��ID��¼������\n";
	}
}

void find_baseinfo_by_name(Student* stu, int m) {
	//ʹ��������ѯ����ӡ���
	cout << "��������: ";
	string name;
	cin >> name;
	bool flag_find_name = false;
	for (int i = 0; i < m; i++) {
		if (name == stu[i].get_name() ) {
			flag_find_name = true;
			cout << "ѧ��  ����  �Ա�   �������  �绰����\n";
			cout << stu[i];
			break;
		}
		if (i == m - 1 && !flag_find_name)
			cout << "  ��������¼������\n";
	}
}

/*
find_baseinfo_by_dor()
��ѯ_ѧ��������Ϣ_ͨ��_����,��find_baseinfo()����
�������Stuent*, m
*/
void find_baseinfo_by_dor(Student* stu, int m) {
	//�������ѯ����ӡ���
	cout << "���������: ";
	int dor_number;
	cin >> dor_number;
	cout << "ѧ��  ����  �Ա�   �������  �绰����\n";
	bool flag_find_dor = false;
	for (int i = 0; i < m; i++) {
		if (dor_number == stu[i].get_dor_number()) {
			flag_find_dor = true;
			cout << stu[i];
			cout << "\n";
		}
		if (i == m - 1 && !flag_find_dor)
			cout << "    �����¼������\n";
	}
}

/*��ѯ_����,��find()���ã���ʾ��Ӧ�ķ�����Ϣ
���������Student*, StudentScore*,m(ѧ����Ϣ����),n(������Ϣ����)
*/
void find_score(Student* stu, StudentScore* stu_score, int m, int n) {
	cout << "�����ѧ����ѧ��:";
	int id;
	cin >> id;
	bool flag_find_id = false;
	for (int i = 0; i < m; i++) {
		if (id == stu[i].get_ID()) {
			flag_find_id = true;
			cout << "\t\t\t\tѧ��: " << std::setiosflags(std::ios::left)
				<< std::setw(10) << stu[i].get_ID() << "����: "
				<< std::setw(10) << stu[i].get_name();
			break;
		}
		if (i == m - 1 && !flag_find_id) {
			cout << "\n\t\t��IDѧ����Ϣ��¼������\n";
		}
	}
	bool flag_find_score = false;
	int lesson_n = 0;
	double all_credit = 0;
	for (int i = 0; i < n; i++) {
		if (id == stu_score[i].get_ID()) {
			flag_find_score = true;
			cout << "\n" << stu_score[i];
			lesson_n++;
			all_credit += stu_score[i].get_actual_score();
		}
		if (i == n - 1 && !flag_find_score) {
			cout << "\n\t\t��ID�ɼ���¼������\n";
		}
	}
	cout << "\n\t\t����: " << lesson_n << "�ƣ�ʵ����ѧ��Ϊ: " << all_credit;
}

/*
delete_by_ID()
ɾ����ID��ص���Ϣ
*/
int delete_by_ID(Student * stu, StudentScore * stu_score, int &m, int &n) {
	cout << "ɾ����ѧ�ŵ����������Ϣ��\n����ѧ�ţ�";
	int ID;
	cin >> ID;
	//ɾ��ID��ص�ѧ��������Ϣ
	for (int i = 0; i < m; i++) {
		if (stu[i].get_ID() == ID) {
			int k = i;
			if (k == m - 1) {
				stu[i] = Student(); //ʹ��Ϊ��
				m--;
			}
			else {
				for (int j = k + 1; j < m; j++) {
					stu[j - 1] = stu[j];
				}
				m--;
			}
		}
	}
	//ɾ��ID��صĳɼ���Ϣ
	for (int i = n - 1; i >= 0; i--) {
		if (stu_score[i].get_ID() == ID) {
			int k = i;
			if (k == n - 1) {
				stu_score[i] = StudentScore(); //ʹ��Ϊ��
				n--;
			}
			else{
				for (int j = k + 1; j < n; j++) {
					stu_score[j - 1] = stu_score[j];
				}
				n--;
			}
		}
	}
	cout << "��ѧ�����������Ϣɾ���ɹ�\n";
	return 0;
};

/*����������,(����)��
���������StudentScore*, n(�ɼ�����)
*/
int sort_score(StudentScore * stu_score, int n)
{
	int choice;
	cout << "ѡ��1.���ۺϳɼ�����   2.��ʵ��ѧ������";
	cin >> choice;
	switch (choice) {
	case 1: {
		StudentScore temp;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (stu_score[j].get_total_score() < stu_score[j + 1].get_total_score()) {
					temp = stu_score[j];
					stu_score[j] = stu_score[j + 1];
					stu_score[j + 1] = temp;
				}
			}
		}
		break;
	}
	case 2: {
		StudentScore temp;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (stu_score[j].get_actual_score() < stu_score[j + 1].get_actual_score()) {
					temp = stu_score[j];
					stu_score[j] = stu_score[j + 1];
					stu_score[j + 1] = temp;
				}
			}
		}
		break;
	}
	}

	for (int i = 0; i < n; i++) {
		cout << "ѧ��: " << std::setiosflags(std::ios::left) << std::setw(4)
			<< stu_score[i].get_ID() << stu_score[i] << "\n";
	}
	return n;
};
