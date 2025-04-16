#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
int main()
{
    std::string forground_path = "../img/01.png";
    std::string mask_path = "../img/01-alpha.png";
    std::string back_path = "../img/02.png";
    Mat fore = imread(forground_path, IMREAD_COLOR);
    Mat mask = imread(mask_path, IMREAD_COLOR);
    Mat back = imread(back_path, IMREAD_COLOR);

    mask.convertTo(mask, CV_32FC3, 1.0 / 255);
    std::vector<Mat *> imgs = {&fore, &back, &mask};
    for (auto img : imgs)
    {
        Mat tmp = img->clone();
        putText(tmp, "Press any key to continue", Point(100, 80), FONT_HERSHEY_TRIPLEX, 1.0, Scalar(0, 0, 0), 5);
        putText(tmp, "Press any key to continue", Point(100, 80), FONT_HERSHEY_TRIPLEX, 1.0, Scalar(218, 254, 252), 3);
        imshow("Display window - out", tmp);
        waitKey(0);
    }

    int i = 0;
    while (true)
    {
        i += 1;
        i %= fore.cols;
        if (i == 0)
            continue;
        auto l = fore.colRange(0, i);
        auto r = fore.colRange(i, fore.cols);

        auto l_a = mask.colRange(0, i);
        auto r_a = mask.colRange(i, mask.cols);

        Mat f, m;
        hconcat(r, l, f);
        hconcat(r_a, l_a, m);

        Mat out = Mat::zeros(back.size(), back.type());
        Mat b = back.clone();
        putText(b, "Press 'q' to exit", Point(100, 80), FONT_HERSHEY_TRIPLEX, 1.0, Scalar(218, 254, 252), 3);
        putText(b, "a CMake/vcpkg/OpenCV demo", Point((550 - i * 2 / 3) % b.cols, 180), FONT_HERSHEY_TRIPLEX, 1.5, Scalar(255, 255, 255), 5);
        putText(b, "a CMake/vcpkg/OpenCV demo", Point((550 - i * 2 / 3) % b.cols, 180), FONT_HERSHEY_TRIPLEX, 1.5, Scalar((20 + i) % 20 + 218, 149, 242), 2);
        multiply(Scalar::all(1.0) - m, f, f, 1.0, fore.type());
        multiply(m, b, b, 1.0, b.type());

        add(b, f, out);
        imshow("Display window - out", out);
        if ('q' == waitKey(1)) // Wait for a keystroke in the window
            break;
    }
    return 0;
}