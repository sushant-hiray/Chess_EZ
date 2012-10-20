/*Specifications:
*Created in gedit.exe
*Tab Width           :4
*Font                :Monospace Normal 12
*Lines Of Code       :
*/


/*
*Range of Queen
*@Version            :1.0.0  06 Nov 2011
*@Author             :Hardik Kothari
*/


//#include "class_decln_compiled.cpp"


int Coin::updateQueen () {

	Movement tempMove;
	
	nRange = 0;
	int i=1;
	int tempCoinId;
	int curQueenX;										
	int curQueenY;				//Stores current position of Queen.
                                                                                         
	int colorQueen;			//Identifies whether Queen is black or white.	
	

	/*Get the color of Queen.*/							
	colorQueen = getColour();

	/*Get the position of Queen.*/
	curPos.getXY(curQueenX,curQueenY);

	
	tempMove.coinId=coinId;
	tempMove.initPos=curPos;

	
	/*Working on the white Queen*/
	if(colorQueen==1) {
		
		i=1;
		while((curQueenX + i)<8){
		
			tempCoinId=board[curQueenY][curQueenX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX+i,curQueenY);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY][curQueenX + i]);
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
		while((curQueenX - i)>=0){
		
			tempCoinId=board[curQueenY][curQueenX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX-i,curQueenY);
			tempMove.finalPos=finalPos;
		
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY][curQueenX - i]);
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
		while((curQueenY + i)<8){
		
			tempCoinId=board[curQueenY + i][curQueenX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX,curQueenY+i);
			tempMove.finalPos=finalPos;

			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY + i][curQueenX]);
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
		while((curQueenY - i)>=0){
		
			tempCoinId=board[curQueenY - i][curQueenX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX,curQueenY-i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY - i][curQueenX]);
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
		while((curQueenX + i)<8 && (curQueenY + i)<8){
		
			tempCoinId=board[curQueenY + i][curQueenX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX+i,curQueenY+i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {	
					coinRange[nRange].copyObject(board[curQueenY + i][curQueenX + i]);
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
		while((curQueenX + i)<8 && (curQueenY - i)>=0){
		
			tempCoinId=board[curQueenY - i][curQueenX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX+i,curQueenY-i);
			tempMove.finalPos=finalPos;

			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY - i][curQueenX + i]);
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
		while((curQueenX - i)>=0 && (curQueenY + i)<8){
		
			tempCoinId=board[curQueenY + i][curQueenX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX-i,curQueenY+i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY + i][curQueenX - i]);
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
		while((curQueenX - i)>=0 && (curQueenY - i)>=0) {
		
			tempCoinId=board[curQueenY - i][curQueenX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX-i,curQueenY-i);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY - i][curQueenX - i]);
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
		
		return 1;
	
	} else if(colorQueen==0) {
		
		
		i=1;
		while((curQueenX + i)<8){
		
			tempCoinId=board[curQueenY][curQueenX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX+i,curQueenY);
			tempMove.finalPos=finalPos;
			
			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY][curQueenX + i]);
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
		
		while((curQueenX - i)>=0){
			
			tempCoinId=board[curQueenY][curQueenX-i].getCoinId();
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX-i,curQueenY);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY][curQueenX - i]);
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
		while((curQueenY + i)<8){
		
			tempCoinId=board[curQueenY + i][curQueenX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX,curQueenY+i);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY + i][curQueenX]);
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
		while((curQueenY - i)>=0){
		
			tempCoinId=board[curQueenY - i][curQueenX].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX,curQueenY-i);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY - i][curQueenX]);
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
		while((curQueenX + i)<8 && (curQueenY + i)<8){
		
			tempCoinId=board[curQueenY + i][curQueenX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX+i,curQueenY+i);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY + i][curQueenX + i]);
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
		while((curQueenX + i)<8 && (curQueenY - i)>=0){
		
			tempCoinId=board[curQueenY - i][curQueenX + i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX+i,curQueenY-i);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY - i][curQueenX + i]);
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
		while((curQueenX - i)>=0 && (curQueenY + i)<8){
		
			tempCoinId=board[curQueenY + i][curQueenX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX-i,curQueenY+i);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY + i][curQueenX - i]);
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
		while((curQueenX - i)>=0 && (curQueenY - i)>=0) {
		
			tempCoinId=board[curQueenY - i][curQueenX - i].getCoinId();
			
			tempMove.captureCoinId=tempCoinId;
			finalPos.setXY(curQueenX-i,curQueenY-i);
			tempMove.finalPos=finalPos;

			if(tempCoinId ==EMPTY || (tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)) {
				
				if(verifyCheck(tempMove)==1) {
					coinRange[nRange].copyObject(board[curQueenY - i][curQueenX - i]);
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

		return 1;
	}
}
