// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
stack <char> stackOperators;
string pst = "";
for (int i = 0; i < inf.size(); i++) {
    if (isdigit(inf[i])) {
        while (isdigit(inf[i])) {
            pst += inf[i];
            i++;
            if (i == inf.size())
                break;
        }
        pst += " ";
        i--;
    }
    if (IsOperator(inf[i])) {
        if (inf[i] == '(') {
            stackOperators.push(inf[i]);
        } else if (inf[i] == ')') {
            char s = stackOperators.top();
            stackOperators.pop();
            while (s != '(') {
                //pst += to_string(s);
                pst += string() + s;
                pst += ' ';
                s = stackOperators.top();
                stackOperators.pop();
            }
        } else {
            if (!stackOperators.empty()) {
                if (Priority(inf[i]) <= Priority(stackOperators.top())) {
                    pst += string() + stackOperators.top();
                    pst += ' ';
                    stackOperators.pop();
                }
            }
            stackOperators.push(inf[i]);
        }
    }
}
while (!stackOperators.empty()) {
    pst += stackOperators.top();
    pst += ' ';
    stackOperators.pop();
}
  return std::string("");
}

int eval(std::string pst) {
int result = 0, ElementInTop = 0;
TStack <int> stack2;
for (int i = 0; i < pst.size(); i++) {
if (isdigit(pst[i])) {
string strstack2 = "";
while (isdigit(pst[i])) {
strstack2 += pst[i];
i++;
if (i == pst.size())
break;
}
stack2.push(stoi(strstack2));
i--;
} else { if (IsOperator(pst[i])) {
int a = stack2.top();
stack2.pop();
int b = stack2.top();
stack2.pop();
switch (pst[i]) {
case '+': result = b + a; break;
case '-': result = b - a; break;
case '*': result = b * a; break;
case '/': result = b / a; break;
case '^': {
result = stoi(to_string(pow(stoi(to_string(b)), stoi(to_string(a)))));
break;
        }
        }
        stack2.push(result);
    }
           }
  return 0;
}
ElementInTop = stack2.top();
return ElementInTop;
}
int Priority(char s) {
switch (s) {
case '(': return 0;
case ')': return 1;
case '+': return 2;
case '-': return 3;
case '*': return 4;
case '/': return 4;
case '^': return 5;
default: return 6;
}
}
bool IsOperator(char symbol) {
switch (symbol) {
case '+': return true;
case '-': return true;
case '*': return true;
case '/': return true;
case '^': return true;
case '(': return true;
case ')': return true;
default: return false;
}
}
