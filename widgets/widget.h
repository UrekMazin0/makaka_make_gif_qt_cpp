#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QThread>
#include <QApplication>
#include <QPixmap>
#include <QScreen>
#include <QWindow>
#include <QDebug>
#include <QImage>

#include "widgets/fullscreen_widget.h"
#include "gif-codec/codec_obj.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton * CreateGifArea_button;
    QPushButton * SaveAs_button;
    QPushButton * Copy_button;
    QPushButton * Stop_button;
    FullScreen_Widget fullscreen_w;
    QPixmap desktop_screen;

	Gif_Codecc gif_Obj;
	QThread thread_gif_write;

private slots:
    void slot_CreateGifArea();
    void slot_SaveAs();
    void slot_Copy();
    void slot_Stop();
    void slot_start_recording();

};

#endif // WIDGET_H
