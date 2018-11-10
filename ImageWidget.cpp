#include "ImageWidget.h"
#include <stdint.h>
#include <QPainter>

ImageWidget::ImageWidget(QWidget *parent)
	: QWidget(parent)
{

}

void ImageWidget::setImage(QImage image)
{
	image_ = image;
	update();
}

void ImageWidget::sepia()
{
	QImage image = image_.convertToFormat(QImage::Format_RGB888);
	int w = image.width();
	int h = image.height();
	if (w < 1 || h < 1) return;
	for (int y = 0; y < h; y++) {
		uint8_t *p = image.scanLine(y);
		for (int x = 0; x < w; x++) {
			double r = p[0];
			double g = p[1];
			double b = p[2];
			r = pow(r / 255, 0.62) * 205 + 19;
			g = pow(g / 255, 1.00) * 182 + 17;
			b = pow(b / 255, 1.16) * 156 + 21;
			p[0] = r;
			p[1] = g;
			p[2] = b;
			p += 3;
		}
	}
	image_ = image;
	update();
}

void ImageWidget::unsepia()
{
	QImage image = image_.convertToFormat(QImage::Format_RGB888);
	int w = image.width();
	int h = image.height();
	if (w < 1 || h < 1) return;
	for (int y = 0; y < h; y++) {
		uint8_t *p = image.scanLine(y);
		for (int x = 0; x < w; x++) {
			double r = p[0];
			double g = p[1];
			double b = p[2];
			r = pow((r - 19) / 205, 1 / 0.62) * 255;
			g = pow((g - 17) / 182, 1 / 1.00) * 255;
			b = pow((b - 21) / 156, 1 / 1.16) * 255;
			if (r < 0) r = 0; else if (r > 255) r = 255;
			if (g < 0) g = 0; else if (g > 255) g = 255;
			if (b < 0) b = 0; else if (b > 255) b = 255;
			p[0] = r;
			p[1] = g;
			p[2] = b;
			p += 3;
		}
	}
	image_ = image;
	update();
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
	QPainter pr(this);
	pr.drawImage(0, 0, image_);
}
