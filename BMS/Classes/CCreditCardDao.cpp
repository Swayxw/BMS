

#include "stdafx.h"
#include "CCreditCardDao.h"




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
	sprintf_s(aBuf, sizeof(aBuf), "%s##%s##%s##%s##%s##%d##%f##%f##%f##%f##%d##%d\n", pCard->getCardNum().c_str(),
		pCard->getPassword().c_str(), pCard->getAccount().c_str(), pCard->getBankName().c_str(), strDate,
		pCard->getBonuspoint(), pCard->getMoney(), pCard->getCredit(), pCard->getHandleChargeRate(),
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