// Kinsey McGlasson, Program #1

#include "card.h"

// Default constructor
card::card() {
    rank = START_RANK;
    suit = START_SUIT;
    is_up = true;
}

// Secondary constructor
card::card(Rank my_r, Suit my_s, bool face_up) {
    rank = my_r;
    suit = my_s;
    is_up = face_up;
}

// Returns blackjack value of card based on rank
int card::get_value() const {
    int value = 0;

    if (rank > 0 && rank < 10)
        value = rank;
    else
        value = 10;

    return value;
}

// Returns is_up
bool card::get_is_up() const {
    return is_up;
}

// Sets new rank
Rank card::set_rank(Rank r) {
    rank = r;
    return rank;
}

// Sets new suit
Suit card::set_suit(Suit s) {
    suit = s;
    return suit;
}

// Sets is_up to true or false
bool card::set_is_up(bool up_or_down) {
    is_up = up_or_down;
    return is_up;
}

// Prints a card in format RankSuit, e.g. 5D for 5 of Diamonds
ostream& operator<<(ostream& os, const card& c) {
    if (c.rank > 1 && c.rank <= 10)
        os << c.rank;

    else if (c.rank > 9) {
        if (c.rank == 11)
            os << 'J';
        else if (c.rank == 12)
            os << 'Q';
        else
            os << 'K';
    }

    else
        os << 'A';


    if (c.suit == 0)
        os << 'C';
    else if (c.suit == 1)
        os << 'D';
    else if (c.suit == 2)
        os << 'S';
    else
        os << 'H';

    return os;
}

