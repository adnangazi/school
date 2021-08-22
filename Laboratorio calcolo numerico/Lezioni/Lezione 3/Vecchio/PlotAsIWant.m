% x: asse delle ascisse
% f: function handle della funzione da valutare e plottare
% fig_number: numero della figura dove produrre il grafico
% varargin: titolo_grafico, specifica_grafica, nome_figura,
% opzione_salvataggio, flag_chiusura
function [varargout] = PlotAsIWant(x, f, fig_number, varargin)

% imposto il numero della figura dove produrre il grafico
myfig = figure(fig_number);

% parametro per specifica grafica plot
if nargin >= 5
    plot(x, f(x), varargin{2}); % f --> f(x). creazione plot con tale grafica
else
    plot(x, f(x)); % f --> f(x). creazione plot con grafica standard
end

% parametro titolo
if nargin >= 4
    title(varargin{1}); % assegno titolo a figura
end

% parametro salvataggio formato .fig di default
if (nargin == 6) || (nargin >= 7)
    savefig(myfig, [varargin{3} '.fig']) % salvo in formato .fig di default
end

% parametro salvataggio formato .eps su richiesta
if nargin >= 7 && (strcmp(varargin{4}, 'eps') || strcmp(varargin{4}, 'entrambi'))
    hgexport(myfig, [varargin{3} '.eps']) % salvo in formato .eps su richiesta
end

% composizione output in base al tipo di salvataggio fatto
if nargout == 1
    % salvataggio in entrambi i formati
    if nargin >= 7 && strcmp(varargin{4}, 'entrambi')
        % composizione output per salvataggio in entrambi i formati
        varargout{1} = ['Salvata figura ' num2str(fig_number) ' in' varargin{3} '.fig' ' e in' varargin{3} '.eps'];
    elseif nargin >= 7 && strcmp(varargin{4}, 'eps') % salvataggio solo in formato .eps
        % composizione output per salvataggio solo in formato .eps
        varargout{1} = ['Salvata figura ' num2str(fig_number) ' in' varargin{3} '.eps'];
    elseif nargin == 6 % salvataggio solo in formato .fig
        % composizione output per salvataggio solo in formato .fig
        varargout{1} = ['Salvata figura ' num2str(fig_number) ' in' varargin{3} '.fig'];
    else % non richiesto il salvataggio
        % composizione output per non salvataggio
        varargout{1} = ['Non salvata figura ' num2str(fig_number)];
    end
end

% parametro flag chiusura e valore flag
if nargin >= 8 && varargin{5}
    close(myfig) % chiusura figura dopo salvataggio
end