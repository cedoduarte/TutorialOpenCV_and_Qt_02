#include "myopencv.h"
#include <QtConcurrent>
#include <Windows.h>
#include <QWindow>

MyOpenCV::MyOpenCV(const QString &windowName, int idCamera, QObject *parent)
    : QObject { parent }
    , mVideoCap { idCamera }
{
    mExit = false;
    mWindowName = windowName;
    mVideoOutputWidget = nullptr;
}

MyOpenCV::~MyOpenCV()
{
    mExit = true;
}

bool MyOpenCV::start()
{
    // arrancamos la captura de video de OpenCV
    QtConcurrent::run([&]()
    {
        if (mVideoCap.isOpened())
        {
            while (!mExit)
            {
                mVideoCap >> mFrame;
                if (!mFrame.empty())
                {
                    cv::imshow(mWindowName.toStdString(), mFrame);
                    if (cv::waitKey(5) >= 0)
                    {
                        break;
                    }
                }
            }
        }
    });

    // esperamos a encontrar la ventana de OpenCV
    HWND hwnd = nullptr;
    while (hwnd == nullptr)
    {
        hwnd = FindWindow(nullptr, reinterpret_cast<const wchar_t *>(mWindowName.data()));
    }
    QWindow *window = QWindow::fromWinId(reinterpret_cast<WId>(hwnd));
    mVideoOutputWidget = QWidget::createWindowContainer(window, nullptr);
    return true;
}
