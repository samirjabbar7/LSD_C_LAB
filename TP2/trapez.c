#include <stdio.h>
#include <stdlib.h>
float fonction(float x)
{
	return (x);
}
float trapez(float (*f)(float),float a, float b, int n)
{
	float I=0.5*(f(a)+f(b));
	float h=(b-a)/n;
	float x=a+h;

	for(int i=0;i<n-1;i++)
	{
		I+=f(x);
		x+=h;
	}
	return h*I;
}
int main()
{
        float s=trapez(fonction,0,5,1000);
        printf("%f",s);
}



