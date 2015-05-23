// DepositInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "DepositInfoDlg.h"
#include "afxdialogex.h"


// DepositInfoDlg dialog

IMPLEMENT_DYNAMIC(DepositInfoDlg, CDialogEx)

DepositInfoDlg::DepositInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DepositInfoDlg::IDD, pParent)
{

}

DepositInfoDlg::~DepositInfoDlg()
{
}

void DepositInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DepositInfoDlg, CDialogEx)
	ON_BN_CLICKED(ID_BTN_DEPOSITINFO_OK, &DepositInfoDlg::OnBnClickedBtnDepositinfoOk)
END_MESSAGE_MAP()


// DepositInfoDlg message handlers


void DepositInfoDlg::OnBnClickedBtnDepositinfoOk()
{
	// TODO: Add your control notification handler code here
}
