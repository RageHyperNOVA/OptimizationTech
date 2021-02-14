/*


BOUNDING PHASE METHOD

SUDHARSAN NEELAMEGAM

*/
#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>

using namespace std;


int fun(int x)
{ int result;
  result= pow(100-x,2);//ENTER FUNCTION IN TERMS OF X AS GIVEN IN QUESTION PROPERLY HERE
}
int fun();

int main()
{
  int x0,k=0,xk,xkp,n,fxk,fxkp,fmm,fpp,d,f0,v=0;
  int c,con=0;
  cout<<"Enter the initial guess value x0 and increment value k:";
  cin>>x0>>d;
  cout<<"k   xk      x(k+1)      fxk     fx(k+1)     cond"<<endl;
    fmm=x0-d;
    f0=x0;
    xk=f0;
    fpp=x0+d;
    xkp=fpp;
  while(v==0)
  {   int a=fun(fmm),b=fun(xk),c=fun(xkp);   
      if(b<=c)
      { con++;
        cout<<k<<"  "<<xk<<"  "<<xkp<<"  "<<b<<"  "<<c<<"  "<<con<<endl;
        break;
      }
    cout<<k<<"  "<<xk<<"  "<<xkp<<"  "<<b<<"  "<<c<<"  "<<con<<endl;
     xk=xkp;
     xkp=xk+((pow(2,k+1))*d);
     k++;
  }
  cout<<"Req range is: ("<<(xk-(pow(2,k-1)*d))<<","<<xkp<<")";
  return 0; 
}
