


#include "stdafx.h"
#include "CSavingCardDao.h"
#include "CToolKit.h"
#include <vector>

#define SAVINGCARD_INFO_LENGTH  500
CSavingCardDao::CSavingCardDao()
{
}

CSavingCardDao::~CSavingCardDao()
{
}



BOOL CSavingCardDao::save(CSavingCard *pCard)
{
	BOOL bRet = FALSE;
	//׼������
	char cTime[50] = {'\0'};
	strftime(cTime, sizeof(cTime), "%Y-%m-%d %H:%M:%S", &(pCard->getCreateDate()));
	string strTime = cTime;

	char cBuff[500] = {'\0'};
	sprintf_s(cBuff, sizeof(cBuff), "%s##%s##%s##%s##%s##%d##%f##%f\n", pCard->getCardNum().c_str(),
		pCard->getPassword().c_str(), pCard->getAccount().c_str(), pCard->getBankName().c_str(),
		strTime.c_str(), pCard->getBonusPoint(), pCard->getMoney(), pCard->getInterestRate());
	string buff = cBuff;

	ofstream outFile;
	//���ļ�
	outFile.open("Resource/SavingCard.txt", ios::app);
	if (!outFile)
	{
		bRet = FALSE;
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

CSavingCard *CSavingCardDao::getCardByCardNum(const char *pCardNum)
{
	//���ļ�
	ifstream inFile;
	inFile.open("Resource/SavingCard.txt", ios::in);
	if (!inFile)
	{
		return NULL;
	}

	//��ȡ�ļ�
	char aSavingCardInfo[SAVINGCARD_INFO_LENGTH] = {'\0'};
	CSavingCard *pRet = NULL;

	while (inFile.getline(aSavingCardInfo, sizeof(aSavingCardInfo)))
	{
		pRet = praseSavingCard(aSavingCardInfo);
		if (pRet != nullptr)
		{
			if (strcmp(pRet->getCardNum().c_str(), pCardNum) == 0)
			{
				return pRet;
			}
			delete pRet;
			pRet = NULL;
		}
	}

	inFile.close();
	return pRet;
}



bool CSavingCardDao::isExsit(const char *pCardNum)
{
	bool bRet = false;
	//���ļ�
	ifstream inFile;
	inFile.open("Resource/SavingCard.txt", ios::in);
	if (!inFile)
	{
		return false;
	}

	char aSavingCardInfo[SAVINGCARD_INFO_LENGTH] = {'\0'};
	CSavingCard *p = NULL;
	while (inFile.getline(aSavingCardInfo, sizeof(aSavingCardInfo)))
	{
		p = praseSavingCard(aSavingCardInfo);
		if (p != NULL)
		{
			if (strcmp(p->getCardNum().c_str(), pCardNum) == 0)
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



bool CSavingCardDao::Update(CSavingCard *pCard)
{
	//�Զ��ķ�ʽ ���ļ�
	ifstream inFile;
	inFile.open("Resource/SavingCard.txt", ios::in);
	if (!inFile)
	{
		return false;
	}
	char aSavingCardInfo[SAVINGCARD_INFO_LENGTH] = {'\0'};
	vector<CSavingCard *> savingCards;
	while (inFile.getline(aSavingCardInfo, sizeof(aSavingCardInfo)))
	{
		CSavingCard *tempCard = praseSavingCard(aSavingCardInfo);
		if (tempCard != NULL)
		{
			if (strcmp(tempCard->getCardNum().c_str(), pCard->getCardNum().c_str()) != 0)
			{
				savingCards.push_back(tempCard);
			}
			else
			{
				savingCards.push_back(pCard);
			}
		}
	}

	inFile.close();

	//��д�ķ�ʽ���ļ�
	ofstream outFile;
	outFile.open("Resource/SavingCard.txt", ios::out);
	outFile.close();

	for (int i = 0; i < savingCards.size(); i++)
	{
		save(savingCards[i]);
	}

	for (int i = 0; i < savingCards.size(); i++)
	{
		if (savingCards[i] != NULL)
		{
			delete savingCards[i];
		}
	}

	return true;
}


CSavingCard *CSavingCardDao::praseSavingCard(const char *pSavingCardInfo)
{
	char *pDllimes = "##";
	char aFlag[8][128] = { '\0' };
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
	CSavingCard *pRet = new CSavingCard();
	pRet->setCardNum(aFlag[0]);
	pRet->setPassword(aFlag[1]);
	pRet->setAccount(aFlag[2]);
	pRet->setBankName(aFlag[3]);

	struct tm tempTime;
	CToolKit::charToTime(aFlag[4], tempTime);
	pRet->setCreateDate(tempTime);

	pRet->setBonusPoint(atoi(aFlag[5]));
	pRet->setMoney(atof(aFlag[6]));
	pRet->setInterestRate(atof(aFlag[7]));
	
	return pRet;
}