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
 
 
 
enum  MsgTypeBtn {
	MSG_BTN_START,
	MSG_BTN_STOP,
	MSG_BTN_EXTRA,
	MSG_BTN_DESTROY,
	MSG_BTN_MAX
};


#define ENUM_CLASS_DECLARE(cls_type, enum_type)/
 public: enum_type  m_val; /
 public: /
cls_type ( const enum_type& s): m_val(s) {} ; /
bool operator == ( const enum_type& cs ) { /
 if ( m_val == m_val ) return true; /
else return false; } /
operator enum_type() { return m_val; };


template<typename T>
class Test
{
    
};


template<typename T>
void RegistAll(int mtMax)
{
    T mt;
    while(mt != mtMax)
    {
        mt =(T)( mt + T(1));
    }
}
 
int main()
{
    //use uuuu;
    //thread_wrapper *tw= new thread_final();
    //uuuu.test(tw);
    
    RegistAll<MsgTypeBtn>(MsgTypeBtn::MSG_BTN_MAX);
    
    return 0;
}