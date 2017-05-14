#! /bin/bash
#powinno dzialac, ale przetestuje w domu
varX= 1; #zmienna x do mnozenia
echo $varX
for line in $(cat $@ | tr ";" "\n") #for, otwiera plik i kazda zmienna oddzielona ; traktuje jako nowa linie
do
echo $varX
echo $line
varX = $((varX * line)) #matemtyka
done
echo $varX  #wysiwetla odpowiedz
