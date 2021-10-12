% Gazi Adnan Latif Matricola 1224442
clear all;
f1=@(x) x.^2-2;
f2=@(x) 2.*x;
f3 = @(x) (x.^2-2).^3;
f4 = @(x) 6.*x.*(x.^2-2).^2;
f5 = @(x) (x.^2-2).^5;
f6 = @(x) 10.*x.*(x.^2-2).^4;

xstar=sqrt(2); 
toll=10^-7;
itmax=20;
x0=sqrt(2)-1+.001;
x1=sqrt(2)+1+.002;
method='s';
p_s=(1+sqrt(5))/2;

[zero_s1,res_s1,iterates_s1,flag_s1]=Secanti(f1,x0,x1,toll,itmax,method);
s_s1=iterates_s1(2:end)-iterates_s1(1:end-1);
err_s1=abs(xstar-iterates_s1);
fprintf('------------Metodo delle secanti-----------------------------\n')
fprintf('Numero di iterazioni = %d\n',length(iterates_s1));
fprintf('Ultimo scarto = %1.12g\n',abs(s_s1(end)));
fprintf('Ultima approssimazione = %1.12f\n',zero_s1);
fprintf('Ultimo errore = %1.15g\n',abs(zero_s1-xstar));
fprintf('Residuo = %1.12g\n',res_s1(end));
fprintf('termine algoritmo per:\n')
switch flag_s1
    case 's'
        fprintf('tolleranza raggiunta\n');
    case 'e'
        fprintf('numero di iterazioni\n');
end
[zero1,res1,iterates1,flag1]=Newton(f1,f2,x0,toll,itmax,method);
s1=iterates1(2:end)-iterates1(1:end-1);
err1=abs(iterates1-xstar);
fprintf('------------Metodo di Newton --------------------------------\n')
fprintf('Numero di iterazioni = %d\n',length(iterates1));
fprintf('Ultimo scarto = %1.12g\n',abs(s1(end)));
fprintf('Ultima approssimazione = %1.12f\n',zero1);
fprintf('Ultimo errore = %1.15g\n',abs(zero1-xstar));
fprintf('Residuo = %1.12g\n',res1(end));
fprintf('termine algoritmo per:\n')
switch flag1
    case 's'
        fprintf('tolleranza raggiunta\n');
    case 'e'
        fprintf('numero di iterazioni\n');
end

figure(1);
semilogy(err_s1);
hold on
semilogy(err1);
title('confronto degli errori')
legend('Secanti','Newton')
C_s1=abs(s_s1(2:end))./abs(s_s1(1:end-1)).^p_s;
C1=abs(s1(2:end))./(abs(s1(1:end-1)).^2);
figure(2);
plot(C_s1);
hold on
plot(C1)
plot(1:length(C_s1),0.*C_s1+1/2)
plot(1:length(C1),0.*C1+1/(2*sqrt(2)))
title('approssimazione delle costanti asintotiche')
legend('approx cost asintotica secanti','approx cost asintotica Newton',...
    'valore teorico secanti','valore teorico Newton')









[zero_s2,res_s2,iterates_s2,flag_s2]=Secanti(f3,x0,x1,toll,itmax,method);
s_s2=iterates_s2(2:end)-iterates_s2(1:end-1);
err_s2=abs(xstar-iterates_s2);
fprintf('------------Metodo delle secanti-----------------------------\n')
fprintf('Numero di iterazioni = %d\n',length(iterates_s2));
fprintf('Ultimo scarto = %1.12g\n',abs(s_s2(end)));
fprintf('Ultima approssimazione = %1.12f\n',zero_s2);
fprintf('Ultimo errore = %1.15g\n',abs(zero_s2-xstar));
fprintf('Residuo = %1.12g\n',res_s2(end));
fprintf('termine algoritmo per:\n')
switch flag_s2
    case 's'
        fprintf('tolleranza raggiunta\n');
    case 'e'
        fprintf('numero di iterazioni\n');
end
[zero2,res2,iterates2,flag2]=Newton(f3,f4,x0,toll,itmax,method);
s2=iterates2(2:end)-iterates2(1:end-1);
err2=abs(iterates2-xstar);
fprintf('------------Metodo di Newton --------------------------------\n')
fprintf('Numero di iterazioni = %d\n',length(iterates2));
fprintf('Ultimo scarto = %1.12g\n',abs(s2(end)));
fprintf('Ultima approssimazione = %1.12f\n',zero2);
fprintf('Ultimo errore = %1.15g\n',abs(zero2-xstar));
fprintf('Residuo = %1.12g\n',res2(end));
fprintf('termine algoritmo per:\n')
switch flag2
    case 's'
        fprintf('tolleranza raggiunta\n');
    case 'e'
        fprintf('numero di iterazioni\n');
end

figure(3);
semilogy(err_s2);
hold on
semilogy(err2);
title('confronto degli errori')
legend('Secanti','Newton')
C_s2=abs(s_s2(2:end))./abs(s_s2(1:end-1)).^p_s;
C2=abs(s2(2:end))./(abs(s2(1:end-1)).^2);
figure(4);
plot(C_s2);
hold on
plot(C2)
plot(1:length(C_s2),0.*C_s2+1/2)
plot(1:length(C2),0.*C2+1/(2*sqrt(2)))
title('approssimazione delle costanti asintotiche')
legend('approx cost asintotica secanti','approx cost asintotica Newton',...
    'valore teorico secanti','valore teorico Newton')








[zero_s3,res_s3,iterates_s3,flag_s3]=Secanti(f5,x0,x1,toll,itmax,method);
s_s3=iterates_s3(2:end)-iterates_s3(1:end-1);
err_s3=abs(xstar-iterates_s3);
fprintf('------------Metodo delle secanti-----------------------------\n')
fprintf('Numero di iterazioni = %d\n',length(iterates_s3));
fprintf('Ultimo scarto = %1.12g\n',abs(s_s3(end)));
fprintf('Ultima approssimazione = %1.12f\n',zero_s3);
fprintf('Ultimo errore = %1.15g\n',abs(zero_s3-xstar));
fprintf('Residuo = %1.12g\n',res_s3(end));
fprintf('termine algoritmo per:\n')
switch flag_s3
    case 's'
        fprintf('tolleranza raggiunta\n');
    case 'e'
        fprintf('numero di iterazioni\n');
end
[zero3,res3,iterates3,flag3]=Newton(f5,f6,x0,toll,itmax,method);
s3=iterates3(2:end)-iterates3(1:end-1);
err3=abs(iterates3-xstar);
fprintf('------------Metodo di Newton --------------------------------\n')
fprintf('Numero di iterazioni = %d\n',length(iterates3));
fprintf('Ultimo scarto = %1.12g\n',abs(s3(end)));
fprintf('Ultima approssimazione = %1.12f\n',zero3);
fprintf('Ultimo errore = %1.15g\n',abs(zero3-xstar));
fprintf('Residuo = %1.12g\n',res3(end));
fprintf('termine algoritmo per:\n')
switch flag3
    case 's'
        fprintf('tolleranza raggiunta\n');
    case 'e'
        fprintf('numero di iterazioni\n');
end

figure(5);
semilogy(err_s3);
hold on
semilogy(err3);
title('confronto degli errori')
legend('Secanti','Newton')
C_s3=abs(s_s3(2:end))./abs(s_s3(1:end-1)).^p_s;
C3=abs(s3(2:end))./(abs(s3(1:end-1)).^2);
figure(6);
plot(C_s3);
hold on
plot(C3)
plot(1:length(C_s3),0.*C_s3+1/2)
plot(1:length(C3),0.*C3+1/(2*sqrt(2)))
title('approssimazione delle costanti asintotiche')
legend('approx cost asintotica secanti','approx cost asintotica Newton',...
    'valore teorico secanti','valore teorico Newton')