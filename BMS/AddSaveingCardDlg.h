#pragma once


// AddSaveingCardDlg dialog

class AddSaveingCardDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddSaveingCardDlg)

public:
	AddSaveingCardDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~AddSaveingCardDlg();

// Dialog Data
	enum { IDD =  IDD_ADD_SAVINGCARD_DIALOG};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
