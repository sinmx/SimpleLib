//////////////////////////////////////////////////////////////////////
//
// SimpleLib ATL Win Version 1.0
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
// FrameWindow.h - declaration of CBarFrameWindow class

#ifndef __FRAMEWINDOW_H
#define __FRAMEWINDOW_H

#ifdef __ATLWIN_H__


namespace Simple
{

// Simple frame window implementation. Provides:
//		- Docked bars and panels
//		- Full screen mode
//		- Frame position persistence
//		- Bar persistence
//		- Icon loading


#define BARFLAG_TOP			ASF_TOP
#define BARFLAG_BOTTOM		ASF_BOTTOM
#define BARFLAG_LEFT		ASF_LEFT
#define BARFLAG_RIGHT		ASF_RIGHT
#define BARFLAG_SAVESIZE	0x00010000
#define BARFLAG_SAVEVISIBLE	0x00020000


#define WM_BAR_FIRST			(WM_USER + 1024)
#define WM_BAR_LAST				(WM_USER + 1048)

#define WM_BAR_GETPLACEMENT		(WM_BAR_FIRST + 0)		// lParam=hWndBar, returns BARFLAG
#define WM_BAR_SETPLACEMENT		(WM_BAR_FIRST + 1)		// lParam=hWndBar, wParam=placement
#define WM_BAR_RESIZEBAR		(WM_BAR_FIRST + 2)		// lParam=hWndBar, wParam=newsize
#define WM_BAR_RECALCLAYOUT		(WM_BAR_FIRST + 3)		// all params unused 


class CBarFrameWindowImpl
{
public:
// Construction
			CBarFrameWindowImpl(HWND& hWndFrame);
	virtual ~CBarFrameWindowImpl();

	LRESULT OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

// Bar arrangement
	void AddBar(HWND hWndBar, int iSize, DWORD dwPlacement, bool bUpdate=false, HWND hWndAfter=NULL);
	void RemoveBar(HWND hWndBar, bool bUpdate=true);
	void ResizeBar(HWND hWndBar, int iNewSize, bool bUpdate=true);
	void RecalcLayout();
	void SetLayoutMargins(RECT rc);

// Bar persistence
	void EnableBarPersistence(HWND hWndBar, const wchar_t* pszName, DWORD dwFlags);
	void SaveBarState(const wchar_t* pszSection=NULL);
	void LoadBarState(const wchar_t* pszSection=NULL, bool bRecalcLayout=true);

// Placement persistence
	void SavePlacement(const wchar_t* pszSection=L"Window", const wchar_t* pszPrefix=L"MainFrame");
	int LoadPlacement(const wchar_t* pszSection=L"Window", const wchar_t* pszPrefix=L"MainFrame");

// Full screen
	bool GetFullScreen();
	void SetFullScreen(bool bFullScreen, const wchar_t* pszNormalState=NULL, const wchar_t* pszFullScreenState=NULL);

// Implementation
protected:
// CBarEntry
	class CBarEntry
	{
	public:
		CBarEntry(HWND hWnd, int iSize, DWORD dwPlacement) :	
			m_hWnd(hWnd),
			m_iSize(iSize),
			m_dwFlags(dwPlacement),
			m_bNonFullScreenVisible(true)
		{
		}

		bool IsBar() { return (m_dwFlags & (BARFLAG_LEFT|BARFLAG_TOP|BARFLAG_RIGHT|BARFLAG_BOTTOM))!=0; }

		HWND		m_hWnd;
		int			m_iSize;
		DWORD		m_dwFlags;
		bool		m_bNonFullScreenVisible;
		CUniString	m_strPersistName;
	};


// Attributes
	HWND&				m_hWndFrame;
	CVector<CBarEntry*, SOwnedPtr>	m_Bars;
	bool				m_bFullScreen;
	WINDOWPLACEMENT		m_NonFullScreenWindowPlacement;
	RECT				m_rcMargins;

	int FindBarEntry(HWND hWnd);
};

template <class TBase>
class CBarFrameWindow : 
	public TBase,
	public CBarFrameWindowImpl
{
public:
	typedef CBarFrameWindow<TBase>	_CBarFrameWindow;

	CBarFrameWindow() : CBarFrameWindowImpl(TBase::m_hWnd)
	{
	}
	virtual ~CBarFrameWindow()
	{
	}

	void LoadIcon(UINT nResID)
	{
		m_hIconSmall=LoadIconEx(nResID, false);
		m_hIconLarge=LoadIconEx(nResID, true);
		TBase::SetIcon(m_hIconSmall, false);
		TBase::SetIcon(m_hIconLarge, true);
	}


	// Message map
	BEGIN_MSG_MAP(CBarFrameWindow)
		MESSAGE_RANGE_HANDLER(WM_BAR_FIRST, WM_BAR_LAST, CBarFrameWindowImpl::OnMessage)
	END_MSG_MAP()

	CSmartHandle<HICON>	m_hIconLarge;
	CSmartHandle<HICON>	m_hIconSmall;
};


}	// namespace Simple

#endif	// __ATLWIN_H__

#endif	// __FRAMEWINDOW_H

