clear
%-------------function input-------
f=@(x) x(1)-x(2)+2*x(1)^2+2*x(1)*x(2)+x(2)^2;

%--------------------initial vectors-----
x0=[-0.25;0];
s=[0;1];
%---------searching process by exhaustive search method----------
if f(x0+0.01*s)<f(x0)
k=0;
while k<100
    if f(x0+k*s)<f(x0+(k+0.001)*s)
        break
    else
        k=k+0.001;
    end
end
disp('optimal value of parameter k is');
disp(k);
disp('optimial min point is');
disp(x0+k*s);
disp('function value at optimal point is');
disp(f(x0+k*s));
else
    k=0;
while k>-100
    if f(x0+k*s)<f(x0+(k-0.001)*s)
        break
    else
        k=k-0.001;
    end
end
disp('optimal value of parameter k is');
disp(k);
disp('optimial min point is');
disp(x0+k*s);
disp('function value at optimal point is');
disp(f(x0+k*s));
end