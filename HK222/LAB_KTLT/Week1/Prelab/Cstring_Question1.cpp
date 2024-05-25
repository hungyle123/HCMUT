// Student may implement another function as need

void process(char str[], char outstr[]) {
    int Vitri1, Vitri2;
    int a = strlen(str);
    for (int i = 0; i< a;i++){
        if (str[i]==' ') continue;
        else { Vitri1 =i;
        break;}
    }
    for (int i = a -1; i>=0;i--){
        if (str[i]==' ') continue;
        else { Vitri2 =i;
        break;}
    }
    int out=0, space = 0;
    for (int i = Vitri1; i<= Vitri2;i++){
        if (str[i]!=' ') {
            space =0;
            outstr[out]=str[i];
            out++;
        }
        if ((str[i] ==' ')&&(space == 1)){
            continue;
        }
        if ((str[i] ==' ')&&(space == 0)){
            space = 1;
            outstr[out] =' ';
            out++;
        }
    }
    outstr[out] ='\0';
}
