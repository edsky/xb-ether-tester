/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef __DEBUG_H_
#define __DEBUG_H_

#include <tchar.h>

#define WIDEN2(x) L ## x
#define WIDEN(x) WIDEN2(x)
#define __WFILE__ WIDEN(__FILE__)

void __dbg_print(const TCHAR * szFormat, ...);
void __dbg_print_w(const WCHAR * szFormat, ...);

// For narrow character debug printing
#define dbg_print(fmt, ...) \
    do \
    { \
        __dbg_print(_T("DBG:%s(%d)-%s:\n") _T(fmt) _T("\n"), __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); \
    } while (0)

// For wide character debug printing
#define dbg_print_w(fmt, ...) \
    do \
    { \
        __dbg_print_w(L"DBG:%ls(%d)-%ls:\n" L##fmt L"\n", __FILEW__, __LINE__, __FUNCTIONW__, __VA_ARGS__); \
    } while (0)

#endif


