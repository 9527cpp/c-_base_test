#include <string.h>
#include <stdio.h>
using namespace std;

void strReserveByChar(char *strSrc,char chChar)
{
    char * p = strSrc;
    int nStart = 0;
    int nStop = 0;
    while(1)
    {
        char chTemp = *p;
        if(chTemp == 0)break;
        if(chTemp == chChar)
        {
            for(int i= nStart;i<nStop/2;i++)
            {
                p[i]^=p[nStop-1-i]^=p[i]^=p[nStop-1-i];
            }
            nStart = nStop;
        }
        p++;
        nStop++;
    }
}










template<typename MsgType,typename MsgDerived> 
class MsgBase
{
typedef void (MsgDerived::*MsgHandleFunc)();
       
typedef struct tagMsgHandle
{
	MsgType mtType;
	MsgHandleFunc mhfFun;
}MsgHandle;

typedef struct tagMsg
{
	MsgType mtType;
	void * pArg; 
}Msg;

public:
	MsgBase(){}
	~MsgBase(){}
	virtual void MsgProcess()
	{
	    /// peek msg
            
	}
	virtual void RegistMsgHandles(MsgType mt,MsgHandleFunc mhfFun)
	{
        gMsgHandle[mt].mtType =  mt;
        gMsgHandle[mt].mhfFun =  mhfFun;	   
	}
private:
	MsgHandle gMsgHandle[MsgType::MSG_MAX];
};


enum ReportType {
    MSG_0,
    MSG_1,
    MSG_2,
    MSG_MAX
};
class MsgDerived:public MsgBase<ReportType,MsgDerived>
{
public:
    void Msg0_handle(){} 
    void Msg1_handle(){}
    void Msg2_handle(){}   
};

int main()
{
    MsgDerived rtMsg;
    rtMsg.RegistMsgHandles(MSG_0,&MsgDerived::Msg0_handle);
    rtMsg.RegistMsgHandles(MSG_1,&MsgDerived::Msg1_handle);
    rtMsg.RegistMsgHandles(MSG_2,&MsgDerived::Msg2_handle);
    return 0;
}