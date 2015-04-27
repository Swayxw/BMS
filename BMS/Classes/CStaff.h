//			BMS	 CStaff.h
//			The bank worker
//			Create by sway_xw 2015_04_26
//


#ifndef _BMS__CSTAFF_H_
#define _BMS__CSTAFF_H_
#include<iostream>
using namespace std;

class CStaff
{
public:
	CStaff();
	CStaff(const char *account, const char *password, const char *name, const char *bankname, const int perimission);
	~CStaff();

private:
	char m_aAccount[21];
	char m_aPassword[7];
	char m_aName[15];
	char m_aBankName[41];
	int  m_nPermission;

public:
	string getAccount()const { return m_aAccount; }
	void setAcount(const string& val){ strcpy_s(m_aAccount, val.c_str()); }


	string getPassword()const{ return m_aPassword; };
	void setPassword(const string& val){ strcpy_s(m_aPassword, val.c_str()); }


	string getName()const{ return m_aName; }
	void setName(const string& val){ strcpy_s(m_aName, val.c_str()); }

	string getBankName()const{ return m_aBankName; }
	void setBankName(const string& val){ strcpy_s(m_aBankName, val.c_str()); }


	int getPermission()const{ return m_nPermission; }
	void setPermission(const int& val){ m_nPermission = val; }

};




#endif