/*Specifications:
*Created in gedit.exe
*Tab width 		: 4
*Font 	   		: Monospace Normal 12
*Lines of code		: 410
*/

/*this function mainly aims towards updating the range of pawns
*it contains separate functions for both the colors (W and B)
*@version 1.0.3  < 7 Nov 2011>
*@author: Sushant Hiray
*/

/*macros used */


#define EMPTY -1


int Coin::updatePawn()
{
	int curPawnX;
	int curPawnY;
	int colorPawn;
	int tempCoinId;
	
	Movement tempMove;
	nRange=0;
	
	colorPawn = colour;
	
	curPos.getXY(curPawnX,curPawnY);
	tempMove.coinId=coinId;
	tempMove.initPos=curPos;
	
	
	if(colorPawn==0){
		tempCoinId=board[curPawnY+1][curPawnX].getCoinId();
		
		if(tempCoinId==EMPTY && curPawnY+1 < 8 ) { 
			tempMove.captureCoinId=EMPTY;
			finalPos.setXY(curPawnX,curPawnY+1);
			tempMove.finalPos=finalPos;
			if(verifyCheck(tempMove)==1){
				
				coinRange[nRange].copyObject(board[curPawnY+1][curPawnX]);
				nRange++;
			}
		}
		
		tempCoinId=board[curPawnY+2][curPawnX].getCoinId();
		if(tempCoinId==EMPTY && curPawnY == 1 && board[curPawnY+1][curPawnX].getCoinId()==EMPTY) { 
			tempMove.captureCoinId=EMPTY;
			finalPos.setXY(curPawnX,curPawnY+2);
			tempMove.finalPos=finalPos;
			if(verifyCheck(tempMove)==1){
				coinRange[nRange].copyObject(board[curPawnY+2][curPawnX]);
				nRange++;
			}
		}
		
		tempCoinId=board[curPawnY+1][curPawnX+1].getCoinId();
		if(curPawnY+1 < 8 && curPawnX +1 <8 ) { 
			if(tempCoinId >=16 && tempCoinId <32) {			
				tempMove.captureCoinId=tempCoinId;
				finalPos.setXY(curPawnX+1,curPawnY+1);
				tempMove.finalPos=finalPos;
				if(verifyCheck(tempMove)==1){
					coinRange[nRange].copyObject(board[curPawnY+1][curPawnX+1]);
					nRange++;
					cout<<"nRange set to"<<nRange<<endl;
				}
			} else if(tempCoinId == EMPTY and board[curPawnY][curPawnX+1].getCoinId()>=16 && board[curPawnY][curPawnX+1].getCoinId()<24 && curPawnY==4) {	
				tempMove.captureCoinId=tempCoinId;
				finalPos.setXY(curPawnX+1,curPawnY+1);
				tempMove.finalPos=finalPos;
				if(verifyCheck(tempMove)==1){
					coinRange[nRange].copyObject(board[curPawnY+1][curPawnX+1]);
					nRange++;
				}
			}
		}
		
		tempCoinId=board[curPawnY+1][curPawnX-1].getCoinId();
		if(curPawnX-1 >= 0 && curPawnY +1 <8 ) { 
			if(tempCoinId >=16 && tempCoinId <32) {			
				tempMove.captureCoinId=tempCoinId;
				finalPos.setXY(curPawnX-1,curPawnY+1);
				tempMove.finalPos=finalPos;
				if(verifyCheck(tempMove)==1){
					coinRange[nRange].copyObject(board[curPawnY+1][curPawnX-1]);
					nRange++;
				}
			} else if(tempCoinId == EMPTY and board[curPawnY][curPawnX-1].getCoinId()>=16 && board[curPawnY][curPawnX-1].getCoinId()<24 && curPawnY==4) {	
				tempMove.captureCoinId=tempCoinId;
				finalPos.setXY(curPawnX-1,curPawnY+1);
				tempMove.finalPos=finalPos;
				if(verifyCheck(tempMove)==1){
					coinRange[nRange].copyObject(board[curPawnY+1][curPawnX-1]);
					nRange++;
				}
			}
		} 
	} else if(colorPawn==1){
		tempCoinId=board[curPawnY-1][curPawnX].getCoinId();
		if(tempCoinId==EMPTY && curPawnY-1 >= 0 ) { 
			
			tempMove.captureCoinId=EMPTY;
			finalPos.setXY(curPawnX,curPawnY-1);
			tempMove.finalPos=finalPos;
			if(verifyCheck(tempMove)==1){
				coinRange[nRange].copyObject(board[curPawnY-1][curPawnX]);
				nRange++;
			}
		}

		tempCoinId=board[curPawnY-2][curPawnX].getCoinId();
		if(tempCoinId==EMPTY && curPawnY == 6 && board[curPawnY-1][curPawnX].getCoinId()==EMPTY) { 
			tempMove.captureCoinId=EMPTY;
			finalPos.setXY(curPawnX,curPawnY-2);
			tempMove.finalPos=finalPos;
			if(verifyCheck(tempMove)==1){
				coinRange[nRange].copyObject(board[curPawnY-2][curPawnX]);
				nRange++;
			}
		}
		
		tempCoinId=board[curPawnY-1][curPawnX+1].getCoinId();
		if(curPawnY-1 >= 0 && curPawnX +1 <8 ) { 
			if(tempCoinId <16 && tempCoinId >=0) {			
				tempMove.captureCoinId=tempCoinId;
				finalPos.setXY(curPawnX+1,curPawnY-1);
				tempMove.finalPos=finalPos;
				if(verifyCheck(tempMove)==1){
					coinRange[nRange].copyObject(board[curPawnY-1][curPawnX+1]);
					nRange++;
				}
			} else if(tempCoinId == EMPTY and board[curPawnY][curPawnX+1].getCoinId()<16 && board[curPawnY][curPawnX+1].getCoinId()>=8 &&curPawnY==3) {	
				tempMove.captureCoinId=tempCoinId;
				finalPos.setXY(curPawnX+1,curPawnY-1);
				tempMove.finalPos=finalPos;
				if(verifyCheck(tempMove)==1){
					coinRange[nRange].copyObject(board[curPawnY-1][curPawnX+1]);
					nRange++;
				}
			}
		}
		
		tempCoinId=board[curPawnY-1][curPawnX-1].getCoinId();
		if(curPawnY-1 >= 0 && curPawnX -1 <8 ) { 
			if(tempCoinId <16 && tempCoinId >=0) {			
				tempMove.captureCoinId=tempCoinId;
				finalPos.setXY(curPawnX-1,curPawnY-1);
				tempMove.finalPos=finalPos;
				if(verifyCheck(tempMove)==1){
					coinRange[nRange].copyObject(board[curPawnY-1][curPawnX-1]);
					nRange++;
				}
			} else if(tempCoinId == EMPTY and board[curPawnY][curPawnX-1].getCoinId()>=8 && board[curPawnY][curPawnX-1].getCoinId()<16 && curPawnY==3) {	
				tempMove.captureCoinId=tempCoinId;
				finalPos.setXY(curPawnX-1,curPawnY-1);
				tempMove.finalPos=finalPos;
				if(verifyCheck(tempMove)==1){
					coinRange[nRange].copyObject(board[curPawnY-1][curPawnX-1]);
					nRange++;
				}
			}
		}
}
}		
		
