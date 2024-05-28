#include "knight.h"
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
int Prime(int a){
    int check=1;
    for (int k =2;k<a;k++){
        if(a % k ==0){
            check =0;
            break;
        }
    }
    if (a<=1)
    return 0;
    else 
    return check;
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    ifstream ifs;
    ifs.open(file_input);
    ifs.clear();
    int j, calwave = 0;                          //quá trình đếm số lượt đi để tạo mảng chứa các quá trình
    while(ifs >> j){
        calwave++;
    }
    calwave = calwave - 5;
    int *t =new int[calwave];
    ifs.clear();
   string a,file_mush_ghost,file_asclepius_pack,file_merlin_pack;
    ifs >> a;
    int lengthfile=a.length();
    int r1,r2,turn=0;                              //vị trí 2 dấu phẩy của dòng 3
    for (int k = 0;k <lengthfile;k++){
        if ((a[k]==',')&&(turn == 0)){
            r1 = k;
            turn = 1;}
        if ((a[k]==',')&&(turn==1))
            r2 = k;
    }
    file_mush_ghost =a.substr(0,r1);
    file_asclepius_pack = a.substr(r1+1,r2-r1-1);
    file_merlin_pack = a.substr(r2+1,lengthfile-1-r2);
    ifs.close();
    ifs.open(file_input);
    int specialcharacter;                                  //nếu là hiệp sĩ bàn tròn = 0; King Arthur = 1; Lancelot =2
    ifs >> HP;
    int maxHP =HP;
    if (maxHP == 999)
        specialcharacter = 1;
    else if (Prime(maxHP)==1)
        specialcharacter =2;
    else specialcharacter =0;
    ifs >> level;
    ifs >> remedy;
    ifs >> maidenkiss;
    ifs >> phoenixdown;
    rescue = -1;
    int i = 1;
    int trangthaitihon =0;                               //trang thai dung bien rieng de co the xac dinh
    int trangthaiech =0;
    int levelech;
    int laptihon,lapech;                                        //biến lap dùng để xác định vòng hết trạng thái bất lợi
    for (int k = 0; k <calwave;k++){
        ifs>>t[k];
    }
    ifs.close();
    int meetasclepius = 0;
    int meetmerlin = 0;
    for (int k = 0; k<calwave;k++){
        if (t[k] == 0){
            sukien0(rescue);
        }
        else if ((t[k] >=1 )&&(t[k]<=5)){
            sukien1_5(HP,level,phoenixdown,rescue,i,t[k],maxHP,trangthaitihon,trangthaiech,levelech,specialcharacter);
        }
        else if (t[k] == 6){
            sukien6(HP,level,remedy,i,trangthaitihon,laptihon,trangthaiech,specialcharacter);
        }
        else if (t[k] == 7){
            sukien7(level,i,trangthaiech,lapech,levelech,trangthaitihon,specialcharacter);
        }
        else if  (t[k] == 11){
            sukien11(HP,level,phoenixdown,maxHP);
        }
        else if (t[k] == 12){
            sukien12 (HP);
        }
        else if ((t[k] >= 15)&&(t[k] <=17)){
                sukien15_17 (remedy,maidenkiss,phoenixdown,t[k]);
        }
        else if (t[k]==19){
            sukien19(remedy,maidenkiss,phoenixdown,meetasclepius,file_asclepius_pack);
        }
        else if (t[k]==18){
            sukien18(HP,maxHP,meetmerlin,file_merlin_pack);
        }
        else if (t[k]==99){
            sukien99(level,rescue,specialcharacter);
        }
        else {
            sukien13(HP,level,remedy,maidenkiss,phoenixdown,rescue,t[k],maxHP,trangthaitihon,trangthaiech,levelech,file_mush_ghost);
        }
         if ((trangthaitihon == 1) && (remedy >= 1)){
                trangthaitihon = 0;
                remedy =remedy -1;
                HP = HP*5;
                if (HP >maxHP)
                HP = maxHP;
            }
            if ((trangthaiech == 1) && (maidenkiss >= 1)){
                trangthaiech = 0;
                maidenkiss =maidenkiss -1;
                level = levelech;
            }

        if ((trangthaitihon == 1)&&(i == laptihon)&&( HP > 0)) {
        HP = HP*5;
        if (HP >maxHP)
                HP = maxHP;}

        if ((trangthaiech == 1)&&(i ==lapech)){
            level = levelech;
        }
        if ((i == calwave )&&(HP > 0))
            rescue =1;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        if ((rescue == 1) || (rescue == 0))
        break;
        i++;
}
}
void sukien0 (int & rescue) {
            rescue = 1;
}
void sukien1_5 (int & HP, int & level,int & phoenixdown, int & rescue, int i,int t,int maxHP,int & trangthaitihon,int & trangthaiech,int &levelech,int  specialcharacter) {
    int b =i % 10;
    int levelO = i > 6?(b > 5?b : 5) : b;
    if ((level > levelO)||(specialcharacter != 0)){
        if(level < 10)
            level = level + 1;
    }
    else if (level < levelO) {
        float baseDamge,damage;
        if (t == 1)
            baseDamge =1;
        else if (t== 2)
            baseDamge = 1.5;
        else if (t == 3)
            baseDamge =4.5;
        else if ( t == 4)
            baseDamge =7.5;
        else if ( t == 5)
            baseDamge =9.5;
        damage = baseDamge*levelO*10;
        HP = HP - (int)damage;
    }
    if (HP <= 0){
        if (phoenixdown > 0){
            phoenixdown = phoenixdown -1;
            HP =maxHP;
            trangthaitihon = 0;
            if (trangthaiech==1){
            trangthaiech = 0;
            level =levelech;}
        }
        else rescue = 0;
    }
}
void sukien6 (int & HP,int & level,int & remedy,int i,int & trangthaitihon, int & laptihon,int &trangthaiech,int  specialcharacter){
    if ((trangthaiech == 0)&&(trangthaitihon == 0)){
    int b =i % 10;
    int levelO = i > 6?(b > 5?b : 5) : b;
    if ((level > levelO)||(specialcharacter != 0)){
            level = level + 2;
            if (level > 10)
            level = 10;
    }
     else if (level < levelO) {
        if (remedy >= 1) {
         remedy = remedy -1;
        }
        else {
            trangthaitihon = 1;
            laptihon = i+3;
            if (HP <5)
            HP = 1;
            else HP = HP/5;}}
}
}
void sukien7(int & level,int i,int & trangthaiech, int & lapech,int & levelech,int & trangthaitihon,int  specialcharacter){
            if ((trangthaiech == 0)&&(trangthaitihon == 0)){
            int b =i % 10;
            int levelO = i > 6?(b > 5?b : 5) : b;
            if ((level > levelO)||(specialcharacter!=0)){
            level = level + 2;
            if (level > 10)
            level = 10;
                }
            else if (level < levelO) {
                trangthaiech =1;
                levelech =level;
                level = 1;
                lapech = i +3;}}

}
void sukien11 (int & HP,int & level, int &phoenixdown,int maxHP) {
        int n1 = ((level+phoenixdown)%5+1)*3;
        int s1= 0;
        int t =0;
        for (int j =99; j>=1;j = j -2){
                if (t == n1)
                break;
            s1 = s1+j;
            t++;
        }
        HP = HP + (s1%100);
        int p = HP+1;
        while(1>0) {
            if (Prime(p)==1)
            break;
            p++;
        }
        HP =p;
        if (HP >= maxHP)
            HP = maxHP;


}
void sukien12 (int & HP) {
        if  (HP > 1){
        int h1 = 1, h2 = 1;
        int j=1;
        while ((h1 < HP)&&(h2 < HP)){
            h1 = h1 + h2;
            if (h1 < HP)
            j = h1;
            h2 = h2 +h1;
            if (h2 <HP)
            j = h2;
            }
            HP = j;
        }

}
void sukien15_17 ( int & remedy, int & maidenkiss, int & phoenixdown,int t) {
        if (t == 15){
            if (remedy <99)
                remedy = remedy +1;
        }
        else if (t == 16){
            if (maidenkiss <99)
                maidenkiss = maidenkiss +1;
        }
        else if (t == 17){
            if (phoenixdown <99)
                phoenixdown = phoenixdown +1;
        }
}
void sukien19(int & remedy, int & maidenkiss, int & phoenixdown,int & meetasclepius,string  file_asclepius_pack){
    if  (meetasclepius == 0){
        ifstream ifs;
        ifs.open(file_asclepius_pack);
        int r1,c1;
        ifs >>r1;
        ifs >>c1;
        int turn =0,j;
        for (int k =1;k <= r1;k++){
            turn =0;
            for (int h = 1; h<=c1;h++){
                ifs >> j;
                    if (turn == 3)
                    continue;
                if ((j >=16)&&(j<=18)){
                    if (j == 16){
                        if (remedy <99)
                        remedy = remedy +1;}
                    else if (j ==17) {
                        if (maidenkiss <99)
                        maidenkiss =maidenkiss+1;}
                    else if (j == 18){
                        if (phoenixdown < 99)
                        phoenixdown =phoenixdown+1;}
                    turn =turn +1;
                }
            }
            ifs.clear();
        }
        meetasclepius = 1;
        ifs.close();}
}
void sukien18(int & HP,int maxHP,int & meetmerlin,string  file_merlin_pack) {
    ifstream ifs;
    if (meetmerlin == 0){
    ifs.open(file_merlin_pack);
    int n9;
    ifs >> n9;
    string *arr = new string[n9];
    for (int k =0;k<n9;k++){
        ifs>>arr[k];
    }
    ifs.close();
    for (int k=0;k<n9;k++){
        if((arr[k].find("Merlin")!=string::npos)||(arr[k].find("merlin")!=string::npos)){
            HP = HP +3;
            if (HP >maxHP)
                HP = maxHP;
        }
        else if(((arr[k].find('M')!=string::npos)||(arr[k].find('m')!=string::npos))&&((arr[k].find('E')!=string::npos)||(arr[k].find('e')!=string::npos))&&((arr[k].find('R')!=string::npos)||(arr[k].find('r')!=string::npos))&&((arr[k].find('L')!=string::npos)||(arr[k].find('l')!=string::npos))&&((arr[k].find('I')!=string::npos)||(arr[k].find('i')!=string::npos))&&((arr[k].find('N')!=string::npos)||(arr[k].find('n')!=string::npos)))
        {
            HP = HP +2;
            if (HP >maxHP)
                HP = maxHP;
        }

    }
    meetmerlin =1;}
}
void sukien99(int & level,int & rescue,int  specialcharacter){
            if (( specialcharacter == 1)||((specialcharacter==2)&&(level >=8))||((specialcharacter == 0)&&(level == 10)))
                level = 10;
            else rescue = 0;
}
void sukien13 (int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int t,int maxHP,int & trangthaitihon,int & trangthaiech,int & levelech,string  file_mush_ghost){
            ifstream ifs;
            stringstream ss;
            ss << t;
            string str = ss.str();
            int solannam=str.length();
            ifs.open(file_mush_ghost);
            int n2;
            ifs >> n2;
            string dayso;
            ifs >> dayso;
            int z=dayso.length();
            int *sodong2 = new int[n2];
            int g=0,v=0,dautru =0;
            for (int l = 0;l<z;l++){
                    if(dayso[l]==','){
                        if (dautru == 1)
                        sodong2[v] = g*(-1);
                        else sodong2[v] = g;
                    dautru = 0;
                    g=0;
                    v++;
                    }
                    else if (dayso[l] == '-')
                            dautru =1;
                    else g=g*10+(dayso[l]-'0');
            }
            if (dautru == 1)
            sodong2[n2 - 1] =g*(-1);
            else 
            sodong2[n2 - 1] = g;
            ifs.close();
            for(int r=2;r<solannam;r++){
                    if (str[r]=='1'){
                        int maxiG=sodong2[0],maniG=sodong2[0];
                        int maxi=0,mani=0;
                        for(int l=0;l<n2;l++){
                            if (sodong2[l]>=maxiG){
                                    maxiG =sodong2[l];
                                    maxi =l;
                            }
                            if (sodong2[l]<=maniG){
                                    maniG =sodong2[l];
                                    mani =l;
                            }

                        }
                        HP = HP -(maxi+mani);
                        if (HP >maxHP)
                            HP = maxHP;
                        if (HP <= 0){
                                if (phoenixdown > 0){
                                phoenixdown = phoenixdown -1;
                                HP =maxHP;
                                trangthaitihon = 0;
                                if (trangthaiech==1){
                                trangthaiech = 0;
                                level =levelech;}
                            }
                                else {rescue = 0;
                                 break;}
                        }
                        }
                    else if (str[r]=='2'){
                        int mtx =-2,mti=-3;
                        int chamdinh =0;
                        int dinhy=sodong2[0],dinhx=0;
                        int kiemtra =1;
                        for(int l=1;l<n2;l++){
                                if ((sodong2[l]>sodong2[l-1])&&(chamdinh == 0)){
                                        dinhy = sodong2[l];
                                        dinhx = l;
                                }
                                else if ((sodong2[l]<sodong2[l-1])&&(chamdinh==0)) {
                                    chamdinh =1;
                                }
                                else if ((sodong2[l]>sodong2[l-1])&&(chamdinh == 1)){
                                    kiemtra =0;
                                    break;
                                }
                                else if (sodong2[l]==sodong2[l-1]){
                                    kiemtra =0;
                                    break;
                                }

                    }
                        if (kiemtra==1){
                            mtx = dinhy;
                            mti =dinhx;
                        }
                        HP = HP -(mtx + mti);
                        if (HP >maxHP)
                        HP = maxHP;
                        if (HP <= 0){
                                if (phoenixdown > 0){
                                phoenixdown = phoenixdown -1;
                                HP =maxHP;
                                trangthaitihon = 0;
                                if (trangthaiech==1){
                                trangthaiech = 0;
                                level =levelech;}
                            }
                                else {rescue = 0;
                                 break;}
                        }
                        }
                    else if (str[r] =='3'){
                        int *sodadoi =new int[n2];
                        for (int l =0;l<n2;l++){
                            sodadoi[l]=sodong2[l];
                        }
                        for (int l =0;l<n2;l++){
                            if (sodadoi[l]<0)
                                sodadoi[l]=sodadoi[l]*(-1);
                            sodadoi[l] =(17*sodadoi[l]+9)%257;
                        }
                        int maxiG2=sodadoi[0],maniG2=sodadoi[0];
                        int maxi2=0,mani2=0;
                        for(int l=0;l<n2;l++){
                            if (sodadoi[l]>maxiG2){
                                    maxiG2 =sodadoi[l];
                                    maxi2 =l;
                            }
                            if (sodadoi[l]<maniG2){
                                    maniG2 =sodadoi[l];
                                    mani2 =l;
                            }

                        }
                        HP = HP -(maxi2+mani2);
                        if (HP >maxHP)
                        HP = maxHP;
                        if (HP <= 0){
                                if (phoenixdown > 0){
                                phoenixdown = phoenixdown -1;
                                HP =maxHP;
                                trangthaitihon = 0;
                                if (trangthaiech==1){
                                trangthaiech = 0;
                                level =levelech;}
                            }
                                else {rescue = 0;
                                 break;}
                        }
                        }
                    else if (str[r]=='4') {
                        if (n2 < 3){
                           int max2_3x = -5;
                           int max2_3i = -7;
                            HP = HP - (max2_3x + max2_3i);
                           }
                        else if (n2 >= 3){
                        int *sodadoi =new int[n2];
                        for (int l =0;l<n2;l++){
                            sodadoi[l]=sodong2[l];
                        }
                        for (int l =0;l<n2;l++){
                            if (sodadoi[l]<0)
                                sodadoi[l]=sodadoi[l]*(-1);
                            sodadoi[l] =(17*sodadoi[l]+9)%257;
                        }
                        int max1=sodadoi[0];
                        int max2_3x=-5,max2_3i=-7,check =0;
                        for (int l=1;l<=2;l++){
                            if (sodadoi[l]>max1){
                                max1 =sodadoi[l];
                            }
                        }
                        int lan1 = 1;
                        for (int l=0;l<=2;l++){
                            if (sodadoi[l]!=max1){
                                if(lan1 == 1){
                                    max2_3x =sodadoi[l];
                                    max2_3i =l;
                                    lan1 =0;
                                }
                                else if(lan1==0){
                                    if(sodadoi[l]>max2_3x){
                                        max2_3x=sodadoi[l];
                                        max2_3i=l;
                                    }
                                }
                            }
                        }
                        if ((sodadoi[0] == sodadoi[1])&&(sodadoi[0]==sodadoi[2])) {
                            max2_3x = -5;
                            max2_3i = -7;
                        }     
                        HP = HP - (max2_3x + max2_3i);
                        }

                        if (HP >maxHP)
                            HP = maxHP;
                        if (HP <= 0){
                                if (phoenixdown > 0){
                                phoenixdown = phoenixdown -1;
                                HP =maxHP;
                                trangthaitihon = 0;
                                if (trangthaiech==1){
                                trangthaiech = 0;
                                level =levelech;}
                            }
                                else {rescue = 0;
                                 break;}
                        }
                        }
            }} 

