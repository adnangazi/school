% Gazi Adnan Latif Matricola 1224442
clear all;
f1 = @(x) x.^2-2;
f2 = @(x) (x.^2-2).^3;

a = 1;
b = 2;
toll1 = 10^-12;
toll2 = 10^-4;
x = linspace(a, b);
y = 0.*x;
method = 'm';

figure(1);
plot(x, f1(x));
hold on;
plot(x, y);
hold off;
title('Grafico f1 e retta y=0 in [1,2]');
legend('f1(x)=x^2-2', 'y=0');

figure(2);
plot(x, f2(x));
hold on;
plot(x, y);
hold off;
title('Grafico f2 e retta y=0 in [1,2]');
legend('f2(x)=x^2-2', 'y=0');

[zero1, res1, wres1, iterates1, flag1] = Bisezione(f1, a, b, toll1, method);
[zero2, res2, wres2, iterates2, flag2] = Bisezione(f2, a, b, toll2, method);

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

err_iterates1 = abs(zero1-iterates1(1, :));
err_res1 = abs(f1(iterates1(1, :)));
figure(3);
semilogy(err_iterates1);
hold on;
semilogy(err_res1);
hold off;
title('Grafico errore iterate e residui f1');
legend('Errore iterate', 'Errore residui');

err_iterates2 = abs(zero2-iterates2(1, :));
err_res2 = abs(f2(iterates2(1, :)));
figure(4);
semilogy(err_iterates2);
hold on;
semilogy(err_res2);
hold off;
title('Grafico errore iterate e residui f2');
legend('Errore iterate', 'Errore residui');

figure(5);
plot(err_iterates1./err_res1);
hold on;
plot(ones(size(err_iterates1))./(2*sqrt(2)));
title('Grafico rapporto errori e retta 1/fprimo(sqrt(2))');
legend('Errore iterate/Errore residui', '1/fprimo(sqrt(2))');

figure(6);
plot(err_iterates2./err_res2);
hold on;
plot(ones(size(err_iterates2))./(2*sqrt(2)));
title('Grafico rapporto errori e retta 1/fprimo(sqrt(2))');
legend('Errore iterate/Errore residui', '1/fprimo(sqrt(2))');
