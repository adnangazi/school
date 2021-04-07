format long;
fprintf('Risuluzione eq. secondo grado\n');
a = input('Inserire il valore di a: ');
b = input('Inserire il valore di b: ');
c = input('Inserire il valore di c: ');
if (a == 0 || b == 0 || c == 0)
    % messaggio di errore
    fprintf('Errore: i coefficienti non possono essere nulli!\n');
else
    % calcolo delle radici
    % calcolo della discriminante
    delta = ((b^2) - (4 * a * c));
    if delta < 0
        % delta negativo
        fprintf('Delta negativo\n');
    elseif delta > 0
        % delta positivo
        fprintf('Delta positivo\n');
        delta = delta^(1/2);
        % calcolo di x1 e x2
        x1 = (-(b + delta)) / (2 * a);
        x2 = ((-b) + delta) / (2 * a);
        fprintf('Valore della radice x1: %f\n', x1);
        fprintf('Valore della radice x2: %f\n', x2);
    else
        % delta uguale a zero
        fprintf('Delta uguale a zero\n');
        delta = delta^(1/2);
        x = (-b) / (2 * a);
        fprintf('Valore della radice: %f\n', x);
    end
end