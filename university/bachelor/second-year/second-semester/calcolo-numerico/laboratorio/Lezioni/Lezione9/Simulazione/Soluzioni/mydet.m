function d=mydet(A)
[L,U,P]=lu(A);
%calcolo del segno della matrice di permutazione
s=rem(sum(sum(P-diag(P))),2);
d=prod(diag(U))*(-1)^s;