#ifndef CRAZY8_DECK_H
#define CRAZY8_DECK_H

#include <array>
#include <format>
#include <string>
#include <string_view>

using namespace std::string_literals;
using namespace std::string_view_literals;

namespace Crazy8::Deck
{

  using Card = int;

  inline constexpr int suits = 4;
  inline constexpr int ranks = 13;
  inline constexpr int deckSize = suits * ranks;

  inline constexpr std::array suitNames{"diamonds", "hearts", "clubs",
                                        "spades"};
  inline constexpr std::array rankNames{
    "ace",   "two",  "three", "four", "five",  "six", "seven",
    "eight", "nine", "ten",   "jack", "queen", "king"};

  enum Suit : int
  {
    diamonds,
    hearts,
    clubs,
    spades,
    max_suits
  };

  enum Rank : int
  {
    ace,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    max_ranks
  };

  int getVictoryPoints(Card card);
  Rank getRank(Card card);
  Suit getSuit(Card card);
  std::string getName(Card card);

} // namespace Crazy8::Deck


#endif // CRAZY8_DECK_H
