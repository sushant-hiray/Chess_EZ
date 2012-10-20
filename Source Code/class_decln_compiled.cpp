/*
*Specifications:
*Created in Geany
*Tab width : 4
*Font 	   		: Monospace Normal 12
*Lines of code	: 
*/


/*
*Declaration of classes and Global variables
*@version: 1.0.3 29th Oct 2011

*@author : Guna Prasaad
*@author : Sushant Hiray ( for functions enpassant,piece creation,invalid move,castling both white and black coins)
/


/*
*The index allocation for the coins is going to be in the following order:
*A8 to H8
*A7 to H7
*A2 to H2
*A1 to H1
*
/


/*
* The origin for the board is at top left corner of the board
* 
*/

#define EMPTY -1
#define LBROOK 0
#define LBKNIGHT 1
#define LBBISHOP 2
#define BQUEEN 3
#define BKING 4
#define RBBISHOP 5
#define RBKNIGHT 6
#define RBROOK 7
#define BPAWN1 8
#define BPAWN2 9
#define BPAWN3 10
#define BPAWN4 11
#define BPAWN5 12
#define BPAWN6 13
#define BPAWN7 14
#define BPAWN8 15
#define WPAWN1 16
#define WPAWN2 17
#define WPAWN3 18
#define WPAWN4 19
#define WPAWN5 20
#define WPAWN6 21
#define WPAWN7 22
#define WPAWN8 23
#define LWROOK 24
#define LWKNIGHT 25
#define LWBISHOP 26
#define WQUEEN 27
#define WKING 28
#define RWBISHOP 29
#define RWKNIGHT 30
#define RWROOK 31


/*Header Files*/

#include<iostream>
#include<fstream>
#include "ezwin.h"
#include "bitmap.h"
#include<cstring>
#include "rect.h"


/*Global Variables */

SimpleWindow Main("Main",29.0,15.5,Position(0.5,0.0));
SimpleWindow PP("Pawn Promotion",8.5,3.5,Position(10.25,8.25));
BitMap	pic[8][8];					//Denotes the associated .xpm file
char	picName[8][8][9]; 			//Contains names of pics in each square
int oldX =8, oldY=8;
int enpassant=0;
int mode = 0;
int nHistoryOfMoves=0;
int fiftyMoveRule=0;
int retValue=-1;
int blackOut =0;
int whiteOut =0;
int replaceCoinId = -1;
/*Function Declarartions*/

void updateRange();
int FiftyMoveRule();
void coinReplace(int, int, int, int);
void displayBoardState();
void displayRange();
int displayDialog(int);
void displayInDock(int);
void initialize();
void displayCoinReplace(int,int);

/*Class Declaration for Class Pos*/

class Pos {

private:
	int 	x;
	int 	y;
	int 	colour;
	int  	coinId;					//-1 if empty and index of coin if occuppied
	int 	coinIndex;
public:
	void	setXY(const int inputX, const int inputY);
	void 	getXY(int &outputX, int &outputY);
	void  	setColor(const int inputColor);
	int 	getColor();
	void 	setCoinId(const int inputCoinId);
	int 	getCoinId();
	void	setCoinIndex(int inputIndex);
	int 	getCoinIndex();
	const int 	getX();
	const int 	getY();
	void 	copyObject(Pos tempObject);//Copies the details of the passed object in
	int		equalObject(Pos tempObject);
	friend  void initialize();
};


Pos board[8][8];//Global variable that stores game situation


void Pos::setCoinIndex(int inputIndex) {
	coinIndex = inputIndex;
}

int Pos::getCoinIndex() {
	return coinIndex;
}

void Pos::setXY(const int inputX,const int inputY) {
	x = inputX;
	y = inputY;
}


void Pos::getXY(int &outputX, int &outputY) {
	outputX = x;
	outputY = y;
}

const int Pos::getX() {
	return x;
}

const int  Pos::getY() {
	return y;
}

void  Pos::setColor(const int inputColor) {
	colour = inputColor;
}


int Pos::getColor() {
	return  colour;
}

void Pos::setCoinId(const int inputCoinId) {
	coinId = inputCoinId;
	////cout<<"setCoinId was called with"<<inputCoinId<<"and set as"<<coinId<<endl;
}


int Pos::getCoinId() {
	return coinId;
}

void Pos::copyObject(Pos tempObject) {
	*this = tempObject;
}


int Pos::equalObject(Pos tempObject) {
	int tempX, tempY;
	tempObject.getXY(tempX,tempY);
	
	if(tempX == x && tempY == y) {
		return 1;
	} else {
		return 0;
	}
}

/* Class Declaration for Movement*/


class Movement {
public:
	Pos 		initPos;
	Pos			finalPos;
	int 		coinId;
	int 		coinIndex;
	int 		captureCoinIndex;
	int			colour;      //colour of the coin 
	int 		captureCoinId;
	

	void 		setInitPos(Pos tempPos);
	void 		setFinalPos(Pos tempPos);
	Pos			getInitPos();
	Pos 		getFinalPos();
	void 		setColor(int inputColor);
	int			getColor();
	int 		initializeMove(Pos tempInitPos,Pos tempFinalPos); //Creates a move and verifies if it is possible
	int 		makeMove();			//Makes the move and calls range update functions
	int 		storeMove();		//Stores the movement in the file
 	int 		modifyBoard();		//Called inside verifyCheck() to temp alter board
	int 		undoBoard(int);		//Called inside verifyCheck() to undo temp change
	//void static setRetValue(int);
};

Movement currentMove;


/*Function Declarations for Class Movement*/


void Movement::setInitPos(Pos tempPos) {
	initPos = tempPos;
}
	 
void Movement::setFinalPos(Pos tempPos) {
	finalPos = tempPos;
}
	
Pos	Movement::getInitPos() {
	return initPos;
}
	
Pos Movement::getFinalPos() {
	return finalPos;
}

void Movement::setColor(int inputColor) {
	colour = inputColor;
}


int Movement::getColor() {
	return colour;
}

/*Class Declaration of Class Coin*/

class Coin {
private:

	Pos 		curPos;
	Pos			finalPos;
	int 		coinId;
	Pos			coinRange[100];
	int 		nRange;
	int 		nHistory; // stores no. of moves made 
	int 		mode;
	int 		colour;
	
	
	int 		updatePawn();
	int 		updateRook();
	int 		updateKnight();
	int 		updateBishop();
	int 		updateQueen();
	int 		updateKing();
	
public:

	void setCurPos(const Pos);
	void setFinalPos(Pos tempPos);
	Pos returnCurPos(); 
	Pos returnFinalPos();
	void setColour(int inputColour);
	int getColour();
	void setCoinId(int inputCoinId);
	void setMode(int tempMode);
	void setNHistory(int inputNHistory); 
	void incNHistory();
	int returnNHistory();
	int returnMode(); 
	void modeOff();
	int getNRange();
	
	int checkRange(Pos tempObject);	
	int  verifyCheck(Movement tempMove);	//Checks if a temporary movement is possible
	
	friend void initialize();
	friend void updateRange();	//Calls corresponding range update functions
	friend void displayRange();
	friend int ReceiveMouseClick(const Position &p);
};

/*Global Variable Declaration*/
Coin allCoins[32];	

/*Function Definitions of Class Coin*/

void Coin::setCurPos(const Pos tempPos) {
		curPos = tempPos;
}

void Coin::incNHistory() {
	nHistory++;
}

void Coin::setMode(int tempMode) {
	mode = tempMode;
}
	
void Coin::setNHistory(int inputNHistory) {
	nHistory = inputNHistory;
}
	
int Coin::getNRange() {
	return nRange;
}	
	
int Coin::returnNHistory() {
	return nHistory;
}
	
Pos Coin::returnCurPos() {
	return curPos;
}

Pos Coin::returnFinalPos() {
	return finalPos;
}

int Coin::returnMode() {
	return mode;
}	

void Coin::modeOff() {
	mode=0;
}
	
void Coin::setFinalPos(Pos tempPos) {
	finalPos.copyObject(tempPos);
}
	
void Coin::setColour(int inputColour) {
	colour = inputColour;
}

int Coin::getColour() {
	return colour;
}
	
void Coin::setCoinId(int inputCoinId) {
	coinId = inputCoinId;
}	

int Coin::checkRange(Pos tempObject) {
	int i=1;
	int x1,x2,y1,y2;
	
	tempObject.getXY(x1,y1);
	//cout<<"nRange = "<<getNRange()<<endl;
	
	for(int i=0;i<nRange; i++) {
		//cout<<"iteration"<<i<<endl;
		
		if(tempObject.equalObject(coinRange[i])==1) {
			coinRange[i].getXY(x2,y2);
			//cout<<x1<<y1<<" = "<<x2<<y2<<endl;
			//cout<<"In range"<<i<<endl;
			return 1;
		} else {
			coinRange[i].getXY(x2,y2);
			//cout<<x2<<y2<<" != "<<x1<<y1<<endl;
		}
	}
	
	//cout<<"Not in Range"<<endl;
	return 0;
	
	
}

/* Function to be called only by currentMove Object*/

int Movement::initializeMove(Pos tempInitPos,Pos tempFinalPos) {
	
	initPos.copyObject(tempInitPos);

	finalPos.copyObject(tempFinalPos);

	//Storing X and Y of the initial Position
	int tempInitX, tempInitY;
	initPos.getXY(tempInitX,tempInitY);
	//cout<<"Getting initial Pos as:"<<tempInitX<<tempInitY<<endl;
	//Storing X and Y of the final Position
	int tempFinalX, tempFinalY;
	finalPos.getXY(tempFinalX,tempFinalY);
	//cout<<"Getting Final Pos as:"<<tempFinalX<<tempFinalY<<endl;
	
	//Initialising CoinId
	coinIndex = board[tempInitY][tempInitX].getCoinIndex();
	//cout<<"Getting CoinIndex as : "<<coinIndex<<endl;
	
	coinId = board[tempInitY][tempInitX].getCoinId();
	//cout<<"Getting CoinId as : "<<coinId<<endl;
	
	//Initialising colour
	if(coinId >= 0 && coinId <=15) {
		colour = 0;	//Black
	}
	else if(coinId >15 && coinId <=31) {
		colour = 1;	//White
	} 
	
	
	//Initialising captureCoinId
	captureCoinIndex = board[tempFinalY][tempFinalX].getCoinIndex();
	////cout<<"Getting Capture CoinIndex as : "<<captureCoinIndex<<endl; 
	
	captureCoinId = board[tempFinalY][tempFinalX].getCoinId();
	//cout<<"Getting Capture CoinId as : "<<captureCoinId<<endl; 
	
	//cout<<"Calling makeMove()"<<endl;
	makeMove();
}	


int Movement::makeMove() {

	//Stores initial position
	int tempInitX, tempInitY; 
	initPos.getXY(tempInitX,tempInitY);

	//stores final position
	int tempFinalX, tempFinalY; 
	finalPos.getXY(tempFinalX,tempFinalY);
	
	//cout<<"calling coinId : "<<coinId<<endl;

	int temp =allCoins[coinIndex].checkRange(finalPos);
	if( temp == 1) {
		if(coinId>=16 && coinId<=23 && captureCoinId == -1 && (((tempFinalX - tempInitX)==1) || ((tempInitX - tempFinalX)==1)) && tempInitY==3 ) 
			{	/*EnPassant for White Pawn*/
				
				int RealCaptureCoinIndex;
				
				//For the Bpawn that is goin to be removed
				RealCaptureCoinIndex = board[tempInitY][tempFinalX].getCoinIndex();
				
				//Final Pos of White Pawn is set
				allCoins[coinIndex].setCurPos(finalPos);

				//Black Pawn undergoing enpassant is switched off
				allCoins[RealCaptureCoinIndex].modeOff();

				//Init Pos of White Pawn is empty
				board[tempInitY][tempInitX].setCoinId(EMPTY);
				board[tempInitY][tempInitX].setCoinIndex(EMPTY);

				//Final Pos for White Pawn is set
				board[tempFinalY][tempFinalX].setCoinId(coinId);
				board[tempFinalY][tempFinalX].setCoinIndex(coinIndex);
				allCoins[coinIndex].incNHistory();
				

				//Init Pos of Black Pawn is empty
				board[tempInitY][tempFinalX].setCoinId(EMPTY);
				board[tempInitY][tempFinalX].setCoinIndex(EMPTY);
				
				
				//Updation for fifty-move rule
				fiftyMoveRule=nHistoryOfMoves;
				displayInDock(BPAWN1);
				coinReplace(tempFinalX,tempInitY,EMPTY,-1);
								
				retValue= 4;
				nHistoryOfMoves++;
				
			
			} else if(coinId>=8 && coinId<=15 && captureCoinId == -1 && (((tempFinalX - tempInitX)==1) || ((tempInitX - tempFinalX)==1)) && tempInitY==4) 
			{	/*EnPassant for Black Pawn*/
				
				int RealCaptureCoinIndex;
				//For the wpawn that is goin to be removed
				RealCaptureCoinIndex = board[tempInitY][tempFinalX].getCoinIndex();
				
				//Final Pos of Black Pawn is set
				allCoins[coinIndex].setCurPos(finalPos);

				//White Pawn undergoing enpassant is switched off
				allCoins[RealCaptureCoinIndex].modeOff();

				//Init Pos of Black Pawn is empty
				board[tempInitY][tempInitX].setCoinId(EMPTY);
				board[tempInitY][tempInitX].setCoinIndex(EMPTY);
				
				//Final Pos for Black Pawn is set
				board[tempFinalY][tempFinalX].setCoinId(coinId);
				board[tempFinalY][tempFinalX].setCoinId(coinIndex);
				allCoins[coinIndex].incNHistory();
				

				//Init Pos of White Pawn is empty
				board[tempInitY][tempFinalX].setCoinId(EMPTY);
				board[tempFinalY][tempFinalX].setCoinIndex(EMPTY);

				//Updation for fifty-move rule
				fiftyMoveRule=nHistoryOfMoves;
			
				//Appropriate GUI Update
				displayInDock(WPAWN1);
				coinReplace(tempFinalX,tempInitY,EMPTY,-1);
				retValue= 4;
				nHistoryOfMoves++;
				
			} else if(coinId == WKING && captureCoinId == EMPTY && (((tempFinalX - tempInitX)==2) || ((tempInitX - tempFinalX)==2))) 
			{	/*Castling for White King*/
				
				if( (tempFinalX - tempInitX)==2) {
					//Update in allCoins
					allCoins[WKING].setCurPos(finalPos);
					allCoins[RWROOK].setCurPos(board[tempFinalY][tempFinalX-1]);
					
					//Init Pos is empty
					board[tempInitY][tempInitX].setCoinId(EMPTY);
					board[tempInitY][tempInitX].setCoinIndex(EMPTY);

					//Final Pos for King is set
					board[tempFinalY][tempFinalX].setCoinId(WKING);
					board[tempFinalY][tempFinalX].setCoinIndex(WKING);
					allCoins[WKING].incNHistory();

					//Final Pos for Rook is set
					board[tempFinalY][tempFinalX-1].setCoinId(RWROOK);
					board[tempFinalY][tempFinalX-1].setCoinIndex(RWROOK);
					allCoins[RWROOK].incNHistory();

					//Init Pos of Rook is empty
					board[tempInitY][tempInitX+3].setCoinId(EMPTY);
					board[tempInitY][tempInitX+3].setCoinIndex(EMPTY);
					
					retValue= 2;
					nHistoryOfMoves++;
				
				}
				if( (tempInitX - tempFinalX)==2){

				//Update in allCoins
					allCoins[WKING].setCurPos(finalPos);
					allCoins[LWROOK].setCurPos(board[tempFinalY][tempFinalX+1]);
					
					//Init Pos is empty
					board[tempInitY][tempInitX].setCoinIndex(EMPTY);
					board[tempInitY][tempInitX].setCoinId(EMPTY);

					//Final Pos for King is set
					board[tempFinalY][tempFinalX].setCoinId(WKING);
					board[tempFinalY][tempFinalX].setCoinIndex(WKING);
					allCoins[WKING].incNHistory();

					//Final Pos for Rook is set
					board[tempFinalY][tempFinalX+1].setCoinId(LWROOK);
					board[tempFinalY][tempFinalX+1].setCoinIndex(LWROOK);
					allCoins[LWROOK].incNHistory();

					//Init Pos of Rook is empty
					board[tempInitY][tempInitX-4].setCoinId(EMPTY);
					board[tempInitY][tempInitX-4].setCoinIndex(EMPTY);

					//Appropriate GUI Update
					retValue= 3;
					nHistoryOfMoves++;
				}
			
			} else if(coinId==4 && captureCoinId == -1 && (((tempFinalX - tempInitX)==2) || ((tempInitX - tempFinalX)==2))) 
			{	/*Castling for Black King*/
				
				if( (tempFinalX - tempInitX)==2) {
					//Update in allCoins
					allCoins[BKING].setCurPos(finalPos);
					allCoins[RBROOK].setCurPos(board[tempFinalY][tempFinalX-1]);
					
					//Init Pos is empty
					board[tempInitY][tempInitX].setCoinId(EMPTY);
					board[tempInitY][tempInitX].setCoinIndex(EMPTY);
					
					//Final Pos for King is set
					board[tempFinalY][tempFinalX].setCoinId(BKING);
					board[tempFinalY][tempFinalX].setCoinIndex(BKING);
					allCoins[BKING].incNHistory();

					//Final Pos for Rook is set
					board[tempFinalY][tempFinalX-1].setCoinId(RBROOK);
					board[tempFinalY][tempFinalX-1].setCoinIndex(RBROOK);
					allCoins[RBROOK].incNHistory();

					//Init Pos of Rook is empty
					board[tempInitY][tempInitX+3].setCoinId(EMPTY);
					board[tempInitY][tempInitX+3].setCoinIndex(EMPTY);
					nHistoryOfMoves++;
					retValue= 2;
				}
				if( (tempInitX - tempFinalX)==2){

				//Update in allCoins
					allCoins[BKING].setCurPos(finalPos);
					allCoins[LBROOK].setCurPos(board[tempFinalY][tempFinalX+1]);
					
					//Init Pos is empty
					board[tempInitY][tempInitX].setCoinId(-1);
					board[tempInitY][tempInitX].setCoinIndex(-1);

					//Final Pos for King is set
					board[tempFinalY][tempFinalX].setCoinId(BKING);
					board[tempFinalY][tempFinalX].setCoinIndex(BKING);
					allCoins[BKING].incNHistory();

					//Final Pos for Rook is set
					board[tempFinalY][tempFinalX+1].setCoinId(LBROOK);
					board[tempFinalY][tempFinalX+1].setCoinIndex(LBROOK);
					allCoins[LBROOK].incNHistory();

					//Init Pos of Rook is empty
					board[tempInitY][tempInitX-4].setCoinId(-1);
					board[tempInitY][tempInitX-4].setCoinIndex(-1);

					//Appropriate GUI Update
					retValue= 3; 
					nHistoryOfMoves++;
				}
			} else if(coinId>=16 && coinId<=23 && captureCoinId >=EMPTY && captureCoinId<=BPAWN8 && tempFinalY == 0) 
			{	/*piece creation for White Pawn*/

				
				////cout<<"enter the coinId";
				//cin>>replaceCoinId;
				if(tempFinalX==1 || tempFinalX==6) {
					displayCoinReplace(1,1);
				} else {
					displayCoinReplace(1,0);
				}				
				if(captureCoinId!=EMPTY) {
					allCoins[captureCoinIndex].modeOff();
				}
				//Replace the pawn with the claimed coin
				allCoins[coinId].setCoinId(replaceCoinId);
				allCoins[coinId].setCurPos(board[tempFinalY][tempFinalX]);
				allCoins[coinId].incNHistory();
				
				//cout<<"coinId of "<<tempInitY<<tempInitX<<" is set to:"<<-1<<endl;
				//cout<<"coinIndex of "<<tempInitY<<tempInitX<<" is set to:"<<-1<<endl;
				
				//The final Pos of pawn is replaced by new coin
				board[tempFinalY][tempFinalX].setCoinId(replaceCoinId);
				board[tempFinalY][tempFinalX].setCoinIndex(coinIndex);
				 
				//cout<<"coinId of "<<tempFinalY<<tempFinalX<<" is set to:"<<replaceCoinId<<endl;
				//cout<<"coinIndex of "<<tempFinalY<<tempFinalX<<" is set to:"<<coinIndex<<endl;
				
				//fiftymove rule update
				fiftyMoveRule=nHistoryOfMoves;
				
				//GUI Update
				coinReplace(tempInitX,tempInitY,EMPTY,-1);
				coinReplace(tempFinalX,tempFinalY,replaceCoinId,1);
				retValue = 5;
				
				nHistoryOfMoves++;
			
			} else if(coinId>=8 && coinId<=15 && (captureCoinId == EMPTY ||(captureCoinId >=WPAWN1 && captureCoinId<=RBROOK)) && tempFinalY == 8) 
			{	/*piece creation for Black Pawn*/
				
				//int replaceCoinId; //For the new coin
				
				////cout<<"Enter the coinId";
				//cin>> replaceCoinId;
				if(tempFinalX==1 || tempFinalX==6) {
					displayCoinReplace(0,1);
				} else {
					displayCoinReplace(0,0);
				}				
				if(captureCoinId!=EMPTY) {
					allCoins[captureCoinIndex].modeOff();
				}
				if(captureCoinId!=EMPTY) {
					allCoins[captureCoinIndex].modeOff();
				}
				//Replace the pawn with the claimed coin
				allCoins[coinId].setCoinId(replaceCoinId);
				allCoins[coinId].setCurPos(board[tempFinalY][tempFinalX]);
				allCoins[coinId].incNHistory();

				//Pawn's last but one step ise empty
				board[tempInitY][tempInitX].setCoinId(-1);
				board[tempInitY][tempInitX].setCoinIndex(-1);

				//The final Pos of pawn is replaced by new coin
				board[tempFinalY][tempFinalX].setCoinId(replaceCoinId);
				board[tempFinalY][tempFinalX].setCoinIndex(coinIndex);

				//fiftymove rule update
				fiftyMoveRule=nHistoryOfMoves;
				
				//GUI Update
				coinReplace(tempInitX,tempInitY,EMPTY,-1);
				coinReplace(tempFinalX,tempFinalY,replaceCoinId,0);
				retValue= 5;
				nHistoryOfMoves++;
			
			} else if(coinId>=16 &&coinId<32 && captureCoinId>=0 && captureCoinId<16 && captureCoinId != BKING) 
			{ 	/*White coin replacing Black Coin*/
				
				//Appropriate changes in allCoins array
				allCoins[coinIndex].setCurPos(finalPos);
				allCoins[coinIndex].incNHistory();
				
				//Updation for Fifty Move Rule
				if( coinId >= 8 && coinId <= 23 ) {
					fiftyMoveRule=nHistoryOfMoves; 
				}

				//Switching off the mode for eliminated coin
				allCoins[captureCoinIndex].modeOff();
				//cout<<"Mode of "<<captureCoinIndex<<"set to :"<<0<<endl;
				//Appropriate Update
				board[tempFinalY][tempFinalX].setCoinId(coinId);
				//cout<<"CoinId of "<<tempFinalY<<tempFinalX<<" set as "<<coinId<<endl;
				board[tempFinalY][tempFinalX].setCoinIndex(coinIndex);
				//cout<<"CoinIndex of "<<tempFinalY<<tempFinalX<<" set as "<<coinIndex<<endl;
				board[tempInitY][tempInitX].setCoinId(EMPTY);
				//cout<<"CoinId of "<<tempInitY<<tempInitX<<" set as "<<EMPTY<<endl;
				board[tempInitY][tempInitX].setCoinIndex(EMPTY);
				//cout<<"CoinIndex of "<<tempInitY<<tempInitX<<" set as "<<EMPTY<<endl;
				
				displayInDock(captureCoinId);
				
				retValue= 1;
				nHistoryOfMoves++;
			} else if(coinId>=0 &&coinId<16 && captureCoinId>=16 && captureCoinId<32 && captureCoinId != WKING) 
			{ 	/*Black coin replacing White Coin*/
				
				//Appropriate changes in allCoins array
				allCoins[coinIndex].setCurPos(finalPos);
				allCoins[coinIndex].incNHistory();
				
				//Updation for Fifty Move Rule
				if( coinId >= 8 && coinId <= 23 ) {
					fiftyMoveRule=nHistoryOfMoves; 
				}

				//Switching off the mode for eliminated coin
				allCoins[captureCoinIndex].modeOff();
				
				//cout<<"Mode of "<<captureCoinIndex<<"set to :"<<0<<endl;
				//Appropriate Update
				board[tempFinalY][tempFinalX].setCoinId(coinId);
				board[tempFinalY][tempFinalX].setCoinIndex(coinIndex);
				board[tempInitY][tempInitX].setCoinId(EMPTY);
				board[tempInitY][tempInitX].setCoinIndex(EMPTY);
				displayInDock(captureCoinId);
				retValue= 1;
				nHistoryOfMoves++;
			} else if (captureCoinId==EMPTY) {   
				/*White or Black coin to EMPTY*/
				allCoins[coinIndex].setCurPos(finalPos);
				allCoins[coinIndex].incNHistory();
				
				
				if( coinId >= 8 && coinId <= 23 ) {
					fiftyMoveRule = nHistoryOfMoves;
				}
			
				/*Appropriate GUI Update*/
				board[tempFinalY][tempFinalX].setCoinId(coinId);
				board[tempFinalY][tempFinalX].setCoinIndex(coinIndex);
				//cout<<"CoinId for "<<tempFinalX<<tempFinalY<<"set as"<<coinId<<endl;
				//cout<<"CoinIndex for "<<tempFinalX<<tempFinalY<<"set as"<<coinIndex<<endl;
				
				board[tempInitY][tempInitX].setCoinId(EMPTY);
				board[tempInitY][tempInitX].setCoinIndex(EMPTY);
				//cout<<"coinId for "<<tempInitX<<tempInitY<<"set as "<<EMPTY<<endl;
				
				retValue= 0;
				//cout<<"retValue set to "<<0<<endl;
				nHistoryOfMoves++;
			} else {
				//cout<<"retvalue set to "<<-1<<endl;
				//cout<<"Invalid Move"<<endl;
				retValue = -1;
			
			}
		} else {
				//It is an Invalid Move
				//cout<<"invalid move"<<endl;
				retValue= -1; 
		}	
		
}


void updateRange() {

	int i,t=0;
	int tempX=0,tempY=0;
	//cout<<endl;
	for(i=0;i<=31;i++)  {
		
		if(allCoins[i].returnMode()==1) {
			
			t=allCoins[i].coinId;
			
			if(t >= 8 && t <= 23) {
				allCoins[i].updatePawn();
				
			} else if(t==LBROOK || t==RBROOK || t==LWROOK || t==RWROOK) {
				allCoins[i].updateRook();
				
				
			} else if(t==LBKNIGHT || t==RBKNIGHT || t==LWKNIGHT || t==RWKNIGHT) {
				allCoins[i].updateKnight();
				
				
			} else if(t==LBBISHOP || t==RBBISHOP || t==LWBISHOP || t==RWBISHOP) {
				allCoins[i].updateBishop();
				
				
			} else if(t==BQUEEN || t==WQUEEN) {
				allCoins[i].updateQueen();
				
				
			} else if(t==BKING || t==WKING) {
			   allCoins[i].updateKing();
			   
			   
			}
		}
	}
}


void initialize() {
		int i=0,j=0;
	
		
		//Setting  X and Y  and Colour in board
		for(int x=0;x<8;x++) {
			for(int y=0;y<8;y++) {
				
				board[y][x].setXY(x,y);
				board[y][x].getXY(i,j);
				if((x+y)%2==0) {
					board[y][x].setColor(1);
				} else {
					board[y][x].setColor(0);
				}
			}
		}
		
		
		//Setting coinId
		for(int x=0;x<8;x++) {
			board[0][x].setCoinId(x);
			board[0][x].setCoinIndex(x);
		}
		
		for(int x=0;x<8;x++) {
			board[1][x].setCoinId(x+8);
			board[1][x].setCoinIndex(x+8);
		}
		
		
		for(int x=0;x<8;x++) {
			for(int y=2;y<6;y++) {
				board[y][x].setCoinId(-1);
				board[y][x].setCoinIndex(-1);
			}
		}
		
		
		for(int x=0;x<8;x++) {
			board[6][x].setCoinId(x+16);
			board[6][x].setCoinIndex(x+16);
		}
		
		for(int x=0;x<8;x++) {
			board[7][x].setCoinId(x+24);
			board[7][x].setCoinIndex(x+24);
		}
		
		//iniitializing the current position
		int x;
		for (int i=0;i<8;i++) {
			x=i;
			allCoins[i].setCurPos(board[0][x]);
		}
		
		for (int i=8;i<16;i++) {
			x=i-8;
			allCoins[i].setCurPos(board[1][x]);
		}
		for (int i=16;i<24;i++) {
			x=i-16;
			allCoins[i].setCurPos(board[6][x]);
		}
		
		for (int i=24;i<32;i++) {
			x=i-24;
			allCoins[i].setCurPos(board[7][x]);
		}
		
		//intializing mode
		for (int i=0;i<32;i++ ) {
			allCoins[i].setMode(1);
		}
		
		//initializing colour
		for (int i=0;i<16;i++) {
			allCoins[i].setColour(0);
		}
		
		for(int i=16;i<32;i++) {
			allCoins[i].setColour(1);
		}
		
		//initialize History
		nHistoryOfMoves = 0;
		
		for( i = 0; i < 32; i++) {
			allCoins[i].setNHistory(0);
			allCoins[i].setCoinId(i);
		}
	
		updateRange();
		//displayBoardState();
		displayRange();
}


int FiftyMoveRule()	{

	if(nHistoryOfMoves-fiftyMoveRule==50) {
		//cout<<"its a draw situation "<<endl;
	}
	return 0;
}

void displayBoardState() {
	int tempColor, tempX, tempY;
	for(int i=0 ; i<8 ; i++) {
			for(int j=0;j<8;j++){
				tempColor=board[i][j].getColor();
				board[i][j].getXY(tempX,tempY);
				//cout<<tempX<<"  "<<tempY<<"  "<<tempColor<<"  "<<board[i][j].getCoinId()<<endl;
			}
	}
	//cout<<"\n\n\n\n\n";
} 

void displayRange() {
	int tempX, tempY;//cout<<endl;
	for(int i = 0;i<32; i++) {
		if(allCoins[i].returnMode()==1) {
			//cout<<i<<"  "<<allCoins[i].coinId<<"  "<<allCoins[i].nRange<<" : ";
			for(int j=0;j<allCoins[i].nRange;j++) {
				allCoins[i].coinRange[j].getXY(tempX,tempY);
				//cout<<tempX<<tempY<<"  ";
			}
			//cout<<endl;
		}
	}
}


	
#include "updateBishop_compiled3.cpp"
#include "updateKing_compiled3.cpp"
#include "updateKnight_compiled4.cpp"
#include "updatePawn_compiled3.cpp"
#include "updateQueen_compiled3.cpp"
#include "updateRook_compiled3.cpp"
//#include "unsufficientMaterial_compiled.cpp"
#include "modifyBoard_compiled2.cpp"
#include "verifyCheck_compiled.cpp"
#include "verifyCheckmateStalemate_compiled.cpp"

