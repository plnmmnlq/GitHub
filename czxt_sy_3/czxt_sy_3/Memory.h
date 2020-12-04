#pragma once
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include"Page.h"

struct work
{
	string name = NULL;
	int Page_Num = 0;
	int Memory_Num = 0;
	work* next;
};

class Memory
{
public:
	Memory();
	void Run();
	~Memory();

private:
	int Memory_Size = 0;
	work* workhead = NULL;
};


class FIFO
{
public:
	FIFO();
	~FIFO();

private:

};

#endif // !__MEMORY__H__
