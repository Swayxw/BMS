

#include "stdafx.h"
#include "CCreditCard.h"




CCreditCard::CCreditCard()
{
	m_dbCredit = 0;
	m_dbHandleChargeRate = 0;
	m_nBillDay = 30;
	m_nRepaymentDay = 60;
}

CCreditCard::~CCreditCard()
{

}

bool CCreditCard::Equal(CCreditCard *pCard)
{

}