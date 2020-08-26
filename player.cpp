// Kinsey McGlasson, Program #1

#include "player.h"

// Default constructor
player::player () {
    name = "Betsy";
    bank = 100;
    is_busted = false;
}

// Returns name
string player::get_name() const {
    return name;
}

// Returns bank
double player::get_bank() const {
    return bank;
}

// Returns is_busted
bool player::get_is_busted() const {
    return is_busted;
}

// Returns bet
double player::get_bet() const {
    return bet;
}

// Sets name to n
string player::set_name(string n) {
    name = n;
    return name;
}

// Sets bank to b
double player::set_bank(double b) {
    bank = b;
    return bank;
}

// Sets bet to b
double player::set_bet(double b) {
    bet = b;
    return bet;
}

// Sets is_busted to bust
bool player::set_is_busted(bool bust) {
    is_busted = bust;
    return is_busted;
}

// Tests if player has busted
bool player::test_bust() {
    if (get_total() > 21) {
        is_busted = true;
        cout << "Bust!" << endl << endl;
    }
    return is_busted;
}

// Prints out a player's hand in the format [3D][7H][KS]...
void player::print_hand() {
    cout << name << "'s current hand: ";
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].get_is_up()) {
            cout << "[" << hand[i] << "]";
        }
        else {
            hand[i].set_is_up(true);
            cout << "[??]";
        }
    }
}

// Calls print_hand and displays total pts in player's hand, then handles draw/stay decision by return bool
bool player::player_turn() {
    print_hand();
    cout << " (" << get_total() << " points)" << endl;

    if (!test_bust()) {                                                         // If player's hand total <= 21:
        string draw;
        cout << "Would you like to draw another card? (Y or N) ";
        cin >> draw;

        while (draw != "Y" && draw != "N") {                                            // Input test
            cout << "Error. Invalid input. Please enter a 'Y' or an 'N': " << endl;
            cin >> draw;
        }
        if (draw == "Y") {
            cout << name << " chooses to draw" << endl;
            return true;
        }
        else {
            cout << name << " chooses to stay" << endl;
            return false;
        }
    }
    else                                                                        // If player's hand total > 21:
        return false;
}