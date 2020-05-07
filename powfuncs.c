#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NREPS   10000000

long int ipowintrec(int m, int n)
{
    long int p=1;
    if(n<0)
    {
        fprintf(stderr,"ipowint cannot take negative exponents\a\a\n");
        exit(0);
    }
    if(n==0)
        return 1;
    p = ipowintrec(m,n/2);
    if(n%2==0)
        return (p*p);
    else
        return (p*p*m);
}

long int ipowint(int m, int n)
{
    long int p=1;
    int i;
    if(n<0)
    {
        fprintf(stderr,"ipowint cannot take negative exponents\a\a\n");
        exit(0);
    }
    for(i=0;i<n;i++)
        p *= m;
    return p;
}


double powintrec(double x, int n)
{
    double y=1.0;
    if(n<0)
        return 1.0/powintrec(x,-n);
    if(n==0)
        return 1.0;
    y = powintrec(x,n/2);
    if(n%2==0)
        return (y*y);
    else
        return (y*y*x);
}

double powint(double x, int n)
{
    double y=1.0;
    int i,negsign=0;
    if(n<0)
    {
        negsign = 1;
        n = -n;
    }
    for(i=0;i<n;i++)
        y *= x;
    if(negsign)
        return 1.0/y;
    else
        return y;
}

double nth_root(double x, int n)
{
// using Newton Raphson iteration
    double root,root2,eps=1.e-30;
    int i;
    root = 1.0 + (x-1.0)/n;
//    printf("guess is %lg\n",root);
    for(i=0;i<100;i++)
    {
        root2 = ((n-1)*root + x/powintrec(root,n-1))/n;
//        printf("%d %lg\n",i,root2);
        if(fabs(root2-root)<eps) break;
        root = root2;
    }
    return root2;
}

int main()
{
    double x = 4.56,y;
    int npow = 100,i;
    printf("%d %lg\n",(int)pow(7.0,5),pow(7.0,5));
/*
    printf("5.0^10  = %lg\n",powintrec(5.0,10));
    printf("5.0^11  = %lg\n",powintrec(5.0,11));

    printf("5^10    = %ld\n",ipowintrec(5,10));
    printf("5^11    = %ld\n",ipowintrec(5,11));
*/
    y = nth_root(123.0e12,4);
    printf("4th root of 123e12 is %lg\n",y);

    return 0;
}
