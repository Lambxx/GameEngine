
#include <stdio.h>
#include "board.h"
#include "gamePlayer.h"

int evaluate(int board[7][6], int player){
    // Evaluate the board
    int score = 0;
   if (checkWin(board, player) == player){
         return 9999;
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


   //  Check for 3 in a row with one space horizontally
    for(int row = 0; row < 6; row++){
        for(int col = 0; col < 7; col++){
            if(board[col][row] == player){
                if(col + 3 < 7){
                    if(board[col + 1][row] == player && board[col + 2][row] == player && board[col + 3][row] == 0){
                        score = 1000;
                    }
                }
                if(col - 3 >= 0){
                    if(board[col - 1][row] == player && board[col - 2][row] == player && board[col - 3][row] == 0){
                        score = 1000;
                    }
                }
            }
        }

    } 

     //Check for 3 in a row with one space vertically
    for(int col = 0; col < 7; col++){
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                if(row + 3 < 6){
                    if(board[col][row + 1] == player && board[col][row + 2] == player && board[col][row + 3] == 0){
                        score += 1000;
                    }
                }
                if(row - 3 >= 0){
                    if(board[col][row - 1] == player && board[col][row - 2] == player && board[col][row - 3] == 0){
                        score += 1000;
                    }
                }
            }
        }

    }


     //Check for 3 in a row with one space vertically other player
     int otherPlayer = 3 - player   ;
    for (int col = 0; col < 7; col++){
        for (int row = 0; row < 6; row++){
            if (board[col][row] == otherPlayer){
                if (row + 3 < 6){
                    if (board[col][row + 1] == otherPlayer && board[col][row + 2] == otherPlayer && board[col][row + 3] == 0){
                        score = -1000;
                    }
                }
                if (row - 3 >= 0){
                    if (board[col][row - 1] == otherPlayer && board[col][row - 2] == otherPlayer && board[col][row - 3] == 0){
                        score = -1000;
                    }
                }
            }
        }
    }

      

     //Check for 3 in a row with one space diagonally
    for(int col = 0; col < 7; col++){
        for(int row = 0; row < 6; row++){
            if(board[col][row] == player){
                // Check diagonal right
                if(col + 3 < 7 && row + 3 < 6){
                    if(board[col + 1][row + 1] == player && board[col + 2][row + 2] == player && board[col + 3][row + 3] == 0){
                        score = 1000;
                    }
                }
                // Check diagonal left
                if(col - 3 >= 0 && row + 3 < 6){
                    if(board[col - 1][row + 1] == player && board[col - 2][row + 2] == player && board[col - 3][row + 3] == 0){
                        score = 1000;
                    }
                }
            }
        } 

    }

   
    
         

    
    return score;
}

int evaluateAI(int board[7][6], int AIplayer){
    
        return evaluate(board, AIplayer) -  evaluate(board, 3 - AIplayer);
    
        
    
}

int minimax(int board[7][6], int depth, int playerTurn,bool maximizingPlayer){

// EVALUATE THE BOARD
    int score = evaluate(board, playerTurn) ;
  
   // BASE CASE
  if (depth == 0 || checkWin(board, 1) == 1 || checkWin(board, 2) == 2 || noMovesLeft(board)){
        return score;
    }
     int otherPlayer;
    if(playerTurn == 1){
        otherPlayer = 2;
    } else {
        otherPlayer = 1;
    }

    // Maximizing player case
    if(maximizingPlayer){
       int maxScore = -99999;
        for (int i = 0; i<7;i++){
            if(validMove(board, i)){
                int newBoard[7][6];
                for(int j = 0; j < 7; j++){
                    for(int k = 0; k < 6; k++){
                        newBoard[j][k] = board[j][k];
                    }
                }
                addPiece(newBoard, i, playerTurn);
                int newScore = minimax(newBoard, depth - 1, otherPlayer, false);
                if(newScore > maxScore){
                    maxScore = newScore;
                }
            }
        }
        return maxScore;
    }  else {
        int minScore = 99999;
        for (int i = 0; i<7;i++){
            if(validMove(board, i)){
                int newBoard[7][6];
                for(int j = 0; j < 7; j++){
                    for(int k = 0; k < 6; k++){
                        newBoard[j][k] = board[j][k];
                    }
                }
                addPiece(newBoard, i, playerTurn);
                int newScore = minimax(newBoard, depth - 1, otherPlayer, true);
                if(newScore < minScore){
                    minScore = newScore;
                }
            }
        }
        return minScore;
    }

}

int bestMove(int board[][6], int depth, int player){
    // try rmeve first dimentsion ?
    player = 1;
    int bestVal = 1000000;
    int bestMove = 0;
    for (int i = 0; i<7;i++){
        
        if(validMove(board, i)){
            int newBoard[7][6];
            for(int j = 0; j < 7; j++){
                for(int k = 0; k < 6; k++){
                    newBoard[j][k] = board[j][k];
                }
            }
            addPiece(newBoard, i, player);
            int moveVal = minimax(newBoard, depth, player, true);
            printf("Player %d move %d has value %d\n", player, i, moveVal);
           
            if(moveVal < bestVal){
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}
