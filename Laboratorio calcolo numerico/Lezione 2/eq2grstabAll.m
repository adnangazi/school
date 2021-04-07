format long;
fprintf('Risuluzione eq. secondo grado per qualsiasi coefficienti\n');
a = input('Inserire il valore di a: ');
b = input('Inserire il valore di b: ');
c = input('Inserire il valore di c: ');
% calcolo delle radici
    if a == 0
        if b == 0
            x1 = NaN;
            x2 = NaN;
            fprintf('Radici non definite!\n');
        else
            % equazione di primo grado
            x1 = -c / b;
            x2 = x1;
            fprintf('x1 = x2: %f\n', x2);
        end
    else
        % calcolo il discriminante
        delta = ((b^2) - (4 * a * c));
        if delta < 0
            x1 = NaN;
            x2 = NaN;
            fprintf('Radici non definite!\n');
        elseif delta == 0
            x1 = -b / (2 * a);
            x2 = x1;
            fprintf('x1 = x2: %f\n', x2);
        else
            delta = delta^(1/2);
            if b == 0
                x1 = (-(b + delta)) / (2 * a);
                x2 = ((-b) + delta) / (2 * a);
                fprintf('Valore della radice x1: %f\n', x1);
                fprintf('Valore della radice x2: %f\n', x2);
            else
                x1 = (-(b + sign(b) * delta) / (2 * a));
                x2 = c / (a * x1);
                fprintf('Valore della radice x1: %f\n', x1);
                fprintf('Valore della radice x2: %f\n', x2);
            end
        end
    end