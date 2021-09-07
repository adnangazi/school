% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% funzioni
f1 = @(x) x.^2-2;
f2 = @(x) 2.*x;
f3 = @(x) f1(x).^3;
f4 = @(x) 6.*x.*(f1(x)).^2;
f5 = @(x) f1(x).^5;
f6 = @(x) 10.*x.*(f1(x)).^4;

%% variabili globali
a = 1;
b = 2;
x = linspace(a, b);
solvera = sqrt(2);
x0 = 2;
toll = 10^-8;
itmax = 100;
method = 's';
m1 = 1;
m2 = 3;
m3 = 5;

%% plot funzioni e derivate
figure(1);
plot(x, f1(x));
hold on;
plot(x, f2(x));
title('Plot f1 e f2');
legend('f1', 'f2');
hold off;

figure(2);
plot(x, f3(x));
hold on;
plot(x, f4(x));
title('Plot f3 e f4');
legend('f3', 'f4');
hold off;

figure(3);
plot(x, f5(x));
hold on;
plot(x, f6(x));
title('Plot f5 e f6');
legend('f5', 'f6');
hold off;

%% calcolo zero di funzione
[zero1, res1, iterates1, flag1] = Newton(f1, f2, x0, toll, itmax, method);
[zero2, res2, iterates2, flag2] = Newton(f3, f4, x0, toll, itmax, method);
[zero3, res3, iterates3, flag3] = Newton(f5, f6, x0, toll, itmax, method);

%% calcolo p
if f2(zero1) ~= 0
    p1 = 2;
else
    p1 = 1;
end

if f4(zero2) ~= 0
    p2 = 2;
else
    p2 = 1;
end

if f6(zero3) ~= 0
    p3 = 2;
else
    p3 = 1;
end

%% stampa a video risulatati
switch flag1
    case 's'
        fprintf('Uscita per test dello scarto:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-solvera));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'r'
        fprintf('Uscita per test del residuo:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-solvera));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'a'
        fprintf('Uscita causato da entrambi i test:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-solvera));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'e'
        fprintf('Raggiunto il massimo numero di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-solvera));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'f'
        fprintf('Residuo 0 in un numero finito di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-solvera));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
end

switch flag2
    case 's'
        fprintf('Uscita per test dello scarto:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Errore finale: %f\n', abs(zero2-solvera));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'r'
        fprintf('Uscita per test del residuo:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Errore finale: %f\n', abs(zero2-solvera));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'a'
        fprintf('Uscita causato da entrambi i test:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Errore finale: %f\n', abs(zero2-solvera));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'e'
        fprintf('Raggiunto il massimo numero di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Errore finale: %f\n', abs(zero2-solvera));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'f'
        fprintf('Residuo 0 in un numero finito di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Errore finale: %f\n', abs(zero2-solvera));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
end

switch flag3
    case 's'
        fprintf('Uscita per test dello scarto:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-solvera));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
    case 'r'
        fprintf('Uscita per test del residuo:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-solvera));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
    case 'a'
        fprintf('Uscita causato da entrambi i test:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-solvera));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
    case 'e'
        fprintf('Raggiunto il massimo numero di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-solvera));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
    case 'f'
        fprintf('Residuo 0 in un numero finito di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-solvera));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
end

%% grafici semilogaritmici
r1 = abs(f1(iterates1));
r2 = abs(f3(iterates2));
r3 = abs(f5(iterates3));

s1 = abs(iterates1(2:end) - iterates1(1:end-1));
s2 = abs(iterates2(2:end) - iterates2(1:end-1));
s3 = abs(iterates3(2:end) - iterates3(1:end-1));

e1 = abs(iterates1 - solvera);
e2 = abs(iterates2 - solvera);
e3 = abs(iterates3 - solvera);

figure(4);
semilogy(r1);
hold on;
semilogy(r2);
semilogy(r3);
semilogy(s1);
semilogy(s2);
semilogy(s3);
semilogy(e1);
semilogy(e2);
semilogy(e3);
title('Errori');
legend('r1', 'r2', 'r3', 's1', 's2', 's3', 'e1', 'e2', 'e3');
hold off;

figure(5);
semilogy(abs(s1(2:end))./abs(s1(1:end-1)).^p1);
hold on;
semilogy(abs(s2(2:end))./abs(s2(1:end-1)).^p2);
semilogy(abs(s3(2:end))./abs(s3(1:end-1)).^p3);
title('Ordine di convergenza');
legend('o1', 'o2', 'o3');
hold off;


figure(6);
semilogy(e1(2:end)./abs(s1).^p1);
hold on;
semilogy(e2(2:end)./abs(s2).^p2);
semilogy(e3(2:end)./abs(s3).^p3);
title('Rapporto');
legend('es1', 'es2', 'es3');
hold off;