#include<iostream>
#include<vector>
#include<array>
#include"include/Random.h"

constexpr int g_maximumScore{ 21 };
//-----------------------forward declaration
class Deck;
//---------------------------- 
class Card
{
public:
    enum class CardSuit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum class CardRank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };
    
    Card(CardRank r = CardRank::max_ranks, CardSuit s = CardSuit::max_suits);
    
    ~Card();

private:
    CardRank m_rank;
    CardSuit m_suit;

public:
    void printCard() const
    {
        switch (m_rank)
        {
        case CardRank::rank_2:      std::cout << '2';   break;
        case CardRank::rank_3:      std::cout << '3';   break;
        case CardRank::rank_4:      std::cout << '4';   break;
        case CardRank::rank_5:      std::cout << '5';   break;
        case CardRank::rank_6:      std::cout << '6';   break;
        case CardRank::rank_7:      std::cout << '7';   break;
        case CardRank::rank_8:      std::cout << '8';   break;
        case CardRank::rank_9:      std::cout << '9';   break;
        case CardRank::rank_10:     std::cout << 'T';   break;
        case CardRank::rank_jack:   std::cout << 'J';   break;
        case CardRank::rank_queen:  std::cout << 'Q';   break;
        case CardRank::rank_king:   std::cout << 'K';   break;
        case CardRank::rank_ace:    std::cout << 'A';   break;
        default:
            std::cout << '?';
            break;
        }

        switch (m_suit)
        {
        case CardSuit::club:       std::cout << 'C';   break;
        case CardSuit::diamond:    std::cout << 'D';   break;
        case CardSuit::heart:      std::cout << 'H';   break;
        case CardSuit::spade:      std::cout << 'S';   break;
        default:
            std::cout << '?';
            break;
        }
        std::cout << ',';
    }

    int value() const{
        switch (m_rank)
        {
            case CardRank::rank_2:      return 2;
            case CardRank::rank_3:      return 3;
            case CardRank::rank_4:      return 4;
            case CardRank::rank_5:      return 5;
            case CardRank::rank_6:      return 6;
            case CardRank::rank_7:      return 7;
            case CardRank::rank_8:      return 8;
            case CardRank::rank_9:      return 9;
            case CardRank::rank_10:     return 10;
            case CardRank::rank_jack:   return 11;
            case CardRank::rank_queen:  return 12;
            case CardRank::rank_king:   return 13;
            case CardRank::rank_ace:    return 1;
        default:
                return -1;
        }
    }

    friend class Deck;
};

Card::Card( Card::CardRank r, Card::CardSuit s ):m_rank{r} , m_suit{s}
{
}

Card::~Card()
{
}
//----------------------------
class Deck
{
private:
    std::array<Card, 52> m_deck{Card{}};
    
    void createDeck()
    {
        int index{ 0 };

        for (int suit{ 0 }; suit < static_cast<int>(Card::CardSuit::max_suits); ++suit)
        {
            for (int rank{ 0 }; rank < static_cast<int>(Card::CardRank::max_ranks); ++rank)
            {
                m_deck[index] = Card { static_cast<Card::CardRank>(rank), 
                     static_cast<Card::CardSuit>(suit)};
                ++index;
            }
        }

    }

    unsigned long m_cardIndex{};

public:
    Deck(){
        createDeck();
    };
    
    ~Deck();
    
    void shuffleDeck()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
        std::shuffle(m_deck.begin(), m_deck.end(), mt);
    }
    
    void print(){
        for (Card card : m_deck){
            card.printCard();
        }
        std::cout << '\n';
    }

    const Card& dealCard() {
        return m_deck[m_cardIndex++];
    }
};

Deck::~Deck()
{
}

//-----------------------------
class Player
{
private:
    int m_score{};
public:
    Player();
    ~Player();
    int drawCard(Deck& deck) {
        Card m_playerCard = deck.dealCard();
        m_score += m_playerCard.value();
        return m_playerCard.value();
    }
    int score(){
        return m_score;
    }
    bool checkBust(){
        return m_score > g_maximumScore;
    }
};

Player::Player()
{
}

Player::~Player()
{
}

void game(Player& player, Player& dealer, Deck& deck){
    while (!player.checkBust() && !dealer.checkBust()){
        int playerCard = player.drawCard(deck) ;
        std::cout << "The player drew a card with value " << playerCard << " and now has score " << player.score() << '\n';
        if (player.checkBust()){
            std::cout <<"you lose\n";
            break;
            }
        while (dealer.score() < player.score()){
            int dealerCard = dealer.drawCard(deck) ;
            std::cout << "The dealer drew a card with value " << dealerCard << " and now has score " << dealer.score() << '\n';
            if (dealer.checkBust()){
                std::cout << "Dealer Bust, you win\n";
                goto End;
            }
        }
        std::cout << "Want to draw another?(y/n)";
        char choice {};
        std::cin >> choice;

        if (choice == 'y')
            continue;
        if (choice = 'n'){
            while (dealer.score() < player.score()){
                int dealerCard = dealer.drawCard(deck) ;
                std::cout << "The dealer drew a card with value " << dealerCard << " and now has score " << dealer.score() << '\n';
                if (dealer.checkBust()){
                    std::cout << "Dealer Bust, you win\n";
                    break;
                }
            }
            if (player.score() < dealer.score()){
                    std::cout << "you lose\n";
                    break;
                }
            if (player.score() == dealer.score()){
                std::cout << "Draw\n";
                break;
            }
        }
    }
    End :
        return;
}
    

int main()
{
    Deck deck{};

    deck.shuffleDeck();
    deck.print();

    Player player{};
    Player dealer{};

    game(player , dealer ,deck);

    return 0;
}