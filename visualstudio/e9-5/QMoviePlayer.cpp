#include "QMoviePlayer.h"
#include "ui_QMoviePlayer.h"

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
	return false;
}

void QMoviePlayer::paintEvent(QPaintEvent * e)
{
}

void QMoviePlayer::_copyImage()
{
}

void QMoviePlayer::nextFrame()
{
}
