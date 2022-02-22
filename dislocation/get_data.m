function [x,y,result] = get_data(dumping)
res = table2array(sortrows(dumping,3));
result = unique(res(:,3));
l = length(result);


a = zeros(length(res)/l,4,length(result));

x = zeros(996,l);
y = zeros(996,l);

for i = 0:(l-1)
    
    a(:,:,(i+1)) = res((end/l*i+1):(end/l*(1+i)),:);
    mean(a(:,4,i+1))
    y(:,i+1) = mean(rot90(reshape(a(:,4,i+1),996,[])));
    x(:,i+1) = 5:1000;
end
plot(x,y);
mean(y)
end

