#include<iostream>
using namespace std;

struct orario{int ore,minuti,secondi; orario(int a=0, int b=0, int c=0){ore=a; minuti=b; secondi=c;}};

struct rileva{int ril, corr; orario time; rileva(int a=0, int b=0, orario c=orario()){ril=a; corr=b; time=c;}};
istream & operator>>(istream & s, orario & x); // da completare

istream & operator>>(istream & s, rileva & x); // da completare



main()
{
  int ncorr;
  cin >> ncorr;
  orario z;
  cin >> z; //presuppone che abbiate definito operator>> per orario, z non serve nel resto del programma
  //servono array per contenere le rilevazioni e forse anche altre cose
  int w;
  cin>> w;
  while (w=!-1)// ciclo fino alla sentinella -1

    {
     //legge e gestisce una rilevazione
    }

  //controllo dei problemi e stampa in ordine
}
