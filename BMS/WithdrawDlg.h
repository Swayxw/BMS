#pragma once


// WithdrawDlg dialog

class WithdrawDlg : public CDialogEx
{
	DECLARE_DYNAMIC(WithdrawDlg)

public:
	WithdrawDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~WithdrawDlg();

// Dialog Data
	enum { IDD = IDD_CASHORWITHDRAW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnCashorwithdrawOk();
};
