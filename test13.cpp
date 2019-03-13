#include <stdio.h>

char data[7]={'a','b','c','d','e','f','g'};

int getCount(int nNumber)
{
	if(nNumber = 1)
		return 1;
	return nNumber*getCount(nNumber-1);
}

#if 0
int main()
{
	int nNumber = 7;
	int nTotal = getCount(nNumber);

	return 0;
}
#endif