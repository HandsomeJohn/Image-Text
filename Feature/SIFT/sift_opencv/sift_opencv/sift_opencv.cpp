// sift_opencv.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "highgui.h"
#include<legacy/legacy.hpp>
#include <nonfree/features2d.hpp>
#include"iostream"
using namespace std;
using namespace cv;


int _tmain(int argc, _TCHAR* argv[])
{
	//SIFT���������
//Mat image=imread("beaver.png");
//Mat iamgeGray=imread("beaver.png",0);
/*Mat image=imread("test.jpg");
Mat iamgeGray=imread("test.jpg",0);

Mat descriptors;
vector<KeyPoint> keypoints;

SiftFeatureDetector sift2(0.06f,10.0);
sift2.detect(iamgeGray,keypoints);
//SurfFeatureDetector detector(40);
drawKeypoints(image,keypoints,image,Scalar(255,0,255));
//imshow("beaver.png",image);
imshow("test.jpg",image);
imwrite("result.jpg",image);

waitKey(0);*/

	//SIFT������ƥ��
Mat input1=imread("beaver.png",1);
Mat input2=imread("beaver_xform.png",1);
//Mat input1 = imread("aa.jpg");  
  //  Mat input2 = imread("cc.jpg");  
SiftFeatureDetector detector;
vector<KeyPoint> keypoint1,keypoint2;
detector.detect(input1,keypoint1);

Mat output1;
drawKeypoints(input1,keypoint1,output1);
imshow("sift_result1.jpg",output1);
imwrite("sift_result1.jpg",output1);

Mat output2;
SiftDescriptorExtractor extractor;
Mat descriptor1,descriptor2;
//Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create( "BruteForce" );//��������ƥ���� 
BruteForceMatcher<L2<float>> matcher;

vector<DMatch> matches;
Mat img_matches;
detector.detect(input2,keypoint2);
drawKeypoints(input2,keypoint2,output2);

imshow("sift_result2.jpg",output2);
imwrite("sift_result2.jpg",output2);

extractor.compute(input1,keypoint1,descriptor1);
extractor.compute(input2,keypoint2,descriptor2);

matcher.match(descriptor1,descriptor2,matches);

drawMatches(input1,keypoint1,input2,keypoint2,matches,img_matches);
imshow("matches",img_matches);
imwrite("matches.jpg",img_matches);

waitKey();

	return 0;

    /* initModule_nonfree();//��ʼ��ģ�飬ʹ��SIFT��SURFʱ�õ�  
    Ptr<FeatureDetector> detector = FeatureDetector::create( "SIFT" );//����SIFT���������  
    Ptr<DescriptorExtractor> descriptor_extractor = DescriptorExtractor::create( "SIFT" );//������������������  
    Ptr<DescriptorMatcher> descriptor_matcher = DescriptorMatcher::create( "BruteForce" );//��������ƥ����  
    if( detector.empty() || descriptor_extractor.empty() )  
        cout<<"fail to create detector!";  
  
    //����ͼ��  
   // Mat img1 = imread("beaver.png");  
   // Mat img2 = imread("beaver_xform.png");  
	Mat img1 = imread("aa.jpg");  
    Mat img2 = imread("cc.jpg");  
  
    //��������  
    double t = getTickCount();//��ǰ�δ���  
    vector<KeyPoint> keypoints1,keypoints2;  
    detector->detect( img1, keypoints1 );//���img1�е�SIFT�����㣬�洢��keypoints1��  
    detector->detect( img2, keypoints2 );  
    cout<<"ͼ��1���������:"<<keypoints1.size()<<endl;  
    cout<<"ͼ��2���������:"<<keypoints2.size()<<endl;  
  
    //����������������������Ӿ��󣬼�������������  
    Mat descriptors1,descriptors2;  
    descriptor_extractor->compute( img1, keypoints1, descriptors1 );  
    descriptor_extractor->compute( img2, keypoints2, descriptors2 );  
    t = ((double)getTickCount() - t)/getTickFrequency();  
    cout<<"SIFT�㷨��ʱ��"<<t<<"��"<<endl;  
  
  
    cout<<"ͼ��1�������������С��"<<descriptors1.size()  
        <<"����������������"<<descriptors1.rows<<"��ά����"<<descriptors1.cols<<endl;  
    cout<<"ͼ��2�������������С��"<<descriptors2.size()  
        <<"����������������"<<descriptors2.rows<<"��ά����"<<descriptors2.cols<<endl;  
  
    //����������  
    Mat img_keypoints1,img_keypoints2;  
    drawKeypoints(img1,keypoints1,img_keypoints1,Scalar::all(-1),0);  
    drawKeypoints(img2,keypoints2,img_keypoints2,Scalar::all(-1),0);  
    //imshow("Src1",img_keypoints1);  
    //imshow("Src2",img_keypoints2);  
  
    //����ƥ��  
    vector<DMatch> matches;//ƥ����  
    descriptor_matcher->match( descriptors1, descriptors2, matches );//ƥ������ͼ�����������  
    cout<<"Match������"<<matches.size()<<endl;  
  
    //����ƥ�����о����������Сֵ  
    //������ָ���������������ŷʽ���룬�������������Ĳ��죬ֵԽС��������������Խ�ӽ�  
    double max_dist = 0;  
    double min_dist = 100;  
    for(int i=0; i<matches.size(); i++)  
    {  
        double dist = matches[i].distance;  
        if(dist < min_dist) min_dist = dist;  
        if(dist > max_dist) max_dist = dist;  
    }  
    cout<<"�����룺"<<max_dist<<endl;  
    cout<<"��С���룺"<<min_dist<<endl;  
  
    //ɸѡ���Ϻõ�ƥ���  
    vector<DMatch> goodMatches;  
    for(int i=0; i<matches.size(); i++)  
    {  
        if(matches[i].distance < 0.31 * max_dist)  
        {  
            goodMatches.push_back(matches[i]);  
        }  
    }  
    cout<<"goodMatch������"<<goodMatches.size()<<endl;  
  
    //����ƥ����  
    Mat img_matches;  
    //��ɫ���ӵ���ƥ���������ԣ���ɫ��δƥ���������  
    drawMatches(img1,keypoints1,img2,keypoints2,goodMatches,img_matches,  
                Scalar::all(-1)/*CV_RGB(255,0,0)*/
	//,CV_RGB(0,255,0),Mat(),2);  
  
 //imshow("MatchSIFT",img_matches);  
  //  waitKey(0);  
	//return 0;*/

}
  

