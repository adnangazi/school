% pulizia workspace
clear all;
% inserimento numero casi test
ind = input('Inserire il numero di casi test che si vogliono eseguire: ');
% apertura file main3.txt per scrittura risultati
file = fopen('main3.txt', 'w');
% scrittura titolo nel file
fprintf(file, 'Risuluzione eq. secondo grado per qualsiasi coefficienti\n');
fprintf(file, 'Numero di casi test: %f\n', ind);
% ciclo sui casi test
for i = 1:ind
    % scrittura dati test nel file
    fprintf(file, 'Test numero: %f\n', i);
    % inserimento soluzioni vere e scrittura nel file
    solx1 = input('Inserire la soluzione vera di x1 per questo test: ');
    solx2 = input('Inserire la soluzione vera di x2 per questo test: ');
    fprintf(file, 'Soluzione vera di x1: %f\n', solx1);
    fprintf(file, 'Soluzione vera di x2: %f\n', solx2);
    % esecuzione eq2grstabAll.m
    eq2grstabAll;
    % scrittura dati test nel file
    fprintf(file, 'Valori dei coefficienti: a=%f, b=%f, c=%f\n', a, b, c);
    fprintf(file, 'Valori delle radici: x1=%f, x2=%f\n', x1, x2);
    % calcolo degli errori relativi e scrittura nel file
    errore_relativo_x1 = ((abs(solx1 - x1)) / (abs(solx1))) * 100;
    errore_relativo_x2 = ((abs(solx2 - x2)) / (abs(solx2))) * 100;
    fprintf(file, 'Errore relativo di x1: %f%%\n', errore_relativo_x1);
    fprintf(file, 'Errore relativo di x2: %f%%\n', errore_relativo_x2);
end
% chiusura file
fclose(file);