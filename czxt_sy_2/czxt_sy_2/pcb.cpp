#include "pcb.h"

int Rand(int MIN, int MAX)
{
	srand((unsigned)time(NULL) + rand());
	return (rand() % (MAX - MIN + 1)) + MIN;
};

pcb::pcb()
{
	pcb(TURN_OFF, 1, 5);
};

pcb::pcb(bool Run_Mode, int Time_Slice, int Process_Num)
{
	PROCESSNUM = Process_Num;
	RUN_MODE = Run_Mode;
	TIMESLICE = Time_Slice;
	if (RUN_MODE)
	{
		cout << "-------------------------------------------------" << endl;
		cout << "|                                               |" << endl;
		cout << "|  程序将以非抢占式静态优先级算法进行进程模拟   |" << endl;
		cout << "|                                               |" << endl;
		cout << "-------------------------------------------------" << endl << endl;
	}
	else
	{
		cout << "-------------------------------------------------" << endl;
		cout << "|                                               |" << endl;
		cout << "|      程序将以时间片轮转法算法进行进程模拟     |" << endl;
		cout << "|                 时间片长度为：" << TIMESLICE << "               |" << endl;
		cout << "|                                               |" << endl;
		cout << "-------------------------------------------------" << endl << endl;
	}
	init();
};


pcb::~pcb()
{
}

void pcb::dispaly()
{
	PCB* curpcb = head;
	cout << "-------------------------------------------------" << endl;
	cout << "|                                               |" << endl;
	cout << "|程序计数器:\t\t" << SYSTEMCLOCK << "\t\t\t\|" << endl;
	cout << "|                                               |" << endl;
	cout << "-------------------------------------------------" << endl << endl;
	cout << "名称\t创建时间\t服务时间\t优先级\t\t状态" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	while (curpcb)
	{
		cout << curpcb->name << "\t" << curpcb->create_time << "\t\t" << curpcb->serve_time << "\t\t" << curpcb->priority << "\t\t";
		if (curpcb->state == READY)cout << "就绪" << endl;
		else cout << "结束" << endl;
		curpcb = curpcb->next;
	}
	cout << endl << endl << endl;
}

void pcb::display_all()
{
	PCB* curpcb = head;
	cout << "----------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|                                               |" << endl;
	cout << "|程序计数器:\t\t" << SYSTEMCLOCK << "\t\t\t\|" << endl;
	cout << "|                                               |" << endl;
	cout << "-------------------------------------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "名称\t开始时间\t结束时间\t运行时间\t平均周转时间\t带权周转时间" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	while (curpcb)
	{
		cout << curpcb->name << "\t" << curpcb->Start_time << "\t\t" << curpcb->End_time << "\t\t" << curpcb->Run_time << "\t";
		cout << "\t" << to_string((double)(((double)curpcb->End_time - (double)curpcb->Start_time) / (double)PROCESSNUM));
		cout << "\t" << to_string((double)((((double)curpcb->End_time - (double)curpcb->Start_time) / (double)curpcb->Run_time) / (double)PROCESSNUM)) << endl;
		curpcb = curpcb->next;
	}

}

void pcb::init()
{
	head = NULL;
	createpcb();
	run();
	display_all();
}

void pcb::createpcb()
{
	PCB* curpcb;
	cout << "\n";
	string temp = "P";
	head = List("P0", Rand_1_10, Rand_1_10, Rand_1_50, head);
	curpcb = head;
	SYSTEMCLOCK = curpcb->create_time;
	for (size_t i = 1; i < PROCESSNUM; i++)
	{
		head = List(temp + to_string(i), Rand_1_10, Rand_1_10, Rand_1_50, head);
		if (curpcb && curpcb->create_time <= SYSTEMCLOCK)SYSTEMCLOCK = curpcb->create_time;
		if (curpcb)curpcb = curpcb->next;
	}
	dispaly();
}

void pcb::run()
{
	PCB* curpcb = head;

	//curpcb->priority--;
	//if (curpcb->serve_time > 0 && curpcb->next != NULL && curpcb->next->priority > curpcb->priority)
	//{
	//	List(curpcb);
	//	Delete(curpcb);
	//}
	if (RUN_MODE)
	{
		while (curpcb)
		{
			if (curpcb->create_time <= SYSTEMCLOCK && curpcb->state == READY)
			{
				if (curpcb->Start_time < 0)curpcb->Start_time = SYSTEMCLOCK;
				curpcb->serve_time = 0;
				curpcb->state = END;
				SYSTEMCLOCK = SYSTEMCLOCK + curpcb->Run_time;
				curpcb->End_time = SYSTEMCLOCK + 1;
				curpcb = head;
				dispaly();
			}
			else
				curpcb = curpcb->next;
		}
	}
	else
	{
		int end_process = 0;
		while (end_process != PROCESSNUM)
		{
			while (curpcb)
			{
				if (curpcb->create_time <= SYSTEMCLOCK && curpcb->state == READY)
				{
					if (curpcb->Start_time < 0)curpcb->Start_time = SYSTEMCLOCK;
					curpcb->serve_time -= TIMESLICE;
					if (curpcb->serve_time <= 0)
					{
						curpcb->End_time = SYSTEMCLOCK + 1;
						curpcb->state = END;
						end_process++;
						SYSTEMCLOCK = SYSTEMCLOCK + TIMESLICE - (0 - curpcb->serve_time);
						curpcb->serve_time = 0;
					}
					else
						SYSTEMCLOCK = SYSTEMCLOCK + TIMESLICE;
				}
				curpcb = curpcb->next;
			}
			dispaly();
			curpcb = head;
		}
	}

}

//void pcb::swap(PCB* curpcb)
//{
//	//PCB* temp = curpcb;
//	//PCB* cur, * pre;
//	//PCB* tempcura, * tempprea, * tempcurb, * temppreb;
//	//if (curpcb == NULL || curpcb->next == NULL)cout << "error:交换节点其中一个或全为空" << endl;
//	//curpcb = curpcb->next;
//	//while (temp&&temp->next)
//	//{
//	//	pre = temp->next;
//	//	temp->next = pre->next;
//	//	pre->next = temp;
//	//	if(pre->next=)
//	//}
//	PCB* tempcura = curpcb, * tempprea = curpcb->next, * tempcurb = curpcb->next, * temppreb = curpcb->next->next;
//};

PCB* pcb::List(string name, int start_time, int run_time, int priority, PCB* head)
{
	PCB* curpcb = head;
	PCB* prepcb = NULL;
	PCB* newpcb = NULL;

	while ((curpcb != NULL) && (curpcb->priority > priority))
	{
		prepcb = curpcb;
		curpcb = curpcb->next;
	}

	newpcb = new PCB;

	if (newpcb == NULL)
		return head;

	newpcb->name = name;
	newpcb->create_time = start_time;
	newpcb->serve_time = run_time;
	newpcb->Run_time = run_time;
	newpcb->priority = priority;
	newpcb->state = READY;

	if (prepcb == NULL)
	{
		newpcb->next = curpcb;
		return newpcb;
	}
	else
	{
		prepcb->next = newpcb;
		newpcb->next = curpcb;
		return head;
	}

	return head;
}

PCB* pcb::List(PCB* curpcb)
{
	return head = List(curpcb->name, curpcb->create_time, curpcb->Run_time, curpcb->priority, head);
}

//void pcb::Swap(PCB* curpcb)
//{
//	PCB temp;
//	temp.name = curpcb->name;
//	temp.priority = curpcb->priority;
//	temp.run_time = curpcb->run_time;
//	temp.create_time = curpcb->create_time;
//	temp.state = curpcb->state;
//	curpcb->name = curpcb->next->name;
//	curpcb->priority = curpcb->next->priority;
//	curpcb->run_time = curpcb->next->run_time;
//	curpcb->create_time = curpcb->next->create_time;
//	curpcb->state = curpcb->next->state;
//	curpcb->next->name = temp.name;
//	curpcb->next->priority = temp.priority;
//	curpcb->next->run_time = temp.run_time;
//	curpcb->next->create_time = temp.create_time;
//	curpcb->next->state = temp.state;
//	//PCB* temp = curpcb->next->next;
//	//curpcb->next->next = curpcb->next;
//	//curpcb->next = curpcb;
//	//curpcb = temp;
//}

void pcb::Delete(PCB* curpcb)
{
	PCB* p = head->next, * q = head;
	while (p)
	{
		if (p == curpcb)
		{
			q->next = p->next;
			delete p, q;
			break;
		}
		q = p;
		p = p->next;
	}
}
