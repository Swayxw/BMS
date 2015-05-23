
//	BMS		CCard.h
//	定义银行卡基类的属性和行为
//	create by sway_xw 2015_05_19
//


#ifndef _BMS__CCARD_H_
#define _BMS__CCARD_H_

#include <string>
#include <AFX.h>
using namespace std;

class CCard
{
public:
	CCard();
	~CCard();

protected:
	char m_aCardNum[21];
	char m_aPassword[7];
	char m_aAccount[21];
	char m_aBankName[64];
	int m_nType;
	struct tm m_tCreateDate;
	int m_nBonusPoint;
	double m_dbMoney;

public:
	virtual void Deposit(double val);
	virtual bool Withdraw(double val);
	virtual bool Cash(double val);

public:
	void setCardNum(const char *pVal){ strcpy_s(m_aCardNum, pVal); }
	string getCardNum() const { return m_aCardNum; }

	void setPassword(const char *pVal){ strcpy_s(m_aPassword, pVal); }
	string getPassword()const{ return m_aPassword; }

	void setAccount(const char *pVal){ strcpy_s(m_aAccount, pVal); }
	string getAccount()const { return m_aAccount; }

	void setBankName(const char *pVal){ strcpy_s(m_aBankName, pVal); }
	string getBankName()const { return m_aBankName; }

	void setType(const int val){ m_nType = val; }
	int getType() const { return m_nType; }

	void setCreateDate(const struct tm val) { m_tCreateDate = val; }
	struct tm getCreateDate() const { return m_tCreateDate; }

	void setBonusPoint(const int val) { m_nBonusPoint = val; }
	int getBonusPoint() const { return m_nBonusPoint; }

	void setMoney(const double val) { m_dbMoney = val; }
	double getMoney() const { return m_dbMoney; }
};

#endif