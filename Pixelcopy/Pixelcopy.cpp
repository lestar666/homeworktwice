#include <iostream>
#include <opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("D:\\testImage\\1.jpg");
	cv::Mat shallowMat;
	cv::Mat deepMat;

	shallowMat = srcMat;
	srcMat.copyTo(deepMat);

	int height = srcMat.rows;//行数为高
	int width = srcMat.cols;//列数为宽

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			uchar threshold = 100;
			uchar average = (srcMat.at<Vec3b>(j, i)[0] +
				srcMat.at<Vec3b>(j, i)[1] +
				srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold)
				average = 255;
			else
				average = 0;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
		}
	}

	imshow("src", srcMat);
	imshow("shallow", shallowMat);
	imshow("deep", deepMat);

	waitKey(0);
	return 0;

}

