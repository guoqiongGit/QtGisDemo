

/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/

#ifndef BLACKSTYLE_HPP
#define BLACKSTYLE_HPP

//#include "qxdrribbon_global.h"
#include <QApplication>
#include <QFile>
#include <QFont>
#include <QProxyStyle>
#include <QStyleFactory>

class BlackStyle : public QProxyStyle {
	Q_OBJECT

public:
	BlackStyle();
	explicit BlackStyle(QStyle *style);

	QStyle *baseStyle() const;

	void polish(QPalette &palette) override;
	void polish(QApplication *app) override;

private:
	QStyle *styleBase(QStyle *style = Q_NULLPTR) const;
	QString mstrStylesheet;

};

#endif  // BLACKDARKSTYLE_HPP
