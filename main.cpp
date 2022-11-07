#include "calculate.h"
#include "string.h"
#include <iostream>
#define MAX_LEN 100
using namespace std;

int main() {
    cout<< "---Arithmetic Expression Calculation---\n"<<endl;
    while(1)
    {
        cout<< "0 - calculate\n1 - quit\n\nplease input your choice: "<<endl;
        char n;
        cin>>n;
        switch (n) {
            case '0':
            {
                cout << "Please enter:" << endl;
                char s[MAX_LEN];
                memset(s,'\0',MAX_LEN*sizeof(char));
                cin >> s;
                double res = cal(s);
                cout << res << endl;
                break;
            }
            case '1':
                return 0;
            default:
                cout<<"wrong number, please enter again: "<<endl;
                break;
        }
    }
}