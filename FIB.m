f=inline(input('Enter a function f(x) for minimization case','s'));
a=input('Enter the starting point of search point');
b=input('Enter the ending point of search point');
n=input('Enter the number of function evaluations');
F(1)=1;
F(2)=1;
for i=1:n+1
F(2+i)=F(i+1)+F(i);
end
L=b-a;
k=2;
Lk=F(n-k+2)*L/F(n+2);
x1=a+Lk;
x2=b-Lk;
for k=2:n
if f(x1)>=f(x2)
a=x1;
fprintf('\n New interval at iteration %d is %6.4f and %6.4f',k-1,a,b);
k=k+1;
Lk=F(n-k+2)*L/F(n+2);
x1=a+Lk;
x2=b-Lk;
else
b=x2;
fprintf('\n New interval at iteration %d is %6.4f and %6.4f',k-1,a,b);
k=k+1;
Lk=F(n-k+2)*L/F(n+2);
x1=a+Lk;
x2=b-Lk;
end
end
fprintf('\n Final interval is %6.4f and %6.4f \n',a,b);
