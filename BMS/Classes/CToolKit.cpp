



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
	//���pDimָ�����������
	memset(pDim, 0, nSize);

	//��ȡָ��strSrc���ڲ��ַ���������ָ��
	wchar_t *pSrc = strSrc.GetBuffer(strSrc.GetLength());
	//��ȡstrSrc�е��ֽ���
	int nLen = ::WideCharToMultiByte(CP_ACP, 0, pSrc, -1, );
}