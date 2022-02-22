


syms f1(a1,b1,c1);
f1 (a1,b1,c1) = a1*log(1+b1*(x^c1));

syms a1(p1,p2,y) b1(p3,p4,y) c1(p5,p6,y);
a1(p1,p2,y) = p1*y + p2;
b1(p3,p4,y) =  (p3) / (y + p4);
c1(p5,p6,y) = p5*y^p6;

 f2(p1,p2,p3,p4,p5,p6,y,x) = f1(a1,b1,c1);