//
//		BMS		CToolKit.h
//		Some tools and functiona for BMS
//		create by sway_xw 2015_04_29


#ifndef _BMS__CTOOLKIT_H_
#define _BMS__CTOOLKIT_H_
#include <AFX.h>
#include <string>
using namespace std;
class CToolKit
{
public:
	CToolKit();
	~CToolKit();

public:

	/** ��CString����ת��Ϊchar*���� */
	static void ToChars(char *pDim, CString strSrc, const int nSize);
	/* ��char*����ת��ΪCString���� */
	static CString ToString(char *pSrc, const int nSize);

	/* ���������ˮ�� */
	static void GenerateId(char *pDim, int nSize);

	static BOOL charToTime(const char *pVal, struct tm &outTime);
};



#endif