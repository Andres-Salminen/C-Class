#pragma once
#include <iostream>

using namespace std;

class PokemonState
{
public:
	virtual void DoThings() = 0;
	virtual void Move(float* myPosition) = 0;
	virtual void Attack() = 0;
};

class Charmander : public PokemonState
{
public:
	virtual void DoThings()
	{
		cout << "Rawr, I'm a charmander" << endl;
	}

	virtual void Move(float* myPosition)
	{
		float movespeed = 4;

		myPosition[2] += movespeed;

		cout << "Moved forward " << movespeed << " steps." << endl;
	}

	virtual void Attack()
	{
		cout << "Using a tiny flamethrower." << endl;
	}
};

class Charmeleon : public PokemonState
{
public:
	virtual void DoThings()
	{
		cout << "RAWR, I've evolved into a Charmeleon." << endl;
	}

	virtual void Move(float* myPosition)
	{
		float movespeed = 6;

		myPosition[2] += movespeed;

		cout << "Moved forward " << movespeed << " steps." << endl;
	}

	virtual void Attack()
	{
		cout << "Breathing fire." << endl;
	}
};

class Charizard : public PokemonState
{
public:
	virtual void DoThings()
	{
		cout << "ROAR, I'M A MASSIVE DRAGON GRRR." << endl;
	}

	virtual void Move(float* myPosition)
	{
		float movespeed = 10;
		myPosition[1] += movespeed;
		cout << "Flew " << movespeed << " units upwards." << endl;
	}

	virtual void Attack()
	{
		cout << "Breathing out hellfire and magma." << endl;
	}
};

class Pokemon
{
private:
	PokemonState* _state;

public:

	Pokemon(PokemonState* state)
	{
		_state = state;
	}

	void ChangeState(PokemonState* state)
	{
		_state = state;
	}

	void Attack()
	{
		_state->Attack();
	}

	void Move(float* position)
	{
		_state->Move(position);
	}

	void Greet()
	{
		_state->DoThings();
	}
};
