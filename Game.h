#ifndef CRAZY8_GAME_H
#define CRAZY8_GAME_H

#include "Deck.h"

#include <vector>
#include <optional>

namespace Crazy8
{
  // TODO might work for now, but it may be desirable to make it a proper class
  using Player = int;

  struct PlayerInfo
  {
    explicit PlayerInfo(int index);
    Player player {};
    int victoryPoints {};
    std::vector<Deck::Card> hand {};
  };

  class Game
  {
  public:
    Game();
    explicit Game(int numberOfPlayers);
    Player nextPlayer();
    [[nodiscard]] int handSize(Player player) const;
    [[nodiscard]] bool hasWinner() const;
    void reset();
    [[nodiscard]] int victoryPoints(Player player) const;
    [[nodiscard]] const PlayerInfo& winnerInfo() const;
    bool apply(Player player, char action);
    void drawCard(Player player);
    bool canDraw(Player player);
    bool canPlay(Player player);
    void showCards(Player player);
    void showTopCard();
    void adjudicateVictoryPoints(Player player, int victoryPoints);

  private:
    void shuffleDeck();
    void init();
    Deck::Card m_topCard{}; //TODO maybe just use the endpoint of the vector
    std::vector<Deck::Card> m_playedCards {};
    std::vector<Deck::Card> m_drawPile {};
    int m_currentPlayerIndex {};
    std::optional<Player> m_winner {};
    std::vector<PlayerInfo> m_players{};
    int m_victoryThreshold {};
  };
} // namespace Crazy8

#endif // CRAZY8_GAME_H
