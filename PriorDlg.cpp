// PriorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "员工信息系统.h"
#include "PriorDlg.h"
#include "员工信息系统Dlg.h"
#include "ManageDlg.h"
#include "WorkerDlg.h"
#include "LoginModDlg.h"
extern CMyApp theApp;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg dialog


CPriorDlg::CPriorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPriorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPriorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPriorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPriorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPriorDlg, CDialog)
	//{{AFX_MSG_MAP(CPriorDlg)
	ON_BN_CLICKED(IDC_RELOGIN, OnRelogin)
	ON_BN_CLICKED(IDC_PRIOR, OnPrior)
	ON_BN_CLICKED(IDC_WORKER, OnWorker)
	ON_BN_CLICKED(IDC_BACKCOLO, OnBackcolo)
	ON_BN_CLICKED(IDC_FONTCOLO, OnFontcolo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg message handlers

void CPriorDlg::OnRelogin() 
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
	CMyDlg dlg;
	if(dlg.DoModal()==IDCANCEL)
		return;
	CPriorDlg dlg1;
	dlg1.DoModal();
//OnCancel();
	/*CString str;
if(dlg.DoModal()==IDCANCEL)
OnCancel();
else
{
	if(theApp.sPrior=="普通")
GetDlgItem(IDC_PRIOR)->SetWindowText("修改密码");
//	GetDlgItem(IDC_PRIOR)->EnableWindow(theApp.sPrior!="普通");
	str="-"+theApp.sPrior;
	str=theApp.sName+str;
	str=str+"用户 登录";
	str="用户名为 "+str;

	SetWindowText(str);
ShowWindow(SW_SHOW);
}
*/
}

void CPriorDlg::OnPrior() 
{
	// TODO: Add your control notification handler code here
if(theApp.sPrior=="高级")
{
	CManageDlg dlg;
	dlg.DoModal();
}
if(theApp.sPrior=="普通")
{
	CLoginModDlg dlg;
	dlg.DoModal();
}
}

BOOL CPriorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
CString str;
//	CString str=theApp.m_user.sPrior;
if(theApp.sPrior=="普通")
GetDlgItem(IDC_PRIOR)->SetWindowText("修改密码");
//	GetDlgItem(IDC_PRIOR)->EnableWindow(theApp.sPrior!="普通");
	str="-"+theApp.sPrior;
	str=theApp.sName+str;
	str=str+"用户 登录";
	str="用户名为 "+str;

	SetWindowText(str);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//DEL void CPriorDlg::OnWorker() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 
//DEL CWorker dlg;
//DEL dlg.DoModal();
//DEL 
//DEL 
//DEL 
//DEL 
//DEL 
//DEL }

//DEL void CPriorDlg::OnWorker() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	CWorker Dlg;
//DEL 
//DEL Dlg.DoModal();
//DEL }

void CPriorDlg::OnWorker() 
{
	// TODO: Add your control notification handler code here
	
	CWorkerDlg dlg;
if(IDCANCEL==dlg.DoModal())
return;
}

void CPriorDlg::OnBackcolo() 
{
	// TODO: Add your control notification handler code here
	theApp.OnBackCol();
	Invalidate();
}

void CPriorDlg::OnFontcolo() 
{
	// TODO: Add your control notification handler code here
	theApp.OnFontCol();
	Invalidate();
}
