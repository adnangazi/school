% Gazi Adnan Latif Matricola 1224442
clear all;
f1 = @(x) x.^2-2;
f2 = @(x) 2.*x;
df2 = @(x) 2;
f3 = @(x) (x.^2-2).^3;
f4 = @(x) 6.*x.*(x.^2-2).^2;
df4 = @(x) 6*f1(x).*(f2(x).^2)+3.*f1(x).^2.*2;
f5 = @(x) (x.^2-2).^5;
f6 = @(x) 10.*x.*(x.^2-2).^4;
df6 = @(x) 20*f1(x).^3.*(f2(x).^2)+5.*f1(x).^4.*2;

x = linspace(1, 2);
xvera = sqrt(2);

phi1 = MappaNewton(f1, f2, x);
phi2 = MappaNewtonDer(f1, f2, df2, x);
xvera1 = MappaNewtonDer(f1, f2, df2, xvera);

phi3 = MappaNewton(f3, f4, x);
phi4 = MappaNewtonDer(f3, f4, df4, x);
phi5 = MappaNewtonMod(f3, f4, 3, x);
phi6 = MappaNewtonModDer(f3, f4, df4, 3, x);
xvera2 = MappaNewtonDer(f3, f4, df4, xvera);

phi7 = MappaNewton(f5, f6, x);
phi8 = MappaNewtonDer(f5, f6, df6, x);
phi9 = MappaNewtonMod(f5, f6, 5, x);
phi10 = MappaNewtonModDer(f5, f6, df6, 5, x);
xvera3 = MappaNewtonDer(f5, f6, df6, xvera);

figure(1);
hold on;
plot(x, x);
plot(x, phi1);
plot(x, phi2);
plot(xvera, xvera1, 'o');
title('m=2');
legend('diagonale', 'Mappa Newton', 'Mappa Newton derivata', 'marker');
hold off;

figure(2);
hold on;
plot(x, x);
plot(x, phi3);
plot(x, phi4);
plot(x, phi5);
plot(x, phi6);
plot(xvera, xvera2, 'o');
title('m=3');
legend('diagonale', 'Mappa Newton', 'Mappa Newton derivata', 'marker');
hold off;

figure(3);
hold on;
plot(x, x);
plot(x, phi7);
plot(x, phi8);
plot(x, phi9);
plot(x, phi10);
plot(xvera, xvera3, 'o');
title('m=5');
legend('diagonale', 'Mappa Newton', 'Mappa Newton derivata', 'marker');
hold off;