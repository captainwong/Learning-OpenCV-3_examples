/********************************************************************************
** Form generated from reading UI file 'QMoviePlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMOVIEPLAYER_H
#define UI_QMOVIEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMoviePlayer
{
public:
    QFrame *frame;

    void setupUi(QWidget *QMoviePlayer)
    {
        if (QMoviePlayer->objectName().isEmpty())
            QMoviePlayer->setObjectName(QStringLiteral("QMoviePlayer"));
        QMoviePlayer->resize(400, 300);
        frame = new QFrame(QMoviePlayer);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, -10, 401, 311));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(QMoviePlayer);

        QMetaObject::connectSlotsByName(QMoviePlayer);
    } // setupUi

    void retranslateUi(QWidget *QMoviePlayer)
    {
        QMoviePlayer->setWindowTitle(QApplication::translate("QMoviePlayer", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QMoviePlayer: public Ui_QMoviePlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMOVIEPLAYER_H
