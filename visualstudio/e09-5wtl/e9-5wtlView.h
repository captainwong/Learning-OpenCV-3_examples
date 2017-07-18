// e9-5wtlView.h : interface of the CE95wtlView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
class CE95wtlView : public CWindowImpl<CE95wtlView>
{
public:
	DECLARE_WND_CLASS(NULL)

	bool OpenFile(std::string file);
	void _copyImage();

	BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP(CE95wtlView)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgrnd)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MESSAGE_HANDLER(WM_TIMER, OnTimer);
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnEraseBkgrnd(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

private:
	cv::VideoCapture cap_;
	cv::Mat cv_imge_;
	RGBTRIPLE* bitmap_bits_;
};
