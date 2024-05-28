#include <cstring>
void mostFrequentCharacter(char* str, char& res, int& freq) {
    int a = strlen(str);
    for (int i =0; i<a;i++){
        str[i] = tolower(str[i]);
    }
    char Tcheck;
    res = str[0];
    int count=0;
    for (int i= 0;i<a;i++){
        Tcheck = str[i];
        for (int j =i;j<a;j++){
            if(Tcheck == str[j]){
                count = count +1;
            }
        }
        if (count > freq){
           
            res = Tcheck;
            freq = count;
        }
        else if (count ==freq){
            if((int)Tcheck<=(int)res){
            res = Tcheck;
            freq = count;
        }}
        
        count = 0;
    }
}