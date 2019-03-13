#include <iostream>
#include <iomanip>
#include <chrono>
#include <windows.h>
#include <time.h>
using namespace std;


bool test(int value)
{
	return value==1||value==2;
}


#if 0
int main()
{

	// only copy
	char str1[]="a";//
	char str2[]="a";//
	const char str3[]="a";//
	const char str4[]="a";//

	// same addr
	const char *str5="a";
	const char *str6="a";

	// == is to compare addrs
	cout<<boolalpha<<(str1==str2)<<endl;
	cout<<boolalpha<<(str3==str4)<<endl;
	cout<<boolalpha<<(str5==str6)<<endl;

	printf("%d\n",sizeof(long));
	printf("%d\n",sizeof(long long));


	cout<<boolalpha<<test(1)<<endl;
	cout<<boolalpha<<test(2)<<endl;
	cout<<boolalpha<<test(3)<<endl;
	return 0;
}
#endif

