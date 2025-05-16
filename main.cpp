#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#define sleep_ms(ms) Sleep(ms)
#else
#include <unistd.h>
#define sleep_ms(ms) usleep((ms) * 1000)
#endif

using namespace std;

void printSeparator()
{
    cout << "**************************************************" << endl;
}

void printWelcome()
{
    printSeparator();
    cout << "*              WELCOME TO CASINO GAME            *" << endl;
    cout << "*            Developed by scientificoder         *" << endl;
    printSeparator();
}

int getValidBet(int balance)
{
    int bet;
    while (true)
    {
        cout << "Place your bet (Current Balance: $" << balance << "): ";
        cin >> bet;
        if (cin.fail() || bet <= 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid bet amount. Bet must be a positive number." << endl;
        }
        else if (bet > balance)
        {
            cout << "Bet cannot exceed your current balance." << endl;
        }
        else
        {
            return bet;
        }
    }
}

int getValidChoice(int minChoice, int maxChoice)
{
    int choice;
    while (true)
    {
        cout << "Enter your choice (" << minChoice << "-" << maxChoice << "): ";
        cin >> choice;
        if (cin.fail() || choice < minChoice || choice > maxChoice)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Try again." << endl;
        }
        else
        {
            return choice;
        }
    }
}

// Vegas Slot Game - 777 Slots
void playSlots(int &balance)
{
    printSeparator();
    cout << "Welcome to the [7.7.7] Vegas Slot Game!" << endl;
    int bet = getValidBet(balance);

    cout << "Spinning..." << endl;
    sleep_ms(1500);

    srand(time(0));
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    int num3 = rand() % 10;
    cout << "Slot Results: " << num1 << " " << num2 << " " << num3 << endl;

    if (num1 == 7 && num2 == 7 && num3 == 7)
    {
        cout << "Jackpot! Triple sevens! You win 10x your bet!" << endl;
        balance += bet * 10;
    }
    else if (num1 == num2 && num2 == num3)
    {
        cout << "Triple match! You win 5x your bet!" << endl;
        balance += bet * 5;
    }
    else if ((num1 % 2 == 0) && (num2 % 2 == 0) && (num3 % 2 == 0))
    {
        cout << "All even numbers! You win 2x your bet!" << endl;
        balance += bet * 2;
    }
    else if ((num1 % 2 != 0) && (num2 % 2 != 0) && (num3 % 2 != 0))
    {
        cout << "All odd numbers! You win 2x your bet!" << endl;
        balance += bet * 2;
    }
    else
    {
        cout << "No win this time. Better luck next spin!" << endl;
        balance -= bet;
    }
    cout << "Current Balance: $" << balance << endl;
    printSeparator();
}

// Guess The Number Game
void playGuessNumber(int &balance)
{
    printSeparator();
    cout << "Welcome to Guess The Number! Guess between 1 and 5." << endl;
    int bet = getValidBet(balance);

    int userGuess = 0;
    while (userGuess < 1 || userGuess > 5)
    {
        cout << "Enter your guess (1-5): ";
        cin >> userGuess;
        if (cin.fail() || userGuess < 1 || userGuess > 5)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid guess, please enter a number between 1 and 5." << endl;
            userGuess = 0;
        }
    }

    cout << "Checking..." << endl;
    sleep_ms(1500);

    srand(time(0));
    int computerNum = (rand() % 5) + 1;
    cout << "The computer chose: " << computerNum << endl;

    if (userGuess == computerNum)
    {
        cout << "Congrats! You guessed right and win 2x your bet!" << endl;
        balance += bet * 2;
    }
    else
    {
        cout << "Sorry, wrong guess. You lose your bet." << endl;
        balance -= bet;
    }
    cout << "Current Balance: $" << balance << endl;
    printSeparator();
}

// Roulette Game
void playRoulette(int &balance)
{
    printSeparator();
    cout << "Welcome to Roulette! Bet on numbers between 1 and 36." << endl;
    int bet = getValidBet(balance);

    int numBets;
    while (true)
    {
        cout << "On how many numbers do you want to place your bet? (1-36): ";
        cin >> numBets;
        if (cin.fail() || numBets < 1 || numBets > 36)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid number of bets. Enter a number between 1 and 36." << endl;
        }
        else
        {
            break;
        }
    }

    int betPerNumber = bet / numBets;
    cout << "You are betting $" << betPerNumber << " on each number." << endl;

    vector<int> numbers;
    int number;
    for (int i = 0; i < numBets; i++)
    {
        while (true)
        {
            cout << "Enter number " << (i + 1) << " (1-36): ";
            cin >> number;
            if (cin.fail() || number < 1 || number > 36)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid number. Please enter between 1 and 36." << endl;
            }
            else if (find(numbers.begin(), numbers.end(), number) != numbers.end())
            {
                cout << "Number already chosen. Pick a different number." << endl;
            }
            else
            {
                numbers.push_back(number);
                break;
            }
        }
    }

    cout << "Spinning the roulette wheel..." << endl;
    sleep_ms(1500);

    srand(time(0));
    int winningNumber = (rand() % 36) + 1;
    cout << "Winning Number: " << winningNumber << endl;

    if (find(numbers.begin(), numbers.end(), winningNumber) != numbers.end())
    {
        cout << "Congratulations! You win 36x your bet per number hit!" << endl;
        balance += betPerNumber * 36;
    }
    else
    {
        cout << "Sorry, no winning number hit. You lose your bet." << endl;
        balance -= bet;
    }

    cout << "Current Balance: $" << balance << endl;
    printSeparator();
}

int main()
{
    int balance = 1000;
    printWelcome();

    while (balance > 0)
    {
        cout << "Your current balance is $" << balance << endl;
        cout << "Choose a game to play:" << endl;
        cout << "1. Vegas Slot Game [7.7.7]" << endl;
        cout << "2. Guess The Number (1-5)" << endl;
        cout << "3. Roulette (1-36)" << endl;
        cout << "4. Quit" << endl;

        int choice = getValidChoice(1, 4);

        if (choice == 1)
        {
            playSlots(balance);
        }
        else if (choice == 2)
        {
            playGuessNumber(balance);
        }
        else if (choice == 3)
        {
            playRoulette(balance);
        }
        else
        {
            cout << "Thank you for playing! Goodbye!" << endl;
            break;
        }

        if (balance <= 0)
        {
            cout << "You've run out of money! Game over." << endl;
            break;
        }
    }

    return 0;
}
