//All the tools and structs for cards and a card deck
#include<stdio.h>
#include<stdlib.h>

enum suit{C,D,H,S};

typedef struct card Card;

struct card
{
    char suit;
    char rank;
    int visibility;
};

Card* newUnshuffledDeck() {
    Card cardDeck[52];

    char suits[4] = {'C','D','H','S'};
    Card newCard;
    for (int i = C; i <= S ; i++) {
        newCard.suit = suits[i];
        newCard.rank = 'A';
        cardDeck[i*13] = newCard;
        for (int j = 2; j <= 9; j++) {
            newCard.rank = j;
            cardDeck[i*13+j-1] = newCard;
        }
        newCard.rank = 'T';
        cardDeck[i*13+9] = newCard;
        newCard.rank = 'J';
        cardDeck[i*13+10] = newCard;
        newCard.rank = 'Q';
        cardDeck[i*13+11] = newCard;
        newCard.rank = 'K';
        cardDeck[i*13+12] = newCard;
    }

    return cardDeck;
}

void shuffleDeck(Card* deck) {

}