# Blackjack

This is a C++ program to simulate a game of Blackjack between a dealer and two players. There are many variations on the rules of Blackjack, so the exact rules used in this case are outlined in the following section.

## Rules of Blackjack

At the start of each round, each player is required to bet on the outcome of the round. In this program, no player may bet an amount lower than $1. The dealer does not bet, but will deal out bet money to any winning players and collect bet money from any losing players at the end of the round. After all bets are in, each player (including the dealer) is dealt 2 cards by the dealer (also known as the house). The first card dealt to each player is face-down, while the second card is face-up. The point values assigned to each card are as follows:

- Any Jack, Queen, or King is given a value of 10
- An Ace is given a value of 1 or 11, depending on which value is most advantageous to the player
- All other cards are given a value equal to the number on the card in question

Once the initial two cards have been dealt to all players, players have the choice to either (1) have the dealer deal them additional cards (hit) or (2) pass and keep their hand total as it is (stay). If the player or dealer hit and exceed a hand total of 21, they are said to have busted and their turn is over. Once all the players have finished their turns, the dealer will play. The dealer will always hit if their hand total is less than 17, and will stay otherwise. Under these rules, there are 4 possible outcomes to any round of Blackjack:

- The player and the dealer both have the same hand total, and neither have busted. The player loses.
- The player has busted. The player loses.
- The dealer has busted, but the player has not. The player wins. 
- The player has a hand total greater than that of the dealer, but less than or equal to 21. The player wins.
