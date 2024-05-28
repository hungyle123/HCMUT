#include <iostream>
#include <string>

using namespace std;
int Check(string s) {
    int a =s.length();
    int k = 1;
    for (int i =0;i < a/2;i++){
        if (s[i]!=s[a-i-1]){
        k = 0;
        break;}
    }
    return k;
}
int main()  {
    string o;
    cin >> o;
    string s;
    int k =0;
    int checknho = 0;
    int a = o.length();
    for (int i=2;i<=a;i++){
        for (int j =0; j< a-(i-1);j++){
       string out(o,j,i);
       if ((Check(out)==1)&&(i>k)){
          s = out;
           checknho =1;
           k = i;
       }
    }}
    if (a !=0){
    
    if ((checknho == 1)&&(a!=1))
   cout << s;
   else cout<<o[0];}
    return 0;
}