#if !defined(AFX_FINDDLG_H__7C79B8E0_55C0_4EE0_9CBF_9F3CA176664D__INCLUDED_)
#define AFX_FINDDLG_H__7C79B8E0_55C0_4EE0_9CBF_9F3CA176664D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindDlg.h : header file
//
#include "WorkerDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CFindDlg dialog

class CFindDlg : public CDialog
{
// Construction

public:

	CFindDlg(CWnd* pParent = NULL);   // standard constructor
    CWorkerDlg *m_pDlg;
// Dialog Data
	//{{AFX_DATA(CFindDlg)
	enum { IDD = IDD_FIND_DLG };
	CComboBox	m_depar;
	int		m_age2;
	COleDateTime	m_date1;
	COleDateTime	m_date2;
	CString	m_Fname;
	CString	m_Lname;
	int		m_isex;
	CString	m_nrank;
	CString	m_nsala;
	CString	m_nsala2;
	BOOL	m_bage;
	BOOL	m_bdate;
	BOOL	m_bdepart;
	BOOL	m_bfname;
	BOOL	m_blname;
	BOOL	m_bnumb;
	BOOL	m_brank;
	BOOL	m_bsala;
	BOOL	m_bsex;
	CString	m_depart;
	CString	m_num1;
	CString	m_num2;
	int	m_age1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindDlg)
	afx_msg void OnFind();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDDLG_H__7C79B8E0_55C0_4EE0_9CBF_9F3CA176664D__INCLUDED_)
