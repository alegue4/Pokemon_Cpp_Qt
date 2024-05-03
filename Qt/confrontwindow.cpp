#include "confrontwindow.h"
#include "ui_confrontwindow.h"
#include <QtCharts>
#include <QDesktopWidget>

ConfrontWindow::ConfrontWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfrontWindow)
{
    ui->setupUi(this);

    // Connessioni per aggiornare lo stato del pulsante al cambiamento delle combo box
    connect(ui->firstPokemonComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_firstPokemonComboBox_currentIndexChanged(int)));
    connect(ui->secondPokemonComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_secondPokemonComboBox_currentIndexChanged(int)));

    this->resize(770, 770);

    // Ottieni la geometria disponibile del desktop
    QRect desktopGeometry = QApplication::desktop()->availableGeometry();

    // Calcola le coordinate x e y per centrare la finestra
    int x = desktopGeometry.width() / 2 - width() / 2;
    int y = desktopGeometry.height() / 2 - height() / 2;

    // Imposta la posizione centrata
    move(x, y);
}

ConfrontWindow::~ConfrontWindow()
{
    delete ui;
}

void ConfrontWindow::setListaPokemon(const QList<Pokemon> &listaPokemon)
{
    if(listaPokemon.isEmpty())
        return;
    this->listaPokemon = listaPokemon;
    // Popola le combo box con i nomi dei Pokémon
    for (const Pokemon &pokemon : listaPokemon) {
        ui->firstPokemonComboBox->addItem(pokemon.name);
        ui->secondPokemonComboBox->addItem(pokemon.name);
    }
}

void ConfrontWindow::on_firstPokemonComboBox_currentIndexChanged(int index)
{
    if (index >= 0 && index < listaPokemon.size()) {
        firstPokemonPhoto = listaPokemon[index].image;
        firstPokemonType = listaPokemon[index].type;
        updatePokemonImages();
        updateFirstPokemonType();
        updateConfrontButtonState();
    }
}

void ConfrontWindow::on_secondPokemonComboBox_currentIndexChanged(int index)
{
    if (index >= 0 && index < listaPokemon.size()) {
        secondPokemonPhoto = listaPokemon[index].image;
        secondPokemonType = listaPokemon[index].type;
        updatePokemonImages();
        updateSecondPokemonType();
        updateConfrontButtonState();
    }
}

void ConfrontWindow::updatePokemonImages()
{
    ui->firstPokemonImageLabel->setPixmap(firstPokemonPhoto);
    ui->secondPokemonImageLabel->setPixmap(secondPokemonPhoto);
}

void setLabelBackgroundColor(QLabel *label, const QString &type)
{
    // Mappa che contiene colori di sfondo per ogni tipo
    QMap<QString, QColor> typeColors;
    typeColors["Normal"] = QColor(145, 145, 108);
    typeColors["Steel"] = QColor(194, 191, 184);
    typeColors["Fire"] = QColor(250, 80, 67);
    typeColors["Water"] = QColor(66, 139, 235);
    typeColors["Electric"] = QColor(242, 242, 2);
    typeColors["Grass"] = QColor(120, 200, 80);
    typeColors["Ice"] = QColor(116, 209, 252);
    typeColors["Poison"] = QColor(206, 66, 245);
    typeColors["Flying"] = QColor(132, 143, 194);
    typeColors["Fighting"] = QColor(181, 10, 4);
    typeColors["Bug"] = QColor(127, 161, 42);
    typeColors["Dragon"] = QColor(128, 11, 224);
    typeColors["Dark"] = QColor(66, 66, 66);
    typeColors["Psychic"] = QColor(250, 85, 233);
    typeColors["Ground"] = QColor(217, 190, 115);
    typeColors["Fairy"] = QColor(250, 170, 241);
    typeColors["Rock"] = QColor(153, 144, 75);
    typeColors["Ghost"] = QColor(79, 29, 115);

    // Imposta il colore di sfondo della label
    label->setAutoFillBackground(true);
    QPalette palette = label->palette();
    palette.setColor(QPalette::Window, typeColors.value(type, Qt::white)); // Restituisce il colore corrispondente o bianco se il tipo non è definito
    label->setPalette(palette);
}

void ConfrontWindow::updateFirstPokemonType()
{
    if(firstPokemonType.contains(",")) {
        ui->secondTypeLabel1->setVisible(true);
        QStringList typeList = firstPokemonType.split(",");

       // Ora puoi accedere ai tipi separati
       QString firstType = typeList.at(0).trimmed();  // Rimuovi eventuali spazi
       QString secondType = typeList.at(1).trimmed(); // Rimuovi eventuali spazi

       // Fai qualcosa con i due tipi (ad esempio, assegnali a QLabel)
       ui->firstTypeLabel1->setText(firstType);
       ui->secondTypeLabel1->setText(secondType);

       // Imposta lo sfondo personalizzato in base al tipo
       setLabelBackgroundColor(ui->firstTypeLabel1, firstType);
       setLabelBackgroundColor(ui->secondTypeLabel1, secondType);

    } else {
       ui->firstTypeLabel1->setText(firstPokemonType);
       setLabelBackgroundColor(ui->firstTypeLabel1, firstPokemonType);
       ui->secondTypeLabel1->setVisible(false);
    }
}

void ConfrontWindow::updateSecondPokemonType()
{
    if(secondPokemonType.contains(",")) {
        ui->secondTypeLabel2->setVisible(true);
        QStringList typeList = secondPokemonType.split(",");

       // Ora puoi accedere ai tipi separati
       QString firstType = typeList.at(0).trimmed();  // Rimuovi eventuali spazi
       QString secondType = typeList.at(1).trimmed(); // Rimuovi eventuali spazi

       // Fai qualcosa con i due tipi (ad esempio, assegnali a QLabel)
       ui->firstTypeLabel2->setText(firstType);
       ui->secondTypeLabel2->setText(secondType);

       // Imposta lo sfondo personalizzato in base al tipo
       setLabelBackgroundColor(ui->firstTypeLabel2, firstType);
       setLabelBackgroundColor(ui->secondTypeLabel2, secondType);

    } else {
       ui->firstTypeLabel2->setText(secondPokemonType);
       setLabelBackgroundColor(ui->firstTypeLabel2, secondPokemonType);
       ui->secondTypeLabel2->setVisible(false);
    }
}



void ConfrontWindow::updateConfrontButtonState()
{
    // Abilita il pulsante se i Pokémon selezionati sono diversi, altrimenti disabilita
    ui->confrontButton->setEnabled(ui->firstPokemonComboBox->currentIndex() != ui->secondPokemonComboBox->currentIndex());
}

void ConfrontWindow::on_confrontButton_clicked()
{
    // Rimuovi il grafico precedente, se presente
    QLayoutItem *item;
    while ((item = ui->graphLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    // Recupera i dati dei due Pokémon selezionati
    int firstIndex = ui->firstPokemonComboBox->currentIndex();
    int secondIndex = ui->secondPokemonComboBox->currentIndex();

    if (firstIndex >= 0 && secondIndex >= 0) {
        const Pokemon &firstPokemon = listaPokemon[firstIndex];
        const Pokemon &secondPokemon = listaPokemon[secondIndex];

        QBarSeries *series = new QBarSeries();

        QBarSet *set1 = new QBarSet(firstPokemon.name);
        QBarSet *set2 = new QBarSet(secondPokemon.name);

        // Aggiungi le statistiche per Pokemon 1
        *set1 << firstPokemon.total << firstPokemon.hp << firstPokemon.attack
              << firstPokemon.defense << firstPokemon.sp_attack
              << firstPokemon.sp_defense << firstPokemon.speed;

        // Aggiungi le statistiche per Pokemon 2
        *set2 << secondPokemon.total << secondPokemon.hp << secondPokemon.attack
             << secondPokemon.defense << secondPokemon.sp_attack
             << secondPokemon.sp_defense << secondPokemon.speed;

        series->append(set1);
        series->append(set2);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Confronto Statistiche Pokemon");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "Total" << "HP" << "Atk" << "Def" << "Sp. Atk" << "Sp. Def" << "Speed";

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axisX, series);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(750, 750);

        //Aggiungi QChartView al layout del tuo frame
        ui->graphLayout->addWidget(chartView);
        ui->graphLayout->update();
    }
}

