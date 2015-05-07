// AddSaveingCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "AddSaveingCardDlg.h"
#include "afxdialogex.h"
#include "Classes\CSavingCard.h"
#include "Classes\CSavingCardDao.h"
#include "Classes\CToolKit.h"
#include "Classes\CCustomerDao.h"
#include "MainDialog.h"
#include "Classes\CStaff.h"
#include "Classes\CStaffDao.h"


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
	CString strAccount;
	this->GetDlgItemTextW(IDC_ADD_SAVINGCARD_EDIT_USERACCOUNT, strAccount);

	CString strSetPassword;
	this->GetDlgItemTextW(IDC_ADD_SAVINGCARD_EDIT_SETPASSWORD, strSetPassword);

	CString strConfirmPassword;
	this->GetDlgItemTextW(IDC_ADD_SAVINGCARD_EDIT_CONFIRMPASSWORD, strConfirmPassword);

	int  nMoney = this->GetDlgItemInt(IDC_ADD_SAVINGCARD_EDIT_SUM);
	
	CCustomerDao customer;
	CSavingCard pSavingCar;
	CSavingCardDao pSavingCardDao;

	//用户账户
	char aAccount[21] = { '\0' };
	CToolKit::ToChars(aAccount, strAccount, sizeof(aAccount));
	if (!customer.IsExsit(aAccount))
	{
		if (IDOK == MessageBox(L"用户不存在，请重新输入"))
		{
			return;
		}
	}
	pSavingCar.setAccount(aAccount);

	//用户密码
	if (strSetPassword.GetLength() != 6)
	{
		if (IDOK == MessageBox(L"密码长度不正确， 应该为6位"))
		{
			return;
		}
	}
	char aSetPassword[7] = { '\0' };
	CToolKit::ToChars(aSetPassword, strSetPassword, sizeof(aSetPassword));
	
	//确认密码
	char aConfirmPassword[7] = { '\0' };
	CToolKit::ToChars(aConfirmPassword, strConfirmPassword, sizeof(aConfirmPassword));
	if (strcmp(aSetPassword, aConfirmPassword) != 0)
	{
		if (IDOK == MessageBox(L"前后两次输入不相同，请重新输入"))
		{
			return;
		}
	}
	pSavingCar.setPassword(aSetPassword);

	//金额
	if (nMoney < 1)
	{
		if (IDOK == MessageBox(L"输入金额小于1元，请重新输入"))
		{
			return;
		}
	}
	pSavingCar.setMoney((double)nMoney);

	//所属银行
	HWND hWnd = ::FindWindow(NULL, _T("银行管理系统"));
	CMainDialog *pMainDlg = (CMainDialog *)FromHandle(hWnd);
	CString strStaffAccount = pMainDlg->getAccount();
	char aStaffAcount[21] = { '\0' };
	CToolKit::ToChars(aStaffAcount, strStaffAccount, sizeof(aStaffAcount));
	CStaffDao staffDao;
	CStaff *pStaff = NULL;
	pStaff = staffDao.FindByAccount(aStaffAcount);
	pSavingCar.setBankName(pStaff->getBankName().c_str());
}
