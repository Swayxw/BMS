//		BMS		CCustomerDao.h
//		�Կͻ���Ϣ����IO����
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
	/*�ж��Ƿ�����Բ���Ϊ�ʻ����û��� ���ڷ���true�� ���򷵻�false*/
	bool IsExsit(const char *pAccount);
	/*ͨ���û��˻������û��������û��Ķ���ָ��*/
	CCustomer *FindByAccount(const char *pAccount);
private:
	/*�����ͻ���Ϣ���ַ���������һ���ͻ�����ָ��*/
	CCustomer *parseCustomer(const char *pCustomerInfo);
};



#endif
