#include "videostreamer.h"
#include "ui_videostreamer.h"
#include <QPainter>
#include <QDebug>
#include <QByteArray>
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>

VideoStreamer::VideoStreamer(v4l2_device_param param, bool mainCamera, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::VideoStreamer),
  _capture(new V4L2Device(param))
{
  ui->setupUi(this);
  _width =  (int) _capture->getWidth();
  _height = (int) _capture->getHeight();
  _stride = (int) _capture->getStride();

  if (mainCamera)
  {
      _capture->setCallback([&](const Buffer& buffer, const struct v4l2_buffer& buffer_info) {

          QImage img = QImage(_width, _height, QImage::Format_RGB888);
          unsigned char *rgb_data = img.bits();
          v4lconvert_yuyv_to_rgb24((const unsigned char*) buffer.data, rgb_data, _width, _height, _stride);
          emit renderedImage(img);
        });

  }
  /*else
  {
      _capture->setCallback([&](const Buffer& buffer, const struct v4l2_buffer& buffer_info)
      {

          cv::Mat bayer8 =  cv::Mat(_height, _width, CV_8UC1, (uchar*) buffer.data);
          cv::Mat rgb8 =  cv::Mat(_height, _width, CV_8UC3);
          cv::cvtColor(bayer8, rgb8, cv::COLOR_BayerBG2BGR);
          cv::Mat result = cv::Mat(_height, _width, CV_8UC3);
          cv::cvtColor(rgb8, result, cv::COLOR_BGR2RGB);
          QImage img = QImage((const uchar*) result.data, result.cols,result.rows, result.step1(), QImage::Format_RGB888);
          img.bits();
          emit renderedImage(img);
        });      
    }*/

  // connect rendered image signal to set picture slot
  connect(this, SIGNAL(renderedImage(QImage)), this, SLOT(setPicture(QImage)));
  setAutoFillBackground(true);
}
/*********************************************************************************************/
void VideoStreamer::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  painter.setPen(Qt::white);
  painter.setFont(QFont("Arial", 30));
  painter.drawText(rect(), Qt::AlignCenter, "BEL VIDEO GRABBER");
  painter.drawPixmap(this->rect(), pixmap);
}
/*********************************************************************************************/
void VideoStreamer::setPicture(const QImage& image)
{
  pixmap = QPixmap::fromImage(image);
  update();
  qApp->processEvents();
}
/*********************************************************************************************/
VideoStreamer::~VideoStreamer()
{
  delete ui;
}
/*********************************************************************************************/
void VideoStreamer::on_streamButton_clicked()
{
  _capture->changeState();

  if (_capture->isCapturing())
  {
      ui->streamButton->setText("STOP");
  }
  else
  {
      ui->streamButton->setText("START");
  }
}
/*********************************************************************************************/
