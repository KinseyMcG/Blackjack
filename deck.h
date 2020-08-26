// Kinsey McGlasson, Program #1

#ifndef INC_1_MCGLASSON_KINSEY_DECK_H
#define INC_1_MCGLASSON_KINSEY_DECK_H

#include <iostream>
#include "hand.h"
#include "player.h"

class deck : public hand {
public:
    void create_deck();
    void shuffle();
    void deal_card(player& p, int num_times);
    void debug_print() const;
};


#endif //INC_1_MCGLASSON_KINSEY_DECK_H
