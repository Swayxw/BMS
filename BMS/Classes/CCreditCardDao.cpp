

#include "stdafx.h"
#include "CCreditCardDao.h"
#include "CToolKit.h"
#include <vector>
#define CREDITCARD_INFO_LENGTH 500


CCreditCardDao::CCreditCardDao()
{

}

CCreditCardDao::~CCreditCardDao()
{

}

bool CCreditCardDao::save(CCreditCard *pCard)
{
	bool bRet = false;
	//准备数据
	char strDate[50] = {'\0'};
	strftime(strDate, sizeof(strDate), "%Y-%m-%d %H:%M:%S", &(pCard->getCreateDate()));

	char aBuf[500] = {'\0'};
	sprintf_s(aBuf, sizeof(aBuf), "%s##%s##%s##%s##%s##%d##%f##%f##%f##%d##%d\n", pCard->getCardNum().c_str(),
		pCard->getPassword().c_str(), pCard->getAccount().c_str(), pCard->getBankName().c_str(), strDate,
		pCard->getBonusPoint(), pCard->getMoney(), pCard->getCredit(), pCard->getHandleChargeRate(),
		pCard->getBillDay(), pCard->getRepaymentDay());

	string strBuf = aBuf;

	//打开文件
	ofstream outFile;
	outFile.open("Resource/CreditCard.txt", ios::app);
	if (!outFile)
	{
		return false;
	}

	//写文件
	if (outFile.write(strBuf.c_str(), strBuf.size()))
	{
		bRet = true;
	}
	else
	{
		bRet = false;
	}

	outFile.flush();
	outFile.close();
	return bRet;
}


bool CCreditCardDao::isExsit(const char *pCardNum)
{
	bool bRet = false;
	//打开文件
	ifstream inFile;
	inFile.open("Resource/CreditCard.txt", ios::in);
	if (!inFile)
	{
		return false;
	}

	//读取文件
	char aCreditCardInfo[CREDITCARD_INFO_LENGTH] = {'\0'};
	CCreditCard *p = NULL;
	while (inFile.getline(aCreditCardInfo, sizeof(aCreditCardInfo)))
	{
		p = praseCreditCard(aCreditCardInfo);
		if (p != NULL)
		{
			if (strcmp(pCardNum, p->getCardNum().c_str()) == 0)
			{
				bRet = true;
				delete p;
				p = NULL;
				break;
			}
			delete p;
			p = NULL;
		}
	}
	inFile.close();
	return bRet;
}


CCreditCard *CCreditCardDao::getCardByCardNum(const char *pCardNum)
{
	//打开文件
	ifstream inFile;
	inFile.open("Resource/CreditCard.txt", ios::in);
	if (!inFile)
	{
		return NULL;
	}

	//读取文件
	char aCreditCardInfo[CREDITCARD_INFO_LENGTH] = {'\0'};
	CCreditCard *p = NULL;
	while (inFile.getline(aCreditCardInfo, sizeof(aCreditCardInfo)))
	{
		p = praseCreditCard(aCreditCardInfo);
		if (p != NULL)
		{
			if (strcmp(p->getCardNum().c_str(), pCardNum))
			{
				return p;
			}
			delete p;
			p = NULL;
		}
	}

	inFile.close();
	return p;
}


bool CCreditCardDao::Update(CCreditCard *pCard)
{
	bool bRet = false;

	//读取方式打开文件
	ifstream inFile;
	inFile.open("Resource/CreditCard.txt", ios::in);
	if (!inFile)
	{
		return false;
	}
	vector<CCreditCard *> creditCrads;
	char aCreditCardInfo[CREDITCARD_INFO_LENGTH] = {'\0'};
	while (inFile.getline(aCreditCardInfo, sizeof(aCreditCardInfo)))
	{
		CCreditCard *tempCard = praseCreditCard(aCreditCardInfo);
		if (tempCard != NULL)
		{
			if (strcmp(tempCard->getCardNum().c_str(), pCard->getCardNum().c_str()) != 0)
			{
				creditCrads.push_back(tempCard);
			}
			else
			{
				creditCrads.push_back(pCard);
			}
		}
	}
	inFile.close();


	//写入方式打开文件
	ofstream outFile;
	outFile.open("Resource/CreditCard.txt", ios::out);
	outFile.close();

	for (int i = 0; i < creditCrads.size(); i++)
	{
		save(creditCrads[i]);
	}

	for (int i = 0; i < creditCrads.size(); i++)
	{
		if (creditCrads[i] != NULL)
		{
			delete creditCrads[i];
		}
	}
	creditCrads.clear();
	return true;
}



CCreditCard *CCreditCardDao::praseCreditCard(const char *pCreditCardInfo)
{
	char *pDllimes = "##";
	char aFlag[11][128] = {'\0'};
	char *pBuf = NULL;
	char *pStr = NULL;
	char *p;

	int nIndex = 0;
	while ((pStr = strtok_s(pBuf, pDllimes, &p)) != NULL)
	{
		strcpy_s(aFlag[nIndex], pStr);
		pBuf = NULL;
		nIndex++;
	}

	CCreditCard *pRet = new CCreditCard();
	pRet->setCardNum(aFlag[0]);
	pRet->setPassword(aFlag[1]);
	pRet->setAccount(aFlag[2]);
	pRet->setBankName(aFlag[3]);
	
	struct tm tempTime;
	CToolKit::charToTime(aFlag[4], tempTime);
	pRet->setCreateDate(tempTime);

	pRet->setBonusPoint(atoi(aFlag[5]));
	pRet->setMoney(atof(aFlag[6]));
	pRet->setCredit(atof(aFlag[7]));
	pRet->setHandleChargeRate(atof(aFlag[8]));
	pRet->setBillDay(atoi(aFlag[9]));
	pRet->setRepaymentDay(atoi(aFlag[10]));

	return pRet;
}