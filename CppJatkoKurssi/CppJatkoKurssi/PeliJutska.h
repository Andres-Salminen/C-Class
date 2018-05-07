#pragma once
#include <iostream>

using namespace std;

class Game {
protected:
	int playersCount;
	virtual void initializeGame() = 0;
	virtual void makePlay(int player) = 0;
	virtual bool endOfGame() = 0;
	virtual void printWinner() = 0;
public:
	/* A template method */
	void playOneGame(int playersCount) {
		this->playersCount = playersCount;
		initializeGame();
		int j = 0;
		while (!endOfGame()) {
			makePlay(j);
			j = (j + 1) % playersCount;
		}
		printWinner();
	}
};

class TikkuPeli : public Game
{
private:
	int tikut;
	int winningPlayer;
protected:

	virtual void initializeGame()
	{
		tikut = 10 + this->playersCount * 10;
	}

	virtual void makePlay(int player)
	{
		int otetut = 0;
		cout << "It's player " << player + 1 << "\'s turn. Stack has " << tikut << " sticks. Please choose how many sticks you would like: ";
		while (true)
		{
			cin >> otetut;
			if (otetut > 0 && otetut < 4 && otetut < tikut + 1)
				break;
			else
				cout << "Invalid amount of sticks. Please take from 1 up to 3 or the maximum amount of sticks left. Amount of sticks left is " << tikut <<". Take sticks: ";
		}
		tikut -= otetut;
		if (tikut <= 0)
		{
			winningPlayer = this->playersCount - player;
		}
	}
	virtual bool endOfGame()
	{
		return (tikut <= 0);
	}
	virtual void printWinner()
	{
		cout << "Congratulations player " << winningPlayer << " has won!" << endl;
	}
};