

#include "stdafx.h"
#include "CCreditCard.h"




CCreditCard::CCreditCard()
{
	strcpy_s(m_aCardNum, "");
	strcpy_s(m_aPassword, "");
	strcpy_s(m_aAccount, "");
	strcpy_s(m_aBankName, "");
	m_nType = 1;

	time_t t = time(NULL);
	localtime_s(&m_tCreateDate, &t);

	m_nBonuspoints = 0;
	m_dbMoney = 0;
	m_dbCredit = 0;
	m_dbHandleChargeRate = 0;
	m_nBillDay = 30;
	m_nRepaymentDay = 60;
}

CCreditCard::~CCreditCard()
{

}