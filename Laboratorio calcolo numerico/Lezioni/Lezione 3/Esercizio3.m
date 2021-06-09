clear all; % pulizia workspace

% vettore riga di 100 valori pseudocasuali per le ascisse di f
x1 = randn(100, 1);
% vettore riga di 100 valori pseudocasuali per le ascisse di g
x2 = randn(100, 1);

% anonymous function per restituire vettore riga di 100 valori pseudocasuali per le ordinate sia di f che di g
myFun = @(x) randn(100, 1); 

% creazione plot di f
f = PlotAsIWant(x1, myFun, 1, ' Funzione f ', '.', 'figura della funzione f', 'eps' , 0) 
% creazione plot di g
g = PlotAsIWant(x2, myFun, 2, ' Funzione g ', '.', 'figura della funzione g', 'eps' , 0) 