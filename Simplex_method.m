%%%------------------------------------------------------------------
%%%%--   Simplex alogirthm by Nelder and Mead(1965)-----------
%%%------------------------------------------------------------------
clear
%-------------function input-------
f=@(x) 4*x(1)^2-4*x(1)*x(2)+2*x(2)^2;
%--------------------initial values and initial simplex vectors-----
gamma=1.5;
beta=0.5;
x(:,1)=[2;2];x(:,2)=[1;0];x(:,3)=[1;2];
N=2; %------number of variables of the problem---------
%-----------------simplex alogirthm--based on number of iteration-------

for iter=1:20
    disp('Simplex geometry points are')
disp(x);
    xh=x(:,1);h=1;xl=xh;l=1;
 for i=1:N+1
     if f(xh)<f(x(:,i))
         xh=x(:,i);h=i;
     elseif f(xl)>f(x(:,i))
         xl=x(:,i);l=i;
     end
 end
 disp('Worst point is');
 disp(xh);
 disp('Best point is')
 disp(xl);
 %------centroid computation------------
 xc=zeros(length(xh),1);
 for i=1:N+1
     if i~=h
     xc=xc+x(:,i);
     end
 end
 xc=xc/N;
 disp('centroid is')
 disp(xc);
 %--------reflected point
 xr=2*xc-xh;
 disp('reflection point of xh in the direction of xc is');
 disp(xr);
 %----------new simplex point------------------
 if f(xr)<f(xl)
     xnew=(1+gamma)*xc-gamma*xh;
 elseif f(xr)>f(xh)
     xnew=(1-beta)*xc+beta*xh;
 else
     xnew=(1+beta)*xc-beta*xh;
 end
 disp('New point of simplex is')
 disp(xnew);
 x(:,h)=xnew;
 disp('---------------------------------------------------');
 end