#include<iostream>
#include<fstream>
#include<cstring>
#include "ezwin.h"
#include "bitmap.h"
#include "assert.h"
#include "rect.h"
#include "Graphic.h"

using namespace std;

#include "class_decln_compiled.cpp"

void picMove(int, int, int, int);
void coinSelect(int,int,int,int);
void coinDeselect(int,int,int,int);
int ReceiveMouseClick(const Position&);


int ApiMain() {

	Main.Open();
	assert(Main.GetStatus() == WindowOpen);


	for(int j=0;j<8;j++) {
		for(int i=0;i<8;i++) {
			pic[j][i].SetWindow(Main);
			pic[j][i].SetPosition(Position(i*1.5+1.0,j*1.5+1.0));
		}
	}

	FILE *fp = fopen("input.txt","r");
	

	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			fscanf(fp,"%s\n",picName[i][j]);
			
		}
	}


	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			pic[i][j].Load(picName[i][j]);
			assert(pic[i][j].GetStatus() ==  BitMapOkay);
			pic[i][j].Draw();

		}
	}
	
	initialize();
	Main.SetMouseClickCallback(ReceiveMouseClick);
	return 0;
}

int ReceiveMouseClick(const Position &p) {
	
	int i=0,j=0;
	float x=0.0,y=0.0;
	x=p.GetXDistance();
	y=p.GetYDistance();
	i=(x-1.0)/1.5;
	j=(y-1.0)/1.5;
	

	if(x>1.5*i+1.0 && x<1.5*i+2.5&&y>1.5*j+1.0 && y<1.5*j+2.5) {
			if(mode==0) {
				coinSelect(oldI,oldJ,i,j);
				oldI=i;
				oldJ=j;
				mode = 1;

			} else if(mode==1 && oldJ==j && oldI==i) {
				
				
				coinDeselect(oldI,oldJ,i,j);
				oldI=8;
				oldJ=8;
				mode = 0;

			}else if(mode==1) {
		
				int coinId = board[i][j].getCoinId();
				Pos tempInitPos, tempFinalPos;
			
				tempInitPos.setXY(oldI,oldJ);
				tempFinalPos.setXY(i,j);
			
				int MoveId = currentMove.initializeMove(tempInitPos,tempFinalPos);
				
				switch (MoveId) {
					case 0: picMove(oldI,oldJ,i,j);
							oldJ=8;
							oldI=8;
							mode=0;
							break;
					
					case 1: picMove(oldI,oldJ,i,j);
							oldJ=8;
							oldI=8;
							mode=0;
							break;
				
					case 2: 
							//Pic movement for King
							picMove(oldI,oldJ,i,j);
							
							//pic Movement for Rook
							picMove(oldI+3,oldJ,i+1,j);
							
							oldJ=8;
							oldI=8;
							mode=0;
							break;
							
					case 3: 
							//Pic movement for King
							picMove(oldI,oldJ,i,j);
							
							//pic Movement for Rook
							picMove(oldI-4,oldJ,oldI-1,oldJ);
							
							oldJ=8;
							oldI=8;
							mode=0;
							break;
			
					case 4: picMove(oldI,oldJ,i,j);
							oldJ=8;
							oldI=8;
							mode=0;
							break;
							//Pawn removing taken care by coinReplace
					case 5: 
							//Pawn promotion purely taken care by coinReplace
							oldI =8;
							oldJ =8;
							mode =0;
							break;
					
					case -1: coinDeselect(i,j,oldI,oldJ);
							oldI =8;
							oldJ=8;
							mode =0;
							break;
					//RenderText saying invalid Move 
				}
			}
	}
	return 0;
}

void picMove(int oldI, int oldJ, int i, int j) {
	BitMap *tempold = new BitMap();						
	BitMap *tempnew = new BitMap();
	tempold->SetWindow(Main);
	tempnew->SetWindow(Main);
			
	strcpy(picName[j][i],picName[oldJ][oldI]);
	if((oldJ+oldI)%2==0) {
		strcpy(picName[oldJ][oldI],"nbee.xpm");
	} else {
		strcpy(picName[oldJ][oldI],"nwee.xpm");
	}
		
	picName[j][i][0]='n';
	if((j+i)%2==0) {
		picName[j][i][1]='b';
	} else {
		picName[j][i][1]='w';
	}
		
	tempold->SetPosition(Position(oldI*1.5+1.0,oldJ*1.5+1.0));
	tempnew->SetPosition(Position(i*1.5+1.0,j*1.5+1.0));
		
	tempold->Load(picName[oldJ][oldI]);
	tempnew->Load(picName[j][i]);
		
	assert(tempold->GetStatus()==BitMapOkay);
	assert(tempnew->GetStatus()==BitMapOkay);
		
	pic[oldJ][oldI]=*tempold;
	pic[j][i]=*tempnew;
		
	pic[oldJ][oldI].Draw();
	pic[j][i].Draw();
				
	delete tempold;
	delete tempnew;	
							
}

void  coinReplace(int tempX, int tempY, int replaceCoinId,int colour) {
	
	//int tempX, tempY;
	
	BitMap *temp = new BitMap();
	
	temp->SetWindow(Main);
	temp->SetPosition(Position(tempX*1.5 + 1.0, tempY*1.5 + 1.0));
	
	picName[tempX][tempY][0] = 'n';
		
	if(((tempX + tempY)%2)==0) {
		picName[tempX][tempY][1] = 'b';
	} else {
		picName[tempX][tempY][1] = 'w';
	}
	
	if(colour ==0 ) {
		picName[tempX][tempY][2] = 'b';
		switch (replaceCoinId) {
				case LBROOK : 	picName[tempX][tempY][3] = 'r';
								break;
				case LBKNIGHT : picName[tempX][tempY][3] = 'n';
								break;
				case LBBISHOP : picName[tempX][tempY][3] = 'b';
								break;
				case BQUEEN  : 	picName[tempX][tempY][4] = 'q';
								break;
		}
	} else if(colour == 1) {
		picName[tempX][tempY][2] = 'w';
		switch (replaceCoinId) {
				case LWROOK : 	picName[tempX][tempY][3] = 'r';
								break;
				case LWKNIGHT : picName[tempX][tempY][3] = 'n';
								break;
				case LWBISHOP : picName[tempX][tempY][3] = 'b';
								break;
				case WQUEEN : 	picName[tempX][tempY][4] = 'q';
								break;
		}
	} else if(colour ==-1) {
		picName[tempX][tempY][2] = 'e';
		picName[tempX][tempY][3] = 'e';
	}

	temp->Load(picName[tempX][tempY]);
	pic[tempX][tempY] = *temp;
	pic[tempX][tempY].Draw();
	delete temp;
}

void coinSelect(int oldI,int oldJ, int i, int j) {			
				BitMap *temp= new BitMap();
				temp->SetWindow(Main);
				temp->SetPosition(pic[j][i].GetPosition());
				picName[j][i][0]='y';
				
				temp->Load(picName[j][i]);
				assert(temp->GetStatus()==BitMapOkay);

				pic[j][i]=*temp;

				pic[j][i].Draw();

				delete temp;
}

void coinDeselect(int oldI, int OldJ, int i, int j) {
				BitMap *temp= new BitMap();
				temp->SetWindow(Main);
				temp->SetPosition(pic[j][i].GetPosition());
				picName[j][i][0]='n';
				temp->Load(picName[j][i]);
				
				assert(temp->GetStatus()==BitMapOkay);
				pic[j][i]=*temp;
				pic[j][i].Draw();

				delete temp;
}	
