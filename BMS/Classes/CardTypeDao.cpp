

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


bool CardTypeDao::getTypeByCardNum(const char *pCardNum, int &nType)
{
	//���ļ�
	ifstream inFile;
	inFile.open("Resource/CardType.txt", ios::in);
	if (!inFile)
	{
		return false;
	}

	//��ȡ�ļ�
	char aCardTypeInfo[25] = {'\0'};
	CardTypeStruct *pCTS = NULL;
	while (inFile.getline(aCardTypeInfo, sizeof(aCardTypeInfo)))
	{
		pCTS = praseCardType(aCardTypeInfo);
		if (pCTS != NULL)
		{
			if (strcmp(pCardNum, pCTS->m_aCardNum) == 0)
			{
				nType = pCTS->m_nType;
				delete pCTS;
				pCTS = NULL;
				return true;
			}
			delete pCTS;
			pCTS = NULL;
		}
	}
	inFile.close();
	return false;
}


CardTypeStruct *CardTypeDao::praseCardType(char *pCardTypeInfo)
{
	char *pDllimes = "##";
	char aFlag[2][25] = {'\0'};
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

	CardTypeStruct *pCardType = new CardTypeStruct();
	strcpy_s(pCardType->m_aCardNum, aFlag[0]);
	string type = aFlag[1];
	int t = atoi(type.c_str());
	pCardType->m_nType = t;

	return pCardType;
}