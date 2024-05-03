#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "confrontwindow.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QList>
#include <QtCharts>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file("pokedex.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    QStringList header = in.readLine().split(','); // Leggi la prima riga (titoli delle colonne)
    header.removeFirst(); // Per rimuovere colonna "img" dalla tabella
    header.removeFirst(); // Per rimuovere colonna "#" dalla tabella
    ui->pokedex_table->setColumnCount(header.size()); // Numero di colonne in base alle informazioni dei Pokémon
    ui->pokedex_table->setHorizontalHeaderLabels(header);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = parseCSVLine(line);
        QPixmap image = (QPixmap) fields[0];
        int id = fields[1].toInt();
        QString name = fields[2];
        QString type = fields[3];
        int total = fields[4].toInt();
        int hp = fields[5].toInt();
        int attack = fields[6].toInt();
        int defense = fields[7].toInt();
        int sp_attack = fields[8].toInt();
        int sp_defense = fields[9].toInt();
        int speed = fields[10].toInt();
        Pokemon p(image, id, name, type, total, hp, attack, defense,
                  sp_attack, sp_defense, speed);
        listaPokemon.append(p);
    }
    file.close();

    ui->pokedex_table->setSortingEnabled(false);
    ui->pokedex_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->disattivaOrdinButton->setEnabled(false);
    populateTable(listaPokemon);


    this->setMinimumSize(1200, 700);

    // Ottieni la geometria disponibile del desktop
    QRect desktopGeometry = QApplication::desktop()->availableGeometry();

    // Calcola le coordinate x e y per centrare la finestra
    int x = desktopGeometry.width() / 2 - width() / 2;
    int y = desktopGeometry.height() / 2 - height() / 2;

    // Imposta la posizione centrata
    move(x, y);

}

MainWindow::~MainWindow()
{
    delete ui;
}


QStringList MainWindow::parseCSVLine(const QString& line) {
    QStringList fields;

    QString current_field;
    bool inside_quotes = false;

    for (int i = 0; i < line.size(); ++i) {
        const QChar& current_char = line.at(i);

        if (current_char == '"') {
            inside_quotes = !inside_quotes;
            // Controlla se abbiamo incontrato un doppio apice, quindi scorre fino al prossimo doppio apice
            if (line.at(i + 1) == '"') {
                current_field += '"';
                ++i; // Salta il prossimo doppio apice
            }
        } else if (current_char == ',' && !inside_quotes) {
            // Se troviamo una virgola e non siamo all'interno di virgolette, il campo è completo
            fields.append(current_field);
            current_field.clear();
        } else {
            // Altrimenti aggiungi il carattere al campo corrente
            current_field += current_char;
        }
    }

    // Aggiungi l'ultimo campo alla lista
    fields.append(current_field);

    return fields;
}

void MainWindow::populateTable(const QList<Pokemon> &pokemonList) {
    // Imposta il numero di righe e colonne nella QTableWidget
    ui->pokedex_table->setRowCount(pokemonList.size());
    ui->pokedex_table->setColumnCount(9); // Numero di colonne in base alle informazioni dei Pokémon

    // Popola la QTableWidget con i dati dei Pokémon
    for (int row = 0; row < pokemonList.size(); ++row) {
        const Pokemon &currentPokemon = pokemonList.at(row);

        // Inserisci le informazioni del Pokémon nelle celle della tabella
        ui->pokedex_table->setItem(row, 0, new QTableWidgetItem(currentPokemon.name));
        ui->pokedex_table->item(row, 0)->setTextAlignment(Qt::AlignCenter);
        ui->pokedex_table->item(row, 0)->setTextColor(QColor(Qt::blue));

        ui->pokedex_table->setItem(row, 1, new QTableWidgetItem(currentPokemon.type));
        ui->pokedex_table->item(row, 1)->setTextAlignment(Qt::AlignCenter);

        // Serve per considerare il valore come un intero nell'ordinamento
        QString totalString = QString("%1").arg(currentPokemon.total, 5);  // 5 è la larghezza del campo numerico
        ui->pokedex_table->setItem(row, 2, new QTableWidgetItem(totalString));
        ui->pokedex_table->item(row, 2)->setTextAlignment(Qt::AlignCenter);
        QFont boldFont = ui->pokedex_table->item(row, 2)->font();
        boldFont.setBold(true);
        ui->pokedex_table->item(row, 2)->setFont(boldFont);

        // Serve per considerare il valore come un intero nell'ordinamento
        QString hpString = QString("%1").arg(currentPokemon.hp, 5);  // 5 è la larghezza del campo numerico
        ui->pokedex_table->setItem(row, 3, new QTableWidgetItem(hpString));
        ui->pokedex_table->item(row, 3)->setTextAlignment(Qt::AlignCenter);

        // Serve per considerare il valore come un intero nell'ordinamento
        QString attackString = QString("%1").arg(currentPokemon.attack, 5);  // 5 è la larghezza del campo numerico
        ui->pokedex_table->setItem(row, 4, new QTableWidgetItem(attackString));
        ui->pokedex_table->item(row, 4)->setTextAlignment(Qt::AlignCenter);

        // Serve per considerare il valore come un intero nell'ordinamento
        QString defenseString = QString("%1").arg(currentPokemon.defense, 5);  // 5 è la larghezza del campo numerico
        ui->pokedex_table->setItem(row, 5, new QTableWidgetItem(defenseString));
        ui->pokedex_table->item(row, 5)->setTextAlignment(Qt::AlignCenter);

        // Serve per considerare il valore come un intero nell'ordinamento
        QString spAtkString = QString("%1").arg(currentPokemon.sp_attack, 5);  // 5 è la larghezza del campo numerico
        ui->pokedex_table->setItem(row, 6, new QTableWidgetItem(spAtkString));
        ui->pokedex_table->item(row, 6)->setTextAlignment(Qt::AlignCenter);

        // Serve per considerare il valore come un intero nell'ordinamento
        QString spDefString = QString("%1").arg(currentPokemon.sp_defense, 5);  // 5 è la larghezza del campo numerico
        ui->pokedex_table->setItem(row, 7, new QTableWidgetItem(spDefString));
        ui->pokedex_table->item(row, 7)->setTextAlignment(Qt::AlignCenter);

        // Serve per considerare il valore come un intero nell'ordinamento
        QString speedString = QString("%1").arg(currentPokemon.speed, 5);  // 5 è la larghezza del campo numerico
        ui->pokedex_table->setItem(row, 8, new QTableWidgetItem(speedString));
        ui->pokedex_table->item(row, 8)->setTextAlignment(Qt::AlignCenter);
    }

    ui->pokedex_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}


void MainWindow::on_filterButton_clicked()
{
    QString type1 = ui->first_type_edit->text().trimmed();
    QString type2 = ui->second_type_edit->text().trimmed();

    QList<Pokemon> filteredPokemons;

    if (type1.isEmpty() && type2.isEmpty()) {
        return;
    }

    if (type1 == "," || type2 == ",") {
        ui->first_type_edit->setText("");
        ui->second_type_edit->setText("");
        return;
    }

    int count = 0;
    for (int i = 0; i < listaPokemon.size(); ++i) {
        const Pokemon &currentPokemon = listaPokemon.at(i);
        bool matchesType1 = type1.isEmpty() || currentPokemon.type.contains(type1, Qt::CaseInsensitive);
        bool matchesType2 = type2.isEmpty() || currentPokemon.type.contains(type2, Qt::CaseInsensitive);

        if (matchesType1 && matchesType2) {
            // Il Pokémon contiene entrambi i tipi cercati
            // Aggiungi il Pokémon alla lista filtrata
            filteredPokemons.append(currentPokemon);
            count++;
        }
    }

    if (count > 0) {
        ui->pokedex_table->setSortingEnabled(false);
        ui->attivaOrdinButton->setEnabled(true);
        ui->disattivaOrdinButton->setEnabled(false);
        populateTable(filteredPokemons);
    }

}


void MainWindow::on_resetTableButton_clicked()
{
    ui->first_type_edit->setText("");
    ui->second_type_edit->setText("");
    ui->pokedex_table->setSortingEnabled(false);
    ui->attivaOrdinButton->setEnabled(true);
    ui->disattivaOrdinButton->setEnabled(false);
    populateTable(listaPokemon);
}


void MainWindow::on_openConfrontButton_clicked()
{
    if(listaPokemon.isEmpty())
        return;
    ConfrontWindow *confrontWindow = new ConfrontWindow(this);
    confrontWindow->setListaPokemon(listaPokemon);  // Passa la lista dei Pokémon alla finestra di confronto
    confrontWindow->show();
}

void MainWindow::on_attivaOrdinButton_clicked()
{
    ui->attivaOrdinButton->setEnabled(false);
    ui->disattivaOrdinButton->setEnabled(true);

    ui->pokedex_table->setSortingEnabled(true);
}


void MainWindow::on_disattivaOrdinButton_clicked()
{
    ui->disattivaOrdinButton->setEnabled(false);
    ui->attivaOrdinButton->setEnabled(true);

    ui->pokedex_table->setSortingEnabled(false);
}

