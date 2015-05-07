#pragma once


// CMainDialog dialog
class CMainDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDialog)

public:
	CMainDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMainDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	CString m_strName;
	CString m_strAccount;
public:
	CString getName()const { return m_strName; }
	void setName(const CString &val){ m_strName = val; }

	CString getAccount()const { return m_strAccount; }
	void setAccount(const CString &val){ m_strAccount = val; }
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnAddcustomer();
	afx_msg void OnBnClickedBtnAddsavingcard();
};
