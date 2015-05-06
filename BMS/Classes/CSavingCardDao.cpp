


#include "stdafx.h"
#include "CSavingCardDao.h"

CSavingCardDao::CSavingCardDao()
{
}

CSavingCardDao::~CSavingCardDao()
{
}



BOOL CSavingCardDao::save(CSavingCard *pCard)
{
	BOOL bRet = FALSE;
	//准备数据
	char cTime[50] = {'\0'};
	strftime(cTime, sizeof(cTime), "%Y-%m-%d %H:%M:%S", &(pCard->getCreateDate()));
	string strTime = cTime;

	char cBuff[500] = {'\0'};
	sprintf_s(cBuff, sizeof(cBuff), "%s##%s##%s##%s##%s##%d##%f##%f\n", pCard->getcardNum().c_str(),
		pCard->getPassword().c_str(), pCard->getAccount().c_str(), pCard->getBankName().c_str(),
		strTime.c_str(), pCard->getBonusPoints(), pCard->getMoney(), pCard->getInterestRate());
	string buff = cBuff;

	ofstream outFile;
	//打开文件
	outFile.open("Resource/SavingCard.txt", ios::app);
	if (!outFile)
	{
		bRet = FALSE;
	}
	//写入数据
	if (outFile.write(buff.c_str(), buff.size()))
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