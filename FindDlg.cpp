// FindDlg.cpp : implementation file
//

#include "stdafx.h"
#include "员工信息系统.h"
#include "FindDlg.h"
#include "WorkerDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindDlg dialog
extern CMyApp theApp;

CFindDlg::CFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindDlg)
	m_age2 = 0;
	m_date2 = COleDateTime::GetCurrentTime();
m_date1 = COleDateTime::GetCurrentTime();
	m_Fname = _T("");
	m_Lname = _T("");
	m_isex = -1;
	m_nrank = _T("");
	m_nsala = _T("");
	m_nsala2 = _T("");
	m_bage = FALSE;
	m_bdate = FALSE;
	m_bdepart = FALSE;
	m_bfname = FALSE;
	m_blname = FALSE;
	m_bnumb = FALSE;
	m_brank = FALSE;
	m_bsala = FALSE;
	m_bsex = FALSE;
	m_depart = _T("");
	m_num1 = _T("");
	m_num2 = _T("");
	m_age1 = 0;
	//}}AFX_DATA_INIT
}


void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindDlg)
	DDX_Control(pDX, IDC_DEPART, m_depar);
	DDX_Text(pDX, IDC_AGE2, m_age2);
	DDX_DateTimeCtrl(pDX, IDC_BIRDATE1, m_date1);
	DDX_DateTimeCtrl(pDX, IDC_BIRDATE2, m_date2);
	DDX_Text(pDX, IDC_fNAME2, m_Fname);
	DDX_Text(pDX, IDC_lNAME, m_Lname);
	DDX_Radio(pDX, IDC_RADIO1, m_isex);
	DDX_Text(pDX, IDC_RANK, m_nrank);
	DDX_Text(pDX, IDC_SALA1, m_nsala);
	DDX_Text(pDX, IDCSALA2, m_nsala2);
	DDX_Check(pDX, IDC_CHECK_AGE, m_bage);
	DDX_Check(pDX, IDC_CHECK_DATE, m_bdate);
	DDX_Check(pDX, IDC_CHECK_DEPART, m_bdepart);
	DDX_Check(pDX, IDC_CHECK_FNAME, m_bfname);
	DDX_Check(pDX, IDC_CHECK_LNAME, m_blname);
	DDX_Check(pDX, IDC_CHECK_NUM, m_bnumb);
	DDX_Check(pDX, IDC_CHECK_RANK, m_brank);
	DDX_Check(pDX, IDC_CHECK_SALA, m_bsala);
	DDX_Check(pDX, IDC_CHECK_SEX, m_bsex);
	DDX_CBString(pDX, IDC_DEPART, m_depart);
	DDX_Text(pDX, IDC_NUM_WORKER1, m_num1);
	DDX_Text(pDX, IDC_NUM_WORKER2, m_num2);
	DDX_Text(pDX, IDC_NAGE1, m_age1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialog)
	//{{AFX_MSG_MAP(CFindDlg)
	ON_BN_CLICKED(IDFIND, OnFind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindDlg message handlers

void CFindDlg::OnFind() 
{
	// TODO: Add your control notification handler code here

	CString szSQL="SELECT *FROM t_worker ";
	UpdateData();
	CString str;
	//工号
	if(m_bnumb)
	{
		if(m_num1&&m_num2)
			str.Format("f_numb>='%s' AND f_numb<='%s'",m_num1,m_num2);
	}
	//姓名
	if(m_blname)
	{
		if(str.GetLength())
		str+=" AND ";
		CString szText;
		szText.Format("f_name LIKE '%s%%'",m_Lname);
		str+=szText;
	}
	if(m_bfname)
	{
if(str.GetLength())
		str+=" AND ";
		CString szText;
		szText.Format("f_name LIKE '%%%s'",m_Fname);
		str+=szText;
	}
if(m_blname&&m_bfname)
	{
if(str.GetLength())
		str+=" AND ";
		CString szText,szName;
		szName+=m_Lname;
		szName+=m_Fname;
		szText.Format("f_name='%s'",szName);
		str+=szText;
	}

//性别
if(m_bsex)
	{
if(str.GetLength())
		str+=" AND ";
CString szText,szSex;
if(m_isex)
szSex="女";
else
szSex="男";
		
		szText.Format("f_sex='%s'",szSex);
		str+=szText;
	}

//年龄
	if(m_bage)
	{
      if(str.GetLength())
		str+=" AND ";
CString szText;
		if(m_age1&&m_age2)
		{
		
			szText.Format("f_age>=%d AND f_age<=%d",m_age1,m_age2);
		str+=szText;
		}
	}

	//出生日期

	if(m_bdate)
	{
      if(str.GetLength())
		str+=" AND ";
CString szText,szStart,szEnd;
szStart=m_date1.Format("%Y年%m月%d日");
szEnd=m_date2.Format("%Y年%m月%d日");
			szText.Format("f_date>='%s' AND f_date<='%s'",szStart,szEnd);
		str+=szText;
		
	}

//部门
	if(m_bdepart)
	{
      if(str.GetLength())
		str+=" AND ";
CString szText;
szText.Format("f_depart='%s'",m_depart);
		str+=szText;
		
	}

//岗位
	if(m_brank)
	{
      if(str.GetLength())
		str+=" AND ";
CString szText;
szText.Format("f_work='%s'",m_nrank);
		str+=szText;
		
	}

	//薪资
	if(m_bsala)
	{
       if(str.GetLength())
		str+=" AND ";
CString szText;
		if(m_nsala&&m_nsala2)
		{
		
			szText.Format("f_sala>='%s' AND f_sala<='%s'",m_nsala,m_nsala2);
		str+=szText;
		}
		
	}
	if(str.GetLength())
		szSQL+=" WHERE "+str;
	if(theApp.m_ado.Select(szSQL)<0)
	{
		AfxMessageBox("查询失败!"+theApp.m_ado.GetLastError());
		return;
	}

if(theApp.m_ado.IsEOF())
	{
		AfxMessageBox("没有符合条件的信息!");
		return;
	}

CString m_szNum,m_szName,m_szAge,m_szRank,m_szSala,m_szSex,m_szDepart;int i=0,age=0;
m_pDlg->m_list.DeleteAllItems();
while(!theApp.m_ado.IsEOF())
{
	theApp.m_ado.GetFieldByIndex(0,m_szNum);
	m_pDlg->m_list.InsertItem(i,m_szNum);
theApp.m_ado.GetFieldByIndex(1,m_szName);
	m_pDlg->m_list.SetItemText(i,1,m_szName);

theApp.m_ado.GetFieldByIndex(2,m_szSex);
	m_pDlg->m_list.SetItemText(i,2,m_szSex);

theApp.m_ado.GetFieldByIndex(3,age);
m_szAge.Format("%d",age);
	m_pDlg->m_list.SetItemText(i,3,m_szAge);

theApp.m_ado.GetFieldByIndex(4,str);
	m_pDlg->m_list.SetItemText(i,4,str);

theApp.m_ado.GetFieldByIndex(5,m_szDepart);
	m_pDlg->m_list.SetItemText(i,5,m_szDepart);
theApp.m_ado.GetFieldByIndex(6,m_szRank);
	m_pDlg->m_list.SetItemText(i,6,m_szRank);
theApp.m_ado.GetFieldByIndex(7,m_szSala);
	m_pDlg->m_list.SetItemText(i,7,m_szSala);
	
	i++;
theApp.m_ado.MoveNext();
}
CDialog::OnOK();
}

BOOL CFindDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_depar.AddString("运维部");
m_depar.AddString("营销部");
 m_depar.AddString("技术部");
 m_depar.AddString("市场部");
 m_depar.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
