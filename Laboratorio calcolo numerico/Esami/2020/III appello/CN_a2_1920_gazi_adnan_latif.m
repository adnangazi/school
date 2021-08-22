% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% funzione e primitiva
f = @(x) (5/2).*(x.^4) - (15/2).*(x.^2) + (4.*x) - 1;
F = @(x) x; % necessario al calcolo dell'integrale vero ed errore assoluto tra esso e il metodo dei trapezi

%% variabili globali
m = 2; % numero di sottointervalli
esp = 1024; % massimo numero di sottointervalli
lung = log2(esp); % numero di esperimenti da fare in base alla lunghezza dei sottointervalli e al loro variare
a = -1; b = 2; % estremi di intergrazione
x = linspace(a, b); % asse x necessario per il grafico della funzione
intvero = F(b) - F(a); % valore dell'integrale vero calcolata con l'integrale della funzione degli estremi dell'intervallo
zero = sqrt(2); % zero di funzione calcolato visualizzando il grafico della funzione
intveron = F(b) - F(zero); % valore dell'integrale vero della parte negatiava calcolata con l'integrale della funzione degli estremi dell'intervallo in cui la funzione è negativa
intverop = F(zero) - F(a); % valore dell'integrale vero della parte positiva calcolata con l'integrale della funzione degli estremi dell'intervallo in cui la funzione è positiva
toll = 10^-8; % tolleranza per il metodo di bisezione
method = 'm'; % metodo (minimo tra scarto e residuo pesato approssimato) per il metodo di bisezione

% vettori per salvare i risultati ad ogni esperimento
intval = zeros(1, lung); % integrale calcolato con trapezi
hval = zeros(1, lung); % passo di integrazione secondo trapezi
intvaln = zeros(1, lung); % integrale calcolato della parte negatiava con trapezi
hvaln = zeros(1, lung); % passo di integrazione della parte negatiava secondo trapezi
intvalp = zeros(1, lung); % integrale calcolato della parte positiva con trapezi
hvalp = zeros(1, lung); % passo di integrazione della parte positiva secondo trapezi
errintval = zeros(1, lung); % errore assoluto tra integrale vero e quello calcolato
errintvaln = zeros(1, lung); % errore assoluto tra integrale vero della parte negativa e quello calcolato della parte negativa
errintvalp = zeros(1, lung); % errore assoluto tra integrale vero della parte positiva e quello calcolato della parte positiva
i = 1; % indice per scorrere i vettori


%% plot funzione e assi cartesiani
figure(1);
plot(x, f(x), 'b'); % funzione linea continua in blu
hold on;
plot(x, zeros(1, length(x)), '--y'); % asse x linea tratteggiata in giallo
plot(zeros(1, length(x)), f(x), '--y'); % asse y linea tratteggiata in giallo
title('Grafico funzione');
legend('funzione', 'asse x', 'asse y');
hold off;

%% corpo dell'esperimento
file = fopen('tab_err.txt', 'w');
fprintf(file, 'TAB ERR\n');
while m <= 1024
    [int, h, xint] = Trapezi(f, a, b, m);
    [intn, hn, xintn] = Trapezi(f, a, zero, m);
    [intp, hp, xintp] = Trapezi(f, zero, b, m);
    intval(i) = int;
    hval(i) = h;
    intvaln(i) = intn;
    hvaln(i) = hn;
    intvalp(i) = intp;
    hvalp(i) = hp;
    errintval(i) = abs(intvero - intval(i));
    errintvaln(i) = abs(intveron - intvaln(i));
    errintvalp(i) = abs(intverop - intvalp(i));
    fprintf(file, '%4.0f:\t%f\n', m, errintval(i));
    fprintf(file, '%4.0f:\t%f (neg)\n', m, errintvaln(i));
    fprintf(file, '%4.0f:\t%f (pos)\n', m, errintvalp(i));
    fprintf(file, '\n');
    i = i + 1;
    m = m * 2;
end
fclose(file);

%% plot velocità di convergenza, passo di convergenza e integali calcolati
figure(2); % trapezi
plot(errintval, 'b'); % velocità di convergenza linea continua blu
hold on;
plot(errintvaln, 'r'); % velocità di convergenza della parte negativa linea continua rossa
plot(errintvalp, 'm'); % velocità di convergenza della parte positiva  linea continua magenta
plot(hval, '--b'); % passo di convergenza linea tratteggiata blu
plot(hvaln, '--r'); % passo di convergenza della parte negativa linea tratteggiata rossa
plot(hvalp, '--m'); % passo di convergenza della parte positiva linea tratteggiata magenta
plot(intval, 'ob'); % passo di convergenza cerchi blu
plot(intvaln, 'or'); % passo di convergenza della parte negativa cerchi rossi
plot(intvalp, 'om'); % passo di convergenza della parte positiva cerchi magenta
title('Velocità di convergenza, passo di convergenza e integali calcolati');
hold off;

%% calcolo zero di funzione
[zero1, res1, wres1, iterates1, flag1] = Bisezione(f, a, b, toll, method);

%% stampa risultati
switch flag1
    case 's'
        fprintf('Uscita per test dello scarto:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Modulo del residuo pesato approssimato: %f\n', wres1);
        fprintf('Iterate del metodo di Bisezione: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'r'
        fprintf('Uscita per test del residuo pesato approssimato:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Modulo del residuo pesato approssimato: %f\n', wres1);
        fprintf('Iterate del metodo di Bisezione: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'b'
        fprintf('Uscita causato da entrambi i test:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Modulo del residuo pesato approssimato: %f\n', wres1);
        fprintf('Iterate del metodo di Bisezione: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'f'
        fprintf('Residuo 0 in un numero finito di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Modulo del residuo pesato approssimato: %f\n', wres1);
        fprintf('Iterate del metodo di Bisezione: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
end