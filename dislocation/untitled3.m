
ty = (10:1000)*10;
tx = (1:1000)*10+5;
tx = 5:1000;
ty = 10:480;
res1 = meshgrid(tx,ty);
res2 = meshgrid(ty,tx);
hold on
mesh(ty,flip(tx),fittedmodel(res2,rot90(res1)),'FaceAlpha','1')
mesh(y,x,z,'FaceAlpha','0.1')
xlabel('1/concentrtion')
ylabel('field size')
zlabel('time')