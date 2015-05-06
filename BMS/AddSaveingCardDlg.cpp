// AddSaveingCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "AddSaveingCardDlg.h"
#include "afxdialogex.h"
#include "Classes\CSavingCard.h"
#include "Classes\CSavingCardDao.h"
#include "Classes\CToolKit.h"


// AddSaveingCardDlg dialog

IMPLEMENT_DYNAMIC(AddSaveingCardDlg, CDialogEx)

AddSaveingCardDlg::AddSaveingCardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddSaveingCardDlg::IDD, pParent)
{

}

AddSaveingCardDlg::~AddSaveingCardDlg()
{
}

void AddSaveingCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddSaveingCardDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddSaveingCardDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// AddSaveingCardDlg message handlers


void AddSaveingCardDlg::OnBnClickedOk()
{
	
}
