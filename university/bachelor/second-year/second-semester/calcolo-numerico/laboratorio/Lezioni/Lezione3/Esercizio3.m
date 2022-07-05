% Gazi Adnan Latif Matricola 1224442
clear all;
f = @(x) ((exp(x)).*((x.^2)+1));
g = @(x) ((exp(x))./((x.^2)+1));
x = linspace(0, 1, 100);
hold on;
PlotAsIWant(x, f, 1, 'Grafico unico', '-.', 'GraficoFunico', 1, false);
PlotAsIWant(x, g, 1, 'Grafico unico', '-.', 'GraficoGunico', 1, false);
hold off;
PlotAsIWant(x, f, 2, 'Grafico di F', '-.', 'GraficoF', 1, true);
PlotAsIWant(x, g, 3, 'Grafico di G', '-.', 'GraficoG', 1, true);