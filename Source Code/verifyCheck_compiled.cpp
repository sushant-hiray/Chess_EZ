/*
*Specifications:
*Created in gedit.exe
*Tab width 		: 4
*Font 	   		: Monospace Normal 12
*Lines of code	: 638
*/


/*
*Definition of the verifyCheck() function
*@version: 1.0.0 06 Oct 2011
*@author : Guna Prasaad
*/


/*
*The verifyCheck() function uses the following inputs and produces the output
*INPUT : Movement tempMove, Position board[8][8], Coin allCoins[32]
*OUTPUT: '1' if the movement is permitted
*	     '0' if the movement is not permitted
*/  

//#include "class_decln_compiled.cpp"
//#include "modifyBoard_compiled.cpp"
//#include "undoBoard_compiled.cpp"

int	Coin::verifyCheck (Movement tempMove) {
	
	int		curKingX;
	int		curKingY;																//Stores the current position of king
	
	
	int 	i;
	/*Get the color of the current player*/

	
	/*Modify the board for temporary movement before getting position of king*/
	int t= tempMove.modifyBoard();
 		
	/*To identify and initialize the x, y positions of king*/


	
	/*Working on the white king*/
	if (coinId >=16 && coinId<32) {
		for(int y =0;y<8;y++) {
			for(int x=0;x<8;x++) {
				if(board[y][x].getCoinId()==WKING) {
					curKingX = x;
					curKingY = y;		
					break;
				}
			}	
		}
		i=1;
	//	cout<<"Position of King is: "<<curKingX<<curKingY<<endl;
		/*Check condition for horizontal right squares from king*/
		while (curKingX + i < 8) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY][curKingX+i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LBROOK || tempCoinId == RBROOK || tempCoinId == BQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);				
				return 0;
			} else if (tempCoinId == BKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);					
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}
		}
		i=1;
	
		/*Check condition for horizontal left squares from king*/
		while (curKingX - i >= 0) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY][curKingX-i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LBROOK || tempCoinId == RBROOK || tempCoinId == BQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == BKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}
		i=1;
		/*Check condition for vertical down squares from king*/
		while (curKingY + i < 8) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY+i][curKingX].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LBROOK || tempCoinId == RBROOK || tempCoinId == BQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == BKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}
		}
	
		i=1;
		/*Check condition for vertically up squares from king*/
		while (curKingY - i >= 0) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY-i][curKingX].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LBROOK || tempCoinId == RBROOK || tempCoinId == BQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == BKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}
		i=1;
		/*Check condition for diagonal top right from king*/
		while (curKingY - i >= 0 && curKingX + i < 8) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY-i][curKingX+i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LBBISHOP || tempCoinId == RBBISHOP || tempCoinId == BQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == BKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);				
				return 0;
			} else if (tempCoinId >= BPAWN1 && tempCoinId <= BPAWN8 && i == 1) {
				/*Adjacent square contains opposite pawn*/ 
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}
	
		i=1;
		/*Check condition for diagonal top left from king*/
		while (curKingY - i >= 0 && curKingX - i >= 0) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY- i][curKingX - i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LBBISHOP || tempCoinId == RBBISHOP || tempCoinId == BQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t); 
				return 0;
			} else if (tempCoinId == BKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);			
				return 0;
			} else if (tempCoinId >= BPAWN1 && tempCoinId <= BPAWN8 && i == 1) {
				/*Adjacent square contains opposite pawn*/ 
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}
	
		i=1;
		/*Check condition for diagonal bottom right from king*/
		while (curKingY + i < 8 && curKingX + i < 8) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY + i][curKingX + i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LBBISHOP || tempCoinId == RBBISHOP || tempCoinId == BQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == BKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}
		i=1;
		/*Check condition for diagonal bottom left from king*/
		while (curKingY + i < 8 && curKingX - i >= 0) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY + i][curKingX - i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LBBISHOP || tempCoinId == RBBISHOP || tempCoinId == BQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);				
				return 0;
			} else if (tempCoinId == BKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}

		/* Block for Checking  for 8 horse positions */
		{
			if (curKingX + 1 < 8 && curKingY + 2 < 8) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY + 2][curKingX+ 1].getCoinId();		
				
				if (tempCoinId == LBKNIGHT || tempCoinId == RBKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	        
			if (curKingX + 2 < 8 && curKingY + 1 < 8) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY+1][curKingX +2].getCoinId();		
				
				if (tempCoinId == LBKNIGHT || tempCoinId == RBKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	        
			if (curKingX - 1 >= 0 && curKingY - 2 >= 0) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY-2][curKingX - 1].getCoinId();		
				
				if (tempCoinId == LBKNIGHT || tempCoinId == RBKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	        
			if (curKingX - 2 >= 0 && curKingY - 1 >= 0) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY - 1][curKingX - 2].getCoinId();		
				
				if (tempCoinId == LBKNIGHT || tempCoinId == RBKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	        
			if (curKingX + 1 < 8 && curKingY - 2 >= 0) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY - 2][curKingX + 1].getCoinId();		
				
				if (tempCoinId == LBKNIGHT || tempCoinId == RBKNIGHT) {
					tempMove.undoBoard(t);
 					return 0;
				}
			}	
  	      
			if (curKingX - 1 >= 0 && curKingY + 2 < 8) {
			
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY+ 2][curKingX-1].getCoinId();		
				
				if (tempCoinId == LBKNIGHT || tempCoinId == RBKNIGHT) {
					tempMove.undoBoard(t);	
	 				return 0;
				}
			}	
	
		        if (curKingX + 2 < 8 && curKingY - 1 >= 0) {
			
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY-1][curKingX+ 2].getCoinId();		
				
				if (tempCoinId == LBKNIGHT || tempCoinId == RBKNIGHT) {
					tempMove.undoBoard(t);
		 			return 0;
				}
			}	
        
			if (curKingX - 2 >= 0 && curKingY + 1 < 8) {
			
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY+1][curKingX- 2].getCoinId();		
				
				if (tempCoinId == LBKNIGHT || tempCoinId == RBKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	    }
	} else {
		 /*Working on Black King */
		
		for(int y =0;y<8;y++) {
			for(int x=0;x<8;x++) {
				if(board[y][x].getCoinId()==BKING) {
					curKingX = x;
					curKingY = y;		
					break;
				}
			}	
		}
	//	cout<<"Position of King is: "<<curKingX<<curKingY<<endl;
		 /*Check condition for horizontal right squares from king*/
		 i=1;
		 while (curKingX + i < 8) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY][curKingX+i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LWROOK || tempCoinId == RWROOK || tempCoinId == WQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == WKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}
		}
		i=1;
		/*Check condition for horizontal left squares from king*/
		while (curKingX - i >= 0) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY][curKingX-i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LWROOK || tempCoinId == RWROOK || tempCoinId == WQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == WKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}

		i=1;
		/*Check condition for vertical down squares from king*/
		while (curKingY + i < 8) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY + i][curKingX].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LWROOK || tempCoinId == RWROOK || tempCoinId == WQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == WKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}
		}
	
		i=1;
		/*Check condition for vertically up squares from king*/
		while (curKingY - i >= 0) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY-i][curKingX].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LWROOK || tempCoinId == RWROOK || tempCoinId == WQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == WKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}

		i=1;
		/*Check condition for diagonal top right from king*/
		while (curKingY - i >= 0 && curKingX + i < 8) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY- i][curKingX+ i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LWBISHOP || tempCoinId == RWBISHOP || tempCoinId == WQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == WKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}
	
		i=1;
		/*Check condition for diagonal top left from king*/
		while (curKingY - i >= 0 && curKingX - i >= 0) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY- i][curKingX- i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LWBISHOP || tempCoinId == RWBISHOP || tempCoinId == WQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == WKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}
	
		i=1;
		/*Check condition for diagonal bottom right from king*/
		while (curKingY + i < 8 && curKingX + i < 8) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY + i][curKingX + i].getCoinId();
			
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LWBISHOP || tempCoinId == RWBISHOP || tempCoinId == WQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId == WKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId >= WPAWN1 && tempCoinId <= WPAWN8 && i == 1) {
				/*Adjacent square contains opposite pawn*/ 
				tempMove.undoBoard(t);
				return 0;
			
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}
	
		i=1;
		/*Check condition for diagonal bottom left from king*/
		while (curKingY + i < 8 && curKingX - i >= 0) {

			/*storing coin id of the element square in a temp variable*/
			int 	tempCoinId = board[curKingY + i][curKingX - i].getCoinId();		
					
			if (tempCoinId == EMPTY) {
				/*Square is empty*/			
				i++;
				continue;
			} else if (tempCoinId == LWBISHOP || tempCoinId == RWBISHOP || tempCoinId == WQUEEN) {
				/*Square contains attackable elements*/
				tempMove.undoBoard(t);		
				return 0;
			} else if (tempCoinId == WKING && i == 1) {
				/*Adjacent square contains opposite king*/
				tempMove.undoBoard(t);
				return 0;
			} else if (tempCoinId >= WPAWN1 && tempCoinId <= WPAWN8 && i == 1) {
				/*Adjacent square contains opposite pawn*/ 
				tempMove.undoBoard(t);
				return 0;
			} else {
				/*Square contains friendly coin or non-attacking opponent coins*/  
				break;
			}			
		}

		/* Block for Checking  for 8 horse positions */
		{
			if (curKingX + 1 < 8 && curKingY + 2 < 8) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY + 2][curKingX + 1].getCoinId();		
				
				if (tempCoinId == LWKNIGHT || tempCoinId == RWKNIGHT) {
					tempMove.undoBoard(t);	 				
					return 0;
				}
			}	
	        
			if (curKingX + 2 < 8 && curKingY + 1 < 8) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY + 1][curKingX + 2].getCoinId();		
				
				if (tempCoinId == LWKNIGHT || tempCoinId == RWKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	        
			if (curKingX - 1 >= 0 && curKingY - 2 >= 0) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY - 2][curKingX - 1].getCoinId();		
				
				if (tempCoinId == LWKNIGHT || tempCoinId == RWKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	        
			if (curKingX - 2 >= 0 && curKingY - 1 >= 0) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY-1][curKingX - 2].getCoinId();		
				
				if (tempCoinId == LWKNIGHT || tempCoinId == RWKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	        
			if (curKingX + 1 < 8 && curKingY - 2 >= 0) {
				
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY- 2][curKingX +1].getCoinId();		
				
				if (tempCoinId == LWKNIGHT || tempCoinId == RWKNIGHT) {
					tempMove.undoBoard(t);
 					return 0;
				}
			}	
  	      
			if (curKingX - 1 >= 0 && curKingY + 2 < 8) {
			
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY+ 2][curKingX-1].getCoinId();		
				
				if (tempCoinId == LWKNIGHT || tempCoinId == RWKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	
	        if (curKingX + 2 < 8 && curKingY - 1 >= 0) {
			
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY-1][curKingX+2].getCoinId();		
				
				if (tempCoinId == LWKNIGHT || tempCoinId == RWKNIGHT) {
					tempMove.undoBoard(t);
		 			return 0;
				}
			}	
        
			if (curKingX - 2 >= 0 && curKingY + 1 < 8) {
			
				/*storing coin id of the element square in a temp variable*/
				int 	tempCoinId = board[curKingY+1][curKingX - 2].getCoinId();		
				
				if (tempCoinId == LWKNIGHT || tempCoinId == RWKNIGHT) {
					tempMove.undoBoard(t);
	 				return 0;
				}
			}	
	    }
	}	
	
	/*If program reaches here it means there is no attack from any side*/
	tempMove.undoBoard(t);
	return 1;
}
