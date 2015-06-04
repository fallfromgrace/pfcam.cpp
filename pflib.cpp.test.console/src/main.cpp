// pflib.cpp.test.console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "pfcam.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int port_count;
	int result = ::pfPortInit(&port_count);

	return 0;
}

