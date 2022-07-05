% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% variabili globali
esp = 1:30;
toll = 0;
Kappa1 = zeros(1, length(esp));
KappaInf = zeros(1, length(esp));
E1 = zeros(1, length(esp));
EInf = zeros(1, length(esp));
i = 1;

%% corpo dell'esperimento
for n = esp
   A = hilb(n); 
   A2 = eye(n);
   A3 = A * MyQRInv(A, toll);
   Kappa1(i) = MyCond(A, 1, toll);
   KappaInf(i) = MyCond(A, Inf, toll);
   E1(i) = abs(cond(A2, 1) - MyCond(A3, 1, toll));
   EInf(i) = abs(cond(A2, 1) - MyCond(A3, Inf, toll));
   i = i + 1;
end

%% plot
figure(1);
semilogy(esp, eps * Kappa1);
hold on;
semilogy(esp, eps * KappaInf);
semilogy(esp, E1);
semilogy(esp, EInf);
title('Numeri di condizionamento ed errori assoluti');
legend('eps*Kappa1', 'eps*KappaInf', 'E1', 'EInf');
hold off;

%% commento al risultato
fprintf('COMMENTO AL RISULTATO:\n');
fprintf('La figura prodotta indica che il valore dei numeri di condizionamento cresce al crescere delle dimensioni della matrice utilizzata ma presto si stabilizza.');
fprintf(' Inoltre non vi è tanta differenza tra l uso di una norma in particolare, in quanto la norma 1 o la norma Inf restituiscono risultati molto vicini.');
fprintf(' Per questo anche gli errori assoluti calcolati hanno la stessa caratteristica.\n');