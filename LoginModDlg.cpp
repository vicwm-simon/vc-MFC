// LoginModDlg.cpp : implementation file
//

#include "stdafx.h"
#include "员工信息系统.h"
#include "LoginModDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginModDlg dialog
extern CMyApp theApp;

CLoginModDlg::CLoginModDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginModDlg::IDD, pParent),m_ado(theApp.m_ado)
{
	//{{AFX_DATA_INIT(CLoginModDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginModDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginModDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginModDlg)
	ON_BN_CLICKED(IDMOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginModDlg message handlers

void CLoginModDlg::OnMod() 
{
	// TODO: Add your control notification handler code here
	CString szOld,szNew,szConf,szSQL,szSQL1;

	GetDlgItemText(IDC_OLD,szOld);
GetDlgItemText(IDC_NEW,szNew);
GetDlgItemText(IDC_CONF,szConf);
if(szNew.IsEmpty())
{
	AfxMessageBox("新密码不能为空!");
	return;
}
if(szNew!=szConf)
{
AfxMessageBox("两次输入的密码不一致!请重新输入!");
SetDlgItemText(IDC_NEW,"");
SetDlgItemText(IDC_CONF,"");
return;
}
if(szNew==szOld)
{
	AfxMessageBox("新密码不能和旧密码相同!请重新输入!");
SetDlgItemText(IDC_NEW,"");
SetDlgItemText(IDC_CONF,"");
	return;
}

szSQL1.Format("UPDATE t_user SET f_pass='%s' WHERE f_name='%s' AND f_pass='%s'",szNew,theApp.sName,szOld);
int nRet=m_ado.ExecSQL(szSQL1);
if(nRet<0)
{
	AfxMessageBox("修改密码出错!"+m_ado.GetLastError());
	return;
}
if(nRet==0)
{
	AfxMessageBox("旧密码输入错误!请重新输入!");
	return;
}
AfxMessageBox("修改密码成功!");
CDialog::OnOK();
}

BOOL CLoginModDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString szSQL,szOld;
	// TODO: Add extra initialization here
		szSQL.Format("SELECT *FROM t_user WHERE f_name='%s'",theApp.sName);
//m_ado.GetFieldByIndex(1,szOld);
//AfxMessageBox(szOld);
	SetDlgItemText(IDC_OLD,theApp.sPass);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
