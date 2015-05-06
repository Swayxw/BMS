



#include "stdafx.h"
#include "CToolKit.h"



CToolKit::CToolKit()
{
}

CToolKit::~CToolKit()
{

}

void CToolKit::ToChars(char *pDim, CString strSrc, const int nSize)
{
	//清空pDim指向的区域内容
	memset(pDim, 0, nSize);

	//获取指向strSrc的内部字符缓冲区的指针
	wchar_t *pSrc = strSrc.GetBuffer(strSrc.GetLength());
	//获取strSrc中的字节数
	int nLen = ::WideCharToMultiByte(CP_ACP, 0, pSrc, -1, NULL, 0, NULL, FALSE);
	//根据字节数动态分配内存
	char *pBuf = new char[nLen];
	WideCharToMultiByte(CP_ACP, 0, pSrc, -1, pBuf, nLen, NULL, FALSE);
	if (nLen > nSize)
	{
		nLen = nSize;
	}
	for (int i = 0; i < nLen; i++)
	{
		*(pDim + i) = *(pBuf + i);
	}
	//释放缓冲区
	strSrc.ReleaseBuffer();
	delete []pBuf;
}


CString CToolKit::ToString(char *pSrc, const int nSize)
{
	//拷贝字符串数组
	char *pBuf = new char[nSize+1];
	for (int i = 0; i < nSize; i++)
	{
		*(pBuf + i) = *(pSrc + i);
	}
	pBuf[nSize] = NULL;


	//多字节转换为宽字符
	int nLen = ::MultiByteToWideChar(CP_ACP, 0, pBuf, -1, NULL, 0);
	wchar_t *pWBuf = new wchar_t[nLen + 1];
	memset(pWBuf, 0, (nLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, pBuf, -1, (LPWSTR)pWBuf, nLen);
	delete []pBuf;

	//构造字符串对象
	CString sRet(pWBuf);
	delete []pWBuf;

	return sRet;
}


void CToolKit::GenerateId(char *pDim, int nSize)
{
	//生成当前日期
	time_t t = time(NULL);
	struct tm *pTime = new tm();
	localtime_s(pTime, &t);
	char aTime[15] = { '\0' };
	strftime(aTime, sizeof(aTime), "%Y%m%d%H%M%S", pTime);
	strcat_s(pDim, nSize, aTime);
	delete pTime;
	//生成最后五位随机数
	srand(time(0));
	int nRand = rand() % 100000;
	char aBuf[6] = { '\0' };
	sprintf_s(aBuf, sizeof(aBuf), "%05d", nRand);
	strcat_s(pDim, nSize, aBuf);
}


BOOL CToolKit::charToTime(const char *pVal, struct tm &outTime)
{
	//BOOL bRet = FALSE;

	//处理字符串文本去除'-'和':'
	//string tempStr = pVal;
	//for (string::iterator it = tempStr.begin(); it != tempStr.end(); it++)
	//{
		//if (((*it) == '-') || ((*it) == ':'))
		//{
			//tempStr.erase(it);
		//}
	//}
	char *pBeginPos = const_cast<char *>(pVal);
	char *pPos = strstr(pBeginPos, "-");
	if (pPos == NULL)
	{
		printf("strDateStr[%s] err \n", pVal);
		//bRet = FALSE;
		return FALSE;
	}
	int iYear = atoi(pBeginPos);
	int iMonth = atoi(pPos + 1);

	pPos = strstr(pPos + 1, "-");
	if (pPos == NULL)
	{
		printf("strDateStr[%s] err \n", pVal);
		//bRet = FALSE;
		return FALSE;
	}
	int iDay = atoi(pPos + 1);
	int iHour = 0;
	int iMin = 0;
	int iSec = 0;
	pPos = strstr(pPos + 1, " ");
	//为了兼容有些没有精确到时分秒的
	if (pPos != NULL)
	{
		iHour = atoi(pPos + 1);
		pPos = strstr(pPos+1, ":");
		if (pPos != NULL)
		{
			iMin = atoi(pPos + 1);
			pPos = strstr(pPos + 1, ":");
			if (pPos != NULL)
			{
				iDay = atoi(pPos + 1);
			}
		}
	}
	
	memset(&outTime, 0, sizeof(outTime));
	outTime.tm_sec = iSec;
	outTime.tm_min = iMin;
	outTime.tm_hour = iHour;
	outTime.tm_mday = iDay;
	outTime.tm_mon = iMonth - 1;
	outTime.tm_year = iYear - 1900;

	return TRUE;
}