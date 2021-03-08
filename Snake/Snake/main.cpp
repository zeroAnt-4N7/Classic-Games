#include <iostream>
#include <vector>
#include <Windows.h>
#include <random>
#include <ctime>



int main() {
	srand((unsigned)time(0));
	while (true) {
		char nBoard[30][15];
		int nTailX[100];
		int nTailY[100];
		int nDirection = 0;
		int x = 15, y = 7;
		nTailX[0] = x - 1;
		nTailY[0] = y;
		nTailX[1] = x - 2;
		nTailY[1] = y;
		nTailX[2] = x - 3;
		nTailY[2] = y;
		int nTail = 3;
		bool nGameOver = false;
		int nScore = 0;
		int nTime = 300;
		int nFruitX;
		int nFruitY;
		bool bSolve = false;
		
		int nRand, nRandy;
		while (true) {
			int t = 0;
			nRand = (rand() % 30) + 0;
			nRandy = (rand() % 15) + 0;
			for (int i = 0; i < nTail; i++) {
				if (!(nTailX[i] == nRand && nTailY[i] == nRandy))
					t++;
			}
			if (t == nTail && (x != nRand || y != nRandy)) {
				nFruitX = nRand;
				nFruitY = nRandy;
				break;
			}
		}

		while (!nGameOver) {
			
			if (GetAsyncKeyState('W') && !(nDirection == 3) && !bSolve)
				nDirection = 1;
			else if (GetAsyncKeyState('D') && !(nDirection == 4) && !bSolve)
				nDirection = 2;
			else if (GetAsyncKeyState('S') && !(nDirection == 1) && !bSolve)
				nDirection = 3;
			else if (GetAsyncKeyState('A') && !(nDirection == 2) && !(nDirection == 0) && !bSolve)
				nDirection = 4;
			else if (GetAsyncKeyState(VK_ESCAPE))
				nDirection = 0;
			else if (GetAsyncKeyState('L'))
				bSolve = true;

			if (bSolve) {
				if (nFruitY > y && !(nDirection == 1)) {
					int nT = 0;
					for (int i = 0; i < nTail; i++){
						if (!(nTailY[i] == y + 1 && nTailX[i] == x))
							nT++;
					}
					if(nT == nTail)
					nDirection = 3;
				}
				if (nFruitY > y && nDirection == 1) {
					int nT = 0;
					for (int i = 0; i < nTail; i++) {
						if (!(nTailY[i] == y + 1 && nTailX[i] == x))
							nT++;
					}
					if (nT == nTail)
						nDirection = 2;
					else
						nDirection = 4;
				}
				else if (nFruitY < y && !(nDirection == 3)) {
					int nT = 0;
					for (int i = 0; i < nTail; i++) {
						if (!(nTailY[i] == y - 1 && nTailX[i] == x))
							nT++;
					}
					if (nT == nTail)
						nDirection = 1;
				}
				else if (nFruitY < y && nDirection == 3) {
					int nT = 0;
					for (int i = 0; i < nTail; i++) {
						if (!(nTailY[i] == y - 1 && nTailX[i] == x))
							nT++;
					}
					if (nT == nTail)
						nDirection = 2;
					else
						nDirection = 4;
				}
				else if (nFruitX > x && !(nDirection == 4)) {
					int nT = 0;
					for (int i = 0; i < nTail; i++) {
						if (!(nTailY[i] == y && nTailX[i] == x+1))
							nT++;
					}
					if (nT == nTail)
						nDirection = 2;
				}
				else if (nFruitX > x && nDirection == 4) {
					int nT = 0;
					for (int i = 0; i < nTail; i++) {
						if (!(nTailY[i] == y && nTailX[i] == x + 1))
							nT++;
					}
					if (nT == nTail)
						nDirection = 1;
					else
						nDirection = 3;
				}
				else if (nFruitX < x && !(nDirection == 2)) {
					int nT = 0;
					for (int i = 0; i < nTail; i++) {
						if (!(nTailY[i] == y && nTailX[i] == x - 1))
							nT++;
					}
					if (nT == nTail)
						nDirection = 4;
				}
				else if (nFruitX < x && nDirection == 2) {
					int nT = 0;
					for (int i = 0; i < nTail; i++) {
						if (!(nTailY[i] == y && nTailX[i] == x - 1))
							nT++;
					}
					if (nT == nTail)
						nDirection = 3;
					else
						nDirection = 1;
				}
			}

			for (int i = nTail - 1; i >= 0; i--) {
				if (!(nDirection == 0)) {
					if (i == 0) {
						nTailX[0] = x;
						nTailY[0] = y;
					}
					else {
						nTailX[i] = nTailX[i - 1];
						nTailY[i] = nTailY[i - 1];
					}
				}
			}

			switch (nDirection)
			{
			default:
				break;
			case 1:
				if (y > 0)
					y--;
				else
					nGameOver = true;
				break;
			case 2:
				if (x < 29)
					x++;
				else
					nGameOver = true;
				break;
			case 3:
				if (y < 14)
					y++;
				else
					nGameOver = true;
				break;
			case 4:
				if (x > 0)
					x--;
				else
					nGameOver = true;
				
				break;
			}
			for (int i = 0; i < nTail; i++) {
				if (nTailX[i] == x && nTailY[i] == y)
					nGameOver = true;
			}
			if (nFruitX == x && nFruitY == y) {
				while (true) {
					int t = 0;
					nRand = (rand() % 30) + 0;
					nRandy = (rand() % 15) + 0;
					for (int i = 0; i < nTail; i++) {
						if (!(nTailX[i] == nRand && nTailY[i] == nRandy))
							t++;
					}
					if (t == nTail && (x != nRand || y != nRandy)) {
						nFruitX = nRand;
						nFruitY = nRandy;
						break;
					}
				}
				nScore += 10;
				if (nScore == 50 && nTime == 300)
					nTime = 250;
				else if (nScore == 100 && nTime == 250)
					nTime = 200;
				else if (nScore == 200 && nTime == 200)
					nTime = 150;
				else if (nScore == 300 && nTime == 150)
					nTime = 100;
				else if (nScore == 400 && nTime == 100)
					nTime = 75;
				else if (nScore == 500 && nTime == 75)
					nTime = 50;
				nTailX[nTail] = nTailX[nTail - 1];
				nTailY[nTail] = nTailY[nTail - 1];
				nTail++;
			}

			if (nGameOver)
				break;


			for (int i = 0; i < 30; i++) {
				for (int j = 0; j < 15; j++) {
					nBoard[i][j] = ' ';
				}
			}

			for (int i = 0; i < nTail; i++) {
				int nX = nTailX[i];
				int nY = nTailY[i];
				nBoard[nX][nY] = '#';
			}

			nBoard[x][y] = 'O';
			nBoard[nFruitX][nFruitY] = '$';
			system("cls");
			std::cout << " ------------------------------ \n";
			for (int i = 0; i < 15; i++) {
				std::cout << "|";
				for (int j = 0; j < 30; j++) {
					std::cout << nBoard[j][i];
				}
				std::cout << "|\n";
			}
			std::cout << " ------------------------------ \n";
			std::cout << "Score: " << nScore;
			Sleep(nTime);
		}  
		std::cout << "\n\n::> Game Over!\n";
		Sleep(2000);
		break;
	}
	return 0;
}