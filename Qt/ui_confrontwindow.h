/********************************************************************************
** Form generated from reading UI file 'confrontwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFRONTWINDOW_H
#define UI_CONFRONTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfrontWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *firstPokemonLayout;
    QComboBox *firstPokemonComboBox;
    QLabel *firstPokemonImageLabel;
    QHBoxLayout *typesLayout1;
    QLabel *firstTypeLabel1;
    QLabel *secondTypeLabel1;
    QHBoxLayout *horizontalLayout;
    QPushButton *confrontButton;
    QVBoxLayout *secondPokemonLayout;
    QComboBox *secondPokemonComboBox;
    QLabel *secondPokemonImageLabel;
    QHBoxLayout *typesLayout2;
    QLabel *firstTypeLabel2;
    QLabel *secondTypeLabel2;
    QVBoxLayout *graphLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConfrontWindow)
    {
        if (ConfrontWindow->objectName().isEmpty())
            ConfrontWindow->setObjectName(QString::fromUtf8("ConfrontWindow"));
        ConfrontWindow->resize(1073, 666);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConfrontWindow->sizePolicy().hasHeightForWidth());
        ConfrontWindow->setSizePolicy(sizePolicy);
        ConfrontWindow->setBaseSize(QSize(200, 200));
        centralwidget = new QWidget(ConfrontWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, 0);
        firstPokemonLayout = new QVBoxLayout();
        firstPokemonLayout->setSpacing(10);
        firstPokemonLayout->setObjectName(QString::fromUtf8("firstPokemonLayout"));
        firstPokemonLayout->setContentsMargins(-1, -1, -1, 0);
        firstPokemonComboBox = new QComboBox(centralwidget);
        firstPokemonComboBox->setObjectName(QString::fromUtf8("firstPokemonComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(firstPokemonComboBox->sizePolicy().hasHeightForWidth());
        firstPokemonComboBox->setSizePolicy(sizePolicy1);
        firstPokemonComboBox->setMinimumSize(QSize(250, 25));
        firstPokemonComboBox->setMaximumSize(QSize(250, 25));
        firstPokemonComboBox->setBaseSize(QSize(0, 0));

        firstPokemonLayout->addWidget(firstPokemonComboBox);

        firstPokemonImageLabel = new QLabel(centralwidget);
        firstPokemonImageLabel->setObjectName(QString::fromUtf8("firstPokemonImageLabel"));
        sizePolicy1.setHeightForWidth(firstPokemonImageLabel->sizePolicy().hasHeightForWidth());
        firstPokemonImageLabel->setSizePolicy(sizePolicy1);
        firstPokemonImageLabel->setMinimumSize(QSize(250, 250));
        firstPokemonImageLabel->setMaximumSize(QSize(250, 250));
        firstPokemonImageLabel->setScaledContents(true);

        firstPokemonLayout->addWidget(firstPokemonImageLabel);

        typesLayout1 = new QHBoxLayout();
        typesLayout1->setSpacing(10);
        typesLayout1->setObjectName(QString::fromUtf8("typesLayout1"));
        firstTypeLabel1 = new QLabel(centralwidget);
        firstTypeLabel1->setObjectName(QString::fromUtf8("firstTypeLabel1"));
        firstTypeLabel1->setMinimumSize(QSize(125, 30));
        firstTypeLabel1->setMaximumSize(QSize(125, 30));
        firstTypeLabel1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        firstTypeLabel1->setAlignment(Qt::AlignCenter);

        typesLayout1->addWidget(firstTypeLabel1);

        secondTypeLabel1 = new QLabel(centralwidget);
        secondTypeLabel1->setObjectName(QString::fromUtf8("secondTypeLabel1"));
        secondTypeLabel1->setMinimumSize(QSize(125, 30));
        secondTypeLabel1->setMaximumSize(QSize(125, 30));
        secondTypeLabel1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        secondTypeLabel1->setAlignment(Qt::AlignCenter);

        typesLayout1->addWidget(secondTypeLabel1);


        firstPokemonLayout->addLayout(typesLayout1);


        horizontalLayout_2->addLayout(firstPokemonLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        confrontButton = new QPushButton(centralwidget);
        confrontButton->setObjectName(QString::fromUtf8("confrontButton"));
        sizePolicy1.setHeightForWidth(confrontButton->sizePolicy().hasHeightForWidth());
        confrontButton->setSizePolicy(sizePolicy1);
        confrontButton->setMinimumSize(QSize(200, 30));
        confrontButton->setMaximumSize(QSize(200, 30));

        horizontalLayout->addWidget(confrontButton);


        horizontalLayout_2->addLayout(horizontalLayout);

        secondPokemonLayout = new QVBoxLayout();
        secondPokemonLayout->setSpacing(10);
        secondPokemonLayout->setObjectName(QString::fromUtf8("secondPokemonLayout"));
        secondPokemonLayout->setContentsMargins(-1, -1, -1, 0);
        secondPokemonComboBox = new QComboBox(centralwidget);
        secondPokemonComboBox->setObjectName(QString::fromUtf8("secondPokemonComboBox"));
        sizePolicy1.setHeightForWidth(secondPokemonComboBox->sizePolicy().hasHeightForWidth());
        secondPokemonComboBox->setSizePolicy(sizePolicy1);
        secondPokemonComboBox->setMinimumSize(QSize(250, 25));
        secondPokemonComboBox->setMaximumSize(QSize(250, 25));

        secondPokemonLayout->addWidget(secondPokemonComboBox);

        secondPokemonImageLabel = new QLabel(centralwidget);
        secondPokemonImageLabel->setObjectName(QString::fromUtf8("secondPokemonImageLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(secondPokemonImageLabel->sizePolicy().hasHeightForWidth());
        secondPokemonImageLabel->setSizePolicy(sizePolicy2);
        secondPokemonImageLabel->setMinimumSize(QSize(250, 250));
        secondPokemonImageLabel->setMaximumSize(QSize(250, 250));
        secondPokemonImageLabel->setScaledContents(true);

        secondPokemonLayout->addWidget(secondPokemonImageLabel);

        typesLayout2 = new QHBoxLayout();
        typesLayout2->setSpacing(10);
        typesLayout2->setObjectName(QString::fromUtf8("typesLayout2"));
        firstTypeLabel2 = new QLabel(centralwidget);
        firstTypeLabel2->setObjectName(QString::fromUtf8("firstTypeLabel2"));
        firstTypeLabel2->setMinimumSize(QSize(125, 30));
        firstTypeLabel2->setMaximumSize(QSize(125, 30));
        firstTypeLabel2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        firstTypeLabel2->setAlignment(Qt::AlignCenter);

        typesLayout2->addWidget(firstTypeLabel2);

        secondTypeLabel2 = new QLabel(centralwidget);
        secondTypeLabel2->setObjectName(QString::fromUtf8("secondTypeLabel2"));
        secondTypeLabel2->setMinimumSize(QSize(125, 30));
        secondTypeLabel2->setMaximumSize(QSize(125, 30));
        secondTypeLabel2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        secondTypeLabel2->setAlignment(Qt::AlignCenter);

        typesLayout2->addWidget(secondTypeLabel2);


        secondPokemonLayout->addLayout(typesLayout2);


        horizontalLayout_2->addLayout(secondPokemonLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        graphLayout = new QVBoxLayout();
        graphLayout->setObjectName(QString::fromUtf8("graphLayout"));

        verticalLayout->addLayout(graphLayout);


        verticalLayout_2->addLayout(verticalLayout);

        ConfrontWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConfrontWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1073, 22));
        ConfrontWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ConfrontWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ConfrontWindow->setStatusBar(statusbar);

        retranslateUi(ConfrontWindow);

        QMetaObject::connectSlotsByName(ConfrontWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConfrontWindow)
    {
        ConfrontWindow->setWindowTitle(QApplication::translate("ConfrontWindow", "ConfrontWIndow", nullptr));
        firstPokemonImageLabel->setText(QApplication::translate("ConfrontWindow", "Image 1", nullptr));
        firstTypeLabel1->setText(QApplication::translate("ConfrontWindow", "TextLabel", nullptr));
        secondTypeLabel1->setText(QApplication::translate("ConfrontWindow", "TextLabel", nullptr));
        confrontButton->setText(QApplication::translate("ConfrontWindow", "Confronta", nullptr));
        secondPokemonImageLabel->setText(QApplication::translate("ConfrontWindow", "Image 2", nullptr));
        firstTypeLabel2->setText(QApplication::translate("ConfrontWindow", "TextLabel", nullptr));
        secondTypeLabel2->setText(QApplication::translate("ConfrontWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfrontWindow: public Ui_ConfrontWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFRONTWINDOW_H
