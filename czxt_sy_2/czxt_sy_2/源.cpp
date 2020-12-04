#include "pcb.h"

int main()
{
	bool mode = 1;
	bool flag = 1;
	unsigned int timeslice = 1;
	unsigned int processnum = 5;
start:
	cout << "\n是否指定参数：0-------指定\n              1-------默认\n";
	cin >> flag;
	cout << "\n进程模拟方式: 0-------时间片轮转法\n              1-------非抢占式静态优先级算法\n";
	cout << "\n输入进程模拟方式：";
	cin >> mode;
	if (mode)
	{
		if (flag)pcb test;
		else
		{
		cin_processnum_0:
			cout << "\n输入进程数：";
			cin >> processnum;
			if (timeslice < 0)
			{
				cout << "\n进程数不允许为负数！\n";
				goto cin_processnum_0;
			}
			pcb test(TURN_OFF, timeslice, processnum);
		}
	}
	else
	{
		if (flag)pcb test(TURN_ON, timeslice, processnum);
		else
		{
		cin_timeslice:
			cout << "\n输入时间片长度：";
			cin >> timeslice;
			if (timeslice <= 0)
			{
				cout << "\n时间片不允许为负数！\n";
				goto cin_timeslice;
			}
		cin_processnum:
			cout << "\n输入进程数：";
			cin >> processnum;
			if (timeslice < 0)
			{
				cout << "\n进程数不允许为负数！\n";
				goto cin_processnum;
			}
			pcb test(TURN_ON, timeslice, processnum);
		}
	}
	cout << "\n\n是否再次运行：0-------再次执行\n              1-------结束程序\n";
	cin >> mode;
	if (!mode)goto start;
	system("pause");
	return 0;
}