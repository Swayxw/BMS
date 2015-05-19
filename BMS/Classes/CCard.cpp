

#include "stdafx.h"
#include "CCard.h"


CCard::CCard()
{

	strcpy_s(m_aCardNum, "");
	strcpy_s(m_aPassword, "");
	strcpy_s(m_aAccount, "");
	strcpy_s(m_aBankName, "");
	m_nType = 0;

	time_t t = time(NULL);
	localtime_s(&m_tCreateDate, &t);

	m_nBonusPoint = 0;
	m_dbMoney = 0;
}

CCard::~CCard()
{
}