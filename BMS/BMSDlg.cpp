
// BMSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BMS.h"
#include "BMSDlg.h"
#include "afxdialogex.h"
#include <string>
#include  "MainDialog.h"
#include "Classes\CStaffDao.h"
#include "Classes\CToolKit.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBMSDlg dialog



CBMSDlg::CBMSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBMSDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBMSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CBMSDlg::OnBnClickedBtnLogin)
END_MESSAGE_MAP()


// CBMSDlg message handlers

BOOL CBMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBMSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBMSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBMSDlg::OnBnClickedBtnLogin()
{
	// TODO: Add your control notification handler code here
	CString strAccount;
	CString strPassword;

	this->GetDlgItemTextW(IDC_EDIT_ACCOUNT, strAccount);
	this->GetDlgItemTextW(IDC_EDIT_PASSWORD, strPassword);

	char aAccount[21];
	char aPassword[15];
	
	CToolKit::ToChars(aAccount, strAccount, sizeof(aAccount));
	CToolKit::ToChars(aPassword, strPassword, sizeof(aPassword));

	CStaffDao staffDao;
	if (staffDao.Login(aAccount, aPassword) == TRUE)
	{
		//if (strPassword == _T("123456"))
		//{
		this->ShowWindow(SW_HIDE);
		//MessageBox(_T("µ«¬º≥…π¶"));
		CMainDialog dlg;
		CStaff *pStaff = staffDao.FindByAccount(aAccount);
		dlg.setInfo(CToolKit::ToString(const_cast<char *>(pStaff->getName().c_str()), pStaff->getName().size()));
		INT_PTR nRespon = dlg.DoModal();
		if (nRespon == IDCANCEL)
		{
			this->ShowWindow(SW_SHOW);
		}
		//}
	}
	else
	{
		MessageBox(L"’ ∫≈ªÚ’ﬂ√‹¬Î¥ÌŒÛ");
	}

}
