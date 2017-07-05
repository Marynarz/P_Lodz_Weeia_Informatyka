###############
# ex 6
###############
a = "290"
b ="19"
aTemp = int(a[::-1])
bTemp = int(b[::-1])
aTemp +=bTemp
print str(aTemp)[::-1]


############
# funkcje
############

def fun(arg):
    return arg

print fun(10)

def fun(a, b=10):
    print a
    print b

fun(5)

def fun(*arg):  #zmienna ilosc parametrow
    return arg

print fun(1,2,3,4)
print fun(2)

def fun(**arg): #do slownika dowolna ilosc argumentow
    return arg

print fun(a=1,b=3,c=10)
print fun(a=10,b=1)

def fun(a, *arg): #wymuszanie przynajmniej ejdnego parametru
    print a
    print arg

fun(2)

###############
# LAMBDA
#################

def fun(arg):
    return arg*2

a= lambda x:x*2
print type(a)
print a(2)

a=[1,2,3,4,5,6,7]

def fun(lst, n):
    temp = []
    for elem in lst:
        if elem >n:
            temp.append(elem)
    return temp

print fun(a,3)

def fun(arg):
    if arg >3:
        return True
    else:
        return False

print filter(fun,a)

print filter(lambda arg: True if arg>3 else False, a)
print filter(lambda arg:arg>3, a)   #zajebiste!

def fun(lst,n):
    temp =[]
    for umbers in lst:
        temp.append(umbers * n)
    return temp
a=[1,2,3,4,5,6,7,8,9,10]
print fun(a,2)

print map(lambda x:x*2,a)

a=lambda x,y:x*y
print a(2,5)

#############
# ex
##############

#ma wyprintowac wszystkie slowa ktorych dlugosc jest >3
a=["aaa","bbb","ddda","ccc"]

print filter(lambda arg: len(arg) >3, a)

#ma wyprintowac dlugosc slow
a=["a","bbb","cc"]
print map(lambda arg:len(arg),a)


###########
# regex
###########

import re

text = "this is this is sample text 54 3 sample"

print re.match(".*",text).group()

#* greedy operator
#*? not greedy operator
print re.match(".*? is",text).group()


#[0-9] <=> \d
#[A-Z] <=> \w
print re.match("(.*) is sample text ([0-9]{2})",text).group(2)

#{} krotosc
#() grupa
#[] przedzial

text = "12 34sample56"

#match <- szuka poczatku tekstu
#searh <- szuka tekstu w calym 
print re.search("sample",text).group()

print re.findall("\d{2}",text)

a=":****::::"

#print re.match("[:*]{9}$",a).group()
print re.search("^[:*]{9}$",a).group()

text = "Allowed Hello Hollow"
for m in re.finditer("ll",text):
    print m.start(),m.end()

######
# ex7
######
print "--------------------------------------------------------"
dictOp = {"::*:::*::":'+',"::::*::::":'-',"*:*:::*:*":'*',":::***:::":'/'}
tempNum = []
tempopera=''
with open("card.txt") as f:
    lines = f.read().splitlines()

if re.match("[:]{9}$",lines[0]) and re.match("[:]{9}$",lines[4]):
    try:
        if lines[2] in dictOp:
            for line in lines[1:4:2]:
                for m in re.finditer("[*]",line):
                    tempNum.append(m.start()+1)
            tempopera +="".join(str(tempNum[0]))
            tempopera +="".join(dictOp[lines[2]])
            tempopera +="".join(str(tempNum[1]))
            print tempopera," = ",eval(tempopera)
    except Exception as e:
        print "Error"
        print e
else:
    print "BLAD! Pierwsza i ostania zle"

print "--------------------------------------------------------"
###############
# I/O
###############

try:
    f = open("card.txt")
    lines = f.readlines()
    print lines
    f.seek(0) # przesuwa wskaznik na poczatek
    lines = f.readlines()
    print lines
    f.seek(0)
    lines = f.read().splitlines()
    print lines
except IOError as e:
    print e
else:
    f.close()
finally:
    pass

#file will be closed automaticaly
with open("card.txt") as f:
    print f.readlines()

#############
# chall 4
#############
"""
import urllib
uri = "http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing=%s"
nothing = "8022"


while True:
    try:
        fileTex = urllib.urlopen(uri % nothing).read()
        nothing = re.search("and the next nothing is (\d+)",fileTex).group(1)
        print nothing
    except:
        break
print nothing
"""

#peak.html

#############
# chall 5
#############

import pickle, urllib
source = urllib.urlopen("http://www.pythonchallenge.com/pc/def/banner.p")
#print source
pickled = pickle.load(source)
print pickled
target =""
for pi in pickled:
    print "".join(el[0] * el[1] for el in pi)
    
print target
source.close()

############
# chall 6
############

nothing = "90052.txt"

with open("90052") as f:
    f.read().splitlines()
