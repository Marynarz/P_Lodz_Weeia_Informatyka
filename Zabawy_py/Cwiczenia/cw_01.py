import random

liczba = random.randint(1,10)
print liczba


for i in range(3):
    odp = int(raw_input("Podaj liczbe: "))
    print "Zgadles" if liczba == odp else "Zle!"
    if liczba == odp:
        break