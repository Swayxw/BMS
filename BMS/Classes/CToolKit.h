//
//		BMS		CToolKit.h
//		Some tools and functiona for BMS
//		create by sway_xw 2015_04_29


#ifndef _BMS__CTOOLKIT_H_
#define _BMS__CTOOLKIT_H_
#include <AFX.h>
class CToolKit
{
public:
	CToolKit();
	~CToolKit();

public:

	//��CString����ת��Ϊchar*����
	static void ToChars(char *pDim, CString strSrc, const int nSize);

	static CString ToString(char *pSrc, const int nSize);

};



#endif