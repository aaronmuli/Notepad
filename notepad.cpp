#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit); //setting the textEdit area to take up the full screen

   /* QMenu *about = Notepad::findChild<QMenu *>("menuAbout");
    connect(about, SIGNAL(triggered()), this, SLOT(on_actionAbout()));*/
}

Notepad::~Notepad()
{
    delete ui;
}


// slots defeintions

void Notepad::on_actionAbout_triggered() {
    QMessageBox::information(this, "About", aboutText);
}


void Notepad::on_actionNew_triggered()
{
    CurrentFile.clear();
    ui->textEdit->setText(QString());
}

void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "open file");
    QFile file(fileName);
    CurrentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "can not open file " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void Notepad::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "save as");
    QFile file(fileName);
    CurrentFile = fileName;
    if(!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "can not save file " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void Notepad::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "Warning", "can not access printer");
        return;
    }
    ui->textEdit->print(&printer);
}

void Notepad::on_actionExit_triggered()
{
    QApplication::quit();
}

void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void Notepad::on_actionzoom_in_triggered()
{
    ui->textEdit->zoomIn(1);
}


void Notepad::on_actionzoom_out_triggered()
{
    ui->textEdit->zoomOut(1);
}

