// WorkerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ա����Ϣϵͳ.h"
#include "WorkerDlg.h"
#include "InputDlg.h"
#include "ModDlg.h"
#include "FindDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CMyApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CWorkerDlg dialog


CWorkerDlg::CWorkerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWorkerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWorkerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWorkerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWorkerDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWorkerDlg, CDialog)
	//{{AFX_MSG_MAP(CWorkerDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_SERACH, OnSerach)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_NOTIFY_EX(TTN_NEEDTEXT,0,SetTipText)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkerDlg message handlers

BOOL CWorkerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_tip.Create(this);
	m_tip.SetMaxTipWidth(1000);
	m_tip.AddTool(GetDlgItem(IDC_LIST1));
	m_tip.Activate(TRUE);
	// TODO: Add extra initialization here
	CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
	pList->InsertColumn(0,"����",LVCFMT_CENTER,50);
pList->InsertColumn(1,"����",LVCFMT_CENTER,70);
pList->InsertColumn(2,"�Ա�",LVCFMT_CENTER,50);
pList->InsertColumn(3,"����",LVCFMT_CENTER,50);
pList->InsertColumn(4,"��������",LVCFMT_CENTER,150);
pList->InsertColumn(5,"����",LVCFMT_CENTER,70);
pList->InsertColumn(6,"��λ",LVCFMT_CENTER,100);
pList->InsertColumn(7,"н��",LVCFMT_CENTER,70);
pList->SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

Load();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWorkerDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here

CInputDlg dlg;
dlg.m_pDlg=this;
if(IDCANCEL==dlg.DoModal())
return;

}

void CWorkerDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
	POSITION pos=pList->GetFirstSelectedItemPosition();//��ѡ����ɫΪ׼
int nsel=pList->GetNextSelectedItem(pos);
if(nsel<0)
{
	AfxMessageBox("��ѡ��һ���û�ɾ��!");
	return;
}

CString szNumb=pList->GetItemText(nsel,0),str;
str.Format("ȷ��Ҫɾ������%s��Ա����Ϣ��",szNumb);
if(IDYES==AfxMessageBox(str,MB_YESNO))

{
	CString szSQL;
szSQL.Format("DELETE FROM t_worker WHERE f_numb='%s'",szNumb);
if(theApp.m_ado.ExecSQL(szSQL)<0)
AfxMessageBox("ɾ��ʧ��!"+theApp.m_ado.GetLastError());
else
Load();
}
	/*	CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
	POSITION pos=pList->GetFirstSelectedItemPosition();//��ѡ����ɫΪ׼
int nsel=pList->GetNextSelectedItem(pos);
if(nsel<0)
{
	AfxMessageBox("��ѡ��һ��Ա����Ϣɾ��!");
	return;
}
CString szName=pList->GetItemText(nsel,0);

CString str;
str.Format("ȷ��Ҫɾ������ %s ��",szName);
if(IDYES==AfxMessageBox(str,MB_YESNO))
pList->DeleteItem(nsel);
*/
}


void CWorkerDlg::OnMod() 
{
	// TODO: Add your control notification handler code here

	POSITION pos=m_list.GetFirstSelectedItemPosition();//��ѡ����ɫΪ׼
int nsel=m_list.GetNextSelectedItem(pos);
if(nsel<0)
{
	AfxMessageBox("��ѡ��һ��Ա����Ϣ�޸�!");
	return ;
}
SetWindowText("�����޸�Ա����Ϣ...");
CModDlg dlg;
dlg.m_pDlg=this;
if(IDCANCEL==dlg.DoModal())
return;

}

void CWorkerDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fd(FALSE,"ifo",NULL,OFN_OVERWRITEPROMPT,"��Ϣ�ļ�(*.ifo)|*ifo|�����ļ�|*.*||",NULL);
	if(IDCANCEL==fd.DoModal())
		return;
	CString str=fd.GetPathName();
	CFile file;
	if(!file.Open(str,CFile::modeWrite|CFile::modeCreate))
	{
		AfxMessageBox("����ʧ��!");
		return;
	}
	CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
	int i=0,nCount=pList->GetItemCount();
Info info;

	while(i<nCount)
	{
		info.nNumb=atoi(pList->GetItemText(i,0));
	pList->GetItemText(i,1,info.sName,sizeof(info.sName));
pList->GetItemText(i,2,info.nSex,sizeof(info.nSex));
info.nAge=atoi(pList->GetItemText(i,3));
pList->GetItemText(i,4,info.birth,sizeof(info.birth));
	pList->GetItemText(i,5,info.sDept,sizeof(info.sDept));
	pList->GetItemText(i,6,info.sRank,sizeof(info.sRank));
info.fSala=(float)atof(pList->GetItemText(i,7));
file.Write(&info,sizeof(info));
++i;
	}
	file.Close();

}

void CWorkerDlg::OnOpen() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fd(TRUE,"ifo",NULL,OFN_FILEMUSTEXIST,"��Ϣ�ļ�(*.ifo)|*ifo|�����ļ�|*.*||",NULL);
	if(IDCANCEL==fd.DoModal())
		return;
	CString str=fd.GetPathName();
	CFile file;
	if(!file.Open(str,CFile::modeRead|CFile::shareDenyNone))
	{
		AfxMessageBox("��ʧ��!");
		return;
	}
	CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);
	int i=0,nCount=pList->GetItemCount();
Info info;
pList->DeleteAllItems();

	while(file.Read(&info,sizeof(info)))
	{
	CString str;
	str.Format("%d",info.nNumb);
	pList->InsertItem(i,str);
	pList->SetItemText(i,1,info.sName);
	pList->SetItemText(i,2,info.nSex);

		str.Format("%d",info.nAge);
	pList->SetItemText(i,3,str);
	pList->SetItemText(i,4,info.birth);
pList->SetItemText(i,5,info.sDept);
pList->SetItemText(i,6,info.sRank);
str.Format("%0.1f",info.fSala);
	pList->SetItemText(i,7,str);
	++i;
	}
	file.Close();
}

void CWorkerDlg::OnSerach() 
{
	// TODO: Add your control notification handler code here
CFindDlg dlg;
dlg.m_pDlg=this;
if(IDCANCEL==dlg.DoModal())
return;
	/*	CString str,str1;
GetDlgItemText(IDC_COMBO1,str1);
CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);

//	str=pList->GetItemText(0,5);
	//AfxMessageBox(str);
	int nCount=pList->GetItemCount();
	int i=0;int count=0;
	while(i<nCount)
	{
		if(str1==pList->GetItemText(i,5))
		{
			count++;
	     int k=0;
		 while (k<8)
		 {
		 str=str+pList->GetItemText(i,k);
		 k++;
		 }
			//str.Format("%s %s %s %s %s %s %s %s",pList->GetItemText(i,0),pList->GetItemText(i,1),pList->GetItemText(i,2),pList->GetItemText(i,3),pList->GetItemText(i,4),pList->GetItemText(i,5),pList->GetItemText(i,6),pList->GetItemText(i,7));
	     AfxMessageBox(str);
		}
 
		i++;
	}
//	str.Format("��%s��������%d����!",str1,count);
//	AfxMessageBox(str);
*/
}

void CWorkerDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	OnMod() ;
	*pResult = 0;
}


CString CWorkerDlg::GetListText()
{
POSITION pos=m_list.GetFirstSelectedItemPosition();
int nItem=m_list.GetNextSelectedItem(pos);
	//if(!m_list.GetSelectedCount())
if(nItem<0)
return "δѡ��Ա����Ϣ";
//int nItem=m_list.GetSelectionMark();
CString str;

str.Format("ѡ�е�Ա����Ϣ:\r\n ����:%s\r\n ����:%s\r\n  �Ա�%s\r\n ���䣺%s\r\n �������£�%s\r\n ����:%s\r\n ��λ:%s\r\n н��:%s\r\n ",
		   m_list.GetItemText(nItem,0), m_list.GetItemText(nItem,1), m_list.GetItemText(nItem,2), m_list.GetItemText(nItem,3),
		    m_list.GetItemText(nItem,4), m_list.GetItemText(nItem,5), m_list.GetItemText(nItem,6), m_list.GetItemText(nItem,7));
return str;
}

BOOL CWorkerDlg::SetTipText(UINT id, NMHDR *pHdr, LRESULT *pResult)
{
TOOLTIPTEXT *pText=(TOOLTIPTEXT*)pHdr;
UINT nID=pHdr->idFrom;
if (pText->uFlags & TTF_IDISHWND)
    {
	
        nID = ::GetDlgCtrlID((HWND)nID);
	
        switch(nID)
        {
		case IDC_LIST1:
			{
		/*	if(!m_list.GetSelectedCount())
					return TRUE;
				int nSel = m_list.GetSelectionMark();
				CString str;
				str.Format("���:%s\r\n����:%s\r\n����:%s",
					m_list.GetItemText(nSel,0),
					m_list.GetItemText(nSel,1),
					m_list.GetItemText(nSel,2));
					*/
				
				strcpy(pText->lpszText,GetListText());
				return TRUE;
			}
        }
}
	return FALSE;
}





BOOL CWorkerDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_tip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}

void CWorkerDlg::Load()
{
CString m_szNum,m_szName,m_szAge,m_szRank,m_szSala,m_szSex,str,m_szDepart;int i=0,age=0;
if(!theApp.m_ado.Select("SELECT *FROM t_worker"))
return;
m_list.DeleteAllItems();
while(!theApp.m_ado.IsEOF())
{
	theApp.m_ado.GetFieldByIndex(0,m_szNum);
	m_list.InsertItem(i,m_szNum);
theApp.m_ado.GetFieldByIndex(1,m_szName);
	m_list.SetItemText(i,1,m_szName);

theApp.m_ado.GetFieldByIndex(2,m_szSex);
	m_list.SetItemText(i,2,m_szSex);

theApp.m_ado.GetFieldByIndex(3,age);
m_szAge.Format("%d",age);
	m_list.SetItemText(i,3,m_szAge);

theApp.m_ado.GetFieldByIndex(4,str);
	m_list.SetItemText(i,4,str);

theApp.m_ado.GetFieldByIndex(5,m_szDepart);
	m_list.SetItemText(i,5,m_szDepart);
theApp.m_ado.GetFieldByIndex(6,m_szRank);
	m_list.SetItemText(i,6,m_szRank);
theApp.m_ado.GetFieldByIndex(7,m_szSala);
	m_list.SetItemText(i,7,m_szSala);
	
	i++;
theApp.m_ado.MoveNext();
}
}
