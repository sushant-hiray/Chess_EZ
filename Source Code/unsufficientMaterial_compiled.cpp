	/* 
	Code for Insufficient Material
	*
	tabwidth 4	

	*Game Draw __insufficient material
	* version 1.0.0.0
	*author --- Himanshu Roy
	* 
	*/

	//# include "class_decln_compiled.cpp"
	
	int insufficientmaterial()
	{
		
		
	int j=0,k=0,k1=0,j1=0,i=0;
		
		
		
		for(i = 0; i<16 ;i++)
		{
			
			if(i!=4 && allCoins[i].returnMode() == 0)
			{
				
				j++;
				
			}
			
			if(i=2||i==3||i==7||i==6&&allCoins[i].returnMode()!=0){j1++;}

		}
		
		for(i = 16; i < 32; i++)
		{
			if(i!=28 && allCoins[i].returnMode() == 0)
			{
				
				
				k++;
			}
			
			if(i=30||i==29||i==25||i==25&&allCoins[i].returnMode()!=0){k1++;}
		}
		
		
		
		if(j==15&&k==14&&k1==1)
		{
			return 1;
		}
		
		if(j==14 && k==15 && j1==1)
		{
			return 1;
		}
		
		else
		{
			return 0;
		}
		
		
	}
		
									
			
			
  
