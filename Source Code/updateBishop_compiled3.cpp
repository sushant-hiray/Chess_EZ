int Coin::updateBishop () {

	Movement tempMove;
	int i=1;
	nRange = 0;
	int tempCoinId;
	int curBishopX;										
	int curBishopY;				//Stores current position of Bishop.
                                                                                         
	int colorBishop;			//Identifies whether Bishop is black or white.	
	
	int coinIdBishop;

	/*Get the color of Bishop.*/							
	colorBishop = getColour();

	/*Get the position of Bishop.*/
	curPos.getXY(curBishopX,curBishopY);

	tempMove.coinId=coinId;
	tempMove.initPos=curPos;

	/*Working on the white Bishop*/
	if(colorBishop==1) {
		
		i=1;
		while((curBishopY + i)<8 && (curBishopX + i)<8 ){
		
			tempCoinId=board[curBishopY + i][curBishopX+i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curBishopX+i,curBishopY+i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curBishopY + i][curBishopX+i]);
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
		while((curBishopY - i)>=0 && (curBishopX + i)<8){
		
			tempCoinId=board[curBishopY - i][curBishopX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curBishopX+i,curBishopY-i);
			tempMove.finalPos=finalPos;
		
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curBishopY - i][curBishopX+i]);
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
		while((curBishopY + i)<8 && (curBishopX - i)>=0 ){
		
			tempCoinId=board[curBishopY+i][curBishopX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curBishopX-i,curBishopY+i);
			tempMove.finalPos=finalPos;

			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curBishopY+i][curBishopX - i]);
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
		while((curBishopY - i)>=0 && (curBishopX - i)>=0){
		
			tempCoinId=board[curBishopY-i][curBishopX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curBishopX-i,curBishopY-i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curBishopY-i][curBishopX - i]);
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
			
	} else if(colorBishop==0) {
		
		i=1;
		while((curBishopY + i)<8 && (curBishopX + i)<8){
		
			tempCoinId=board[curBishopY + i][curBishopX+i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curBishopX+i,curBishopY+i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=WPAWN1 && tempCoinId <=RWROOK || tempCoinId== EMPTY) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curBishopY + i][curBishopX+i]);
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
		while((curBishopY - i)>=0 && (curBishopX + i)<8){
		
			tempCoinId=board[curBishopY - i][curBishopX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curBishopX+i,curBishopY-i);
			tempMove.finalPos=finalPos;
		
			if(tempCoinId >=WPAWN1 && tempCoinId <=RWROOK  || tempCoinId == EMPTY) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curBishopY - i][curBishopX+i]);
					nRange++;
				}
				if(tempCoinId!=EMPTY) {
					break;
				}
			} else {
				break;
			}
			i++;
		}		

		
		i=1;
		while((curBishopY + i)<8 && (curBishopX - i) >=0){
		
			tempCoinId=board[curBishopY + i][curBishopX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curBishopX-i,curBishopY+i);
			tempMove.finalPos=finalPos;

			if(tempCoinId >=WPAWN1 && tempCoinId <=RWROOK || tempCoinId==EMPTY) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curBishopY+i][curBishopX - i]);
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
		while((curBishopY - i)>=0 && (curBishopX - i)>=0){
		
			tempCoinId=board[curBishopY-i][curBishopX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curBishopX-i,curBishopY-i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=WPAWN1 && tempCoinId <=RWROOK || tempCoinId == EMPTY) {
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curBishopY-i][curBishopX - i]);
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
}
