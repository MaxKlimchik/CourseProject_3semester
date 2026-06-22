/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *TextField;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Selector_label;
    QRadioButton *Selector_HTChain;
    QRadioButton *Selector_HTDHash;
    QRadioButton *Selector_HTLinear;
    QRadioButton *Selector_BF;
    QPushButton *Button_CheckOrpho;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button_OpenTxt;
    QPushButton *Button_SaveTxt;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *Layout_Statistic;
    QLabel *Label_LastOrphograhyCheckStatistic;
    QLabel *Label_SpellCheckTime;
    QLabel *Label_TotalWords;
    QLabel *Label_MisspellWords;
    QWidget *formLayoutWidget;
    QFormLayout *Layout_Navigation;
    QLabel *Label_MisspellNavigation;
    QLabel *Label_CurrentMisspell;
    QPushButton *Button_PrevMisspell;
    QPushButton *Button_NextMisspell;
    QLabel *Label_DictLoadTime;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1066, 625);
        MainWindow->setMinimumSize(QSize(1066, 625));
        MainWindow->setMaximumSize(QSize(1066, 625));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        TextField = new QTextEdit(centralwidget);
        TextField->setObjectName("TextField");
        TextField->setGeometry(QRect(10, 70, 721, 501));
        QFont font;
        font.setPointSize(11);
        TextField->setFont(font);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(740, 10, 311, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Selector_label = new QLabel(verticalLayoutWidget);
        Selector_label->setObjectName("Selector_label");
        Selector_label->setFont(font);
        Selector_label->setAcceptDrops(false);
        Selector_label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Selector_label->setTextFormat(Qt::TextFormat::AutoText);
        Selector_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Selector_label->setWordWrap(true);

        verticalLayout->addWidget(Selector_label);

        Selector_HTChain = new QRadioButton(verticalLayoutWidget);
        Selector_HTChain->setObjectName("Selector_HTChain");
        Selector_HTChain->setFont(font);

        verticalLayout->addWidget(Selector_HTChain);

        Selector_HTDHash = new QRadioButton(verticalLayoutWidget);
        Selector_HTDHash->setObjectName("Selector_HTDHash");
        Selector_HTDHash->setFont(font);

        verticalLayout->addWidget(Selector_HTDHash);

        Selector_HTLinear = new QRadioButton(verticalLayoutWidget);
        Selector_HTLinear->setObjectName("Selector_HTLinear");
        Selector_HTLinear->setFont(font);

        verticalLayout->addWidget(Selector_HTLinear);

        Selector_BF = new QRadioButton(verticalLayoutWidget);
        Selector_BF->setObjectName("Selector_BF");
        Selector_BF->setFont(font);

        verticalLayout->addWidget(Selector_BF);

        Button_CheckOrpho = new QPushButton(centralwidget);
        Button_CheckOrpho->setObjectName("Button_CheckOrpho");
        Button_CheckOrpho->setGeometry(QRect(740, 200, 311, 49));
        Button_CheckOrpho->setFont(font);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 261, 59));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Button_OpenTxt = new QPushButton(horizontalLayoutWidget);
        Button_OpenTxt->setObjectName("Button_OpenTxt");
        Button_OpenTxt->setFont(font);

        horizontalLayout->addWidget(Button_OpenTxt);

        Button_SaveTxt = new QPushButton(horizontalLayoutWidget);
        Button_SaveTxt->setObjectName("Button_SaveTxt");
        Button_SaveTxt->setFont(font);

        horizontalLayout->addWidget(Button_SaveTxt);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(740, 290, 311, 141));
        Layout_Statistic = new QVBoxLayout(verticalLayoutWidget_2);
        Layout_Statistic->setSpacing(2);
        Layout_Statistic->setObjectName("Layout_Statistic");
        Layout_Statistic->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        Layout_Statistic->setContentsMargins(0, 0, 0, 0);
        Label_LastOrphograhyCheckStatistic = new QLabel(verticalLayoutWidget_2);
        Label_LastOrphograhyCheckStatistic->setObjectName("Label_LastOrphograhyCheckStatistic");
        Label_LastOrphograhyCheckStatistic->setEnabled(false);
        Label_LastOrphograhyCheckStatistic->setFont(font);
        Label_LastOrphograhyCheckStatistic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        Layout_Statistic->addWidget(Label_LastOrphograhyCheckStatistic);

        Label_SpellCheckTime = new QLabel(verticalLayoutWidget_2);
        Label_SpellCheckTime->setObjectName("Label_SpellCheckTime");
        Label_SpellCheckTime->setEnabled(false);
        Label_SpellCheckTime->setMaximumSize(QSize(16777215, 24));
        Label_SpellCheckTime->setFont(font);

        Layout_Statistic->addWidget(Label_SpellCheckTime);

        Label_TotalWords = new QLabel(verticalLayoutWidget_2);
        Label_TotalWords->setObjectName("Label_TotalWords");
        Label_TotalWords->setEnabled(false);
        Label_TotalWords->setMaximumSize(QSize(16777215, 24));
        Label_TotalWords->setFont(font);

        Layout_Statistic->addWidget(Label_TotalWords);

        Label_MisspellWords = new QLabel(verticalLayoutWidget_2);
        Label_MisspellWords->setObjectName("Label_MisspellWords");
        Label_MisspellWords->setEnabled(false);
        Label_MisspellWords->setMaximumSize(QSize(16777215, 24));
        Label_MisspellWords->setFont(font);

        Layout_Statistic->addWidget(Label_MisspellWords);

        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(740, 440, 311, 122));
        Layout_Navigation = new QFormLayout(formLayoutWidget);
        Layout_Navigation->setObjectName("Layout_Navigation");
        Layout_Navigation->setHorizontalSpacing(7);
        Layout_Navigation->setContentsMargins(0, 0, 0, 0);
        Label_MisspellNavigation = new QLabel(formLayoutWidget);
        Label_MisspellNavigation->setObjectName("Label_MisspellNavigation");
        Label_MisspellNavigation->setEnabled(false);
        Label_MisspellNavigation->setMinimumSize(QSize(0, 32));
        Label_MisspellNavigation->setFont(font);
        Label_MisspellNavigation->setAlignment(Qt::AlignmentFlag::AlignCenter);

        Layout_Navigation->setWidget(0, QFormLayout::ItemRole::SpanningRole, Label_MisspellNavigation);

        Label_CurrentMisspell = new QLabel(formLayoutWidget);
        Label_CurrentMisspell->setObjectName("Label_CurrentMisspell");
        Label_CurrentMisspell->setEnabled(false);
        Label_CurrentMisspell->setMinimumSize(QSize(0, 32));
        Label_CurrentMisspell->setFont(font);

        Layout_Navigation->setWidget(1, QFormLayout::ItemRole::SpanningRole, Label_CurrentMisspell);

        Button_PrevMisspell = new QPushButton(formLayoutWidget);
        Button_PrevMisspell->setObjectName("Button_PrevMisspell");
        Button_PrevMisspell->setEnabled(false);
        Button_PrevMisspell->setMinimumSize(QSize(151, 42));
        Button_PrevMisspell->setFont(font);

        Layout_Navigation->setWidget(2, QFormLayout::ItemRole::LabelRole, Button_PrevMisspell);

        Button_NextMisspell = new QPushButton(formLayoutWidget);
        Button_NextMisspell->setObjectName("Button_NextMisspell");
        Button_NextMisspell->setEnabled(false);
        Button_NextMisspell->setMinimumSize(QSize(131, 42));
        Button_NextMisspell->setFont(font);

        Layout_Navigation->setWidget(2, QFormLayout::ItemRole::FieldRole, Button_NextMisspell);

        Label_DictLoadTime = new QLabel(centralwidget);
        Label_DictLoadTime->setObjectName("Label_DictLoadTime");
        Label_DictLoadTime->setEnabled(false);
        Label_DictLoadTime->setGeometry(QRect(740, 250, 311, 31));
        Label_DictLoadTime->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1066, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\270\321\201 \320\277\320\276 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\265 \320\276\321\200\321\204\320\276\320\263\321\200\320\260\321\204\320\270\320\270", nullptr));
        Selector_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\241\320\277\320\276\321\201\320\276\320\261 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270<br/>\320\276\321\200\321\204\320\276\320\263\321\200\320\260\321\204\320\270\320\270</p></body></html>", nullptr));
        Selector_HTChain->setText(QCoreApplication::translate("MainWindow", "\320\245\320\265\321\210-\321\202\320\260\320\261\320\273\320\270\321\206\320\260 (\320\234\320\265\321\202\320\276\320\264 \321\206\320\265\320\277\320\276\321\207\320\265\320\272)", nullptr));
        Selector_HTDHash->setText(QCoreApplication::translate("MainWindow", "\320\245\320\265\321\210-\321\202\320\260\320\261\320\273\320\270\321\206\320\260 (\320\224\320\262\320\276\320\271\320\275\320\276\320\265 \321\205\320\265\321\210\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265)", nullptr));
        Selector_HTLinear->setText(QCoreApplication::translate("MainWindow", "\320\245\320\265\321\210-\321\202\320\260\320\261\320\273\320\270\321\206\320\260 (\320\233\320\270\320\275\320\265\320\271\320\275\320\276\320\265 \320\277\321\200\320\276\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265)", nullptr));
        Selector_BF->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\221\320\273\321\203\320\274\320\260", nullptr));
        Button_CheckOrpho->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214\n"
"\320\276\321\200\321\204\320\276\320\263\321\200\320\260\321\204\320\270\321\216", nullptr));
        Button_OpenTxt->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214\n"
"\321\204\320\260\320\271\320\273 (.txt)", nullptr));
        Button_SaveTxt->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214\n"
"\320\262 \321\204\320\260\320\271\320\273 (.txt)", nullptr));
        Label_LastOrphograhyCheckStatistic->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\271\n"
"\320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270", nullptr));
        Label_SpellCheckTime->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217: 0 \320\274\321\201.", nullptr));
        Label_TotalWords->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265\320\263\320\276 \321\201\320\273\320\276\320\262: 0", nullptr));
        Label_MisspellWords->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\217\320\262\320\273\320\265\320\275\320\276 \320\276\321\210\320\270\320\261\320\276\320\272: 0", nullptr));
        Label_MisspellNavigation->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\262\320\270\320\263\320\260\321\206\320\270\321\217 \320\277\320\276 \320\276\321\210\320\270\320\261\320\272\320\260\320\274", nullptr));
        Label_CurrentMisspell->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\276\321\210\320\270\320\261\320\272\320\260: 0 \320\270\320\267 0", nullptr));
        Button_PrevMisspell->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264.", nullptr));
        Button_NextMisspell->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264.", nullptr));
        Label_DictLoadTime->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \321\201\320\273\320\276\320\262\320\260\321\200\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
