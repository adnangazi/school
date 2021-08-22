% Adnan Latif Gazi Matricola 1224442
clear all;
ntest = input('Inserire il numero di test da effettuare: ');
f = fopen('main3result.txt', 'w');
fprintf(f, 'Test a        b        c        x1vera   x2vera   x1        x2        errx1    errx2\n');
for i = 1:ntest
    x1vera = input('Inserire il valore di x1vero: ');
    x2vera = input('Inserire il valore di x2vero: ');
    a = input('Inserire coefficiente a: ');
    b = input('Inserire coefficiente b: ');
    c = input('Inserire coefficiente c: ');
    Eq2grstaball;
    errx1 = (abs((x1 - x1vera)/x1vera));
    errx2 = (abs((x2 - x2vera)/x2vera));
    fprintf('Errori relativi: errx1 = %f, errx2= %f\n', errx1, errx2);
    fprintf(f, '  %1.0f: %f %f %f %f %f %f %f %f %f\n', i, a, b, c, x1vera, x2vera, x1, x2, errx1, errx2);
end
fclose(f);