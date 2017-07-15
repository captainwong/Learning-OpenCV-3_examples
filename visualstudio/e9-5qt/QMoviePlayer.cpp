#include "QMoviePlayer.h"
#include "ui_QMoviePlayer.h"
#include <qtimer.h>
#include <qpainter.h>

QMoviePlayer::QMoviePlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QMoviePlayer)
{
    ui->setupUi(this);
}

QMoviePlayer::~QMoviePlayer()
{
    delete ui;
}

bool QMoviePlayer::open(std::string file)
{
	if (!cap_.open(file)) {
		return false;
	}

	cap_.read(cv_img_);
	qt_img_ = QImage(QSize(cv_img_.cols, cv_img_.rows), QImage::Format_RGB888);
	ui->frame->setMinimumSize(qt_img_.width(), qt_img_.height());
	ui->frame->setMaximumSize(qt_img_.width(), qt_img_.height());
	_copyImage();

	timer_ = new QTimer(this);
	connect(timer_, SIGNAL(timeout()), this, SLOT(nextFrame()));
	timer_->start(1000.0 / cap_.get(cv::CAP_PROP_FPS));

	return true;
}

void QMoviePlayer::paintEvent(QPaintEvent * e)
{
	QPainter painter(this);
	painter.drawImage(QPoint(ui->frame->x(), ui->frame->y()), qt_img_);
}

void QMoviePlayer::_copyImage()
{
	cv::Mat cv_header_to_qt_image(cv::Size(qt_img_.width(), qt_img_.height()), CV_8UC3, qt_img_.bits());
	cv::cvtColor(cv_img_, cv_header_to_qt_image, CV_BGR2RGB);
}

void QMoviePlayer::nextFrame()
{
	if (!cap_.isOpened()) { return; }

	cap_.read(cv_img_);
	_copyImage();
	this->update();
}
