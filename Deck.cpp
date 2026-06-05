#include "Deck.h"

namespace
{
  using namespace Crazy8::Deck;

  struct CardInfo
  {
    CardInfo(const Rank r, const Suit s) : rank{r}, suit{s}
    {
      switch (r)
      {
      case eight:
        victoryPoints = 50;
        break;
      case king:
      case queen:
      case jack:
      case ten:
        victoryPoints = 10;
        break;
      case ace:
        victoryPoints = 1;
        break;
      case two:
        victoryPoints = 2;
        break;
      case three:
        victoryPoints = 3;
        break;
      case four:
        victoryPoints = 4;
        break;
      case five:
        victoryPoints = 5;
        break;
      case six:
        victoryPoints = 6;
        break;
      case seven:
        victoryPoints = 7;
        break;
      case nine:
        victoryPoints = 9;
        break;
      default:
      }
    }
    CardInfo() : CardInfo(max_ranks, max_suits) {}
    Rank rank;
    Suit suit;
    int victoryPoints{};
    [[nodiscard]] std::string name() const
    {
      return std::format("{} of {}", rankNames[this->rank],
                         suitNames[this->suit]);
    };
  };

  inline const std::array deckInfo = []
  {
    std::array<CardInfo, deckSize> result{};
    for (int s{diamonds}; s < max_suits; ++s)
    {
      for (int v{ace}; v < max_ranks; ++v)
      {
        const auto i{max_ranks * s + v};
        result[i] = CardInfo{static_cast<Rank>(v), static_cast<Suit>(s)};
      }
    }
    return result;
  }();

} // namespace

int Crazy8::Deck::getVictoryPoints(const Card card)
{
  return deckInfo[card].victoryPoints;
}

Rank Crazy8::Deck::getRank(const Card card) { return deckInfo[card].rank; }

Suit Crazy8::Deck::getSuit(const Card card) { return deckInfo[card].suit; }

std::string Crazy8::Deck::getName(const Card card)
{
  return deckInfo[card].name();
}
