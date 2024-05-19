#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>

void printBoard(int board[7][6]);
void addPiece(int board[7][6], int column, int player);
int checkWin(int board[7][6], int player);
bool validMove(int board[7][6], int column);
void getValidMoves(int board[7][6], int validMoves[7]);
#endif