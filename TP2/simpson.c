#include <stdio.h>
#include <stdlib.h>
float fonction (float x)
{
	return x;
}
float simpson(float (*f)(float),float a,float b,int n)
{
	float h=(b-a)/n;
	float x=a+h;
	float z=a+h/2;
	float I1=0;
	float I2=f(z);
	for(int i=0;i<n-1;i++)
	{
        	z+=h;
        	I1+=f(x);
        	I2+=f(z);
        	x+=h;
	}
	return (h/6)*(f(a) + f(b) + 2*I1 + 4*I2);
}
int main()
{
        float s=simpson(fonction,0,5,1000);
        printf("%f",s);
}


