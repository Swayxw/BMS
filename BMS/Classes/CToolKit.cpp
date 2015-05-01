



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