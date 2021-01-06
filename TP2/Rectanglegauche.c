#include <stdio.h>
#include <stdlib.h>

float fonction(float x)
{
	return (x);
}

float Recgauche(float(*f)(float), float a, float b, int n)
{
	float h=(b-a)/n;
	float x=a+h;
	int s=0;
	for(int i=0;i<n;i++)
	{
		s+=f(x);
		x+=h;
	}
	return s*h;
}

int main()
{
	float s=Recgauche(fonction,0,5,1000);
	printf("%f",s);
}

