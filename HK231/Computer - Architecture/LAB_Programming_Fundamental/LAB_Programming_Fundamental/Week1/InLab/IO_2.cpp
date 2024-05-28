void threeChars(string fileName)   {
    string str;
    ifstream ifs;
    ifs.open(fileName);
    
    while (getline(ifs,str)) {
        int check = 1;
        for (int i = 0; i<2; i++){
            if (str[i]-'0'>str[i+1]-'0')
            check = 0;
            if ((str[i] == '*')&&(str[i+1] == '*')&&(str[i+2] == '*'))
            goto end;
        }
    if(check == 1)
    cout<<"true"<<'\n';
    else cout <<"false"<<'\n';
    }
    end: ifs.close();
}