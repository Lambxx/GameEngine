// Hello world program
#include <stdio.h>
#include "board.h" 


void gameController(){
 int m_board[7][6] = {0};
  
 
   

   printf("\n to end Game enter -1 else enter a number between 0 and 6 for collumn \n");
   int Col = 0;
   int player = 1;
   printBoard(m_board);
  while(Col != -1){
            printf("Player %d enter a column: ", player);
         scanf("%d", &Col);
         addPiece(m_board, Col, player);
         printBoard(m_board);
         int winner = checkWin(m_board, player);
         if(winner != -1){
              printf("Player %d wins\n", winner);
              break;
         }
         if (player == 1){
             player = 2;
             } else
            {
            player = 1;
            }
   }
}

int Test(){
    // Win horizontal
    int board[7][6] = {0};
    addPiece(board, 0, 1);
    addPiece(board, 1, 1);
    addPiece(board, 2, 1);
    addPiece(board, 3, 1);
    int winner = checkWin(board, 1);
    if(winner == 1){
        
        printf("Test 1 horizontal Win Passed\n");
    } else {
        printf("Test 1 horizontal Win Failed\n");
        return -1;
    }
    // Win vertical
    int Vboard[7][6] = {0};
    addPiece(Vboard, 0, 1);
    addPiece(Vboard, 0, 1);
    addPiece(Vboard, 0, 1);
    addPiece(Vboard, 0, 1);
     int Vwinner = checkWin(board, 1);
    if(Vwinner == 1){
        printf("Test 2 vertical Win Passed\n");
        
    } else {
        printf("Test 2 vertical Win Failed\n");
        return -1;
    }

    // Win diagonal test cases
    int Dboard[7][6] = {0};
    addPiece(Dboard, 0, 1);
    addPiece(Dboard, 1, 2);
    addPiece(Dboard, 1, 1);
    addPiece(Dboard, 2, 2);
    addPiece(Dboard, 2, 2);
    addPiece(Dboard, 2, 1);
    addPiece(Dboard, 3, 2);
    addPiece(Dboard, 3, 2);
    addPiece(Dboard, 3, 2);
    addPiece(Dboard, 3, 1);
    int Dwinner = checkWin(Dboard, 1);
    if(Dwinner == 1){
        printf("Test 3 diagonal Win Passed\n");
        
    } else {
        printf("Test 3 diagonal Win Failed\n");
        return -1;
    }

    // Win diagonal test cases Left diagonal
    int Dboard2[7][6] = {0};
    addPiece(Dboard2, 3, 1);
    addPiece(Dboard2, 2, 2);
    addPiece(Dboard2, 2, 1);
    addPiece(Dboard2, 1, 2);
    addPiece(Dboard2, 1, 2);
    addPiece(Dboard2, 1, 1);
    addPiece(Dboard2, 0, 2);
    addPiece(Dboard2, 0, 2);
    addPiece(Dboard2, 0, 2);
    addPiece(Dboard2, 0, 1);
    int Dwinner2 = checkWin(Dboard2, 1);
    if(Dwinner2 == 1){
        printf("Test 4 diagonal Win Passed\n");
        
    } else {
        printf("Test 4 diagonal Win Failed\n");
        return -1;
    }
    // Add more test cases for diagnal win



    return 1;

}

int main() {
   // printf() displays the string inside quotation
   // 7 columns and 6 rows all 0
  
    int pass = Test();
    if(pass == 1){
        printf("All tests passed\n");
    } else {
        printf("Tests failed\n");
    }
    gameController();
   return 0;
}