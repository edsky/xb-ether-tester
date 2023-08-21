/* 
 * 本软件为免费、开源软件。
 * 本软件的版权(包括源码及二进制发布版本)归一切公众所有。
 * 您可以自由使用、传播本软件。
 * 您也可以以任何形式、任何目的使用本软件(包括源码及二进制发布版本)，而不受任何版权限制。
 * =====================
 * 作者: 孙明保
 * 邮箱: sunmingbao@126.com
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


