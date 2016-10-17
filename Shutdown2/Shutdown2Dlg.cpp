
// Shutdown2Dlg.cpp : implementation file
// Implements the UI
//

#include "stdafx.h"
#include "Shutdown2.h"
#include "Shutdown2Dlg.h"
#include "afxdialogex.h"

#include <windows.h>
#include <PowrProf.h>

#include <iostream>
#include <ctime>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib, "PowrProf.lib")


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShutdown2Dlg dialog


CShutdown2Dlg::CShutdown2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShutdown2Dlg::IDD, pParent)
	, m_time(COleDateTime::GetCurrentTime())
	, m_Timer(_T(""))
	, m_Custom_time(0)
	, m_Selection(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShutdown2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER3, m_time);
	DDX_Control(pDX, IDC_CURRENT_TIME, m_CurrentTime);
	DDX_Text(pDX, IDC_CURRENT_TIME, m_Timer);
	DDX_Text(pDX, IDC_EDIT_CUSTOM, m_Custom_time);
	DDX_Control(pDX, IDC_DATETIMEPICKER3, m_time_changed);
	DDX_Control(pDX, IDC_EDIT_CUSTOM, m_Custom_time_control);
	DDX_CBString(pDX, IDC_COMBO1, m_Selection);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
}

BEGIN_MESSAGE_MAP(CShutdown2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON1, &CShutdown2Dlg::OnBnClickedButton1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER3, &CShutdown2Dlg::OnDtnDatetimechangeDatetimepicker3)
	ON_BN_CLICKED(IDC_BUTTON2, &CShutdown2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON60, &CShutdown2Dlg::OnBnClickedButton60)
	ON_BN_CLICKED(IDC_BUTTON30, &CShutdown2Dlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON15, &CShutdown2Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON_START, &CShutdown2Dlg::OnBnClickedButtonStart)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CShutdown2Dlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT_CUSTOM, &CShutdown2Dlg::OnEnChangeEditCustom)
	//ON_STN_CLICKED(IDC_CURRENT_TIME, &CShutdown2Dlg::OnStnClickedCurrentTime)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CUSTOM_BUTTON, &CShutdown2Dlg::OnBnClickedCustomButton)
END_MESSAGE_MAP()


// CShutdown2Dlg message handlers

BOOL CShutdown2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here	

	SetDlgItemText(IDC_EDIT_CUSTOM, TEXT("Minutes"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShutdown2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShutdown2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShutdown2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// OnDtnDatetimechangeDatetimepicker3
// Gets the time from the clock and sets the timer to this time

void CShutdown2Dlg::OnDtnDatetimechangeDatetimepicker3(NMHDR *pNMHDR, LRESULT *pResult)
{
	CTime newTime;
	m_time_changed.GetTime(newTime);
	m_time.SetTime(newTime.GetHour(), newTime.GetMinute(), newTime.GetSecond());
}

// OnBnClickedButton2
// Resets the clock to the current time

void CShutdown2Dlg::OnBnClickedButton2()
{
	time_t currentTime;
	struct tm localTime;
	time(&currentTime);

	localtime_s(&localTime, &currentTime);

	m_time.SetTime(localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
	UpdateData(FALSE);
}

// OnBnClickedButton60
// Adds 60 minutes to the timer

void CShutdown2Dlg::OnBnClickedButton60()
{
	time_t currentTime;
	struct tm localTime;
	time(&currentTime);

	localtime_s(&localTime, &currentTime);

	if ((localTime.tm_hour + 1) > 23) m_time.SetTime(0, localTime.tm_min, localTime.tm_sec);
	else m_time.SetTime((localTime.tm_hour+1), localTime.tm_min, localTime.tm_sec);

	//SetTimer(1, 2000, 0);

	UpdateData(FALSE);
}

// OnBnClickedButton30
// Adds 30 minutes to the timer

void CShutdown2Dlg::OnBnClickedButton30()
{
	time_t currentTime;
	struct tm localTime;
	time(&currentTime);

	localtime_s(&localTime, &currentTime);

	if ((localTime.tm_min + 30) > 59){
		if ((localTime.tm_hour + 1) > 23){
			m_time.SetTime(0, (localTime.tm_min + 30 - 60), localTime.tm_sec);
		}
		else m_time.SetTime(localTime.tm_hour + 1, (localTime.tm_min + 30 - 60), localTime.tm_sec);
	}

	else m_time.SetTime(localTime.tm_hour, (localTime.tm_min + 30), localTime.tm_sec);

	UpdateData(FALSE);
}

// OnBnClickedButton15
// Adds 15 minutes to the timer

void CShutdown2Dlg::OnBnClickedButton15()
{
	time_t currentTime;
	struct tm localTime;
	time(&currentTime);

	localtime_s(&localTime, &currentTime);
	
	if ((localTime.tm_min + 15) > 59){
		if ((localTime.tm_hour + 1) > 23){
			m_time.SetTime(0, (localTime.tm_min + 15 - 60), localTime.tm_sec);
		}
		else m_time.SetTime(localTime.tm_hour+1, (localTime.tm_min + 15 - 60), localTime.tm_sec);
	}

	else m_time.SetTime(localTime.tm_hour, (localTime.tm_min + 15), localTime.tm_sec);

	UpdateData(FALSE);

}

// OnBnClickedButtonStart
// Starts or stops the timer

void CShutdown2Dlg::OnBnClickedButtonStart()
{
	if (!started){
		started = true;
		GetDlgItem(IDC_BUTTON_START)->SetWindowText(_T("Stop"));
		int currentSeconds = ((m_time.GetCurrentTime().GetHour() * 3600) + m_time.GetCurrentTime().GetMinute() * 60 + m_time.GetCurrentTime().GetSecond());
		int customSeconds = ((m_time.GetHour()*3600) + m_time.GetMinute() * 60 + m_time.GetSecond());
		m_Seconds = customSeconds - currentSeconds;
		int m_SecondsTemp = m_Seconds;
		SetTimer(0, 1000, NULL);

	}
	else {
		started = false;
		GetDlgItem(IDC_BUTTON_START)->SetWindowText(_T("Start"));
		KillTimer(0);
	}
}

// OnCbnSelchangeCombo1
// Gets the selection from the combo box

void CShutdown2Dlg::OnCbnSelchangeCombo1()
{
	int selected = m_ComboBox.GetCurSel();
	
	if (selected == 0) selection = SHUTDOWN;
	else if (selected == 1) selection = RESTART;
	else if (selected == 2) selection = HIBERNATE;
	else if (selected == 3) selection = LOGOFF;
	else selection = SLEEP;
}



// OnTimer
// Controls the timer

void CShutdown2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	m_Seconds--;
	m_Timer.Format(_T("%d seconds left"), m_Seconds);
	UpdateData(FALSE);

	if (m_Seconds == 0){
		KillTimer(0);
		Execute(selection);
		OnBnClickedButtonStart();
	}

}

//Execute
// Runs the appropriate Windows API call

void CShutdown2Dlg::Execute(Type selection){
	switch (selection){
		case SHUTDOWN: ExitWindowsEx(EWX_POWEROFF, EWX_FORCEIFHUNG); break;
		case RESTART: ExitWindowsEx(EWX_REBOOT, EWX_FORCEIFHUNG); break;
		case HIBERNATE: SetSuspendState(TRUE, FALSE, FALSE); break;
		case LOGOFF: ExitWindowsEx(EWX_LOGOFF, EWX_FORCEIFHUNG); break;
		case SLEEP: SetSuspendState(TRUE, FALSE, FALSE); break;
	}
}

// OnBnCLickedCustomButton
// Gets times from custom time box

void CShutdown2Dlg::OnBnClickedCustomButton()
{
	time_t currentTime;
	struct tm localTime;
	time(&currentTime);

	localtime_s(&localTime, &currentTime);

	CString sCustomText;
	m_Custom_time_control.GetWindowText(sCustomText);

	int customTimeTemp = _ttoi(sCustomText);

	while (customTimeTemp > 60){
		if ((localTime.tm_hour + 1) > 23) m_time.SetTime(0, localTime.tm_min, localTime.tm_sec);
		else m_time.SetTime((localTime.tm_hour + 1), localTime.tm_min, localTime.tm_sec);
		customTimeTemp -= 60;
	}


	if ((m_time.GetMinute() + customTimeTemp) > 59){
		if ((localTime.tm_hour + 1) > 23){
			m_time.SetTime(0, (localTime.tm_min + customTimeTemp - 60), localTime.tm_sec);
		}
		else {
			m_time.SetTime(m_time.GetHour()+1, (localTime.tm_min + customTimeTemp - 60), localTime.tm_sec);
		}
	}

	else m_time.SetTime(localTime.tm_hour, (localTime.tm_min + customTimeTemp), localTime.tm_sec);

	UpdateData(FALSE);
}