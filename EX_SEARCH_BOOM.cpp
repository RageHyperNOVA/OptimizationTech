/*


EXHAUSTVE SEARCH METHOD


*/
#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>

using namespace std;



int main()
{
  float x1=0,x2,x3,b,a,n,dx,fx1,fx2,fx3,value;
  int c=0;
  cout<<"Enter the interval a,b and intermediate points n:";
  cin>>a>>b>>n;
  int ivl=(n/2)+2;
  
  
  cout<<"iter   x1      x2      x3    fx1     fx2     fx3    cond"<<endl;
  dx=(b-a)/n;
  for(int i=1;i<ivl-1;i++)
  {
      
      
      x1=a;
      x2=a+dx;
      x3=a+(2*dx);
      
      
        /*ENTER THE GIVEN FUNCTION HERE:*/
        fx1=pow(x1-1,2)-(0.01*pow(x1,4)); //enter funtion f(x1) properly in terms of x1 
        fx2=pow(x2-1,2)-(0.01*pow(x2,4)); //enter funtion f(x2) properly in terms of x1
        fx3=pow(x3-1,2)-(0.01*pow(x3,4)); //enter funtion f(x3) properly in terms of x1
        /*                              */
       
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