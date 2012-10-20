
int Movement::modifyBoard() {
	
	int initX, initY, finalX, finalY,t=0;
	initPos.getXY(initX, initY);
	finalPos.getXY(finalX, finalY);
	
	if(captureCoinId == EMPTY) {
		if(coinId >=8 && coinId <=23 && board[initY][finalX].getCoinId() >=8 && board[initY][finalX].getCoinId()<=23 &&(initX-finalX == 1 || finalX-initX ==1)) {
			//EnPassant
			board[finalY][finalX].setCoinId(coinId);
			board[initY][initX].setCoinId(EMPTY);
			t=board[initY][finalX].getCoinId();
			board[initY][finalX].setCoinId(EMPTY);
			
		} else if((coinId == WKING || coinId == BKING) && (finalX-initX==2 ||initX-finalX==2)) {
			//Castling
			if(finalX > initX) {
				board[finalY][finalX].setCoinId(coinId);
				board[initY][initX].setCoinId(EMPTY);
				board[initY][initX+3].setCoinId(EMPTY);
				if(coinId <16) {				
					board[finalY][finalX-1].setCoinId(RBROOK);
				} else {
					board[finalY][finalX-1].setCoinId(RWROOK);
				}
			} else if(initX > finalX) {
				board[finalY][finalX].setCoinId(coinId);
				board[initY][initX].setCoinId(EMPTY);
				board[initY][initX-4].setCoinId(EMPTY);
				if(coinId < 16) {				
					board[finalY][finalX+1].setCoinId(LBROOK);
				} else {
					board[finalY][finalX+1].setCoinId(LWROOK);
				}
			}
		} else {
			//normal 
			board[finalY][finalX].setCoinId(coinId);
			board[initY][initX].setCoinId(EMPTY);
		}
	} else if(coinId==captureCoinId && (coinId==WKING || coinId ==BKING)) {
		return -2;
	} else if(captureCoinId >=0 && captureCoinId <32) {
			//elimination
			board[finalY][finalX].setCoinId(coinId);
			board[initY][initX].setCoinId(EMPTY);
	} 
return t;
}

int Movement::undoBoard(int t) {
	int initX, initY, finalX, finalY;
	initPos.getXY(initX, initY);
	finalPos.getXY(finalX, finalY);
	
	if(t>0) {				
		board[finalY][finalX].setCoinId(EMPTY);
		board[initY][initX].setCoinId(coinId);
		board[initY][finalX].setCoinId(t);		
	} else if(t==0) {
		if((coinId == WKING || coinId == BKING) && (finalX-initX==2 ||initX-finalX==2)) {
			if(finalX > initX) {
				board[finalY][finalX].setCoinId(EMPTY);
				board[initY][initX].setCoinId(coinId);
				board[finalY][finalX-1].setCoinId(EMPTY);
				if(coinId < 16) {				
					board[initY][initX+3].setCoinId(RBROOK);
				} else {
					board[initY][initX+3].setCoinId(RWROOK);
				}
			} else if(initX > finalX) {
				board[finalY][finalX].setCoinId(EMPTY);
				board[initY][initX].setCoinId(coinId);
				board[finalY][finalX+1].setCoinId(EMPTY);
				if(coinId < 16) {				
					board[initY][initX-4].setCoinId(LBROOK);
				} else {
					board[initY][initX-4].setCoinId(LWROOK);
				}
			}
		} else if(captureCoinId==EMPTY) {
			board[finalY][finalX].setCoinId(EMPTY);
			board[initY][initX].setCoinId(coinId);
		} else {
			board[finalY][finalX].setCoinId(captureCoinId);
			board[initY][initX].setCoinId(coinId);
		}
	} else if(t==-2) {
	}		
}
