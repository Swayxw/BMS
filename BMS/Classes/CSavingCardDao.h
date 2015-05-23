//
//	BMS		CSavingCardDao.h
//	������������һЩ����
//	create by sway_xw 2015_05_06
//


#ifndef _BMS__CSAVINGCARDDAO_H_
#define _BMS__CSAVINGCARDDAO_H_

#include <windows.h>
#include <fstream>
#include "CSavingCard.h"


class CSavingCardDao
{
public:
	CSavingCardDao();
	~CSavingCardDao();

public:

	BOOL save(CSavingCard *pCard);
	CSavingCard *getCardByCardNum(const char *pCardNum);
	bool isExsit(const char *pCardNum);
	bool Update(CSavingCard *pCard);
private:
	CSavingCard *praseSavingCard(const char *pSavingCardInfo);
};

#endif