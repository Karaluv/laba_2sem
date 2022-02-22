for i = 1:78105
if (res(i,1)<res(i+1,1)-2)
res(i+1,:) = [];
end

if (res(i,1)>res(i+1,1)-1)
    if res(i,1) < 1000
res(i+1,:) = [];
    end
end
end
