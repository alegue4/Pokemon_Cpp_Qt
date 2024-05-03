/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *pokedex_layout;
    QTableWidget *pokedex_table;
    QHBoxLayout *filter_layout;
    QLineEdit *first_type_edit;
    QLineEdit *second_type_edit;
    QPushButton *filterButton;
    QHBoxLayout *reset_generate_layout;
    QPushButton *resetTableButton;
    QPushButton *openConfrontButton;
    QHBoxLayout *ordinamentoLayout;
    QPushButton *attivaOrdinButton;
    QPushButton *disattivaOrdinButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1115, 1050);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        pokedex_layout = new QHBoxLayout();
        pokedex_layout->setObjectName(QString::fromUtf8("pokedex_layout"));
        pokedex_table = new QTableWidget(centralwidget);
        if (pokedex_table->columnCount() < 11)
            pokedex_table->setColumnCount(11);
        pokedex_table->setObjectName(QString::fromUtf8("pokedex_table"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pokedex_table->sizePolicy().hasHeightForWidth());
        pokedex_table->setSizePolicy(sizePolicy);
        pokedex_table->setMinimumSize(QSize(700, 500));
        pokedex_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        pokedex_table->setSortingEnabled(false);
        pokedex_table->setColumnCount(11);

        pokedex_layout->addWidget(pokedex_table);


        verticalLayout->addLayout(pokedex_layout);

        filter_layout = new QHBoxLayout();
        filter_layout->setObjectName(QString::fromUtf8("filter_layout"));
        first_type_edit = new QLineEdit(centralwidget);
        first_type_edit->setObjectName(QString::fromUtf8("first_type_edit"));
        first_type_edit->setAlignment(Qt::AlignCenter);

        filter_layout->addWidget(first_type_edit);

        second_type_edit = new QLineEdit(centralwidget);
        second_type_edit->setObjectName(QString::fromUtf8("second_type_edit"));
        second_type_edit->setAlignment(Qt::AlignCenter);

        filter_layout->addWidget(second_type_edit);

        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        filterButton->setMinimumSize(QSize(200, 0));

        filter_layout->addWidget(filterButton);


        verticalLayout->addLayout(filter_layout);

        reset_generate_layout = new QHBoxLayout();
        reset_generate_layout->setObjectName(QString::fromUtf8("reset_generate_layout"));
        resetTableButton = new QPushButton(centralwidget);
        resetTableButton->setObjectName(QString::fromUtf8("resetTableButton"));
        resetTableButton->setMinimumSize(QSize(200, 0));

        reset_generate_layout->addWidget(resetTableButton);

        openConfrontButton = new QPushButton(centralwidget);
        openConfrontButton->setObjectName(QString::fromUtf8("openConfrontButton"));
        openConfrontButton->setMinimumSize(QSize(200, 0));

        reset_generate_layout->addWidget(openConfrontButton);


        verticalLayout->addLayout(reset_generate_layout);

        ordinamentoLayout = new QHBoxLayout();
        ordinamentoLayout->setObjectName(QString::fromUtf8("ordinamentoLayout"));
        attivaOrdinButton = new QPushButton(centralwidget);
        attivaOrdinButton->setObjectName(QString::fromUtf8("attivaOrdinButton"));
        attivaOrdinButton->setMinimumSize(QSize(200, 0));

        ordinamentoLayout->addWidget(attivaOrdinButton);

        disattivaOrdinButton = new QPushButton(centralwidget);
        disattivaOrdinButton->setObjectName(QString::fromUtf8("disattivaOrdinButton"));
        disattivaOrdinButton->setMinimumSize(QSize(200, 0));

        ordinamentoLayout->addWidget(disattivaOrdinButton);


        verticalLayout->addLayout(ordinamentoLayout);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1115, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        first_type_edit->setPlaceholderText(QApplication::translate("MainWindow", "Inserisci il primo tipo del Pokemon...", nullptr));
        second_type_edit->setPlaceholderText(QApplication::translate("MainWindow", "Inserisci il secondo tipo del Pokemon...", nullptr));
        filterButton->setText(QApplication::translate("MainWindow", "Filtra Pokemon", nullptr));
        resetTableButton->setText(QApplication::translate("MainWindow", "Resetta Tabella", nullptr));
        openConfrontButton->setText(QApplication::translate("MainWindow", "Apri Finestra di Confronto", nullptr));
        attivaOrdinButton->setText(QApplication::translate("MainWindow", "Attiva Funzione di ordinamento", nullptr));
        disattivaOrdinButton->setText(QApplication::translate("MainWindow", "Disattiva Funzione di ordinamento", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
