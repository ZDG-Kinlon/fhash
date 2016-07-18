#include "stdafx.h"

#include "UIStringsZHCN.h"

#include <tchar.h>

UIStringsZHCN::UIStringsZHCN()
{
	// Global Strings
	m_stringsMap[_T("FILE_STRING")] = _T("�ļ�");
	m_stringsMap[_T("BYTE_STRING")] = _T("�ֽ�");
	m_stringsMap[_T("HASHVALUE_STRING")] = _T("Hash ֵ:");
	m_stringsMap[_T("FILENAME_STRING")] = _T("�ļ���:");
	m_stringsMap[_T("FILESIZE_STRING")] = _T("�ļ���С:");
	m_stringsMap[_T("MODIFYTIME_STRING")] = _T("�޸�����:");
	m_stringsMap[_T("VERSION_STRING")] = _T("�汾:");
	m_stringsMap[_T("SECOND_STRING")] = _T("��");
	m_stringsMap[_T("BUTTON_OK")] = _T("ȷ��");
	m_stringsMap[_T("BUTTON_CANCEL")] = _T("ȡ��");

	// Main Dialog Strings
	m_stringsMap[_T("MAINDLG_INITINFO")] = _T("���ļ���������򿪣���ʼ���㡣");
	m_stringsMap[_T("MAINDLG_WAITING_START")] = _T("׼����ʼ���㡣");
	m_stringsMap[_T("MAINDLG_CONTEXT_INIT")] = _T("��Ҫ����ԱȨ��");
	m_stringsMap[_T("MAINDLG_ADD_SUCCEEDED")] = _T("��ӳɹ�");
	m_stringsMap[_T("MAINDLG_ADD_FAILED")] = _T("���ʧ��");
	m_stringsMap[_T("MAINDLG_REMOVE_SUCCEEDED")] = _T("�Ƴ��ɹ�");
	m_stringsMap[_T("MAINDLG_REMOVE_FAILED")] = _T("�Ƴ�ʧ��");
	m_stringsMap[_T("MAINDLG_REMOVE_CONTEXT_MENU")] = _T("�Ƴ��Ҽ��˵�");
	m_stringsMap[_T("MAINDLG_ADD_CONTEXT_MENU")] = _T("����Ҽ��˵�");
	m_stringsMap[_T("MAINDLG_CLEAR")] = _T("���(&R)");
	m_stringsMap[_T("MAINDLG_CLEAR_VERIFY")] = _T("�����֤(&R)");
	m_stringsMap[_T("MAINDLG_CALCU_TERMINAL")] = _T("������ֹ");
	m_stringsMap[_T("MAINDLG_FIND_IN_RESULT")] = _T("�ڽ��������");
	m_stringsMap[_T("MAINDLG_RESULT")] = _T("ƥ��Ľ��:");
	m_stringsMap[_T("MAINDLG_NORESULT")] = _T("��ƥ����");
	m_stringsMap[_T("MAINDLG_FILE_PROGRESS")] = _T("�ļ�����");
	m_stringsMap[_T("MAINDLG_TOTAL_PROGRESS")] = _T("�������");
	m_stringsMap[_T("MAINDLG_UPPER_HASH")] = _T("��д Hash");
	m_stringsMap[_T("MAINDLG_TIME_TITLE")] = _T("����ʱ��:");
	m_stringsMap[_T("MAINDLG_OPEN")] = _T("��(&O)...");
	m_stringsMap[_T("MAINDLG_STOP")] = _T("ֹͣ(&S)");
	m_stringsMap[_T("MAINDLG_COPY")] = _T("ȫ������(&C)");
	m_stringsMap[_T("MAINDLG_VERIFY")] = _T("��֤(&V)");
	m_stringsMap[_T("MAINDLG_ABOUT")] = _T("����(&A)");
	m_stringsMap[_T("MAINDLG_EXIT")] = _T("�˳�(&X)");
	m_stringsMap[_T("MAINDLG_HYPEREDIT_MENU_COPY")] = _T("���ƹ�ϣֵ");
	m_stringsMap[_T("MAINDLG_HYPEREDIT_MENU_SERACHGOOGLE")] = _T("���� Google");
	m_stringsMap[_T("MAINDLG_HYPEREDIT_MENU_SERACHVIRUSTOTAL")] = _T("���� VirusTotal");

	// Find Dialog Strings
	m_stringsMap[_T("FINDDLG_TITLE")] = _T("��֤");

	// About Dialog Strings
	m_stringsMap[_T("ABOUTDLG_TITLE")] = _T("���� fHash");
	m_stringsMap[_T("ABOUTDLG_INFO_TITLE")] = _T("fHash: �ļ� Hash ������ ");
	m_stringsMap[_T("ABOUTDLG_INFO_RIGHT")] = _T("Copyright (C) 2007-2016 SUN Junwen.");
	m_stringsMap[_T("ABOUTDLG_INFO_MD5")] = _T("MD5 �㷨���� RSA Data Security, Inc.��д��Copyright (C) RSA Data Security, Inc.");
	m_stringsMap[_T("ABOUTDLG_INFO_SHA256")] = _T("SHA256 �㷨���� Niels Moller ��д��Copyright (C) Niels Moller");
	m_stringsMap[_T("ABOUTDLG_INFO_CRC32")] = _T("CRC32 �㷨���� Dominik Reichl ��д��Copyright (C) Dominik Reichl");
	m_stringsMap[_T("ABOUTDLG_INFO_RIGHTDETAIL")] = _T("��ϸ��Ȩ��Ϣ����������վ��");
	m_stringsMap[_T("ABOUTDLG_INFO_OSTITLE")] = _T("��ǰ����ϵͳ:");
	m_stringsMap[_T("ABOUTDLG_PROJECT_SITE")] = _T("<a>Hosted on GitHub</a>");
	m_stringsMap[_T("ABOUTDLG_PROJECT_URL")] = _T("https://github.com/sunjw/fhash");

}
