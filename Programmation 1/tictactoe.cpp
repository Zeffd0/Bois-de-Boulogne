
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

enum class GameState { PLAYING, END };
enum class PlayerTurn { COMP, PLAYER };

void showGrid();
void checkWinLose();
void playOnCell(char, char);

char randomCell(char&);

bool endGame();
bool validInput(char);

GameState gameState = GameState::PLAYING;
PlayerTurn playerTurn;

char cell1 = '1';
char cell2 = '2';
char cell3 = '3';
char cell4 = '4';
char cell5 = '5';
char cell6 = '6';
char cell7 = '7';
char cell8 = '8';
char cell9 = '9';

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int flipACoin = rand() % 2;

    char playersMarker = 'n';
    char compsMarker = 'n';

    if (flipACoin == 0)
    {
        playerTurn = PlayerTurn::PLAYER;
        playersMarker = 'X';
        compsMarker = 'O';
        cout << "****** You Start ! ******\n=========================" << endl;
    }
    else
    {
        playerTurn = PlayerTurn::COMP;
        playersMarker = 'O';
        compsMarker = 'X';
        cout << "***** COMP Starts ! *****\n=========================" << endl;
    }

    while (gameState == GameState::PLAYING)
    {
        for (int numbrOfTurns = 1; numbrOfTurns <= 9; numbrOfTurns++)
        {

            showGrid();

            if (playerTurn == PlayerTurn::PLAYER)
            {

                bool turnIsOver = false;

                do
                {
                    char playerInput = 'n';

                    cout << "> Your Turn!" << endl;
                    cout << "Select an available Cell to play on, from the Grid. You can also enter R to randomly select a Cell." << endl;
                    cout << endl << "Input : ";

                    cin >> playerInput;

                    if (playerInput == 'R' || playerInput == 'r')
                    {
                        randomCell(playerInput);
                    }

                    if (validInput(playerInput))
                    {
                        playOnCell(playerInput, playersMarker);
                        cout << "---- You played on Cell : " << playerInput << " ----" << endl;
                        turnIsOver = true;
                    }
                    else
                    {
                        cout << "!!! Error. Invalid Input !!!" << endl;
                    }

                } while (!turnIsOver);

            }
            else
            {
                char compInput = randomCell(compInput);

                playOnCell(compInput, compsMarker);
                cout << "> COMPUTER Played on Cell : " << compInput << " <" << endl;
            }

            if (endGame())
            {
                checkWinLose();
                break;
            }

            if (playerTurn == PlayerTurn::PLAYER)
            {
                playerTurn = PlayerTurn::COMP;
            }
            else
            {
                playerTurn = PlayerTurn::PLAYER;
            }
        }

        if (gameState == GameState::PLAYING)
        {
            gameState = GameState::END;
            showGrid();
            cout << "***** It's a Tie! *****" << endl;
        }
    }
}

void showGrid()
{
    cout << "\t" << cell1 << " | " << cell2 << " | " << cell3 << "\n";
    cout << "\t" << char(196) << char(32) << char(197) << char(32) << char(196) << char(32) << char(197) << char(32) << char(196) << "\n";
    cout << "\t" << cell4 << " | " << cell5 << " | " << cell6 << "\n";
    cout << "\t" << char(196) << char(32) << char(197) << char(32) << char(196) << char(32) << char(197) << char(32) << char(196) << "\n";
    cout << "\t" << cell7 << " | " << cell8 << " | " << cell9 << "\n";
    cout << endl;
}

void playOnCell(char input, char marker)
{
    switch (input)
    {
    case '1':       cell1 = marker;     break;
    case '2':       cell2 = marker;     break;
    case '3':       cell3 = marker;     break;
    case '4':       cell4 = marker;     break;
    case '5':       cell5 = marker;     break;
    case '6':       cell6 = marker;     break;
    case '7':       cell7 = marker;     break;
    case '8':       cell8 = marker;     break;
    case '9':       cell9 = marker;     break;
    }
}

bool validInput(char input)
{
    switch (input)
    {
    case '1':       return cell1 == '1';  break;
    case '2':       return cell2 == '2';  break;
    case '3':       return cell3 == '3';  break;
    case '4':       return cell4 == '4';  break;
    case '5':       return cell5 == '5';  break;
    case '6':       return cell6 == '6';  break;
    case '7':       return cell7 == '7';  break;
    case '8':       return cell8 == '8';  break;
    case '9':       return cell9 == '9';  break;
    default:        return false;
    }
}

char randomCell(char& input)
{
    int rNumber = rand() % 9;

    do
    {
        rNumber = ((rNumber + 2) % 9);
        input = char(49 + rNumber);

    } while (!validInput(input));

    return input;
}

void checkWinLose()
{
    if (playerTurn == PlayerTurn::PLAYER)
    {
        gameState = GameState::END;
        showGrid();
        cout << "******* You Won! *******" << endl;
    }
    else
    {
        gameState = GameState::END;
        showGrid();
        cout << "******* You Lost! *******" << endl;
    }
}

bool endGame()
{
    return (cell1 == cell2 && cell2 == cell3)
        || (cell4 == cell5 && cell5 == cell6)
        || (cell7 == cell8 && cell8 == cell9)
        || (cell1 == cell4 && cell4 == cell7)
        || (cell2 == cell5 && cell5 == cell8)
        || (cell3 == cell6 && cell6 == cell9)
        || (cell1 == cell5 && cell5 == cell9)
        || (cell3 == cell5 && cell5 == cell7);
}
