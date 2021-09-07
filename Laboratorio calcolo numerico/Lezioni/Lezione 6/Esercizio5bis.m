% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

f = @(x, al) abs(x).^al;
alfa = [2/3, 1, 5/4, 3/2];
a = -1;
b = 1;
k = 5000;
degs = 2:2:50;
xeval = linspace(a, b, k+1);
e = zeros(length(degs), length(alfa));
i = 1;

for m = degs
   j = 1;
   for a = alfa
       c = polyfit(xeval, f(xeval, a), m);
       p = polyval(c, xeval);
       e(i, j) = max(abs(p - f(xeval, a)));
       j = j + 1;
   end
   i = i + 1;
end

figure(1);
semilogy(degs, e);
title('Plot 1');
legend('e');

figure(2);
semilogy(degs, e.^(1./alfa));
title('Plot 2');
legend('e^1^/^a');
