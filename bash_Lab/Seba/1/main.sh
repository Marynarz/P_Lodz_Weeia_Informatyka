#! /bin/bash
#powinno dzialac, ale przetestuje w domu
varX=1; #zmienna x do mnozenia
echo $varX
for line in $(cat $@ | tr ";" "\n") #for, otwiera plik i kazda zmienna oddzielona ; traktuje jako nowa linie
do
varX=$((varX*line)) #matemtyka
done
echo $varX  #wysiwetla odpowiedz

#dane zapisane w formacie 1;2;3;4, jak w pliku test.txt
#wywoływanie skyrptu: ./main.sh test.txt

