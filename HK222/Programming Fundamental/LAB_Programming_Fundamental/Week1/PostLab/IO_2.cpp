void calMoney(string price, string buy) {
    ifstream ifs;
    ifs.open(price);
    int N;
    ifs >>N;
    int arr[20][2];
    for (int i =0;i <N;i++){
        ifs >>arr[i][0];
        ifs >>arr[i][1];
    }
    ifs.close();
    ifs.open(buy);
    int M;
    int t;
    int tongtien = 0;
    ifs >> M;
    string name;
    for (int i = 1;i <= M;i++){
        tongtien =0;
        ifs >> name;
       while(ifs >> t){
            for (int j = 0; j<N;j++){
                if (arr[j][0]==t){
                    ifs >>t;
                    tongtien = tongtien +arr[j][1]*t;
                    break;
                }
            }
        }
    ifs.clear();
        cout<<name<<' '<<tongtien<<endl;
    }
}