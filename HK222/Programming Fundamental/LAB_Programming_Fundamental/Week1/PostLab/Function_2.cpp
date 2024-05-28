int Power(int a){
    int k =1;
    for (int i =1;i<=a;i++){
        k = k * 10;}
    return k;
}
int convertToBaseM(int n, int m =2) {
    int final=0,t=0;
    int i = n;
    while ((i/m) > 0){
        final =final+ (i % m)*Power(t);
        i =i/m;
        t++;
    }
    final =final+ (i % m)*Power(t);
    return final;
}