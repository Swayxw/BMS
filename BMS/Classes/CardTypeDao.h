//		BMS  CardTypeDao.h
//		定义保存卡类型的操作
//		create by sway_xw
//
//


#ifndef _BMS__CARDTYPEDAO_H_
#define _BMS__CARDTYPEDAO_H_

#include <windows.h>
#include <string>
#include <fstream>
using namespace std;


struct CardTypeStruct
{
	CardTypeStruct()
	{
		strcpy_s(m_aCardNum, "");
		m_nType = 0;
	}
	char m_aCardNum[21];
	int m_nType;
};


class CardTypeDao
{
public:
	CardTypeDao();
	~CardTypeDao();

public:
	BOOL saveCardType(const char *pCardNum, int nType);
	bool getTypeByCardNum(const char *pCardNum, int &nType);
	CardTypeStruct *praseCardType(char *pCardTypeInfo);
};
#endif