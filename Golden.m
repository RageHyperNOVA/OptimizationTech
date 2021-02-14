clear
f=inline(input('Enter a function f(x) for minimization case','s'));
a=input('Enter the starting point of search point');
b=input('Enter the ending point of search point');
eps=input('Enter desired accuracy of the interval');
aw=0;bw=1;
Lw=1;
iter=1;
while Lw>=eps
wx1=aw+0.618*Lw;
wx2=bw-0.618*Lw;
x1=(b-a)*wx1+a;x2=(b-a)*wx2+a;
if f(x2)>f(x1)
aw=wx2;
Lw=bw-aw;
else
bw=wx1;
Lw=bw-aw;
end
fprintf('%d \t %6.3f \t %6.3f \t %6.3f \t %6.3f\t %6.3f\t %6.3f\n',...
iter,wx2,wx1,x2,x1,f(x1),f(x2));
iter=iter+1;
end
fprintf('Optimal lies between %6.3f and %6.3f',x2,x1);