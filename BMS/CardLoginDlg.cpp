// CardLoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "CardLoginDlg.h"
#include "afxdialogex.h"


// CardLoginDlg dialog

IMPLEMENT_DYNAMIC(CardLoginDlg, CDialogEx)

CardLoginDlg::CardLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CardLoginDlg::IDD, pParent)
{

}

CardLoginDlg::~CardLoginDlg()
{
}

void CardLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CardLoginDlg, CDialogEx)
	ON_BN_CLICKED(ID_BTN_CARDLOGIN_OK, &CardLoginDlg::OnBnClickedBtnCardloginOk)
END_MESSAGE_MAP()


// CardLoginDlg message handlers


void CardLoginDlg::OnBnClickedBtnCardloginOk()
{
	// TODO: Add your control notification handler code here
}
