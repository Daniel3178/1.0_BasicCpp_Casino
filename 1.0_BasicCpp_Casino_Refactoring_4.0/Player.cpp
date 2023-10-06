#include "Player.h"

namespace casino 
{
	Player::Player(std::string aName)
	: playerName (aName), isPlayerLegit ( false), isPlayerPlaying (false),
		playerTotalBudget ( 1000), playerBet (0)
	{
	}

	void Player::IncreasePlayerTotalBudget(const int aValue)
	{
		playerTotalBudget += aValue;
	}
	void Player::DecreasePlayerTotalBudget(const int aValue)
	{
		playerTotalBudget -= aValue;
	}

	const int Player::GetPlayerTotalBudget() const
	{
		return playerTotalBudget;
	}

	void Player::SetPlayerBet(const int aValue)
	{
		playerBet = aValue;
	}

	const int Player::GetPlayerBet() const
	{
		return playerBet;
	}

	void Player::SetPlayerLegit(const bool aBoolean)
	{
		isPlayerLegit = aBoolean;
	}

	const bool Player::GetPlayerLegit() const
	{
		return isPlayerLegit;
	}
	const std::string Player::GetPlayerName() const
	{
		return playerName;
	}
	void Player::SetPlayerPlayingState(const bool aBoolean)
	{
		isPlayerPlaying = aBoolean;
	}
	const bool Player::GetPlayerPlaying() const
	{
		return isPlayerPlaying;
	}
}