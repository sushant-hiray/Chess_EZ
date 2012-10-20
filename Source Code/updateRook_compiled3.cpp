int Coin::updateRook () {

	Movement tempMove;
	nRange = 0;
	int i=1;
	int tempCoinId;
	int curRookX;										
	int curRookY;				//Stores current position of Rook.
                                                                                         
	int colorRook;			//Identifies whether Rook is black or white.	
	
	int coinIdRook;

	/*Get the color of Rook.*/							
	
	/*Get the position of Rook.*/
	curPos.getXY(curRookX,curRookY);
	
	
	tempMove.coinId=coinId;
	tempMove.initPos=curPos;

	/*Working on the white Rook*/
	if(coinId==LWROOK || coinId == RWROOK) {
		
		i=1;
		while((curRookY + i)<8){
			
			tempCoinId=board[curRookY + i][curRookX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curRookX,curRookY+i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <= BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curRookY + i][curRookX]);
					nRange++;
				}
				if(tempCoinId!=EMPTY) {
					break;
				}
			} 
			else {
				break;
			}
			i++;
		}	
		
		
		i=1;
		while((curRookY - i)>=0){
		
			tempCoinId=board[curRookY - i][curRookX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curRookX,curRookY-i);
			tempMove.finalPos=finalPos;
		
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curRookY - i][curRookX]);
					nRange++;
				}
				if(tempCoinId!=EMPTY) {
					break;
				}
			} 
			else {
				break;
			}
			i++;
		}		

		
		i=1;
		while((curRookX + i)<8){
		
			tempCoinId=board[curRookY][curRookX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curRookX+i,curRookY);
			tempMove.finalPos=finalPos;

			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curRookY][curRookX + i]);
					nRange++;
				}
				if(tempCoinId!=EMPTY) {
					break;
				}
			} 
			else {
				break;
			}
			i++;
		}				
			
			
		i=1;
		while((curRookX - i)>=0){
		
			tempCoinId=board[curRookY][curRookX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curRookX-i,curRookY);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curRookY][curRookX - i]);
					nRange++;
				}
				if(tempCoinId!=EMPTY) {
					break;
				}
			} 
			else {
				break;
			}
			i++;
		}				
			
	} else {
		
		i=1;
		while((curRookY + i)<8){
		
			tempCoinId=board[curRookY + i][curRookX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curRookX,curRookY+i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=WPAWN1 && tempCoinId <=RWROOK || tempCoinId== EMPTY) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curRookY + i][curRookX]);
					nRange++;
				}
				if(tempCoinId!=EMPTY) {
					break;
				}
			} 
			else {
				break;
			}
			i++;
		}	
		
		
		i=1;
		while((curRookY - i)>=0){
		
			tempCoinId=board[curRookY - i][curRookX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curRookX,curRookY-i);
			tempMove.finalPos=finalPos;
		
			if(tempCoinId >=WPAWN1 && tempCoinId <=RWROOK  || tempCoinId == EMPTY) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curRookY - i][curRookX]);
					nRange++;
				}
				if(tempCoinId!=EMPTY) {
					break;
				}
			} 
			else {
				break;
			}
			i++;
		}		

		
		i=1;
		while((curRookX + i)<8){
		
			tempCoinId=board[curRookY][curRookX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curRookX+i,curRookY);
			tempMove.finalPos=finalPos;

			if(tempCoinId >=WPAWN1 && tempCoinId <=RWROOK || tempCoinId==EMPTY) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curRookY][curRookX + i]);
					nRange++;
				}
				if(tempCoinId!=EMPTY) {
					break;
				}
			} 
			else {
				break;
			}
			i++;
		}				
			
			
		i=1;
		while((curRookX - i)>=0){
		
			tempCoinId=board[curRookY][curRookX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curRookX-i,curRookY);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=WPAWN1 && tempCoinId <=RWROOK || tempCoinId == EMPTY) {
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curRookY][curRookX - i]);
					nRange++;
				}
				if(tempCoinId!=EMPTY) {
					break;
				}
			} 
			else {
				break;
			}
			i++;
		}				
			
	}
	
	return 1;		
}
