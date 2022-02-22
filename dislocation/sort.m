%x(:,end+1:end+length(nx(1,:))) = nx;
%y(:,end+1:end+length(ny(1,:))) = ny;
%z(end+1:end+length(result)) = result;

[z_sorted, z_order] = sort(z);
newB = y(z_order,:);
