// AutoRun_Startup_Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>
#include <Shlobj.h>
#pragma comment(lib, "shell32.lib")


BOOL AutoRun_Startup(char *lpszSrcFilePath, char *lpszDestFileName)
{
	BOOL bRet = FALSE;
	char szStartupPath[MAX_PATH] = {0};
	char szDestFilePath[MAX_PATH] = {0};
	// ��ȡ ��������Ŀ¼ ·��
	bRet = ::SHGetSpecialFolderPath(NULL, szStartupPath, CSIDL_STARTUP, TRUE);
	printf("szStartupPath=%s\n", szStartupPath);
	if (FALSE == bRet)
	{
		return FALSE;
	}
	// ���쿽���� Ŀ���ļ�·��
	::wsprintf(szDestFilePath, "%s\\%s", szStartupPath, lpszDestFileName);
	// �����ļ�����������Ŀ¼��
	bRet = ::CopyFile(lpszSrcFilePath, szDestFilePath, FALSE);
	if (FALSE == bRet)
	{
		int err = GetLastError();
		return FALSE;
	}

	return TRUE;
}


int _tmain(int argc, _TCHAR* argv[])
{
	if (FALSE == AutoRun_Startup("E:\\Dten\\other demo\\common\\CppTest.exe", "CppTest.exe"))
	{
		printf("Startup Error!\n");
	}
	printf("Startup OK!\n");

	system("pause");
	return 0;
}

