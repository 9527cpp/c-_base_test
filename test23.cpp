#include <iostream>
using namespace std;


class platform_thread
{
public:
    platform_thread(){}
    ~platform_thread(){} 
public:
    void init(){printf("this is platform_thread init\r\n");}      
};
 
class thread_wrapper
{
public:
    thread_wrapper(){}
    ~thread_wrapper(){}  
public:
    virtual void Init()=0;      
}; 
 
class thread_final:public  thread_wrapper,public platform_thread
{
public:
     thread_final(){}
public:
    virtual void Init(){platform_thread::init();}            
};
 
class use
{
public:
    void test(thread_wrapper * wrapper){wrapper->Init();}    
};
 
int main()
{
    use uuuu;
    thread_wrapper *tw= new thread_final();
    uuuu.test(tw);
    return 0;
}