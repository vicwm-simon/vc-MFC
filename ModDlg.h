#if !defined(AFX_MODDLG_H__D1C02970_4058_4D1A_A2F4_61DDCDC7DB36__INCLUDED_)
#define AFX_MODDLG_H__D1C02970_4058_4D1A_A2F4_61DDCDC7DB36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModDlg.h : header file
//
#include "WorkerDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CModDlg dialog

class CModDlg : public CDialog
{
// Construction
public:
	CModDlg(CWnd* pParent = NULL);   // standard constructor
CWorkerDlg *m_pDlg;
// Dialog Data
	//{{AFX_DATA(CModDlg)
	enum { IDD = IDD_MOD };
	CComboBox	m_DEPART;
	CString	m_age;
	COleDateTime	m_date;
	CString	m_numb;
	CString	m_name;
	CString	m_depart;
	CString	m_rank;
	float	m_salary;
	int		m_iSex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CModDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnMod();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODDLG_H__D1C02970_4058_4D1A_A2F4_61DDCDC7DB36__INCLUDED_)
