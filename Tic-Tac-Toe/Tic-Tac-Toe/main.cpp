#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <Windows.h>
using namespace std;

// this function checks if the game is over.
// it returns 1, if somebody won,
// 0, if its a draw and
// 2, if game in  progress
int checkMate(std::vector<char>& cBoard)
{
    if (cBoard[0] == cBoard[1] && cBoard[1] == cBoard[2])
        return 1;
    else if (cBoard[3] == cBoard[4] && cBoard[4] == cBoard[5])
        return 1;
    else if (cBoard[6] == cBoard[7] && cBoard[7] == cBoard[8])
        return 1;
    else if (cBoard[0] == cBoard[4] && cBoard[4] == cBoard[8])
        return 1;
    else if (cBoard[0] == cBoard[3] && cBoard[3] == cBoard[6])
        return 1;
    else if (cBoard[2] == cBoard[5] && cBoard[5] == cBoard[8])
        return 1;
    else if (cBoard[1] == cBoard[4] && cBoard[4] == cBoard[7])
        return 1;
    else if (cBoard[2] == cBoard[4] && cBoard[4] == cBoard[6])
        return 1;

    else if (cBoard[0] != '1' && cBoard[1] != '2' && cBoard[2] != '3' && cBoard[3] != '4' && cBoard[4] != '5' && cBoard[5] != '6' && cBoard[6] != '7' && cBoard[7] != '8' && cBoard[8] != '9')
        return 0;

    else
        return 2;
}

// this function clears the screen and
// re-draws the game board
void drawBoard(std::vector<char>& cBoard, int nGameMod, char pMark, int nNums) {
    std::vector<char> cBoardNumLess = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    for (int i = 0; i < cBoard.size(); i++) {
        if (cBoard[i] == 'X' or cBoard[i] == 'O' || nNums == 1)
            cBoardNumLess[i] = cBoard[i];
    }

    system("cls");
    std::cout << "Tic-Tac-Toe\n\n";
    if (nGameMod == 1)
        std::cout << "Player 1 (X) - Player 2 (O)\n";
    else {
        char anpMark;
        if (pMark == 'X')
            anpMark = 'O';
        else {
            anpMark = 'X';
        }
        std::cout << "You (" << pMark << ") - Computer (" << anpMark << ")\n";
    }

    cout << "     |     |     \n" << "  " << cBoardNumLess[0] << "  |  " << cBoardNumLess[1] << "  |  " << cBoardNumLess[2] << "\n";
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << cBoardNumLess[3] << "  |  " << cBoardNumLess[4] << "  |  " << cBoardNumLess[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << cBoardNumLess[6] << "  |  " << cBoardNumLess[7] << "  |  " << cBoardNumLess[8] << endl;
    cout << "     |     |     " << endl << endl;
}

// this function is checking for "check condition"
// it returns TRUE if check being located and resolved (mate or draw)
// or FALSE if no check being detected
bool checkCheck(std::vector<char>& cBoard, char mark, char cnMark) {
    //lines
    if ((cBoard[0] == cBoard[1] && cBoard[1] == cnMark) && (cBoard[2] != 'X' && cBoard[2] != 'O')) {
        cBoard[2] = mark;
        return true;
    }
    else if ((cBoard[1] == cBoard[2] && cBoard[2] == cnMark) && (cBoard[0] != 'X' && cBoard[0] != 'O')) {
        cBoard[0] = mark;
        return true;
    }
    else if ((cBoard[3] == cBoard[4] && cBoard[4] == cnMark) && (cBoard[5] != 'X' && cBoard[5] != 'O')) {
        cBoard[5] = mark;
        return true;
    }
    else if ((cBoard[4] == cBoard[5] && cBoard[5] == cnMark) && (cBoard[3] != 'X' && cBoard[3] != 'O')) {
        cBoard[3] = mark;
        return true;
    }
    else if ((cBoard[6] == cBoard[7] && cBoard[7] == cnMark) && (cBoard[8] != 'X' && cBoard[8] != 'O')) {
        cBoard[8] = mark;
        return true;
    }
    else if ((cBoard[7] == cBoard[8] && cBoard[8] == cnMark) && (cBoard[6] != 'X' && cBoard[6] != 'O')) {
        cBoard[6] = mark;
        return true;
    }
    else if ((cBoard[0] == cBoard[2] && cBoard[2] == cnMark) && (cBoard[1] != 'X' && cBoard[1] != 'O')) {
        cBoard[1] = mark;
        return true;
    }
    else if ((cBoard[3] == cBoard[5] && cBoard[5] == cnMark) && (cBoard[4] != 'X' && cBoard[4] != 'O')) {
        cBoard[4] = mark;
        return true;
    }
    else if ((cBoard[6] == cBoard[8] && cBoard[8] == cnMark) && (cBoard[7] != 'X' && cBoard[7] != 'O')) {
        cBoard[7] = mark;
        return true;
    }

    //coloumns
    else if ((cBoard[0] == cBoard[3] && cBoard[3] == cnMark) && (cBoard[6] != 'X' && cBoard[6] != 'O')) {
        cBoard[6] = mark;
        return true;
    }
    else if ((cBoard[3] == cBoard[6] && cBoard[6] == cnMark) && (cBoard[0] != 'X' && cBoard[0] != 'O')) {
        cBoard[0] = mark;
        return true;
    }
    else if ((cBoard[1] == cBoard[4] && cBoard[4] == cnMark) && (cBoard[7] != 'X' && cBoard[7] != 'O')) {
        cBoard[7] = mark;
        return true;
    }
    else if ((cBoard[7] == cBoard[4] && cBoard[4] == cnMark) && (cBoard[1] != 'X' && cBoard[1] != 'O')) {
        cBoard[1] = mark;
        return true;
    }
    else if ((cBoard[2] == cBoard[5] && cBoard[5] == cnMark) && (cBoard[8] != 'X' && cBoard[8] != 'O')) {
        cBoard[8] = mark;
        return true;
    }
    else if ((cBoard[5] == cBoard[8] && cBoard[8] == cnMark) && (cBoard[2] != 'X' && cBoard[2] != 'O')) {
        cBoard[2] = mark;
        return true;
    }
    else if ((cBoard[0] == cBoard[6] && cBoard[6] == cnMark) && (cBoard[3] != 'X' && cBoard[3] != 'O')) {
        cBoard[3] = mark;
        return true;
    }
    else if ((cBoard[1] == cBoard[7] && cBoard[7] == cnMark) && (cBoard[4] != 'X' && cBoard[4] != 'O')) {
        cBoard[4] = mark;
        return true;
    }
    else if ((cBoard[2] == cBoard[8] && cBoard[8] == cnMark) && (cBoard[5] != 'X' && cBoard[5] != 'O')) {
        cBoard[5] = mark;
        return true;
    }

    //diagonals
    else if ((cBoard[0] == cBoard[4] && cBoard[4] == cnMark) && (cBoard[8] != 'X' && cBoard[8] != 'O')) {
        cBoard[8] = mark;
        return true;
    }
    else if ((cBoard[4] == cBoard[8] && cBoard[8] == cnMark) && (cBoard[0] != 'X' && cBoard[0] != 'O')) {
        cBoard[0] = mark;
        return true;
    }
    else if ((cBoard[0] == cBoard[8] && cBoard[8] == cnMark) && (cBoard[4] != 'X' && cBoard[4] != 'O')) {
        cBoard[4] = mark;
        return true;
    }
    else if ((cBoard[2] == cBoard[4] && cBoard[4] == cnMark) && (cBoard[6] != 'X' && cBoard[6] != 'O')) {
        cBoard[6] = mark;
        return true;
    }
    else if ((cBoard[6] == cBoard[4] && cBoard[4] == cnMark) && (cBoard[2] != 'X' && cBoard[2] != 'O')) {
        cBoard[2] = mark;
        return true;
    }
    else if ((cBoard[2] == cBoard[6] && cBoard[6] == cnMark) && (cBoard[4] != 'X' && cBoard[4] != 'O')) {
        cBoard[4] = mark;
        return true;
    }
    else
        return false;
}


int main() {
    while (true) {
        std::vector<char> cBoard = { '1','2','3','4','5','6','7','8','9' };

        srand((unsigned)time(0));

        int nInput;
        int i;
        int nCounter = 0;
        int difficulty = 0;
        char pMark = 'X';
        bool bGameOver = false;
        char mark;
        int nGameMod = 0;
        int nStart = 0;
        int add_set = 0;
        int nNums = 0;

        // get user-input settings

        while (nGameMod != 1 && nGameMod != 2) {
            system("cls");
            std::cout << "Choose who you want to play with:\n\n";
            std::cout << "1. A friend\n2. Computer\n\n::> Enter number: ";
            std::cin >> nGameMod;
            if (nGameMod != 1 && nGameMod != 2) {
                std::cout << "\n::> Invalid input, press ENTER to continue.\n";
                cin.ignore();
                cin.get();
            }
        }
        while (add_set != 1 && add_set != 2) {
            system("cls");
            std::cout << "Choose the action:\n\n";
            std::cout << "1. Start playing\n2. Additional settings\n\n::> Enter number: ";
            std::cin >> add_set;
            if (add_set != 1 && add_set != 2) {
                std::cout << "\n::> Invalid input, press ENTER to continue.\n";
                cin.ignore();
                cin.get();
            }
        }
        if (add_set == 2) {
            if (nGameMod == 2) {
                while (difficulty != 1 && difficulty != 2 && difficulty != 3) {
                    system("cls");
                    std::cout << "Choose difficulty: \n\n";
                    std::cout << "1. Easy\n";
                    std::cout << "2. Medium\n";
                    std::cout << "3. Hard\n\n";
                    std::cout << "::> Enter number: ";
                    std::cin >> difficulty;
                    if (difficulty != 1 && difficulty != 2 && difficulty != 3) {
                        std::cout << "\n::> Invalid input, press ENTER to continue.\n";
                        cin.ignore();
                        cin.get();
                    }
                }
                while (nStart != 1 && nStart != 2) {
                    system("cls");
                    std::cout << "Choose who plays first: \n\n";
                    std::cout << "1. You\n";
                    std::cout << "2. Computer\n\n";
                    std::cout << "::> Enter number: ";
                    std::cin >> nStart;
                    if (nStart != 1 && nStart != 2) {
                        std::cout << "\n::> Invalid input, press ENTER to continue.\n";
                        cin.ignore();
                        cin.get();
                    }
                }
                int nUsrIn = 0;
                while (nUsrIn != 1 && nUsrIn != 2) {
                    system("cls");
                    std::cout << "Choose the side:\n\n";
                    std::cout << "1. (X)\n2. (O)\n\n::> Enter number: ";
                    std::cin >> nUsrIn;
                    if (nUsrIn == 1)
                        pMark = 'X';
                    else if (nUsrIn == 2)
                        pMark = 'O';
                    else {
                        std::cout << "\n::> Invalid input, press ENTER to continue.\n";
                        cin.ignore();
                        cin.get();
                    }
                }
                while (nNums != 1 && nNums != 2) {
                    system("cls");
                    std::cout << "Do you want numbers to be displayed on the board: \n\n";
                    std::cout << "1. Yes\n";
                    std::cout << "2. No\n\n";
                    std::cout << "::> Enter number: ";
                    std::cin >> nNums;
                    if (nNums != 1 && nNums != 2) {
                        std::cout << "\n::> Invalid input, press ENTER to continue.\n";
                        cin.ignore();
                        cin.get();
                    }
                }
            }
            else {
                while (nNums != 1 && nNums != 2) {
                    system("cls");
                    std::cout << "Do you want numbers to be displayed on the board: \n\n";
                    std::cout << "1. Yes\n";
                    std::cout << "2. No\n\n";
                    std::cout << "::> Enter number: ";
                    std::cin >> nNums;
                    if (nNums != 1 && nNums != 2) {
                        std::cout << "\n::> Invalid input, press ENTER to continue.\n";
                        cin.ignore();
                        cin.get();
                    }
                }
            }
        }
        else {
            nNums = 1;
            difficulty = 2;
            pMark = 'X';
            nStart = 1;
        }


        int turn = nStart;

        // main loop
        while (!bGameOver) {
            drawBoard(cBoard, nGameMod, pMark, nNums);

            if (turn % 2 == 0)
                turn = 2;
            else
                turn = 1;

            // Player 1 move
            if (turn == 1) {
                if (nGameMod == 2)
                    std::cout << "::> Enter a move:  ";
                else
                    std::cout << "::> Player 1 turn:  ";
                std::cin >> nInput;

                mark = pMark;

                if (nInput == 1 && cBoard[0] == '1')
                    cBoard[0] = mark;
                else if (nInput == 2 && cBoard[1] == '2')
                    cBoard[1] = mark;
                else if (nInput == 3 && cBoard[2] == '3')
                    cBoard[2] = mark;
                else if (nInput == 4 && cBoard[3] == '4')
                    cBoard[3] = mark;
                else if (nInput == 5 && cBoard[4] == '5')
                    cBoard[4] = mark;
                else if (nInput == 6 && cBoard[5] == '6')
                    cBoard[5] = mark;
                else if (nInput == 7 && cBoard[6] == '7')
                    cBoard[6] = mark;
                else if (nInput == 8 && cBoard[7] == '8')
                    cBoard[7] = mark;
                else if (nInput == 9 && cBoard[8] == '9')
                    cBoard[8] = mark;
                else {
                    std::cout << "::> Invalid move, press ENTER to continue.";
                    turn--;
                    cin.ignore();
                    cin.get();
                }

            }
            // Computer move
            else if (turn == 2 && nGameMod == 2) {
                // easy randomised AI version
                if (difficulty == 1) {
                    int nRand = (rand() % 8) + 0;
                    char mark;
                    if (pMark == 'X')
                        mark = 'O';
                    else
                        mark = 'X';
                    while (cBoard[nRand] == 'X' || cBoard[nRand] == 'O') {
                        nRand = (rand() % 8) + 0;
                    }
                    cBoard[nRand] = mark;
                }
                // medium difficulty
                else if (difficulty == 2) {
                    char mark;
                    if (pMark == 'X')
                        mark = 'O';
                    else
                        mark = 'X';

                    // checking for mate possiabilities
                    if (!checkCheck(cBoard, mark, mark)) {
                        // defending from possiable checks
                        if (!checkCheck(cBoard, mark, pMark)) {
                            // if no check detected,
                            // move to the corner,
                            // if not moved there before.
                            bool bCExist = true;
                            if ((cBoard[0] != mark && cBoard[2] != mark) && (cBoard[6] != mark && cBoard[8] != mark))
                                bCExist = false;
                            if ((cBoard[0] != 'X' && cBoard[0] != 'O') && !bCExist)
                                cBoard[0] = mark;
                            else if ((cBoard[2] != 'X' && cBoard[2] != 'O') && !bCExist)
                                cBoard[2] = mark;
                            else if ((cBoard[6] != 'X' && cBoard[6] != 'O') && !bCExist)
                                cBoard[6] = mark;
                            else if ((cBoard[8] != 'X' && cBoard[8] != 'O') && !bCExist)
                                cBoard[8] = mark;
                            else {
                                // randomly play in irrelevant positions.
                                int nRand = (rand() % 8) + 0;
                                while (cBoard[nRand] == 'X' || cBoard[nRand] == 'O') {
                                    nRand = (rand() % 8) + 0;
                                }
                                cBoard[nRand] = mark;
                            }

                        }
                    }

                }
                // hard version
                else {
                    char mark;
                    if (pMark == 'X')
                        mark = 'O';
                    else
                        mark = 'X';

                    // checking for mate possiabilities
                    if (!checkCheck(cBoard, mark, mark)) {
                        // defending from possiable checks
                        if (!checkCheck(cBoard, mark, pMark)) {
                            // move if no check detected
                            // move in center if possiable
                            if (cBoard[4] != 'X' && cBoard[4] != 'O')
                                cBoard[4] = mark;
                            // if not, move to corner, if not moved there before.
                            else {
                                bool bCExist = true;
                                if ((cBoard[0] != mark && cBoard[2] != mark) && (cBoard[6] != mark && cBoard[8] != mark))
                                    bCExist = false;
                                if ((cBoard[0] != 'X' && cBoard[0] != 'O') && !bCExist)
                                    cBoard[0] = mark;
                                else if ((cBoard[2] != 'X' && cBoard[2] != 'O') && !bCExist)
                                    cBoard[2] = mark;
                                else if ((cBoard[6] != 'X' && cBoard[6] != 'O') && !bCExist)
                                    cBoard[6] = mark;
                                else if ((cBoard[8] != 'X' && cBoard[8] != 'O') && !bCExist)
                                    cBoard[8] = mark;
                                else {
                                    // randomly play in irrelevant positions.
                                    int nRand = (rand() % 8) + 0;
                                    while (cBoard[nRand] == 'X' || cBoard[nRand] == 'O') {
                                        nRand = (rand() % 8) + 0;
                                    }
                                    cBoard[nRand] = mark;
                                }
                            }
                        }
                    }

                }
            }
            // Player 2 move
            else {
                if (nGameMod == 2)
                    std::cout << "::> Enter a move:  ";
                else
                    std::cout << "::> Player 2 turn:  ";
                std::cin >> nInput;

                mark = 'O';

                if (nInput == 1 && cBoard[0] == '1')
                    cBoard[0] = mark;
                else if (nInput == 2 && cBoard[1] == '2')
                    cBoard[1] = mark;
                else if (nInput == 3 && cBoard[2] == '3')
                    cBoard[2] = mark;
                else if (nInput == 4 && cBoard[3] == '4')
                    cBoard[3] = mark;
                else if (nInput == 5 && cBoard[4] == '5')
                    cBoard[4] = mark;
                else if (nInput == 6 && cBoard[5] == '6')
                    cBoard[5] = mark;
                else if (nInput == 7 && cBoard[6] == '7')
                    cBoard[6] = mark;
                else if (nInput == 8 && cBoard[7] == '8')
                    cBoard[7] = mark;
                else if (nInput == 9 && cBoard[8] == '9')
                    cBoard[8] = mark;
                else {
                    std::cout << "::> Invalid move, press ENTER to continue.";
                    turn--;
                    cin.ignore();
                    cin.get();
                }

            }

            // check if game over
            i = checkMate(cBoard);
            if (i == 0)
                bGameOver = true;

            drawBoard(cBoard, nGameMod, pMark, nNums);
            if (i == 1 && nGameMod == 2) {
                if (turn == 1) {
                    cout << "::> You win!";
                    bGameOver = true;
                }
                else if (turn == 2) {
                    cout << "::> Computer wins!";
                    bGameOver = true;
                }
            }
            else if (i == 1) {
                if (turn == 1) {
                    cout << "::> Player 1 wins!";
                    bGameOver = true;
                }
                else if (turn == 2) {
                    cout << "::> Player 2 wins!";
                    bGameOver = true;
                }
            }
            else
                cout << "::> Game draw";
            turn++;
            nCounter++;
        }
        cin.ignore();
        cin.get();
        int in = 0;
        while (!(in == 1 || in == 2)) {
            system("cls");
            std::cout << "Wanna play again?\n\n1. Yes\n2. No\n\n::> Enter a number: ";
            std::cin >> in;
            if (!(in == 1 || in == 2)) {
                std::cout << "\n::> Invalid input, press ENTER to continue.\n";
                cin.ignore();
                cin.get();
            }
            else
                break;
        }
        if (in == 2)
            break;
    }
    return 0;
}
