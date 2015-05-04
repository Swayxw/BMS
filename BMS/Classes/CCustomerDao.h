//		BMS		CCustomerDao.h
//		对客户信息进行IO操作
//		create by sway_xw 2015_05_03
//


#ifndef _BMS__CCUSTOMERDAO_H_
#define _BMS__CCUSTOMERDAO_H_

#include <windows.h>
#include <fstream>
#include "CCustomer.h"
using namespace std;


class CCustomerDao
{
public:
	CCustomerDao();
	~CCustomerDao();


public:
	BOOL Save(CCustomer *pCustomer);
};



#endif
