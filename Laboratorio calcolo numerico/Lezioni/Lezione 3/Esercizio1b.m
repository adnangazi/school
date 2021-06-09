clear all; % pulizia workspace
asseX = 0:(0.01):1; % range [0,1] con dentro 100 punti equispaziati
figure(1); % numero del grafico creato
plot(asseX, myMFun(asseX)); % grafico creato su asseX con myFun