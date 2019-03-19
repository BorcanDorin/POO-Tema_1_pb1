# POO-Tema_1_pb1

## Cerinte comune:

* implementare in C++ folosind clase;
* ATENTIE: functiile pe care le-am numit mai jos metode (fie ca sunt supraincarcari de operatori, fie altfel de functii), pot fi implementate ca functii prieten in loc de metode ale claselor respective, daca se considera ca aceasta alegere este mai naturala;
* supraincarcarea operatorilor << si >> pentru iesiri si intrari de obiecte, dupa indicatiile de mai jos, astfel incat sa fie permise (si ilustrate in program):
  * citirea de la tastatura si dintr-un fisier;
  * scrierea pe ecran sau intr-un fisier;
  * citirea informațiilor complete a n obiecte, memorarea și afisarea acestora;

### Tema 1. liste de numere intregi reprezentate ca tablouri unidimensionale:

- metode ale clasei vector de intregi:
  - suma tuturor elementelor vectorului;
  - gasirea maximului si a pozitiei lui;
  - sortarea crescatoare;
  - produsul scalar a doi vectori de aceeasi lungime, implementat prin supraincarcarea operatorului *;
  
- sa se creeze o clasa matrice de numere intregi, prietena a clasei vector de intregi, care sa reprezinte matricile de numere intregi, nu neaparat patratice, sub forma unui vector de elemente de tip clasa vector de numere intregi, privite ca vectori linie; mai precis, o matrice cu m linii si n coloane va fi reprezentata ca un vector de m elemente de tip clasa vector, fiecare avand dimensiunea n, elemente care vor reprezenta liniile matricii; 
- sa se supraincarce operatorii >> si << si pentru clasa matrice de intregi, folosind supraincarcarea operatorilor >> si << pentru clasa vector de intregi; 
- sa se creeze o metoda pentru adunarea a doua matrici, care sa supraincarce operatorul +;
- sa se scrie o functie care sa aiba ca parametri o matrice de intregi A cu m linii si n coloane, un vector de intregi x de dimensiune n privit ca vector coloana, si un vector de intregi y de dimensiune m privit tot ca vector coloana, si care sa verifice daca Ax=y, folosind produsul scalar din clasa vector de intregi;
