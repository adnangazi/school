clear all; % pulizia workspace
myFun = @(x) (exp(x)).*((x.^2)+1); % anonymous function e^x (x^2 +1)
asseX = 0:(0.01):1; % range [0,1] con dentro 100 punti equispaziati
figure(1); % numero del grafico creato
plot(asseX, myFun(asseX)); % grafico creato su asseX con myFun