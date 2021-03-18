
#include <memory>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

std::unique_ptr<cv::Mat> toGray(std::unique_ptr<cv::Mat> _uptr)
{
    std::cout << "using unique ptr" << std::endl;
    cv::Mat dst;
    cv::cvtColor(*_uptr, dst, cv::COLOR_RGB2GRAY);
    std::unique_ptr<cv::Mat> ret(new cv::Mat(dst));
    return ret;
}

cv::Mat toGray(cv::Mat* _ptr)
{
    std::cout << "using raw ptr" << std::endl;
    cv::Mat dst;
    cv::cvtColor(*_ptr, dst, cv::COLOR_RGB2GRAY);
    return dst;
}

std::unique_ptr<cv::Mat> toEdge(std::unique_ptr<cv::Mat> _uptr)
{
    std::cout << "using unique ptr" << std::endl;
    cv::Mat dst;
    cv::Canny(*_uptr, dst, 100, 127);
    std::unique_ptr<cv::Mat> ret(new cv::Mat(dst));
    return ret;
}




int main()

{
    cv::Mat img = cv::imread("/home/colson/workspace/cpp-memory-master/example/opencv/landscape.jpg", cv::IMREAD_COLOR);
    
    std::unique_ptr<cv::Mat> A(new cv::Mat(img));

    std::cout << "col: " << img.cols << "row: " << img.rows;
    cv::imshow("Display window", img);
    int k = cv::waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        cv::imwrite("/home/colson/workspace/cpp-memory-master/example/opencv/landscape_copy.png", img);
    }

    cv::Mat gray = toGray(&img);
    cv::imshow("Gray window1", gray);
    k = cv::waitKey(0);
    if(k == 's')
    {
        cv::imwrite("/home/colson/workspace/cpp-memory-master/example/opencv/landscape_Gray.png", img);
    }

    auto ret = toGray(std::move(A));
    cv::Mat *retptr = ret.get();
    cv::imshow("Gray window2", *retptr);
    k = cv::waitKey(0);
    
    auto B = std::move(ret);

    auto ret2 = toEdge(std::move(B));
    cv::Mat *retptr2 = ret2.get();
    cv::imshow("Gray window2", *retptr2);
    k = cv::waitKey(0);

    // std::unique_ptr<cv::Mat> ret = toGray(*img);

    // std::unique_ptr<cv::Mat> input = std::make_unique<cv::Mat>(img);
    // std::unique_ptr<cv::Mat> ret = toGray(std::move(img));


    return 0;
}