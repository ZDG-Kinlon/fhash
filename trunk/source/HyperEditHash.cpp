// src\HyperEditHash.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "HyperEditHash.h"
#include "Global.h"

// CHyperEditHash

IMPLEMENT_DYNAMIC(CHyperEditHash, CHyperEditHash_BASE_CLASS)

CHyperEditHash::CHyperEditHash()
{
	InitializeCriticalSection(&m_csLinkOffsets);

	ClearTextBuffer();

	COLORREF crBlack = RGB(0, 0, 0);
	SetHyperlinkColors(crBlack, crBlack);
}

CHyperEditHash::~CHyperEditHash()
{
	DeleteCriticalSection(&m_csLinkOffsets);
}


BEGIN_MESSAGE_MAP(CHyperEditHash, CHyperEditHash_BASE_CLASS)
END_MESSAGE_MAP()



// CHyperEditHash ��Ϣ�������
BOOL CHyperEditHash::PreTranslateMessage(MSG* pMsg)
{  
    // �༭���ݼ�����  
    if(WM_KEYDOWN == pMsg->message)   
    {
		if(::GetFocus() == GetSafeHwnd() && (GetKeyState( VK_CONTROL) & 0xFF00 ) == 0xFF00)   
        {
            // ȫѡ
            if( pMsg->wParam == 'A' || pMsg->wParam == 'a')  
            {
                this->SetSel(0, -1);
                return true;
            }

            // ����
            if( pMsg->wParam == 'C' || pMsg->wParam == 'c')  
            {
                this->Copy();
                return true;
			}

            // ����
            if( pMsg->wParam == 'X' || pMsg->wParam == 'x')  
            {
                this->Cut();
                return true;
			}

            // ճ��
            if( pMsg->wParam == 'V' || pMsg->wParam == 'v')  
            {
                this->Paste();
                return true;
            }

            // ����
            if( pMsg->wParam == 'Z' || pMsg->wParam == 'z')  
            {
                this->Undo();
                return true;
            }

        }  
    }  

    return CHyperEditHash_BASE_CLASS::PreTranslateMessage(pMsg);  
}

void CHyperEditHash::ClearTextBuffer()
{
	EnterCriticalSection(&m_csLinkOffsets);
	m_bufferLinkOffsets.clear();
	LeaveCriticalSection(&m_csLinkOffsets);
	m_cstrTextBuffer = CString(_T(""));
}

CString CHyperEditHash::GetTextBuffer() const
{
	return m_cstrTextBuffer;
}

void CHyperEditHash::ShowTextBuffer()
{
	EnterCriticalSection(&m_csLinkOffsets);
	m_linkOffsets = m_bufferLinkOffsets;
	LeaveCriticalSection(&m_csLinkOffsets);
	SetWindowText(m_cstrTextBuffer);
}

void CHyperEditHash::AppendTextToBuffer(LPCTSTR pszText)
{
	m_cstrTextBuffer.Append(pszText);
}

void CHyperEditHash::AppendLinkToBuffer(LPCTSTR pszText)
{
	int startPos = m_cstrTextBuffer.GetLength();
	AppendTextToBuffer(pszText);
	INT endPos = m_cstrTextBuffer.GetLength();
	INT linkLength = endPos - startPos;
	_TOKEN_OFFSET off = { startPos /* Start offset */, linkLength /* Length */ };
	EnterCriticalSection(&m_csLinkOffsets);
	m_bufferLinkOffsets.push_back(off);
	LeaveCriticalSection(&m_csLinkOffsets);
}

void CHyperEditHash::CopyLinkOffsets(OFFSETS& linkOffsets)
{
	EnterCriticalSection(&m_csLinkOffsets);
	linkOffsets = m_bufferLinkOffsets;
	LeaveCriticalSection(&m_csLinkOffsets);
}

void CHyperEditHash::SetLinkOffsets(const OFFSETS& linkOffsets)
{
	EnterCriticalSection(&m_csLinkOffsets);
	m_bufferLinkOffsets = linkOffsets;
	LeaveCriticalSection(&m_csLinkOffsets);
}

void CHyperEditHash::BuildOffsetList(int iCharStart, int iCharFinish)
{
	// We do nothing in CHyperEditHash::BuildOffsetList.
	// m_linkOffsets is already built in AppendLinkToBuffer.
}

HINSTANCE CHyperEditHash::OpenHyperlink(const CString& hyperlink, CPoint point)
{
	if (hyperlink.IsEmpty())
		return 0;

	ClientToScreen(&point);

	m_cstrLastHyperlink = hyperlink;
	m_cpLastScreenPoint = point;
	
	CWnd *parentWnd = GetParent();
	if (parentWnd != NULL)
	{
		::PostMessage(parentWnd->GetSafeHwnd(), WM_CUSTOM_MSG, WM_HYPEREDIT_MENU, 0);
	}

	return 0;
}

