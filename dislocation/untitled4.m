hold on;

res1 = meshgrid(x,z);
res2 = meshgrid(z,x);

for i = 1:(length(z))
    for j = 1:(length(x))
        data(i,j) = (4.881*z(i)+45)*log(1+a*exp(b*z(i))*(x(j)^(tanh(z(i)*0.01165+0.001214)*2.276+0.6663)));
    end
end
data = 0;
zn = linspace(2,10000,500);
xn = linspace(3,10000,400);
for i = 1:(length(zn))
    for j = 1:(length(xn))
        data(i,j) = (4.881*zn(i)+45)*log(1+a*exp(b*zn(i))*(xn(j)^(tanh(zn(i)*0.01165+0.001214)*2.276+0.6663)));
    end
end

%mesh(z,x,fittedmodel(rot90(res1),res2))
mesh(zn,flip(xn),rot90(data))
mesh(z,flip(x),rot90(y))

xlabel("1/concentation");
ylabel("size");
zlabel("time");