#include "pcb.h"

int main()
{
	bool mode = 1;
	bool flag = 1;
	unsigned int timeslice = 1;
	unsigned int processnum = 5;
start:
	cout << "\n�Ƿ�ָ��������0-------ָ��\n              1-------Ĭ��\n";
	cin >> flag;
	cout << "\n����ģ�ⷽʽ: 0-------ʱ��Ƭ��ת��\n              1-------����ռʽ��̬���ȼ��㷨\n";
	cout << "\n�������ģ�ⷽʽ��";
	cin >> mode;
	if (mode)
	{
		if (flag)pcb test;
		else
		{
		cin_processnum_0:
			cout << "\n�����������";
			cin >> processnum;
			if (timeslice < 0)
			{
				cout << "\n������������Ϊ������\n";
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
			cout << "\n����ʱ��Ƭ���ȣ�";
			cin >> timeslice;
			if (timeslice <= 0)
			{
				cout << "\nʱ��Ƭ������Ϊ������\n";
				goto cin_timeslice;
			}
		cin_processnum:
			cout << "\n�����������";
			cin >> processnum;
			if (timeslice < 0)
			{
				cout << "\n������������Ϊ������\n";
				goto cin_processnum;
			}
			pcb test(TURN_ON, timeslice, processnum);
		}
	}
	cout << "\n\n�Ƿ��ٴ����У�0-------�ٴ�ִ��\n              1-------��������\n";
	cin >> mode;
	if (!mode)goto start;
	system("pause");
	return 0;
}