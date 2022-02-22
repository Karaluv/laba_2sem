function [x,y] = dump_it(dump)
%single_move = table2array(dump);
single = dump(:,4);
res = reshape(single,996,[]);
y = mean(rot90(res));
x = 5:1000;

plot(x,y);

end
