// candy_margin.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "cv.h"
#include "cxcore.h"
#include "highgui.h" 

int _tmain(int argc, _TCHAR* argv[])
{
	  //����IplImageָ��
         IplImage* pImg = NULL; 
	    IplImage* pCannyImg = NULL; 
	    //����ͼ��ǿ��ת��ΪGray
		pImg = cvLoadImage( "1.bmp", 0); 
		//Ϊcanny��Եͼ������ռ�
		pCannyImg = cvCreateImage(cvGetSize(pImg), IPL_DEPTH_8U, 1);
		//canny��Ե���
		cvCanny(pImg, pCannyImg, 50, 150, 3); 
		//��������
		cvNamedWindow("src", 1);
		cvNamedWindow("canny",1);
		//��ʾͼ��
		cvShowImage( "src", pImg ); 
		cvShowImage( "canny", pCannyImg ); 
		//�ȴ�����
		cvWaitKey(0);
		//���ٴ���
		cvDestroyWindow( "src" ); 
		cvDestroyWindow( "canny" );
		//�ͷ�ͼ��
		cvReleaseImage( &pImg ); 
		cvReleaseImage( &pCannyImg );
		return 0;
}

