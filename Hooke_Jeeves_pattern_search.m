%%%------------------------------------------------------------------
%%%%--   Hooke-Jeeves pattern search method----------------
%%%------------------------------------------------------------------
clear
%-------------function input-------
f=@(x) (x(1)^2+x(2)-11)^2+(x(1)+x(2)^2-7)^2;
%f=@(x) (x(1)-3)^2+(x(2)+1)^2;
%f=@(x) (x(1)^2+ x(2)-11)^2+ (x(1)+ x(2)^2-7)^2; 
%--------------------initial vectors-----
X(:,1)=[3;1];k=1;
delta=[0.4;0.4];
alpha=2;
iter=1;l=0;
%-----------------Exploratory move------------
I=eye(length(delta));
x=X(:,1);
while norm(delta)>1.0e-3

for i=1:length(delta)
    if f(x)>f(x+I(:,i).*delta)
        x=x+I(:,i).*delta;
    elseif f(x)>f(x-I(:,i).*delta)
        x=x-I(:,i).*delta;
    end
    disp(x);
end
if max(x~=X(:,k))
    disp('Exploratory move is success');
    X(:,k+1)=x;
    disp(X);
else
    delta=delta/alpha;
    continue;
end
%------pattern move----------------
while 1

l=l+1;k=k+1;
XP(:,l)=2*X(:,k)-X(:,k-1);
x=XP(:,l);
disp('Pattern point is ');
disp(XP(:,l));
for i=1:length(delta)
    if f(x)>f(x+I(:,i).*delta)
        x=x+I(:,i).*delta;
    elseif f(x)>f(x-I(:,i).*delta)
        x=x-I(:,i).*delta;
    end
    disp(x);
end
if max(x~=XP(:,l))
    disp('Exploratory move is success');
    X(:,k+1)=x;disp(X);
    if f(X(:,k+1))<f(X(:,k)) 
    continue;
    else
    break;
    end
else
    delta=delta/alpha;break;
end

end

end
