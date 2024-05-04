#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
 float x[20], y[20][20],xp,yp = 0,p;
 int i,j, n;
 system("cls");
 
 
 printf("Enter number of data?\n");
 scanf("%d", &n);
 printf("Enter data:\n");
 for(i = 0; i < n ; i++)
 {
  printf("x[%d]=", i);
  scanf("%f", &x[i]);
  printf("y[%d]=", i);
  scanf("%f", &y[i][0]);
 }


 
 for(i = 1; i < n; i++)
 {
  for(j = 0; j < n-i; j++)
  {
   y[j][i] = y[j+1][i-1] - y[j][i-1];
  }
 }

 printf("\nFORWARD DIFFERENCE TABLE\n\n");
 for(i = 0; i < n; i++)
 {
  printf("%0.2f", x[i]);
  
  for(j = 0; j < n-i ; j++)
  {
   printf("\t%0.2f", y[i][j]);
  }
  printf("\n");
 }

	 printf("Enter interpolation point: ");
	 scanf("%f", &xp);
	 
	 /* Implementing Lagrange Interpolation */
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p * (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i][0];
	 }
	 printf("Interpolated value at %.3f is %.3f.", xp, yp);
 getch(); 
 return 0;
}
