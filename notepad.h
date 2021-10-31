#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

// imports by developer
# include <QFile>
# include <QFileDialog>
# include <QMessageBox>
# include <QTextStream>
# include <QPrinter>
# include <QPrintDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_actionAbout_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionzoom_in_triggered();

    void on_actionzoom_out_triggered();

private:
    Ui::Notepad *ui;
    QString CurrentFile = "";
    QString aboutText = "A simple notepad created by A.Muli, while learning Qt.";
};
#endif // NOTEPAD_H
