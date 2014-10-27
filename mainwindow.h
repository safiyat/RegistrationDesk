#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>

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
		void broadcastMessage();
		void otherCheck(QString);
		void clearFields();

	private:
		Ui::MainWindow *ui;
		QString uname;
		QDateTime delta;
		QStringList collegeNames;
		QStringList eventNames;

};

#endif // MAINWINDOW_H
