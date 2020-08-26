// Kinsey McGlasson, Program #1

#include <iostream>
#include "deck.h"
#include <random>

// Creates an ordered deck of 52 cards and stores in vector hand
void deck::create_deck() {
    for (int i = 1; i != 14; ++i) {                      // Loops through Rank and Suit, adds each card to vec hand
        for (int j = 0; j != 4; ++j) {                   // for a total of 52 unique cards
            Rank rank = static_cast<Rank>(i);
            Suit suit = static_cast<Suit>(j);
            card c(rank, suit, true);
            add(c);
        }
    }
}

// Shuffles deck created in function above
void deck::shuffle() {
    mt19937 r{random_device{}()};                   // Ensures random shuffle each call
    ::shuffle(hand.begin(), hand.end(), r);
}

// Deals cards (num dealt determined by num_times) from the top of the deck
void deck::deal_card(player& p, int num_times) {
    int empty_deal_calls = 0;                        // <- Stores num times deal is called when deck is empty
                                                     // to make sure cout statements are not repeated w/each call

    if (hand.size() == 0) {                                            // In case deck is empty when deal is called
        empty_deal_calls++;
        if (empty_deal_calls == 1) {
            cout << "Deck depleted. Game over!" << endl << endl;
            cout << "Thanks for playing! Come again soon!" << endl;
        }
    }

    //
    for (int i = 0; i < num_times; i++) {

        if (num_times == 2 && i == 0)                // Sets is_up to false for 1st card dealt to each player at
            hand[0].set_is_up(false);                // start of round, so that [??] is printed instead of card

        p.add(hand[0]);                                 // Adds first card in deck to player hand
        hand.erase(hand.begin());                           // Erases card copy in deck
    }
}

// Prints deck to check that it was created correctly
void deck::debug_print() const {
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i] << " ";
    }
    cout << endl << endl;
}