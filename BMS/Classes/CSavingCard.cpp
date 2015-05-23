
#include "stdafx.h"
#include "CSavingCard.h"




CSavingCard::CSavingCard()
{
	m_dbInterestRate = 0.0f;
}

CSavingCard::~CSavingCard()
{
}

//bool CSavingCard::withdraw(double dbVal)
//{
//	if ((m_dbMoney - dbVal) >= 0)
//	{
//		m_dbMoney -= dbVal;
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//
//bool CSavingCard::cash(double dbVal)
//{
//	if ((m_dbMoney - dbVal) >= 0)
//	{
//		m_dbMoney -= dbVal;
//		m_nBonusPoint += floor(dbVal);
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}