% Adnan Latif Gazi Matricola 1224442
clear all;
ntest = input('Inserire il numero di test da effettuare: ');
for i = 1:ntest
    x1vera = input('Inserire il valore di x1vero: ');
    x2vera = input('Inserire il valore di x2vero: ');
    Eq2grst;
    fprintf('Errori relativi: errx1 = %f, errx2= %f\n', (abs((x1 - x1vera)/x1vera)), (abs((x2 - x2vera)/x2vera)));
end