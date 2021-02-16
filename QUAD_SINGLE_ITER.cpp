/*

SUCCESIVE QUADRATIC METHOD
Sudharsan Neelamegam

*/
#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>

using namespace std;

float fun(float x)
{
    float result;
    result = pow(x,2)+(54/x) ; //ENTER THE FUNCTION VALUE IN TERMS OF x AS PER IN QUESTION
    return result;
}
float fun();
int main()
{
  float x1,x2,x3,a,b,d,a0,a1,a2,n,dx,fx1,fx2,fx3,value;
  int c=0;
  float f[3];
  cout<<"NOTE***** = This Program wont give you direct answer but it can give you the values for Fmin, Xmin, x' and f(x') for a given iteration and choosen x1,x2,x3 values according to Algorithm\n";
  cout<<"Enter the initial value x1 ,x2 and x3\n";
  cin>>x1>>x2>>x3;
  
  
  float x[3]={x1,x2,x3};
  f[0]=fun(x1);
  f[1]=fun(x2);
  f[2]=fun(x3);
  float Fm;
  if(f[0]<=f[1] && f[0]<=f[2])
    {
        Fm=f[0];
    }
    else if(f[1]<=f[0] && f[1]<=f[2])
    {
        Fm=f[1];
    }
    else
    {
        Fm=f[2];
    }
  float ck=Fm,Xm,xb;
  int j=0;
  while(j<3)
  { 
    if(f[j]==ck)
    {
        Xm=x[j];
        break;
    }
    j++;  
  }
  
  a0=f[0];
  a1=(f[1]-f[0])/(x[1]-x[0]);
  a2=pow(x[2]-x[1],-1)*(((f[2]-f[0])/(x[2]-x[0]))-a1);
  xb= ((x[0]+x[1])/2)-(a1/(2*a2));
  cout<<"Fmin: "<<Fm<<endl<<"Xmin: "<<Xm<<endl<<"x1: "<<x[0]<<endl<<"x2: "<<x[1]<<endl<<"x3: "<<x[2]<<endl<<"x': "<<xb<<endl<<"F(x'): "<<fun(xb)<<endl;
  
 
return 0; 
}