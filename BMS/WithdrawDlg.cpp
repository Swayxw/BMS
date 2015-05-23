// WithdrawDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "WithdrawDlg.h"
#include "afxdialogex.h"


// WithdrawDlg dialog

IMPLEMENT_DYNAMIC(WithdrawDlg, CDialogEx)

WithdrawDlg::WithdrawDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(WithdrawDlg::IDD, pParent)
{

}

WithdrawDlg::~WithdrawDlg()
{
}

void WithdrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WithdrawDlg, CDialogEx)
	ON_BN_CLICKED(ID_BTN_CASHORWITHDRAW_OK, &WithdrawDlg::OnBnClickedBtnCashorwithdrawOk)
END_MESSAGE_MAP()


// WithdrawDlg message handlers


void WithdrawDlg::OnBnClickedBtnCashorwithdrawOk()
{
	// TODO: Add your control notification handler code here
}
