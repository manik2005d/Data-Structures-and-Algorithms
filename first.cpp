#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    char str[] = {'a','b','c','d','e'};
    int st = 0;
    int end = strlen(str)-1;
    while(st<=end){
        swap(str[st],str[end]);
        st++;
        end--;
    }
    for (char ch: str){
        cout << ch;
    }
}