// DateTimeTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TimeConvTest.h"
#include "TimeConvTestDlg.h"
#include "ZTimeConv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDateTimeTestDlg dialog



CTimeConvTestDlg::CTimeConvTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeConvTestDlg::IDD, pParent)
	, m_dwUnixTime(0)
	, m_dwDosDateTime(0)
	, m_dwDosDate(0)
	, m_dwDosTime(0)
	, m_FileTimeRaw(0)
	, m_nYear(0)
	, m_nMonth(0)
	, m_nDay(0)
	, m_nHour(0)
	, m_nMin(0)
	, m_nSec(0)
	, m_nMilliSec(0)
	, m_dwUnixTime_UTC(0)
	, m_dwFileTimeRawLO(0)
	, m_dwFileTimeRawHI(0)
{
	ZeroMemory(&m_LocalRelFimeTime, sizeof(FILETIME));
	ZeroMemory(&m_FileTimeLocal, sizeof(FILETIME));
	ZeroMemory(&m_FileTime, sizeof(FILETIME));
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimeConvTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_UNIXTIME_UTC, m_dwUnixTime_UTC);
	DDX_Text(pDX, IDC_UNIXTIME, m_dwUnixTime);
	DDX_Text(pDX, IDC_DOSTIME, m_dwDosDateTime);
	DDX_Text(pDX, IDC_DOSTIME2, m_dwDosDate);
	DDX_Text(pDX, IDC_DOSTIME3, m_dwDosTime);
	DDX_Text(pDX, IDC_FILETIME, m_FileTime);
	DDX_Text(pDX, IDC_FILETIME_RAW, m_FileTimeRaw);
	DDX_Text(pDX, IDC_FILETIME_LOCAL, m_FileTimeLocal);
	DDX_Text(pDX, IDC_FILETIME_LOCAL_REF, m_LocalRelFimeTime);
	DDX_Text(pDX, IDC_YEAR, m_nYear);
	DDX_Text(pDX, IDC_MONTH, m_nMonth);
	DDX_Text(pDX, IDC_DAY, m_nDay);
	DDX_Text(pDX, IDC_HOUR, m_nHour);
	DDX_Text(pDX, IDC_MINUTE, m_nMin);
	DDX_Text(pDX, IDC_SECOND, m_nSec);
	DDX_Text(pDX, IDC_MILLISECOND, m_nMilliSec);
	DDX_Text(pDX, IDC_FILETIME_RAW_LO, m_dwFileTimeRawLO);
	DDX_Text(pDX, IDC_FILETIME_RAW_HI, m_dwFileTimeRawHI);
}

BEGIN_MESSAGE_MAP(CTimeConvTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_GO_UT, OnBnClickedGoUt)
	ON_BN_CLICKED(IDC_GO_UT_UTC, OnBnClickedGoUtUtc)
	ON_BN_CLICKED(IDC_GO_ST, OnBnClickedGoSt)
	ON_BN_CLICKED(IDC_GO_FT, OnBnClickedGoFt)
	ON_BN_CLICKED(IDC_GO_DT, OnBnClickedGoDt)
	ON_BN_CLICKED(IDC_GETSYSTEMTIME, OnBnClickedGetsystemtime)
	ON_BN_CLICKED(IDC_GETLOCALTIME, OnBnClickedGetlocaltime)
	ON_BN_CLICKED(IDC_GO_FT_RAW, OnBnClickedGoFtRaw)
	ON_BN_CLICKED(IDC_GO_FT_LOCAL, OnBnClickedGoFtLocal)
	ON_BN_CLICKED(IDC_GETTIMET, OnBnClickedGettimet)
	ON_BN_CLICKED(IDC_GO_FT_LOCAL_REF, OnBnClickedGoFtLocalRef)
	ON_BN_CLICKED(IDC_CLEAR, OnBnClickedClear)
	ON_BN_CLICKED(IDC_GO_DT2, OnBnClickedGoDt2)
	
	ON_BN_CLICKED(IDC_GO_FT_RAW_LOHI, OnBnClickedGoFtRawLohi)
END_MESSAGE_MAP()


// CDateTimeTestDlg message handlers

BOOL CTimeConvTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTimeConvTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTimeConvTestDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTimeConvTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTimeConvTestDlg::OnBnClickedGoSt()
{
	UpdateData(TRUE);
	if( m_nYear > 0 )
	{
		SYSTEMTIME st;
		ZeroMemory( &st , sizeof(SYSTEMTIME) );
		st.wYear = m_nYear;
		st.wMonth = m_nMonth;
		st.wDay = m_nDay;
		st.wHour = m_nHour;
		st.wMinute = m_nMin;
		st.wSecond = m_nSec;
		st.wMilliseconds = m_nMilliSec;

		CZTimeConv::ToTime_t( &m_dwUnixTime_UTC , &st );
		m_dwUnixTime = (DWORD)CZTimeConv::Time_tToLocalTime_t( (const time_t)m_dwUnixTime_UTC );

		CZTimeConv::ToDosDateTime( &m_dwDosDateTime, &st );

		WORD date,time;

		if( CZTimeConv::ToDosDateTime( &date, &time, &st ) )
		{
			m_dwDosDate = date;
			m_dwDosTime = time;
		}

		CZTimeConv::ToFileTime( &m_FileTime , &st );
		CZTimeConv::ToLocalFileTime( &m_FileTimeLocal , &st );
		CZTimeConv::ToLocalRelFileTime( &m_LocalRelFimeTime , &m_FileTime );
		SetRawFileTime( m_FileTime );

		UpdateData(FALSE);

	}
}

void CTimeConvTestDlg::OnBnClickedGoFt()
{
	UpdateData(TRUE);
	if( m_FileTime.dwLowDateTime > 0 )
	{
		UpdateResult( m_FileTime );
	}
}

void CTimeConvTestDlg::SetRawFileTime( FILETIME& ft )
{
	ULARGE_INTEGER li;
	li.HighPart = ft.dwHighDateTime;
	li.LowPart = ft.dwLowDateTime;
	m_FileTimeRaw =  li.QuadPart;
	m_dwFileTimeRawLO = ft.dwLowDateTime;
	m_dwFileTimeRawHI = ft.dwHighDateTime;
}

void CTimeConvTestDlg::UpdateResult( FILETIME& ft )
{
	CZTimeConv::ToTime_t( &m_dwUnixTime_UTC , &ft);
	m_dwUnixTime = (DWORD)CZTimeConv::Time_tToLocalTime_t( (const time_t)m_dwUnixTime_UTC );

	CZTimeConv::ToDosDateTime( &m_dwDosDateTime , &ft );
	WORD dosDate=0,dosTime=0;
	CZTimeConv::DosTimeDWORD2WORD(&dosDate , &dosTime , m_dwDosDateTime );
	m_dwDosDate = dosDate;
	m_dwDosTime = dosTime;

	SetRawFileTime( ft );

	m_FileTime = ft;
	CZTimeConv::ToLocalFileTime( &m_FileTimeLocal , &m_FileTime );
	CZTimeConv::ToLocalRelFileTime( &m_LocalRelFimeTime , &m_FileTime );
	SetRawFileTime( m_FileTime );

	SYSTEMTIME st;
	CZTimeConv::ToSystemTime( &st , &ft );
	UpdateSystemTime( &st );

	UpdateData( FALSE );
}

void CTimeConvTestDlg::OnBnClickedGoFtLocal()
{
	UpdateData(TRUE);
	if( m_FileTimeLocal.dwLowDateTime > 0 )
	{
		FILETIME ft;
		LocalFileTimeToFileTime( &m_FileTimeLocal , &ft );
		UpdateResult( ft );

	}
}
void CTimeConvTestDlg::OnBnClickedGoFtLocalRef()
{
	UpdateData(TRUE);
	if( m_LocalRelFimeTime.dwLowDateTime > 0  )
	{
		FILETIME ft;
		if( !CZTimeConv::ToLocalRelFileTime( &ft , &m_LocalRelFimeTime ) )
			return;
		UpdateResult( ft );
	}
}

void CTimeConvTestDlg::OnBnClickedGoFtRaw()
{
	UpdateData(TRUE);
	if( m_FileTimeRaw > 0 )
	{
		FILETIME ft;
		ULARGE_INTEGER li;
		li.QuadPart = m_FileTimeRaw;
		ft.dwHighDateTime = li.HighPart;
		ft.dwLowDateTime = li.LowPart;
		UpdateResult(ft);
	}
}

void CTimeConvTestDlg::OnBnClickedGoDt()
{
	UpdateData(TRUE);
	if( m_dwDosDateTime > 0 )
	{
		UpdateResultDosDate( m_dwDosDateTime );
	}
}

void CTimeConvTestDlg::UpdateResultDosDate( DWORD dwDosDateTime )
{
	WORD dosDate=0,dosTime=0;
	CZTimeConv::DosTimeDWORD2WORD(&dosDate , &dosTime , dwDosDateTime );
	m_dwDosDate = dosDate;
	m_dwDosTime = dosTime;

	CZTimeConv::ToTime_t( &m_dwUnixTime_UTC , dwDosDateTime );
	m_dwUnixTime = (DWORD)CZTimeConv::Time_tToLocalTime_t( (time_t)m_dwUnixTime_UTC );

	CZTimeConv::ToFileTime( &m_FileTime ,dosDate , dosTime );
	CZTimeConv::ToLocalFileTime( &m_FileTimeLocal,&m_FileTime );
	CZTimeConv::ToLocalRelFileTime( &m_LocalRelFimeTime , &m_FileTime );
	SetRawFileTime( m_FileTime );

	SYSTEMTIME st;
	CZTimeConv::ToSystemTime( &st , dosDate , dosTime );
	UpdateSystemTime( &st );

	UpdateData( FALSE );
}

void CTimeConvTestDlg::OnBnClickedGoUt()
{
	UpdateData(TRUE);
	if( m_dwUnixTime > 0 )
	{
		m_dwUnixTime_UTC = (DWORD)CZTimeConv::LocalTime_tToUTCTime_t( (time_t)m_dwUnixTime );
		UpdateResult( (time_t)m_dwUnixTime_UTC );
	}
}
void CTimeConvTestDlg::OnBnClickedGoUtUtc()
{
	UpdateData(TRUE);
	if( m_dwUnixTime_UTC > 0 )
	{
		m_dwUnixTime = (DWORD)CZTimeConv::Time_tToLocalTime_t( (time_t)m_dwUnixTime_UTC );
		UpdateResult( (time_t)m_dwUnixTime_UTC );
	}
}

void CTimeConvTestDlg::UpdateResult( time_t t )
{
	CZTimeConv::ToDosDateTime( &m_dwDosDateTime, t);
	WORD dosDate=0,dosTime=0;
	CZTimeConv::DosTimeDWORD2WORD(&dosDate , &dosTime , m_dwDosDateTime );
	m_dwDosDate  = dosDate;
	m_dwDosTime  = dosTime;

	CZTimeConv::ToFileTime( &m_FileTime , t );
	CZTimeConv::ToLocalFileTime( &m_FileTimeLocal , &m_FileTime );
	CZTimeConv::ToLocalRelFileTime( &m_LocalRelFimeTime , &m_FileTime );
	SetRawFileTime( m_FileTime );
	
	SYSTEMTIME st;
	CZTimeConv::ToSystemTime( &st , t );
	UpdateSystemTime( &st );

	UpdateData(FALSE);
}

void CTimeConvTestDlg::UpdateSystemTime( SYSTEMTIME* st )
{
	m_nYear = st->wYear;
	m_nMonth = st->wMonth;
	m_nDay = st->wDay;
	m_nHour = st->wHour;
	m_nMin = st->wMinute;
	m_nSec = st->wSecond;
	m_nMilliSec = st->wMilliseconds;
}

void CTimeConvTestDlg::OnBnClickedGetsystemtime()
{
	SYSTEMTIME st;
	FILETIME ft;
	GetSystemTime( &st );
	SystemTimeToFileTime( &st , &ft );

	m_FileTime = ft;
	UpdateData( FALSE );
	OnBnClickedGoFt();
}


void CTimeConvTestDlg::OnBnClickedGetlocaltime()
{
	SYSTEMTIME st;
	FILETIME ftlocal;
	GetLocalTime( &st );
	SystemTimeToFileTime( &st , &ftlocal );

	m_FileTimeLocal = ftlocal;
	UpdateData( FALSE );
	OnBnClickedGoFtLocal();
}



void CTimeConvTestDlg::OnBnClickedGettimet()
{
	time_t t = time(NULL);
	m_dwUnixTime = (DWORD)t;
	UpdateData(FALSE);
	OnBnClickedGoUt();
}


void CTimeConvTestDlg::OnBnClickedClear()
{
	m_dwUnixTime = 0;
	m_dwUnixTime_UTC = 0;
	m_dwDosDateTime = 0;
	m_dwDosDate = 0;
	m_dwDosTime = 0;
	m_FileTime.dwLowDateTime = 0;
	m_FileTime.dwHighDateTime = 0;
	m_FileTimeLocal.dwLowDateTime = 0;
	m_FileTimeLocal.dwHighDateTime = 0;
	m_LocalRelFimeTime.dwLowDateTime = 0;
	m_LocalRelFimeTime.dwHighDateTime = 0;
	m_FileTimeRaw = 0;
	m_nYear = 0;
	m_nMonth = 0;
	m_nDay = 0;
	m_nHour = 0;
	m_nMin = 0;
	m_nSec = 0;
	m_nMilliSec = 0;
	UpdateData(FALSE);

}

void CTimeConvTestDlg::OnBnClickedGoDt2()
{
	UpdateData(TRUE);
	if( m_dwDosDate > 0 && m_dwDosTime > 0 )
	{
		DWORD dosDateTime = 0;
		CZTimeConv::DosTimeWORD2DWORD( &dosDateTime , (WORD)m_dwDosDate , (WORD)m_dwDosTime );
		if( dosDateTime > 0 )
			UpdateResultDosDate( dosDateTime );
	}
}



void CTimeConvTestDlg::OnBnClickedGoFtRawLohi()
{
	UpdateData(TRUE);
	FILETIME ft;
	ft.dwLowDateTime = m_dwFileTimeRawLO;
	ft.dwHighDateTime = m_dwFileTimeRawHI;
	SetRawFileTime( ft );
	UpdateData(FALSE);

	OnBnClickedGoFtRaw();
}
