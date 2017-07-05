#########
#day3
##########

########
#Classes
########
import random
import sys

class Person():
    pass

class Employee(Person): #dziedziczenie w nawiasach
    company_name = "Ericpol by Ericsson"
    def __init__(self, name, surname): #konstrutor
        self.name = name    #atrybutu w dowolnym miejscy ale w metodzie i przez uzycie self
        self.surname = surname
        self.salary = random.randint(1000,2000)
    def __str__(self):  #cos jak ostream<<
        return self.name + " " + self.surname + " " + str(self.salary)
    def increase_salary(self,salary):
        self.salary += salary
    def decrease_dalary(self,salary):
        self.salary -=salary
    @classmethod #dekorator, info ze metoda statyczna
    def get_company_name(cls):
        return cls.company_name

print sys.argv

emp = Employee(sys.argv[1],sys.argv[2])
emp.increase_salary(1000)
print emp
print Employee.get_company_name()
