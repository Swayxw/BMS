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

	/** 将CString类型转换为char*类型 */
	static void ToChars(char *pDim, CString strSrc, const int nSize);
	/* 将char*类型转换为CString类型 */
	static CString ToString(char *pSrc, const int nSize);

	/* 生成随机流水号 */
	static void GenerateId(char *pDim, int nSize);

	static BOOL charToTime(const char *pVal, struct tm &outTime);
};



#endif