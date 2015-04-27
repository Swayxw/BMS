// MainDialog.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "MainDialog.h"
#include "afxdialogex.h"
#include <string>
#include <iostream>
using namespace std;


// CMainDialog dialog

IMPLEMENT_DYNAMIC(CMainDialog, CDialogEx)

CMainDialog::CMainDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDialog::IDD, pParent)
{

}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialogEx)
END_MESSAGE_MAP()


// CMainDialog message handlers


BOOL CMainDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ModifyStyleEx(0, WS_EX_APPWINDOW);
#ifdef _UNICODE
	wstring info = m_strInfo;
	wstring s;
	s.append(_T("管理员【"));
	s.append(info);
	s.append(_T("】，已登录"));
#else
	string info = m_strInfo;
	sstring s;
	s.append("管理员【");
	s.append(info);
	s.append("】，已登录");
#endif
	this->SetDlgItemTextW(IDC_STATIC_TEXT, CString(s.c_str()));





	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
