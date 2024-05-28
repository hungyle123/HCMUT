#include <cstring>
bool isPalindrome(const char* str) {
    int s = strlen(str);
    int a=1,t = s/2 -1 ;
    for (int i = 0;i <=t;i++){
        if (str[i]==str[s-1-i])
        a = a*1;
        else a = a*0;
    }
    if (a == 1)
    return true;
    else return false;
}