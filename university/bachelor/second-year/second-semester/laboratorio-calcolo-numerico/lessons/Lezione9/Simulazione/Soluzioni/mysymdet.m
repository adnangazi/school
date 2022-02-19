function d=mysymdet(V)
[Q,R]=qr(V);
d=prod(diag(R)).^2;