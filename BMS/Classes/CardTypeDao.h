//		BMS  CardTypeDao.h
//		���屣�濨���͵Ĳ���
//		create by sway_xw
//
//


#ifndef _BMS__CARDTYPEDAO_H_
#define _BMS__CARDTYPEDAO_H_

#include <windows.h>
#include <string>
#include <fstream>
using namespace std;


class CardTypeDao
{
public:
	CardTypeDao();
	~CardTypeDao();

public:
	BOOL saveCardType(const char *pCardNum, int nType);
};
#endif