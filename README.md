// Hangman!
// Word is lollipop
#include <iostream>
using namespace std;

void star(int y) // Star for winning
{
    if (y == y)
    {
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
}

void hanger(int x) // Function added for display of current hangman status
{
    if (x==7)
    {
        cout << "|-----\n";
        cout << "|     \n";
        cout << "|     \n";
        cout << "|     \n";
        cout << "|     \n";
        cout << "|     \n";
        cout << "------\n";
    }
    if (x == 6)
    {
	cout << "|-----\n";
	cout << "|   | \n";
	cout << "|     \n";
	cout << "|     \n";
	cout << "|     \n";
	cout << "|     \n";
	cout << "------\n";
    }
    else if (x == 5)
    {
	cout << "|-----\n";
	cout << "|   | \n";
	cout << "|   O \n";
	cout << "|     \n";
	cout << "|     \n";
	cout << "|     \n";
	cout << "------\n";
    }
    else if (x == 4)
    {
	cout << "|-----\n";
	cout << "|   | \n";
	cout << "|   O \n";
	cout << "|   | \n";
	cout << "|     \n";
	cout << "|     \n";
	cout << "------\n";
    }
    else if (x == 3)
    {
	cout << "|-----\n";
	cout << "|   | \n";
	cout << "|   O \n";
	cout << "|  <| \n";
	cout << "|     \n";
	cout << "|     \n";
	cout << "------\n";
    }
    else if (x == 2)
    {
	cout << "|-----\n";
	cout << "|   | \n";
	cout << "|   O \n";
	cout << "|  <|>\n";
	cout << "|     \n";
	cout << "|     \n";
	cout << "------\n";
   }
   else if (x == 1)
   {
	cout << "|-----\n";
	cout << "|   | \n";
	cout << "|   O \n";
	cout << "|  <|>\n";
	cout << "|  (  \n";
	cout << "|     \n";
	cout << "------\n";
   }
   else if (x == 0)
   {
	cout << "|-----\n";
	cout << "|   | \n";
	cout << "|   O \n";
	cout << "|  <|>\n";
	cout << "|  ( )\n";
	cout << "|     \n";
	cout << "------\n";
   }
}

void playerS(int z) // Users pick if theyre player 1 or 2
{
    if (z == z)
    {
    	int player1,player2,indicator = false,indicator2 = false;
    	char playerOne[25];
    	char playerTwo[25];
    	char decision;

    	while (indicator == false)
    	{
        	while (indicator2 == false)
        	{
        		cout << "Enter name: ";
        		cin >> playerOne;
        		cout << "Player 1 or 2? ";
        		cin >> player1;
        		cout << "Other player enter name: ";
        		cin >> playerTwo;

        		if (player1 == 1)
        		{
            			player2 = 2;
            			break;
        		}
        		else if (player1 == 2)
        		{
        			player2 = 1;
        			break;
        		}
        		else
        		{
            			cout << "Try again." << endl;
        		}
  
    			cout << playerOne << " is player " << player1 << endl;
    			cout << playerTwo << " is player " << player2 << endl;
    			cout << "Is this correct? [Y/N] ";
    			cin >> decision;
    			decision = tolower(decision);

    			if (decision == 'y')
    			{
        			indicator = true;
    			}
    			else if (decision == 'n')
    			{
        			cout << "Okay let's try again." << endl;
    			}
    			else
    			{
        			cout << "Try again." << endl;
    			}
      	     	}
    	}
}
}

int main ()
{
    // Declare Variables
    char entry;
    char inputAnswer[20];
    string answer = "lollipop";
    string answer2 = "Lollipop";
    string pOne = "I went to the candy store and bought a '_ _ _ _ _ _ _ _'\n";
    string corr = "Correct! \n";
    string incorr = "Incorrect! \n";
    int stat,x;

    // Request User Input
    cout << "Welcome to Hangman!\n";
    cout << "Today's sentence is: " << pOne;
    cout << "Enter your guess or press [G/g] to guess the word: ";
    cin >> entry;

    // The Rest
    entry = tolower(entry);
    stat = 7;
    x = 0;
    while (stat != 0)
    {
        if (entry == 'p' || entry == 'o' || entry == 'l' || entry == 'i')
        {
            if (entry == 'l')
            {
                x++;
                pOne[40] = 'l';
                pOne[44] = 'l';
                pOne[46] = 'l';
            }
            else if (entry == 'o')
            {
                x++;
                pOne[42] = 'o';
                pOne[52] = 'o';
            }
            else if (entry == 'p')
            {
                x++;
                pOne[50] = 'p';
                pOne[54] = 'p';
            }
            else if (entry == 'i')
            {
                x++;
                pOne[48] = 'i';
            }
            if (x == 4)
            {
                cout << "You won! \n";
                star(x);
                hanger(stat);
                cout << pOne;
                break;
            }
            cout << corr;
            hanger(stat);
            cout << pOne;
            cout << "Enter your guess: ";
            cin >> entry;
            entry = tolower(entry);
        }
        else if (entry != 'g')
        {
            --stat;
            cout << incorr;
            hanger(stat);
            cout << pOne;
            if (stat >0)
            {
                cout << "Enter your guess: ";
                cin >> entry;
                entry = tolower(entry);
            }
            else
            {
                cout << "Sorry you lose. The word was lollipop.";
                break;
            }
        }
        else if (entry == 'g')
        {
            cout << "Enter your guess: ";
            cin >> inputAnswer;

            if (inputAnswer == answer || inputAnswer == answer2)
            {
                cout << "Correct you won!\n";
                star(x);
                hanger(stat);
                cout << "I went to the candy store and bought a lollipop!\n";
                break;
            }
            else
            {
                cout << incorr;
                hanger(stat);
                cout << pOne;
                cout << "Enter your guess: ";
                cin >> entry;
                entry = tolower(entry);
            }
        }
    }


    return 0;
}
