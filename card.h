// Kinsey McGlasson, Program #1

#ifndef INC_1_MCGLASSON_KINSEY_CARD_H
#define INC_1_MCGLASSON_KINSEY_CARD_H

#include <iostream>
using namespace std;

enum Rank {Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
const Rank START_RANK = Ace;
const Rank END_RANK = King;
enum Suit {Clubs, Diamonds, Spades, Hearts};
const Suit START_SUIT = Clubs;
const Suit END_SUIT = Hearts;

class card {
public:
    card();
    card(Rank my_r, Suit my_s, bool face_up);
    int get_value() const;
    bool get_is_up() const;
    Rank set_rank(Rank r);
    Suit set_suit(Suit s);
    bool set_is_up(bool up_or_down);
    friend ostream& operator <<(ostream& out, const card& c);

private:
    Rank rank;
    Suit suit;
    bool is_up;
};


#endif //INC_1_MCGLASSON_KINSEY_CARD_H
