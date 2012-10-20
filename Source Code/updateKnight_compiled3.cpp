int Coin::updateKnight() {

	int nrange = 0;
	int tempCoinId;
	int curKnightX;										
	int curKnightY;				//Stores current position of Knight.
                                                                                         
	int colorKnight;			//Identifies whether Knight is black or white.	

	int coinIdKnight;
	
	Movement tempMove;
	
	/*Get the color of Knight.*/							
	colorKnight = getColour();

	/*Get the position of Knight.*/
	curPos.getXY(curKnightX,curKnightY);

		
	tempMove.coinId=coinId;
	tempMove.initPos=curPos;

	if(colorKnight==1) {
		/*White Knight*/
		
		for(int i=-1;i<=1;i=i+2) {
			for(int j=1;j<=2;j++) {
				
				if((curKnightY + i*j)<8 && (curKnightY +i*j)>=0 && (curKnightX + i*(3-j))>=0 && (curKnightX + i*(3-j))<8) {
					tempCoinId = board[curKnightY + i*j][curKnightX + i*(3-j)].getCoinId();
					tempMove.captureCoinId=tempCoinId;
					finalPos.setXY(curKnightX+i*(3-j),curKnightY+i*j);
					tempMove.finalPos=finalPos;
					/*Square contains either a black coin or it is empty.*/
					if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
						/*Then store it as a valid range.*/
						coinRange[nrange].copyObject(board[curKnightY + i*j][curKnightX + i*(3-j)]);
						nrange++;
					}
				
				}
				
				if((curKnightY +i*j)<8 && (curKnightY +i*j)>=0 && (curKnightX + -i*(3-j))>=0 && (curKnightX + -i*(3-j))<8) {
					tempCoinId = board[curKnightY + i*j][curKnightX + -i*(3-j)].getCoinId();
					tempMove.captureCoinId=tempCoinId;
					finalPos.setXY(curKnightX-i*(3-j),curKnightY+i*j);
					tempMove.finalPos=finalPos;
					/*Square contains either a black coin or it is empty.*/
					if(tempCoinId >=EMPTY && tempCoinId <=BPAWN8 && verifyCheck(tempMove)==1) {
						/*Then store it as a valid range.*/
						coinRange[nrange].copyObject(board[curKnightY + i*j][curKnightX + -i*(3-j)]);
						nrange++;
					}							
				}
			}
		} 
	} else {
		//Black Knight
		for(int i=-1;i<=1;i=i+2) {
			for(int j=1;j<=2;j++) {
				if((curKnightY +i*j)<8 && (curKnightY +i*j)>=0 && (curKnightX + i*(3-j))>=0 && (curKnightX + i*(3-j))<8) {
					tempCoinId = board[curKnightY + i*j][curKnightX + i*(3-j)].getCoinId();
					tempMove.captureCoinId=tempCoinId;
					finalPos.setXY(curKnightX+i*(3-j),curKnightY+i*j);
					tempMove.finalPos=finalPos;
					/*Square contains either a black coin or it is empty.*/
					if(((tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)||tempCoinId == EMPTY) && verifyCheck(tempMove)==1) {
						/*Then store it as a valid range.*/
						coinRange[nrange].copyObject(board[curKnightY + i*j][curKnightX + i*(3-j)]);
						nrange++;
					}
				}
				
				if((curKnightY +i*j)<8 && (curKnightY +i*j)>=0 && (curKnightX + -i*(3-j))>=0 && (curKnightX + -i*(3-j))<8) {
					tempCoinId = board[curKnightY + i*j][curKnightX + -i*(3-j)].getCoinId();
					tempMove.captureCoinId=tempCoinId;
					finalPos.setXY(curKnightX+i*(3-j),curKnightY+-i*j);
					tempMove.finalPos=finalPos;
					/*Square contains either a black coin or it is empty.*/
					if(((tempCoinId >=WPAWN1 && tempCoinId <=RWROOK)||tempCoinId == EMPTY) && verifyCheck(tempMove)==1) {
						/*Then store it as a valid range.*/
						coinRange[nrange].copyObject(board[curKnightY + i*j][curKnightX + -i*(3-j)]);
						nrange++;
					}							
				}
			}
		}
	}
}


