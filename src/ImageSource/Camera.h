/*
 * Camera.h
 *
 *  Created on: Jul 27, 2015
 *      Author: richard
 */

#ifndef OOI_PROCESSING_CAMERA_H_
#define OOI_PROCESSING_CAMERA_H_

#include <opencv2/videoio.hpp>
#include <string>

class Scene;
class Frame;

class Camera {
public:
	Camera(const std::string& source);
	virtual ~Camera();
	bool getNextFrame(cv::Mat& img, cv::Mat& overlay);
	const std::string& getSourceName() const;
	int getFPS() const;
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	void restart();

private:
	const std::string source_;
	cv::VideoCapture camera_;
//	cv::Size size;
	int fps_;
	unsigned int width_;
	unsigned int height_;
	bool real_camera_;
    double text_size_ = 0.75;
    int left_margin_ = 40;
    int top_margin_ = 25;

};

#endif /* OOI_PROCESSING_CAMERA_H_ */