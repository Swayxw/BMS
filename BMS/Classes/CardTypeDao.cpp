

#include "stdafx.h"
#include "CardTypeDao.h"


CardTypeDao::CardTypeDao()
{
}

CardTypeDao::~CardTypeDao()
{
}


BOOL CardTypeDao::saveCardType(const char *pCardNum, int nType)
{
	BOOL bRet = FALSE;
	//准备数据
	char cBuff[50] = {'\0'};
	sprintf_s(cBuff, sizeof(cBuff), "%s##%d\n", pCardNum, nType);
	string buff = cBuff;
	//打开文件
	ofstream outFile;
	outFile.open("Resource/CardType.txt", ios::app);
	if (!outFile)
	{
		return FALSE;
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