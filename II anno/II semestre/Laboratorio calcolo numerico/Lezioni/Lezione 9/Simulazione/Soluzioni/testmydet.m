clear all
close all
nmax=10;

for n=1:10
    H=hilb(n);
    d(n)=det(H);
    d1(n)=mydet(H);
end
figure(1);
semilogy(d)
hold on
semilogy(d1,'--')
hold off
legend('det','mydet')