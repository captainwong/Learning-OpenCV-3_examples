#include "stdafx.h"
#include "e9-5wtlView.h"
#include <atldlgs.h>

bool CE95wtlView::OpenFile(std::string file)
{
	if (!cap_.open(file)) { return false; }
	cap_.read(cv_imge_);
	bitmap_bits_ = new RGBTRIPLE[cv_imge_.cols * cv_imge_.rows];
	_copyImage();
	SetTimer(0, 1000.f / cap_.get(cv::CAP_PROP_FPS));
	return true;
}

void CE95wtlView::_copyImage()
{
	cv::Mat cv_header_to_rgbtriple(cv::Size(cv_imge_.cols, cv_imge_.rows), CV_8UC3, bitmap_bits_);
	cv::cvtColor(cv_imge_, cv_header_to_rgbtriple, cv::COLOR_BGR2RGB);
}

BOOL CE95wtlView::PreTranslateMessage(MSG * pMsg)
{
	return 0;
}

LRESULT CE95wtlView::OnEraseBkgrnd(UINT, WPARAM, LPARAM, BOOL &)
{
	return LRESULT(0);
}

LRESULT CE95wtlView::OnPaint(UINT, WPARAM, LPARAM, BOOL &)
{
	CPaintDC dc(m_hWnd);
	CRect rc;
	GetClientRect(rc);
	if (cap_.isOpened()) {
		BITMAPINFO bmi = { 0 };
		bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
		bmi.bmiHeader.biCompression = BI_RGB;
		bmi.bmiHeader.biWidth = cv_imge_.cols;
		// bitmaps default to bottom-up, use negative height to represent top-down
		bmi.bmiHeader.biHeight = -1 * cv_imge_.rows;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biBitCount = 24;
		dc.StretchDIBits(0, 0, rc.Width(), rc.Height(), 0, 0, bmi.bmiHeader.biWidth, abs(bmi.bmiHeader.biHeight), bitmap_bits_, &bmi, DIB_RGB_COLORS, SRCCOPY);
	} else {
		dc.FillRect(rc, COLOR_WINDOW);
	}
	return LRESULT();
}

LRESULT CE95wtlView::OnTimer(UINT, WPARAM, LPARAM, BOOL &)
{
	if (!cap_.isOpened()) {
		return 0;
	}

	cap_.read(cv_imge_);
	_copyImage();
	Invalidate();

	return LRESULT(0);
}
