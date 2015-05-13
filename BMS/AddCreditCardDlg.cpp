// AddCreditCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "AddCreditCardDlg.h"
#include "afxdialogex.h"
#include "Classes\CCustomerDao.h"
#include "Classes\CToolKit.h"
#include "Classes\CCreditCard.h"
#include "Classes\CCreditCardDao.h"
#include "Classes\CardTypeDao.h"
#include "Classes\CStaff.h"
#include "Classes\CStaffDao.h"
#include "MainDialog.h"


// AddCreditCardDlg dialog

IMPLEMENT_DYNAMIC(AddCreditCardDlg, CDialogEx)

AddCreditCardDlg::AddCreditCardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddCreditCardDlg::IDD, pParent)
{

}

AddCreditCardDlg::~AddCreditCardDlg()
{
}

void AddCreditCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddCreditCardDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddCreditCardDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// AddCreditCardDlg message handlers


void AddCreditCardDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	CString strAccount;
	this->GetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_ACCOUNT, strAccount);

	CString strPassword;
	this->GetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_PASSWORD, strPassword);

	CString strConfirmPassword;
	this->GetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_CONFIRMPASSWORD, strConfirmPassword);

	int nMoney = 0;
	nMoney = this->GetDlgItemInt(IDC_ADD_CREDITCARD_EDIT_MONEY);

	int nCredit = 0;
	nCredit = this->GetDlgItemInt(IDC_ADD_CREDITCARD_EDIT_CREDITVAL);

	int nBillboardDay = 0;
	nBillboardDay = this->GetDlgItemInt(IDC_ADD_CREDITCARD_EDIT_BILLBOARDDAY);

	int nRepaymentDay = 0;
	nRepaymentDay = this->GetDlgItemInt(IDC_ADD_CREDITCARD_EDIT_REPAYDAY);

	CCreditCard creditCard;
	CCreditCardDao creditCardDao;
	CStaff staff;
	CStaffDao staffDao;

	//用户账户
	if (strAccount.GetLength() <= 0)
	{
		if (IDOK == MessageBox(L"用户账户不能为空"))
		{
			return;
		}
	}
	char aAccount[21] = {'\0'};
	CToolKit::ToChars(aAccount, strAccount, sizeof(aAccount));
	CCustomerDao customerDao;
	if (!customerDao.IsExsit(aAccount))
	{
		if (IDOK == MessageBox(L"用户账户错误"))
		{
			return;
		}
	}
	creditCard.setAccount(aAccount);

	//密码
	if (strPassword.GetLength() != 6)
	{
		if (IDOK == MessageBox(L"密码长度错误， 请输入六位密码"))
		{
			return;
		}
	}
	char aPassword[7] = { '\0' };
	char aConfirmPassword[7] = { '\0' };
	CToolKit::ToChars(aPassword, strPassword, sizeof(aPassword));
	CToolKit::ToChars(aConfirmPassword, strConfirmPassword, sizeof(aConfirmPassword));
	if (strcmp(aPassword, aConfirmPassword) != 0)
	{
		if (IDOK == MessageBox(L"两次输入密码不一致， 请重新输入"))
		{
			return;
		}
	}
	creditCard.setPassword(aPassword);

	//金额
	if (nMoney < 1)
	{
		if (IDOK == MessageBox(L"请至少存入1元"))
		{
			return;
		}
	}
	creditCard.setMoney((double)nMoney);

	//信用额度
	creditCard.setCredit((double)nCredit);

	//账单日
	if (nBillboardDay <= 0)
	{
		if (IDOK == MessageBox(L"账单日必须要大于一天以上"))
		{
			return;
		}
	}
	creditCard.setBillDay(nBillboardDay);
	//还款日
	if (nRepaymentDay <= 0)
	{
		if (IDOK == MessageBox(L"还款日必须要大于一天以上"))
		{
			return;
		}
	}
	creditCard.setRepaymentDay(nRepaymentDay);
	//类型
	creditCard.setType(1);

	//手续费
	creditCard.setHandleChargeRate(0.03);

	//所属银行
	//char aBankName[64] = {'\0'};
	//CMainDialog mainDlg;
	//CString strUserName = mainDlg.getAccount();
	HWND hWnd = ::FindWindow(NULL, _T("银行管理系统"));
	CMainDialog *pMainDlg = (CMainDialog *)FromHandle(hWnd);
	CString strStaffAccount = pMainDlg->getAccount();
	char aUserAccount[21] = { '\0' };
	CToolKit::ToChars(aUserAccount, strStaffAccount, sizeof(aUserAccount));
	creditCard.setBankName(staffDao.FindByAccount(aUserAccount)->getBankName().c_str());

	//创建日期
	time_t t = time(NULL);
	struct tm tempTm;
	localtime_s(&tempTm, &t);
	creditCard.setCreateDate(tempTm);

	//卡号
	char aCardNum[21] = {'\C'};
	CToolKit::GenerateCardNum(aCardNum, sizeof(aCardNum));
	creditCard.setCardNum(aCardNum);

	if (creditCardDao.save(&creditCard))
	{
		MessageBox(L"办理信用卡成功\n" + CToolKit::ToString(const_cast<char *>(creditCard.getCardNum().c_str()), creditCard.getCardNum().size()) + "\n请牢记卡号");
	}
	else
	{
		if (IDOK == MessageBox(L"创建信用卡失败，请确认填写信息"))
		{
			return;
		}
	}
	CardTypeDao cardTypeDao;
	cardTypeDao.saveCardType(creditCard.getCardNum().c_str(), creditCard.getType());

	this->SetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_ACCOUNT, L"");
	this->SetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_PASSWORD, L"");
	this->SetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_CONFIRMPASSWORD, L"");
	this->SetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_MONEY, L"");
	this->SetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_CREDITVAL, L"");
	this->SetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_BILLBOARDDAY, L"");
	this->SetDlgItemTextW(IDC_ADD_CREDITCARD_EDIT_REPAYDAY, L"");
}
