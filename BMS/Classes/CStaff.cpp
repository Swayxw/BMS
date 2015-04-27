
#include "stdafx.h"
#include "CStaff.h"

CStaff::CStaff()
{
	strcpy_s(m_aAccount, "");
	strcpy_s(m_aPassword, "");
	strcpy_s(m_aName, "");
	strcpy_s(m_aBankName, "");
	m_nPermission = 0;
}


CStaff::CStaff(const char *account, const char *password, const char *name, const char *bankname, const int perimission)
{
	strcpy_s(m_aAccount, account);
	strcpy_s(m_aPassword, password);
	strcpy_s(m_aName, name);
	strcpy_s(m_aBankName, bankname);
	m_nPermission = perimission;
}


CStaff::~CStaff()
{

}




