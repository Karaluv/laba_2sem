
mean(abs((a_model(z) - coef_a)./coef_a))
mean(abs((b_model(z) - coef_b)./coef_b))
mean(abs((c_model(z) - coef_c)./coef_c))


hold on;
proxim = zeros(length(z),length(x));
for i = 1:length(z)
%proxim(i,:) = a_model(z(i))*log(1+b_model(z(i)).*(x.^c_model(z(i))));
proxim(i,:) = fittedmodel(z,x);
plot(x,proxim(i,:))
plot(x, y(i,:))
end