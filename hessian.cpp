//hessian
//Sudharsan Neelamegam
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
float gf(float p,float q)
{
  float h;
  h=pow(p,3)+pow(q,3)+2*pow(p,2)+4*pow(q,2)+6; // Function given in the question
  //h= 2*p*q+p-q+2*pow(p,2) + pow(q,2);
  return h;
}
float gf();

int main()
{ float r[2][2]; // r is hessian matrix
  int n;
  cout<<"Enter the number of minimum points : ";
  cin>>n;
  float X[n],Y[n];
  cout<<endl<<"Input the minimum points : "<<endl;
  for (int j=0;j<n;j++)
  { cin>>X[j]>>Y[j];}
  for(int i=0;i<n;i++)
  {
      r[0][0]=6*X[i]+4; //d2f/dx1
      r[0][1]=0;        //d2f/dx1dx2                   //r is hessian matrix (put expression please)
      r[1][0]=r[0][1];
      r[1][1]=6*Y[i]+8; //d2f/dx2
      float j1,j2;
      j1=(r[0][0]);
      j2=((r[0][0]*r[1][1])-(r[0][1]*r[1][0]));
      cout<<"Point: ("<<X[i]<<","<<Y[i]<<")"<<endl<<"J1 :"<<ceil(j1)<<", J2:"<<ceil(j2)<<endl;
      if(j1>0 && j2>0)
      {
          cout<<"RESULT : Positive Definite , Relative Minimum , Fn value : "<<gf(X[i],Y[i])<<endl<<endl;
      }
      else if(j1<0 && j2>0)
      {
          cout<<"Negative Definite , Relative Maximum , Fn value : "<<gf(X[i],Y[i])<<endl<<endl;
      }
      else
      {
          cout<<"Indefinite , Saddle point , Fn value : "<<gf(X[i],Y[i])<<endl<<endl;
      }
  }
return 0;
}
