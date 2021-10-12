% Adnan Latif Gazi Matricola 1224442
if a == 0
    if b == 0
        x1 = NaN;
        x2 = NaN;
        fprintf('x1 = %f, x2 = %f\n', x1, x2);
    else
        x1 = -c/b;
        x2 = x1;
        fprintf('x1 = %f, x2 = %f\n', x1, x2);
    end
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
        if b == 0
            x1 = ((-delta) / (2 * a));
            x2 = ((delta) / (2 * a));
            fprintf('x1 e x2 reali e distinte con b == 0 ==> formule instabili. x1 = %f, x2 = %f\n', x1, x2);
        else
            x1 = (-(b+sign(b)*sqrt(delta))/(2*a));
            x2 = ((c)/(a*x1));
            fprintf('x1 e x2 reali e distinte con b ~= 0 ==> formule stabili. x1 = %f, x2 = %f\n', x1, x2);
        end
    end
end