import random

ileLiczb = int(raw_input("Ile liczb losowac: "))
maksZakres = int(raw_input("Maksymalna liczba: "))

print "Losowanie %d liczb z %d" % (ileLiczb,maksZakres)

liczby = set()
while len(liczby) <ileLiczb:
    liczby.add(random.randint(1,maksZakres))

print liczby
typy = set()
while len(typy) <ileLiczb:
    try:
        typy.add(int(raw_input("Podaj liczbe: ")))
    except:
        print "Zla wartosc!"

print "WYGRANA" if typy & liczby else "PRZEGRALES!!!"