#comentarz, jedna linie
"""
kilka
ljnijek
komentarz
"""

#####
#Vars
#####
a=1
print type(a)   #pokazuje typ zmiennej

a='1'
print type(a)

a=1.0
print type(a)

#print help(int) #wyswietla helpa do funkcji (funkcja)


########
# Tuple
########

a = (1,2,3,4)
print type(a)

print a[1]
print a[-1]

#tuple sa niemodyfikowane
#a[0] = '1'

a =1,2,3,4
print type(a)

#jednoelementowa krotka:
a = (1,)
print type(a)

a=1
b=2

#patter matching
a,b=b,a     #zajebiste, zamienia miejscami
print a
print b

#######
#Lista
#######
a=[1,2,3,4]
print type(a)

print a[0]
print a[-1]

a[0] = 'W' #modyikacja listy
print a

a.append(10) #dodwawanie do listy
print a

#print dir(a)    #wyswietla metody klasy list
a.insert(2,11) #(index,value)
print a

del a[0] #index
print a

a= [1,2,3,4]    #rozszerza liste o liste
b=[2,3,4,5]
a.extend(b)
print a

a= range(1,10,2)    #range zwraca liste od 1 do 10 bez 10, o krok 2
print a

for elem in a:
    print elem

#skladanie listy na podstawie innej listy (comprehension list)
a= [x for x in range(1,10)]
print a

#proste zadanie, mamy jakas liste,
a=[1,2,3,4,5,6]
print a

#a chcemy liste, gdzie kazdy element jest wymnozony przez 2
a=[x*2 for x in a]  #zajebiste
print a

############
# Slices
############

a=[1,2,3,4,5,6,7,8,9,10]
print a[2:5:1] #wycinek od 2 do 5 bez 5, krok 1, nie musi byc podawany
print a[-1:-5:-1]   #domyslny krok jest 1, musi byc ustawiony na -1

###########
# Syntax
############

if 1<2:
    print 'ok'
elif 1<10:
    print 'ok2'
else:
    print 'nie ok'

a= "sample text"
print a.split() #domyslny separtor to spacja
print " ".join(a.split()[::-1])
print a.split('e')
print a[::-1] #odwrocony ciag
a="a"
print ord(a) #numer ascii
aa=98
print chr(aa) #znak na podstawie numeru ascii

a="sample text"
print a.index("m"),'log2'
#########
# ex1
##########

#ODwrocic napis She sells sea shells <- oba napisy maj byc stringami
a='She sells sea shells'
print " ".join(a.split()[::-1])

#drugi
#a= raw_input("Enter text: ")
#print " ".join(a.split()[::-1])

############
# set
############

a=[1,2,3,4,5]
b="sample text"
c=set(a)
d=set(b)
print c
print d
c.add((1,2,3)) # do seta mozna dodac tylko elementy niezmienalne
print c
c.remove(5) #sety sa nie indeksowane, podajemy warotsc
print c

#nie modyfikowalny set
a=[1,2,3,4]
b= frozenset(a)
print b
#b.add(10)

#########
# disctonary
#########

a= {"a" :1, "c" : 2, "xv" :4}
print type(a)
print a
print a["c"]
print a.keys()
print a.values()
print a. items()

########
# ex2
#######

phoneKeyboard={
    "abc":'2',
    "def":'3',
    "ghi":'4',
    "jkl":'5',
    "mno":'6',
    "pqrs":'7',
    "tuv":'8',
    "wxyz":'9',
    " ":'#'
    }
print phoneKeyboard.keys()
#textTrans="3388833#4427777#2#22228"
#textTrans = textTrans.split('#')
#print textTrans
textTrans = "dupa"
translatedText = ""
for letters in textTrans:
    #print letters in "abc"
    if letters in "abc":
        translatedText += phoneKeyboard["abc"] * ("abc".index(letters)+1)        
        #print translatedText
    elif letters in "def":
        translatedText +=phoneKeyboard["def"] * ("def".index(letters)+1)
    elif letters in "ghi":
        translatedText +=phoneKeyboard["ghi"] * ("ghi".index(letters)+1)
    elif letters in "jkl":
        translatedText +=phoneKeyboard["jkl"] * ("jkl".index(letters)+1)
    elif letters in "mno":
        translatedText +=phoneKeyboard["mno"] * ("mno".index(letters)+1)
    elif letters in "pqrs":
        translatedText +=phoneKeyboard["pqrs"] * ("pqrs".index(letters)+1)
    elif letters in "tuv":
        translatedText +=phoneKeyboard["tuv"] * ("tuv".index(letters)+1)
    elif letters in "wxyz":
        translatedText +=phoneKeyboard["wxyz"] * ("wxyz".index(letters)+1)
    elif letters == ' ':
        translatedText +=phoneKeyboard[" "]

print translatedText

#to samo, ale prosciej
sample = "adj".lower()
result =''

for letter in sample:
    for item in phoneKeyboard.items():
        if letter in item[0]:
            index = item[0].index(letter) +1
            result +=index * item[1]

print result

#######
#ex3
######
x = []

sample = "177"

for letter in sample:
    if letter not in x:
        x+= letter

print len(x)

##prosciej
a=177
print len(set(str(a)))
###########
#chall 2
############
import string
sample ="g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj. "
result =""
for letter in sample:
    if ord(letter) +2 > 122:
        result += chr(ord(letter)+2-122)
    elif ord(letter) +2 <96:
        result += letter
    else:
        result += chr(ord(letter)+2)
print result

table = string.maketrans("abcdefghijklmnopqrstuvwxyz", "cdefghijklmnopqrstuvwxyzab")

#print sample.translate("ocr")

###########
# ex 4
###########
x = range(1,7)
y = range(1,7)
xLess =[]
xEqual =[]
xMore =[]
for cubeNum in x:
    for cubeYnum in y:
        if cubeNum == cubeYnum:
            xEqual += (cubeNum, cubeYnum)
        elif cubeNum > cubeYnum:
            xMore += (cubeNum, cubeYnum)
        else:
            xLess += (cubeNum, cubeYnum)

#print xLess
#print xEqual
#print xMore
def funkcja(temp):
    counter = 0
    xCount =0
    yCount =0
    for number in range(0,len(temp)):
        if (counter%2)==0:
            xCount +=temp.pop()
        else:
            yCount +=temp.pop()
        counter +=1
    print "X: ", xCount
    print "Y: ", yCount

funkcja(xLess)
funkcja(xEqual)
funkcja(xMore)

#POSPRZATANE!
print xLess
print xEqual
print xMore

#############
#ex 5
#############

source = "A toyota".lower()
temp = "".join(source.split())

if temp[::1] == temp[::-1]:
    print "jest"
else:
    print "nie jest"

print temp[::1] == temp[::-1]

##############
# chall 3
###############


import sys
import os

def FileBuffer():
	try:
		f= open("text.txt","r")
		lines = f.readlines()
		f.close()
		return lines
	except:
		print("[IO_EXCEPTION]Fail to open file")

lines = FileBuffer()

import re
for line in lines:
    #print re.findall("[A-Za-z]", line)
    listka = re.findall("[A-Za-z]", line)
    if listka:
        print listka
#pass: equality
############
# chall 4
############
print ' '
def FileBuffer():
	try:
		f= open("text2.txt","r")
		lines = f.readlines()
		f.close()
		return lines
	except:
		print("[IO_EXCEPTION]Fail to open file")

lines = FileBuffer()

for line in lines:
    #print re.findall("[A-Za-z]", line)
    listka = re.findall("[^A-Z]+[A-Z]{3}([a-z])[A-Z]{3}[^A-Z]+", line)
    if listka:
        print listka
