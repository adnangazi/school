% Adnan Latif Gazi Matricola 1224442
function [dete] = MySymDet (V)
    G = V' * V;
    [Q, R] = qr(G);
    dete = det(Q) * det(R);
    
%     ho cercato di calcolare il determinante di una matrice a mano
%     mediante somma e sottrazione tra produttorie di diagonali, ma non
%     riesco a ricavarmi le diagonali che mi servono visto che richiedono
%     la diagonale superiore unita ad una diagonale inferiore
%     n = length(G);
%     d1 = 0;
%     d2 = 0;
%     B = flip(Q, 2);
%     for k = 0:n - 1
%         d1 = d1 + prod([diag(Q, k), diag(Q, k - n)]) - prod([diag(B, k), diag(B, k - n)]);
%     end
%     
%     B = flip(R, 2);
%     for k = 0:n - 1
%         d2 = d2 + prod([diag(R, k), diag(R, k - n)]) - prod([diag(B, k), diag(B, k - n)]);
%     end
end