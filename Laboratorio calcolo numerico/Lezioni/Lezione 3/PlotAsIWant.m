% Gazi Adnan Latif Matricola 1224442
function [varargout] = PlotAsIWant(x, f, n, varargin)
    H = figure(n);
    switch nargin
        case 3
            plot(x, f(x));
        case 4
            title(varargin{1});
            plot(x, f(x), varargin{2});
        case 5
            title(varargin{1});
            plot(x, f(x), varargin{2});
        case 6
            title(varargin{1});
            plot(x, f(x), varargin{2});
            savefig(H, [varargin{3} '.fig']);
        case 7
            title(varargin{1});
            plot(x, f(x), varargin{2});
            if varargin{4} == 0 % varargin{4} == 0 ==> salvataggio in formato fig
                savefig(H, [varargin{3} '.fig']);
            elseif varargin{4} == 1 % varargin{4} == 1 ==> salvataggio in formato eps
                hgexport(H, [varargin{3} '.eps']);
            else % altrimenti ==> salvataggio in entrambi i formati
                savefig(H, [varargin{3} '.fig']);
                hgexport(H, [varargin{3} '.eps']);
            end
        case 8
            title(varargin{1});
            plot(x, f(x), varargin{2});
            if varargin{4} == 0 % varargin{4} == 0 ==> salvataggio in formato fig
                savefig(H, [varargin{3} '.fig']);
            elseif varargin{4} == 1 % varargin{4} == 1 ==> salvataggio in formato eps
                hgexport(H, [varargin{3} '.eps']);
            else % altrimenti ==> salvataggio in entrambi i formati
                savefig(H, [varargin{3} '.fig']);
                hgexport(H, [varargin{3} '.eps']);
            end
            if varargin{5} == true
                close(H);
            end
    end
    if nargout == 1
        varargout{1} = ['Fatto tutte le operzioni come richieste!'];
    end
end