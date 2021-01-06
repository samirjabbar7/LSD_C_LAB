#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 double fonction(double x)
{return exp(x);}

double trapez(double(*f)(double),double a, double b, int n)
{
        double I=0.5*(f(a)+f(b));
        double h=(b-a)/n;
        double x=a+h;

        for(int i=0;i<n-1;i++)
        {
                I+=f(x);
                x+=h;
        }
        return h*I;
}

double simpson(double(*f)(double),double a,double b,int n){
    double h=(b-a)/n,x=a+h,z=a+h/2,I1=0,I2=f(z);
    for(int i=0;i<n-1;i++){
        z+=h;
        I1+=f(x);
        I2+=f(z);
        x+=h;
    }
    return(h/6)*(f(a) + f(b) + 2*I1 + 4*I2);
}

double Rectanglegauche(double(*f)(double), double a, double b, int n)
{
        double h=(b-a)/n;
        double x=a+h;
        float s=0;
        for(int i=0;i<n;i++)
        {
                s+=f(x);
                x+=h;
        }
        return s*h;
}
double Rectangledroite(double (*f)(double), double a, double b, int n)
{
    double h=(b-a)/n;
    double s=0;
    double t=a;
    for(int k=0;k<n;k++)
    {
        s+=f(t);
        t+=h;
    }
    return (h*s);
}

int nb_nec(double(*f)(double),double a, double b,double Err,double (*Methode)(double(*)(double),double,double,int),double exacte)
{
	int n=1;
	while ((Methode(exp,a,b,n)-exacte)> Err || (Methode(exp,a,b,n)-exacte)< -Err)
	{n+=1;}
	return n;
}
int main()
{
	    printf("par simpson %d \n",nb_nec(exp,0,1,0.001,simpson,exp(1)-1));
	
	    printf("par Rectanglegauche %d \n",nb_nec(exp,0,1,0.001,Rectanglegauche,exp(1)-1));

	    printf("par trapez %d \n",nb_nec(exp,0,1,0.001,trapez,exp(1)-1));

	    printf("par REctangledroite %d \n",nb_nec(exp,0,1,0.001,Rectangledroite,exp(1)-1));

}
	













































