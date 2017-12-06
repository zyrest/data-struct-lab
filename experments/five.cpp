//
// Created by samson on 17-11-29.
//
#include "iostream"
#include "map"
#include "../stack/arrayStack.h"
#include "maze.h"

using namespace std;

map<char, int> symp;

int getNumber(char a) {
    switch(a) {
        case '1' :
            return 1;
        case '2' :
            return 2;
        case '3' :
            return 3;
        case '4' :
            return 4;
        case '5' :
            return 5;
        case '6' :
            return 6;
        case '7' :
            return 7;
        case '8' :
            return 8;
        case '9' :
            return 9;
        case '0' :
            return 0;
        default:
            return -1;
    }
}

int doCal(int one, char mid, int two) {
    switch (mid) {
        case '+' :
            return one + two;
        case '-' :
            return one - two;
        case '*' :
            return one * two;
        case '/' :
            return one / two;
        default:
            return 0;
    }
}

void caculate(const char* inputs, int len) {
    cout << "需要计算的表达式为:" << inputs << endl;
    symp['('] = 0;
    symp[')'] = 0;
    symp['+'] = 1;
    symp['-'] = 1;
    symp['*'] = 2;
    symp['/'] = 2;

    ArrayStack<int> nums(len);
    ArrayStack<char> sy(len);
    for (int i = 0; i < len; ++i) {
        char ele = inputs[i];
        if (getNumber(ele) != -1) nums.push(getNumber(ele));
        else {
            if (sy.isEmpty()) sy.push(ele);
            else if (ele == '(') sy.push(ele);
            else {
                if (symp[ele] >= symp[sy.top()]) sy.push(ele);

                else {
                    while (! sy.isEmpty() && symp[sy.top()] >= symp[ele]) {
                        char mid = sy.pop();
                        if (mid == '(') break;

                        int two = nums.pop();
                        int one = nums.pop();
                        int ans = doCal(one, mid, two);
                        nums.push(ans);
                    }

                    if (ele != ')') sy.push(ele);
                }
            }
        }
    }

    while (! sy.isEmpty()) {
        char mid = sy.pop();
        int two = nums.pop();
        int one = nums.pop();
        int ans = doCal(one, mid, two);
        nums.push(ans);
    }
    cout << "经过计算，结果为:" << nums.top() << endl;
}

