// CefWin64.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CefWin64.h"



int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	XCefAppManagePtr mng = XCefAppManage::Instance();
	{
		// Manage����д�����ÿ�����̶������
		//XManifestUtil::Instance().EnableOffScreenRendering();

		// ע���¼�
		mng->RigisterCallback(new XWinCallback);
		{
			std::string strPath = XCefAppManage::GetModuleCurrentDirectory().ToString() + "..\\..\\resources\\JSHandle.html";
			XManifestUtil::Instance().LoadUrl(strPath.c_str());
		}
// 		XManifestUtil::Instance().LoadHtml(
//  			CefString("<script type='text/javascript'>alert('111');</script>")
//  			);
		XManifestUtil::Instance().SetWin32less();
		//XManifestUtil::Instance().Maximize();
	}
	int exit_code = mng->RunSingle(hInstance);
	if (exit_code >= 0)
		return exit_code;
	return NULL;
}
