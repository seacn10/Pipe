// client.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "..\Commu\PipeCommuUtils.h"
#include "..\Commu\PipeUtils.h"
#include <iostream>


DWORD WriteMsg(void** lpBuffer, LPDWORD dwSize)
{
	*lpBuffer = new char[15];
	memcpy(*lpBuffer, "hello server", 14);
	*dwSize = 15;
	return *dwSize;
}

DWORD ReadMsg(void* lpBuffer, LPDWORD dwSize)
{
	char* lpBuf = (char*)lpBuffer;
	std::cout<<lpBuf<<std::endl;
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CALLBACKFUNC callFunc = {0};
	callFunc.readFunc = (PipeReadFunc)ReadMsg;
	callFunc.writeFunc = (PipeWriteFunc)WriteMsg;

	PipeCommuUtils commu;
	commu.SetCallbackFunc(callFunc);
	commu.StartClient(PIPENAME);

	getchar();
	return 0;
}

