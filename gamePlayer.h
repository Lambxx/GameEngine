#ifndef GAMEPLAYER_H_INCLUDED
#define GAMEPLAYER_H_INCLUDED

int evaluate(int board[7][6], int player);
int evaluateAI(int board[7][6], int AIplayer);
int minimax(int board[7][6], int depth, int playerTurn,bool maximizingPlayer);
int bestMove(int board[7][6], int depth, int player);
#endif