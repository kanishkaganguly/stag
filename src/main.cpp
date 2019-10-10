#include "opencv2/opencv.hpp"
#include "Stag.h"

#ifndef OS_WIN
int main(){
	cv::Mat image = cv::imread("../markers/11_223.png", CV_LOAD_IMAGE_GRAYSCALE);

	Stag stag(11, 7, true);

	stag.detectMarkers(image);
	stag.logResults("../log/");
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