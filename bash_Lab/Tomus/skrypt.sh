#! /bin/bash
echo "Ile wyswietlic liczb pierwszych?: "
read iloscLiczb		#wybierasz ilosc liczb pierwszych do wyswietlenia
varX=4		#zmienna pomocnicza, od tej liczby zaczyna liczyc zmienne
varY=1		#zmienna pomocnicza, wielkosc tablicy z liczbami pierwszymi
tabLP=(2 3)	#tablica z liczbami pierwszymi
while test $varY -lt $((iloscLiczb-1))	#while jesli rozmiar tablicy jest mniejszy od ilosci liczb do wyswietlenia
do
for lines in $(factor $varX)	#dla kazdej liczby wyswietonej w poleceniu factor(polecenie do robijania podanej liczby na liczby pierwsze)
do
if test ${tabLP[$varY]} -lt $lines	#jesli ostatni element tablicy jest mniejszy od liczby zwroconej przez factor
then
varY=$((varY+1))	#powieksz rozmiar tablicy o jeden
tabLP[varY]=$lines	#dopisz do tablicy liczbe pierwsza
fi
done
varX=$((varX+1))	#powieksz o jeden liczbe sprawdzana
done


echo ${tabLP[@]}	#wypisz tablice (dziala dopiero po osiagnieciu zakladanej liczby liczb pierwszych
echo ${tabLP[@]} > wynik.txt #wynik zapisuje do pliku wynik.txt
#if generuje napisy "oczekiwano wyrazenia calkowitego" nie jest to blad.
#funkcja factor zwraca printout w postaci: liczba: liczba1 liczba2, liczba3
#test generuje napis dla pierwszego elentu printouta, bo jest liczba:
#jest to pozadane zachowanie