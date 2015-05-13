#pragma once


// AddCreditCardDlg dialog

class AddCreditCardDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCreditCardDlg)

public:
	AddCreditCardDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~AddCreditCardDlg();

// Dialog Data
	enum { IDD = IDD_ADD_CREDITCARD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
