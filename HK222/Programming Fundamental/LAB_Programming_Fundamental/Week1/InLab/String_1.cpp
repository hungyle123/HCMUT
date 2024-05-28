#include <cstring>
void replaceString(string s, string s1, string s2){
    int a= s.length(), b= s1.length();
    int h = 0,Vitri1 = -1,Vitri2 = -1,t,t0;
    for (int i =0 ;i < a; i ++){
        if (s[i] == s1[0]){
            h = 1;
            t = i;
            for (int j = 0; j < b; j++ ){
                 t0 = i;
                if (s[t]==s1[j])
                    h = h*1;
                else h = h*0;
                t++;
            }
            if (h ==1) {
                Vitri1 = t0;
                Vitri2 = t0 + b-1;
            }
            
        }
    }
    if ((Vitri1 == -1) && (Vitri2 == -1)) {
        cout <<s;
    }
    else {
       for (int i = 0;i < Vitri1;i++){
           cout<<s[i];
       }
       cout <<s2;
       for (int i = Vitri2 +1;i < a;i++){
           cout<<s[i];
       }
    }
}