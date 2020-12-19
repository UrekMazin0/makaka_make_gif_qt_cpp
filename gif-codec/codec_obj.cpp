#include "gif-codec/codec_obj.h"
#include "gif-codec/gif.h"

const char* filename = "test.gif";

Gif_Codecc::Gif_Codecc(QObject *parent):
	QObject(parent)
{

}

Gif_Codecc::~Gif_Codecc()
{

}

void Gif_Codecc::Gif_StartWrite()
{
	// inizialization GifWriter object
	GifWriter main_gif;
	GifBegin(&main_gif, filename, fullscreen_w.rubberBand_rect.width(), fullscreen_w.rubberBand_rect.height(), delay);

	// grub full window screen to qscreen
	QScreen *screen = QGuiApplication::primaryScreen();
	if (const QWindow *window = windowHandle())
		screen = window->screen();
	if (!screen)
		return;

	QPixmap desktop_screen;
	QImage desktop_screen_buffer(fullscreen_w.rubberBand_rect.width(), fullscreen_w.rubberBand_rect.height(), QImage::Format_RGBA8888);

	while(recording_active)
	{
		desktop_screen = screen->grabWindow(0, fullscreen_w.rubberBand_rect.x(),
											   fullscreen_w.rubberBand_rect.y(),
											   fullscreen_w.rubberBand_rect.height(),
											   fullscreen_w.rubberBand_rect.width());

		desktop_screen_buffer = desktop_screen.toImage();
		desktop_screen_buffer = desktop_screen_buffer.convertToFormat(QImage::Format_RGBA8888);

		GifWriteFrame(&main_gif,
					  desktop_screen_buffer.bits(),
					  fullscreen_w.rubberBand_rect.width(),
					  fullscreen_w.rubberBand_rect.height(),
					  delay);
		QThread::sleep(1);
	}

	GifEnd(&main_gif);

	emit finished();
}
