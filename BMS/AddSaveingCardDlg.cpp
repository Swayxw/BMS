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
#include "Classes\CardTypeDao.h"


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
	CardTypeDao pCardTypeDao;

	//�û��˻�
	char aAccount[21] = { '\0' };
	CToolKit::ToChars(aAccount, strAccount, sizeof(aAccount));
	if (!customer.IsExsit(aAccount))
	{
		if (IDOK == MessageBox(L"�û������ڣ�����������"))
		{
			return;
		}
	}
	pSavingCar.setAccount(aAccount);

	//�û�����
	if (strSetPassword.GetLength() != 6)
	{
		if (IDOK == MessageBox(L"���볤�Ȳ���ȷ�� Ӧ��Ϊ6λ"))
		{
			return;
		}
	}
	char aSetPassword[7] = { '\0' };
	CToolKit::ToChars(aSetPassword, strSetPassword, sizeof(aSetPassword));
	
	//ȷ������
	char aConfirmPassword[7] = { '\0' };
	CToolKit::ToChars(aConfirmPassword, strConfirmPassword, sizeof(aConfirmPassword));
	if (strcmp(aSetPassword, aConfirmPassword) != 0)
	{
		if (IDOK == MessageBox(L"ǰ���������벻��ͬ������������"))
		{
			return;
		}
	}
	pSavingCar.setPassword(aSetPassword);

	//���
	if (nMoney < 1)
	{
		if (IDOK == MessageBox(L"������С��1Ԫ������������"))
		{
			return;
		}
	}
	pSavingCar.setMoney((double)nMoney);

	//��������
	HWND hWnd = ::FindWindow(NULL, _T("���й���ϵͳ"));
	CMainDialog *pMainDlg = (CMainDialog *)FromHandle(hWnd);
	CString strStaffAccount = pMainDlg->getAccount();
	char aStaffAcount[21] = { '\0' };
	CToolKit::ToChars(aStaffAcount, strStaffAccount, sizeof(aStaffAcount));
	CStaffDao staffDao;
	CStaff *pStaff = NULL;
	pStaff = staffDao.FindByAccount(aStaffAcount);
	pSavingCar.setBankName(pStaff->getBankName().c_str());

	//��������
	pSavingCar.setType(0);

	//����ʱ��
	struct tm tempTm;
	time_t t = time(NULL);
	localtime_s(&tempTm, &t);
	pSavingCar.setCreateDate(tempTm);

	//����
	pSavingCar.setBonusPoints(0);

	//����
	pSavingCar.setInterestRate(double(0.31));

	//����
	char aCardNum[21] = {'S'};
	CToolKit::GenerateCardNum(aCardNum, sizeof(aCardNum));
	pSavingCar.setCardNum(aCardNum);

	if (pSavingCardDao.save(&pSavingCar) && pCardTypeDao.saveCardType(aCardNum, pSavingCar.getType()))
	{
		MessageBox(L"��������ɹ�\n���ţ�"+ CToolKit::ToString(aCardNum, sizeof(aCardNum)) + "\n���μǿ���");
	}
	else
	{
		MessageBox(L"�������ʧ�ܣ�������Ϣ�Ƿ�����");
	}

	this->SetDlgItemTextW(IDC_ADD_SAVINGCARD_EDIT_USERACCOUNT, L"");
	this->SetDlgItemTextW(IDC_ADD_SAVINGCARD_EDIT_SETPASSWORD, L"");
	this->SetDlgItemTextW(IDC_ADD_SAVINGCARD_EDIT_CONFIRMPASSWORD, L"");
	this->SetDlgItemInt(IDC_ADD_SAVINGCARD_EDIT_SUM, 0);

}
