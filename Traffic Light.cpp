/* --------------------------  Traffic Light Checker  -------------- */
/* ---------------------- Author : Jafar Mesgarian ------------------*/
/* ------------------- Presented to : HIRSCH Maschinenbau -----------*/
/* --------------------- Software Version : Dev-C++ 5.11 ------------*/
/* ------------------------   Date : 2022/Nov/08 --------------------*/
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
string SEQ = "";
int SEQL;
string Evaluation = "A C C E P T";
bool EvaBool = true;
int main()
{
	getline(cin, SEQ);			/* Import the Sequence from the CIN */
	SEQL = SEQ.length();		/*Length of the Sequence*/
/*--------------   Delete The Spaces between Charachters and rebiuld the SEQ------------------------------*/
	for (int i=1;i<=SEQL/2;++i)
	{
		SEQ[i] = SEQ [2*i];
		SEQ[2*i] = ' ';
	}
	SEQL = ceil(SEQL/2+1);
/*	cout << SEQ << endl;*/
/*   cout << "LEN =" << SEQL << endl; */
/*-------------------  Rule No.1 : Check the Valid Charachters in the Input ------------------------------*/
	for (int i=0; i<SEQL;++i)
	{
		if (SEQ[i] != 'R' and SEQ[i] != 'G' and SEQ[i] != 'Y' and SEQ[i] != 'X' and SEQ[i] != 'C' and SEQ [i] != 'P')
		{
		Evaluation = "\nR E J E C T (Rule No.1)";	
		EvaBool = false;
		}
	}
/*-------------------  Rule No.2 : The Sequence doesn't start with "R" ----------------------------------- */
	if ((SEQ[0] != 'R' ) and EvaBool)
	{
		Evaluation = "\nR E J E C T (Rule No.2)";
		EvaBool = false;
	}	
	
/* ------------------Rule No.3 : No color may be repeated   --------- ----------------------------------- */	
	if (EvaBool)
	{
		for (int i=0; i<SEQL;++i) 
		{	
			if (SEQ[i] == SEQ[i+1])
			{		
			Evaluation = "\nR E J E C T (Rule No.3)";	
			EvaBool = false;
			}
		}	
	}
/* ------------------ Rule No.4 : Sequence must be ended with 'R' or 'P'    ------------------------------*/
	if (SEQ[SEQL-1] != 'R' and SEQ[SEQL-1] != 'P' and EvaBool)
	{
		Evaluation = "\nR E J E C T (Rule No.4)";
		EvaBool = false;
	}
/*------------------ Rule No.5 : a "G" must be showed after "R" ------------------------------------------*/
	if (EvaBool)
	{
		for (int i=1; i<SEQL;++i)
		{
			if ((SEQ[i] == 'G') and (SEQ[i-1] != 'R'))
			{
			Evaluation = "\nR E J E C T (Rule No.5)";	
			EvaBool = false;
			}
		}
	}
/*------------------ Rule No.6 :  flash sequence may only be started after the red light-----------------*/
	if (EvaBool)
	{
		for (int i=1; i<SEQL;++i)
		{
			if ( ((SEQ[i] == 'P') or (SEQ[i] == 'C')) and (SEQ[i-1] != 'R') and (SEQ[i+1] != 'R'))
			{
			Evaluation = "\nR E J E C T (Rule No.6)";	
			EvaBool = false;
			}
		}
	}

		
/* ------------------ END : Print out the Evaluation ----------------------------------------------------*/

	cout << Evaluation << endl;
	

}

