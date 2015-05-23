//
//	BMS		CCreditCard.h
//	定义信用卡对象的属性以及行为
//	create by	sway_xw 2015_05_11


#ifndef _BMS__CCREDITCARD_H_
#define _BMS__CCREDITCARD_H_


#include <string>
#include <AFX.h>
#include "CCard.h"
using namespace std;

class CCreditCard : public CCard
{
public:
	CCreditCard();
	~CCreditCard();

	bool Equal(CCreditCard *pCard);
private:
	double m_dbCredit;
	double m_dbHandleChargeRate;
	int m_nBillDay;
	int m_nRepaymentDay;


public:
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