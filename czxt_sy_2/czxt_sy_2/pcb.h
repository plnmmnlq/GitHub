#pragma once
#ifndef __PCB_H__
#define __PCB_H__

//三种运行状态其中RUN状态并没有实际作用
#define READY -1
#define RUN 0
#define END 1
//两种随机数
#define Rand_1_10 Rand(1,10)
#define Rand_1_50 Rand(1,50)
//运行模式
#define TURN_ON 0
#define TURN_OFF 1

#include<iostream>
using namespace std;

#include<string>
#include<time.h>
#include<stdlib.h>

//随机数生成器 数值范围[MIN,MAX]
int Rand(int MIN, int MAX);

struct PCB
{
	string name = "";
	int create_time = 0;
	int serve_time = 100;
	int priority = 0;
	int state = READY;
	PCB* next;
	//为了方便计算加入以下变量
	int Start_time = -1;
	int End_time = -1;
	int Run_time = 0;
};

class pcb
{
public:
	//默认进程数为5执行非抢占式静态优先级算法
	pcb();
	pcb(bool Run_Mode, int Time_Slice, int Process_Num);
	~pcb();
	//打印PCB信息 原始信息
	void dispaly();
	////打印进程信息 指定进程名称并打印信息
	//void dispaly(string name);
	//打印题目所需的信息
	void display_all();
	//默认的初始化
	void init();
	//PCB建立函数 生成随机的5个进程，并建立PCB队列
	void createpcb();
	//运行
	void run();

private:
	PCB* head;
	//此处系统时间设为100是为了方便程序初始化
	unsigned int SYSTEMCLOCK = 100;
	//时间片默认为一
	unsigned int TIMESLICE = 1;
	//运行模式 默认非轮转式
	bool RUN_MODE = TURN_OFF;
	//进程数默认5
	unsigned int PROCESSNUM = 5;

	//PCB队列建立函数 使用直插法对进程进行按优先级模式进行排序
	PCB* List(string name, int start_time, int run_time, int priority, PCB* head = NULL);
	PCB* List(PCB* curpcb);

	////寻找指定的进程
	//PCB* Find(string progress, PCB* head);
	////修改指定的进程
	//PCB* Change(string progress, int state);
	//交换指定的进程
	//void swap(PCB* curpcb);
	//void Swap(PCB* curpcb);
	//删除指定的进程
	void Delete(PCB* curpcb);
};

#endif // !__PCB_H__
