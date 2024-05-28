// Student may implement another function as need
    void process(char str[], char outstr[]) {
   int a=strlen(str);
   char e;
   for (int i = 0; i<a;i++){
        outstr[i]=str[a-1-i];
        
   }
   outstr[a] ='\0';
}
