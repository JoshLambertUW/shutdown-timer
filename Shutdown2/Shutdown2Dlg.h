
// Shutdown2Dlg.h : header file
//

#pragma once
#include "ATLComTime.h"
#include "afxwin.h"
#include "afxdtctl.h"


// CShutdown2Dlg dialog
class CShutdown2Dlg : public CDialogEx
{
// Construction
public:
	CShutdown2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SHUTDOWN2_DIALOG };

	int m_Seconds;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	enum Type { SHUTDOWN, RESTART, HIBERNATE, LOGOFF, SLEEP};
	Type selection;
	bool started = false;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	//afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	COleDateTime m_time;
	afx_msg void OnBnClickedButton60();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButtonCustom();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEditCustom();
	afx_msg void OnStnClickedCurrentTime();
	CStatic m_CurrentTime;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void Execute(Type selection);
private:
	CString m_Timer;
	int m_Custom_time;
public:
	CDateTimeCtrl m_time_changed;
	CEdit m_Custom_time_control;
	CString m_Selection;
	CComboBox m_ComboBox;
	afx_msg void OnBnClickedCustomButton();
};
