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
  float f[3]={0,0,0};
  cout<<"Enter the initial value x1 and increment value:";
  cin>>x1>>d;
  x2=x1+d;
  f[0]=fun(x1);
  f[1]=fun(x2);
  if(f[0]>f[1])
  {
      x3=x2+d;
  }
  else
  {
      x3=x1-d;
  }
  float x[3]={x1,x2,x3};
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
  cout<<"Fmin: "<<Fm<<'\n'<<"Xmin: "<<Xm<<'\n'<<"a0: "<<a0<<'\n'<<"a1: "<<a1<<'\n'<<"a2: "<<a2<<'\n'<<"x': "<<xb<<'\n'<<"f(x'): "<<fun(xb);
  
 
return 0; 
}
