# ZTimeConv
Windows C++ class for converting between different timeformats

# Usage

```cpp
#include "ZTimeConv.h"

// time_t to FileTime
FileTime fileTime;
time_t timeT;
time(&timeT);

CZTimeConv::ToFileTime( &fileTime , &timeT );
```

# Conversions
```cpp
  static BOOL ToSystemTime( SYSTEMTIME* pSystemTime , const FILETIME* pFileTime )
  static BOOL ToSystemTime( SYSTEMTIME* pSystemTime , const __time32_t dwTime_t )
  static BOOL ToSystemTime( SYSTEMTIME* pSystemTime , const __time64_t dwTime_t )
  static BOOL ToSystemTime( SYSTEMTIME* pSystemTime , const double variantTime )
  static BOOL ToSystemTime( SYSTEMTIME* pSystemTime , const WORD dosDate , const WORD dosTime )

  static BOOL ToLocalFileTime( FILETIME* pLocalFileTime , const FILETIME* pFileTime )
  static BOOL ToLocalFileTime( FILETIME* pLocalFileTime , const SYSTEMTIME* st )
  static BOOL ToLocalRelFileTime( FILETIME* pLocalFileTime , const FILETIME* pFileTime )
  static BOOL FromFileTimeLocal( FILETIME* pFileTime  ,const FILETIME* pLocalFileTime  )
  static BOOL FromFileTimeLocalRel( FILETIME* pFileTime  ,const FILETIME* pLocalFileTime  )
  static BOOL ToFileTime( FILETIME* pFileTime , const SYSTEMTIME* pSystemTime )
  static BOOL ToFileTime( FILETIME* pFileTime , const __time32_t Time_t )
  static BOOL ToFileTime( FILETIME* pFileTime , const __time64_t Time_t )
  static BOOL ToFileTime( FILETIME* pFileTime , const double variantTime )
  static BOOL ToFileTime( FILETIME* pFileTime , const WORD dosDate , const WORD dosTime )
  static __int64  FileTimeToINT64(FILETIME* ft)
  static void INT64ToFileTime(FILETIME* ft , __int64 nValue)

  static BOOL ToDosDateTime( DWORD* pDateTime , const __time32_t dwTime_t )
  static BOOL ToDosDateTime( WORD* pDate , WORD* pTime , const FILETIME* pFileTime )
  static BOOL ToDosDateTime( DWORD* pDosDateTime , const SYSTEMTIME* st )
  static BOOL ToDosDateTime( WORD* pDate , WORD* pTime , const SYSTEMTIME* st )
  static void DosTimeDWORD2WORD( WORD* pDate , WORD* pTime , DWORD dosDateTime )
  static void DosTimeWORD2DWORD( DWORD* pDosDateTime , WORD Date , WORD Time )
  static BOOL ToDosDateTime( DWORD* pDateTime , const FILETIME* pFileTime )

  static BOOL ToTime_t( __time32_t* pdwTime_t , const FILETIME* pFileTime )
  static BOOL ToTime_t( __time64_t* pdwTime_t , const FILETIME* pFileTime )
  static BOOL ToTime_t( __time32_t* pdwTime_t , const SYSTEMTIME* pSystemTime )
  static BOOL ToTime_t( __time64_t* pdwTime_t , const SYSTEMTIME* pSystemTime )
  static BOOL ToTime_t( __time32_t* pdwTime_t , const double variantTime )
  static BOOL ToTime_t( __time32_t* pdwTime_t , const DWORD dosDateTime )
  static BOOL ToTime_t( __time32_t* pdwTime_t , const WORD dosDate , const WORD dosTime )
  static BOOL ToTime_t( __time64_t* pdwTime_t , const DWORD dosDateTime )
  static BOOL ToTime_t( __time64_t* pdwTime_t , const WORD dosDate , const WORD dosTime )

  static __time32_t Time_tToLocalTime_t( const __time32_t Time_t )
  static __time64_t Time_tToLocalTime_t( const __time64_t Time_t )
  static __time32_t Time_tToLocalRelTime_t( const __time32_t Time_t )
  static __time64_t Time_tToLocalRelTime_t( const __time64_t Time_t )
  static __time32_t LocalTime_tToUTCTime_t( const __time32_t Time_t )
  static __time64_t LocalTime_tToUTCTime_t( const __time64_t Time_t )
```
# History 

v1.3 - 2019-11-05 
First public version

v1.3 - 2008-06-18
Lastest version
