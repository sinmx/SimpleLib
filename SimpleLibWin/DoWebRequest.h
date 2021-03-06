//////////////////////////////////////////////////////////////////////
//
// SimpleLib Win Version 1.0
//
// Copyright (C) 1998-2007 Topten Software.  All Rights Reserved
// http://www.toptensoftware.com
//
// This code has been released for use "as is".  Any redistribution or 
// modification however is strictly prohibited.   See the readme.txt file 
// for complete terms and conditions.
//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// DoWebRequest.h - declaration of DoWebRequest

#ifndef __DOWEBREQUEST_H
#define __DOWEBREQUEST_H


namespace Simple
{

CUniString SIMPLEAPI UrlEncode(const wchar_t* p);
bool SIMPLEAPI DoWebRequest(const wchar_t* pszUrl, CUniString& str);
bool SIMPLEAPI DoWebPost(const wchar_t* pszUrl, const wchar_t* pszFormData, CUniString& str);

}	// namespace Simple

#endif	// __DOWEBREQUEST_H

