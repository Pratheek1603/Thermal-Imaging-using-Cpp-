# Thermal-Imaging-using-MATLAB-
MATLAB provides functions to acquire thermal images from various sources, such as cameras, files, or simulated data.
Thermal Imaging using C++ is a computer vision project that demonstrates how thermal-style image visualization can be simulated using image processing techniques. The project uses C++ along with the OpenCV library to process images or video frames and apply thermal color mappings that resemble real thermal camera output.

The main program is responsible for initializing the system, capturing image frames, processing them, and displaying the thermal visualization. It begins by loading the required libraries and setting up the camera or reading an input image/video. Once the input is obtained, each frame is processed to extract intensity information.

The captured image is first converted into grayscale so that pixel brightness values can represent relative heat levels. Based on these intensity values, the program simulates temperature differences across the image. A thermal color map is then applied, transforming grayscale intensity values into colors such as blue, yellow, red, and white to visually represent colder and hotter regions.

After processing, the thermal-style image is displayed in real time. If a webcam is used, the program continuously captures and processes frames to create a live thermal imaging effect. Users can typically stop the program using a keyboard input.

This project demonstrates basic concepts of image processing, real-time video processing, and color mapping using C++. It can serve as a learning project for students and developers interested in computer vision, thermal visualization techniques, and practical usage of OpenCV in C++ applications.
