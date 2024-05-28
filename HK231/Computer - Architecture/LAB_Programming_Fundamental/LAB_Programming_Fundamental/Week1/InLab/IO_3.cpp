void process(string fileName)   {
    ifstream ifs(fileName);
    int N, M;
    ifs >> N >> M;
    double fimax ;
    int thutu1 =1;
    for (int j = 0; j<N; j++) {
        double maxr, num;
        ifs >> maxr;
        for (int i = 0; i<M-1; i++) {
            ifs >> num;
            maxr = max(maxr, num);
        }
        cout << maxr << ' ';
        if (thutu1 == 1){
            fimax = maxr;
            thutu1 = 0;
        }
        else fimax = max(fimax, maxr);
    }
    cout << fimax;
    ifs.close();
}