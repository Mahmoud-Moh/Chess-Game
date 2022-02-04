


/******************************** Chess Game **************************************/
/**Students:
1- Mahmoud Mohamed Abdelaziz - ID: 19016578
2- Moamen Mahmoud Gharib Hafez - ID: 19016208
**/

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>


#define False 0
#define True 1
#define FPS 30
#define FRAME_TARGET_TIME (1000/FPS) //frame duration
#define block_size 75 //size of piece rectangle

 #define GRID 8
 #define NUM_OF_PIECES 6

/**defines and declarations for history part
*undo - redo*/
/**----------------------------------------*/
char moved_piece[30];
bool undo_flag = false;
/**----------------------------------------*/

// all surfaces used for GUI
SDL_Window* window1 = NULL;
SDL_Renderer* renderer1 = NULL;
SDL_Surface* surface1_forboard = NULL;
SDL_Surface* surface1 = NULL;
SDL_Surface* surface2 = NULL;
SDL_Surface* surface3 = NULL;
SDL_Surface* surface4 = NULL;
SDL_Surface* surface5 = NULL;
SDL_Surface* surface6 = NULL;
SDL_Surface* surface7 = NULL;
SDL_Surface* surface8 = NULL;
SDL_Surface* surface9 = NULL;
SDL_Surface* surface10 = NULL;
SDL_Surface* surface11 = NULL;
SDL_Surface* surface12 = NULL;
SDL_Surface* surface13 = NULL;
SDL_Surface* surface14 = NULL;
SDL_Surface* surface15 = NULL;
SDL_Surface* surface16 = NULL;
SDL_Surface* surface17 = NULL;
SDL_Surface* surface18 = NULL;
SDL_Surface* surface19 = NULL;
SDL_Surface* surface20 = NULL;
SDL_Surface* surface21 = NULL;
SDL_Surface* surface22 = NULL;
SDL_Surface* surface23 = NULL;
SDL_Surface* surface24 = NULL;
SDL_Surface* surface25 = NULL;
SDL_Surface* surface26 = NULL;
SDL_Surface* surface27 = NULL;
SDL_Surface* surface28 = NULL;
SDL_Surface* surface29 = NULL;
SDL_Surface* surface30 = NULL;
SDL_Surface* surface31 = NULL;
SDL_Surface* surface32 = NULL;


//all Textures used for GUI
SDL_Texture* texture1 = NULL;

SDL_Texture* king_w = NULL;
SDL_Texture* king_b = NULL;
SDL_Texture* queen_w = NULL;
SDL_Texture* queen_b = NULL;
SDL_Texture* knight1_w = NULL;
SDL_Texture* knight1_b = NULL;
SDL_Texture* knight2_w = NULL;
SDL_Texture* knight2_b = NULL;
SDL_Texture* bishop1_w = NULL;
SDL_Texture* bishop1_b = NULL;
SDL_Texture* bishop2_w = NULL;
SDL_Texture* bishop2_b = NULL;
SDL_Texture* rock1_w = NULL;
SDL_Texture* rock1_b = NULL;
SDL_Texture* rock2_w = NULL;
SDL_Texture* rock2_b = NULL;
SDL_Texture* pawn1_w = NULL;
SDL_Texture* pawn2_w = NULL;
SDL_Texture* pawn3_w = NULL;
SDL_Texture* pawn4_w = NULL;
SDL_Texture* pawn5_w = NULL;
SDL_Texture* pawn6_w = NULL;
SDL_Texture* pawn7_w = NULL;
SDL_Texture* pawn8_w = NULL;
SDL_Texture* pawn1_b = NULL;
SDL_Texture* pawn2_b = NULL;
SDL_Texture* pawn3_b = NULL;
SDL_Texture* pawn4_b = NULL;
SDL_Texture* pawn5_b = NULL;
SDL_Texture* pawn6_b = NULL;
SDL_Texture* pawn7_b = NULL;
SDL_Texture* pawn8_b = NULL;

SDL_Texture* undobutton_i = NULL;
SDL_Texture* undobutton_f = NULL;

SDL_Texture* check_white = NULL;
SDL_Texture* check_black = NULL;
SDL_Texture* gamover = NULL;

SDL_Texture* savegame_i = NULL;
SDL_Texture* savegame_f = NULL;

SDL_Texture* loadgame_i = NULL;
SDL_Texture* loadgame_f = NULL;
SDL_Texture* background = NULL;
//all
SDL_Rect king_w_rect;
SDL_Rect king_b_rect ;
SDL_Rect queen_w_rect ;
SDL_Rect queen_b_rect ;
SDL_Rect knight1_w_rect;
SDL_Rect knight1_b_rect;
SDL_Rect knight2_w_rect;
SDL_Rect knight2_b_rect;
SDL_Rect bishop1_w_rect;
SDL_Rect bishop1_b_rect;
SDL_Rect bishop2_w_rect;
SDL_Rect bishop2_b_rect;
SDL_Rect rock1_w_rect;
SDL_Rect rock2_w_rect;
SDL_Rect rock1_b_rect;
SDL_Rect rock2_b_rect;
SDL_Rect pawn1_w_rect;
SDL_Rect pawn2_w_rect;
SDL_Rect pawn3_w_rect;
SDL_Rect pawn4_w_rect;
SDL_Rect pawn5_w_rect;
SDL_Rect pawn6_w_rect;
SDL_Rect pawn7_w_rect;
SDL_Rect pawn8_w_rect;
SDL_Rect pawn1_b_rect;
SDL_Rect pawn2_b_rect;
SDL_Rect pawn3_b_rect;
SDL_Rect pawn4_b_rect;
SDL_Rect pawn5_b_rect;
SDL_Rect pawn6_b_rect;
SDL_Rect pawn7_b_rect;
SDL_Rect pawn8_b_rect;

SDL_Rect background_rect;

SDL_Rect boarditself;

SDL_Rect undobutton_i_rect;
SDL_Rect undobutton_f_rect;

SDL_Rect check_white_rect;
SDL_Rect check_black_rect;

SDL_Rect gameover_rect;

SDL_Rect savegame_rect;
SDL_Rect loadgame_rect;

SDL_Rect background2_rect;

SDL_Texture* background2 = NULL;

//logical integer indicating whether the game is running or not.
int game_is_running = False;

/** variables used for drag and drop**/
int leftMouseButtonDown = 0;
SDL_Point mousePos;
SDL_Point clickOffset;
SDL_Rect* selectedRect = NULL;
/**---------------------------------**/


/****-------------------------------------------------------------------------------------****/
/****-------------------------------------------------------------------------------------****/
/****---------------------------- ((control of the game)) --------------------------------****/
/****-------------------------------------------------------------------------------------****/
/****-------------------------------------------------------------------------------------****/

char gameBoard[GRID][GRID];
void initialize_game_board(char gameBoard[GRID][GRID]){
for(int i=1; i<GRID-1;i++){ //initialize gameBoard
		for(int j=0;j<GRID;j++){
			if(i==1)
	        	gameBoard[i][j] = 'p'; //white pawns -whole row
	        else if(i==6)
	        	gameBoard[i][j] = 'P'; //black pawns - whole row
	       	else
	       		gameBoard[i][j] = '-';//no pieces in the middle of the board
	    }
    }
	    //initialize all the pieces which are not pawn - USING NUMBERS IN INITIALIZIATION WITH MOAB'S PERMISSION!
	    //black is
	   gameBoard[0][0]= 'r';
	   gameBoard[7][0]= 'R';
	   gameBoard[0][1]= 'n';
	   gameBoard[7][1]= 'N';
	   gameBoard[0][2]= 'b';
	   gameBoard[7][2]= 'B';
	   gameBoard[0][3]= 'q';
	   gameBoard[7][3]= 'Q';
	   gameBoard[0][4]= 'k';
	   gameBoard[7][4]= 'K';
	   gameBoard[0][5]= 'b';
	   gameBoard[7][5]= 'B';
	   gameBoard[0][6]= 'n';
	   gameBoard[7][6]= 'N';
	   gameBoard[0][7]= 'r';
	   gameBoard[7][7]= 'R';
}

//struct used to define all specs of a move.
 typedef struct elem_t {
	int dstRow; // destination row
	int dstCol; // destination column
	int startRow; // start row
	int startCol; // start column
	char fig; // what figure was moved
	char prevFig; // what figure was captured
	int gameStatus; // game status before the move
	char player; // whose move that was
} elem;

//numerical constants for the validity of move
#define ILLEGAL_FIGURE 5
#define ILLEGAL_MOVE 4
#define ALLOWED_MOVE 8
int there_is_capture;

/**function used for checking validity of the move**/
int isValidMove(char gameBoard[GRID][GRID], elem* element){
	int row=0,col=0;
	if(element->prevFig == '-'){ // checks if there is a figure in start point
		return ILLEGAL_FIGURE;}
	if(!((element->player=='w'&&isupper(element->prevFig)) || (element->player=='b'&&islower(element->prevFig)))){ // checks if figure is current player's figure
		return ILLEGAL_FIGURE;}
    if(!allowedMove(gameBoard, element) || !noOverlap(gameBoard, element)){
        return ILLEGAL_MOVE;
    }
    return ALLOWED_MOVE;
}

int allowedMove(char gameBoard[GRID][GRID], elem* element){

	switch(element->prevFig){ //checks  if the figure can move in the specific direction the user entered
    case 'p':
    case 'P':
        return(pawnMove(gameBoard, element));
    break;

	case 'B':
	case 'b'://checks bishop move
		return(bishopMove(element));
    break;
	case 'R':
	case 'r'://checks rook move
	    return(rookMove(element));
    break;
	case 'N':
	case 'n':
		return (knightMove(gameBoard, element));
    break;
	case 'Q':
    case 'q':
        return queenMove(element);
    break;
    case 'k':
	case 'K'://checks knight/king move
	    return kingMove(gameBoard, element);
    break;
	}
}

int pawnMove(char gameBoard[GRID][GRID], elem* element){

	 if(element->player == 'w'){ // white player move
		 if(element->startRow == 6){ // can move two cells if it is in initial cell
            if(element->startCol == element->dstCol){
			 if((element->dstRow-element->startRow ==-2 || element->dstRow-element->startRow == -1) && gameBoard[element->dstRow][element->dstCol] == '-'){
				 there_is_capture = 0;
				 return 1;}
			 else
                return 0;
            }else if((element->dstCol - element->startCol) == 1 || (element->dstCol - element->startCol) == -1){
                if((islower(gameBoard[element->dstRow][element->dstCol])) && (element->dstRow-element->startRow) == -1 ){
                    there_is_capture = 1;
                    return 1;
                    }
                else
                    return 0;
                }else{
                return 0;}
		 }else{ //not row 6
		     if(element->startCol == element->dstCol){
                if((element->dstRow - element->startRow) == -1 && gameBoard[element->dstRow][element->dstCol] == '-'){
                    return 1;}
                else
                    return 0;
                }else if(element->dstCol - element->startCol == 1 || element->dstCol - element->startCol == -1){ //if capture
                     if((islower(gameBoard[element->dstRow][element->dstCol])) && (element->dstRow-element->startRow) == -1 ){
                        there_is_capture = 1;
                        return 1;
                        }
                     else
                        return 0;
                }else{
                    return 0;
                    }
		 }
	 }else if (element->player == 'b'){
	     if(element->startRow == 1){ // can move two cells if it is in initial cell
            if(element->startCol == element->dstCol){
			 if((element->dstRow-element->startRow ==2 || element->dstRow-element->startRow == 1) && gameBoard[element->dstRow][element->dstCol] == '-'){
				 return 1;}
			 else
                return 0;
            }else if(element->dstCol - element->startCol == 1 || element->dstCol - element->startCol == -1){//if capture
                if((isupper(gameBoard[element->dstRow][element->dstCol])) && element->dstRow-element->startRow == 1 ){
                    there_is_capture = 1;
                    return 1;
                    }
                else
                    return 0;
                }else{
                return 0;}
		 }else{
		     if(element->startCol == element->dstCol){
                if(element->dstRow - element->startRow == 1 && gameBoard[element->dstRow][element->dstCol] == '-'){
                    return 1;}
                else
                    return 0;
                }else if(element->dstCol - element->startCol == 1 || element->dstCol - element->startCol == -1){
                     if((isupper(gameBoard[element->dstRow][element->dstCol])) && element->dstRow-element->startRow == 1 ){
                        there_is_capture = 1;
                        return 1;
                        }
                     else{
                        return 0;}
                }else{
                    return 0;
                    }
		 }

	 }
 }

 int bishopMove(elem* element){
    int col,row;
	if((element->dstCol-element->startCol)==0 && (element->dstRow-element->startRow)==0) // stay is not valid
		return 0;
	col=element->dstCol-element->startCol;
	row=element->dstRow-element->startRow;
	col=abs(col); row=abs(row);
	if(col==row)
	   return 1;
	else
	   return 0;
}

int rookMove(elem* element){
	if((element->dstCol-element->startCol)==0 && (element->dstRow-element->startRow)==0) // stay is not valid
		return 0;
	if((element->dstCol != element->startCol) && (element->dstRow != element->startRow))	// move can not be in both row and col
	       return 0;
	else
	       return 1;
}

int knightMove(char gameBoard[GRID][GRID], elem* element){
	if((abs(element->dstCol-element->startCol) == 2) && (abs(element->dstRow-element->startRow) == 1)){ // two horizontal + one vertical
		 return 1;}
	if((abs(element->dstCol-element->startCol) == 1) && (abs(element->dstRow-element->startRow) == 2)){// one horizontal + two vertical
		 return 1;}
	return 0;
}

int queenMove(elem* element){
	return (rookMove(element) || bishopMove(element)); // diagonal move or horizontal/vertical move
}

int kingMove(elem* element){
	if(abs(element->dstCol-element->startCol)>1 || abs(element->dstRow-element->startRow)>1){
		return 0;}
	else if((element->dstCol-element->startCol)==0 && (element->dstRow-element->startRow)==0){ // stay is not valid
		return 0;}
	else{return 1;}// one cell move in any direction
}


/*overlap*/

int noOverlap(char gameBoard[GRID][GRID], elem* element){

	switch(element->prevFig){ //Checks if the move given doesn't overlap other pieces

	case 'P':
	case 'p': //checks pawn overlap
		return pawnOverlap(gameBoard,element);
	case 'B':
	case 'b'://checks bishop overlap
		return bishopOverlap(gameBoard,element);

	case 'R':
	case 'r'://checks rook overlap
		return rookOverlap(gameBoard,element);

	case 'N':
	case 'n':
	case 'K':
	case 'k'://checks knight/king overlap
		return kingOrKnightOverlap(gameBoard,element);

	case 'Q':
	case 'q'://checks queen overlap
		return queenOverlap(gameBoard,element);
	}
	return 0;
}

int pawnOverlap(char gameBoard[GRID][GRID],elem* element){ //returns true if the move is fine- the overlap is legal or no overlap

	int curr_row_checked=0;
	if(abs(element->dstRow - element->startRow)==1){ // moves one cell forward
		 if (element->startCol ==element->dstCol) // column not change
		     return(gameBoard[element->dstRow][element->dstCol] == '-');//if the cell is empty the move can be done

		 else if (abs(element->startCol -element->dstCol) == 1){ // capture
		      if(element->player == 'w' && islower(gameBoard[element->dstRow][element->dstCol])){
                there_is_capture = 1;
                return 1;
		      }else if(element->player == 'b' && isupper(gameBoard[element->dstRow][element->dstCol])){
                there_is_capture = 1;
		      return 1;
		      }
		 }
	}else if(abs(element->dstRow - element->startRow)==2){ //two moves forward
		 if(element->player == 'w') // white player moves up on board
			 curr_row_checked=element->startRow-1;
		 else // black player moves down on board
			 curr_row_checked=element->startRow+1;
		 if (gameBoard[curr_row_checked][element->dstCol] == '-' && gameBoard[element->dstRow][element->dstCol] == '-') //checks if the two steps don't overlap
			 return 1;
		 else
		 return 0;
	 }
	 return 0;
}


int bishopOverlap(char gameBoard[GRID][GRID],elem* element){ //returns true if the move is fine- the overlap is legal or no overlap
	int curr_row_checked=0, curr_col_checked=0;
	int there_is_overlap = 0;
	if (element->dstRow > element->startRow){
		if (element->dstCol > element->startCol){ //moving in south east
			curr_row_checked=element->startRow+1;
			curr_col_checked=element->startCol+1;

			while (curr_row_checked!=element->dstRow){ //while that's not the dst cell
			    if(gameBoard[curr_row_checked][curr_col_checked] != '-'){//checks if the step is not an overlap
				there_is_overlap = 1;}
				curr_row_checked++;
				curr_col_checked++;
			}
		}
		else //moving in south west
		{
			curr_row_checked=element->startRow+1;
			curr_col_checked=element->startCol-1;
			while (curr_row_checked!=element->dstRow){//while that's not the dst cell
				if (gameBoard[curr_row_checked][curr_col_checked] != '-') //checks if the step is not an overlap
					there_is_overlap = 1;
				curr_row_checked=curr_row_checked+1;
				curr_col_checked=curr_col_checked-1;
			}
		}
	}
	else{
		if (element->startCol>element->dstCol){ //moving in north west
			curr_row_checked=element->startRow-1;
			curr_col_checked=element->startCol-1;
			while (curr_row_checked!=element->dstRow){ //while that's not the dst cell
				if (gameBoard[curr_row_checked][curr_col_checked] != '-'){//checks if the step is not an overlap
					there_is_overlap = 1;}
				curr_row_checked=curr_row_checked-1;
				curr_col_checked=curr_col_checked-1;
			}
		}
		else //moving on north east
		{
			curr_row_checked=element->startRow-1;
			curr_col_checked=element->startCol+1;
			while (curr_row_checked!=element->dstRow){//while that's not the dst cell
				if (gameBoard[curr_row_checked][curr_col_checked] != '-') //checks if the step is not an overlap
					there_is_overlap = 1;
				curr_row_checked=curr_row_checked-1;
				curr_col_checked=curr_col_checked+1;
			}
		}
	}
	if(abs(element->dstRow - element->startRow)== 1 && abs(element->dstCol - element->startCol) == 1){
    if (element->player == 'w' && islower(gameBoard[element->dstRow][element->dstCol])){there_is_capture = 1;}
	else if(element->player == 'b' && isupper(gameBoard[element->dstRow][element->dstCol])){there_is_capture = 1;}
	}

	if(!there_is_overlap){
		if(gameBoard[element->dstRow][element->dstCol] == '-')
			return 1;
		else if(element->player == 'w' && islower(gameBoard[element->dstRow][element->dstCol])){
			there_is_capture = 1; return 1; }
		else if(element->player == 'b' && isupper(gameBoard[element->dstRow][element->dstCol])){
			there_is_capture = 1; return 1; }
		else
		    return 0;
		}else{
		return 0;}
}

int rookOverlap(char gameBoard[GRID][GRID],elem* element){ //returns true if the move is fine- the overlap is legal or no overlap

	int curr_col_checked=0, curr_row_checked=0;
	int there_is_overlap = 0;
	if (element->startRow==element->dstRow){ //moving horizontally
		if (element->dstCol>element->startCol){//moving right
			curr_col_checked=element->startCol+1;
			while (curr_col_checked!=element->dstCol){
				if (gameBoard[element->dstRow][curr_col_checked] != '-'){ //checks if the step is not an overlap
				there_is_overlap = 1; }
				curr_col_checked++;
			}
		}
		else if(element->dstCol < element->startCol){ //moving left
			curr_col_checked=element->startCol-1;
			while (curr_col_checked!=element->dstCol){
				if (gameBoard[element->dstRow][curr_col_checked] != '-') {//checks if the step is not an overlap
				    there_is_overlap = 1;}
				curr_col_checked--;
			}
		}
	}
	else{ //moving vertically
		if (element->dstRow>element->startRow){ //moving downwards(to the south)
			curr_row_checked=element->startRow+1;
			while (curr_row_checked!=element->dstRow){
				if (gameBoard[curr_row_checked][element->dstCol] != '-'){//checks if the step is not an overlap
				there_is_overlap = 1;}
				curr_row_checked++;
			}
		}
		else{ //moving to the north
			curr_row_checked=element->startRow-1;
			while (curr_row_checked!=element->dstRow){
				if (gameBoard[curr_row_checked][element->dstCol] != '-'){//checks if the step is not an overlap
				there_is_overlap = 1;}
				curr_row_checked--;
			}
		}
	}
	if((abs(element->dstRow - element->startRow)==1 && abs(element->dstCol - element->startCol)==0)||(abs(element->dstCol - element->startCol)==1 && abs(element->dstRow - element->startRow)==0)){
	if (element->player == 'w' && islower(gameBoard[element->dstRow][element->dstCol])){
		there_is_capture = 1;}
	else if(element->player == 'b' && isupper(gameBoard[element->dstRow][element->dstCol])){
		there_is_capture = 1;}
	}
	if(!there_is_overlap){
		if(gameBoard[element->dstRow][element->dstCol] == '-')
			return 1;
		else if(element->player == 'w' && islower(gameBoard[element->dstRow][element->dstCol])){
			there_is_capture = 1; return 1; }
		else if(element->player == 'b' && isupper(gameBoard[element->dstRow][element->dstCol])){
			there_is_capture = 1; return 1; }
		else
			return 0;
		}else{
		return 0;}
}

int kingOrKnightOverlap(char gameBoard[GRID][GRID],elem* element){//returns true if the move is fine- the overlap is legal or no overlap

	if(gameBoard[element->dstRow][element->dstCol] == '-'){
        return 1;
	}else if(element->player == 'w'){
		if(islower(gameBoard[element->dstRow][element->dstCol])){
	    there_is_capture = 1;
		return 1;}
		else{return 0;}
	}else if(element->player == 'b'){
		if(isupper(gameBoard[element->dstRow][element->dstCol])){
	    there_is_capture = 1;
		return 1;}
		else{return 0;}
	}
}

int queenOverlap(char gameBoard[GRID][GRID] ,elem* element){ //returns true if the move is fine- the overlap is legal or no overlap
int col, row;
col=abs(element->dstCol-element->startCol);
row=abs(element->dstRow-element->startRow);
	if ((col == row) && (col != 0 && col!= 0)) //if the queen wants to move diagonal
		return bishopOverlap(gameBoard,element); //checks if "bishop" doesn't overlap
	else
        return rookOverlap(gameBoard,element); //the queen moves left or right - checks if "rook" doesn't overlap
}

int check1flag=0;
int check2flag=0;

int isCheck(char gameBoard[GRID][GRID], elem* element){
	int check1 =0, check2=0;
	int row=0,col=0;
	if(element->player == 'w'){ //get white king place
		for(int i=0; i<8; i++){
		   for(int j=0; j<8; j++){
		       if(gameBoard[i][j] == 'K'){
			   row = i;
			   col = j;
			   }
		   }
		}
	}
	else{//get black_king place
	     for(int i=0; i<8; i++){
		   for(int j=0; j<8; j++){
		       if(gameBoard[i][j] == 'k'){
			   row = i;
			   col = j;
			   }
		   }
		}
	}
	check1 = pieceUnderAttack(gameBoard,element,row,col); //check if the current player's king is under attack
if(check1){ //player's king is threatened
if(element->player=='w'){
check1flag = 1;
return 1;}
else if(element->player =='b'){
check2flag = 1;
return 1;}
}else{
if(element->player=='w')
check1flag = 0;
else if(element->player =='b')
check2flag = 0;
}

	//switchPlayer
	if(element->player == 'w'){
	element->player = 'b';
	//get black_king place
	     for(int i=0; i<8; i++){
		   for(int j=0; j<8; j++){
		       if(gameBoard[i][j] == 'k'){
			   row = i;
			   col = j;
			   }
		   }
		}
	}
	else{
	element->player = 'w';
	for(int i=0; i<8; i++){
		   for(int j=0; j<8; j++){
		       if(gameBoard[i][j] == 'K'){
			   row = i;
			   col = j;
			   }
		   }
		}
	}

	check2 = pieceUnderAttack(gameBoard,element, row,col);//check if the other player's king is under attack
	char enemy = element->player;
	//reswitch players.
	if(element->player == 'w'){
	element->player = 'b';
	//get black_king place
	     for(int i=0; i<8; i++){
		   for(int j=0; j<8; j++){
		       if(gameBoard[i][j] == 'k'){
			   row = i;
			   col = j;
			   }
		   }
		}
	}
	else{
	element->player = 'w';
	for(int i=0; i<8; i++){
		   for(int j=0; j<8; j++){
		       if(gameBoard[i][j] == 'K'){
			   row = i;
			   col = j;
			   }
		   }
		}
	}

if(check2){ //player's enemy is threatened
if(enemy=='w'){
check1flag = 1;
return 1;}
else if(enemy =='b'){
check2flag = 1;
return 1;}
}else{ //player's enemy is not threatened
if(enemy=='w'){
check1flag = 0; return 0;}
else if(enemy =='b'){
check2flag = 0; return 0;}
}
}

/**int isCheck_small(char gameBoard[GRID][GRID], char playersym);**/

int pieceUnderAttack(char gameBoard[GRID][GRID], elem* element, int row,int col){
    int flago = 0;
	elem newelement; //new struct represents the possible moves from enemy that threatens player's king
	newelement.dstRow = row;
	newelement.dstCol = col;
	if(element->player == 'w'){newelement.player ='b';}
	else if(element->player == 'b'){newelement.player = 'w';}

	if(element->player == 'w'){newelement.fig = 'K';}
	else{newelement.fig = 'k';}

	for (int i=0;i<GRID;i++){ //scan all board
		for (int j=0;j<GRID;j++){

            newelement.prevFig = gameBoard[i][j];
			if ((element->player=='w' && islower(gameBoard[i][j])) || (element->player=='b' && isupper(gameBoard[i][j]))){//check if the figure is the opponnent's figure
			newelement.startRow = i;
			newelement.startCol = j;
			int isValidMove1 = isValidMove(gameBoard, &newelement);
			int noOverlap1 = noOverlap(gameBoard, &newelement);
			if((isValidMove1==8) && noOverlap1){
			return 1;
			}
			else{
                flago = 1;
			}
		   }
	   }
	}
	if(flago){return 0;}
}
/**
int pieceUnderAttackSmall(char gameBoard[GRID][GRID], char playerSym, int row,int col);

int possibleMoves(char player,char gameiBoard[GRID][GRID], int row, int col);
int possiblePawnMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col);
int possibleBishopMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col);
int possibleRookMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col);
int possibleKnightMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col);
int possibleQueenMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col);
int possibleKingMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col);**/


static char newBoard[GRID][GRID];

void CopyBoard(char gamaBoard[GRID][GRID]){
     for(int i=0; i<GRID; i++){
	    for(int j=0; i<GRID; j++){
		   newBoard[i][j] = gamaBoard[i][j];
		   }
	}
}


/****-------------------------------------------------------------------------------------****/
/****-------------------------------------------------------------------------------------****/


/****-------------------------------------------------------------------------------------****/
/****-------------------------------------------------------------------------------------****/
int last_frame_time = 0;

/**prototype for loadTexture, close functions**/
SDL_Texture* loadTexture();
void loadpieces();
void close();

/**Initializing
* window - Renderer **/
int initialize_window(void){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){ //if any thing not zero, smth bad happened
        printf("Error initalizing SDL");
        return False; //return  if error happened
    }

    window1 = SDL_CreateWindow("udemy course", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);
    if(!window1){
        printf("error creating sdl window");
        return False;
    }
    renderer1 = SDL_CreateRenderer(window1, -1, 0);
    if(!renderer1){
        printf("error creating sdl renderer");
        return False;
    }
    loadMedia();
    loadpieces();
    SDL_SetRenderDrawColor(renderer1, 127, 193, 193, 80);
    //SDL_SetRenderDrawColor(renderer1,255, 195, 101, 50);
    initialize_game_board(gameBoard);
    return True;

}
/**checking if media was loaded or not**/
int loadMedia()
{
	//Loading success flag
	int success = True;

	//Load PNG texture
	 texture1 = loadTexture();
	if( texture1 == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = False;
	}

	return success;
}

void setup(){

    background_rect.x = 690;
    background_rect.y = 150;
    background_rect.w = 110;
    background_rect.h = 130;

    background2_rect.x = 0;
    background2_rect.y = 150;
    background2_rect.w = 130;
    background2_rect.h = 130;

    rock1_w_rect.x = 100;
    rock1_w_rect.y = 800-75;
    rock1_w_rect.h = 75;
    rock1_w_rect.w = 75;

    rock2_w_rect.x = 800-100-75;
    rock2_w_rect.y = 800-75;
    rock2_w_rect.h = 75;
    rock2_w_rect.w = 75;

    rock1_b_rect.x = 100;
    rock1_b_rect.y = 200;
    rock1_b_rect.h = 75;
    rock1_b_rect.w = 75;

    rock2_b_rect.x = 800-100-75;
    rock2_b_rect.y = 200;
    rock2_b_rect.h = 75;
    rock2_b_rect.w = 75;

    boarditself.x = 100;
    boarditself.y = 200;
    boarditself.w = 600;
    boarditself.h = 600;

    knight1_w_rect.x = 100+75;
    knight1_w_rect.y = 800-75;
    knight1_w_rect.w = 75;
    knight1_w_rect.h = 75;

    knight2_w_rect.x = 800-100-75-75;
    knight2_w_rect.y = 800-75;
    knight2_w_rect.w = 75;
    knight2_w_rect.h = 75;

    knight1_b_rect.x = 100+75;
    knight1_b_rect.y = 200;
    knight1_b_rect.h = 75;
    knight1_b_rect.w = 75;

    knight2_b_rect.x = 800-100-2*75;
    knight2_b_rect.y = 200;
    knight2_b_rect.h = 75;
    knight2_b_rect.w = 75;

    bishop1_w_rect.x = 100+2*75;
    bishop1_w_rect.y = 800-75;
    bishop1_w_rect.w = 75;
    bishop1_w_rect.h = 75;

    bishop2_w_rect.x = 800-100 - 3*75;
    bishop2_w_rect.y = 800-75;
    bishop2_w_rect.w = 75;
    bishop2_w_rect.h = 75;

    bishop1_b_rect.x = 100+2*75;
    bishop1_b_rect.y = 200;
    bishop1_b_rect.h = 75;
    bishop1_b_rect.w = 75;

    bishop2_b_rect.x = 800-100 - 3*75;
    bishop2_b_rect.y = 200;
    bishop2_b_rect.h = 75;
    bishop2_b_rect.w = 75;

    queen_w_rect.x = 100+3*75;
    queen_w_rect.y = 800-75;
    queen_w_rect.h = 75;
    queen_w_rect.w = 75;

    queen_b_rect.x = 100+3*75;
    queen_b_rect.y = 200;
    queen_b_rect.h = 75;
    queen_b_rect.w = 75;

    king_w_rect.x = 100+4*75;
    king_w_rect.y = 800-75;
    king_w_rect.h = 75;
    king_w_rect.w = 75;

    king_b_rect.x = 100+4*75;
    king_b_rect.y = 200;
    king_b_rect.h = 75;
    king_b_rect.w = 75;

    pawn1_w_rect.x = 100;
    pawn1_w_rect.y = 800-2*75;
    pawn1_w_rect.h = 75;
    pawn1_w_rect.w = 75;

    pawn2_w_rect.x = 100+75;
    pawn2_w_rect.y = 800-2*75;
    pawn2_w_rect.h = 75;
    pawn2_w_rect.w = 75;

    pawn3_w_rect.x =  100+2*75;
    pawn3_w_rect.y =800-2*75;
    pawn3_w_rect.h = 75;
    pawn3_w_rect.w = 75;

    pawn4_w_rect.x = 100+3*75;
    pawn4_w_rect.y = 800-2*75;
    pawn4_w_rect.h = 75;
    pawn4_w_rect.w = 75;

    pawn5_w_rect.x = 100+4*75;
    pawn5_w_rect.y = 800-2*75;
    pawn5_w_rect.h = 75;
    pawn5_w_rect.w =75;

    pawn6_w_rect.x = 100+5*75;
    pawn6_w_rect.y = 800-2*75;
    pawn6_w_rect.h = 75;
    pawn6_w_rect.w =75;

    pawn7_w_rect.x = 100+6*75;
    pawn7_w_rect.y = 800-2*75;
    pawn7_w_rect.h = 75;
    pawn7_w_rect.w = 75;

    pawn8_w_rect.x = 100+7*75;
    pawn8_w_rect.y = 800-2*75;
    pawn8_w_rect.h = 75;
    pawn8_w_rect.w = 75;

    pawn1_b_rect.x = 100;
    pawn1_b_rect.y = 200+75;
    pawn1_b_rect.h = 75;
    pawn1_b_rect.w = 75;

    pawn2_b_rect.x = 100+1*75;
    pawn2_b_rect.y = 200+75;
    pawn2_b_rect.h = 75;
    pawn2_b_rect.w = 75;

    pawn3_b_rect.x =  100+2*75;
    pawn3_b_rect.y =200+75;
    pawn3_b_rect.h = 75;
    pawn3_b_rect.w = 75;

    pawn4_b_rect.x = 100+3*75;
    pawn4_b_rect.y = 200+75;
    pawn4_b_rect.h = 75;
    pawn4_b_rect.w = 75;

    pawn5_b_rect.x = 100+4*75;
    pawn5_b_rect.y = 200+75;
    pawn5_b_rect.h = 75;
    pawn5_b_rect.w = 75;

    pawn6_b_rect.x = 100+5*75;
    pawn6_b_rect.y = 200+75;
    pawn6_b_rect.h = 75;
    pawn6_b_rect.w =75;

    pawn7_b_rect.x =100+6*75;
    pawn7_b_rect.y = 200+75;
    pawn7_b_rect.h = 75;
    pawn7_b_rect.w = 75;

    pawn8_b_rect.x = 100+7*75;
    pawn8_b_rect.y = 200+75;
    pawn8_b_rect.h = 75;
    pawn8_b_rect.w = 75;

    undobutton_i_rect.x= 580;
    undobutton_i_rect.y = 20;
    undobutton_i_rect.h = 60;
    undobutton_i_rect.w = 160;

    undobutton_f_rect.x= 580;
    undobutton_f_rect.y = 20;
    undobutton_f_rect.h = 60;
    undobutton_f_rect.w = 160;

    check_white_rect.x = 300;
    check_white_rect.y = 150;
    check_white_rect.h = 50;
    check_white_rect.w = 100;

    check_black_rect.x = 360;
    check_black_rect.y = 150;
    check_black_rect.h = 50;
    check_black_rect.w = 100;

    gameover_rect.x = 200;
    gameover_rect.y = 100;
    gameover_rect.h = 70;
    gameover_rect.w = 200;

    savegame_rect.x = 350;
    savegame_rect.y = 10;
    savegame_rect.w = 120;
    savegame_rect.h = 80;

    loadgame_rect.x = 350;
    loadgame_rect.y = 100;
    loadgame_rect.w = 120;
    loadgame_rect.h = 80;
}
SDL_Rect* undobutton_f_rect_p = &undobutton_f_rect;

SDL_Rect* arr_of_rects[32] = {&rock1_w_rect, &rock2_w_rect, &knight1_w_rect, &knight2_w_rect, &bishop1_w_rect, &bishop2_w_rect,
&queen_w_rect, &king_w_rect, &pawn1_w_rect, &pawn2_w_rect, &pawn3_w_rect, &pawn4_w_rect, &pawn5_w_rect, &pawn6_w_rect, &pawn7_w_rect, &pawn8_w_rect,
&rock1_b_rect, &rock2_b_rect, &knight1_b_rect, &knight2_b_rect, &bishop1_b_rect, &bishop2_b_rect, &queen_b_rect, &king_b_rect,
&pawn1_b_rect, &pawn2_b_rect, &pawn3_b_rect, &pawn4_b_rect, &pawn5_b_rect, &pawn6_b_rect, &pawn7_b_rect, &pawn8_b_rect};


const char *pieces_names[32] = {"rock1_w","rock2_w","knight1_w","knight2_w","bishop1_w","bishop2_w",
"queen_w","king_w","pawn1_w","pawn2_w","pawn3_w","pawn4_w","pawn5_w","pawn6_w","pawn7_w","pawn8_w",
"rock1_b","rock2_b","knight1_b","knight2_b","bishop1_b","bishop2_b","queen_b","king_b",
"pawn1_b","pawn2_b","pawn3_b","pawn4_b","pawn5_b","pawn6_b","pawn7_b","pawn8_b"};

int history_list[100][8];
/**===========================================================================**/
/**============================ save and load ================================**/
/**===========================================================================**/
void savefunction1(char M[8][8]){
      for(int i=0; i<GRID; i++){

      FILE *ch ;
      ch = fopen("Boardsaved.txt","w") ;
      for(int i = 0 ; i < 8 ; i++)
      {
        for(int j =0 ; j < 8 ; j++)
      {
          fprintf(ch ,"%c ", M[i][j]) ;
      }
      fprintf(ch, "\n");
      }
      fclose(ch) ;
}
}

void loadfunction1(char M[8][8]){
      FILE *ch ;
      char x;
      char matrix[8][8];
      int i=0, j=0;

      ch = fopen("Boardsaved.txt","r") ;
      while(i<8){
        int j =0;
        while(j<8){
            fscanf(ch ,"%c", &x);

            if(x == ' ' || x == '\n'){
                //don't increment
                //continue
            }else{
               M[i][j] = x;
               j++;
            }
        }i++;
      }

      fclose(ch);
}

void savefunction2(int M[32][4]){
      FILE *ch ;
      ch = fopen("piecesSaved.txt","w") ;
      for(int i = 0 ; i < 32 ; i++)
      {
          for(int j=0; j< 4; j++){
          fprintf(ch ,"%d ", M[i][j]) ;
          }
      }
      fclose(ch) ;
}

void loadfunction2(int M[32][4]){
      FILE *ch ;
      ch = fopen("piecesSaved.txt","r") ;
      int x;
      int i=0, j=0;
      while(i<32){
        int j =0;
        while(j<4){
            fscanf(ch ,"%d", &x);
            if(x == ' '){
                //don't increment
                //continue
            }else{
               M[i][j] = x;
               j++;
            }
        }i++;
      }
      fclose(ch) ;


}






/**===========================================================================**/
/**============================ process input ================================**/
/**===========================================================================**/
//OUT variables
int y_w = 110;
int y_b = 110;
int ctr1 = 0, ctr2 = 0;
int index;
bool flag1 = true;
int save_load_matrix[32][4];
int gameoverint = 0;
char* current_piece_name[20];
static int no_of_saving_moves = 0;
int historyctr = 0;
int x_init, y_init;
int *x_initp, *y_initp;
int undo_clicks = 0;
int save_game_bool = 0, load_game_bool = 0, undo_bool = 0;

void process_input(elem* ourMove){
    //save_game_bool = 0, load_game_bool = 0, undo_bool = 0;
    int no_move_done;
    SDL_Event event; //normal struct
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT: //clicking x putton
            game_is_running = False;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                game_is_running = False;
            break;
        case SDL_MOUSEBUTTONUP:
                if (leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
                {
                    if(selectedRect != NULL){

                        selectedRect->x = ((mousePos.x-100)/75)*75 + 100;
                        selectedRect->y = ((mousePos.y-200)/75)*75 + 200;

                        ourMove->dstRow = (selectedRect->y - 200)/75;
                        ourMove->dstCol = (selectedRect->x - 100)/75;
                        ourMove->fig = gameBoard[ourMove->dstRow][ourMove->dstCol];

                    switch(isValidMove(gameBoard, ourMove)){
                    case 5:
                        printf("illegal figure\n");
                        ourMove->dstRow = ourMove->startRow;
                        ourMove->dstCol = ourMove->startCol;
                        selectedRect->x = x_init;
                        selectedRect->y = y_init;
                        no_move_done = 1;
                        break;
                    case 4:
                        printf("illegal Move\n");
                        ourMove->dstRow = ourMove->startRow;
                        ourMove->dstCol = ourMove->startCol;
                        selectedRect->x = x_init;
                        selectedRect->y = y_init;
                        no_move_done = 1;
                        break;
                    case 8:
                if(ourMove->player == 'w'){
                    if(index>=0 && index<=15){
                        if(there_is_capture){
                            for(int j=0; j<32; j++){
                            if ((SDL_PointInRect(&mousePos, arr_of_rects[j])&& pieces_names[j]!=pieces_names[index]) && there_is_capture){
                                arr_of_rects[j]->x = 25;
                                arr_of_rects[j]->y = 320 + ctr1;
                                arr_of_rects[j]->w = 50;
                                arr_of_rects[j]->h = 50;
                                ctr1 += 50;

                            }
                        }
                        }
                        gameBoard[ourMove->dstRow][ourMove->dstCol] = ourMove->prevFig;
                        gameBoard[ourMove->startRow][ourMove->startCol] = '-';
                        no_move_done = 0;
                    }else{ //not valid move
                       selectedRect->x = x_init;
                       selectedRect->y = y_init;
                       no_move_done = 1;
                    }
                }else{ //player is black
                    if(index>=16 && index<=31){
                        if(there_is_capture){

                        for(int j=0; j<32; j++){
                            if ((SDL_PointInRect(&mousePos, arr_of_rects[j])&& pieces_names[j]!=pieces_names[index]) && there_is_capture){
                                arr_of_rects[j]->x = 725;
                                arr_of_rects[j]->y = 320 + ctr2;
                                arr_of_rects[j]->w = 50;
                                arr_of_rects[j]->h = 50;
                                ctr2 += 50;

                            }
                           }
                    }
                    gameBoard[ourMove->dstRow][ourMove->dstCol] = ourMove->prevFig;
                    gameBoard[ourMove->startRow][ourMove->startCol] = '-';
                    no_move_done = 0;

                }else{//not valid move
                       selectedRect->x = x_init;
                       selectedRect->y = y_init;
                       no_move_done = 1;
                }
                }
                break;
                }


                    for(int i=0; i<GRID; i++){
                             for(int j=0; j<GRID; j++){
                                    printf("%c ", gameBoard[i][j]);
                                   }
                                   printf("\n");
                                }
                                printf("\n----------------------------------------------------------\n");
                    //if a player is in check he can't make a move unless it releases his check.
                     int checki = (check1flag || check2flag) ;
                     int check = isCheck(gameBoard, ourMove);
                     if(checki && (checki == check)){
                        selectedRect->x = x_init;
                        selectedRect->y = y_init;
                        no_move_done = 1;
                     }

                     for(int c=0; c<32; c++){
                        save_load_matrix[c][0] = arr_of_rects[c]->x;
                        save_load_matrix[c][1] = arr_of_rects[c]->y;
                        save_load_matrix[c][2] = arr_of_rects[c]->h;
                        save_load_matrix[c][3] = arr_of_rects[c]->w;
                     }

                     //checkmate
                     //if a player is in check, then find if it is in checkmate
                     /**
                     if(check1flag){//white player is in check.
                         for(int i=0; i<8; i++){
                             for(int j=0; j<8; j++){
                                    no_of_saving_moves = possibleMoves('w', gameBoard, i, j);
                             }
                         }
                     }
                     if(check2flag){//black player is in check
                         for(int i=0; i<8; i++){
                             for(int j=0; j<8; j++){
                                    no_of_saving_moves = possibleMoves('b', gameBoard, i, j);

                            }
                        }
                     }


                        if(no_of_saving_moves == 0){gameoverint = 1;} **/


                    if(!no_move_done){
                    history_list[historyctr][0] = index;
                    history_list[historyctr][1] = ourMove->startRow;
                    history_list[historyctr][2] = ourMove->startCol;
                    history_list[historyctr][3] = ourMove->dstRow;
                    history_list[historyctr][4] = ourMove->dstCol;
                    history_list[historyctr][5] = ourMove->prevFig;
                    history_list[historyctr][6] = *x_initp;
                    history_list[historyctr][7] = *y_initp;
                    historyctr ++;
                    if(ourMove->player == 'b'){
                        ourMove->player = 'w';
                    }else if(ourMove->player == 'w'){
                        ourMove->player = 'b';
                    }
                    }
                    there_is_capture = 0;
                    leftMouseButtonDown = 0;
                    selectedRect = NULL;
                    }
					}// end of ((if selected != NULL)))


                 break;



        case SDL_MOUSEBUTTONDOWN:
            if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
                {

                    leftMouseButtonDown = 1;

                    for (int i=0; i<32; i++)
                    {
                        if (SDL_PointInRect(&mousePos, arr_of_rects[i]))
                        {
                            index = i;
                            selectedRect = arr_of_rects[i];
                            x_init = selectedRect->x;
                            y_init = selectedRect->y;
                            x_initp = &x_init;
                            y_initp = &y_init;
                            clickOffset.x = mousePos.x - arr_of_rects[i]->x;
                            clickOffset.y = mousePos.y - arr_of_rects[i]->y;
                            ourMove->startRow = (arr_of_rects[i]->y-200)/75;
                            ourMove->startCol = (arr_of_rects[i]->x-100)/75;
                            ourMove->prevFig = gameBoard[ourMove->startRow][ourMove->startCol];


                        }
                    }
                }

                if(SDL_PointInRect(&mousePos, &undobutton_i_rect)){

                        int l,k,m,n,j;
                        l = history_list[historyctr-undo_clicks-1][1];
                        k = history_list[historyctr-undo_clicks-1][2];
                        m = history_list[historyctr-undo_clicks-1][3];
                        n = history_list[historyctr-undo_clicks-1][4];
                        j = history_list[historyctr-undo_clicks-1][0];
                        arr_of_rects[j]->x = history_list[historyctr-undo_clicks-1][6];
                        arr_of_rects[j]->y = history_list[historyctr-undo_clicks-1][7];
                        gameBoard[l][k] = gameBoard[m][n] ;
                        gameBoard[m][n] = '-';
                        undo_clicks ++;

                        for(int i=0; i<GRID; i++){
                            for(int j=0; j<GRID; j++){
                                 printf("%c ", gameBoard[i][j]);
                             }
                             printf("\n");

                        }

                        leftMouseButtonDown = 0;
                }

                if(SDL_PointInRect(&mousePos, &savegame_rect)){
                    savefunction1(gameBoard);
                    savefunction2(save_load_matrix);
                    leftMouseButtonDown = 0;
                }else if(SDL_PointInRect(&mousePos, &loadgame_rect)){
                    leftMouseButtonDown = 0;
                    loadfunction1(gameBoard);
                    loadfunction2(save_load_matrix);
                    for(int i=0; i<32; i++){
                        arr_of_rects[i]->x = save_load_matrix[i][0];
                        arr_of_rects[i]->y = save_load_matrix[i][1];
                        arr_of_rects[i]->h = save_load_matrix[i][2];
                        arr_of_rects[i]->w = save_load_matrix[i][3];
                    }
                }

                break;


        case SDL_MOUSEMOTION:
                mousePos.x = event.motion.x;
                mousePos.y = event.motion.y;
                if (leftMouseButtonDown && selectedRect != NULL){
                        selectedRect->x = mousePos.x - clickOffset.x;
                        selectedRect->y = mousePos.y - clickOffset.y;
                    }
                if(SDL_PointInRect(&mousePos, &savegame_rect)){
                    save_game_bool = 1;}else{save_game_bool = 0;}
                if(SDL_PointInRect(&mousePos, &loadgame_rect)){
                    load_game_bool = 1;} else{load_game_bool = 0;}
                if(SDL_PointInRect(&mousePos, &undobutton_i_rect)){
                    undo_bool = 1;}else{undo_bool = 0;}
                break;
    }
}


/**==========================================**/
void update(){
    while(!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));
    last_frame_time = SDL_GetTicks();

}

void render(){
                //Clear screen

				SDL_RenderClear( renderer1 );

				SDL_RenderCopy( renderer1, background, NULL, &background_rect );
				SDL_RenderCopy( renderer1, background2, NULL, &background2_rect );
				//Render texture to screen
				SDL_RenderCopy( renderer1, texture1, NULL, &boarditself );

				//Update screen
				SDL_RenderPresent( renderer1 );

				SDL_RenderCopy( renderer1, rock1_w, NULL, &rock1_w_rect );
				SDL_RenderCopy( renderer1, rock2_w, NULL, &rock2_w_rect );
				SDL_RenderCopy( renderer1, rock1_b, NULL, &rock1_b_rect );
				SDL_RenderCopy( renderer1, rock2_b, NULL, &rock2_b_rect );
				SDL_RenderCopy( renderer1, knight1_w, NULL, &knight1_w_rect);
				SDL_RenderCopy( renderer1, knight2_w, NULL, &knight2_w_rect );
				SDL_RenderCopy( renderer1, knight1_b, NULL, &knight1_b_rect);
				SDL_RenderCopy( renderer1, knight2_b, NULL, &knight2_b_rect );
				SDL_RenderCopy( renderer1, bishop1_w, NULL, &bishop1_w_rect);
				SDL_RenderCopy( renderer1, bishop2_w, NULL, &bishop2_w_rect );
				SDL_RenderCopy( renderer1, bishop1_b, NULL, &bishop1_b_rect);
				SDL_RenderCopy( renderer1, bishop2_b, NULL, &bishop2_b_rect);
                SDL_RenderCopy( renderer1, queen_w, NULL, &queen_w_rect);
				SDL_RenderCopy( renderer1, queen_b, NULL, &queen_b_rect);
                SDL_RenderCopy( renderer1, king_w, NULL, &king_w_rect);
				SDL_RenderCopy( renderer1, king_b, NULL, &king_b_rect);

                SDL_RenderCopy( renderer1, pawn1_w, NULL, &pawn1_w_rect);
				SDL_RenderCopy( renderer1, pawn2_w, NULL, &pawn2_w_rect);
                SDL_RenderCopy( renderer1, pawn3_w, NULL, &pawn3_w_rect);
				SDL_RenderCopy( renderer1, pawn4_w, NULL, &pawn4_w_rect);
				SDL_RenderCopy( renderer1, pawn5_w, NULL, &pawn5_w_rect);
				SDL_RenderCopy( renderer1, pawn6_w, NULL, &pawn6_w_rect);
                SDL_RenderCopy( renderer1, pawn7_w, NULL, &pawn7_w_rect);
				SDL_RenderCopy( renderer1, pawn8_w, NULL, &pawn8_w_rect);

				SDL_RenderCopy( renderer1, pawn1_b, NULL, &pawn1_b_rect);
				SDL_RenderCopy( renderer1, pawn2_b, NULL, &pawn2_b_rect);
                SDL_RenderCopy( renderer1, pawn3_b, NULL, &pawn3_b_rect);
				SDL_RenderCopy( renderer1, pawn4_b, NULL, &pawn4_b_rect);
				SDL_RenderCopy( renderer1, pawn5_b, NULL, &pawn5_b_rect);
				SDL_RenderCopy( renderer1, pawn6_b, NULL, &pawn6_b_rect);
                SDL_RenderCopy( renderer1, pawn7_b, NULL, &pawn7_b_rect);
				SDL_RenderCopy( renderer1, pawn8_b, NULL, &pawn8_b_rect);
				SDL_RenderCopy( renderer1, undobutton_i, NULL, &undobutton_i_rect);
				SDL_RenderCopy( renderer1, savegame_i, NULL, &savegame_rect);
				SDL_RenderCopy( renderer1, loadgame_i, NULL, &loadgame_rect);

				if(undo_bool){
                   SDL_RenderCopy( renderer1, undobutton_f, NULL, &undobutton_i_rect);
				}

				if(save_game_bool){
                    SDL_RenderCopy( renderer1, savegame_f, NULL, &savegame_rect);
				}

				if(load_game_bool){
                   SDL_RenderCopy( renderer1, loadgame_f, NULL, &loadgame_rect);
				}

				if(check1flag){
                    SDL_RenderCopy( renderer1, check_white, NULL, &check_white_rect);
				}else if(check2flag){SDL_RenderCopy( renderer1, check_black, NULL, &check_black_rect);}

				if(gameoverint){
                    SDL_RenderCopy( renderer1, gamover, NULL, &gameover_rect);
				}



				SDL_RenderPresent( renderer1 );
}

void destroy_window(){
    SDL_DestroyRenderer(renderer1);
    SDL_DestroyWindow(window1);
    SDL_Quit();
}

int main(int argc, char *argv[]){
    printf("------------------CHESS GAME------------------\n");
    game_is_running = initialize_window();
    elem element;
    element.player = 'w';
    there_is_capture = false;
    setup();


    while(game_is_running){
        process_input(&element);
        update();
        render();
    }
for(int i=0; i<GRID; i++){
        for(int j=0; j<GRID; j++){
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
    close();
    return 0;
}

/** function for loading media, making board**/
SDL_Texture* loadTexture()
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP("brown_min.bmp");
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image! SDL_image Error:\n");
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from SDL Error: %s\n", SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture( texture1 );
	texture1 = NULL;
	SDL_DestroyTexture(rock1_w );
	SDL_DestroyTexture(rock2_w );
	SDL_DestroyTexture(rock1_b);
	SDL_DestroyTexture(rock2_b);
	SDL_DestroyTexture(knight1_w);
	SDL_DestroyTexture(knight2_w);
	SDL_DestroyTexture(knight1_b);
	SDL_DestroyTexture(knight2_b);
	SDL_DestroyTexture(bishop1_w);
	SDL_DestroyTexture(bishop2_w);
	SDL_DestroyTexture(bishop1_b);
	SDL_DestroyTexture(bishop2_b);
	SDL_DestroyTexture(queen_w);
	SDL_DestroyTexture(queen_b);
	SDL_DestroyTexture(king_w);
	SDL_DestroyTexture(king_b);
	SDL_DestroyTexture(pawn1_w);
	SDL_DestroyTexture(pawn2_w);
	SDL_DestroyTexture(pawn3_w);
	SDL_DestroyTexture(pawn4_w);
	SDL_DestroyTexture(pawn5_w);
	SDL_DestroyTexture(pawn6_w);
	SDL_DestroyTexture(pawn7_w);
	SDL_DestroyTexture(pawn8_w);
	SDL_DestroyTexture(pawn1_b);
	SDL_DestroyTexture(pawn2_b);
	SDL_DestroyTexture(pawn3_b);
	SDL_DestroyTexture(pawn4_b);
	SDL_DestroyTexture(pawn5_b);
	SDL_DestroyTexture(pawn6_b);
	SDL_DestroyTexture(pawn7_b);
	SDL_DestroyTexture(pawn8_b);

	SDL_DestroyTexture(undobutton_i);
	SDL_DestroyTexture(undobutton_f);
	SDL_DestroyTexture(check_black);
	SDL_DestroyTexture(check_white);
	SDL_DestroyTexture(loadgame_i);
	SDL_DestroyTexture(loadgame_f);
	SDL_DestroyTexture(savegame_i);
	SDL_DestroyTexture(savegame_f);
	//Destroy window
	SDL_DestroyRenderer( renderer1 );
	SDL_DestroyWindow( window1 );
	window1 = NULL;
	window1 = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void loadpieces()
{
	//The final texture
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = NULL;

	loadedSurface = SDL_LoadBMP("IMG-20190623-WA0000-removebg-preview.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    background = newTexture;

    loadedSurface = SDL_LoadBMP("IMG_7046-removebg-preview.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    background2 = newTexture;


    loadedSurface = SDL_LoadBMP("WhiteR.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    rock1_w = newTexture;
    rock2_w = newTexture;

    loadedSurface = SDL_LoadBMP("BlackR.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    rock1_b = newTexture;
    rock2_b = newTexture;

    loadedSurface = SDL_LoadBMP("WhiteN.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    knight1_w = newTexture;
    knight2_w = newTexture;

    loadedSurface = SDL_LoadBMP("BlackN.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    knight1_b = newTexture;
    knight2_b = newTexture;

    loadedSurface = SDL_LoadBMP("WhiteB.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    bishop1_w = newTexture;
    bishop2_w = newTexture;

    loadedSurface = SDL_LoadBMP("BlackB.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    bishop1_b = newTexture;
    bishop2_b = newTexture;

    loadedSurface = SDL_LoadBMP("WhiteQ.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    queen_w = newTexture;

    loadedSurface = SDL_LoadBMP("BlackQ.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    queen_b = newTexture;

    loadedSurface = SDL_LoadBMP("WhiteK.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    king_w = newTexture;

    loadedSurface = SDL_LoadBMP("BlackK.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    king_b = newTexture;

    loadedSurface = SDL_LoadBMP("WhiteP.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    pawn1_w = newTexture;
    pawn2_w = newTexture;
    pawn3_w = newTexture;
    pawn4_w = newTexture;
    pawn5_w = newTexture;
    pawn6_w = newTexture;
    pawn7_w = newTexture;
    pawn8_w = newTexture;


    loadedSurface = SDL_LoadBMP("BlackP.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    pawn1_b = newTexture;
    pawn2_b = newTexture;
    pawn3_b = newTexture;
    pawn4_b = newTexture;
    pawn5_b = newTexture;
    pawn6_b = newTexture;
    pawn7_b = newTexture;
    pawn8_b = newTexture;

    loadedSurface = SDL_LoadBMP("undo.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    undobutton_i = newTexture;

    loadedSurface = SDL_LoadBMP("UndoFinal.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    undobutton_f = newTexture;



    loadedSurface = SDL_LoadBMP("received_436300067440288.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    check_black = newTexture;

    loadedSurface = SDL_LoadBMP("received_152773089944746.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    check_white = newTexture;

    loadedSurface = SDL_LoadBMP("gameover.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    gamover = newTexture;

    loadedSurface = SDL_LoadBMP("saveGame.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    savegame_i = newTexture;

    loadedSurface = SDL_LoadBMP("saveGameb.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    savegame_f = newTexture;

    loadedSurface = SDL_LoadBMP("LoadGame.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    loadgame_i = newTexture;

    loadedSurface = SDL_LoadBMP("LoadGameFinal.bmp");
    newTexture = SDL_CreateTextureFromSurface( renderer1, loadedSurface );
    loadgame_f = newTexture;

}
/**
int pieceUnderAttackSmall(char gameBoard[GRID][GRID], char playerSym, int row,int col){
    int flago = 0;
	elem newelement; //new struct represents the possible moves from enemy that threatens player's king
	newelement.dstRow = row;
	newelement.dstCol = col;
	if(playerSym == 'w'){newelement.player ='b';}
	else if(playerSym == 'b'){newelement.player = 'w';}

	if(playerSym == 'w'){newelement.fig = 'K';}
	else if(playerSym == 'b'){newelement.fig = 'k';}
	for (int i=0;i<GRID;i++){ //scan all board
		for (int j=0;j<GRID;j++){
            newelement.prevFig = gameBoard[i][j];
			if ((playerSym=='w' && islower(gameBoard[i][j])) || (playerSym=='b' && isupper(gameBoard[i][j]))){//check if the figure is the opponnent's figure
			newelement.startRow = i;
			newelement.startCol = j;
			int isValidMove1 = isValidMove(gameBoard, &newelement);
			int noOverlap1 = noOverlap(gameBoard, &newelement);
			if((isValidMove1==8) && noOverlap1){
			return 1;
			}
			else{
                flago = 1;
			}
		   }
	   }
	}
	if(flago){return 0;}
}

int isCheck_small(char gameBoard[GRID][GRID], char playersym){
    int small_check;
	int row=0,col=0;
	if(playersym == 'w'){ //get white king place
		for(int i=0; i<8; i++){
		   for(int j=0; j<8; j++){
		       if(gameBoard[i][j] == 'K'){
			   row = i;
			   col = j;
			   }
		   }
		}
	}
	else if(playersym == 'b'){//get black_king place
	     for(int i=0; i<8; i++){
		   for(int j=0; j<8; j++){
		       if(gameBoard[i][j] == 'k'){
			   row = i;
			   col = j;
			   }
		   }
		}
	}
	small_check = pieceUnderAttackSmall(gameBoard,playersym,row,col); //check if the current player's king is under attack
return(small_check);
}


int possibleMoves(char player,char gameBoard[GRID][GRID], int row, int col){
    char w = gameBoard[row][col];
	switch(w){
	case 'P':
	case 'p': // pawn moves
		if(possiblePawnMoves(player, gameBoard ,row,col) == 1){return 1; }else{return 0;}
	case 'B':
	case 'b': // bishop moves
		if( possibleBishopMoves(player, gameBoard ,row,col) == 1){return 1; }else{return 0;}
	case 'R':
	case 'r': // rook moves
		 if( possibleRookMoves(player, gameBoard ,row,col) == 1){return 1; ;}else{return 0;}
	case 'N':
	case 'n': // knight moves
		if( possibleKnightMoves(player, gameBoard ,row,col) == 1){return 1; }else{return 0;}
	case 'Q':
	case 'q': // queen moves
		if( possibleQueenMoves(player, gameBoard ,row,col) == 1){return 1; }else{return 0;}
	case 'K':
	case 'k': // king moves
		if( possibleKingMoves(player, gameBoard ,row,col) == 1){return 1; }else{return 0;}
    default:
        return 0;
	}
}

int possiblePawnMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col){

	elem pieceelement;
    int isvalid, overlap, checks;
	pieceelement.startRow = row;
	pieceelement.startCol = col;
	if(myplayer == 'w'){
	    //1
		pieceelement.dstRow = row-2;
		pieceelement.dstCol= col;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if(isvalid && overlap && !checks){return 1;}

		//2
		pieceelement.dstRow = row-1;
		pieceelement.dstCol= col;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if(f && overlap && !checks){return 1;}

		//3
		pieceelement.dstRow = row-1;
		pieceelement.dstCol= col+1;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if(isvalid && overlap && !checks){return 1;}

		//4
		pieceelement.dstRow = row-1;
		pieceelement.dstCol= col-1;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if(isvalid && overlap && !checks){return 1;}

		return 0;
	}
	else{
	    //1
		pieceelement.dstRow = row+2;
		pieceelement.dstCol= col;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if(isvalid && overlap && !checks){return 1;}

		//2
		pieceelement.dstRow = row+1;
		pieceelement.dstCol= col;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if(isvalid && overlap && !checks){return 1;}

		//3
		pieceelement.dstRow = row+1;
		pieceelement.dstCol= col+1;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if(isvalid && overlap && !checks){return 1;}

		//4
		pieceelement.dstRow = row+1;
		pieceelement.dstCol= col-1;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if(isvalid && overlap && !checks){return 1;}
		return 0;
	}
	return 0;
}





int possibleBishopMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col){

	int i=0,j=0,index=0;
	int add_move=0;
	elem pieceelement;
    int isvalid, overlap, checks;
	pieceelement.startRow = row;
	pieceelement.startCol = col;
	pieceelement.player = myplayer;
	pieceelement.prevFig = gameBoard[row][col];
	char playersym = myplayer;
	i=row-1;j=col-1;
	//checking all 13 possible moves of the knight if they are valid
	while((i>=0 && i<=(GRID-1)) && (j>=0 && j<=(GRID-1))) //right backwards diagonal
	{
	    pieceelement.dstRow = i;
		pieceelement.dstCol= j;
		pieceelement.fig = gameBoard[i][j];
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
		if(isvalid && overlap){
            CopyBoard(gameBoard);
            newBoard[row][col] = '-';
            newBoard[i][j] = pieceelement.prevFig;
            for(int p=0; p<GRID; p++){
                             for(int k=0; k<GRID; k++){
                                    printf("%c ", newBoard[p][k]);
                                   }
                                   printf("\n");
                                }
            checks = isCheck_small(newBoard, playersym);
		}
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}
		i--; j--;
	}
	i=row-1;j=col+1;
	while((i>=0 && i<=(GRID-1)) && (j>=0 && j<=(GRID-1))) //left backwards diagonal
	{
		pieceelement.dstRow = i;
		pieceelement.dstCol= j;
		pieceelement.fig = gameBoard[i][j];
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        if(isvalid && overlap){
            CopyBoard(gameBoard);
            newBoard[row][col] = '-';
            newBoard[i][j] = pieceelement.prevFig;
            checks = isCheck_small(newBoard, playersym);
		}

		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}
		i--; j++;
	}
	i=row+1;j=col-1;
	while((i>=0 && i<=(GRID-1)) && (j>=0 && j<=(GRID-1))) //left forward diagonal
	{
		pieceelement.dstRow = i;
		pieceelement.dstCol= j;
		pieceelement.fig = gameBoard[i][j];
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        if(isvalid && overlap){
            CopyBoard(gameBoard);
            newBoard[row][col] = '-';
            newBoard[i][j] = pieceelement.prevFig;
            for(int p=0; p<GRID; p++){
                             for(int k=0; k<GRID; k++){
                                    printf("%c ", newBoard[p][k]);
                                   }
                                   printf("\n");
                                }
            checks = isCheck_small(newBoard, playersym);
		}

		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}
		i++; j--;
	}
	i=row+1;j=col+1;
	while((i>=0 && i<=(GRID-1)) && (j>=0 && j<=(GRID-1))) //left forward diagonal
	{
		pieceelement.dstRow = i;
		pieceelement.dstCol= j;
		pieceelement.fig = gameBoard[i][j];
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        if(isvalid && overlap){
            CopyBoard(gameBoard);
            newBoard[row][col] = '-';
            newBoard[i][j] = pieceelement.prevFig;
            for(int p=0; p<GRID; p++){
                             for(int k=0; k<GRID; k++){
                                    printf("%c ", newBoard[p][k]);
                                   }
                                   printf("\n");
                                }
            checks = isCheck_small(newBoard, playersym);
		}

		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;  }
		i++; j++;
	}
	return 0;
}

int possibleRookMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col){

	elem pieceelement;
    int isvalid, overlap, checks;
	pieceelement.startRow = row;
	pieceelement.startCol = col;

	for (int i=row+1;i<GRID;i++){//moving forward
		pieceelement.dstRow = i;
		pieceelement.dstCol= col;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, pieceelement.player);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}
	}
	for (int i=row-1;i>=0;i--){//moving backwards
	    pieceelement.dstRow = i;
		pieceelement.dstCol= col;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, pieceelement.player);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}
	}
	for (int j=col+1;j<GRID;j++){//moving right
		pieceelement.dstRow = row;
		pieceelement.dstCol= j;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, pieceelement.player);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}
	}
	for (int j=col-1;j>=0;j--){//moving left
		pieceelement.dstRow = row;
		pieceelement.dstCol= j;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}
	}
	return 0;
}

int possibleKnightMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col){
	elem pieceelement;
    int isvalid, overlap, checks;
	pieceelement.startRow = row;
	pieceelement.startCol = col;
	//checking all 8 possible moves of the knight if they are valid

	    pieceelement.dstRow = row+2;
		pieceelement.dstCol= col+1;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if((myplayer == 'w') && isvalid && overlap && !checks){
                return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){
		    return 1;}

		pieceelement.dstRow = row+1;
		pieceelement.dstCol= col+2;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if((myplayer == 'w') && isvalid && overlap && !checks){
                return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){
		    return 1;}

		pieceelement.dstRow = row+2;
		pieceelement.dstCol= col-1;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}

		pieceelement.dstRow = row+1;
		pieceelement.dstCol= col-2;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}

		pieceelement.dstRow = row+1;
		pieceelement.dstCol= col-2;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}

		pieceelement.dstRow = row-2;
		pieceelement.dstCol= col-1;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}

		pieceelement.dstRow = row-1;
		pieceelement.dstCol= col-2;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, &pieceelement);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}

		pieceelement.dstRow = row-2;
		pieceelement.dstCol= col+1;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, pieceelement.player);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}

		pieceelement.dstRow = row-1;
		pieceelement.dstCol= col+2;
		isvalid = allowedMove(gameBoard, &pieceelement);
		overlap =  noOverlap(gameBoard, &pieceelement);
        checks = isCheck_small(gameBoard, pieceelement.player);
		if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}
	   return 0;
}


int possibleQueenMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col){
int rookarr, bishoparr, queenarr;
	//queen moves:bishop moves+rook moves
	rookarr = possibleRookMoves(myplayer, gameBoard,row,col);
	bishoparr = possibleBishopMoves(myplayer, gameBoard,row,col);
	queenarr = rookarr + bishoparr;
if(queenarr){return 1;}
else{return 0;}
return 0;
}

int possibleKingMoves(char myplayer, char gameBoard[GRID][GRID],int row, int col){
	elem pieceelement;
    int isvalid, overlap, checks;
	pieceelement.startRow = row;
	pieceelement.startCol = col;
	for (int i=row-1;i<=row+1;i++){ //the king has 8 moves options
		for (int j=col-1;j<=col+1;j++){
			if ((i>=0 && i<=(GRID-1)) && (j>=0 && j<=(GRID-1))){
				pieceelement.dstRow = i;
		       pieceelement.dstCol= j;
		       isvalid = allowedMove(gameBoard, &pieceelement);
		       overlap =  noOverlap(gameBoard, &pieceelement);
               checks = isCheck_small(gameBoard, pieceelement.player);
		      if((myplayer == 'w') && isvalid && overlap && !checks){return 1;}
		else if((myplayer == 'b') && isvalid && overlap && !checks){return 1;}
			}
		}
	}
	return 0;
}

**/




