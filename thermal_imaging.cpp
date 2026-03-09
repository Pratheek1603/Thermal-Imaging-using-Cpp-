
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    string filename = "taj.jpg";

    cout << "Transforming image to a thermal image: " << filename << endl;

    Mat originalRGBImage = imread(filename);

    if (originalRGBImage.empty()) {
        cout << "Error loading image!" << endl;
        return -1;
    }

    imshow("Original Image", originalRGBImage);

    // Convert to grayscale using minimum channel value (MATLAB min(...,[],3))
    Mat channels[3];
    split(originalRGBImage, channels);
    Mat grayImage = min(channels[0], min(channels[1], channels[2]));

    // Crop RGB image
    int imageRow1 = 40;
    int imageRow2 = 298;
    int imageCol1 = 20;
    int imageCol2 = 460;

    Rect rgbROI(imageCol1, imageRow1,
                imageCol2 - imageCol1,
                imageRow2 - imageRow1);

    Mat rgbImage = originalRGBImage(rgbROI);

    imshow("Cropped Pseudocolor Image", rgbImage);

    // Crop colorbar
    int colorBarRow1 = 45;
    int colorBarRow2 = 293;
    int colorBarCol1 = 533;
    int colorBarCol2 = 545;

    Rect colorBarROI(colorBarCol1, colorBarRow1,
                     colorBarCol2 - colorBarCol1,
                     colorBarRow2 - colorBarRow1);

    Mat colorBarImage = originalRGBImage(colorBarROI);

    imshow("Colorbar Image", colorBarImage);

    // Extract color map from first column
    Mat storedColorMap(colorBarImage.rows, 1, CV_32FC3);

    for (int i = 0; i < colorBarImage.rows; i++)
    {
        Vec3b pixel = colorBarImage.at<Vec3b>(i, 0);

        storedColorMap.at<Vec3f>(i,0)[0] = pixel[0] / 255.0f;
        storedColorMap.at<Vec3f>(i,0)[1] = pixel[1] / 255.0f;
        storedColorMap.at<Vec3f>(i,0)[2] = pixel[2] / 255.0f;
    }

    // Flip vertically
    flip(storedColorMap, storedColorMap, 0);

    // Convert cropped image to grayscale index
    Mat indexedImage;
    cvtColor(rgbImage, indexedImage, COLOR_BGR2GRAY);

    imshow("Indexed Image", indexedImage);

    double highTemp = 51.6;
    double lowTemp  = 20.6;

    Mat normalized;
    normalize(indexedImage, normalized, 0, 1, NORM_MINMAX, CV_32F);

    Mat thermalImage = lowTemp + (highTemp - lowTemp) * normalized;

    Mat displayThermal;
    normalize(thermalImage, displayThermal, 0, 255, NORM_MINMAX);
    displayThermal.convertTo(displayThermal, CV_8U);

    applyColorMap(displayThermal, displayThermal, COLORMAP_JET);

    imshow("Thermal Image", displayThermal);

    waitKey(0);
    return 0;
}
