% Adnan Latif Gazi Matricola 1224442
clear all;
crediti = [3, 4, 5, 6];
voti = [21, 22, 23, 24];

fprintf('La mediana dei voti è %f\n', ((voti(1) + voti(length(voti)))/2));
fprintf('La media dei voti è %f\n', (sum(voti)/length(voti)));
fprintf('La media pesata dei voti è %f\n', (sum(crediti.*voti)/sum(crediti)));
fprintf('Il voto massimo è %f\n', max(voti));
fprintf('Il voto minimo è %f\n', min(voti));