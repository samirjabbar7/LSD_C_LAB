#include<stdio.h>
#include<stdlib.h>
float fonction(float x)
{ 
	return (x); 
} 

float Rectangledroite(float (*f)(float), float a, float b, int n)
{
    float h=(b-a)/n;
    float s=0;
    float t=a;
    for(int k=0;k<n;k++)
    {
        s+=f(t);
	t+=h;
    }
    return (h*s);
}
int main()
{
    //float (*Rec)(float)=&fonction;
    float s=Rectangledroite(fonction,0,2, 2000000);
    //printf("%f",Rectangledroite(Rec,2,10, 15));
    printf("%f",s);
}

