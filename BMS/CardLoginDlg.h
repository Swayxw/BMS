#pragma once


// CardLoginDlg dialog

class CardLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CardLoginDlg)

public:
	CardLoginDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CardLoginDlg();

// Dialog Data
	enum { IDD = IDD_CARDLOGIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnCardloginOk();
};
