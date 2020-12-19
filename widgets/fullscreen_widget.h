#ifndef FULLSCREEN_WIDGET_H
#define FULLSCREEN_WIDGET_H

#include <QWidget>
#include <QRubberBand>
#include <QPoint>
#include <QMouseEvent>
#include <QPixmap>
#include <QScreen>
#include <QLabel>
#include <QShortcut>
#include <QPalette>
#include <QRect>

class FullScreen_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit FullScreen_Widget(QWidget *parent = nullptr);
    void show_screenshot(QPixmap input);
    QRect rubberBand_rect;

private:

    QRubberBand * rubberBand;
    QPoint rubberBand_point;
    QPixmap ScreenShot;
    QLabel * mainLabel;
    QShortcut * key_Esc;
    QShortcut * key_Enter;
    QPalette rubberBand_palette;

signals:
    void signalEsc();
    void signalEnter();

protected slots:
    void mousePressEvent(QMouseEvent *event)   override;
    void mouseMoveEvent(QMouseEvent *event)    override;
	void mouseReleaseEvent(QMouseEvent *event) override;
    void slotShortcutEsc();
    void slotShortcutEnter();
};

#endif // FULLSCREEN_WIDGET_H
