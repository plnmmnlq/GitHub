#pragma once
#ifndef __PCB_H__
#define __PCB_H__

//��������״̬����RUN״̬��û��ʵ������
#define READY -1
#define RUN 0
#define END 1
//���������
#define Rand_1_10 Rand(1,10)
#define Rand_1_50 Rand(1,50)
//����ģʽ
#define TURN_ON 0
#define TURN_OFF 1

#include<iostream>
using namespace std;

#include<string>
#include<time.h>
#include<stdlib.h>

//����������� ��ֵ��Χ[MIN,MAX]
int Rand(int MIN, int MAX);

struct PCB
{
	string name = "";
	int create_time = 0;
	int serve_time = 100;
	int priority = 0;
	int state = READY;
	PCB* next;
	//Ϊ�˷������������±���
	int Start_time = -1;
	int End_time = -1;
	int Run_time = 0;
};

class pcb
{
public:
	//Ĭ�Ͻ�����Ϊ5ִ�з���ռʽ��̬���ȼ��㷨
	pcb();
	pcb(bool Run_Mode, int Time_Slice, int Process_Num);
	~pcb();
	//��ӡPCB��Ϣ ԭʼ��Ϣ
	void dispaly();
	////��ӡ������Ϣ ָ���������Ʋ���ӡ��Ϣ
	//void dispaly(string name);
	//��ӡ��Ŀ�������Ϣ
	void display_all();
	//Ĭ�ϵĳ�ʼ��
	void init();
	//PCB�������� ���������5�����̣�������PCB����
	void createpcb();
	//����
	void run();

private:
	PCB* head;
	//�˴�ϵͳʱ����Ϊ100��Ϊ�˷�������ʼ��
	unsigned int SYSTEMCLOCK = 100;
	//ʱ��ƬĬ��Ϊһ
	unsigned int TIMESLICE = 1;
	//����ģʽ Ĭ�Ϸ���תʽ
	bool RUN_MODE = TURN_OFF;
	//������Ĭ��5
	unsigned int PROCESSNUM = 5;

	//PCB���н������� ʹ��ֱ�巨�Խ��̽��а����ȼ�ģʽ��������
	PCB* List(string name, int start_time, int run_time, int priority, PCB* head = NULL);
	PCB* List(PCB* curpcb);

	////Ѱ��ָ���Ľ���
	//PCB* Find(string progress, PCB* head);
	////�޸�ָ���Ľ���
	//PCB* Change(string progress, int state);
	//����ָ���Ľ���
	//void swap(PCB* curpcb);
	//void Swap(PCB* curpcb);
	//ɾ��ָ���Ľ���
	void Delete(PCB* curpcb);
};

#endif // !__PCB_H__
