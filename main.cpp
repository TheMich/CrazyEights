#include "Game.h"

#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

// TODO consider moving in game class
void playHand(Crazy8::Game& game)
{
  // Setup player turn
  const auto player{game.nextPlayer()};
  assert(game.handSize(player) > 0 &&
                "Player should not have empty hand at turn start");

  game.showTopCard();

  std::cout << "Player " << player << ", here are your cards: \n";
  game.showCards(player);

  // Check for necessary card drawing
  while (!game.canPlay(player))
  {
    if (!game.canDraw(player))
    {
      std::cout << "Cannot play or draw a card. You shall pass!\n";
      return;
    }
    std::cout << "Cannot play any card. Press enter to draw a card: ";
    std::cin.ignore();
    game.drawCard(player);
  }
  // Allow player action
  auto hasPlayedCard{false};
  do
  {
    std::cout << "Choose a number then press the enter key to play that card,"
                 "or press d and the enter key to draw a card: ";
    char action;
    std::cin >> action; // TODO input validation
    hasPlayedCard = game.apply(player, action);
    // TODO add suit selection if any 8 is played
  }
  while (!hasPlayedCard);

  // Handle case where player wins the match
  if (game.handSize(player) == 0)
  {
    const auto victoryPoints{game.victoryPoints(player)};
    std::cout << "Congrats player " << player << ", you win the match with "
              << victoryPoints << " points!\n";
    game.adjudicateVictoryPoints(player, victoryPoints);
    if (!game.hasWinner())
    {
      std::cout << "Resetting deck and player hands...\n";
      game.reset();
    }
  }
}

int main()
{
  std::cout << "Welcome to Crazy8!\n\n";
  std::cout << "This program is currently under construction.\n\n";
  Crazy8::Game game(2);
  // std::cout << "Enter the number of players (2-7): ";
  //
  // int numberOfPlayers;
  // std::cin >> numberOfPlayers; // TODO input validation
  //
  // Crazy8::Game game(numberOfPlayers);
  //
  // while (!game.hasWinner())
  // {
  //   playHand(game);
  // }
  // auto winInfo{game.winnerInfo()};
  // TODO print win info (winning player and points)
  std::cout << "Bye!\n";
  return 0;
}
