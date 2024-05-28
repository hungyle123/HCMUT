void manage(string library, string book, string author){
    ifstream ifs;
    ifs.open(library);
    int N;
    ifs >> N;
    string *namelibrary = new string[N];
    int **ID= new int*[N];
    for (int i =0; i <N;i++){
        ID[i]=new int [5];
    }
    for (int i = 0; i<N;i++){
        ifs >> namelibrary[i];
        for (int j = 0; j<5;j++){
            ifs >> ID[i][j];
        }
    }
    ifs.close();
    ifs.open(book);
    int M;
    ifs >> M;
    ifs.close();
    ifs.open(author);
    int D;
    ifs >> D;
    string *nameauthor = new string[D];
    for (int i = 0; i<D;i++){
        
        ifs >> nameauthor[i];
        int t;
        while(ifs >>t){
        }
        ifs.clear();
        
    }
    ifs.close();
    string thuvien,tacgia;
    cin >>thuvien>>tacgia;
    int checkthuvien,checktacgia;
    for (int i =0;i<N;i++){
        if (namelibrary[i]==thuvien)
            {checkthuvien = i;
            break;}
    }
    for (int i=0;i<D;i++){
        if (nameauthor[i]==tacgia){
            checktacgia =i;
            break;
        }
    }
    ifs.open(author);
    string t;
    while (t != tacgia){
        ifs>> t;
    }
    int l,ketqua=0;
    while (ifs >> l ){
        for (int i=0;i<5;i++ ){
            if (ID[checkthuvien][i]==l)
            {ketqua = 1;
            goto end;}
        }
    }
    end: if (ketqua == 1)
    cout<<"True";
    else cout<<"False";
    ifs.close();
}