void studentGrading(string fileName)   {
    ifstream ifs;
    ifs.open(fileName);
    int A =0,B=0,C=0,D=0;
    int N;
    ifs >>N;
    double grade,t;
    int check5 = 0;
    for (int i =1; i<=N;i++){
        check5 =0;
    ifs >> grade;
    if (grade <5){
        check5 = 1;
    }
    for (int i=1;i<4;i++){
        ifs >> t;
        if (t <5)
        check5 =1;
        grade = grade + t;
    }
    if (check5 == 1){
        D = D+1;
    }
    else {
        if (grade/4 >=8)
        A = A +1;
        else if ((grade/4<8)&&(grade/4>=6.5))
        B = B +1;
        else if ((grade/4<6.5)&&(grade/4>=5))
        C = C+1;
        else D = D+1;
    }
}
 cout<<"A"<<' '<<A<<endl;
 cout<<"B"<<' '<<B<<endl;
 cout<<"C"<<' '<<C<<endl;
 cout<<"D"<<' '<<D<<endl;
 ifs.close();
}