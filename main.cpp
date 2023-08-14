#include <QApplication>
#include "videostreamer.h"

int main(int argc, char *argv[])
{

  QApplication app(argc, argv);
  v4l2_device_param C1;
  C1.dev_name = "/dev/video0";
  VideoStreamer FirstCamera(C1, true);
  FirstCamera.show();

  v4l2_device_param C2;
  C2.dev_name = "/dev/video1";
  VideoStreamer SecondCamera(C2, true);
  SecondCamera.show();


  /*v4l2_device_param C3;
  C3.dev_name = "/dev/video2";
  VideoStreamer ThirdCamera(C3, true);
  ThirdCamera.show();


  v4l2_device_param C4;
  C4.dev_name = "/dev/video3";
  VideoStreamer FourthCamera(C4, true);
  FourthCamera.show();*/

  return app.exec();
}
