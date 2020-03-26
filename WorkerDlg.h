#if !defined(AFX_WORKERDLG_H__E8CA1421_54F3_45F3_8AE1_10C3B1345089__INCLUDED_)
#define AFX_WORKERDLG_H__E8CA1421_54F3_45F3_8AE1_10C3B1345089__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWorkerDlg dialog

class CWorkerDlg : public CDialog
{
// Construction
	CToolTipCtrl m_tip;
public:
	void Load();
	BOOL SetTipText(UINT id, NMHDR *pHdr, LRESULT *pResult);
	CString GetListText();
	CWorkerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWorkerDlg)
	enum { IDD = IDD_WORKER };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkerDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWorkerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	afx_msg void OnSave();
	afx_msg void OnOpen();
	afx_msg void OnSerach();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKERDLG_H__E8CA1421_54F3_45F3_8AE1_10C3B1345089__INCLUDED_)
