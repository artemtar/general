import random
import os
import sys

class Animal:
    __name = ""
    __hight = 0

    def __init__(self, n, h):
        self.__name = n
        self.__hight = h

    def set_name(self, n):
        self.__name = n

    def set_hight(self, h):
        self.__hight = h

    def get_type(self):
        print ("Animal")

    def toString(self):
        return "{} is {} cm".format(self.__name, self.__hight)

cat = Animal("Mew", 42)
print (cat.toString())

class Dog(Animal):

    __owner = ""

    def __init__(self, name, height, owner):
        self.__owner = owner
        super(Dog, self).__init__(name, height)



dog = Dog("wof", 54, "not me")

dog.toString()