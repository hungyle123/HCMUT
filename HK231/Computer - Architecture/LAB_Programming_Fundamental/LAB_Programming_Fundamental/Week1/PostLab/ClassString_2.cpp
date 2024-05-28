#include <iostream>
#include <string>

using namespace std;
int checkS(string s){
    int a=s.length();
    int check =1;
    for (int i =0;i<a-1;i++){
        for (int j =i +1;j<a;j++){
            if (s[i]==s[j]){
                check = 0;
                goto end;
            }
        }
    }
    end: return check;
}
int main()  {
    string s;
    cin>>s;
    int count = 1;
    int a = s.length();
    for (int i = 1;i <=a;i++){
        for (int j =0;j <a-(i-1);j++){
            string out(s,j,i);
            if (checkS(out)==1)
            count = i;
        }
    }
    cout <<count;
    return 0;
}