#! /bin/bash
#powinno dzialac, ale przetestuje w domu
varX=1; #zmienna x do mnozenia
for line in $(cat $@) #for, otwiera plik i kazda zmienna oddzielona ; traktuje jako nowa linie
do
varX=$((varX*line)) #matemtyka
done
echo $varX  #wysiwetla odpowiedz

#dane zapisane w formacie 1 2 3 4 wszystkow nowej linii, jak w pliku test.txt
#wywoływanie skyrptu: ./main.sh test.txt

