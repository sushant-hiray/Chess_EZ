int Coin::updateKnight() {

	nRange = 0;
	int tempCoinId;
	int curKnightX;										
	int curKnightY;				//Stores current position of Knight.
                                                                                         
	int colorKnight;			//Identifies whether Knight is black or white.	

	Movement tempMove;
	
	/*Get the color of Knight.*/							
	colorKnight = colour;

	/*Get the position of Knight.*/
	curPos.getXY(curKnightX,curKnightY);

		
	tempMove.coinId=coinId;
	tempMove.initPos=curPos;
	
	
	if(colorKnight==1) {
		
		if((curKnightY + 1)<8 && (curKnightY +1)>=0 && (curKnightX + 2)>=0 && (curKnightX + 2)<8) {
			tempCoinId = board[curKnightY + 1][curKnightX + 2].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX +2,curKnightY+1);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY + 1][curKnightX + 2]);
				nRange++;
			}
		}

		if((curKnightY - 1)<8 && (curKnightY -1)>=0 && (curKnightX + 2)>=0 && (curKnightX + 2)<8) {
			tempCoinId = board[curKnightY - 1][curKnightX + 2].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX +2,curKnightY-1);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY - 1][curKnightX + 2]);
				nRange++;
			}
		}

		if((curKnightY - 1)<8 && (curKnightY -1)>=0 && (curKnightX - 2)>=0 && (curKnightX - 2)<8) {
			tempCoinId = board[curKnightY - 1][curKnightX - 2].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX-2,curKnightY-1);
			tempMove.finalPos=finalPos;
			
			/*Square contains either a black coin or it is empty.*/
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				
				coinRange[nRange].copyObject(board[curKnightY - 1][curKnightX - 2]);
				nRange++;
			} 
		}

		if((curKnightY + 1)<8 && (curKnightY +1)>=0 && (curKnightX - 2)>=0 && (curKnightX - 2)<8) {
			tempCoinId = board[curKnightY + 1][curKnightX - 2].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX -2,curKnightY+1);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY + 1][curKnightX - 2]);
				nRange++;
			}
		}

		if((curKnightY + 2)<8 && (curKnightY +2)>=0 && (curKnightX + 1)>=0 && (curKnightX + 1)<8) {
			tempCoinId = board[curKnightY + 2][curKnightX + 1].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX +1,curKnightY+2);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY + 2][curKnightX + 1]);
				nRange++;
			}
		}

		if((curKnightY - 2)<8 && (curKnightY -2)>=0 && (curKnightX + 1)>=0 && (curKnightX + 1)<8) {
			tempCoinId = board[curKnightY - 2][curKnightX + 1].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX +1,curKnightY-2);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY - 2][curKnightX + 1]);
				nRange++;
			}
		}

		if((curKnightY - 2)<8 && (curKnightY -2)>=0 && (curKnightX - 1)>=0 && (curKnightX - 1)<8) {
			tempCoinId = board[curKnightY - 2][curKnightX - 1].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX -1,curKnightY-2);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY - 2][curKnightX - 1]);
				nRange++;
			}
		}

		if((curKnightY + 2)<8 && (curKnightY +2)>=0 && (curKnightX -1)>=0 && (curKnightX - 1)<8) {
			tempCoinId = board[curKnightY + 2][curKnightX - 1].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX -1,curKnightY+2);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY + 2][curKnightX - 1]);
				nRange++;
			}
		}
	
	} else if(colorKnight==0) {
		
		if((curKnightY + 1)<8 && (curKnightY +1)>=0 && (curKnightX + 2)>=0 && (curKnightX + 2)<8) {
			tempCoinId = board[curKnightY + 1][curKnightX + 2].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX +2,curKnightY+1);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if((tempCoinId==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK ))&& verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY + 1][curKnightX + 2]);
				nRange++;
			}
		}

		if((curKnightY - 1)<8 && (curKnightY -1)>=0 && (curKnightX + 2)>=0 && (curKnightX + 2)<8) {
			tempCoinId = board[curKnightY - 1][curKnightX + 2].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX +2,curKnightY-1);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if((tempCoinId==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK ))&& verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY - 1][curKnightX + 2]);
				nRange++;
			}
		}

		if((curKnightY - 1)<8 && (curKnightY -1)>=0 && (curKnightX - 2)>=0 && (curKnightX - 2)<8) {
			tempCoinId = board[curKnightY - 1][curKnightX - 2].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX -2,curKnightY-1);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if((tempCoinId==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK ))&& verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY - 1][curKnightX - 2]);
				nRange++;
			}
		}

		if((curKnightY + 1)<8 && (curKnightY +1)>=0 && (curKnightX - 2)>=0 && (curKnightX - 2)<8) {
			tempCoinId = board[curKnightY + 1][curKnightX - 2].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX -2,curKnightY+1);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if((tempCoinId==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK ))&& verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY + 1][curKnightX - 2]);
				nRange++;
			}
		}

		if((curKnightY + 2)<8 && (curKnightY +2)>=0 && (curKnightX + 1)>=0 && (curKnightX + 1)<8) {
			tempCoinId = board[curKnightY + 2][curKnightX + 1].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX +1,curKnightY+2);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if((tempCoinId==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK ))&& verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY + 2][curKnightX + 1]);
				nRange++;
			}
		}

		if((curKnightY - 2)<8 && (curKnightY -2)>=0 && (curKnightX + 1)>=0 && (curKnightX + 1)<8) {
			tempCoinId = board[curKnightY - 2][curKnightX + 1].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX +1,curKnightY-2);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if((tempCoinId==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK ))&& verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY - 2][curKnightX + 1]);
				nRange++;
			}
		}

		if((curKnightY - 2)<8 && (curKnightY -2)>=0 && (curKnightX - 1)>=0 && (curKnightX - 1)<8) {
			tempCoinId = board[curKnightY - 2][curKnightX - 1].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX -1,curKnightY-2);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if((tempCoinId==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK ))&& verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY - 2][curKnightX - 1]);
				nRange++;
			}
		}

		if((curKnightY + 2)<8 && (curKnightY +2)>=0 && (curKnightX -1)>=0 && (curKnightX - 1)<8) {
			tempCoinId = board[curKnightY + 2][curKnightX - 1].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curKnightX -1,curKnightY+2);
			tempMove.finalPos=finalPos;
			/*Square contains either a black coin or it is empty.*/
			if((tempCoinId==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK ))&& verifyCheck(tempMove)==1) {
				/*Then store it as a valid range.*/
				coinRange[nRange].copyObject(board[curKnightY + 2][curKnightX - 1]);
				nRange++;
			}
		}
	}
	
}

