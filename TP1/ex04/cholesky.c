#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
float *descente(float A[N][N], float B[N], int n)
{
  float   *x;
  x = malloc(sizeof(float) * n);
  /******Implement the solution here******/
  /***************************************/
x[0]=B[0]/A[0][0];
for(int i=1;i<n;i++)
{
	float s=0;
	for(int j=0;j<=i;j++)
	{
		s=s+A[i][j]*x[j];
	}
	x[i]=(B[i]-s)/A[i][i];
}  
  /****************************************/

  return (x);
}

float *remontee(float A[N][N], float B[N], int n)
{
	float   *x;
	x = malloc(sizeof(float) * n);
	for(int i=n-2;i>=0;i--)
	{
		int s=0;
		for(int j=i+1;j<n;j++)
		{
			s=s+A[i][j]*x[j];
		}
	x[i]=(B[i]-s)/A[i][i];
	}  
  /***************************************/
  return x;
}
float *cholesky(float A[N][N], float B[N], int n)
{
  float c[n][n];
  c[0][0]=sqrt(A[0][0]);
  for(int i=1;i<n;i++)
    c[i][0]=A[i][0]/c[0][0];
  for(int j=1;j<n;j++)
  {
    for (int i=0;i<=j-1;i++)
    {
      c[i][j]=0;
    }
    int s=0;
    for(int k=0;k<=j-1;k++)
    {
      s+=c[j][k]*c[j][k];
    }
    c[j][j]=sqrt(A[j][j]-s);
    
    for(int i=j+1;i<n;i++)
    {
	int d=0;
    	for(int k=0;k<j-1;k++)
    	{
      		d+=c[i][k]*c[j][k];
    	}
      	c[i][j]=1/c[j][j]*(A[i][j]-d);
    }
    float cT[n][n];
    int i;
    for(int i=0;i<n;i++)
    {
	    for(int j=0;j<n;j++)
      	    	cT[i][j]=c[j][i];
    }
    for(int i=0;i<n;i++)
	  {
   	for(int j=0;j<n;j++)
		printf("%f \t",c[i][j]);
	printf("\n");}
   
    	float *y=descente(c, B, n);
	float *x=remontee(cT, y, n);
  return (x);
  }

}

int main()
{
  float   A[N][N], B[N];
  float   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = cholesky(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
  return (0);
}

