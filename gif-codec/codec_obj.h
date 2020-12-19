#ifndef CODEC_OBJ
#define CODEC_OBJ

#include <QObject>
#include <QThread>
#include <QScreen>
#include <QPixmap>
#include <QImage>
#include <QWindow>
#include <QApplication>
#include <QWidget>

#include "widgets/fullscreen_widget.h"

class Gif_Codecc : public QObject
{
	Q_OBJECT
//	Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)


public:
	explicit Gif_Codecc(QObject *parent = 0);
	virtual ~Gif_Codecc();
	bool running() const;
	bool recording_active = false;
	FullScreen_Widget fullscreen_w;

private:
	uint16_t delay = 100;

public slots:
	void Gif_StartWrite();

signals:
	void finished();
};

#endif // CODEC_OBJ
