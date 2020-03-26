#if !defined(AFX_INPUTDLG_H__945A92A9_113A_47BA_A0F6_1F314C1410A2__INCLUDED_)
#define AFX_INPUTDLG_H__945A92A9_113A_47BA_A0F6_1F314C1410A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputDlg.h : header file
//
#include "WorkerDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog

class CInputDlg : public CDialog
{
// Construction
public:
	CInputDlg(CWnd* pParent = NULL);   // standard constructor
CWorkerDlg *m_pDlg;
// Dialog Data
	//{{AFX_DATA(CInputDlg)
	enum { IDD = IDD_INPUT };
	int		m_iSex;
	CString	m_szdepart;
	COleDateTime	m_szDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInputDlg)
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	afx_msg void OnBack();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDLG_H__945A92A9_113A_47BA_A0F6_1F314C1410A2__INCLUDED_)
