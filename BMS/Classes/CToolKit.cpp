



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
	int nLen = ::WideCharToMultiByte(CP_ACP, 0, pSrc, -1, NULL, 0, NULL, FALSE);
	//�����ֽ�����̬�����ڴ�
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
	//�ͷŻ�����
	strSrc.ReleaseBuffer();
	delete []pBuf;
}


CString CToolKit::ToString(char *pSrc, const int nSize)
{
	//�����ַ�������
	char *pBuf = new char[nSize+1];
	for (int i = 0; i < nSize; i++)
	{
		*(pBuf + i) = *(pSrc + i);
	}
	pBuf[nSize] = NULL;


	//���ֽ�ת��Ϊ���ַ�
	int nLen = ::MultiByteToWideChar(CP_ACP, 0, pBuf, -1, NULL, 0);
	wchar_t *pWBuf = new wchar_t[nLen + 1];
	memset(pWBuf, 0, (nLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, pBuf, -1, (LPWSTR)pWBuf, nLen);
	delete []pBuf;

	//�����ַ�������
	CString sRet(pWBuf);
	delete []pWBuf;

	return sRet;
}