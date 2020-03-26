#if !defined(AFX_PRIORDLG_H__8F969821_958F_47EA_93F3_7CD30BA81E6D__INCLUDED_)
#define AFX_PRIORDLG_H__8F969821_958F_47EA_93F3_7CD30BA81E6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PriorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg dialog

class CPriorDlg : public CDialog
{
// Construction
public:
	CPriorDlg(CWnd* pParent = NULL);   // standard constructor


// Dialog Data
	//{{AFX_DATA(CPriorDlg)
	enum { IDD = IDD_SYSTEM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPriorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPriorDlg)
	afx_msg void OnRelogin();
	afx_msg void OnPrior();
	virtual BOOL OnInitDialog();
	afx_msg void OnWorker();
	afx_msg void OnBackcolo();
	afx_msg void OnFontcolo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIORDLG_H__8F969821_958F_47EA_93F3_7CD30BA81E6D__INCLUDED_)
