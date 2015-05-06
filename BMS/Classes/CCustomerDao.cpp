

#include "stdafx.h"
#include "CCustomerDao.h"
#include "CToolKit.h"



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

CCustomer *CCustomerDao::parseCustomer(const char *pCustomerInfo)
{
	CCustomer *pCustomer = new CCustomer();
	
	char *pDellims = "##";
	char aFlag[9][CUSTOMER_INFO_MAX] = {'\0'};
	char *pBuf = const_cast<char *>(pCustomerInfo);
	char *pStr = NULL;
	char *p;
	int nIndex = 0;
	while ((pStr = strtok_s(pBuf, pDellims, &p)) != NULL)
	{
		strcpy_s(aFlag[nIndex], pStr);
		pBuf = NULL;
		nIndex++;
	}

	pCustomer->setAccount(aFlag[0]);
	pCustomer->setName(aFlag[1]);
	pCustomer->setGender(atoi(aFlag[2]));
	pCustomer->setIdNum(aFlag[3]);
	pCustomer->setPhoneNum(aFlag[4]);
	pCustomer->setAddress(aFlag[5]);
	pCustomer->setEmail(aFlag[6]);
	pCustomer->setCredit(atoi(aFlag[7]));

	struct tm temp;
	CToolKit::charToTime(aFlag[8], temp);
	pCustomer->setCreateDate(temp);

	return pCustomer;
}

CCustomer *CCustomerDao::FindByAccount(const char *pAccount)
{
	CCustomer *pCustomer = NULL;

	ifstream inFile;
	//打开文件
	inFile.open("Resource/Customer.txt", ios::in);
	if (!inFile)
	{
		return NULL;
	}
	//读取文件
	char aCustomerInfo[500] = { '\0' };
	CCustomer *pc = NULL;
	while (inFile.getline(aCustomerInfo, sizeof(aCustomerInfo)))
	{
		pc = parseCustomer(aCustomerInfo);
		if (pc != NULL)
		{
			if (strcmp(pAccount, pc->getAccount().c_str()) == 0)
			{
				pCustomer = pc;
				break;
			}
			delete pc;
			pc = NULL;
		}
	}
	//关闭文件
	inFile.close();
	return pCustomer;
}
bool CCustomerDao::IsExsit(const char *pAccount)
{
	if (FindByAccount(pAccount) != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}