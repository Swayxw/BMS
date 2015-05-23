// DepositDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "DepositDlg.h"
#include "afxdialogex.h"
#include "Classes\CToolKit.h"
#include "Classes\CardTypeDao.h"
#include "Classes\CCustomer.h"
#include "Classes\CCustomerDao.h"


// DepositDlg dialog

IMPLEMENT_DYNAMIC(DepositDlg, CDialogEx)

DepositDlg::DepositDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DepositDlg::IDD, pParent)
{

}

DepositDlg::~DepositDlg()
{
}

void DepositDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DepositDlg, CDialogEx)
	ON_BN_CLICKED(ID_BTN_DEPOSIT_OK, &DepositDlg::OnBnClickedBtnDepositOk)
END_MESSAGE_MAP()


// DepositDlg message handlers


void DepositDlg::OnBnClickedBtnDepositOk()
{
	// TODO: Add your control notification handler code here

	//��ȡ����Ŀ��źͽ��
	CString strCardNum;
	this->GetDlgItemTextW(IDC_DEPOSIT_EDIT_CARDNUM, strCardNum);
	char aCardNum[21] = {'\0'};
	CToolKit::ToChars(aCardNum, strCardNum, sizeof(aCardNum));

	CString strMoney;
	this->GetDlgItemTextW(IDC_DEPOSIT_EDIT_MONEY, strMoney);
	char aMoney[15] = {'\0'};
	CToolKit::ToChars(aMoney, strMoney, sizeof(aMoney));
	double dbMoney = atof(aMoney);


	//��ȡ�����ͣ����ݿ����ͽ��в�ͬ�Ĳ���
	CardTypeDao cardTypeDao;
	int nType = 0;
	if (!cardTypeDao.getTypeByCardNum(aCardNum, nType))
	{
		if (IDOK == MessageBox(L"û���ҵ�����Ϣ�����鿨�������Ƿ���ȷ"))
		{
			return;
		}
	}

	if (nType == 0)
	{
		//���������
		CSavingCardDao savingCardDao;
		CSavingCard *pSavingCard = savingCardDao.getCardByCardNum(aCardNum);
		if (pSavingCard != NULL)
		{
			Deposit(pSavingCard, dbMoney);
			//delete pSavingCard;
		}
		else
		{
			if (IDOK == MessageBox(L"û���ҵ��뿨����صĿ���Ϣ����ȷ�Ͽ����Ƿ���ȷ"))
			{
				return;
			}
		}
	}
	else
	{
		//���ÿ�������
		CCreditCardDao creditCardDao;
		CCreditCard *pCreditCard = creditCardDao.getCardByCardNum(aCardNum);
		if (pCreditCard != NULL)
		{
			Deposit(pCreditCard, dbMoney);
			//delete pCreditCard;
		}
		else
		{
			if (IDOK == MessageBox(L"û���ҵ��뿨����صĿ���Ϣ����ȷ�Ͽ����Ƿ���ȷ"))
			{
				return;
			}
		}
	}


	this->SetDlgItemTextW(IDC_DEPOSIT_EDIT_CARDNUM, L"");
	this->SetDlgItemTextW(IDC_DEPOSIT_EDIT_MONEY, L"");
}



void DepositDlg::Deposit(CSavingCard *pSavingCard, double dbMoney)
{
	//ȷ�Ͽͻ��˻�
	CCustomerDao customerDao;
	if (customerDao.IsExsit(pSavingCard->getAccount().c_str()))
	{
		pSavingCard->Deposit(dbMoney);
		CSavingCardDao savingCardDao;
		savingCardDao.Update(pSavingCard);
	}
	else
	{
		if (IDOK == MessageBox(L"û�ҵ��뿨�����Ӧ�Ŀͻ��˻���Ϣ����ȷ�Ͽ����Ƿ���ȷ"))
		{
			return;
		}
	}

}


void DepositDlg::Deposit(CCreditCard *pCreditCard, double dbMoney)
{
	//ȷ�Ͽͻ��˻�
	CCustomerDao customerDao;
	if (customerDao.IsExsit(pCreditCard->getAccount().c_str()))
	{
		pCreditCard->Deposit(dbMoney);
		CCreditCardDao creditCardDao;
		creditCardDao.Update(pCreditCard);
	}
	else
	{
		if (IDOK == MessageBox(L"û�ҵ��뿨�����Ӧ�Ŀͻ��˻���Ϣ����ȷ�Ͽ����Ƿ���ȷ"))
		{
			return;
		}
	}
}