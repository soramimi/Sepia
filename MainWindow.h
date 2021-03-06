#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_action_file_open_triggered();

	void on_action_filter_sepia_triggered();

	void on_action_filter_unsepia_triggered();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
