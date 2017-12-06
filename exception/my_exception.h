//
// Created by samson on 17-11-16.
//

#ifndef LEARN_MY_EXCEPTION_H
#define LEARN_MY_EXCEPTION_H
#include<exception>
#include<iostream>
using namespace std;

//customized exception class 'myException'
class IllegalIndex : public exception {
public:
    IllegalIndex(string meg) : exception() { }
};

class IllegalInput : public exception {
public:
    IllegalInput(string meg) : exception() { }
};

class NoSuchElement : public exception {
public:
    NoSuchElement(string meg) : exception() { }
};

class Empty : public exception {
public:
    Empty(string meg) : exception() { }
};

class Full : public exception {
public:
    Full(string meg) : exception() { }
};

class my_exception {

};


#endif //LEARN_MY_EXCEPTION_H
