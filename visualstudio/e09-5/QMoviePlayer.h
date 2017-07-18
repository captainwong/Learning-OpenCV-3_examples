#ifndef QMOVIEPLAYER_H
#define QMOVIEPLAYER_H

#include <QWidget>
#include <opencv2/opencv.hpp>

namespace Ui {
class QMoviePlayer;
}

class QMoviePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit QMoviePlayer(QWidget *parent = 0);
    ~QMoviePlayer();

	bool open(std::string file);

private:
    Ui::QMoviePlayer *ui;
	cv::VideoCapture cap_;
	QImage qt_img_;
	cv::Mat cv_img_;
	QTimer* timer_;

	void paintEvent(QPaintEvent* e);
	void _copyImage();

public slots:
	void nextFrame();
};

#endif // QMOVIEPLAYER_H
