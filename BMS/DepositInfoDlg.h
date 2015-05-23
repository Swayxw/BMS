#pragma once


// DepositInfoDlg dialog

class DepositInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DepositInfoDlg)

public:
	DepositInfoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~DepositInfoDlg();

// Dialog Data
	enum { IDD = IDD_DEPOSITINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnDepositinfoOk();
};
