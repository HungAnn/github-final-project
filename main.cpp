#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <time.h>


void getLightness(cv::Mat img, cv::Mat *lightness)
{
    cv::Mat hsl_img;
    std::vector<cv::Mat> channels;

    cv::cvtColor(img, hsl_img, cv::COLOR_RGB2HLS);
    cv::split(hsl_img, channels);
    *lightness = channels[1].clone();
}

void func(cv::Mat a)
{
  cv::Mat matB(cv::Size(1, 256), CV_32F, cv::Scalar(80));
  a = a+cv::Scalar(80);
}

int main()
{
    uint8_t gridNum = 10;//123
    
    int liveViewW = 1024;
    int liveViewH = 680;
    int grideSizeW = liveViewW / gridNum;
    int grideSizeH = liveViewH / gridNum;
    std::string imgName = "DSC00139.JPG";
    int histSize = 256;
    float range[] = {0, 256};
    const float *histRange[] = {range};
    bool uniform = true, accumulate = false;
    int lowThreshold = 30;
    int ratio = 2;
    int kernel_size = 3;
    int skyThreshold = 10000;
    cv::Mat lightness, blurImg, imgHist, subImgHist, detected_edges;

    cv::Mat rawImg = cv::imread(imgName);
    cv::Size dsize = cv::Size(liveViewW, liveViewH);
    cv::Mat resizeImg = cv::Mat(dsize, rawImg.depth());
    cv::resize(rawImg, resizeImg, dsize);
    getLightness(resizeImg, &lightness);
    // cv::blur(lightness, blurImg, cv::Size(3, 3));
    imgHist = cv::Mat::zeros(cv::Size(1, 256), CV_32F);

    clock_t tStart = clock();
    for (uint8_t i = 0; i < gridNum; i++)
    {
        for (uint8_t j = 0; j < gridNum; j++)
        {
            cv::Mat subImg = lightness(cv::Range(j * grideSizeH, (j + 1) * grideSizeH), cv::Range(i * grideSizeW, (i + 1) * grideSizeW));
            cv::Canny(subImg, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
            // std::cout << std::to_string(i) << "_" << std::to_string(j) << ": " << cv::sum(detected_edges)[0] << std::endl;

            if (cv::sum(detected_edges)[0] < skyThreshold)
            {
                // std::cout << "cv::sum(detected_edges)[0] < skyThreshold" << std::endl;
                cv::calcHist(&subImg, 1, 0, cv::Mat(), subImgHist, 1, &histSize, histRange, uniform, accumulate);
                imgHist = imgHist + subImgHist;
            }
            // else
            // {
            //   cv::imwrite("../subImg" + std::to_string(i) + std::to_string(j) + ".jpg", subImg);
            // }
        }
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    // Show hist
    // int hist_w = 512, hist_h = 400;
    // int bin_w = cvRound((double)hist_w / histSize);
    // cv::Mat skyhistImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));
    // cv::Mat srchistImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));
    // cv::Mat bridgehistImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));

    // cv::Mat srcImgHist;
    // cv::calcHist(&lightness, 1, 0, cv::Mat(), srcImgHist, 1, &histSize, histRange, uniform, accumulate);
    // cv::Mat bridgeImgHist = srcImgHist-imgHist;
    // for(int i=0; i<256; i++)
    // {
    //   std::cout << cvRound(srcImgHist.at<float>(i - 1)) << " ";
    // }
    // std::cout << std::endl;
    // normalize(srcImgHist, srcImgHist, 0, srchistImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
    // for (int i = 1; i < histSize; i++)
    // {
    //     cv::line(srchistImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(srcImgHist.at<float>(i - 1))),
    //              cv::Point(bin_w * (i), hist_h - cvRound(srcImgHist.at<float>(i))),
    //              cv::Scalar(0, 255, 0), 2, 8, 0);
    // }

    // for(int i=0; i<256; i++)
    // {
    //   std::cout << cvRound(imgHist.at<float>(i - 1)) << " ";
    // }
    // std::cout << std::endl;
    // normalize(imgHist, imgHist, 0, skyhistImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
    // for (int i = 1; i < histSize; i++)
    // {
    //     cv::line(skyhistImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(imgHist.at<float>(i - 1))),
    //              cv::Point(bin_w * (i), hist_h - cvRound(imgHist.at<float>(i))),
    //              cv::Scalar(0, 255, 0), 2, 8, 0);
    // }

    // for(int i=0; i<256; i++)
    // {
    //   std::cout << cvRound(bridgeImgHist.at<float>(i - 1)) << " ";
    // }
    // std::cout << std::endl;
    // normalize(bridgeImgHist, bridgeImgHist, 0, bridgehistImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
    // for (int i = 1; i < histSize; i++)
    // {
    //     cv::line(bridgehistImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(bridgeImgHist.at<float>(i - 1))),
    //              cv::Point(bin_w * (i), hist_h - cvRound(bridgeImgHist.at<float>(i))),
    //              cv::Scalar(0, 255, 0), 2, 8, 0);
    // }

    // // cv::imshow("SourceHist", srchistImage);
    // // cv::imshow("skyHist Demo", skyhistImage);
    // cv::imwrite("../SourceHist.jpg", srchistImage);
    // cv::imwrite("../SkyHist.jpg", skyhistImage);
    // cv::imwrite("../BridgeHist.jpg", bridgeImgHist);
    // // cv::waitKey();

    return 0;
}
