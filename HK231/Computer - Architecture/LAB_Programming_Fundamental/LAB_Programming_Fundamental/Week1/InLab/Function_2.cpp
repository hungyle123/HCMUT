int Prime(int n){
    int count =0;
    for (int i = 2;i <n;i++){
        if (n % i == 0) count = count +1;
    }
    if ((count ==0)&&( n > 0))
    return 1;
    else return 0;
}
bool isSpecialNumber(int n) {
    string s=to_string(n);
    int a =s.length();
    int count = 0;
    for (int i = 0; i <a; i++){
        if (s[i] =='0') count = count + 0;
        if (s[i] =='1') count = count + 1;
        if (s[i] =='2') count = count + 2;
        if (s[i] =='3') count = count + 3;
        if (s[i] =='4') count = count + 4;
        if (s[i] =='5') count = count + 5;
        if (s[i] =='6') count = count + 6;
        if (s[i] =='7') count = count + 7;
        if (s[i] =='8') count = count + 8;
        if (s[i] =='9') count = count + 9;
    }
    if ((Prime(count)==1)&&(Prime(n)==1))
    return true;
    else return false;
}