// ManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "员工信息系统.h"
#include "ManageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMyApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CManageDlg dialog


CManageDlg::CManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManageDlg)
	m_name = _T("");
	m_pass = _T("");
	m_prior = _T("");
	//}}AFX_DATA_INIT
}


void CManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManageDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_PASS, m_pass);
	DDX_CBString(pDX, IDC_PRIOR, m_prior);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManageDlg, CDialog)
	//{{AFX_MSG_MAP(CManageDlg)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_WM_CONTEXTMENU()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageDlg message handlers

void CManageDlg::ReadUsers(CListCtrl *pList)
{
CFile file;
pList->DeleteAllItems();
if(!file.Open("./Users.dat",CFile::modeRead))
return;
SUser u;
int i=0;
while(file.Read(&u,sizeof(u))>0)
{
	pList->InsertItem(i,u.sName);
	pList->SetItemText(i,1,u.sPass);
	pList->SetItemText(i,2,u.sPrior);
	++i;
}
file.Close();
}


BOOL CManageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	Invalidate();
	// TODO: Add extra initialization here
	CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
	pList->InsertColumn(0,"用户名",LVCFMT_CENTER  ,100);
pList->InsertColumn(1,"密码",LVCFMT_CENTER  ,100);
pList->InsertColumn(2,"权限",LVCFMT_CENTER  ,50);
CComboBox *pComb=(CComboBox *)GetDlgItem(IDC_PRIOR);
pComb->AddString("普通");
pComb->AddString("高级");
pComb->SetCurSel(1);
//ReadUsers(pList);
GetDlgItem(IDC_NAME)->SetFocus();


Load();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}




void CManageDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	CFile file;
	if(!file.Open("./Users.dat",CFile::modeWrite|CFile::modeCreate))
		return;
CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
int i=0,ncount=pList->GetItemCount();
SUser u;
while(i<ncount)
{
	pList->GetItemText(i,0,u.sName,sizeof(u.sName));
	pList->GetItemText(i,1,u.sPass,sizeof(u.sPass));
	pList->GetItemText(i,2,u.sPrior,sizeof(u.sPrior));
file.Write(&u,sizeof(u));
i++;
	// TODO: Add your message handler code here
	
}
file.Close();
}

void CManageDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString m_szName,m_szPass,m_szPrior,szSQL;;
GetDlgItemText(IDC_NAME,m_szName);
if(m_szName=="")
{
	AfxMessageBox("姓名为空!请输入姓名!");
  GetDlgItem(IDC_NAME)->SetFocus();
  return;
}

		GetDlgItemText(IDC_PASS,m_szPass);
	GetDlgItemText(IDC_PRIOR,m_szPrior);
	szSQL.Format("INSERT INTO t_user VALUES('%s','%s','%s')",m_szName,m_szPass,m_szPrior);
	if(theApp.m_ado.ExecSQL(szSQL)<0)
		AfxMessageBox("插入失败!"+theApp.m_ado.GetLastError());
	else
		Load();
}

void CManageDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
	POSITION pos=pList->GetFirstSelectedItemPosition();//以选中颜色为准
int nsel=pList->GetNextSelectedItem(pos);
if(nsel<0)
{
	AfxMessageBox("请选择一个用户删除!");
	return;
}

CString szName=pList->GetItemText(nsel,0);
if(szName=="admin")
return;
CString str;
str.Format("确定要删除账号%s吗？",szName);
if(IDYES==AfxMessageBox(str,MB_YESNO))

{
	CString szSQL;
szSQL.Format("DELETE FROM t_user WHERE f_name='%s'",szName);
if(theApp.m_ado.ExecSQL(szSQL)<0)
AfxMessageBox("删除失败!"+theApp.m_ado.GetLastError());
else
Load();
}
}

void CManageDlg::OnMod() 
{
	// TODO: Add your control notification handler code here
	//GetDlgItem(IDC_
	UpdateData();
		CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
	POSITION pos=pList->GetFirstSelectedItemPosition();//以选中颜色为准
int nsel=pList->GetNextSelectedItem(pos);
if(nsel<0)
{
	AfxMessageBox("请选择一个用户修改!");
	return;
}
CString szName=pList->GetItemText(nsel,0);

if(szName=="admin")
return;
CString str;
str.Format("确定要修改账号%s吗？",szName);
if(IDYES==AfxMessageBox(str,MB_YESNO))

{
	
	CString szSQL;
szSQL.Format("UPDATE t_user SET f_name='%s',f_pass='%s',f_prior='%s' WHERE f_name='%s'",
		m_name,m_pass,m_prior,szName);
if(theApp.m_ado.ExecSQL(szSQL)<0)
AfxMessageBox("修改失败!"+theApp.m_ado.GetLastError());
else
Load();
}

}

void CManageDlg::Load()
{
CString nName,nPass,nPrior;int i=0;
if(!theApp.m_ado.Select("SELECT *FROM t_user"))
return;
m_list.DeleteAllItems();
while(!theApp.m_ado.IsEOF())
{
	theApp.m_ado.GetFieldByIndex(0,nName);
	m_list.InsertItem(i,nName);
theApp.m_ado.GetFieldByIndex(1,nPass);
	m_list.SetItemText(i,1,nPass);
theApp.m_ado.GetFieldByIndex(2,nPrior);
	m_list.SetItemText(i,2,nPrior);
	i++;
theApp.m_ado.MoveNext();
}
}

void CManageDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
		POSITION pos=m_list.GetFirstSelectedItemPosition();
	int nSel=m_list.GetNextSelectedItem(pos);
	if(nSel<0)
		return;
	CRect rect;
//	SetClientRect(;
//	SInfo &info=theApp.m_info;
	if(nSel)
	{
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu *pMenu=menu.GetSubMenu(0);


pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON,point.x,point.y,this);
	
menu.DestroyMenu();
	}

}

//DEL void CManageDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 		CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
//DEL 	POSITION pos=pList->GetFirstSelectedItemPosition();//以选中颜色为准
//DEL int nsel=pList->GetNextSelectedItem(pos);
//DEL CString szName=pList->GetItemText(nsel,0);
//DEL SetDlgItemText(IDC_NAME,szName);
//DEL SetDlgItemText(IDC_PASS,pList->GetItemText(nsel,1));
//DEL SetDlgItemText(IDC_PRIOR,pList->GetItemText(nsel,2));
//DEL 	CDialog::OnLButtonDblClk(nFlags, point);
//DEL }

//DEL void CManageDlg::OnLButtonDown(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 		
//DEL 	CDialog::OnLButtonDown(nFlags, point);
//DEL }

void CManageDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
	POSITION pos=pList->GetFirstSelectedItemPosition();//以选中颜色为准
 int nsel=pList->GetNextSelectedItem(pos);
 CString szName=pList->GetItemText(nsel,0);
 SetDlgItemText(IDC_NAME,szName);
 SetDlgItemText(IDC_PASS,pList->GetItemText(nsel,1));

m_prior=pList->GetItemText(nsel,2);
	*pResult = 0;
}
