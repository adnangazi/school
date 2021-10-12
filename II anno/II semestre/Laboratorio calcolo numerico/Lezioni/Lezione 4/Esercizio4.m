% Gazi Adnan Latif Matricola 1224442
clear all;
f = @(x) exp(1-1./x)-exp(1)+0.001;
df = @(x) exp(1-1./x)./(x.^2);

toll = 10^-12;
c=0.001;
a = 100;
b = 500;
x = linspace(a, b);
itmax = 100;
x0 = 200;
method1 = 's';
method2 = 'r';
xres = 1/(1-log(exp(1)-c));

figure(1);
hold on;
plot(x, f(x));
plot(x, df(x));
hold off;
title('f e fprimo');
legend('f', 'fprimo');

[zero1, res1, iterates1, flag] = Newton(f, df, x0, toll, itmax, method1);
[zero2, res2, wres2, iterates2, flag2] = Bisezione(f, a, b, toll, method2);

switch flag1
    case 's'
        fprintf('Uscita per test dello scarto:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-xres));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'r'
        fprintf('Uscita per test del residuo:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-xres));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'a'
        fprintf('Uscita causato da entrambi i test:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-xres));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'e'
        fprintf('Raggiunto il massimo numero di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-xres));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
    case 'f'
        fprintf('Residuo 0 in un numero finito di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero1);
        fprintf('Errore finale: %f\n', abs(zero1-xres));
        fprintf('Modulo del residuo: %f\n', res1);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates1, 1), size(iterates1, 2));
end

switch flag2
    case 's'
        fprintf('Uscita per test dello scarto:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Modulo del residuo pesato approssimato: %f\n', wres2);
        fprintf('Iterate del metodo di Bisezione: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'r'
        fprintf('Uscita per test del residuo pesato approssimato:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Modulo del residuo pesato approssimato: %f\n', wres2);
        fprintf('Iterate del metodo di Bisezione: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'b'
        fprintf('Uscita causato da entrambi i test:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Modulo del residuo pesato approssimato: %f\n', wres2);
        fprintf('Iterate del metodo di Bisezione: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'f'
        fprintf('Residuo 0 in un numero finito di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Modulo del residuo pesato approssimato: %f\n', wres2);
        fprintf('Iterate del metodo di Bisezione: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
end

err_res1 = abs(f(iterates1));
s1 = iterates1(2:end)-iterates1(1:end-1);
err1 = abs(xres-iterates1);

figure(2);
hold on;
semilogy(err_res1);
semilogy(s1);
semilogy(err1);
title('Semilogy residuo, scarto, errore');
legend('Residuo f', 'Scarto f', 'Errore f');
hold off;

figure(3);
hold on;
semilogy(abs(s1(2:end))./abs(s1(1:end-1)).^2);
title('|Sk+1|/|Sk|');
legend('|Sk+1|/|Sk|');
hold off;

figure(4);
hold on;
semilogy(err1(2:end)./abs(s1).^2);
title('Ek/|Sk|');
legend('Ek/|Sk|');
hold off;


err_iterates2 = abs(xres-iterates2(1, :));
s2 = iterates2(2:end)-iterates2(1:end-1);
err_res2 = abs(f(iterates2(1, :)));

figure(5);
semilogy(err_iterates2);
hold on;
semilogy(err_res2);
semilogy(s2);
hold off;
title('Grafico errore iterate e residui f');
legend('Errore iterate', 'Errore residui', 'Scarto f');

figure(6);
hold on;
semilogy(abs(s2(2:end))./abs(s2(1:end-1)).^2);
title('|Sk+1|/|Sk|');
legend('|Sk+1|/|Sk|');
hold off;

figure(7);
hold on;
semilogy(err_iterates2(2:end)./abs(s2).^2);
title('Ek/|Sk|');
legend('Ek/|Sk|');
hold off;

figure(8);
plot(err_iterates2./err_res2);
hold on;
plot(ones(size(err_iterates2))./df(2*xres));
title('Grafico rapporto errori e retta 1/fprimo(xres)');
legend('Errore iterate/Errore residui', '1/fprimo(xres)');