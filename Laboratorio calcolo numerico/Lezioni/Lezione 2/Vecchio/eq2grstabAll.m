% impostazione formato
format long;
% titolo programma
fprintf('Risuluzione eq. secondo grado per qualsiasi coefficienti\n');
% inserimento dei coefficienti
a = input('Inserire il valore di a: ');
b = input('Inserire il valore di b: ');
c = input('Inserire il valore di c: ');
% calcolo delle radici
if a == 0
    % equazione di grado massimo a 1
    if b == 0
        % equazione di grado 0
        % calcolo delle radici x1 x2 e visualizzazione a video
        x1 = NaN;
        x2 = NaN;
        fprintf('Radici non definite!\n');
    else
        % equazione di primo grado
        % calcolo delle radici x1 x2 e visualizzazione a video
        x1 = -c / b;
        x2 = x1;
        fprintf('x1 = x2: %f\n', x2);
    end
else
    % equazione di secondo grado
    % calcolo del discriminante
    delta = ((b^2) - (4 * a * c));
    if delta < 0
        % delta negativo
        % calcolo delle radici x1 x2 e visualizzazione a video
        x1 = NaN;
        x2 = NaN;
        fprintf('Radici non definite!\n');
    elseif delta == 0
        % delta uguale a zero
        % calcolo delle radici x1 = x2 e visualizzazione a video
        x1 = -b / (2 * a);
        x2 = x1;
        fprintf('x1 = x2: %f\n', x2);
    else
        % delta positivo
        delta = delta^(1/2);
        if b == 0
            % utilizzo delle formule standard
            % calcolo delle radici x1 x2 e visualizzazione a video
            x1 = (-(b + delta)) / (2 * a);
            x2 = ((-b) + delta) / (2 * a);
            fprintf('Valore della radice x1: %f\n', x1);
            fprintf('Valore della radice x2: %f\n', x2);
        else
            % utilizzo delle formule stabili
            % calcolo delle radici x1 x2 e visualizzazione a video
            x1 = (-(b + sign(b) * delta) / (2 * a));
            x2 = c / (a * x1);
            fprintf('Valore della radice x1: %f\n', x1);
            fprintf('Valore della radice x2: %f\n', x2);
        end
    end
end