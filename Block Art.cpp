/* --------------------------  Block Art Problem  ------------------ */
/* ---------------------- Author : Jafar Mesgarian ------------------*/
/* ------------------- Presented to : HIRSCH Maschinenbau -----------*/
/* --------------------- Software Version : Dev-C++ 5.11 ------------*/
/* ------------------------   Date : 2022/Nov/08 -------------------*/
#include <iostream>
using namespace std;

int r;int c; 		/*  r = Number of Rows, c = Number of Columns*/
int n;				/* n = Number of input lines */
char Operator ;		/*Operator = Type of Operation on the Canvas*/
int R1,C1,R2,C2;	/* Begining and Ending of the Area of operation*/

int Canvas[20][20];
void InitCanvas();
void PrintCanvas();
int OperateCanvas();

int main()
{
	/* ---------------------------- Line 1 : Input Varibales r,c ---------------------------*/
	r=0;
	c=0;
	while ((r<1 or r>20) or (c<1 or c>20))
	{
		cin >> r >> c;
		if (r<1 or r>20) 
		{	
			cout << "The number of Rows must be between 1 , 20\n";
			cout << "Try again!\n";
		}
		if  (c<1 or c>20)
		{	
			cout << "The number of Columns must be between 1 , 20\n";
			cout << "Try again!\n";
		}
	}
	
	/*--------------------------- Line 2 : Input Varibale n  -----------------------------  */
	n = 0;
	cin >> n;
	while (( n<1) or (n>10000))
	{
		cout << "The number of Lines must be between 1 , 10000\n";
		cout << "Try again!\n";
		cin >>n;
	}
	
	InitCanvas ();
	/*	PrintCanvas();*/
	for (int i=1;i<=n;++i)
	{
		cin >> Operator >> R1 >> C1 >> R2 >> C2 ;
		if (R1<1 or R1>r or R2<1 or R2>r or C1<1 or C1>c or C2<1 or C2>c)
		{
			cout << "Invalid Canvas Range";
		}
		else if ((Operator!= 'a') and (Operator != 'r') and (Operator != 'q'))
		{
			cout << "Invalid Operator";
		}
		else 
		{
			OperateCanvas();
		}
		
	}
return (0);
}
/*----------------------------------------------------------------------------------------*/
void InitCanvas ()
{
	for (int i=1;i<=r;++i)
	{
		for (int j=1;j<=c;++j)
		{
			Canvas [i][j] = 0;
		}
	}
}
/*------------------------------------------------------------------------------------------*/
void PrintCanvas(void)
{
	for (int i=1;i<=r;++i)
	{
		for (int j=1;j<=c;++j)
		{
		cout << Canvas[i][j] << " ";
		}
		cout << "\n";
	}
}/* -----------------------------------------------------------------------------------------*/
int OperateCanvas()
{
	int Query;
	switch (Operator) 
	
	{
		case 'a': 			/* Adding a Layer on the Canvas */
			for (int i=R1;i<=R2;++i)
			{
				for (int j=C1;j<=C2;++j)
				{
				Canvas[i][j] += 1; 
				}
			}
		/*	PrintCanvas();*/
			break;
			
		case 'r':			/* Removing a Layer from Canvas */
			for (int i=R1;i<=R2;++i)
			{
				for (int j=C1;j<=C2;++j)
				{
				if (Canvas[i][j] > 0 ) { Canvas[i][j] -= 1;} 
				}
			}	
		/*	PrintCanvas();*/
			break;
			
		case 'q':			/*Query number of Layers on the Canvas*/
			Query = 0;
		for (int i=R1;i<=R2;++i)
			{
				for (int j=C1;j<=C2;++j)
				{
				Query += Canvas[i][j];
				}
			}	
		/*	PrintCanvas();*/
			cout << "\n" << Query;
			break;		
	}
	
}
