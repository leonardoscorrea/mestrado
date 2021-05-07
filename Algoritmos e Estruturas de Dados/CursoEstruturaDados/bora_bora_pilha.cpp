#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

struct card {
  int card_number;
  string card_suit;
  int getValueOfSuit(){
    if(card_suit == "C") return 1;//(Paus - Clubs)
    if(card_suit == "D") return 2;//(Ouros - Diamonds)
    if(card_suit == "H") return 3;//(Copas - Hearts)
    if(card_suit == "S") return 4;//(Espadas - Spades)
    else return 0;
  }
  string getStrCard(){
    return std::to_string(card_number) + card_suit;
  }
  bool biggerThen(card other){
    if(card_number > other.card_number) return true;
    if(card_number == other.card_number) {
        if(getValueOfSuit() <= other.getValueOfSuit()) return false;
        else return true;
    } else return false;
  }
} ;

struct player{
    vector<card> hand;
    card takeoutCard;

    void removeCard(card c){
        vector<card> handAux;
        for(int i = 0; i < hand.size(); i++){
            if(c.card_number != hand[i].card_number || c.card_suit != hand[i].card_suit){
                handAux.push_back(hand[i]);
            }
        }
        hand.erase(hand.begin(),hand.end());
        hand = handAux;
    }

    bool checkHand(card c){
        if(hand.size() > 0){
            card cBiggest = hand[0];
            bool checked = false;
            for(int i = 0; i < hand.size(); i++){
                if(c.card_number == hand[i].card_number || c.card_suit == hand[i].card_suit){
                    if(checked){
                        if(hand[i].biggerThen(cBiggest)) cBiggest = hand[i];
                    } else {
                        cBiggest = hand[i];
                    }
                    checked = true;
                }
            }
            if(checked) {
                removeCard(cBiggest);
                takeoutCard = cBiggest;
                return true;
            }
        }
        return false;
    }


    void showHand(){
        for(int i = 0; i < hand.size(); i++){
            cout << hand[i].getStrCard() << " ";
        }
        cout << "\n";
    }
};

struct game{
    vector<card> deck;
    vector<card> trash;
    vector<player> players;
    vector<int> wins;
    card cardTopOfTrash;
    bool cardTopExecuted = false;
    int numberOfPlayers = 0;
    int numberCardByPlayer = 0;
    int numberOfCards = 0;
    int activePlayer = 0;
    int clockwise  = 1;

    bool take(){
        if(deck.size() > 0){
            cardTopOfTrash = deck[deck.size()-1];
            deck.pop_back();
            cardTopExecuted = false;
            return true;
        } else {
            return false;
        }
    }

    card takeToHand(){
        card c = deck[deck.size()-1];
        deck.pop_back();
        return c;
    }

    void reset(){
        deck.clear();
        trash.clear();
        players.clear();
        numberOfPlayers = 0;
        numberOfCards = 0;
        numberCardByPlayer = 0;
        activePlayer = 0;
        clockwise = 1;
        cardTopExecuted = false;
    }

    void start(){
        for(int i = 0; i < numberOfPlayers; i++){
            player p;
            for(int j = 0; j < numberCardByPlayer; j++){
                if(take()) p.hand.push_back(cardTopOfTrash);
            }
            players.push_back(p);
        }
        take();//inicia primeira jogada
    }

    void nextPlayer(){
        if(activePlayer == 0 && clockwise < 0) activePlayer = players.size()-1;
        else if(activePlayer == (players.size()-1) && clockwise > 0) activePlayer = 0;
        else activePlayer = activePlayer+clockwise;
    }

    int checkWin(){
        for(int i = 0; i < players.size(); i++){
            if(players[i].hand.size() == 0) {
                if(SHOW_WIN_BY_GAME) cout << i+1 << "\n";
                wins.push_back(i+1);
                return i+1;
            }
        }
        return 0;
    }

    void showWins(){
        for(int i = 0; i < wins.size(); i++){
            cout << wins[i] << "\n";
        }
    }

    bool play(){
        if(!cardTopExecuted){
            if(cardTopOfTrash.card_number == 12) {
                clockwise = clockwise*-1;
                cardTopExecuted = true;
            }
            else if(cardTopOfTrash.card_number == 7) {
                card c = takeToHand();
                players[activePlayer].hand.push_back(c);
                c = takeToHand();
                players[activePlayer].hand.push_back(c);
                cardTopExecuted = true;
                return true;
            } else if(cardTopOfTrash.card_number == 1) {
                card c = takeToHand();
                players[activePlayer].hand.push_back(c);
                cardTopExecuted = true;
                return true;
            } else if(cardTopOfTrash.card_number == 11) {
                cardTopExecuted = true;
                return true;
            }
        }

        if(players[activePlayer].checkHand(cardTopOfTrash)) {
            cardTopOfTrash = players[activePlayer].takeoutCard;
            cardTopExecuted = false;
            return true;
        }
        else {
            card c = takeToHand();
            players[activePlayer].hand.push_back(c);
            if(players[activePlayer].checkHand(cardTopOfTrash)){
                cardTopOfTrash = players[activePlayer].takeoutCard;
                cardTopExecuted = false;
            }
            return true;
        }

        return true;
    }

    void showDeck(){
        for(int i = 0; i < deck.size(); i++){
            cout << deck[i].getStrCard() << " ";
        }
        cout << "\n";
    }
};

game mainGame;


void identifiers(string s){
    if(SHOW_IDENTIFIERS){
        std::cout << s << "\n";
    }
}

int getInput(){
    int number;
    string line;
    string suit;

    identifiers("[Nro jogadores] [Nro de cartas por jogador] [Nro cartasBaralho]: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    if (stream >> number)
        mainGame.numberOfPlayers = number;
    if (stream >> number)
        mainGame.numberCardByPlayer = number;
    if (stream >> number)
        mainGame.numberOfCards = number;

    if(mainGame.numberOfPlayers == 0){
        return 0;
    }

    identifiers("Cartas: ");
    vector<card> deckAux;
    for(int i = 0; i < mainGame.numberOfCards;i++){
        std::getline(std::cin, line);
        std::istringstream stream(line);
        card c;
        if (stream >> number)
            c.card_number = number;
        if (stream >> suit)
            c.card_suit = suit;
        deckAux.push_back(c);
    }
    for(int i = deckAux.size() - 1; i >= 0; i--){
        mainGame.deck.push_back(deckAux[i]);
    }
    return 1;
}


int main(){
	while(getInput()){
        //mainGame.showDeck();
        mainGame.start();
        while(!mainGame.checkWin()){
            //mainGame.players[0].showHand();
            //mainGame.showDeck();
            mainGame.play();
            //mainGame.players[0].showHand();
            mainGame.nextPlayer();
        }
        mainGame.reset();
	}
	mainGame.showWins();
    return 1;
}
