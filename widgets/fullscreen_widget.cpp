#include "fullscreen_widget.h"

FullScreen_Widget::FullScreen_Widget(QWidget *parent) :
    QWidget(parent),
    mainLabel(new QLabel(this))
{
    mainLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLabel->setAlignment(Qt::AlignCenter);

    const QRect screenGeometry = screen()->geometry();
    mainLabel->setGeometry(screenGeometry);

    rubberBand_palette.setBrush(QPalette::Highlight, QBrush(Qt::white));

    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    rubberBand->setPalette(rubberBand_palette);

    key_Esc = new QShortcut(this);
    key_Esc->setKey(Qt::Key_Escape);
    connect(key_Esc, &QShortcut::activated, this, &FullScreen_Widget::slotShortcutEsc);

    key_Enter = new QShortcut(this);
    key_Enter->setKey(Qt::Key_Return);
    connect(key_Enter, &QShortcut::activated, this, &FullScreen_Widget::slotShortcutEnter);
}

void FullScreen_Widget::mousePressEvent(QMouseEvent *event)
{
    rubberBand_point = event->pos();
    rubberBand->setGeometry(QRect(rubberBand_point, QSize()));
    rubberBand->show();
}

void FullScreen_Widget::mouseMoveEvent(QMouseEvent *event)
{
        rubberBand->setGeometry(QRect(rubberBand_point, event->pos()).normalized());
        setCursor(Qt::CrossCursor);
}

void FullScreen_Widget::mouseReleaseEvent(QMouseEvent *event)
{
        setCursor(Qt::ArrowCursor);
//    rubberBand->hide();
}

void FullScreen_Widget::show_screenshot(QPixmap input)
{
    mainLabel->setPixmap(input);
    this->showFullScreen();
}

void FullScreen_Widget::slotShortcutEsc()
{
    rubberBand->hide();
    this->setVisible(false);
    emit signalEsc();
}

void FullScreen_Widget::slotShortcutEnter()
{
    rubberBand_rect.setX(rubberBand->x());
    rubberBand_rect.setY(rubberBand->y());
    rubberBand_rect.setHeight(rubberBand->height());
    rubberBand_rect.setWidth(rubberBand->width());
//    rubberBand->hide();
    this->setVisible(false);
	emit signalEnter();
}
