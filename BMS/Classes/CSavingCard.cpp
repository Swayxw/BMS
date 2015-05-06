
#include "stdafx.h"
#include "CSavingCard.h"




CSavingCard::CSavingCard()
{

	strcpy_s(m_aCardNum, "");
	strcpy_s(m_aPassword, "");
	strcpy_s(m_aAccount, "");
	strcpy_s(m_BankName, "");
	m_nType = 0;
	time_t t = time(NULL);
	localtime_s(&m_tCreateDate, &t);
	m_nBonusPoints = 0;
	m_dbMoney = 0.0f;
	m_dbInterestRate = 0.0f;
}

CSavingCard::~CSavingCard()
{
}


void CSavingCard::deposit(double dbVal)
{
	m_dbMoney += dbVal;
}


bool CSavingCard::withdraw(double dbVal)
{
	if ((m_dbMoney - dbVal) >= 0)
	{
		m_dbMoney -= dbVal;
		return true;
	}
	else
	{
		return false;
	}
}


bool CSavingCard::cash(double dbVal)
{
	if ((m_dbMoney - dbVal) >= 0)
	{
		m_dbMoney -= dbVal;
		m_nBonusPoints += floor(dbVal);
		return true;
	}
	else
	{
		return false;
	}
}