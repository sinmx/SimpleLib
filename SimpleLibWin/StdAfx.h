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

// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

#include <malloc.h>

#include "..\SimpleLib.h"
using namespace Simple;

#define WIN32_LEAN_AND_MEAN

#ifndef _WIN32_WINNT
#define _WIN32_WINNT	0x0501
#endif

#include <windows.h>
#include <commctrl.h>
#include <shlwapi.h>

#include <objidl.h>				
#include <oleauto.h>
#include <ocidl.h>

/*
#include <atlbase.h>
#define _Module (*_pModule)
#include <atlcom.h>
#include <atlwin.h>

#include "AtlControls.h"
*/
