

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
	//׼������
	char cBuff[50] = {'\0'};
	sprintf_s(cBuff, sizeof(cBuff), "%s##%d\n", pCardNum, nType);
	string buff = cBuff;
	//���ļ�
	ofstream outFile;
	outFile.open("Resource/CardType.txt", ios::app);
	if (!outFile)
	{
		return FALSE;
	}
	//д������
	if (outFile.write(buff.c_str(), buff.size()))
	{
		bRet = TRUE;
	}
	else
	{
		bRet = FALSE;
	}
	//�������
	outFile.flush();
	//�ر��ļ�
	outFile.close();
	return bRet;
}