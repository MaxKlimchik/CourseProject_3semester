#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QRegularExpressionMatchIterator>
#include <QFileDialog>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QWidget>
#include "UI_text.h"
#include "Service.hpp"
using namespace SpellCheck;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    SC_Service *SpellChecker;
    QList<QPair<qint32, qint32>> misspells;
    qint32 total_words;
    qint32 current_misspell;

    void CheckOrphography();
    void MoveToCurrentMisspell();
    void ActualizeNavigation();

private slots:
    void OnCheckButtonClick();
    void OnOpenTxtClick();
    void OnSaveTxtClick();
    void OnPrevMisspellClick();
    void OnNextMisspellClick();
};
#endif // MAINWINDOW_H
