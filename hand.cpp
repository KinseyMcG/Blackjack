// Kinsey McGlasson, Program #1

#include "hand.h"

// Clears hand
void hand::clear() {
    hand.clear();
}

// Adds a card to the vector hand
void hand::add(card card) {
    hand.push_back(card);
}

// Returns int representing hand count total
int hand::get_total() const {
    int total = 0;
    int card_value;

    for (int i = 0; i < hand.size(); i++) {
        card_value = hand[i].get_value();
        if (card_value == 1) {
            if (total < 11) {
                card_value = 11;
            }
        }
        total += card_value;
    }

    return total;
}

// Returns hand
vector<card> hand::get_hand() const {
    return hand;
}
