#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), total_words(0), current_misspell(0)
{
    ui->setupUi(this);
    connect(ui->Button_CheckOrpho, SIGNAL(clicked()), SLOT(OnCheckButtonClick()));
    connect(ui->Button_OpenTxt, SIGNAL(clicked()), SLOT(OnOpenTxtClick()));
    connect(ui->Button_SaveTxt, SIGNAL(clicked()), SLOT(OnSaveTxtClick()));
    connect(ui->Button_NextMisspell, SIGNAL(clicked()), SLOT(OnNextMisspellClick()));
    connect(ui->Button_PrevMisspell, SIGNAL(clicked()), SLOT(OnPrevMisspellClick()));
    ui->Selector_HTChain->click();

    QElapsedTimer timer;
    timer.start();
    std::string dictionary_path = "dictionaries\\RU_ru\\united_russian.dic";
    SpellChecker = new SC_Service(dictionary_path);
    qint64 load_time = timer.elapsed();
    ui->Label_DictLoadTime->setEnabled(true);
    ui->Label_DictLoadTime->setText(LABEL_DICTLOADTIME_TEXT + QString::number(load_time) + MILLISEC_LITERAL);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete SpellChecker;
}

void MainWindow::CheckOrphography()
{
    QTextCursor baseCursor = ui->TextField->textCursor();

    QTextCursor clearCursor(ui->TextField->document());
    clearCursor.select(QTextCursor::Document);
    QTextCharFormat clearCharFormat;
    clearCharFormat.setUnderlineStyle(QTextCharFormat::NoUnderline);
    clearCursor.mergeCharFormat(clearCharFormat);

    misspells.clear();
    misspells.squeeze();
    total_words = 0;
    QString text = ui->TextField->toPlainText();

    QRegularExpression regExpression("([А-Яа-яЁё]+)((-[А-Яа-яЁё]+)*)");
    QRegularExpressionMatchIterator it = regExpression.globalMatch(text);

    QTextCharFormat misspell;
    misspell.setUnderlineStyle(QTextCharFormat::WaveUnderline);
    misspell.setUnderlineColor(Qt::red);

    QTextCursor cursor(ui->TextField->document());
    while (it.hasNext())
    {
        QRegularExpressionMatch match = it.next();
        qint32 startPos = match.capturedStart();
        qint32 length = match.capturedLength();

        QString word1 = match.captured(1);
        QString word2 = match.captured(2);

        // проверка всего слова целиком
        bool isCorrect = false;
        if ((word1 + word2).size() == 1)
            isCorrect = true;
        else if (SpellChecker->CheckWord((word1+word2).toStdWString()))
            isCorrect = true;
        else if (SpellChecker->CheckWord((word1+word2).toLower().toStdWString()))
            isCorrect = true;

        // проверка слов по отдельности
        if (!isCorrect)
        {
            isCorrect = false;
            // проверка слова word1
            if (SpellChecker->CheckWord(word1.toStdWString()))
                isCorrect = true;
            else if (SpellChecker->CheckWord(word1.toLower().toStdWString()))
                isCorrect = true;

            // проверка слов, содержащихся в word2, если word1 правильное
            if (isCorrect && !word2.isEmpty())
            {
                QStringList subWords = word2.split('-');
                for (const QString &subWord : subWords)
                {
                    if (subWord.isEmpty()) continue;

                    if (SpellChecker->CheckWord(subWord.toStdWString()))
                        isCorrect = true;
                    else if (SpellChecker->CheckWord(subWord.toLower().toStdWString()))
                        isCorrect = true;
                    else
                    {
                        isCorrect = false;
                        break;
                    }
                }
            }
        }
        if (!isCorrect)
        {
            misspells.append(qMakePair(startPos, length));

            cursor.setPosition(startPos);
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, length);
            cursor.mergeCharFormat(misspell);
        }

        ++total_words;
    }

    ui->TextField->document()->clearUndoRedoStacks();
}

void MainWindow::MoveToCurrentMisspell()
{
    if (misspells.size() > 0)
    {
        qint32 position = misspells[current_misspell].first;
        qint32 length = misspells[current_misspell].second;

        QTextCursor cursor(ui->TextField->document());
        cursor.setPosition(position);
        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, length);

        ui->TextField->setTextCursor(cursor);
        ui->TextField->ensureCursorVisible();
    }
    else
    {
        QTextCursor cursor(ui->TextField->document());
        cursor.movePosition(QTextCursor::End);
        ui->TextField->setTextCursor(cursor);
    }
}

void MainWindow::ActualizeNavigation()
{
    QString curr_miss_str;
    if (misspells.size() > 0)
        curr_miss_str = QString::number(current_misspell + 1);
    else
        curr_miss_str = "0";

    ui->Label_CurrentMisspell->setText(LABEL_CURRENTMISSPELL_TEXT + curr_miss_str
                                       + LABEL_CURRENTMISSPELL_OUTOF + QString::number(misspells.count()));
}

void MainWindow::OnCheckButtonClick()
{
    QElapsedTimer timer;
    timer.start();
    if (ui->Selector_HTChain->isChecked())
        SpellChecker->SelectService(Service_type::HashTable_Chain);
    else if (ui->Selector_HTDHash->isChecked())
        SpellChecker->SelectService(Service_type::HashTable_DHash);
    else if (ui->Selector_HTLinear->isChecked())
        SpellChecker->SelectService(Service_type::HashTable_Linear);
    else if (ui->Selector_BF->isChecked())
        SpellChecker->SelectService(Service_type::BloomFilter);

    qint64 load_time = timer.elapsed();
    ui->Label_DictLoadTime->setEnabled(true);
    ui->Label_DictLoadTime->setText(LABEL_DICTLOADTIME_TEXT + QString::number(load_time) + MILLISEC_LITERAL);

    timer.start();
    CheckOrphography();
    qint64 check_time = timer.elapsed();

    if (!ui->TextField->toPlainText().isEmpty())
    {
        for (qint32 i = 0; i < ui->Layout_Statistic->count(); ++i)
        {
            QLayoutItem *item = ui->Layout_Statistic->itemAt(i);
            if (QLabel *label = qobject_cast<QLabel*>(item->widget()))
                label->setEnabled(true);
        }
        for (qint32 i = 0; i < ui->Layout_Navigation->count(); ++i)
        {
            QLayoutItem *item = ui->Layout_Navigation->itemAt(i);
            if (QLabel *label = qobject_cast<QLabel*>(item->widget()))
                label->setEnabled(true);
            else if (QPushButton *button = qobject_cast<QPushButton*>(item->widget()))
                button->setEnabled(true);
        }
    }

    ui->Label_SpellCheckTime->setText(LABEL_SPELLCHECKTIME_TEXT + QString::number(check_time) + MILLISEC_LITERAL);
    ui->Label_TotalWords->setText(LABEL_TOTALWORDS_TEXT + QString::number(total_words));
    ui->Label_MisspellWords->setText(LABEL_MISSPELLWORDS_TEXT + QString::number(misspells.count()));

    current_misspell = 0;
    MoveToCurrentMisspell();
    ActualizeNavigation();
    ui->TextField->setFocus();
}

void MainWindow::OnOpenTxtClick()
{
    QString path = QFileDialog::getOpenFileName(
        this, FILEDIALOG_OPEN_TITLE, "", FILEDIALOG_FILTER_TXT);

    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(
            this, FILEDIALOG_ERROR_TITLE, FILEDIALOG_OPEN_ERROR_MESSAGE);
        return;
    }
    QTextStream t_stream(&file);
    t_stream.setEncoding(QStringConverter::Encoding::Utf8);
    ui->TextField->setPlainText(t_stream.readAll());
    file.close();
}

void MainWindow::OnSaveTxtClick()
{
    if (ui->TextField->toPlainText().isEmpty())
        QMessageBox::information(
            this, FILEDIALOG_SAVE_EMPTYFIELD_TITLE, FILEDIALOG_SAVE_EMPTYFIELD_MESSAGE);

    QString path = QFileDialog::getSaveFileName(
        this, FILEDIALOG_SAVE_TITLE, FILEDIALOG_SAVE_BASEFILENAME, FILEDIALOG_FILTER_TXT);

    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(
            this, FILEDIALOG_ERROR_TITLE, FILEDIALOG_SAVE_ERROR_MESSAGE);
        return;
    }
    QTextStream t_stream(&file);
    t_stream.setEncoding(QStringConverter::Encoding::Utf8);
    t_stream << ui->TextField->toPlainText();
    file.close();
}

void MainWindow::OnPrevMisspellClick()
{
    if (misspells.size() > 0)
    {
        --current_misspell;
        if (current_misspell < 0)
            current_misspell = misspells.count() - 1;

        MoveToCurrentMisspell();
        ActualizeNavigation();
    }
}

void MainWindow::OnNextMisspellClick()
{
    if (misspells.size() > 0)
    {
        ++current_misspell;
        if (current_misspell == misspells.count())
            current_misspell = 0;

        MoveToCurrentMisspell();
        ActualizeNavigation();
    }
}
