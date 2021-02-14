/*
EXHAUSTVE SEARCH METHOD
Sudharsan Neelamegam
*/
#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>

using namespace std;


float fun(float x)
{
    float result;
    result = pow(x-1,2)-(0.01*pow(x,4)); //ENTER THE FUNCTION VALUE IN TERMS OF x AS PER IN QUESTION
    return result;
}
float fun();
int main()
{
  float x1=0,x2,x3,b,a,n,dx,fx1,fx2,fx3,value;
  int c=0;
  cout<<"Enter the interval a,b and intermediate points n:";
  cin>>a>>b>>n;
  int ivl=(n/2)+2;
  
  
  cout<<"iter   x1      x2      x3    fx1     fx2     fx3    cond"<<endl;
  dx=(b-a)/n;
  for(int i=0;i<ivl;i++)
  {
      x1=a;
      x2=a+dx;
      x3=a+(2*dx);
        fx1=fun(x1); 
        fx2=fun(x2); 
        fx3=fun(x3); 
       if( (fx2<=fx1 && fx2<=fx3) )
    {   
        c=1;
        cout<<fixed;
        cout<<i<<setprecision(2)<<"     "<<x1<<"    "<<x2<<"    "<<x3<<"   "<<fx1<<"    "<<fx2<<"    "<<fx3<<"    "<<c<<endl;
        break;
    }
     cout<<fixed;
     cout<<i<<setprecision(2)<<"     "<<x1<<"    "<<x2<<"    "<<x3<<"   "<<fx1<<"    "<<fx2<<"    "<<fx3<<"    "<<c<<endl;
     a+=dx;
  }
  cout<<"Req Range is : ["<<x1<<","<<x3<<"]";

return 0; 
}
