
//			BMS		CStaffDao.h
//			Get the BankWorker's info from file
//			create by sway_xw 2015_04_29
//



#ifndef _BMS__CSTAFFDAO_H_
#define _BMS__CSTAFFDAO_H_
#include <windows.h>
#include <fstream>
#include "CStaff.h"
using namespace std;

class CStaffDao
{
public:
	CStaffDao();
	~CStaffDao();

public:
	BOOL Login(const char *pAccount, const char *pPassword);
	BOOL Login(CStaff *pStaff);
	CStaff *FindByAccount(const char *pAccount);
	//CStaff *FindByName(const char *pAccount);
private:
	CStaff *PraseStaff(char *pStaffInfo);

};

#endif