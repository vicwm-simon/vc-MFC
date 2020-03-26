// LoginModDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ա����Ϣϵͳ.h"
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
	AfxMessageBox("�����벻��Ϊ��!");
	return;
}
if(szNew!=szConf)
{
AfxMessageBox("������������벻һ��!����������!");
SetDlgItemText(IDC_NEW,"");
SetDlgItemText(IDC_CONF,"");
return;
}
if(szNew==szOld)
{
	AfxMessageBox("�����벻�ܺ;�������ͬ!����������!");
SetDlgItemText(IDC_NEW,"");
SetDlgItemText(IDC_CONF,"");
	return;
}

szSQL1.Format("UPDATE t_user SET f_pass='%s' WHERE f_name='%s' AND f_pass='%s'",szNew,theApp.sName,szOld);
int nRet=m_ado.ExecSQL(szSQL1);
if(nRet<0)
{
	AfxMessageBox("�޸��������!"+m_ado.GetLastError());
	return;
}
if(nRet==0)
{
	AfxMessageBox("�������������!����������!");
	return;
}
AfxMessageBox("�޸�����ɹ�!");
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
