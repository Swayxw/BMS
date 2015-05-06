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

#define CUSTOMER_INFO_MAX  128

class CCustomerDao
{
public:
	CCustomerDao();
	~CCustomerDao();


public:
	BOOL Save(CCustomer *pCustomer);
	/*判断是否存在以参数为帐户的用户， 存在返回true， 否则返回false*/
	bool IsExsit(const char *pAccount);
	/*通过用户账户查找用户，返回用户的对象指针*/
	CCustomer *FindByAccount(const char *pAccount);
private:
	/*解析客户信息的字符串，返回一个客户对象指针*/
	CCustomer *parseCustomer(const char *pCustomerInfo);
};



#endif
