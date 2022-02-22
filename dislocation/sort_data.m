
res = table2array(sortrows(dumping,3));
result = unique(res(:,3));
l = length(result);

res = table2array(dumping(:,4));
result = (reshape(res,l,996,[]));
yn = mean(mean(result,1),3);