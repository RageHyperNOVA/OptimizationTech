//Newton Method
//Sudharsan Neelamegam

#include <bits/stdc++.h>
#include <math.h>

using namespace std;
float gf(float p,float q)
{
  float h;
  h=pow((pow(p,2)+q-11),2)+pow((pow(q,2)+p-7),2); // Function given in the question
  //h= 2*p*q+p-q+2*pow(p,2) + pow(q,2);
  return h;
}
float f1(float x1,float x2)
{ float r;
  r=4*pow(x1,3)+2*pow(x2,2)-42*x1+4*x1*x2-14; //Gradient First term(df/dx1)
  return r;
}
float f2(float x1,float x2)
{ float r;
  r=4*pow(x2,3)+2*pow(x1,2)-26*x2+4*x1*x2-22; //Gradient Second term(df/dx2)
  return r;
}
float gf();
float f1();
float f2();
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
int main()
{float X[2]={2,1},s[2],e[2]; //Initial Point X
for(int i=0;i<4;i++)
    { cout<<"Iteration "<<i+1<<endl;
e[0]=f1(X[0],X[1]);
e[1]=f2(X[0],X[1]);
cout<<"First Derivatives are : ("<<e[0]<<","<<e[1]<<")"<<endl;
      //Hessian//
      float r[2][2],b=0; //b=0 for positive semidefinite, b=1 for all other
      r[0][0]=12*pow(X[0],2)+4*X[1]-42; //d2f/dx1
      r[0][1]=4*X[0]+4*X[1];         //d2f/dx1dx2                   //r is hessian matrix (put expression please)
      r[1][0]=r[0][1];
      r[1][1]=4*X[0]+12*pow(X[1],2)-26; //d2f/dx2
      int j1=r[0][0],j2=(r[0][0]*r[1][1]-r[0][1]*r[1][0]);

      //Hessian end//
      //Hessian Inverse//


		float determinant = 0,temp;
        determinant = (r[0][0] * r[1][1]  - r[1][0] * r[0][1]);       //finding determinant
        temp = r[0][0];
        r[0][0]=r[1][1];
        r[1][1]=temp;
	    r[0][1]=-1*(r[0][1]); //REMOVE '-1* if value is 0'
        r[1][0]=-1*(r[1][0]); //REMOVE '-1* if value is 0'

        float p1[2][2];                                                 //p1 is hessian inverse
        p1[0][0]=r[0][0]/determinant;
        p1[0][1]=r[0][1]/determinant;
        p1[1][0]=r[1][0]/determinant;
        p1[1][1]=r[1][1]/determinant;

float s[2];
s[0]=-1*(p1[0][0]*e[0]+p1[0][1]*e[1]);
s[1]=-1*(p1[1][0]*e[0]+p1[1][1]*e[1]);
cout<<"Search Direction : "<<s[0]<<","<<s[1]<<endl;
    float u=univariate(X,s);
    cout<<"Optimal Alpha : "<<univariate(X,s)<<endl;
    if(u<0)
    {   cout<<endl<<"Error 404,[This is ascent direction] !! Run again with new Initial point "<<endl;
        break;
    }
    X[0]+=(u*s[0]);
    X[1]+=(u*s[1]);
    cout<<endl<<"New Point : ("<<X[0]<<","<<X[1]<<")"<<endl<<"Fuction Value at new point:"<<gf(X[0],X[1])<<endl<<endl;
}
return 0;
}
