clear all;
% numero casi test
ind = input('Inserire il numero di casi test che si vogliono eseguire: ');
% ciclo sui casi test
for i = 1:ind
    % inserimento soluzioni vere
    solx1 = input('Inserire la soluzione vera di x1 per questo test: ');
    solx2 = input('Inserire la soluzione vera di x2 per questo test: ');
    % esecuzione eq2gr.m
    eq2grstabAll;
    % calcolo degli errori relativi
    errore_relativo_x1 = ((abs(solx1 - x1)) / (abs(solx1))) * 100;
    errore_relativo_x2 = ((abs(solx2 - x2)) / (abs(solx2))) * 100;
    fprintf('Errore relativo di x1: %f%%\n', errore_relativo_x1);
    fprintf('Errore relativo di x2: %f%%\n', errore_relativo_x2);
end