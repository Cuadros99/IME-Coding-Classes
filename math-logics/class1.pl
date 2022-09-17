p(a,b).
p(b,c).
p(c,d).
a(X,Y):-p(X,Y).
a(X,Y):-p(X,Z), a(Z,Y).