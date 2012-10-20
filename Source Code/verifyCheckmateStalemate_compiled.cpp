/*
*Specifications:
*Created in gedit.exe
*Tab Width     : 4
*Font          : Monospace Normal 12
*Lines of code : 77
*/


/*
*Checking whether Checkmate or Stalemate or neither of the two.
*@version : 1.0.0.  29/10/2011
*@author  : Hardik Kothari
*/


/*The following function checks and returns 1 for Checkmate , 0 for Stalemate and -1 for neither Checkmate nor Stalemate.*/ 

//#include "class_decln_compiled.cpp"

int verify_Checkmate_Stalemate()  {
    
    int i;
    int Range=0;                                                         
    int check;
	Movement dummy;


    /*If the moving coin is white.*/
    if(currentMove.coinId>=16 && currentMove.coinId<32)  {
        /*Checking range for all black coins.*/             
        for(i=LBROOK;i<=BPAWN8;i++)  {
            Range=allCoins[i].getNRange();
            /*If range of any of the coin is not 0 , then neither checkmate nor stalemate .*/
            if(Range!=0 && allCoins[i].returnMode()!=0) {
                
                return -1;
            }
        }
		
		dummy.setInitPos(allCoins[BKING].returnCurPos());
		dummy.coinId=BKING;
		dummy.captureCoinId=BKING;
		dummy.setFinalPos(allCoins[BKING].returnCurPos());
        /*Verifying whether check or not.*/  
        check=allCoins[BKING].verifyCheck(dummy);
        cout<<"verifyCheck returned :"<<check<<endl;
        /*If Checkmate return 1 or return 0 for Stalemate.*/
        if(check==0)  {
            return 1;
        } else {
          return 0;
          }                                
    }
    
    /*If the moving coin is black.*/
    if(currentMove.coinId>=0 && currentMove.coinId<=15)  {
        /*Checking range for all white coins.*/             
        for(i=WPAWN1;i<=RWROOK;i++)  {
            Range=allCoins[i].getNRange();
            /*If range of any of the coin is not 0 , then neither checkmate nor stalemate .*/
            if(Range!=0 && allCoins[i].returnMode()!=0) {
                
                return -1;
            }
        }
		dummy.setInitPos(allCoins[WKING].returnCurPos());
		dummy.coinId=WKING;
		dummy.captureCoinId=WKING;
		dummy.setFinalPos(allCoins[WKING].returnCurPos());
        /*Verifying whether check or not.*/  
        check=allCoins[WKING].verifyCheck(dummy);
        cout<<"verifyCheck returned :"<<check<<endl;
        
        /*If Checkmate return 1 or return 0 for Stalemate.*/
        if(check==0)  {
            return 1;
        } else {
          return 0;
         }         
    }
}
    
    
    
        
        
        
