hold on;
w = linspace(1, 0,length(x));
coef= zeros(length(z)+1,3);
coef(1,:) = [2000 1 1];

fits=cell(1,length(z));
for i = 1:length(z)
ft = fittype('a*log(1+b*(x^c))',...
    'dependent',{'y'},'independent',{'x'},...
    'coefficients',{'a','b','c'});
options = fitoptions('Method', 'NonlinearLeastSquares','Lower',[0 0 coef(i,3)], ...
    'Upper',[16000 0.5 3.7],'StartPoint',[coef(i,1)+10 coef(i,2) coef(i,3)+0.1],'Weight',w);
options.TolX = 10e-32;
options.DiffMaxChange = 10e-6;
options.MaxIter = 1600;
f = fit(rot90(x),rot90(y(i,:)),ft,options)
% Plot results
plot(x, y(i,:))

plot(x,f(x))
fits{i} = f;
coef(i+1,:) = coeffvalues(f);


end

coef(1,:) = [];

coef_a = coef(:,1);
coef_b = coef(:,2);
coef_c = coef(:,3);