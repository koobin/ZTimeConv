// DateTimeTestDlg.h : header file
//

#pragma once


// CDateTimeTestDlg dialog
class CTimeConvTestDlg : public CDialog
{
// Construction
public:
	CTimeConvTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DATETIMETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	void UpdateSystemTime( SYSTEMTIME* st );	
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

protected:
	void UpdateResult( FILETIME& ft );
	void UpdateResult( time_t t );
	void SetRawFileTime( FILETIME& ft );
	void UpdateResultDosDate( DWORD dwDosDateTime );
	afx_msg void OnBnClickedGoSt();
	afx_msg void OnBnClickedGoFt();
	afx_msg void OnBnClickedGoDt();
	afx_msg void OnBnClickedGoUt();
	afx_msg void OnBnClickedGetsystemtime();
	afx_msg void OnBnClickedGetlocaltime();
	afx_msg void OnBnClickedGoFtRaw();
	afx_msg void OnBnClickedGettimet();
	afx_msg void OnBnClickedGoFtLocalRef();
	afx_msg void OnBnClickedGoFtLocal();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedGoDt2();

	DWORD		m_dwUnixTime;
	DWORD		m_dwDosDateTime;
	time_t		m_dwUnixTime_UTC;
	DWORD		m_dwDosDate;
	DWORD		m_dwDosTime;
	FILETIME	m_FileTime;
	FILETIME	m_FileTimeLocal;
	FILETIME	m_LocalRelFimeTime;
	ULONGLONG	m_FileTimeRaw;
	DWORD		m_dwFileTimeRawLO;
	DWORD		m_dwFileTimeRawHI;	
	UINT		m_nYear;
	UINT		m_nMonth;
	UINT		m_nDay;
	UINT		m_nHour;
	UINT		m_nMin;
	UINT		m_nSec;
	UINT		m_nMilliSec;
public:
	afx_msg void OnBnClickedGoUtUtc();
	afx_msg void OnBnClickedGoFtRawLohi();
};
