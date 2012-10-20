/*Specifications:
*Created in gedit.exe
*Tab Width           :4
*Font                :Monospace Normal 12
*Lines Of Code       :
*/


/*
*Range of King
*@Version            :1.0.0  06 Nov 2011
*@Author             :Hardik Kothari
*/


//#include "class_decln_compiled.cpp"


int Coin::updateKing () {

	Movement tempMove;
	nRange = 0;
	int tempCoinId;
	int curKingX;										
	int curKingY;				//Stores current position of King.
                                                                                         
	int colorKing;			//Identifies whether King is black or white.	
	

	/*Get the color of King.*/							
	colorKing = getColour();

	/*Get the position of King.*/
	curPos.getXY(curKingX,curKingY);

	tempMove.coinId=coinId;
	tempMove.initPos=curPos;

	/*Working on the white King*/
	if(colorKing==1) {
		
		if((curKingX + 1)<8){
		
			tempCoinId=board[curKingY][curKingX + 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX+1,curKingY);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY][curKingX + 1]);
					nRange++;
				}
			} 
		}	
		
		if((curKingX - 1)>=0){
		
			tempCoinId=board[curKingY][curKingX - 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX-1,curKingY);
			tempMove.finalPos=finalPos;
		
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY][curKingX - 1]);
					nRange++;
				}
			}		
		}

		if((curKingY + 1)<8){
		
			tempCoinId=board[curKingY + 1][curKingX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX,curKingY+1);
			tempMove.finalPos=finalPos;

			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY + 1][curKingX]);
					nRange++;
				}
			
			}
			
		}				
			
			
		if((curKingY - 1)>=0){
		
			tempCoinId=board[curKingY - 1][curKingX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX,curKingY-1);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY - 1][curKingX]);
					nRange++;
				}
				
			}
			
		}				
			
			
		
		if((curKingX + 1)<8 && (curKingY + 1)<8){
		
			tempCoinId=board[curKingY + 1][curKingX + 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX+1,curKingY+1);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {	
					coinRange[nRange].copyObject(board[curKingY + 1][curKingX + 1]);
					nRange++;
				}
			}
			
		}				
		
		
		
		if((curKingX + 1)<8 && (curKingY - 1)>=0){
		
			tempCoinId=board[curKingY - 1][curKingX + 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX+1,curKingY-1);
			tempMove.finalPos=finalPos;

			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY - 1][curKingX + 1]);
					nRange++;
				}
			}
			
		}	
			
		
		
		if((curKingX - 1)>=0 && (curKingY + 1)<8){
		
			tempCoinId=board[curKingY + 1][curKingX - 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX-1,curKingY+1);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY + 1][curKingX - 1]);
					nRange++;
				}
			}
			
		}
		
		
		
		if((curKingX - 1)>=0 && (curKingY - 1)>=0) {
		
			tempCoinId=board[curKingY - 1][curKingX - 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX-1,curKingY-1);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY - 1][curKingX - 1]);
					nRange++;
				}
	
			}
			
		}
		nRange=nRange;
		
	
	} else if(colorKing==0) {
		
		
		
		if((curKingX + 1)<8){
		
			tempCoinId=board[curKingY][curKingX + 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX+1,curKingY);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY][curKingX + 1]);
					nRange++;
				}
	
			}
		}	
		
		
		
		if((curKingX - 1)>=0){
		
			tempCoinId=board[curKingY][curKingX-1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX-1,curKingY);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY][curKingX - 1]);
					nRange++;
				}
			}
			
		}		

		
		
		if((curKingY + 1)<8){
		
			tempCoinId=board[curKingY + 1][curKingX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX,curKingY + 1);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY + 1][curKingX]);
					nRange++;
				}
			
			}
			
		}				
			
			
		
		if((curKingY - 1)>=0){
		
			tempCoinId=board[curKingY - 1][curKingX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX,curKingY - 1);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY - 1][curKingX]);
					nRange++;
				}
			
			}
			
		}				
			
			
		
		if((curKingX + 1)<8 && (curKingY + 1)<8){
		
			tempCoinId=board[curKingY + 1][curKingX + 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX + 1,curKingY + 1);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY + 1][curKingX + 1]);
					nRange++;
				}
			
			}
			
		}				
		
		
		
		if((curKingX + 1)<8 && (curKingY - 1)>=0){
		
			tempCoinId=board[curKingY - 1][curKingX + 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX + 1,curKingY - 1);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY - 1][curKingX + 1]);
					nRange++;
				}
			
			}
			
		}	
			
		
		
		if((curKingX - 1)>=0 && (curKingY + 1)<8){
		
			tempCoinId=board[curKingY + 1][curKingX - 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX - 1,curKingY + 1);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY + 1][curKingX - 1]);
					nRange++;
				}
			
			}
			
		}
		
		
		
		if((curKingX - 1)>=0 && (curKingY - 1)>=0) {
		
			tempCoinId=board[curKingY - 1][curKingX - 1].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKingX - 1,curKingY - 1);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curKingY - 1][curKingX - 1]);
					nRange++;
				}
			
			}
			
		}

	}


	//Castling Movement
	if(curKingX == 4 && curKingY == 0 && colorKing == 0 && nHistory==0 ) {
		if(board[0][5].getCoinId()==-1 && board[0][6].getCoinId()==-1 && allCoins[RBROOK].returnNHistory() == 0 && board[0][7].getCoinId()==7) {
			tempMove.captureCoinId = EMPTY;
			tempMove.finalPos.setXY(6,0);		
	
			if(verifyCheck(tempMove)==1) {
				coinRange[nRange].copyObject(board[0][6]);
				nRange++;			
			}
		} else if(board[0][3].getCoinId()==-1 && board[0][2].getCoinId()==-1 && board[0][1].getCoinId()==-1 && allCoins[LBROOK].returnNHistory() == 0) {
			tempMove.captureCoinId = EMPTY;
			tempMove.finalPos.setXY(2,0);		
	
			if(verifyCheck(tempMove)==1) {
				coinRange[nRange].copyObject(board[0][2]);
				nRange++;			
			}

		}
	} else if(curKingX == 4 && curKingY == 7 && colorKing == 1 && nHistory==0 ) {
		if(board[7][5].getCoinId()==-1 && board[7][6].getCoinId()==-1 && allCoins[RWROOK].returnNHistory() == 0) {
			tempMove.captureCoinId = EMPTY;
			tempMove.finalPos.setXY(6,7);		
	
			if(verifyCheck(tempMove)==1) {
				coinRange[nRange].copyObject(board[7][6]);
				nRange++;			
			}
		} else if(board[7][3].getCoinId()==-1 && board[7][2].getCoinId()==-1 && board[7][1].getCoinId()==-1 && allCoins[LWROOK].returnNHistory() == 0 && board[7][7].getCoinId()==31) {
			tempMove.captureCoinId = EMPTY;
			tempMove.finalPos.setXY(2,7);		
	
			if(verifyCheck(tempMove)==1) {
				coinRange[nRange].copyObject(board[7][2]);
				nRange++;			
			}

		}
	}
	
}
