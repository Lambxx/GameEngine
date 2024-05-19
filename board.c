#include <stdio.h>
/* To use the functions defined in Functions.c I need to #include Functions.h */
#include "board.h"
#include <stdbool.h>
void printBoard(int board[7][6]){
    printf("Printing board\n");
    // Print the board
    for(int row = 0; row < 6; row++){
        for(int col = 0; col < 7; col++){
            printf("%d ", board[col][row]);
        }
        printf("\n");
    }
}

void addPiece(int board[7][6], int column, int player){
    // Add a piece to the board
    for (int i = 5; i >= 0; i--){
        if(board[column][i] == 0){
            board[column][i] = player;
            break;
        }
    }
}

int checkWin(int board[7][6], int player){
    // Check for a win
    // Check horizontal
    int count = 0;
    for(int row = 0; row < 6; row++){
        count = 0;
         for(int col = 0; col<7;col++){
           if(board[col][row] == player){
               count ++;
           } else {
               count = 0;
           }
           if(count == 4){
              return player;
       }
       }
       
    }
   
    // Check vertical
  count = 0;
    for(int col = 0; col < 7; col++){
        count = 0;
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                count++;
            } else {
                count = 0;
            }
            if(count == 4){
            return player;
        }
        }
        
    }
  
    // Check diagonal
    // Check diagonal
    for(int col = 0; col < 7; col++){
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                // Check diagonal right
                if(col + 2 < 7 && row + 2 < 6){
                    if(board[col ][row] == player && board[col + 1][row + 1] == player && board[col + 2][row + 2] == player){
                        return player;
                    }
                }
                // Check diagonal left
                if(col - 2 >= 0 && row + 2 < 6){
                    if(board[col ][row ] == player && board[col - 1][row + 1] == player && board[col - 2][row + 2] == player){
                        return player;
                    }
                }
            }
        }
    }
    return -1;
}

// Function to check if a move is valid
bool validMove(int board[7][6], int column){
    for(int row = 0; row < 6; row++){
        if(board[column][row] == 0){
            return true;
        }
    }
    return false;
}

// Function to get the valid moves
void getValidMoves(int board[7][6], int validMoves[7]){
    for(int i = 0; i < 7; i++){
        if(validMove(board, i)){
            validMoves[i] = 1;
        } else {
            validMoves[i] = 0;
        }
    }
}

bool noMovesLeft(int board[7][6]){
    for(int i = 0; i < 7; i++){
        if(validMove(board, i)){
            return false;
        }
    }
    return true;
}
    

    