#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
/*****************************************************************************/
	uname = "Safiyat";

	collegeNames.append(" ");
	collegeNames.append("Jamia Millia Islamia");
	collegeNames.append("Delhi Technological University");
	collegeNames.append("Indraprastha Institute of Information Technology");
	collegeNames.append("Bhartiya Vidya Peeth");
	collegeNames.append("Indian Institute of Technology");
	collegeNames.append("Maharaja Agrasen Institute of Technology");
	collegeNames.sort();
	collegeNames.append("Other");

	eventNames.append("Crux");
	eventNames.append("Lan Gaming");
	eventNames.append("Nukkad Natak");
	eventNames.append("Treasure Hunt");
	eventNames.append("Temple Run");
	eventNames.append("Online Treasure Hunt");
	eventNames.append("Gali Cricket");
	eventNames.append("Intra Faculty Quiz");
	eventNames.append("Snap It");
	eventNames.append("Who Dares Wins");
	eventNames.append("Graffiti");
	eventNames.append("Street Dance");
	eventNames.append("Face Painting");
	eventNames.append("T-shirt Painting");
	eventNames.append("Master Chef");
	eventNames.append("Rangoli");
	eventNames.append("Salad Engineering");
	eventNames.append("Royal Battle Chess");
	eventNames.append("Carrom");
	eventNames.append("Beg Borrow Steal");
	eventNames.append("Darting");
	eventNames.append("Sudoku");
	eventNames.append("Ping Pong");
	eventNames.append("Juke Box");
	eventNames.append("Hello World");
	eventNames.append("Java Pro");
	eventNames.append("Verbattle");
	eventNames.append("Ed Max");
	eventNames.append("Roboholics");
	eventNames.append("Bridging The Gap");
	eventNames.append("Eureka");
	eventNames.append("Android");
	eventNames.append("Grid Solver");
	eventNames.append("Mini Marathon");
	eventNames.append("Futsal");
	eventNames.append("Solo Singing");
	eventNames.append("Cric Football");
	eventNames.append("Baloon Buster");
	eventNames.append("Entertainment Quiz");
	eventNames.append("Ad Wars");
	eventNames.append("Tug Of War");
	eventNames.append("Snakes And Ladders");
	eventNames.append("Pencil Sketching");
	eventNames.append("Mehendi Making");
	eventNames.append("Shoot The Basket");
	eventNames.append("Clicker Art");
	eventNames.append("Slow Biking");
	eventNames.append("Business Baazigar");
	eventNames.append("Tequizit");
	eventNames.append("I Am Ronald Dahl");
	eventNames.append("Tux Coder");
	eventNames.append("Jamia Dev Day");
	eventNames.sort();
/*****************************************************************************/

	ui->collegeCombo->addItems(collegeNames);

	for(int i = 0; i < eventNames.length(); i++)
	{
		QListWidgetItem *k = new QListWidgetItem(eventNames.at(i), ui->eventList);
		k->setFlags(k->flags() | Qt::ItemIsUserCheckable);
		k->setCheckState(Qt::Unchecked);
		ui->eventList->addItem(k);
	}
	ui->eventCombo->addItems(eventNames);
}

MainWindow::~MainWindow()
{
	delete ui;
}
/*
void sendConnectionRequest()
{

}
*/
void MainWindow::broadcastMessage()
{
	QString text = ui->broadcastMessage->text();
	text.prepend(tr("<b><span style=\"color:blue\">%1</span> <span style=\"color:red\">%2</span></b><br>").arg(uname).arg(QDateTime::currentDateTime().toString()));
	text.append("<br>");
	//Send text to server through messageboard socket
	ui->messageBoard->append(text);
	ui->broadcastMessage->clear();
}

void MainWindow::otherCheck(QString text)
{
	if(text == "Other")
		ui->collegeEdit->setEnabled(true);
	else
		ui->collegeEdit->setEnabled(false);
}

void MainWindow::clearFields()
{
	ui->nameEdit->clear();
	ui->collegeCombo->setCurrentIndex(0);
	ui->collegeEdit->clear();
	ui->emailEdit->clear();
	ui->phoneEdit->clear();
	for(int i = 0; i < ui->eventList->count(); i++)
		ui->eventList->item(i)->setCheckState(Qt::Unchecked);
}
