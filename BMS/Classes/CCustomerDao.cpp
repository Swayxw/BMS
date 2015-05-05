

#include "stdafx.h"
#include "CCustomerDao.h"



CCustomerDao::CCustomerDao()
{

}


CCustomerDao::~CCustomerDao()
{

}


BOOL CCustomerDao::Save(CCustomer *pCustomer)
{
	BOOL bRet = FALSE;
	//格式化信息
	char strTime[20] = {'\0'};
	strftime(strTime, sizeof(strTime), "%Y-%m-%d %H:%M:%S", &(pCustomer->getCreatDate()));
	char buff[220] = {'\0'};
	//int nLen = pCustomer->getAccount().size() + pCustomer->getName().size() + pCustomer->getAddress().size() + pCustomer->getIdNum().size() + pCustomer->getPhoneNum().size() + pCustomer->getEmail().size() + 2;
	sprintf_s(buff, sizeof(buff), "%s##%s##%d##%s##%s##%s##%s##%d##%s\n", pCustomer->getAccount().c_str(), pCustomer->getName().c_str(),
		pCustomer->getGender(), pCustomer->getIdNum().c_str(), pCustomer->getPhoneNum().c_str(), 
		pCustomer->getAddress().c_str(), pCustomer->getEmail().c_str(), pCustomer->getCredit(), strTime);


	string saveStr = buff;
	ofstream outFile;
	//打开文件
	outFile.open("Resource/Customer.txt", ios::app);
	if (!outFile)
	{
		return FALSE;
	}
	//写入数据
	if (outFile.write(saveStr.c_str(), saveStr.size()))
	{
		bRet = TRUE;
	}
	else
	{
		bRet = FALSE;
	}
	//清除缓存
	outFile.flush();
	//关闭文件
	outFile.close();

	return bRet;
}