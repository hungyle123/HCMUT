int Kiemtra(string s,string s1) {
    int h =0,t,t0;
    int a= s.length(), b= s1.length();
    for (int i = 0; i < a; i++){
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
            if (h ==1) 
                break;
            }
    }
    if (h == 1) return 1;
    else return 0;
}
void deleteWord(string s, string s1){
    while (Kiemtra(s,s1)==1){
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
                s.erase(s.begin()+ t0,s.begin() + t0+b);
            }
            
        }
    }}
    cout<<s;
}