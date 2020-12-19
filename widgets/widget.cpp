#include "widget.h"
//#include "gif-codec/gif.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Giffy");
    this->setFixedSize(400,200);

    CreateGifArea_button = new QPushButton("Создать",this);
    CreateGifArea_button->setGeometry(10, 10, 100,30);

    SaveAs_button = new QPushButton("Сохранить как",this);
    SaveAs_button->setGeometry(120, 10, 100, 30);

    Copy_button = new QPushButton("Копировать", this);
    Copy_button->setGeometry(230, 10, 100, 30);

    Stop_button = new QPushButton("Остановить", this);
    Stop_button->setGeometry(10, 50, 100, 30);

    connect(CreateGifArea_button, &QPushButton::clicked, this, &Widget::slot_CreateGifArea);
    connect(SaveAs_button, &QPushButton::clicked, this, &Widget::slot_SaveAs);
    connect(Copy_button, &QPushButton::clicked, this, &Widget::slot_Copy);
    connect(Stop_button, &QPushButton::clicked, this, &Widget::slot_Stop);
    connect(&fullscreen_w, &FullScreen_Widget::signalEsc, this, &Widget::show);
    connect(&fullscreen_w, &FullScreen_Widget::signalEnter, this, &Widget::slot_start_recording);

	connect(&thread_gif_write, &QThread::started, &gif_Obj, &Gif_Codecc::Gif_StartWrite);
	connect(&gif_Obj, &Gif_Codecc::finished, &thread_gif_write, &QThread::terminate);
	gif_Obj.moveToThread(&thread_gif_write);
}

Widget::~Widget()
{

}

void Widget::slot_CreateGifArea()
{
    this->setVisible(false);
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
	{
		this->setVisible(true);
        return;
	}

    QPixmap desktop_screen = screen->grabWindow(0);
    fullscreen_w.show_screenshot(desktop_screen);
}

void Widget::slot_SaveAs()
{

}

void Widget::slot_Copy()
{

}

void Widget::slot_start_recording()
{
	this->setVisible(true);
	gif_Obj.recording_active = true;
	thread_gif_write.start();
}

void Widget::slot_Stop()
{

//    qApp->quit();
	gif_Obj.recording_active = false;
}
