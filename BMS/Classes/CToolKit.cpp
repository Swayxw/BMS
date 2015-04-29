



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
	int nLen = ::WideCharToMultiByte(CP_ACP, 0, pSrc, -1, );
}