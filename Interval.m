f=inline(input('Enter a function f(x) for minimization case','s'));
a=input('Enter the starting point of search point');
b=input('Enter the ending point of search point');
eps=input('Enter desired accuracy of the interval');
xm=(a+b)/2;
x1=(a+xm)/2;
x2=(b+xm)/2;
L=b-a;
iter=0;fprintf('%d\t%6.4f\t%6.4f\n',iter,a,b);
while L>eps
if f(xm)>=f(x1)
b=xm;
xm=(a+b)/2;
x1=(a+xm)/2;
x2=(b+xm)/2;
L=b-a;
iter=iter+1;
fprintf('%d\t%6.4f\t%6.4f\n',iter,a,b);
continue
elseif f(xm)>=f(x2)
a=xm;
xm=(a+b)/2;
x1=(a+xm)/2;
x2=(b+xm)/2;
L=b-a;
iter=iter+1;
fprintf('%d\t%6.4f\t%6.4f\n',iter,a,b);
continue
else
a=x1;b=x2;
xm=(a+b)/2;
x1=(a+xm)/2;
x2=(b+xm)/2;
L=b-a;
iter=iter+1;
fprintf('%d\t%6.4f\t%6.4f\n',iter,a,b);
continue
end
end
fprintf('Optimal lies between %6.3f and %6.3f',a,b);