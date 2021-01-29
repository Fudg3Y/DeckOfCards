#include<iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

using namespace std;

class Card {
public:
	string face;
	string symbol;
	Card();
	Card(string f, string s);	
};

Card::Card() {

}

Card::Card(const string s, const string f) : symbol(s), face(f) {
}

//Class extends card and holds all 52 cards.

class Deck : public Card {
	vector<Card>* deckOfCards;
	string face[13]{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	string symbol[4]{ "♥", "♦", "♠", "♣" };

	public:
		Deck();				//constructor for deck
		void show();		//Member function for show
		void shuffle();		//Member function for shuffle
		void pickACard();	//Member function to show a single random card
		void topDeck();		//Member function to take the first card from the deck
		~Deck();			//deconstructor for deck
};

//Constructor for deck produces cards in sequence
Deck::Deck() {
	deckOfCards = new vector<Card>();
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 13; ++j)
			deckOfCards->push_back(Card(symbol[i], face[j]));
}

//Member function shows the card
void Deck::show() {
	string showCard("");
	auto it = deckOfCards->begin();
	while (it!= deckOfCards->end()) {
	    showCard.append("╔════╗\n");
	    showCard.append("║    ║\n");
	    showCard.append("║ ");
		showCard.append((it->face));		
		showCard.append((it->symbol));
		if(it->face == "10"){
		    showCard.append("║\n");
		}
		else{
		showCard.append(" ║\n");
		}
	    showCard.append("║    ║\n");
	    showCard.append("╚════╝\n");
		showCard.append("\n");
		it = next(it);
	}
	cout << showCard << endl;
}

//Member function shuffles deck of cards

void Deck::shuffle() {
	srand(time(NULL));
	random_shuffle(deckOfCards->begin(), deckOfCards->end());
}

//Member function picks the card from the top of the deck
void Deck::topDeck() {
	string showCard("");
	auto it = deckOfCards->begin();
		showCard.append("╔════╗\n");
	    showCard.append("║    ║\n");
	    showCard.append("║ ");
		showCard.append((it->face));		
		showCard.append((it->symbol));
		if(it->face == "10"){
		    showCard.append("║\n");
		}
		else{
		showCard.append(" ║\n");
		}
	    showCard.append("║    ║\n");
	    showCard.append("╚════╝\n");
		showCard.append("\n");
		deckOfCards->erase(it);
    cout << showCard << endl;
    if (deckOfCards->begin() == deckOfCards->end())
    {
      cout << "You've run out of cards!" << endl;
      cout << "Now generating a new deck of cards" << endl;
      delete deckOfCards;
      Deck();
      
    }
}

//Member function picks a card at random from the deck
void Deck::pickACard() {
	shuffle();
	topDeck();
}

//Destructor for deck

Deck::~Deck() {
	delete deckOfCards;
}

void displayMenu(){
    cout<< "\n";
    cout<< "Please pick an option:" << endl;
    cout<< "1: Show Entire Deck" << endl;
    cout<< "2: Shuffle Deck" << endl;
    cout<< "3: Top Deck A Card" << endl;
    cout<< "4: Pick A Random Card" << endl;
    cout<< "5: Quit The Program" << endl;
}

int main(){
    Deck d;
    int input;
    
    while(input !=5){
        displayMenu();
        cin >> input;
        if(input == 1){
        cout << "Showing the entire deck" << endl;
        d.show();
        }
        
        else if(input == 2){
        cout << "Shuffling the deck..." << endl; 
        d.shuffle();
        cout << "Deck now shuffled!" << endl; 
        }
        
        else if(input == 3){
        cout << "Picking the card from the top of the deck..." << endl; 
        cout << "The card is" << endl; 
        d.topDeck();
        }
        
        else if(input == 4){
        cout << "The deck is fanned out and you take a card at random..." << endl; 
        cout << "The card is" << endl; 
        d.pickACard();
        }
        
        else if(input == 5){
        cout << "You have chosen to exit, goodbye!";
        }
        
        else{
        cout << "Incorrect input, please try again";
        }
    }
    return 0;
}
