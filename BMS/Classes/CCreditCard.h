//
//	BMS		CCreditCard.h
//	定义信用卡对象的属性以及行为
//	create by	sway_xw 2015_05_11


#ifndef _BMS__CCREDITCARD_H_
#define _BMS__CCREDITCARD_H_


#include <string>
#include <AFX.h>
using namespace std;

class CCreditCard
{
public:
	CCreditCard();
	~CCreditCard();
private:
	char m_aCardNum[21];
	char m_aPassword[7];
	char m_aAccount[21];
	char m_aBankName[64];
	int  m_nType;
	struct tm m_tCreateDate;
	int m_nBonuspoints;
	double m_dbMoney;
	double m_dbCredit;
	double m_dbHandleChargeRate;
	int m_nBillDay;
	int m_nRepaymentDay;


public:
	void setCardNum(const char *pVal){ strcpy_s(m_aCardNum, pVal); }
	string getCardNum()const { return m_aCardNum; }

	void setPassword(const char *pVal){ strcpy_s(m_aPassword, pVal); }
	string getPassword()const { return m_aPassword; }

	void setAccount(const char *pVal){ strcpy_s(m_aAccount, pVal); }
	string getAccount()const { return m_aAccount; }

	void setBankName(const char *pVal){ strcpy_s(m_aBankName, pVal); }
	string getBankName()const { return m_aBankName; }

	void setType(const int val) { m_nType = val; }
	int getType()const { return m_nType; }

	void setCreateDate(const struct tm val) { m_tCreateDate = val; }
	struct tm getCreateDate()const { return m_tCreateDate; }

	void setBonuspoint(const int val){ m_nBonuspoints = val; }
	int getBonuspoint()const { return m_nBonuspoints; }

	void setMoney(const double val) { m_dbMoney = val;}
	double getMoney() const { return m_dbMoney; }

	void setCredit(const double val) { m_dbCredit = val; }
	double getCredit() const { return m_dbCredit; }

	void setHandleChargeRate(const double val) { m_dbHandleChargeRate = val; }
	double getHandleChargeRate() const { return m_dbHandleChargeRate; }

	void setBillDay(const int val){ m_nBillDay = val; }
	int getBillDay()const { return m_nBillDay; }

	void setRepaymentDay(const int val){ m_nRepaymentDay = val; }
	int getRepaymentDay()const { return m_nRepaymentDay; }
};

#endif