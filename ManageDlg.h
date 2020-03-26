#if !defined(AFX_MANAGEDLG_H__1B69883D_E401_40DA_85B0_F0376D5C31B4__INCLUDED_)
#define AFX_MANAGEDLG_H__1B69883D_E401_40DA_85B0_F0376D5C31B4__INCLUDED_

#include "AdoLx.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManageDlg dialog



class CManageDlg : public CDialog
{
// Construction
public:
	void Load();

	void ReadUsers(CListCtrl *pList);
	CManageDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CManageDlg)
	enum { IDD = IDD_PRIOR };
	CListCtrl	m_list;
	CString	m_name;
	CString	m_pass;
	CString	m_prior;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEDLG_H__1B69883D_E401_40DA_85B0_F0376D5C31B4__INCLUDED_)

