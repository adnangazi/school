% Gazi Adnan Latif Matricola 1224442
clear all;
f1 = @(x) x.^2-2;
f2 = @(x) 2.*x;
f3 = @(x) (x.^2-2).^3;
f4 = @(x) 6.*x.*(x.^2-2).^2;
f5 = @(x) (x.^2-2).^5;
f6 = @(x) 10.*x.*(x.^2-2).^4;

a = 1;
b = 2;
x = linspace(a, b);
method = 's';
x0 = 2;
toll = 10^-8;
itmax = 100;
xres = sqrt(2);

figure(1);
hold on;
plot(x, f1(x));
plot(x, f2(x));
hold off;
title('f1 e fprimo1');
legend('f1', 'fprimo1');

figure(2);
hold on;
plot(x, f3(x));
plot(x, f4(x));
hold off;
title('f3 e fprimo3');
legend('f3', 'fprimo3');

figure(3);
hold on;
plot(x, f5(x));
plot(x, f6(x));
hold off;
title('f5 e fprimo5');
legend('f5', 'fprimo5');

[zero1, res1, iterates1, flag1] = Newton(f1, f2, x0, toll, itmax, method);
[zero2, res2, iterates2, flag2] = Newton(f3, f4, x0, toll, itmax, method);
[zero3, res3, iterates3, flag3] = Newton(f5, f6, x0, toll, itmax, method);

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
        fprintf('Errore finale: %f\n', abs(zero2-xres));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'r'
        fprintf('Uscita per test del residuo:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Errore finale: %f\n', abs(zero2-xres));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'a'
        fprintf('Uscita causato da entrambi i test:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Errore finale: %f\n', abs(zero2-xres));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'e'
        fprintf('Raggiunto il massimo numero di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Errore finale: %f\n', abs(zero2-xres));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
    case 'f'
        fprintf('Residuo 0 in un numero finito di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero2);
        fprintf('Errore finale: %f\n', abs(zero2-xres));
        fprintf('Modulo del residuo: %f\n', res2);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates2, 1), size(iterates2, 2));
end

switch flag3
    case 's'
        fprintf('Uscita per test dello scarto:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-xres));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
    case 'r'
        fprintf('Uscita per test del residuo:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-xres));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
    case 'a'
        fprintf('Uscita causato da entrambi i test:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-xres));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
    case 'e'
        fprintf('Raggiunto il massimo numero di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-xres));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
    case 'f'
        fprintf('Residuo 0 in un numero finito di iterazioni:\n');
        fprintf('Ultima approssimazione della radice: %f\n', zero3);
        fprintf('Errore finale: %f\n', abs(zero3-xres));
        fprintf('Modulo del residuo: %f\n', res3);
        fprintf('Iterate del metodo di Newton: [%fx%f]\n', size(iterates3, 1), size(iterates3, 2));
end

err_res1 = abs(f1(iterates1));
err_res2 = abs(f3(iterates2));
err_res3 = abs(f5(iterates3));

s1 = iterates1(2:end)-iterates1(1:end-1);
s2 = iterates2(2:end)-iterates2(1:end-1);
s3 = iterates3(2:end)-iterates3(1:end-1);

err1 = abs(xres-iterates1);
err2 = abs(xres-iterates2);
err3 = abs(xres-iterates3);

figure(4);
hold on;
semilogy(err_res1);
semilogy(err_res2);
semilogy(err_res3);
semilogy(s1);
semilogy(s2);
semilogy(s3);
semilogy(err1);
semilogy(err2);
semilogy(err3);
title('Semilogy residuo, scarto, errore');
legend('Residuo f1', 'Residuo f3', 'Residuo f5', 'Scarto f1', 'Scarto f3', 'Scarto f5', 'Errore f1', 'Errore f3', 'Errore f5');
hold off;

figure(5);
hold on;
semilogy(abs(s1(2:end))./abs(s1(1:end-1)).^2);
semilogy(abs(s2(2:end))./abs(s2(1:end-1)));
semilogy(abs(s3(2:end))./abs(s3(1:end-1)));
title('|Sk+1|/|Sk|');
legend('|S1k+1|/|S1k|', '|S2k+1|/|S2k|', '|S3k+1|/|S3k|');
hold off;

figure(6);
hold on;
semilogy(err1(2:end)./abs(s1).^2);
semilogy(err2(2:end)./abs(s2));
semilogy(err3(2:end)./abs(s3));
title('Ek/|Sk|');
legend('E1k/|S1k|', 'E1k/|S2k|', 'E1k/|S3k|');
hold off;