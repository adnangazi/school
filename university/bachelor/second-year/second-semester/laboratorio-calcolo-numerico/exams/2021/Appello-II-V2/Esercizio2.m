% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% funzione
f = @(x) 1 ./ (1 + x .^ 2);

%% variabili globali
degs = 4:50;
a = -1; b = 1;
pval = 10000;
xeval = linspace(a, b, pval)';
feval = f(xeval);
i = 1;
err_p1 = zeros(1, length(degs));
err_p2 = zeros(1, length(degs));
err_p3 = zeros(1, length(degs));
err_p4 = zeros(1, length(degs));

%% corpo dell'esperimento
for n = degs
    m = n .^ 2;
    xinterp = linspace(a, b, m)';
    yinterp = f(xinterp);
    [peval1, coeff1] = MyFit(xinterp, yinterp, n, xeval, 1);
    [peval2, coeff2] = MyFit(xinterp, yinterp, n, xeval, 2);
    [peval3, coeff3] = MyFit(xinterp, yinterp, n, xeval, 3);
    [peval4, coeff4] = MyFit(xinterp, yinterp, n, xeval, 4);
    
    err_p1(i) = max(abs(peval1 - feval));
    err_p2(i) = max(abs(peval2 - feval));
    err_p3(i) = max(abs(peval3 - feval));
    err_p4(i) = max(abs(peval4 - feval));
    i = i + 1;
end

%% plot
figure(1);
semilogy(degs, err_p1, 'b');
hold on;
semilogy(degs, err_p2, 'r');
semilogy(degs, err_p3, 'g');
semilogy(degs, err_p4, 'm');
title('Max err approx pt val');
legend('p1', 'p2', 'p3', 'p4');
hold off;

%% commento ai risultati
fprintf('COMMENTO AI RISULTATI:\n');
fprintf('Si nota innanzitutto che tutti i polinomi, indipendentemente dal metodo usato, presentano un errore maggiore per gradi bassi e un errore sempre minore (più o meno veloce a seconda del metodo) mano a mano che i gradi aumentano.');
fprintf(' Come si può vedere dal grafico, il metodo migliore per interpolare e valutare un polinomio è mediante l utilizzo delle funzioni polyfit e polyval: questo perchè interpolare e valutare il polinomio in questo modo risulta esser più semplice, facile e veloce rispetto agli altri metodi.');
fprintf(' Inoltre, questo metodo è quello tra tutti che commete mediamente l errore minore: questo perchè le funzioni polyfit e polyval sono messe a disposizione da matlab appositamente per interpolaere e valutare una funzione (e quindi sono ottimizzate per commettere un errore minimo).');
fprintf(' Mentre tutti gli altri metodi richiedono la risoluzione di un sistema lineare; operazione che porta a commettere più errori di calcolo a causa di un maggior numeor di operazioni e ad una conseguente maggiore approssimazione dei risultati intermedi e finali.\n');