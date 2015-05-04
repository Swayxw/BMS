//
//			BMS			CCustomer.h
//			客户信息
//			create by sway_xw 2015_05_02
//




#ifndef _BMS__CCUSTOMER_H_
#define _BMS__CCUSTOMER_H_
#include <string>
using namespace std;

class CCustomer
{
public:
	CCustomer();
	~CCustomer();

private:
	char m_aAccount[21];
	char m_aName[15];
	int	 m_nGender;
	char m_aIdNum[19];
	char m_aPhoneNum[12];
	char m_aEmail[32];
	char m_aAddress[128];
	int	 m_nCredit;
	struct tm m_CreateDate;


public:
	void setAccount(const char *pVal){ strcpy_s(m_aAccount, pVal); }
	string getAccount()const { return m_aAccount; }


	void setName(const char *pVal){ strcpy_s(m_aName, pVal); }
	string getName()const { return m_aName; }

	void setGender(const int val){ m_nGender = val; }
	int getGender()const { return m_nGender; }

	void setIdNum(const char *pVal){ strcpy_s(m_aIdNum, pVal); }
	string getIdNum()const { return m_aIdNum; }

	void setPhoneNum(const char *pVal){ strcpy_s(m_aPhoneNum, pVal); }
	string getPhoneNum()const { return m_aPhoneNum; }

	void setEmail(const char *pVal){ strcpy_s(m_aEmail, pVal); }
	string getEmail()const { return m_aEmail; }

	void setAddress(const char *pVal){ strcpy_s(m_aAddress, pVal); }
	string getAddress()const { return m_aAddress; }

	void setCredit(const int val){ m_nCredit = val; }
	int getCredit()const  { return m_nCredit; }


	void setCreateDate(const struct tm val){ m_CreateDate = val; }
	struct tm getCreatDate()const { return m_CreateDate; }
};




#endif // !_BMS__CCUSTOMER_H_
