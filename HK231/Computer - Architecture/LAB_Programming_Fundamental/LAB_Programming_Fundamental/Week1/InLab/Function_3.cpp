#include <cstring>
void encrypt(char* text, int shift) {
    int a =strlen(text);
    for(int i = 0;i <a;i++){
        if ((text[i]>='a')&&(text[i]<='z'))
       { if (text[i]+shift >122)
            text[i]=(text[i]-97+shift)%26 +97;
        else text[i] =text[i]+shift;}
        if ((text[i]>='A')&&(text[i]<='Z'))
        { if (text[i]+shift >90)
             text[i]=(text[i]-65+shift)%26 +65;
        else text[i] =text[i]+shift;}
    }
}

void decrypt(char* text, int shift) {
     int a =strlen(text);
    for(int i = 0;i <a;i++){
        if ((text[i]>='a')&&(text[i]<='z'))
       {if (shift >= 26) shift =shift%26 ;
           if (text[i] -shift <97)
                text[i]=text[i]-shift +26;
        else text[i] =text[i]-shift;}
        if ((text[i]>='A')&&(text[i]<='Z'))
        { if (shift >= 26) shift =shift%26 ;
           if (text[i] -shift <65)
                text[i]=text[i]-shift +26;
        else text[i] =text[i]-shift;
    }
}
}