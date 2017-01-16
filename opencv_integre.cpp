#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;  
using namespace std;

int main()  
{
	Mat srcImage = imread("F:\\nidalee.jpg");
	Mat logo = imread("F:\\logo.jpg");
	
	if (!srcImage.data)
	{
		cout << "failed to read srcImage.jpg" << endl;
		return 1;
	}
	
	if (!logo.data)
	{
		cout << "failed to read logo.jpg" << endl;
		return 1;
	}
	
	Mat imgROI = srcImage(Rect(30, 800, logo.cols, logo.rows));
	Mat mask = imread("F:\\logo.jpg", 0);
	logo.copyTo(imgROI, mask);

	namedWindow("yancy_window", WINDOW_NORMAL);
	imshow("yancy_window", srcImage);
	waitKey();
}
