void uppercase(string output)   {
    string o;
    cin >> o;
    int a = o.length();
    for (int i = 0; i < a;i ++){
        if ((o[i]>='a')&&(o[i]<='z')) 
            o[i] = o[i] -32;
    }

    ofstream ofs;
    ofs.open(output);
    ofs<< o;
    ofs.close();
}