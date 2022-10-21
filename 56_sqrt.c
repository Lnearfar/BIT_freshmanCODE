#include<stdio.h>
#include<math.h>

double sqt(double,double,double);

int main()
{
    double x,E;
    scanf("%lf%lf",&x,&E);
    printf("%.8f\n",sqt(x,1,E));
}
double sqt(double x,double p,double E)
{
    if(fabs(p*p-x)<E) return p;
    else return sqt(x,p/2+x/(2*p),E); 
}