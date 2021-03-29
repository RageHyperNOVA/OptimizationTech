%%%------------------------------------------------------------------
%%%%--   program works only for two and three dimension problems------
%%%------------------------------------------------------------------
clear
%-------------function input-------
f=@(x) 4*x(1)^2-4*x(1)*x(2)+2*x(2)^2;
%--------------------initial vectors-----
x0=[2;3];
delta=[2;2];
iter=1;
%-----------------Evaluationary alogirthm------------
while norm(delta)>1.0e-2
k=0;
for i=1:2^(length(delta))
    if rem(i,2)==1
        if k~=0
    delta1=delta/2;
    delta1(k)=-delta1(k);
    X(:,i)=x0+delta1;
        else
            X(:,i)=x0+delta/2;
        end
    else
        if k~=0
            delta1=-delta/2;
    delta1(k)=-delta1(k);
    X(:,i)=x0+delta1;
    k=k+1;
        else
            X(:,i)=x0-delta/2;k=k+1;
        end
    end
    
end
disp('The box points are given below');
disp([X x0]);
disp('Function values are')
x1=x0;
for i=1:length(X)
    disp(f(X(:,i)));
    if f(x1)>f(X(:,i))
        x1=X(:,i);
    end
end
disp(f(x0))
disp('new min point is');
disp(x1);
disp('function value at new min point is')
disp(f(x1));
fprintf('iteration - %d completed\n',iter);
disp('---------------------------------------------------------------');
iter=iter+1;
if x1==x0
    delta=delta/2;
else
    x0=x1;
end
end