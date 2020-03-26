// ModDlg.cpp : implementation file
//

#include "stdafx.h"
#include "员工信息系统.h"
#include "ModDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModDlg dialog
extern CMyApp theApp;

CModDlg::CModDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModDlg)
	m_age = _T("");
	m_date = COleDateTime::GetCurrentTime();
	m_numb = _T("");
	m_name = _T("");
	m_depart = _T("");
	m_rank = _T("");
	m_salary = 0.0f;
	m_iSex = -1;
	//}}AFX_DATA_INIT
}


void CModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModDlg)
	DDX_Control(pDX, IDC_DEPART, m_DEPART);
	DDX_Text(pDX, IDC_AGE, m_age);
	DDX_DateTimeCtrl(pDX, IDC_DATE, m_date);
	DDX_Text(pDX, IDC_NUM_WORKER, m_numb);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_CBString(pDX, IDC_DEPART, m_depart);
	DDX_Text(pDX, IDC_RANK, m_rank);
	DDX_Text(pDX, IDC_SALARY, m_salary);
	DDX_Radio(pDX, IDC_RADIO1, m_iSex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModDlg, CDialog)
	//{{AFX_MSG_MAP(CModDlg)
	ON_BN_CLICKED(IDMOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModDlg message handlers

BOOL CModDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
//	CComboBox* pComb=(CComboBox*)GetDlgItem(IDC_DEPART);
 CListCtrl *pList=(CListCtrl *)m_pDlg->GetDlgItem(IDC_LIST1);
		POSITION pos=pList->GetFirstSelectedItemPosition();//以选中颜色为准
int nsel=pList->GetNextSelectedItem(pos);
UpdateData();
m_numb=pList->GetItemText(nsel,0);

m_name=pList->GetItemText(nsel,1);
CString str;
str=pList->GetItemText(nsel,2);
if(str=="男")
m_iSex=0;
else
m_iSex=1;

m_age=pList->GetItemText(nsel,3);

m_date.ParseDateTime(pList->GetItemText(nsel,4),VAR_DATEVALUEONLY);

m_depart=pList->GetItemText(nsel,5);
m_rank=pList->GetItemText(nsel,6);

m_salary=(float)atof(pList->GetItemText(nsel,7));
UpdateData(FALSE);

	
m_DEPART.AddString("运维部");
m_DEPART.AddString("营销部");
m_DEPART.AddString("技术部");
m_DEPART.AddString("市场部");
	// TODO: Add extra initialization here
	
 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CModDlg::OnMod() 
{
	// TODO: Add your control notification handler code here
	CListCtrl *pList=(CListCtrl *)m_pDlg->GetDlgItem(IDC_LIST1);
POSITION pos=pList->GetFirstSelectedItemPosition();//以选中颜色为准
int nsel=pList->GetNextSelectedItem(pos);
if(IDCANCEL==AfxMessageBox("是否要修改数据?",MB_OKCANCEL))
return;
CListCtrl& list = m_pDlg ->m_list;
	UpdateData();
CString m_szNum,m_szName,m_szAge,m_szRank,m_szSala,m_szSex,str,szSQL;
	//CString szSQL;
GetDlgItem(IDC_NAME)->SetFocus();

//	GetDlgItemText(IDC_NAME,m_szName);
/*if(m_szName=="")
{
	AfxMessageBox("姓名为空!请输入姓名!");
  GetDlgItem(IDC_NAME)->SetFocus();
  return;
}

*/
	m_szSex=m_iSex?"女":"男";
	str=m_date.Format("%Y年%m月%d日");
	m_szSala.Format("%0.2lf",m_salary);
	szSQL.Format("UPDATE t_worker SET f_name='%s',f_sex='%s',f_age='%s',f_date='%s',f_depart='%s',f_work='%s',f_sala='%s' WHERE f_numb='%s'",
		m_name,m_szSex,m_age,str,m_depart,m_rank,m_szSala,m_numb);
	if(theApp.m_ado.ExecSQL(szSQL)<0)
		AfxMessageBox("修改失败!"+theApp.m_ado.GetLastError());
	else
	{
	m_pDlg->Load();
	m_pDlg->SetWindowText("修改-员工信息");
	};
	    
/*
pList->SetItemText(nsel,0,m_numb);

//GetDlgItemText(IDC_NAME,str);
pList->SetItemText(nsel,1,m_name);
//GetDlgItemText(IDC_AGE,str);
pList->SetItemText(nsel,2,m_age);
//GetDlgItemText(IDC_DATE,str);
CString str;
//str.Format("%d年%d月%d日",m_date.GetYear(),m_date.GetMonth(),m_date.GetDay());
pList->SetItemText(nsel,3,m_date.Format("%Y年%m月%d日"));
//GetDlgItemText(IDC_DEPART,str);
pList->SetItemText(nsel,4,m_depart);
//GetDlgItemText(IDC_RANK,str);
pList->SetItemText(nsel,5,m_rank);
//GetDlgItemText(IDC_SALARY,str);
str.Format("%0.1f",m_salary);
pList->SetItemText(nsel,6,str);
*/

}

void CModDlg::OnCancel() 
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();

}
