//
//	BMS		CCreditCardDao.h
//	���屣��Ͳ������ÿ���һЩ��Ϊ
//	create by sway_xw   2015_05_11
//

#ifndef _BMS__CCREDITCARDDAO_H_
#define _BMS__CCREDITCARDDAO_H_

#include <windows.h>
#include <fstream>
#include "CCreditCard.h"


class CCreditCardDao
{
public:
	CCreditCardDao();
	~CCreditCardDao();

public:
	bool save(CCreditCard *pCard);
};


#endif