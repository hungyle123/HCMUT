void calSum(string fileName)   {
    ifstream ifs;
    ifs.open(fileName);
    char c = ifs.get();
    int k= 0, sum =0;
while (ifs.good()) {
        if ( c == ' '){
            sum = sum + k;
          k = 0;  
        }
        else k = k*10+(c -'0');
        c = ifs.get();
        }
    cout << sum +k;
    ifs.close();
   
}
