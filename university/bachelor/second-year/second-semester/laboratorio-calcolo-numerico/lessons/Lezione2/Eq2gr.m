% Adnan Latif Gazi Matricola 1224442
format long;
fprintf('Risoluzione eq. secondo grado\n');
a = input('Inserire coefficiente a: ');
b = input('Inserire coefficiente b: ');
c = input('Inserire coefficiente c: ');
if a == 0 || b == 0 || c == 0 
    fprintf('Errore nell inserimento dei coefficienti!\n');
else
    delta = sqrt(b^2 - 4 * a * c);
    if delta < 0
        x1 = NaN;
        x2 = NaN;
        fprintf('Nessuna soluzione reale. x1 = %f, x2 = %f\n', x1, x2);
    elseif delta == 0
        x1 = ((-b) / (2 * a));
        x2 = x1;
        fprintf('Due soluzioni reali coincidenti. x1 = x2 = %f\n', x1);
    else 
        x1 = ((-b - delta) / (2 * a));
        x2 = ((-b + delta) / (2 * a));
        fprintf('x1 e x2 reali e distinte. x1 = %f, x2 = %f\n', x1, x2);
    end
end