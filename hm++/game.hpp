#include <iostream>
using namespace std;
#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

class hm
{
	string iWord;
	string oWord;
	string p1;
	string p2;
	void setPlayers()
	{
		cout << "Player 1 enter your name" << endl;
		getline(cin, p1);
		cout << "Player 2 enter your name" << endl;
		getline(cin, p2);
	}
	void setWord()
	{
		cout << p1 << " enter word " << p2 << " do not look" << endl;
		cin >> iWord;
		oWord = iWord;
		for(long long unsigned i = 0; i != iWord.size(); i++)
		{
			if(oWord[i] != ' ' && oWord[i] != '-')
				oWord[i] = 177;
		}
	}
	void guess()
	{
		setWord();
		short hits = iWord.size(), body = 6;
		char g;
		char l[6]= {' ', ' ', ' ', ' ', ' ', ' '};
		short m = 0;
		bool isIn;
		while(body != 0 && hits != 0)
		{
			isIn = 0;
			cout << body << " trials left" << endl << hits << " hits needed";
			if(m != 0)cout << endl << "Mistakes: ";
			for(char i:l)cout << i;
				cout << endl << oWord;
			for(short i = 0; i != 42; i++)cout << endl;
				cin >> g;
			for(long long unsigned i = 0; i != iWord.size(); i++)
			{
				if(g == iWord[i] || (g + 32 == iWord[i] && g > 64 && g < 91) || (g - 32 == iWord[i]
				&& g > 96 && g < 123))
				{
					oWord[i] = iWord[i];
					hits--;
					isIn = 1;
				}
			}
			if(isIn == 0)
			{
				bool b = 1;
				for(char i:l)
					if(g == i)
					{
						b = 0;
						break;
					}
				if(b)
				{
					body--;
					l[m] = g;
					m++;
				}
			}
		}
		cout << "Guessed " << oWord << " with " << hits << " left and with " << m << " mistakes" << endl;
		if(oWord != iWord)cout << "Real word was: " << iWord << endl;
	}
public:
	void play()
	{
		setPlayers();
		while(1)
		{
			cout << "Play hangman?" << endl;
			char p;
			cin >> p;
			switch(p)
			{
			case 'Y':
			case 'y':
				guess();
				break;
			case 'N':
			case 'n':
				break;
			default:
				cout << "I am not sure I understand this, please input y/Y or n/N" << endl;
				play();
				break;
			}
		}
	}
};

#endif // GAME_HPP_INCLUDED
