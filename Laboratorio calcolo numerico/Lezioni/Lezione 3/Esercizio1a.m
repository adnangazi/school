% Gazi Adnan Latif Matricola 1224442
f = @(x) ((exp(x)).*((x.^2)+1));
nodi = linspace(0, 1, 100);
H = figure(10);
hold on;
plot(nodi, f(nodi));
plot(nodi, Esercizio1b(nodi));
hold off;