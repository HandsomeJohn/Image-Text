// Stitching.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*#include <stdio.h>
#include <iostream>
#include<fstream>
#include "cv.h"
#include "highgui.h"
#include "stitching/stitcher.hpp"  //stitching Ӱ��ƴ��
using namespace std;
using namespace cv;*/
#include <iostream>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{ 
	 IplImage* img_1 = cvLoadImage("1.jpg");
     IplImage* img_2 = cvLoadImage("2.jpg");
  
   vector<Mat> imgs;
   
   imgs.push_back(img_1);
   imgs.push_back(img_2);
    //ƴ��

  Mat pano;
  //Stitcher stitcher = Stitcher::createDefault(false);
  Stitcher stitcher=Stitcher::createDefault(false);
  Stitcher::Status status = stitcher.stitch(imgs, pano);
  if (status != Stitcher::OK)
{
cout << "Can't stitch images, error code = " << status << endl;
return -1;
}

imwrite("stitching image.jpg", pano);
 imshow("ƴ��",pano);
  waitKey(0);
	
	return 0;
}

