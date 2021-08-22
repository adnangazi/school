% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% variabili globali
esp = 1:10;
i = 1;

% vettodi dei determinanti mediante matlab e mediante MyDet.m
d1 = zeros(1, length(esp));
d2 = zeros(1, length(esp));

%% corpo dell'esperimento
for n = esp
   H = hilb(n); % creazione matrice di Hilbert
   d1(i) = det(H);
   d2(i) = MyDet(H);
   i = i + 1;
end

%% plot determinanti
figure(1);
semilogy(esp, d1); % linea continua
hold on;
semilogy(esp, d2, '--'); % linea tratteggiata
title('Determinanti');
legend('Det', 'MyDet');
hold off;