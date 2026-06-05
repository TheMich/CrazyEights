#include "Game.h"
#include "Deck.h"

#include "Random.h"

#include <algorithm>

Crazy8::PlayerInfo::PlayerInfo(const int index) : player(index) {}

void moveCard(std::vector<Crazy8::Deck::Card>& from,
              std::vector<Crazy8::Deck::Card>& to)
{
  to.push_back(from.back());
  from.pop_back();
}

void Crazy8::Game::shuffleDeck()
{
  std::ranges::shuffle(m_drawPile, Random::mt);
}

void Crazy8::Game::init()
{
  for (auto i{0}; i < Deck::deckSize; ++i)
  {
    m_drawPile.emplace_back(i);
  }
  shuffleDeck();
  moveCard(m_drawPile, m_playedCards);
  for (auto& p : m_players)
  {
    const auto handSize = m_players.size() == 2 ? 7 : 5;
    for (auto i{0}; i < handSize; ++i)
    {
      moveCard(m_drawPile, p.hand);
    }
  }
}

Crazy8::Game::Game(const int numberOfPlayers) :
    m_victoryThreshold{50 * numberOfPlayers}
{
  for (auto i{0}; i < numberOfPlayers; ++i)
  {
    m_players.emplace_back(i);
  }
  init();
}

Crazy8::Game::Game() : Game(2) {}

Crazy8::Player Crazy8::Game::nextPlayer()
{
  m_currentPlayerIndex =
    m_currentPlayerIndex == m_players.size() - 1 ? 0 : m_currentPlayerIndex + 1;
  return m_players[m_currentPlayerIndex].player;
}

int Crazy8::Game::handSize(const Player player) const
{
  return static_cast<int>(m_players[player].hand.size());
}

bool Crazy8::Game::hasWinner() const { return m_winner.has_value(); }

void Crazy8::Game::reset()
{
  m_playedCards.clear();
  for (auto& player : m_players)
  {
    player.hand.clear();
  }
  init();
}

int Crazy8::Game::victoryPoints(const Player player) const
{
  return m_players[player].victoryPoints;
}

const Crazy8::PlayerInfo& Crazy8::Game::winnerInfo() const
{
  // TODO implement
  return m_players.front();
}

bool Crazy8::Game::apply(Player player, char action)
{
  // TODO implement
  return false;
}

void Crazy8::Game::drawCard(Player player)
{
  // TODO implement
}

bool Crazy8::Game::canDraw(Player player)
{
  // TODO implement
  return false;
}

bool Crazy8::Game::canPlay(Player player)
{
  // TODO implement
  return false;
}

void Crazy8::Game::showCards(Player player)
{
  // TODO implement
}

void Crazy8::Game::showTopCard()
{
  // TODO implement
}
void Crazy8::Game::adjudicateVictoryPoints(Player player,
                                           const int victoryPoints)
{
  m_players[player].victoryPoints += victoryPoints;
  if (m_players[player].victoryPoints >= m_victoryThreshold && !m_winner)
  {
    m_winner = player;
  }
}
