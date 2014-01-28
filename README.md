// Hangman!
// Word is Poo
#include <iostream>
using namespace std;

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

int main ()
{
    // Declare Variables
    char entry;
    string pOne = "Today's sentence is 'I just took a _ _ _'\n";
    string pTwo = "Today's sentence is 'I just took a P _ _'\n";
    string pThree = "Today's sentence is 'I just took a _ o o'\n";
    string pFour = "Today's sentence is 'I just took a P o o'\n";
    string corr = "Correct! \n";
    string incorr = "Incorrect! \n";
    int stat,x,y;

    // Request User Input
    cout << "Welcome to Hangman!\n";
    cout << pOne;
    cout << "Enter your guess: ";
    cin >> entry;

    // The Rest
    entry = tolower(entry);
    stat = 7;
    x = false;
    y = false;
    while (stat !=0)
    {
        if (entry == 'p' || entry == 'o')
        {
            if (entry == 'p')
            {
                x = true;
                pOne = pTwo;
            }
            else if (entry == 'o')
            {
                y = true;
                pOne = pThree;
            }
            if (x == true && y == true)
            {
                pOne = pFour;
                cout << "You won! \n";
                cout << corr;
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
        else
        {
            --stat;
            cout << incorr;
            hanger(stat);
            if (stat >0)
            {
                cout << "Enter your guess: ";
                cin >> entry;
                entry = tolower(entry);
            }
            else
            {
                cout << "Sorry you lose.";
                break;
            }
        }
    }


    return 0;
}
