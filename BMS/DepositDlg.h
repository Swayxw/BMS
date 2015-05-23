#pragma once


#include "Classes\CCreditCard.h"
#include "Classes\CSavingCard.h"
#include "Classes\CCreditCardDao.h"
#include "Classes\CSavingCardDao.h"

// DepositDlg dialog

class DepositDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DepositDlg)

public:
	DepositDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~DepositDlg();

// Dialog Data
	enum { IDD = IDD_DEPOSIT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void Deposit(CSavingCard *pSavingCard, double dbMoney);
	void Deposit(CCreditCard *pCreditCard, double dbMoney);
public:
	afx_msg void OnBnClickedBtnDepositOk();
};
