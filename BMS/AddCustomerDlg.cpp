// AddCustomerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "AddCustomerDlg.h"
#include "afxdialogex.h"
#include "Classes\CCustomer.h"
#include "Classes\CToolKit.h"
#include "Classes\CCustomerDao.h"


// CAddCustomerDlg dialog

IMPLEMENT_DYNAMIC(CAddCustomerDlg, CDialogEx)

CAddCustomerDlg::CAddCustomerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddCustomerDlg::IDD, pParent)
{

}

CAddCustomerDlg::~CAddCustomerDlg()
{
}

void CAddCustomerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddCustomerDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddCustomerDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddCustomerDlg message handlers


BOOL CAddCustomerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CButton *pBtn = (CButton*)this->GetDlgItem(IDC_RADIO_MALE);
	pBtn->SetCheck(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CAddCustomerDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CCustomer customer;

	//获取客户姓名
	CString strName;
	this->GetDlgItemTextW(IDC_EDIT_NAME, strName);

	//获取客户性别
	int nGender = ((CButton *)this->GetDlgItem(IDC_RADIO_MALE))->GetCheck();
	
	//获取客户身份证号
	CString strIdNum;
	this->GetDlgItemTextW(IDC_EDIT_IDNUM, strIdNum);

	//获取客户电话号吗
	CString strPhoneNum;
	this->GetDlgItemTextW(IDC_EDIT_PHONENUM, strPhoneNum);

	//获取客户地址
	CString strAddress;
	this->GetDlgItemTextW(IDC_EDIT_ADDRESS, strAddress);

	//获取客户邮箱
	CString strEmail;
	this->GetDlgItemTextW(IDC_EDIT_EMAIL, strEmail);


	//生成随机账户
	char aAccount[21] = {'A'};
	CToolKit::GenerateId(aAccount, sizeof(aAccount));

	//保存客户信息
	customer.setAccount(aAccount);

	if (!strName.IsEmpty())
	{
		char aName[15] = { 0 };
		CToolKit::ToChars(aName, strName, sizeof(aName));
		customer.setName(aName);
		if (strName.GetLength() > 15)
		{
			if (IDOK == MessageBox(L"名字太长\n名字长度不超过15个字符"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"名字不能为空"))
		{
			return;
		}
	}
	

	customer.setGender(nGender);

	if (!strIdNum.IsEmpty())
	{
		char aIdNum[19] = { 0 };
		CToolKit::ToChars(aIdNum, strIdNum, sizeof(aIdNum));
		customer.setIdNum(aIdNum);
		if (strIdNum.GetLength() > 18)
		{
			if (IDOK == MessageBox(L"身份证号太长\n身份证号长度不超过18个字符"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"身份证号不能为空"))
		{
			return;
		}
	}
	
	if (!strPhoneNum.IsEmpty())
	{
		char aPhoneNum[12] = { 0 };
		CToolKit::ToChars(aPhoneNum, strPhoneNum, sizeof(aPhoneNum));
		customer.setPhoneNum(aPhoneNum);
		if (strPhoneNum.GetLength() > 11)
		{
			if (IDOK == MessageBox(L"手机号码太长\n手机号码长度不超过11个字符"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"手机号不能为空"))
		{
			return;
		}
	}
	
	if (!strAddress.IsEmpty())
	{
		char aAddress[128] = { 0 };
		CToolKit::ToChars(aAddress, strAddress, sizeof(aAddress));
		customer.setAddress(aAddress);
		if (strAddress.GetLength() > 128)
		{
			if (IDOK == MessageBox(L"家庭住址太长\n家庭住址长度不超过128个字符"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"地址不能为空"))
		{
			return;
		}
	}
	
	if (!strEmail.IsEmpty())
	{
		char aEmail[32] = { 0 };
		CToolKit::ToChars(aEmail, strEmail, sizeof(aEmail));
		customer.setEmail(aEmail);
		if (strEmail.GetLength() > 32)
		{
			if (IDOK == MessageBox(L"邮箱太长\n邮箱长度不超过32个字符"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"邮箱不能为空"))
		{
			return;
		}
	}

	customer.setCredit(1);


	//当前时间
	time_t t = time(NULL);
	struct tm pTime;
	localtime_s(&pTime, &t);
	customer.setCreateDate(pTime);

	//
	CCustomerDao customerDao;
	if (customerDao.Save(&customer) == TRUE)
	{
		MessageBox(L"开户成功\n帐号：" + CToolKit::ToString(aAccount, 21));
	}
	else
	{
		MessageBox(L"开户失败");
	}

	//清空文本信息
	this->SetDlgItemTextW(IDC_EDIT_NAME, L"");
	((CButton *)this->GetDlgItem(IDC_RADIO_MALE))->SetCheck(1);
	this->SetDlgItemTextW(IDC_EDIT_IDNUM, L"");
	this->SetDlgItemTextW(IDC_EDIT_ADDRESS, L"");
	this->SetDlgItemTextW(IDC_EDIT_PHONENUM, L"");
	this->SetDlgItemTextW(IDC_EDIT_EMAIL, L"");
	this->SetDlgItemTextW(IDC_EDIT_ADDRESS, L"");

	//CDialogEx::OnOK();
}
