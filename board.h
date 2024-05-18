#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

void printBoard(int board[7][6]);
void addPiece(int board[7][6], int column, int player);
int checkWin(int board[7][6], int player);
#endif