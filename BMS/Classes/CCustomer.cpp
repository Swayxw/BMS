

#include "stdafx.h"
#include "CCustomer.h"



CCustomer::CCustomer()
{
	strcpy_s(m_aAccount, sizeof(m_aAccount), "");
	strcpy_s(m_aName, sizeof(m_aName), "");
	m_nGender = 1;
	strcpy_s(m_aIdNum, sizeof(m_aIdNum), "");
	strcpy_s(m_aPhoneNum, sizeof(m_aPhoneNum), "");
	strcpy_s(m_aEmail, sizeof(m_aEmail), "");
	strcpy_s(m_aAddress, sizeof(m_aAddress), "");
	m_nCredit = 1;
}

CCustomer::~CCustomer()
{
	//if (&m_CreateDate != NULL)
	//{
		//delete &m_CreateDate;
	//}
}