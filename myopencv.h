#ifndef MYOPENCV_H
#define MYOPENCV_H

#include <QString>
#include <QObject>
#include <QWidget>
#include <opencv2/opencv.hpp>

class MyOpenCV : public QObject
{
    Q_OBJECT
public:
    MyOpenCV(const QString &windowName, int idCamera, QObject *parent = nullptr);
    ~MyOpenCV();

    QWidget *videoOutput() const
    {
        return mVideoOutputWidget;
    }

    QString windowName()
    {
        return mWindowName;
    }

    bool start();
signals:
    void ready();
private:
    bool mExit;
    cv::VideoCapture mVideoCap;
    cv::Mat mFrame;
    QString mWindowName;
    QWidget *mVideoOutputWidget;
};

#endif // MYOPENCV_H
