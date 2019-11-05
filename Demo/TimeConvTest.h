#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CTimeConvTestApp:
// See DateTimeTest.cpp for the implementation of this class
//

class CTimeConvTestApp : public CWinApp
{
public:
	CTimeConvTestApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTimeConvTestApp theApp;