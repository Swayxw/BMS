#pragma once


// CAddCustomerDlg dialog

class CAddCustomerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddCustomerDlg)

public:
	CAddCustomerDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAddCustomerDlg();

// Dialog Data
	enum { IDD = IDD_ADD_CUSTOMER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
