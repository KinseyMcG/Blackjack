// Kinsey McGlasson, Program #1

#ifndef INC_1_MCGLASSON_KINSEY_HAND_H
#define INC_1_MCGLASSON_KINSEY_HAND_H

#include <iostream>
#include "card.h"
#include <vector>

using namespace std;


class hand {
public:
    void clear();
    void add(card card);
    int get_total() const;
    vector<card> get_hand() const;

protected:
    vector<card> hand;
};


#endif //INC_1_MCGLASSON_KINSEY_HAND_H
