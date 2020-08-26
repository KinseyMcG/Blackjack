// Kinsey McGlasson, Program #1

#include <iostream>
#include "card.h"
#include "hand.h"
#include "deck.h"
#include "dealer.h"

using namespace std;

// Displays Blackjack rules
void rules ()   {
    cout << "How to Play: " << endl << endl;
    cout << "   Each player is dealt two cards by the house. Each card has a point value." << endl
         << "   Each player tries to reach a total of 21 points without going over." << endl
         << "   The point values are as follows: " << endl << endl
         << "       The number on the card represents its value." << endl
         << "       The value of a Jack, Queen, or King is 10." << endl
         << "       The value of an Ace is either 1 or 11, depending on whichever is best for the player." << endl << endl
         << "   Players do not play against each other, they play against the house." << endl;
}

// Takes returned bool from player_turn() and deals a card to player if bool == true
void draw (player& p, deck& d1) {
    bool draw = true;
    while (draw) {
        draw = p.player_turn();             // Set draw to bool value returned by player_turn()
        if (draw)                       // Prevent extra card from being drawn after player_turn() set to false
            d1.deal_card(p, 1);
    }
}

// Compares hand totals and determines the winner(s)
void winner (player& p1, player& p2, dealer& house) {
    if (p1.get_total() <= house.get_total() && house.get_total() <= 21) {
        p1.set_is_busted(true);
    }

    if (p2.get_total() <= house.get_total() && house.get_total() <= 21) {
        p2.set_is_busted(true);
    }

    if (p1.get_total() < p2.get_total() && p2.get_total() <= 21) {
        p1.set_is_busted(true);
    }

    if (p2.get_total() < p1.get_total() && p2.get_total() <= 21) {
        p2.set_is_busted(true);
    }

}

// Keeps track of player wins/losses and house gains/losses
void results (player& p, dealer& house) {
    if (p.get_is_busted()) {
        cout << p.get_name() << " loses $" << p.get_bet() << endl;
        p.set_bank(p.get_bank() - p.get_bet());                         // Subtract lost money from player bank
        house.set_bank(house.get_bank() + p.get_bet());                 // Add lost player money to dealer bank
    }
    else {
        cout << p.get_name() << " wins $" << p.get_bet() << endl;
        p.set_bank(p.get_bank() + p.get_bet());                         // Add won money to player bank
        house.set_bank(house.get_bank() - p.get_bet());                 // Subtract won player money from dealer bank
    }
}

// Resets hands and is_busted for all players
void reset_round (player& p1, player& p2, dealer& house, deck& d1) {
    p1.clear();
    p2.clear();
    house.clear();
    p1.set_is_busted(false);
    p2.set_is_busted(false);
    house.set_is_busted(false);
}

// Begins game, asks if player wants to see the rules, and collects names and player starting banks
void start_info (player& p1, player& p2) {
    string rules_list;
    cout << "Welcome to Blackjack! Would you like to learn how to play? (Y or N)" << endl;
    cin >> rules_list;

    // Tests for invalid input
    if (rules_list != "Y" && rules_list != "N") {
        cout << "Error. Invalid input." << endl;
        start_info(p1, p2);
    }

    // If player does want to see rules, calls rules function to display blackjack rules
    if (rules_list == "Y") {
        rules();
        cout << endl << "Type 'N' when you're ready to continue." << endl;
        cin >> rules_list;
        while (rules_list != "N") {
            cout << "Error. Invalid input. Please type 'N' when ready to play: " << endl;
            cin >> rules_list;
        }
    }

    // If player doesn't want to see rules, collects player start info
    if (rules_list == "N") {
        string name1;
        string name2;
        double bank1;
        double bank2;

        cout << "Player 1, please enter your name: " << endl;
        cin >> name1;
        p1.set_name(name1);

        cout << "Player 1, please enter the amount of money you would like to cash in: " << endl;
        cin >> bank1;
        while (cin.fail()) {
            cout << "Error. Invalid input. Please enter a cash amount: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> bank1;
        }
        while (bank1 < 20) {
            cout << "Error. Invalid input. The minimum buy-in is $20. Please try again: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> bank1;
        }
        p1.set_bank(bank1);

        cout << "Player 2, please enter your name: " << endl;
        cin >> name2;
        p2.set_name(name2);

        cout << "Player 2, please enter the amount of money you would like to cash in: " << endl;
        cin >> bank2;
        while (cin.fail()) {
            cout << "Error. Invalid input. Please enter a cash amount: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> bank2;
        }

        while (bank2 < 20) {
            cout << "Error. Invalid input. The minimum buy-in is $20. Please try again: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> bank2;
        }
        p2.set_bank(bank2);
    }

}

// Loops through rounds of Blackjack
void round (player& p1, player& p2, dealer& house, deck& d1) {
    cout << endl << "Round starting now... " << endl << endl;

    double bet1;
    double bet2;

    cout << p1.get_name() << ", how much would you like to bet? " << endl;              // Set and print bets
    cin >> bet1;
    p1.set_bet(bet1);
    cout << p2.get_name() << ", how much would you like to bet? " << endl;
    cin >> bet2;
    p2.set_bet(bet2);

    cout << endl << p1.get_name() << " bets $" << bet1 << endl
         << p2.get_name() << " bets $" << bet2 << endl << endl;


    cout << "Dealing... " << endl << endl;                                  // Deal starting cards

    d1.deal_card(p1, 2);
    d1.deal_card(p2, 2);
    d1.deal_card(house, 2);

    cout << "The initial starting cards are: " << endl << endl;

    p1.print_hand();                                                        // Print Player 1's starting hand
    cout << endl;
    p2.print_hand();                                                        // Print Player 2's starting hand
    cout << endl;
    house.print_hand();                                                     // Print Dealer's starting hand
    cout << endl;

    cout << endl << p1.get_name() << "'s turn: " << endl << endl;           // Player 1's turn
    draw(p1, d1);
    p1.get_total();

    cout << endl << p2.get_name() << "'s turn: " << endl << endl;           // Player 2's turn
    draw(p2, d1);

    cout << endl << "Dealer's turn: " << endl << endl;                      // Dealer's turn
    bool draw = true;
    while (draw) {
        draw = house.player_turn();
        if (draw)
            d1.deal_card(house, 1);
    }

    cout << "Results: " << endl << endl;                                    // Round results

    winner (p1, p2, house);

    results(p1, house);
    results(p2, house);


    cout << endl << "The standings so far: " << endl << endl;                          // Display player banks

    cout << p1.get_name() << " $" << p1.get_bank() << endl;
    cout << p2.get_name() << " $" << p2.get_bank() << endl;

    if (house.get_bank() >= 0)
        cout << house.get_name() << " is up $" << house.get_bank() << endl;
    else
        cout << house.get_name() << " is down $" << -1 * house.get_bank() << endl;


    string play_again;
    cout << endl << "Play another round? (Y or N): " << endl;                               // Play again?
    cin >> play_again;

    while (play_again != "Y" && play_again != "N") {
        cout << "Error. Invalid input. Please type a 'Y' or an 'N': " << endl;              // Input test
        cin >> play_again;
    }

    if (play_again == "Y") {                                                                // Start new round
        reset_round (p1, p2, house, d1);
        round(p1, p2, house, d1);
    }                                                                                       //       OR

    else
        cout << endl << "Thanks for playing! Come back soon!" << endl;                      // End round and game
}

int main() {
    deck d1;
    dealer house;
    player p1;
    player p2;

    d1.create_deck();
    d1.shuffle();

    house.set_bank(0);
    house.set_name("Dealer");

    start_info(p1, p2);
    round(p1, p2, house, d1);

    return 0;
}
