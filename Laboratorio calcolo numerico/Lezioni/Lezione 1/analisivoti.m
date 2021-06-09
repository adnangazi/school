clear all;
% creazione variabili
voti = [24, 26, 28, 30, 30, 24, 30, 30, 26];
crediti = [12, 6, 8, 10, 9, 12, 10, 9, 10];

% 1
mediana = (min(voti) + max(voti)) / 2;
fprintf('La mediana dei voti e'' %2.3f\n', mediana);

% 2
media = sum(voti)/size(voti, 2);
fprintf('La media dei voti e'' %2.3f\n', media);

% 3
media_pesata = sum(crediti.*voti)/sum(crediti);
fprintf('La media pesata dei voti e'' %2.3f\n', media_pesata);

% 4
voto_massimo = max(voti);
fprintf('Il voto massimo e'' %2.3f\n', voto_massimo);

% 5
voto_minimo = min(voti);
fprintf('Il voto minimo '' %2.3f\n', voto_minimo);