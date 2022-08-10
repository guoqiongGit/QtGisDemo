
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

#include "BlackStyle.h"

BlackStyle::BlackStyle() 
{

}

BlackStyle::BlackStyle(QStyle *style) : QProxyStyle(style) {}

QStyle *BlackStyle::styleBase(QStyle *style) const {
	static QStyle *base =
		!style ? QStyleFactory::create(QStringLiteral("Fusion")) : style;
	return base;
}

QStyle *BlackStyle::baseStyle() const { return styleBase(); }

void BlackStyle::polish(QPalette &palette) {
	// modify palette to dark
	palette.setColor(QPalette::Window, QColor(53, 53, 53));
	palette.setColor(QPalette::WindowText, Qt::white);
	palette.setColor(QPalette::Disabled, QPalette::WindowText,
		QColor(127, 127, 127));
	palette.setColor(QPalette::Base, QColor(25, 35, 45));
	palette.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
	palette.setColor(QPalette::ToolTipBase, Qt::white);
	palette.setColor(QPalette::ToolTipText, QColor(53, 53, 53));
	palette.setColor(QPalette::Text, Qt::white);
	palette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
	palette.setColor(QPalette::Dark, QColor(35, 35, 35));
	palette.setColor(QPalette::Shadow, QColor(20, 20, 20));
	palette.setColor(QPalette::Button, QColor(53, 53, 53));
	palette.setColor(QPalette::ButtonText, Qt::white);
	palette.setColor(QPalette::Disabled, QPalette::ButtonText,
		QColor(127, 127, 127));
	palette.setColor(QPalette::BrightText, Qt::red);
	palette.setColor(QPalette::Link, QColor(42, 130, 218));
	palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
	palette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
	palette.setColor(QPalette::HighlightedText, Qt::white);
	palette.setColor(QPalette::Disabled, QPalette::HighlightedText,
		QColor(127, 127, 127));
}

void BlackStyle::polish(QApplication *app) {
	if (!app) return;

	QFont defaultFont = QApplication::font();
	defaultFont.setPointSize(defaultFont.pointSize() + 1);
	app->setFont(defaultFont);

	if (mstrStylesheet.isEmpty())
	{
		// loadstylesheet
		QFile qfDarkstyle(QStringLiteral(":/darkstyle/blackstyle.qss"));
		if (qfDarkstyle.open(QIODevice::ReadOnly | QIODevice::Text)) {
			// set stylesheet
			mstrStylesheet = QString::fromLatin1(qfDarkstyle.readAll());
			qfDarkstyle.close();
		}
	}
	app->setStyleSheet(mstrStylesheet);

}

