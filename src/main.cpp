#include "opencv2/opencv.hpp"
#include <chrono>
#include "Stag.h"

#ifndef OS_WIN
int main() {
	cv::VideoCapture cap;
	cap.open(0);

	// Check if camera opened successfully
	if (!cap.isOpened()) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	} else {
		cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
		cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	}

	Stag stag(11, 7, true);
	std::chrono::time_point<std::chrono::system_clock> start,end;

	while (true) {
		cv::Mat rgb_image, gray_image;
		cap >> rgb_image;
		if (rgb_image.empty()) {
			break;
		}
		cv::cvtColor(rgb_image, gray_image, CV_BGR2GRAY);
		start = std::chrono::system_clock::now();
		stag.detectMarkers(gray_image);
		stag.drawResults(rgb_image);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed = end-start;
		std::cout << "That took " << elapsed.count() << " s\n";
		cv::imshow("Image", rgb_image);

		char c = (char) cvWaitKey(25);
		if (c == 27) {
			break;
		}
	}
	cap.release();
	cv::destroyAllWindows();
	return 0;
}
#else
void main()
{
	cv::Mat image = cv::imread("1.png", CV_LOAD_IMAGE_GRAYSCALE);

	Stag stag(15, 7, true);

	stag.detectMarkers(image);
	stag.logResults("log/");
}
#endif