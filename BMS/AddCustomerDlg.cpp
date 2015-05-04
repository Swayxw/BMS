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

	//��ȡ�ͻ�����
	CString strName;
	this->GetDlgItemTextW(IDC_EDIT_NAME, strName);

	//��ȡ�ͻ��Ա�
	int nGender = ((CButton *)this->GetDlgItem(IDC_RADIO_MALE))->GetCheck();
	
	//��ȡ�ͻ����֤��
	CString strIdNum;
	this->GetDlgItemTextW(IDC_EDIT_IDNUM, strIdNum);

	//��ȡ�ͻ��绰����
	CString strPhoneNum;
	this->GetDlgItemTextW(IDC_EDIT_PHONENUM, strPhoneNum);

	//��ȡ�ͻ���ַ
	CString strAddress;
	this->GetDlgItemTextW(IDC_EDIT_ADDRESS, strAddress);

	//��ȡ�ͻ�����
	CString strEmail;
	this->GetDlgItemTextW(IDC_EDIT_EMAIL, strEmail);


	//��������˻�
	char aAccount[21] = {'A'};
	CToolKit::GenerateId(aAccount, sizeof(aAccount));

	//����ͻ���Ϣ
	customer.setAccount(aAccount);

	if (!strName.IsEmpty())
	{
		char aName[15] = { 0 };
		CToolKit::ToChars(aName, strName, sizeof(aName));
		customer.setName(aName);
		if (strName.GetLength() > 15)
		{
			if (IDOK == MessageBox(L"����̫��\n���ֳ��Ȳ�����15���ַ�"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"���ֲ���Ϊ��"))
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
			if (IDOK == MessageBox(L"���֤��̫��\n���֤�ų��Ȳ�����18���ַ�"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"���֤�Ų���Ϊ��"))
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
			if (IDOK == MessageBox(L"�ֻ�����̫��\n�ֻ����볤�Ȳ�����11���ַ�"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"�ֻ��Ų���Ϊ��"))
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
			if (IDOK == MessageBox(L"��ͥסַ̫��\n��ͥסַ���Ȳ�����128���ַ�"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"��ַ����Ϊ��"))
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
			if (IDOK == MessageBox(L"����̫��\n���䳤�Ȳ�����32���ַ�"))
			{
				return;
			}
		}
	}
	else
	{
		if (IDOK == MessageBox(L"���䲻��Ϊ��"))
		{
			return;
		}
	}

	customer.setCredit(1);


	//��ǰʱ��
	time_t t = time(NULL);
	struct tm pTime;
	localtime_s(&pTime, &t);
	customer.setCreateDate(pTime);

	//
	CCustomerDao customerDao;
	if (customerDao.Save(&customer) == TRUE)
	{
		MessageBox(L"�����ɹ�\n�ʺţ�" + CToolKit::ToString(aAccount, 21));
	}
	else
	{
		MessageBox(L"����ʧ��");
	}

	//����ı���Ϣ
	this->SetDlgItemTextW(IDC_EDIT_NAME, L"");
	((CButton *)this->GetDlgItem(IDC_RADIO_MALE))->SetCheck(1);
	this->SetDlgItemTextW(IDC_EDIT_IDNUM, L"");
	this->SetDlgItemTextW(IDC_EDIT_ADDRESS, L"");
	this->SetDlgItemTextW(IDC_EDIT_PHONENUM, L"");
	this->SetDlgItemTextW(IDC_EDIT_EMAIL, L"");
	this->SetDlgItemTextW(IDC_EDIT_ADDRESS, L"");

	//CDialogEx::OnOK();
}
