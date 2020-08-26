// Kinsey McGlasson, Program #1

#ifndef INC_1_MCGLASSON_KINSEY_PLAYER_H
#define INC_1_MCGLASSON_KINSEY_PLAYER_H

#include <iostream>
#include "hand.h"
#include "card.h"

using namespace std;


class player : public hand {
public:
    player();
    string get_name() const;
    double get_bank() const;
    bool get_is_busted() const;
    double get_bet() const;

    string set_name(string n);
    double set_bank(double b);
    double set_bet(double b);
    bool set_is_busted(bool bust);

    bool test_bust();
    void print_hand();
    bool player_turn();

protected:
    double bank;
    bool is_busted;
    string name;

private:
    double bet;
};


#endif //INC_1_MCGLASSON_KINSEY_PLAYER_H
