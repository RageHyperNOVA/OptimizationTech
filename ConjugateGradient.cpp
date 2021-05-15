//Conjugate Gradient Method Descent Method
//Sudharsan Neelamegam


// IMP NOTE : Run for 1 iteration , get X(1) value and put it in X={} while initializing and run for 10 loop

#include <bits/stdc++.h>
#include <math.h>

using namespace std;


//Calculate the Gradient as soon as question is given and put gradient in terms of x1 and x2 in two functions below

float f1(float x1,float x2)
{ float r;
  r=4*pow(x1,3)+2*pow(x2,2)-42*x1+4*x1*x2-14;
  //r=(1+4*x1+2*x2); //Gradient First term
  return r;
}
float f2(float x1,float x2)
{ float r;
  r=4*pow(x2,3)+2*pow(x1,2)-26*x2+4*x1*x2-22;
  //r1=(-1+2*x1+2*x2); //Gradient First term
  return r;
}
float gf(float p,float q)
{
  float h;
  h=pow((pow(p,2)+q-11),2)+pow((pow(q,2)+p-7),2);
  //h=p-q+2*pow(p,2)+(2*p*q)+pow(q,2); // Function given in the question
  return h;
}
float f1();
float f2();
float gf();
float univariate(float x0[2],float s[2])
{
    if (gf(x0[0]+0.01*s[0],x0[1]+0.01*s[1])<gf(x0[0],x0[1]))
    {float t1,t2,k=0;
        while (k<100)
        {
        t1=gf(x0[0]+k*s[0],x0[1]+k*s[1]);
        t2=gf(x0[0]+(k+0.001)*s[0],x0[1]+(k+0.001)*s[1]);
         if(t1<t2)
         {break;}
         else
         {k=k+0.001;}
        }
    return k;
    }
   else
    {float k=0;
     float t1,t2;
     while (k>-100)
     {
           t1=gf(x0[0]+k*s[0],x0[1]+k*s[1]);
           t2=gf(x0[0]+(k-0.001)*s[0],x0[1]+(k-0.001)*s[1]);
     if(t1<t2)
        {break;}
     else
       {k=k-0.001;}
    }
    return k;
    }

}
float univariate();
float diss(float x,float y)
{ float r;
  r = pow(x,2)+pow(y,2);
  return r;
}
float diss();
int main()
{ float X[2]={2.2371786,2.9791541},e[2],f[0],S[2],u; //Trial Point X1
  int t=0,i=0;
f[0]=f1(X[0],X[1]);
f[1]=f2(X[0],X[1]);
float r1=f[0],r2=f[1];
  S[0]=-1*f[0];
  S[1]=-1*f[1];
  u=univariate(X,S);
      X[0]=X[0]+(u*S[0]);
      X[1]=X[1]+(u*S[1]);
  float dist1,dist2,S2[2];
  for(int i=0;i<10;i++)             //Enter j<n value for n iterations
  {   cout<<"Iteration No."<<(i+1)<<endl;
      cout<<"Search Direc is : ("<<S[0]<<","<<S[1]<<")"<<endl;
      e[0]=f1(X[0],X[1]);
      e[1]=f2(X[0],X[1]);
      cout<<"Optimal point from Univariate : ("<<X[0]<<","<<X[1]<<")"<<endl;
      cout<<"First der at here : "<<e[0]<<" "<<e[1]<<endl;
      cout<<diss(e[0],e[1])<<endl<<diss(r1,r2)<<endl;
      S2[0]=(-1*e[0])+(diss(e[0],e[1])/diss(r1,r2))*S[0];
      S2[1]=(-1*e[1])+(diss(e[0],e[1])/diss(r1,r2))*S[1];
      cout<<"New Search Direction : "<<S2[0]<<" "<<S2[1]<<endl;
      cout<<fixed<<setprecision(7);
      float u=univariate(X,S2);
      cout<<"CHECK : "<<u;
      X[0]=X[0]+(u*S2[0]);
      X[1]=X[1]+(u*S2[1]);
      cout<<"New POINT : ("<<X[0]<<","<<X[1]<<")"<<endl<<endl;
      r1=e[0];
      r2=e[1];
      S[0]=S2[0];
      S[1]=S2[1];
  }

 return (0);
}
