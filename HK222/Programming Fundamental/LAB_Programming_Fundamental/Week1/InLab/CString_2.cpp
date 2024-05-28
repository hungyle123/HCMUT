// Student may implement another function as need
int Validchar(char c) {
    if (('z'>= c && c >= 'a') || ('Z'>= c && c >= 'A'))
    return 1;
    else return 0;
}
void printFirstRepeatedWord(char str[]) {
    int Vitri12=0,Vitri22 =0,Turn2 = 0,Tongkiemtra = 1;
    int Vitri11= 0,Vitri21 =0,Turn1 = 0;
    int Final = 0;
    int s = strlen(str);
    char *stra = new char[s + 2]; // ta lập một chuỗi mới có hai cách hai đầu để tiện việc 
    for (int i = 1;i <=s;i++){    //lấy chuỗi nhỏ mà ko cần xét riêng hai th đầu cuối
        stra[i]= str[i-1];
    } 
    stra[0]= ' ';
    stra[s+1]=' ';
    for (int i= 0;i <s+2; i++){
        if (stra[i] == ' '){
                if ((Turn1 == 1) && (Vitri21 == 0)) {
                Vitri21 =i;
                Turn1 =2;
                
            for (int j = i; j <s+2;j++){
                if (stra[j]==' '){
                    if ((Turn2 == 1) && (Vitri22 == 0)) {
                    Vitri22 =j;
                    Turn2 =2;
                    int t2 = Vitri12 + 1;
                    for (int t = Vitri11 + 1;t < Vitri21;t++){
                        
                        if ((Tongkiemtra == 1) && (stra[t]==stra[t2])&&(!((Validchar(stra[t2+1])==1)&& (t == Vitri21 -1) )))
                            Tongkiemtra = Tongkiemtra*1; // ở trên sẽ có những th sai như (car ta xi bike bike car taxi) nó sẽ in ra "ta"
                        else Tongkiemtra = Tongkiemtra*0;
                        t2++;
                    }
                    if (Tongkiemtra == 1) {
                        for (int t = Vitri11 + 1;t < Vitri21;t++){
                            cout << stra[t];}
                            Final = 1;
                            goto Ketthuc;
                    }
                    else { Vitri12 = 0; 
                    Vitri22= 0;
                    Turn2 =0;
                    Tongkiemtra =1;
                    }
                }
                if ((Vitri12 == 0)&&(Validchar(stra[j+1])==1)) {
                    Vitri12 = j;
                    Turn2 =1;
                }
                if ( j == s + 1) {
                    Vitri11 = 0;
                    Vitri21 = 0;
                    Turn1 = 0;
                }
            }
            
        }
    }
    if ((Vitri11 == 0)&&(Validchar(stra[i+1])==1)) {
                    Vitri11 = i;
                    Turn1 =1;
                }
   }
   
}
    Ketthuc: if (Final == 0) cout<<"No Repetition";
    }