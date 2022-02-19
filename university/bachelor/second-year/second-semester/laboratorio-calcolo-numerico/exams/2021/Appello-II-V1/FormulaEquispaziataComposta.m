% Adnan Latif Gazi Matricola 1224442
function [x, w] = FormulaEquispaziataComposta (a, b, N, n)
    p = linspace(a, b, N + 1); % griglia degli N + 1 sottointervalli
    x = []; % vettore riga di Nn + 1 nodi equispaziati inizialmente vuoto
    w = []; % vettore colonna di Nn + 1 pesi per ogni nodo inizialmente vuoto
    riporto = 0; % riporto iniziale nullo perchè inizialmente vettore dei pesi è vuoto
    
    for k = 1:N % per ogni sottointervallo
        [xtemp, wtemp] = FormulaEquispaziata(p(k), p(k + 1), n); % n + 1 nodi e pesi dell'intervallo attuale
        % assemblaggio con i nodi e i pesi precedenti
        if k == 1 % nessun riporto e niente da assemblare
            x = xtemp;
            w = wtemp;
            riporto = wtemp(end); % riporto per il prossimo sottointervallo
        else
            wtemp(1) = wtemp(1) + riporto; % aggiungo il riporto del precedente intervallo
            riporto = wtemp(end); % riporto per il prossimo sottointervallo
            x = [x(1, 1:end - 1), xtemp]; % tolgo l'ultimo elemento del vettore risultato del sottointervallo precedente
            w = [w(1:end - 1); wtemp]; % tolgo l'ultimo elemento del vettore risultato del sottointervallo precedente
        end
    end
end