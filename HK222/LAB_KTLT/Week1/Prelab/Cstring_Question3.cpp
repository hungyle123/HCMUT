// Student may implement another function as need
int Pow(int a,int b) {
    int k = 1;
    for (int i = 1; i <=b; i++){
        k = k*a;
    }
    return k;
}
int calc(char str[]) {
    int a = strlen(str);
    int b=0;
    for (int i = 0; i < a ; i ++){
        if (str[i]=='0'){
            b = b + 0*Pow(2,a-1-i);
        }
        if (str[i]=='1'){
            b = b + 1*Pow(2,a-1-i);
        }
    }
    return b;
}
