#include<iostream>
#include<fstream>
#include<cstring>
#include "ezwin.h"
#include "bitmap.h"
#include "assert.h"
#include "rect.h"
#include "Graphic.h"
#include "unistd.h"
#include<cmath>

using namespace std;

#include "class_decln_compiled.cpp"
#include "Constants.h"
void picMove(int, int, int, int);
void coinSelect(int,int,int,int);
void coinDeselect(int,int,int,int);
int ReceiveMouseClick(const Position&);
int ReceiveMouseClick2(const Position &p);
void coinHighlight(int,int);
void displayDock();
void displayNumbers();
void displayMove();

int replaceColour = 0;
int modeReplace = 0;
int player = 1;
void RenderMessage(char str[]);

#define STARTX 8.5 
#define STARTY 2.0
#define TITLEX 8.8
#define TITLEY 0.0
#define DOCKBX1 0.25
#define DOCKBY1 2.0
#define DOCKBX2 7.5
#define DOCKBY2 9.25
#define DOCKWX1 21.5 
#define DOCKWY1 2.0
#define DOCKWX2 28.75
#define DOCKWY2 9.25
#define SIZE 1.51


int ApiMain() {
	Main.Open();
	assert(Main.GetStatus() == WindowOpen);
	
	Main.RenderLine(Position(STARTX-0.05,STARTY-0.05),Position(STARTX-0.05,STARTY+12.15),Black,0.06);
	Main.RenderLine(Position(STARTX-0.05,STARTY-0.05),Position(STARTX+12.15,STARTY-0.05),Black,0.06);
	Main.RenderLine(Position(STARTX+12.15,STARTY-0.05),Position(STARTX+12.15,STARTY+12.15),Black,0.06);
	Main.RenderLine(Position(STARTX-0.05,STARTY+12.15),Position(STARTX+12.15,STARTY+12.15),Black,0.06);
	//Main.RenderRectangle(Position(4.0,STARTY+13.0),Position(30.0,STARTY+13.75),Black,0.06);
	Main.RenderLine(Position(0.0,14.54),Position(30.0,14.54),Black,0.06);
	RenderMessage("Message Bar");
	displayNumbers();
	Main.RenderLine(Position(25.0,14.52),Position(25.0,15.5),Black,0.06);
	Main.RenderText(Position(26.0,14.75),"Moves :",Black,White);
	displayDock();
	for(int y=0;y<8;y++) {
		for(int x=0;x<8;x++) {
			pic[y][x].SetWindow(Main);
			pic[y][x].SetPosition(Position(x*SIZE+STARTX,y*SIZE+STARTY));
		}
	}

	FILE *fp = fopen("input.txt","r");
	

	for(int y=0;y<8;y++) {
		for(int x=0;x<8;x++) {
			fscanf(fp,"%s\n",picName[y][x]);
			
		}
	}


	for(int y=0;y<8;y++) {
		for(int x=0;x<8;x++) {
			pic[y][x].Load(picName[y][x]);
			assert(pic[y][x].GetStatus() ==  BitMapOkay);
			
		}
	}
	
	BitMap border(Main);
	border.SetPosition(Position(STARTX+2.25,0.0));
	border.Load("hc.xpm");
	assert(border.GetStatus()==BitMapOkay);
	border.Draw();
	
	for(int y=0;y<8;y++) {
		for(int x=0;x<8;x++) {
			pic[y][x].Draw();
		}
	}
	//Border.Draw();
	
	BitMap Black(Main);
	Black.SetPosition(Position(DOCKBX1+2.25,DOCKBY1-1.5));
	Black.Load("black.xpm");
	assert(Black.GetStatus()==BitMapOkay);
	Black.Draw();
	
	BitMap White(Main);
	White.SetPosition(Position(DOCKWX1+2.25,DOCKWY1-1.5));
	White.Load("white.xpm");
	assert(White.GetStatus()==BitMapOkay);
	White.Draw();
	
	
	BitMap Quit(Main);
	Quit.SetPosition(Position(DOCKWX1+2.25,DOCKWY2+1.0));
	Quit.Load("quit.xpm");
	assert(Quit.GetStatus()==BitMapOkay);
	Quit.Draw();
	
	BitMap claimDraw(Main);
	claimDraw.SetPosition(Position(DOCKWX1+1.25,DOCKWY2+3.0));
	claimDraw.Load("claimdraw.xpm");
	assert(claimDraw.GetStatus()==BitMapOkay);
	claimDraw.Draw();
	
	BitMap resign(Main);
	resign.SetPosition(Position(DOCKWX1+2.0,DOCKWY2+2.0));
	resign.Load("resign.xpm");
	assert(resign.GetStatus()==BitMapOkay);
	resign.Draw();
	
	initialize();
	
	
	
	
	Main.SetMouseClickCallback(ReceiveMouseClick);
	return 0;
}

int ReceiveMouseClick(const Position &p) {
	
	int x=0,y=0,i=0;
	float X=0.0,Y=0.0;
	X=p.GetXDistance();
	Y=p.GetYDistance();
	x=(X-STARTX)/SIZE;
	y=(Y-STARTY)/SIZE;
	int nRange=0;
	if(X > DOCKWX1+2.25 && X<DOCKWX1+4.75 && Y>DOCKWY2+1.0 && Y<DOCKWY2 + 2.0) {
		Main.Close();
	} else  if (X > DOCKWX1+1.75 && X< DOCKWX1+5.25 && Y>DOCKWY2+2.0 && Y<DOCKWY2 + 3.0) {
		Main.Message("Player Resigned");
		Main.Close();
	} else if(X > DOCKWX1+1.25 && X<DOCKWX1+5.75 && Y>DOCKWY2+3.0 && Y<DOCKWY2 + 4.0) {
		Main.Message("Player Claimed Draw");
		Main.Close();
	} else if(X>SIZE*x+STARTX && X<(SIZE*x+STARTX+SIZE)&&Y >SIZE*y+STARTY && Y< (SIZE*y+STARTY+SIZE)) {
		{
			if(mode==0) { 
				
					
				int coinIndex = board[y][x].getCoinIndex();
				if(((nHistoryOfMoves%2==0 && coinIndex>=16 && coinIndex<32)||(nHistoryOfMoves%2==1 && coinIndex>=0 && coinIndex<16))) {
				
				if(coinIndex!=-1) {
				coinSelect(oldX,oldY,x,y);
				for(int i=0;i<allCoins[coinIndex].getNRange();i++) {
					int tempX,tempY;
					allCoins[coinIndex].coinRange[i].getXY(tempX,tempY);
					coinHighlight(tempX,tempY);
				}
				oldX=x;
				oldY=y;
				mode = 1;
				nRange = allCoins[coinIndex].getNRange();
				}
			}
			} else if(mode==1 && oldY==y && oldX==x) {
				
				int coinIndex = board[y][x].getCoinIndex();
				coinDeselect(oldX,oldY,x,y);
				for(int i=0;i<allCoins[coinIndex].getNRange();i++) {
					int tempX,tempY;
					allCoins[coinIndex].coinRange[i].getXY(tempX,tempY);
					coinDeselect(oldX,oldY,tempX,tempY);
				}
				oldX=8;
				oldY=8;
				mode = 0;
				

			}else if(mode==1) {
		
				int coinIndex = board[oldY][oldX].getCoinIndex();
				
				Pos tempInitPos, tempFinalPos;
			
				tempInitPos.setXY(oldX,oldY);
				tempFinalPos.setXY(x,y);
				
				currentMove.initializeMove(tempInitPos,tempFinalPos);
				
				//cout<<"\nReturned Value is:"<<retValue;
				switch (retValue) {
					case 0: 
							picMove(oldX,oldY,x,y);
							oldX=8;
							oldY=8;
							mode=0;
							break;
					
					case 1: picMove(oldX,oldY,x,y);
							oldX=8;
							oldY=8;
							mode=0;
							break;
				
					case 2: 
							//Pic movement for King
							picMove(oldX,oldY,x,y);
							
							//pic Movement for Rook
							picMove(oldX+3,oldY,oldX+1,oldY);
							
							oldX=8;
							oldY=8;
							mode=0;
							break;
							
					case 3: 
							//Pic movement for King
							picMove(oldX,oldY,x,y);
							
							//pic Movement for Rook
							picMove(oldX-4,oldY,x+1,y);
							
							oldX=8;
							oldY=8;
							mode=0;
							break;
			
					case 4: picMove(oldX,oldY,x,y);
							
							oldX=8;
							oldY=8;
							mode=0;
							break;
						
					case 5: 
							//Pawn promotion purely taken care by coinReplace
							oldX =8;
							oldY =8;
							mode =0;
							break;
					
					case -1: coinDeselect(x,y,oldX,oldY);
							oldX =8;
							oldY=8;
							mode =0;
							break;
					//RenderText saying invalid Move 
					
				}
			//cout<<"the received coinIndex is: "<<coinIndex;
			//cout<<"\nThe number of squares to be deselected is: "<<allCoins[coinIndex].getNRange();
			for(int i=0;i<allCoins[coinIndex].getNRange();i++) {
					int tempX,tempY;
					allCoins[coinIndex].coinRange[i].getXY(tempX,tempY);
					coinDeselect(oldX,oldY,tempX,tempY);
			}
			
			displayMove();
			updateRange();
			int a =verify_Checkmate_Stalemate();
			if(a==1) {
				//cout<<"Checkmate"<<endl;
				Main.Message("Checkmate!!");
			} else if(a==0) {
				//cout<<"StaleMate"<<endl;
				Main.Message("Stalemate!!");
			} 
			//cout<<"\nverify_checkmate_stalemate returned: "<<a;
			
			//cout<<"\nCurrent Board State :"<<endl;
			displayBoardState();
			//cout<<"Ranges of all coins by coinId :"<<endl;
			displayRange();
			
			player=nHistoryOfMoves%2;
			}
		
		}
	}
	return 0;
}

void picMove(int oldX, int oldY, int x, int y) {
	BitMap *tempold = new BitMap();						
	BitMap *tempnew = new BitMap();
	
	tempold->SetWindow(Main);
	tempnew->SetWindow(Main);
			
	strcpy(picName[y][x],picName[oldY][oldX]);
	
	if((oldY+oldX)%2==0) {
		strcpy(picName[oldY][oldX],"nwee.xpm");
	} else {
		strcpy(picName[oldY][oldX],"nbee.xpm");
	}
		
	picName[y][x][0]='n';
	
	if((x+y)%2==0) {
		picName[y][x][1]='w';
	} else {
		picName[y][x][1]='b';
	}
		
	tempold->SetPosition(Position(oldX*SIZE+STARTX,oldY*SIZE+STARTY));
	tempnew->SetPosition(Position(x*SIZE+STARTX,y*SIZE+STARTY));
		
	tempold->Load(picName[oldY][oldX]);
	tempnew->Load(picName[y][x]);
		
	assert(tempold->GetStatus()==BitMapOkay);
	assert(tempnew->GetStatus()==BitMapOkay);
		
	pic[oldY][oldX]=*tempold;
	pic[y][x]=*tempnew;
		
	pic[oldY][oldX].Draw();
	pic[y][x].Draw();
				
	delete tempold;
	delete tempnew;	
							
}

void  coinReplace(int tempX, int tempY, int replaceCoinId,int colour) {
	
	BitMap *temp = new BitMap();
	
	temp->SetWindow(Main);
	temp->SetPosition(Position(tempX*SIZE + STARTX, tempY*SIZE + STARTY));
	
	picName[tempY][tempX][0] = 'n';
		
	//cout<<"received replaceCoinId is:"<<replaceCoinId<<endl;
	
	if(((tempX + tempY)%2)==0) {
		picName[tempY][tempX][1] = 'w';
	} else {
		picName[tempY][tempX][1] = 'b';
	}
	
	if(colour ==0 ) {
		picName[tempY][tempX][2] = 'b';
		switch (replaceCoinId) {
				case LBROOK : 	picName[tempY][tempX][3] = 'r';
								break;
				case LBKNIGHT : picName[tempY][tempX][3] = 'n';
								break;
				case LBBISHOP : picName[tempY][tempX][3] = 'b';
								break;
				case BQUEEN  : 	picName[tempY][tempX][3] = 'q';
								break;
		}
	} else if(colour == 1) {
		picName[tempY][tempX][2] = 'w';
		switch (replaceCoinId) {
				case LWROOK : 	picName[tempY][tempX][3] = 'r';
								break;
				case LWKNIGHT : picName[tempY][tempX][3] = 'n';
								break;
				case LWBISHOP : picName[tempY][tempX][3] = 'b';
								break;
				case WQUEEN : 	picName[tempY][tempX][3] = 'q';
								break;
		}
	} else if(replaceCoinId ==EMPTY) {
		picName[tempY][tempX][2] = 'e';
		picName[tempY][tempX][3] = 'e';
	}
	
	//cout<<"Loading :"<<picName[tempY][tempX]<<" onto "<<tempX<<tempY<<endl;
	temp->Load(picName[tempY][tempX]);
	pic[tempY][tempX] = *temp;
	pic[tempY][tempX].Draw();
	delete temp;
}

void coinSelect(int oldX,int oldY, int x, int y) {			
				BitMap *temp= new BitMap();
				temp->SetWindow(Main);
				temp->SetPosition(pic[y][x].GetPosition());
				picName[y][x][0]='y';
				
				temp->Load(picName[y][x]);
				assert(temp->GetStatus()==BitMapOkay);

				pic[y][x]=*temp;

				pic[y][x].Draw();

				delete temp;
}

void coinHighlight(int x, int y) {			
				BitMap *temp= new BitMap();
				temp->SetWindow(Main);
				temp->SetPosition(pic[y][x].GetPosition());
				picName[y][x][0]='h';
				
				temp->Load(picName[y][x]);
				//cout<<"Loaded :"<<picName[y][x]<<endl;
				assert(temp->GetStatus()==BitMapOkay);

				pic[y][x]=*temp;

				pic[y][x].Draw();

				delete temp;
}

void coinDeselect(int oldX, int oldY, int x, int y) {
				BitMap *temp= new BitMap();
				temp->SetWindow(Main);
				temp->SetPosition(pic[y][x].GetPosition());
				picName[y][x][0]='n';
				temp->Load(picName[y][x]);
				
				assert(temp->GetStatus()==BitMapOkay);
				pic[y][x]=*temp;
				pic[y][x].Draw();

				delete temp;
}	

/*int displayDialog(int colour) {
	
	replaceCoinId=-1;
	PP.Open();
	assert(PP.GetStatus()==WindowOpen);
	globalColor= colour;
	
	BitMap coins[4];
	for(int i=0;i<4;i++) {
		coins[i].SetWindow(PP);
		coins[i].SetPosition(Position(i*SIZE+0.5 ,1.0));
	}
		
	if(colour==0) {
		coins[0].Load("nwbb.xpm");
		coins[1].Load("nwbn.xpm");
		coins[2].Load("nwbr.xpm");
		coins[3].Load("nwbq.xpm");
		
	} else if(colour==1) {
		coins[0].Load("nwwb.xpm");
		coins[1].Load("nwwn.xpm");
		coins[2].Load("nwwr.xpm");
		coins[3].Load("nwwq.xpm");
	}
	
	for(int i=0;i<4;i++) {
		assert(coins[i].GetStatus()==BitMapOkay);
		coins[i].Draw();
	}
	
	
	
	PP.SetMouseClickCallback(ReceiveMouseClick2);
	
	
	PP.Close();
	return replaceCoinId;
}*/	

int ReceiveMouseClick2(const Position &p) {
	A:
	int x=p.GetXDistance();
	int y=p.GetYDistance();
	int i;
	if(modeReplace==0) {
		if(replaceColour == 0) {
				i=(x-DOCKBX1)/SIZE;
				if(i>=0 && i<4) {
					switch(i) {
						case 0: replaceCoinId = LBBISHOP;
								break;
						case 1: replaceCoinId = LBKNIGHT;
								break;
						case 2: replaceCoinId = LBROOK;
								break;
						case 3: replaceCoinId = BQUEEN;
								break;
					}
				} else {
					goto A;
				}
		} else {
				i=(x-DOCKWX1)/SIZE;
				if(i>=2 && i<4) {
					switch(i) {
						case 0: replaceCoinId = LWBISHOP;
								break;
						case 1: replaceCoinId = LWKNIGHT;
								break;
						case 2: replaceCoinId = LWROOK;
								break;
						case 3: replaceCoinId = WQUEEN;
								break;
					} 
				} else {
					goto A;
				}
		}
	} else {
		replaceCoinId = -1;
			if(modeReplace==1) {
				if(replaceColour == 0) {
					i=(x-DOCKBX1)/SIZE;
					if(i>=0 && i<4) {
						switch(i) {
							case 1: replaceCoinId = LBKNIGHT;
									break;
							case 2: replaceCoinId = BQUEEN;
									break;
						}
					} else {
						goto A;
					}
				} else {
					i=(x-DOCKWX1)/SIZE;
					if(i>=2 && i<4) {
						switch(i) {
							case 1: replaceCoinId = LWKNIGHT;
									break;
							case 2: replaceCoinId = WQUEEN;
									break;
						} 
					}else {
						goto A;
					}
				}
			}
		}
	//cout<<"replaceCoinId is set at "<<replaceCoinId<<endl;
	return 0;
}


void displayDock() {
	Main.RenderRectangle(Position(DOCKWX1,DOCKWY1),Position(DOCKWX2,DOCKWY2),Black,False);
	Main.RenderRectangle(Position(DOCKBX1,DOCKBY1),Position(DOCKBX2,DOCKBY2),White,True);
}		
		
void displayInDock(int coinId) {
	BitMap *temp = new BitMap();
	temp->SetWindow(Main);
	char name[8];
	
	if(coinId >=0 && coinId <16) {
		temp->SetPosition(Position(DOCKBX1 +(blackOut%4)*1.75+0.25, DOCKBY1 + (int)(blackOut/4)*1.75+0.25));
		name[0] = 'w';
		name[1] = 'w';
		name[2] = 'b';
		if(coinId==LBROOK || coinId==RBROOK) {
			name[3] = 'r';
		} else if (coinId == LBKNIGHT || coinId ==RBKNIGHT) {
			name[3] = 'n';
		} else if (coinId == LBBISHOP || coinId == RBBISHOP) {
			name[3] = 'b';
		} else if(coinId == BQUEEN) {
			name[3] = 'q';
		} else if(coinId >=8) {
			name[3] = 'p';
		}
		blackOut++;
	} else if(coinId >=16 && coinId <32) {
		temp->SetPosition(Position(DOCKWX1 +(whiteOut%4)*1.75+0.25, DOCKWY1 + (int)(whiteOut/4)*1.75+0.25));
		name[0] = 'b';
		name[1] = 'b';
		name[2] = 'w';
		if(coinId==LWROOK || coinId==RWROOK) {
			name[3] = 'r';
		} else if (coinId == LWKNIGHT || coinId ==RWKNIGHT) {
			name[3] = 'n';
		} else if (coinId == LWBISHOP || coinId == RWBISHOP) {
			name[3] = 'b';
		} else if(coinId == WQUEEN) {
			name[3] = 'q';
		} else if (coinId <24) {
			name[3] = 'p';
		}
		whiteOut++;
	}
	name[4]='.';
	name[5]='x';
	name[6]='p';
	name[7]='m';
	//cout<<"name set to:"<<name;
	temp->Load(name);
	assert(temp->GetStatus()==BitMapOkay);
	temp->Draw();
	delete temp;
}

void displayMove() {
	char str[3];
	sprintf(str,"%d",nHistoryOfMoves);
	Main.RenderText(Position(27.0,14.75),str,Black,White);
}

void RenderMessage(char str[]) {
	
	Main.RenderRectangle(Position(2.25,14.65),Position(24.0,15.5),White,False);
	Main.RenderText(Position(12.5,14.75),str,Black,White);
}	

void displayNumbers() {
	char c='A';
	char s[2],t[2];
	for(int i=8;i>=1;i--,c++) {
		sprintf(s,"%d",i);
		sprintf(t,"%c",c);
		Main.RenderText(Position(STARTX-0.3,1.5*(8-i)+STARTY+0.75),s,Black,White);
		Main.RenderText(Position(STARTX+12.3,1.5*(8-i)+STARTY+0.75),s,Black,White);
		Main.RenderText(Position(STARTX + 0.75+1.5*(8-i),STARTY-0.3),t,Black,White);
		Main.RenderText(Position(STARTX + 0.75+1.5*(8-i),STARTY+12.3),t,Black,White);
	}
}

 void displayCoinReplace(int colour,int mode=0) {
	BitMap coins[4];
	char coinName[4][9];
	replaceColour=colour;
	modeReplace=mode;
	for(int i=0;i<4;i++) {
		coins[i].SetWindow(Main);
		if(colour==0) {
			coinName[i][0]='w';
			coinName[i][1]='w';
			coinName[i][2]='b';
			coins[i].SetPosition(Position(DOCKBX1+i*SIZE,DOCKBY2+ SIZE));
		} else {
			coinName[i][0]='b';
			coinName[i][1]='b';
			coinName[i][2]='w';
			coins[i].SetPosition(Position(DOCKBX1+i*SIZE,DOCKBY2+ SIZE));
		}
	}
		coinName[0][3]='r';
		coinName[1][3]='n';
		coinName[2][3]='q';
		coinName[3][3]='b';
		for(int i=0;i<4;i++) {
			coinName[i][4]='.';
			coinName[i][5]='x';
			coinName[i][6]='p';
			coinName[i][7]='m';
			coinName[i][8]='\0';
		}
		
		for(int i=0;i<4;i++) {
			coins[i].Load(coinName[i]);
			//cout<<"coins name loaded as:"<<coinName[i]<<endl;
		}
		
		if(mode==0) {
			for(int i=0;i<4;i++) {
				
				assert(coins[i].GetStatus()==BitMapOkay);
				coins[i].Draw();
			}
		} else if(mode==1) {
			for(int i=2;i<4;i++) {
				
				assert(coins[i].GetStatus()==BitMapOkay);
				coins[i].Draw();
			}
		}
		RenderMessage("Choose the piece for pawn promotion");
		Main.SetMouseClickCallback(ReceiveMouseClick);
}



		
		
