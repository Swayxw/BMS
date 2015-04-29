

#include "stdafx.h"
#include "CStaffDao.h"


#define STAFF_INFO_LENGTH  100

CStaffDao::CStaffDao()
{
}

CStaffDao::~CStaffDao()
{
}



BOOL CStaffDao::Login(const char *pAccount, const char *pPassword)
{
	ifstream infile;
	//1�����ļ�
	infile.open("Resource/Staff.txt", ios::in);
	if (!infile)
	{
		return FALSE;
	}
	//2�����ļ�
	char aStaffInfo[STAFF_INFO_LENGTH] = {0};
	CStaff *pS = NULL;
	BOOL bFlag = FALSE;
	while (infile.getline(aStaffInfo, sizeof(aStaffInfo)))
	{
		//����
		pS = PraseStaff(aStaffInfo);
		//�ж��Ƿ��ܹ���¼
		if (pS != NULL)
		{
		
			if (strcmp(pAccount, pS->getAccount().c_str()) == 0)
			{
				if (strcmp(pPassword, pS->getPassword().c_str()) == 0)
				{
					bFlag = TRUE;
					delete pS;
					pS = NULL;
					break;
				}
			}
			delete pS;
			pS = NULL;
		}
	}

	//3���ر��ļ�
	infile.close();
	return bFlag;
}


CStaff *CStaffDao::PraseStaff(char *pStaffInfo)
{
	char *pDellims = "##";
	char aFlag[5][STAFF_INFO_LENGTH] = { '\0' };
	char *pBuf = pStaffInfo;
	char *pStr = NULL;
	int nIndex = 0;
	while ((pStr = strtok(pBuf, pDellims)) != NULL)
	{
		strcpy(aFlag[nIndex], pStr);
		pBuf = NULL;
		nIndex++;
	}

	CStaff *pStaff = new CStaff();
	pStaff->setAcount(aFlag[0]);
	pStaff->setPassword(aFlag[1]);
	pStaff->setName(aFlag[2]);
	pStaff->setBankName(aFlag[3]);
	pStaff->setPermission(atoi(aFlag[4]));
	return pStaff;
}