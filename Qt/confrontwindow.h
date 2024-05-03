#ifndef CONFRONTWINDOW_H
#define CONFRONTWINDOW_H

#include <QMainWindow>

struct Pokemon{
    QPixmap image;
    int id;
    QString name;
    QString type;
    int total;
    int hp;
    int attack;
    int defense;
    int sp_attack;
    int sp_defense;
    int speed;

    Pokemon(QPixmap &image, int id, QString &name, QString &type,
            int total, int hp, int attack, int defense,
            int sp_attack, int sp_defense, int speed) {
        this->image = image;
        this->id = id;
        this->name = name;
        this->type = type;
        this->total = total;
        this->hp = hp;
        this->attack = attack;
        this->defense = defense;
        this->sp_attack = sp_attack;
        this->sp_defense = sp_defense;
        this->speed = speed;
    }

};
namespace Ui {
class ConfrontWindow;
}

class ConfrontWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConfrontWindow(QWidget *parent = nullptr);
    ~ConfrontWindow();
    void setListaPokemon(const QList<Pokemon> &listaPokemon);
    void updatePokemonImages();
    void updateFirstPokemonType();
    void updateSecondPokemonType();
    void updateConfrontButtonState();

private slots:
    void on_firstPokemonComboBox_currentIndexChanged(int index);

    void on_secondPokemonComboBox_currentIndexChanged(int index);

    void on_confrontButton_clicked();

private:
    Ui::ConfrontWindow *ui;
    QList<Pokemon> listaPokemon;
    QPixmap firstPokemonPhoto;
    QPixmap secondPokemonPhoto;
    QString firstPokemonType;
    QString secondPokemonType;
};

#endif // CONFRONTWINDOW_H
