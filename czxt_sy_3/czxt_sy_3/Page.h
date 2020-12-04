#pragma once
#ifndef __PAGE_H__
#define __PAGE_H__

#include<iostream>
using namespace std;

#include<string>
#include<time.h>
#include<stdlib.h>

//随机数生成器 数值范围[MIN,MAX]
int Rand(int MIN, int MAX);

#define R_1_9 Rand(1,9)
#define R_1_99 Rand(1,99)

struct page
{
	int num = 0;
	bool flag = 0;
	int memory_num = 0;
	int disk_place = 0;
	bool Change_Flag = 0;

	page* next;
};	

class Page
{
public:
	Page(int num);
	Page();
	~Page();

private:
	unsigned int Page_Num = 6;
	page* head;
};
#endif // !__PAGE_H__
