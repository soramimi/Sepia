#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>



class ImageWidget : public QWidget {
private:
	QImage image_;
public:
	ImageWidget(QWidget *parent);
	void setImage(QImage image);
	void sepia();
	void unsepia();
protected:
	void paintEvent(QPaintEvent *event);
};

#endif // IMAGEWIDGET_H
