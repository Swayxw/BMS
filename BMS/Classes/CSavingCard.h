//		BMS		CSavingCard.h
//		定义储蓄卡的属性和行为
//		create by sway_xw 2015_05_06
//



#ifndef _BMS__CSAVINGCARD_H_
#define _BMS__CSAVINGCARD_H_

#include <string>
#include <AFX.h>
#include "CCard.h"
using namespace std;


class CSavingCard : public CCard
{
public:
	CSavingCard();
	~CSavingCard();

private:
	double m_dbInterestRate;
public:


public:
	void setInterestRate(const double dbVal){ m_dbInterestRate = dbVal; }
	double getInterestRate()const { return m_dbInterestRate; }
};


#endif