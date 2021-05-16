//Cauchy's Steepest Descent Method
//Sudharsan Neelamegam

#include <bits/stdc++.h>
#include <math.h>

using namespace std;


//Calculate the Gradient as soon as question is given and put gradient in terms of x1 and x2 in two functions below

float f1(float x1,float x2)
{ float r;
  r=(1+4*x1+2*x2); //Gradient First term
  return r;
}
float f2(float x1,float x2)
{ float r1;
  r1=(-1+2*x1+2*x2); //Gradient Second term
  return r1;
}
float gf(float p,float q)
{
  float h;
  h=p-q+2*pow(p,2)+(2*p*q)+pow(q,2); // Function given in the question
  return h;
}
float f1();
float f2();
float gf();
float univariate(float x0[2],float s[2])
{ float k;
    if (gf(x0[0]+0.01*s[0],x0[1]+0.01*s[1])<gf(x0[0],x0[1]))
    {float t1,t2;
        while (k<100)
        {
        t1=gf(x0[0]+k*s[0],x0[1]+k*s[1]);
        t2=gf(x0[0]+(k+0.001)*s[0],x0[1]+(k+0.001)*s[1]);
         if(t1<t2)
         {break;}
         else
         {k=k+0.001;}
        }
    }
   else
    {float k=0;
    while (k>-100)
    { float t1,t2;

           t1=gf(x0[0]+k*s[0],x0[1]+k*s[1]);
           t2=gf(x0[0]+(k-0.001)*s[0],x0[1]+(k-0.001)*s[1]);
     if(t1<t2)
        {break;}
     else
       {k=k-0.001;}
    }
    }
return k;
}
float univariate();

int main()
{ float X1[2]={0,0},S[2]; //Trial Point X1
  float gf1[2];
  int i=0;
  gf1[0]=f1(X1[0],X1[1]);
  gf1[1]=f2(X1[0],X1[1]);
  S[0]=-1*gf1[0];
  S[1]=-1*gf1[1];
  for(int j=0;j<10;j++)             //Enter n value for n iterations
  {   cout<<"Iteration No."<<(i+1)<<endl;
      cout<<"Search Direc is : ("<<S[0]<<","<<S[1]<<")"<<endl;
      float k1=univariate(X1,S);
      float z=k1;
      cout<<"K value is: "<<z<<endl;
      X1[0]=X1[0]+z*S[0];
      X1[1]=X1[1]+z*S[1];
      cout<<"X2:"<<X1[0]<<","<<X1[1]<<endl;
      float e,r;
      e=f1(X1[0],X1[1]);
      r=f2(X1[0],X1[1]);
      S[0]=-1*e;
      S[1]=-1*r;
      i++;
      if(e==0 && r==e)
      {
      break;
      }
  }

 return (0);
}
