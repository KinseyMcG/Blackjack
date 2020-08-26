// Kinsey McGlasson, Program #1

#include "dealer.h"

// Calls print_hand and displays total pts in dealer's hand, then programs draw/stay decision
bool dealer::player_turn() {
    print_hand();
    cout << " (" << get_total() << " points)" << endl;

    if (!test_bust()) {                                                 // If dealer's hand total <= 21:
        if (get_total() <= 16) {
            cout << "Dealer chooses to draw" << endl;
            return true;
        } else {
            cout << "Dealer chooses to stay" << endl << endl;
            return false;
        }
    }

    else                                                                // If dealer's hand total > 21:
        return false;
}