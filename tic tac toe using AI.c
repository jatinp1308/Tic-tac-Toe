#include<stdio.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
char a[3][3],w,r='f';
void grid();
void human();
void computer();
void rep();
void check();
void result();
int main()
{
int i,j;
for(i=0;i<3;i++)
{
 for(j=0;j<3;j++)
 {
  a[i][j]=' ';
  
 }
}

grid();
do
{	
 human();
 check();
 computer();
 check(); 
  grid();
 }while(r=='f'); 
 result();
 getch();
 return 0;
}
void result()
{
printf("\n\t\t\tGame Over\n\t\t\tPlayer %c has won",w);
}
void grid()
{
int i;
system("cls");
printf("\n\n\t\t      Tic tac toe AI vs human");
printf("\n\n");
printf("\t\t    Computer (X)  -  Player (O)\n\n");
printf("\t\t\t     0   1   2\n\n");
for(i=0;i<3;i++)
   {
   printf("\t\t\t%d    %c | %c | %c \n",i,a[i][0],a[i][1],a[i][2]);
   if(i<2)
    printf("\t\t\t    ---+---+---\n");
   }
   
}
void computer()
{
if(a[1][1]==' '||a[1][1]=='X')
	{
	
		if(a[1][1]==' ')
		{
			a[1][1]='X';
		}
		else if((a[2][2]==' ' || a[0][0]==' ')||(a[0][2]==' ' || a[2][0]==' '))
		{
			if(a[2][0]==' ' || a[0][2]==' ')
			{
				if(a[2][0]==' ')
				{
					a[2][0]='X';
				}
				else 
				{
					a[0][2]='X';
				}
			}
			else if(a[2][2]==' ' || a[0][0]==' ')
			{
				if(a[2][2]==' ')
				{
					a[2][2]='X';	
				}
				else 
				{
					a[0][0]='X';
				}
			}
			 
		}
	
      else
			{
				
				rep();
			}
	}
	
else if(a[0][2]==' ' || a[1][1]=='O')
	{

		if(a[0][2]==' ')
		{
			a[0][2]='X';
		}
		else if(a[2][2]==' '|| a[0][0]==' ')
		{
			if(a[2][2]==' ')
			{
				a[2][2]='X';
			}
			else
			{
				a[0][0]='X';
			}
		}
		else if(a[1][2]==' '|| a[0][1]==' ')
		{
			if(a[1][2]==' ')
			{
				a[1][2]='X';
			}
			else
			{
				a[0][1]='X';
			}
		
		}
		
		else
		{
			rep();
		}
	}
	
else
	{
		rep();
	}
}
void rep()
{
int x,y,i;

srand(time(NULL));
for(i=0;i<32767;i++)
{
x=rand()%3;
y=rand()%3;

}

if(a[x][y]==' ')
{
  a[x][y]='X';
  
}
else
{
	check();
 if(a[0][0]==' '||a[0][1]==' '||a[0][2]==' '||a[1][0]==' '||a[1][1]==' '||a[1][2]==' '||a[2][0]==' '||a[2][1]==' '||a[2][2]==' ')
 {
 	rep();
 }
 else
 {
 	check();
 }
 
}
}
void human()

{
int x,y;
printf("\n\t\t\tEnter Coordinates \n\t\t\tX: ");
scanf("%d",&x);
printf("\t\t\tY: ");
scanf("%d",&y);
if(a[x][y]==' ')
 a[x][y]='O';
else
 {
 grid();
 printf("\t\t\tInvalid Coordinates, Try again\n");
 human();
 }
}
void check()
{
int i;
for(i=0;i<3;i++)
   {
   if(a[i][0]==a[i][1]&&a[i][0]==a[i][2]&&(a[i][0]=='X'||a[i][0]=='O'))
       {
       w=a[i][0];
       r='t';
       break;
       }
   else if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]&&(a[0][i]=='X'||a[0][i]=='O'))
    {
    w=a[0][i];
    r='t';
    break;
    }
   }
if(r=='f')
 {
 if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&(a[0][0]=='X'||a[0][0]=='O'))
  {
  r='t';
  w=a[1][1];
  }
 }

     if(r=='f')
 {
 if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&(a[0][2]=='X'||a[0][2]=='O'))
  {
  r='t';
  w=a[1][1];
  }
 }

}
