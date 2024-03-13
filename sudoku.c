#include <stdio.h>
#include <string.h>

#define ROW_LENGTH 9
#define COL_LENGTH 9
#define true 1
#define false 0

int is_valid(char board[ROW_LENGTH][COL_LENGTH]);

int main(void){
  char board[ROW_LENGTH][COL_LENGTH] = {{'5','3','.','.','7','.','.','.','.'}
                                       ,{'6','.','.','1','9','5','.','.','.'}
                                       ,{'.','9','8','.','.','.','.','6','.'}
                                       ,{'8','.','.','.','6','.','.','.','3'}
                                       ,{'4','.','.','8','.','3','.','.','1'}
                                       ,{'7','.','.','.','2','.','.','.','6'}
                                       ,{'.','6','.','.','.','.','2','8','.'}
                                       ,{'6','.','.','4','1','9','.','.','5'}
                                       ,{'.','.','.','.','8','.','.','7','9'}};
				
  if(is_valid(board) == 1){
    printf("Board is valid\n");
  }else{
    printf("Board is not valid\n");
  }
  return 0;
}

int is_valid(char board[ROW_LENGTH][COL_LENGTH]){
  int rval = 1;
  int checked[ROW_LENGTH] = {0}; //Check array for every number, if 1 the number is already found in row/col/cell and the board is invalid if found again in the same dimension

  //Check rows
  for(int i = 0; i < ROW_LENGTH; i++){
    for(int j = 0; j < COL_LENGTH; j++){
      if(board[i][j] > '0' && board[i][j] <= '9'){
	if(checked[board[i][j] - '1'] == true){ //board - '1' to subtract the ascii value of 1 (49) to get the correct index within range 0-8
	  return 0;
	}else{
	  checked[board[i][j] - '1'] = true; //Set the correct number as found
	}
      }
    }
    memset(checked, 0, sizeof(checked)); //Make all the check values 0 again
  }

  //Check columns
  for(int i = 0; i < ROW_LENGTH; i++){
    for(int j = 0; j < COL_LENGTH; j++){
      if(board[j][i] > '0' && board[j][i] <= '9'){
        if(checked[board[j][i] - '1'] == true){
          return 0;
        }else{
          checked[board[j][i] - '1'] = true;
        }
      }
    }
    memset(checked, 0, sizeof(checked));
  }
  
  return rval;
}

