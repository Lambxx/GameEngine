
#include <stdio.h>
#include "board.h"
#include "gamePlayer.h"

int evaluate(int board[7][6], int player){
    // Evaluate the board
    int score = 0;
   if (checkWin(board, player) == player){
         return 9999;
    }
     // Check for 3 in a row with one space horizontally
    for(int row = 0; row < 6; row++){
        for(int col = 0; col < 7; col++){
            if(board[col][row] == player){
                if(col + 3 < 7){
                    if(board[col + 1][row] == player && board[col + 2][row] == player && board[col + 3][row] == 0){
                        score += 500;
                    }
                }
                if(col - 3 >= 0){
                    if(board[col - 1][row] == player && board[col - 2][row] == player && board[col - 3][row] == 0){
                        score += 500;
                    }
                }
            }
        }

    }

    // Check for 3 in a row with one space vertically
    for(int col = 0; col < 7; col++){
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                if(row + 3 < 6){
                    if(board[col][row + 1] == player && board[col][row + 2] == player && board[col][row + 3] == 0){
                        score += 500;
                    }
                }
                if(row - 3 >= 0){
                    if(board[col][row - 1] == player && board[col][row - 2] == player && board[col][row - 3] == 0){
                        score += 500;
                    }
                }
            }
        }

    }

    // Check for 3 in a row with one space diagonally
    for(int col = 0; col < 7; col++){
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                // Check diagonal right
                if(col + 3 < 7 && row + 3 < 6){
                    if(board[col + 1][row + 1] == player && board[col + 2][row + 2] == player && board[col + 3][row + 3] == 0){
                        score += 500;
                    }
                }
                // Check diagonal left
                if(col - 3 >= 0 && row + 3 < 6){
                    if(board[col - 1][row + 1] == player && board[col - 2][row + 2] == player && board[col - 3][row + 3] == 0){
                        score += 500;
                    }
                }
            }
        }

    }

    // Check for 2 in a row with two spaces horizontally
    
   for(int row = 0; row < 6; row++){
        for(int col = 0; col < 7; col++){
            if(board[col][row] == player){
                if(col + 3 < 7){
                    if(board[col + 1][row] == player && board[col + 2][row] == 0 && board[col + 3][row] == 0){
                        score += 500;
                    }
                }
                if(col - 3 >= 0){
                    if(board[col - 1][row] == player && board[col - 2][row] == 0 && board[col - 3][row] == 0){
                        score += 500;
                    }
                }
            }
        }

    }

    // Check for 2 in a row with two spaces vertically
      for(int col = 0; col < 7; col++){
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                if(row + 3 < 6){
                    if(board[col][row + 1] == player && board[col][row + 2] == 0 && board[col][row + 3] == 0){
                        score += 500;
                    }
                }
                if(row - 3 >= 0){
                    if(board[col][row - 1] == player && board[col][row - 2] == 0 && board[col][row - 3] == 0){
                        score += 500;
                    }
                }
            }
        }

    }

    // Check for 2 in a row with two spaces diagonally
     for(int col = 0; col < 7; col++){
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                // Check diagonal right
                if(col + 3 < 7 && row + 3 < 6){
                    if(board[col + 1][row + 1] == player && board[col + 2][row + 2] == 0 && board[col + 3][row + 3] == 0){
                        score += 500;
                    }
                }
                // Check diagonal left
                if(col - 3 >= 0 && row + 3 < 6){
                    if(board[col - 1][row + 1] == player && board[col - 2][row + 2] == 0 && board[col - 3][row + 3] == 0){
                        score += 500;
                    }
                }
            }
        }

    }

     // Check for 2 in a row with one spaces horizontally
    
   for(int row = 0; row < 6; row++){
        for(int col = 0; col < 7; col++){
            if(board[col][row] == player){
                if(col + 3 < 7){
                    if(board[col + 1][row] == 0 && board[col + 2][row] == 0 && board[col + 3][row] == 0){
                        score += 500;
                    }
                }
                if(col - 3 >= 0){
                    if(board[col - 1][row] == 0 && board[col - 2][row] == 0 && board[col - 3][row] == 0){
                        score += 500;
                    }
                }
            }
        }

    }

    // Check for 2 in a row with one spaces vertically
      for(int col = 0; col < 7; col++){
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                if(row + 3 < 6){
                    if(board[col][row + 1] == 0 && board[col][row + 2] == 0 && board[col][row + 3] == 0){
                        score += 500;
                    }
                }
                if(row - 3 >= 0){
                    if(board[col][row - 1] == 0 && board[col][row - 2] == 0 && board[col][row - 3] == 0){
                        score += 500;
                    }
                }
            }
        }

    }

    // Check for 2 in a row with one spaces diagonally
     for(int col = 0; col < 7; col++){
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                // Check diagonal right
                if(col + 3 < 7 && row + 3 < 6){
                    if(board[col + 1][row + 1] == 0 && board[col + 2][row + 2] == 0 && board[col + 3][row + 3] == 0){
                        score += 500;
                    }
                }
                // Check diagonal left
                if(col - 3 >= 0 && row + 3 < 6){
                    if(board[col - 1][row + 1] == 0 && board[col - 2][row + 2] == 0 && board[col - 3][row + 3] == 0){
                        score += 500;
                    }
                }
            }
        }

    }
    return score;
}

int evaluateAI(int board[7][6], int AIplayer){
    if (AIplayer == 1){
        return evaluate(board, 1) - evaluate(board, 2);
    } else {
        return evaluate(board, 2) - evaluate(board, 1);
    }
}

int minimax(int board[7][6], int depth, int playerTurn,int maximizingPlayer){
    int score = evaluateAI(board, maximizingPlayer);
    if (depth == 0 || checkWin(board, 1) == 1 || checkWin(board, 2) == 2){
        return score;
    }
    
}