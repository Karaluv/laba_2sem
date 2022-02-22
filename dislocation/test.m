s = 0;
res = table2array(dump40_50);
for i = 1:161352
if res(i,3) == 50
s = s+res(i,4);
end
end

s/161352*3
