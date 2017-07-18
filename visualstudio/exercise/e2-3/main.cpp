#pragma warning(push)
#pragma warning(disable:4819)
#include <opencv2/opencv.hpp>
#pragma warning(pop)

void help(char* argv[])
{
	std::cout << "\n"
		<< "e2: Using cv::pyrDown() to create a new image and save to video file, the image is half the width and"
		<< "      height of the input image that captured from camera 0\n"
		<< argv[0] << " <path/video>\n"
		<< "For example:\n"
		<< argv[0] << " e2-6-out.avi\n"
		<< std::endl;
}

bool g_pos_changed = false;
int g_pos = 0;

void on_trackbar(int pos, void* = nullptr)
{
	//g_pos = (pos + 1) * 2;
	g_pos_changed = true;
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		help(argv);
		return 0;
	}

	cv::VideoCapture capture(0);
	if (!capture.isOpened()) {
		std::cout << "Could not open camera 0" << std::endl;
		return 0;
	}

	double fps = capture.get(CV_CAP_PROP_FPS);
	if (fps == 0.0) {
		fps = 30;
	}

	cv::Mat bgr_frame, dsample;

	capture >> bgr_frame;
	cv::pyrDown(bgr_frame, dsample);

	cv::Size size(
		dsample.cols,
		dsample.rows
	);

	/*cv::VideoWriter writer;
	writer.open(argv[1], CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
	if (!writer.isOpened()) {
		std::cout << "Could not open file " << argv[1] << " to save video" << std::endl;
		return 0;
	}	*/

	cv::namedWindow("Exercise 2");
	cv::createTrackbar("reduction level", "Exercise 2", &g_pos, 2, on_trackbar);
	g_pos = 0;

	for (;;) {

		capture >> bgr_frame;
		if (bgr_frame.empty()) break; // end if done

		cv::imshow("Exercise 2", bgr_frame);

		/*if (g_pos_changed) {
			writer.release();
		}*/

		cv::Mat dst = {};
		cv::pyrDown(bgr_frame, dst);
		int pos = g_pos;
		while (pos) {
			cv::Mat tmp;
			cv::pyrDown(dst, tmp, cv::Size(dst.cols / 2, dst.rows / 2));
			dst = tmp;
			pos--;
		} 

		cv::imshow("Downsample - " + std::to_string(static_cast<int>(std::pow(2, (g_pos + 1)))), dst);

		/*if (!g_pos_changed) {
			writer << down_sample;
		}*/

		char c = cv::waitKey(1000.0 / fps);

		if (c == 27) break; // allow the user to break out

	}

	//writer.release();
	capture.release();
}
