#if !defined(AFX_LOGINMODDLG_H__F723BF76_6CF2_4D58_B3EE_04ECCE9D3B74__INCLUDED_)
#define AFX_LOGINMODDLG_H__F723BF76_6CF2_4D58_B3EE_04ECCE9D3B74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginModDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginModDlg dialog

class CLoginModDlg : public CDialog
{
// Construction
public:
	CLoginModDlg(CWnd* pParent = NULL);   // standard constructor
CAdoLx &m_ado;
// Dialog Data
	//{{AFX_DATA(CLoginModDlg)
	enum { IDD = IDD_LOGIN_MOD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginModDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginModDlg)
	afx_msg void OnMod();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINMODDLG_H__F723BF76_6CF2_4D58_B3EE_04ECCE9D3B74__INCLUDED_)
