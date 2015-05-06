//		BMS		CSavingCard.h
//		定义储蓄卡的属性和行为
//		create by sway_xw 2015_05_06
//



#ifndef _BMS__CSAVINGCARD_H_
#define _BMS__CASVINGCARD_H_

#include <string>
#include <AFX.h>
using namespace std;


class CSavingCard
{
public:
	CSavingCard();
	~CSavingCard();

private:
	char m_aCardNum[21];
	char m_aPassword[7];
	char m_aAccount[21];
	char m_BankName[64];
	int m_nType;
	struct tm m_tCreateDate;
	int m_nBonusPoints;
	double m_dbMoney;
	double m_dbInterestRate;
public:
	bool withdraw(double dbVal);
	void deposit(double dbVal);
	bool cash(double dbVal);


public:
	void setCardNum(const char *pVal){ strcpy_s(m_aCardNum, pVal); }
	string getcardNum()const { return m_aCardNum; }

	void setPassword(const char *pVal){ strcpy_s(m_aPassword, pVal); }
	string getPassword()const { return m_aPassword; }

	void setAccount(const char *pVal){ strcpy_s(m_aAccount, pVal); }
	string getAccount()const { return m_aAccount; }

	void setBankName(const char *pVal){ strcpy_s(m_BankName, pVal); }
	string getBankName()const { return m_BankName; }

	void setType(const int val){ m_nType = val; }
	int getType()const { return m_nType; }

	void setCreateDate(const struct tm val){ m_tCreateDate = val; }
	struct tm getCreateDate()const { return m_tCreateDate; }

	void setBonusPoints(const int val){ m_nBonusPoints = val; }
	int getBonusPoints()const { return m_nBonusPoints; }

	void setMoney(const double dbVal){ m_dbMoney = dbVal; }
	double getMoney()const { return m_dbMoney; }

	void setInterestRate(const double dbVal){ m_dbInterestRate = dbVal; }
	double getInterestRate()const { return m_dbInterestRate; }
};


#endif