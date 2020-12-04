#include"Page.h"

int Rand(int MIN, int MAX)
{
	srand((unsigned)time(NULL) + rand());
	return (rand() % (MAX - MIN + 1)) + MIN;
};

Page::Page(int num)
{
}

Page::Page()
{
}

Page::~Page()
{
}

