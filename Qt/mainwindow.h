#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "confrontwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringList parseCSVLine(const QString& line);
    void populateTable(const QList<Pokemon> &pokemonList);

private slots:
    void on_filterButton_clicked();
    void on_resetTableButton_clicked();
    void on_openConfrontButton_clicked();

    void on_attivaOrdinButton_clicked();

    void on_disattivaOrdinButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<Pokemon> listaPokemon;
};
#endif // MAINWINDOW_H
