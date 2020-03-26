// InputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "员工信息系统.h"
#include "InputDlg.h"
#include "WorkerDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog
extern CMyApp theApp;

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputDlg)
	m_iSex = 0;
	m_szdepart = _T("");
	m_szDate = COleDateTime::GetCurrentTime();
	//}}AFX_DATA_INIT
}


void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_iSex);
	DDX_CBString(pDX, IDC_DEPART, m_szdepart);
	DDX_DateTimeCtrl(pDX, IDC_DATE, m_szDate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
	//{{AFX_MSG_MAP(CInputDlg)
	ON_BN_CLICKED(IDADD, OnAdd)
	ON_BN_CLICKED(IDBACK, OnBack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputDlg message handlers

void CInputDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CListCtrl& list = m_pDlg ->m_list;
	UpdateData();
	CString m_szNum,m_szName,m_szAge,m_szRank,m_szSala,m_szSex,str,szSQL,birthdate;
GetDlgItem(IDC_NUM_WORKER)->SetFocus();
	GetDlgItemText(IDC_NUM_WORKER,m_szNum);
	GetDlgItemText(IDC_NAME,m_szName);

	int bdate=m_szDate.GetYear();
	birthdate.Format("%d",bdate);
	int sdate=COleDateTime::GetCurrentTime().GetYear();
	int m_age=sdate-bdate+1;
	m_szAge.Format("%d",m_age);
	UpdateData(FALSE);
	SetDlgItemText(IDC_AGE,m_szAge);

	GetDlgItemText(IDC_AGE,m_szAge);
	GetDlgItemText(IDC_RANK,m_szRank);
	GetDlgItemText(IDC_SALARY,m_szSala);
//	GetDlgItemText(IDC_NAME,m_szName);
/*if(m_szName=="")
{
	AfxMessageBox("姓名为空!请输入姓名!");
  GetDlgItem(IDC_NAME)->SetFocus();
  return;
}

*/
	m_szSex=m_iSex?"女":"男";
	str=m_szDate.Format("%Y年%m月%d日");
	
	szSQL.Format("INSERT INTO t_worker VALUES('%s','%s','%s','%s','%s','%s','%s','%s')",m_szNum,m_szName,m_szSex,m_szAge,str,m_szdepart,m_szRank,m_szSala);
	if(theApp.m_ado.ExecSQL(szSQL)<0)
		AfxMessageBox("插入失败!"+theApp.m_ado.GetLastError());
	else
		m_pDlg->Load();
	
	/*if(GetFocus()!=GetDlgItem(IDC_SALARY))
	{
		NextDlgCtrl();
		return;
	}
	CListCtrl& list = m_pDlg ->m_list;
		int i=list.GetItemCount(),r=0;
		CString str;
		GetDlgItemText(IDC_NUM_WORKER,str);
		while(r<i)
		{
			if(list.GetItemText(r,0)==str)
			{
				CString str1;
				str1.Format("您输入的工号 %s 已存在!请重新输入!",str);
				if(IDYES==AfxMessageBox(str1,MB_YESNO))
				{
SetDlgItemText(IDC_NUM_WORKER,"");
	SetDlgItemText(IDC_NAME,"");
	SetDlgItemText(IDC_AGE,"");
	
	SetDlgItemText(IDC_RANK,"");
	SetDlgItemText(IDC_SALARY,"");
	GetDlgItem(IDC_NUM_WORKER) ->SetFocus();
	return;
				}
				else
					return;
			}
			r++;
		}
if(IDNO==AfxMessageBox("确定要添加员工信息吗？",MB_YESNO))
return;				
list.InsertItem(i,str);
GetDlgItemText(IDC_NAME,str);
	list.SetItemText(i,1,str);
	list.SetItemText(i,2,m_iSex?"女":"男");
GetDlgItemText(IDC_AGE,str);
	list.SetItemText(i,3,str);
GetDlgItemText(IDC_DATE,str);
list.SetItemText(i,4,str);
GetDlgItemText(IDC_DEPART,str);
	list.SetItemText(i,5,str);
GetDlgItemText(IDC_RANK,str);
		list.SetItemText(i,6,str);
GetDlgItemText(IDC_SALARY,str);
list.SetItemText(i,7,str);
{
	if(IDYES==AfxMessageBox("是否要继续添加数据?",MB_YESNO))

		{
			SetDlgItemText(IDC_NUM_WORKER,"");
	SetDlgItemText(IDC_NAME,"");
	SetDlgItemText(IDC_AGE,"");
	
	SetDlgItemText(IDC_RANK,"");
	SetDlgItemText(IDC_SALARY,"");
	GetDlgItem(IDC_NUM_WORKER) ->SetFocus();
		}
		else
			return;
}*/
CDialog::OnOK();
}

BOOL CInputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CComboBox* pComb=	(CComboBox*)GetDlgItem(IDC_DEPART);
 pComb->AddString("运维部");
 pComb->AddString("营销部");
 pComb->AddString("技术部");
 pComb->AddString("市场部");
 pComb->SetCurSel(0);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CInputDlg::OnBack() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
