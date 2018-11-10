#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_action_file_open_triggered()
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open File"));
	QImage image;
	if (image.load(path)) {
		ui->centralWidget->setImage(image);
	}
}

void MainWindow::on_action_filter_sepia_triggered()
{
	ui->centralWidget->sepia();
}

void MainWindow::on_action_filter_unsepia_triggered()
{
	ui->centralWidget->unsepia();
}
