#include <iostream>
#include <string>

using namespace std;

int Count(string s){
    int a = s.length();
    int f1 = 1, f2 = 1;
    for (int i = 0; i < a;i++){
        if (s[i]==s[i+1]){
            f1 = 1;
            for (int j = i+1; j< a; j++){
                if (s[i]==s[j])
                    f1 = f1 +1;
                else break;
        }
        if (f1 >f2 ) {f2 = f1;
        f1 =1;}
        else f1 = 1;
    }
    
}
int e = 1;
for (int i = 0;i <a;i++){
    if (s[i]==' ')
        e = e*1;
    else e = e*0;
}
if (e==1)
return 0;
else return f2;

}
int main()  {
    string s ;
    cin >>s;
    cout <<Count(s);
    return 0;
}