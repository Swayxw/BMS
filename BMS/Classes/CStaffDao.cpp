

#include "stdafx.h"
#include "CStaffDao.h"


#define STAFF_INFO_LENGTH  100

CStaffDao::CStaffDao()
{
}

CStaffDao::~CStaffDao()
{
}

BOOL CStaffDao::Login(CStaff *pStaff)
{
	ifstream infile;
	//打开文件
	infile.open("Resource/Staff.txt", ios::in);
	if (!infile)
	{
		return FALSE;
	}


	//读文件
	char aStaffInfo[STAFF_INFO_LENGTH] = {0};
	CStaff *ps = NULL;
	BOOL bRet = FALSE;
	while (infile.getline(aStaffInfo, sizeof(aStaffInfo)))
	{
		//解析
		ps = PraseStaff(aStaffInfo);
		if (ps != NULL)
		{
			if (pStaff->getAccount() == ps->getAccount() && pStaff->getPassword() == ps->getPassword())
			{
				bRet = TRUE;
				delete ps;
				ps = NULL;
				break;
			}
			delete ps;
			ps = NULL;
		}
	}

	//关闭文件
	infile.close();
	return bRet;
}


BOOL CStaffDao::Login(const char *pAccount, const char *pPassword)
{
	ifstream infile;
	//1、打开文件
	infile.open("Resource/Staff.txt", ios::in);
	if (!infile)
	{
		return FALSE;
	}
	//2、读文件
	char aStaffInfo[STAFF_INFO_LENGTH] = {0};
	CStaff *pS = NULL;
	BOOL bFlag = FALSE;
	while (infile.getline(aStaffInfo, sizeof(aStaffInfo)))
	{
		//解析
		pS = PraseStaff(aStaffInfo);
		//判断是否能够登录
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

	//3、关闭文件
	infile.close();
	return bFlag;
}


CStaff *CStaffDao::PraseStaff(char *pStaffInfo)
{
	char *pDellims = "##";
	char aFlag[5][STAFF_INFO_LENGTH] = { '\0' };
	char *pBuf = pStaffInfo;
	char *pStr = NULL;
	char *p;
	int nIndex = 0;
	while ((pStr = strtok_s(pBuf, pDellims, &p)) != NULL)
	{
		strcpy_s(aFlag[nIndex], pStr);
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


CStaff *CStaffDao::FindByAccount(const char *pAccount)
{
	CStaff *pRet = NULL;
	ifstream infile;
	//打开文件
	infile.open("Resource/Staff.txt", ios::in);
	if (!infile)
	{
		return FALSE;
	}
	//读取文件
	char aStaffInfo[STAFF_INFO_LENGTH] = {0};
	CStaff *ps = NULL;
	while (infile.getline(aStaffInfo, sizeof(aStaffInfo)))
	{
		ps = PraseStaff(aStaffInfo);
		if (ps != NULL)
		{
			if (strcmp(pAccount, ps->getAccount().c_str()) == 0)
			{
				pRet = ps;
				break;
			}
			delete ps;
			ps = NULL;
		}
	}
	//关闭文件
	infile.close();
	return pRet;
}
