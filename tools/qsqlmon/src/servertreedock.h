#ifndef SERVERTREEDOCK_H
#define SERVERTREEDOCK_H

#include <QDockWidget>

#include "ui_servertreewidget.h"

class QAction;
class QActionGroup;
class QMenu;

class ServerTreeDock : public QDockWidget
{
	Q_OBJECT
public:
	ServerTreeDock(QWidget *parent = 0, Qt::WindowFlags flags = 0);
public:
	Ui::ServerTreeWidget ui;
};

#endif
