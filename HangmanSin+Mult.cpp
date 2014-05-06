#include <iostream>
#include <limits>
using namespace std;

class hangman
{
	string entry = " ";
	string entryDisplay = " ";
	string hang[7];
	string guess;
	char prevEntered[6];
	int x,q,w,y,z,s,tracker;
	public:
		void star()// Displayed if player wins
		{
    		cout << "\n\n\n\n" << endl;
    		cout << "          *          " << endl;
    		cout << "         ***         " << endl;
    		cout << "        *****        " << endl;
    		cout << "       *******       " << endl;
    		cout << " ******************* " << endl;
    		cout << "   ***************   " << endl;
    		cout << "     ***********     " << endl;
    		cout << "     ***** *****     " << endl;
    		cout << "    ****     ****    " << endl;
    		cout << "   ***         ***   " << endl;
    		cout << "  **             **  " << endl;
    		cout << " *                 * " << endl;
		}
		void gameStart()// Displayed at beginning of program for aesthetics
		{
    		cout << "--------------------Hangman!--------------------\n";
    		cout << "                                                \n";
    		cout << "          |---------                            \n";
    		cout << "          |       |                             \n";
    		cout << "          |       O   <----- This could be you! \n";
    		cout << "          |      <|>                            \n";
    		cout << "          |      ( )                            \n";
    		cout << "          |                                     \n";
    		cout << "          |--------------                       \n";
    		cout << "          | |  |  |  |  |                       \n";
    		cout << " ~~~~~~~~~---------------~~~~~~~~~~~~~~~~~~~~~~ \n";
    		cout << "                                                \n";
   			cout << "  Player your life is threatened by the PC      \n";
    		cout << "            Try not to die!                     \n";
    		cout << "                By guessing the secret word!    \n";
    		cout << "                                                \n";
    		cout << "\n\n";
		}
		void player1Start()
		{
    		cout << "--------------------Hangman!--------------------\n";
    		cout << "           Created By: Anthony Malone           \n";
    		cout << "                                                \n";
    		cout << "                                                \n";
    		cout << "                                                \n";
    		cout << "          |---------                            \n";
    		cout << "          |       |                             \n";
    		cout << "          |       O   <------ Your goal.        \n";
    		cout << "          |      <|>                            \n";
    		cout << "          |      ( )                            \n";
    		cout << "          |                                     \n";
    		cout << "          |--------------                       \n";
    		cout << "          | |  |  |  |  |                       \n";
			cout << " ~~~~~~~~~---------------~~~~~~~~~~~~~~~~~~~~~~ \n";
		    cout << "                                                \n";
		    cout << "  Player 1 your are the decider of Player 2's   \n";
		    cout << "     life! Think of a word for Player 2 to      \n";
		    cout << "          guess in a game for their life!       \n";
		    cout << "                                                \n";
		}

		void player2Start()
		{
		    cout << "--------------------Hangman!--------------------\n";
		    cout << "                                                \n";
		    cout << "          |---------                            \n";
		    cout << "          |       |                             \n";
		    cout << "          |       O   <----- This could be you! \n";
		    cout << "          |      <|>                            \n";
		    cout << "          |      ( )                            \n";
		    cout << "          |                                     \n";
		    cout << "          |--------------                       \n";
		    cout << "          | |  |  |  |  |                       \n";
		    cout << " ~~~~~~~~~---------------~~~~~~~~~~~~~~~~~~~~~~ \n";
		    cout << "                                                \n";
		    cout << "  Player 2 your life is threatened by Player 1  \n";
    		cout << "            Try not to die!                     \n";
    		cout << "                By guessing the secret word!    \n";
    		cout << "                                                \n";
    		cout << "\n\n\n\n\n\n\n";
		}

		void hangerset()// Creates Hangman Frame that is changed
		{
    		hang[0] = "|-----\n";
    		for (int x=1;x<5;x++)
    		{
    		    hang[x] = "|     \n";
    		}
    		hang[6] = "------\n";
		}

		void prevEnteredSet()
		{
    		for (int x = 0;x < 7;x++)
    		{
    		    prevEntered[x] = ' ';
    		}
		}

		void hanger() // Function added for display of current hangman status
		{
		    if (s == 7)
    		{
    		    hang[1] = "|     \n";
    		}
    		else if (s == 6)
    		{
    		    hang[1] = "|   | \n";
    		}
    		else if (s == 5)
    		{
        		hang[2] = "|   O \n";
			  }
    		else if (s == 4)
    		{
    		    hang[3] = "|   | \n";
    		}
   		 	else if (s == 3)
			  {
    		    hang[3] = "|  <| \n";
    		}
			  else if (s == 2)
    		{
    		    hang[3] = "|  <|>\n";
    		}
    		else if (s == 1)
    		{
    		    hang[4] = "|  (  \n";
    		}
    		else if (s == 0)
    		{
    		    hang[4] = "|  ( )\n";
    		}
    		for (x=0;x<7;x++)
    		{
    		    cout << hang[x];
    		}
		}

		void inputInt()// Allows user to enter int values without breaking program
		{
		    while(!(cin >> x))
		    {
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		cout << "Invalid input.  Try again ";
    		}
		}

		void varSet()// Depending on user input changes the word and progress display for word
		{
    		switch (x)
    		{
    			case(1):
    				entry = "lollipop";
    				break;
    			case(2):
    				entry = "banana";
   		 			break;
    			case(3):
    				entry = "hammer";
    				break;
    			case(4):
    				entry = "hello";
    				break;
    			case(5):
    				entry = "ruler";
    				break;
    			case(6):
    				entry = "glue";
    				break;
    			case(7):
    				entry = "cakes";
    				break;
    			case(8):
    				entry = "cereal";
					  break;
				  case(9):
    				entry = "guitar";
    				break;
    			case(10):
    				entry = "videos";
    				break;
    			default:
    				cout << "Invalid try again.\n";
    				break;
    		}
   			varSet2();
		}

		void varSet2()// Depending on user input changes the progress display for word
		{
			int strSize;
			strSize = entry.length();
			switch (strSize)
    		{
    			case(1):
    				entryDisplay = "_";
   		 			break;
    			case(2):
    				entryDisplay = "_ _";
        			break;
    			case(3):
   			 		entryDisplay = "_ _ _";
      		  		break;
    			case(4):
      	  			entryDisplay = "_ _ _ _";
        			break;
    			case(5):
        			entryDisplay = "_ _ _ _ _";
        			break;
    			case(6):
        			entryDisplay = "_ _ _ _ _ _";
        			break;
    			case(7):
    				entryDisplay = "_ _ _ _ _ _ _";
        			break;
    			case(8):
        			entryDisplay = "_ _ _ _ _ _ _ _";
        			break;
    			default:
        			break;
    		}
		}

		void letEntered() //Displays wrong letters guessed
		{
    		int stat;
    		stat = z;
    		cout << " ----------------------------\n";
    		cout << "| Incorrect letters entered  |\n";
    		cout << "| ";
    		for (z=0;z<=stat;z++)
    		{
     		   cout << prevEntered[z] << " ";
    		}
    		cout << "\n";
    		cout << "-------------------------------\n";
    		z = stat;
		}

		void wordCheck()//This compares the users guess to the word and prints status of game
		{
			guess[0] = tolower(guess[0]);
    		w = 0;
    		for (int q=0;q<=7;q++)
    		{
        		if (guess[0] == entry[q])
        		{
            		w = q*2;
        			if (entryDisplay[w] == '_')
            		{
                		entryDisplay[w] = guess[0];
                		if (entryDisplay[w] == guess[0])
                		{
                    		y++;
                    		w--;
                		}
            		}
        			else
   	 				  {
                		cout << "You already entered that, try again.\n";
                		w--;
                		break;
        			}
        		}
			  }
    		if (y >= entry.length())
    		{
        		tracker = 1;
    		}
    		if (w == 0)
    		{
        		prevEntered[z] = guess[0];
        		z++;
        		s--;
        		if (z == 7)
        		{
            		tracker = 2;
        		}
    		}
    		hanger();
    		letEntered();
    		cout << "\n\n" << entryDisplay << "\n";
		}

		void enterNum()//This starts the game by allowing user to enter which word they want to try and guess
		{
    		cout << "1- Something you get at a candy store.   2- Silly Monkey     \n";
    		cout << "3- Thor had one of these things          4- Greetings        \n";
    		cout << "5- Measurments are funnnnnnn             6- Eww Sticky       \n";
   	 		cout << "7- They're a lie                         8- Part of healthy breakfast \n";
    		cout << "9- Pluckin str- I mean feathers          10- Youtube is full of them \n";
    		cout << "\nChoose your word: ";
    		do
    		{
    			inputInt();
    			varSet();
    		}while (x < 1 || x > 10);
		}

		void enterWord()
		{
    		char done;
    		do
    		{
    			cout << "Enter your word (8 characters or less): ";
    			cin >> entry;
    			varSet2();
    			cout << "You entered " << entry << ", is that correct? ";
    			cin >> done;
    		}while (done != 'y');
    		cout << "Great, lets play Hangman!.";
		}

		void guessFunction()//This is where user enters their guess and displays whether they win or lose
		{
    		while (tracker == 0)
   	 		{
        		cout << "\n\nEnter guess: ";
        		cin >> guess;
        		wordCheck();
        		}
        		if (tracker == 1)
        		{
            		star();
            		cout << "\n\n\nYou won! The word was " << entry << ".\n";
        		}
        		else
        		{
            		cout << "\nYou lost! The word was " << entry << ".\n";
        		}
		}

		void guessFunction2()//This is where user enters their guess and displays whether they win or lose
		{
   		 	while (tracker == 0)
			  {
	    		cout << "\n\nEnter guess Player 2: ";
    			cin >> guess;
    			wordCheck();
    		}
    		if (tracker == 1)
    		{
        		star();
       	 		cout << "\n\n\nYou won! The word was " << entry << ".\n";
    		}
    		else
    		{
        		cout << "\nYou lost! The word was " << entry << ".\n";
    		}
		}

		void statReset()// Resets certain variables so that game can function properly
		{
    		tracker = 0;
    		s = 7;
    		y = 0;
    		z = 0;
		}
};

int main ()
{
	char playAgain = 'y';
  int gameChoice = 0;
  hangman disp;

  cout << "            Welcome to Hangman" << endl;
  do
  {
  	cout << "       Press 1 for Single Player" << endl;
  	cout << "       Press 2 for Multi Player" << endl;
  	cin >> gameChoice;
  	if(gameChoice == 1)
  	{
  		disp.gameStart();
  		disp.prevEnteredSet();
   		disp.statReset();
    	disp.hangerset();
    	disp.enterNum();
    	disp.guessFunction();
    	cout << "Play again? [Y/N]: ";
    	cin >> playAgain;
    	playAgain = tolower(playAgain);
  	}
  	else if (gameChoice == 2)
  	{
  		disp.player1Start();
    	disp.prevEnteredSet();
    	disp.statReset();
    	disp.hangerset();
    	disp.enterWord();
    	disp.player2Start();
    	disp.guessFunction2();
    	cout << "Play again? [Y/N]: ";
    	cin >> playAgain;
    	playAgain = tolower(playAgain);
  	}
  	else
  	{
  		cout << "Invalid input, try again." << endl;
  	}
  }while (playAgain == 'y');

	cin.get();
	return 0;
}
