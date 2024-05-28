#include "knight2.h"
int Prime(int a){
    if (a <= 1)
    return 0;
    int check = 1;
    for (int i = 2; i<a;i++){
        if (a % i == 0)
        {
            check =0;
            break;
        }
    }
    return check;
}
int dragonG(int x){
    if ((x == 345)||(x == 354)||(x == 435)||(x == 453)||(x == 543)||(x == 534))
    return true;
    else return false;
}
/* * * BEGIN implementation of class BaseBag * * */

 bool antidote::canUse(BaseKnight * knight) {
        if ((knight->getpoisoned() == 1)&&(knight->getKnightType() != DRAGON))
        return true;
        else return false;
    }
  void antidote::use(BaseKnight * knight){
        knight->setAntidote(knight->getAntidote()-1);
    }
 bool phoenixI::canUse(BaseKnight *  knight){
        if (knight->gethp() <= 0) return true;
        else return false;
    }
    void phoenixI::use(BaseKnight *  knight) {
        knight->sethp(knight->getmaxhp());
    }
bool phoenixII::canUse(BaseKnight * knight){
        if(knight->gethp()<knight->getmaxhp()/4)
        return true;
        else return false;
    }
    void phoenixII::use(BaseKnight *  knight){
        knight->sethp(knight->getmaxhp());
    }
bool phoenixIII::canUse(BaseKnight * knight){
        if(knight->gethp()<knight->getmaxhp()/3)
        return true;
        else return false;
    }
    void phoenixIII::use(BaseKnight *  knight){
        if(knight->gethp()<=0)
        knight->sethp(knight->getmaxhp()/3);
        else knight->sethp(knight->getmaxhp()/4 + knight->gethp());
    }
 bool phoenixIV::canUse(BaseKnight * knight){
        if(knight->gethp()<knight->getmaxhp()/2)
        return true;
        else return false;
    }
    void phoenixIV::use(BaseKnight *  knight){
        if(knight->gethp()<=0)
        knight->sethp(knight->getmaxhp()/2);
        else knight->sethp(knight->getmaxhp()/5 + knight->gethp());
    }
BaseBag::BaseBag(BaseKnight * knight){
        head =nullptr;
        if (knight->getKnightType() == DRAGON)
            maxbag = 14;
            else if (knight->getKnightType() == LANCELOT)
            maxbag = 16;
            else if (knight->getKnightType()== NORMAL)
            maxbag = 19;
            else maxbag = -1; // Giá trị -1 ko chạm tới nên tự hiểu là vô hạn
        
        int a = knight->getphoenixI();
        int b = knight->getAntidote();
                /*if (a>0){
                int bonullptra = 0;
            BaseItem * newnode = new antidote;
            newnode->data = PhoenixI;
            newnode->next = nullptr;
            if (head == nullptr) {
                    head = newnode;
                    bonullptra =1;
                    newnode = newnode->next;
                    delete newnode;
                }
            for (int i = 0;i<a-bonullptra;i++){
                if (this->countbag()== maxbag)
                break;
            BaseItem *newnode1 = new antidote;
            newnode1->data = PhoenixI;
            newnode1->next = nullptr;
                    newnode1->next = head;
                    head = newnode1;
                    while (newnode1 != nullptr){
                    newnode1 = newnode1->next;}
                    delete newnode1;
                }
                delete newnode;

            }
        if (b>0){      
            int bonullptrb = 0;     
            BaseItem *newnode2 = new antidote;
            newnode2->next = nullptr;
            if (head == nullptr) {
                    head = newnode2;
                    bonullptrb = 1;
                    newnode2 = newnode2->next;
                    delete newnode2;
                }
            for (int i = 0;i<b-bonullptrb;i++){
                if (this->countbag()== maxbag)
                break;
                BaseItem *newnode3 = new antidote;
            newnode3->next = nullptr;
                    newnode3->next = head;
                    head = newnode3;
                    while (newnode3 != nullptr){
                    newnode3 = newnode3->next;}
                    delete newnode3;
                }
                delete newnode2;
                }*/

        for (int i = 0 ;i < a;i++){
           insert(PhoenixI,knight);
        }
       for (int i = 0;i< b;i++){
          insert(Antidote,knight);
        }
    }
bool BaseBag::insertFirst(BaseItem * item){
    int a = maxbag;
    /*if (a == -1)
    return true;
    BaseItem * g = new antidote;
    g = head;
    int i = 0;
    if (g == nullptr){
    return true;}
    
    while (g != nullptr){
        //cout<<"hello"<<endl;
        g = g->next;
        i++;
    }
    delete g;*/
    int i = countbag();
    if (a>i)
    return true;
    else return false;

}
void BaseBag::insert(ItemType a,BaseKnight * knight){
        if ((knight->getKnightType() != DRAGON)||(a != Antidote)){
        BaseItem *newnode =new antidote;
        newnode->data = a;
        newnode->next = nullptr;
       
        if (head == nullptr){
            head = newnode;
            newnode = newnode->next;
            delete newnode;
        }
        else {
        newnode->next = head;
        head =newnode;
        while (newnode != nullptr){
            newnode =newnode->next;
        }
        delete newnode;
        }
        
    }}

 BaseItem * BaseBag:: get(ItemType itemType){
        BaseItem *p = head;
        int kiemtra = 0;
        for(int i = 0;i < this->countbag();i++){
            if(p->data == itemType){
                kiemtra = 1;
                break;
            }
            p = p->next;
        }
        if (kiemtra == 1){
        BaseItem *p1 = head;
        p->data = p1 ->data;
        head = p1->next;
        delete p1;
        }
        //delete p;
        return head;
        }
string BaseBag::toString() const{
        string a1 ="Bag[count=";
        BaseItem *p = head;
        if (p == nullptr) {   
            return a1 +"0;]";
        }
        
            int number = 0;
        while (p  != nullptr) {
            number++;
            p = p->next;
        }
        a1 = a1 + to_string(number);
        BaseItem *f = head;
        for (int i = 0; i< number;i++){
            if (i == 0){
                if (f->data == Antidote)
            a1 = a1 + ";Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ";PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ";PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ";PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ";PhoenixIV";
            f = f->next;
            }
            else {
            if (f->data == Antidote)
            a1 = a1 + ",Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ",PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ",PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ",PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ",PhoenixIV";
            f = f->next;}
        }
        while (f != nullptr){
            f = f->next;
        }
        a1 = a1+"]";
        return a1;
    }
int BaseBag:: countbag(){
    if (head == nullptr)
    return 0;
    int i =0;
    BaseItem *p = head;
    while (p != nullptr){
        p = p->next;
        i++;
    }
    //delete p;
    return i;
    
}
bool paladinbag::insertFirst(BaseItem * item){
     return true;

}
bool lancelotbag::insertFirst(BaseItem * item){
    BaseItem * g = new antidote;
    g = head;
    int i = 1;
    while (g->next != nullptr){
        g = g->next;
        i++;
    }
    if (16>i)
    return true;
    else return false;

}
bool normalbag::insertFirst(BaseItem * item){
    BaseItem * g = new antidote;
    g = head;
    int i = 1;
    while (g->next != nullptr){
        g = g->next;
        i++;
    }
    if (19>i)
    return true;
    else return false;

}
bool dragonbag::insertFirst(BaseItem * item){
    BaseItem * g = head;
    int i = 1;
    while (g->next != nullptr){
        g = g->next;
        i++;
    }
    if (14>i)
    return true;
    else return false;

}
BaseItem * paladinbag:: get(ItemType itemType){
        BaseItem *p = head;
        int kiemtra = 0;
        for(int i = 0;i < this->countbag();i++){
            if(p->data == itemType){
                kiemtra = 1;
                break;
            }
            p = p->next;
        }
        if (kiemtra == 1){
        BaseItem *p1 = head;
        ItemType x = p1->data;
        p1->data = p ->data;
        p->data = x;
        head = p1->next;
        delete p1;
        }
        return head;
        }
BaseItem * dragonbag:: get(ItemType itemType){
        BaseItem *p = head;
        int kiemtra = 0;
        for(int i = 0;i < this->countbag();i++){
            if(p->data == itemType){
                kiemtra = 1;
                break;
            }
            p = p->next;
        }
        if (kiemtra == 1){
        BaseItem *p1 = head;
        ItemType x = p1->data;
        p1->data = p ->data;
        p->data = x;
        head = p1->next;
        delete p1;
        }
        return head;
        } 
BaseItem * lancelotbag:: get(ItemType itemType){
        BaseItem *p = head;
        int kiemtra = 0;
        for(int i = 0;i < this->countbag();i++){
            if(p->data == itemType){
                kiemtra = 1;
                break;
            }
            p = p->next;
        }
        if (kiemtra == 1){
        BaseItem *p1 = head;
        ItemType x = p1->data;
        p1->data = p ->data;
        p->data = x;
        head = p1->next;
        delete p1;
        }
        return head;
        }
BaseItem * normalbag:: get(ItemType itemType){
        BaseItem *p = head;
        int kiemtra = 0;
        for(int i = 0;i < this->countbag();i++){
            if(p->data == itemType){
                kiemtra = 1;
                break;
            }
            p = p->next;
        }
        if (kiemtra == 1){
        BaseItem *p1 = head;
        ItemType x = p1->data;
        p1->data = p ->data;
        p->data = x;
        head = p1->next;
        delete p1;
        }
        return head;
        }   
string paladinbag::toString() const{
        string a1 ="Bag[count=";
        BaseItem *p = head;
        if (p == nullptr){
            return a1 +"0;]";
        }
        else {int number =1;
        while (p->next != nullptr) {
            number++;
            p = p->next;
        }
        a1 = a1 + to_string(number);
        BaseItem *f = head;
        for (int i = 0; i< number;i++){
            if (i == 0){
                if (f->data == Antidote)
            a1 = a1 + ";Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ";PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ";PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ";PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ";PhoenixIV";
            f = f->next;
            }
            else {
            if (f->data == Antidote)
            a1 = a1 + ",Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ",PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ",PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ",PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ",PhoenixIV";
            f = f->next;}
        }}
        a1 = a1+"]";
        return a1;
    }
string lancelotbag::toString() const{
        string a1 ="Bag[count=";
        BaseItem *p = head;
        if (p == nullptr){
            return a1 +"0;]";
        }
        else {int number =1;
        while (p->next != nullptr) {
            number++;
            p = p->next;
        }
        a1 = a1 + to_string(number);
        BaseItem *f = head;
        for (int i = 0; i< number;i++){
            if (i == 0){
                if (f->data == Antidote)
            a1 = a1 + ";Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ";PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ";PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ";PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ";PhoenixIV";
            f = f->next;
            }
            else {
            if (f->data == Antidote)
            a1 = a1 + ",Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ",PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ",PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ",PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ",PhoenixIV";
            f = f->next;}
        }}
        a1 = a1+"]";
        return a1;
    }
string dragonbag::toString() const{
        string a1 ="Bag[count=";
        BaseItem *p = head;
        if (p == nullptr){
            return a1 +"0;]";
        }
        else {int number =1;
        while (p->next != nullptr) {
            number++;
            p = p->next;
        }
        a1 = a1 + to_string(number);
        BaseItem *f = head;
        for (int i = 0; i< number;i++){
            if (i == 0){
                if (f->data == Antidote)
            a1 = a1 + ";Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ";PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ";PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ";PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ";PhoenixIV";
            f = f->next;
            }
            else {
            if (f->data == Antidote)
            a1 = a1 + ",Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ",PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ",PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ",PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ",PhoenixIV";
            f = f->next;}
        }}
        a1 = a1+"]";
        return a1;
    }
string normalbag::toString() const{
        string a1 ="Bag[count=";
        BaseItem *p = head;
        if (p == nullptr){
            return a1 +"0;]";
        }
        else {int number =1;
        while (p->next != nullptr) {
            number++;
            p = p->next;
        }
        a1 = a1 + to_string(number);
        BaseItem *f = head;
        for (int i = 0; i< number;i++){
            if (i == 0){
                if (f->data == Antidote)
            a1 = a1 + ";Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ";PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ";PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ";PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ";PhoenixIV";
            f = f->next;
            }
            else {
            if (f->data == Antidote)
            a1 = a1 + ",Antidote";
            else if (f->data == PhoenixI)
            a1 = a1 + ",PhoenixI";
            else if (f->data == PhoenixII)
            a1 = a1 + ",PhoenixII";
            else if (f->data == PhoenixIII)
            a1 = a1 + ",PhoenixIII";
            else if (f->data == PhoenixIV)
            a1 = a1 + ",PhoenixIV";
            f = f->next;}
        }}
        a1 = a1+"]";
        return a1;
    }    
void BaseOpponent:: setupfight(BaseKnight * knight, Events * event){
}
void Madbear:: setupfight(BaseKnight *  knight, Events * event,int i){
            setlevelO((i+event->Event[i])%10+1);
            if ((knight->getlevel() >= getlevelO())||(knight->getKnightType()==LANCELOT)||(knight->getKnightType()==PALADIN)){
                knight->setgil(knight->getgil()+100);
            }
            else {
                knight->sethp(knight->gethp()-10*(getlevelO()-knight->getlevel()));
            }
    }
void Bandit:: setupfight(BaseKnight *  knight, Events * event,int i){
            setlevelO((i+event->Event[i])%10+1);
            if ((knight->getlevel() >= getlevelO())||(knight->getKnightType()==LANCELOT)||(knight->getKnightType()==PALADIN)){
                knight->setgil(knight->getgil()+150);
                
            }
            else {
                knight->sethp(knight->gethp()-15*(getlevelO()-knight->getlevel()));
            }
    }
void LordLupin:: setupfight(BaseKnight *  knight, Events * event,int i){
            setlevelO((i+event->Event[i])%10+1);
            if ((knight->getlevel() >= getlevelO())||(knight->getKnightType()==LANCELOT)||(knight->getKnightType()==PALADIN)){
                knight->setgil(knight->getgil()+450);
            }
            else {
                knight->sethp(knight->gethp()-45*(getlevelO()-knight->getlevel()));
            }
    }
void Elf:: setupfight(BaseKnight *  knight, Events * event,int i){
            setlevelO((i+event->Event[i])%10+1);
            if ((knight->getlevel() >= getlevelO())||(knight->getKnightType()==LANCELOT)||(knight->getKnightType()==PALADIN)){
                knight->setgil(knight->getgil()+750);
            }
            else {
                knight->sethp(knight->gethp()-75*(getlevelO()-knight->getlevel()));
            }
    }
void Troll:: setupfight(BaseKnight *  knight, Events * event,int i){
            setlevelO((i+event->Event[i])%10+1);
            if ((knight->getlevel() >= getlevelO())||(knight->getKnightType()==LANCELOT)||(knight->getKnightType()==PALADIN)){
                knight->setgil(knight->getgil()+800);
            }
            else {
                knight->sethp(knight->gethp()-95*(getlevelO()-knight->getlevel()));
            }
    }
void Tornbery:: setupfight(BaseKnight *  knight, Events * event,int i){
            setlevelO((i+event->Event[i])%10+1);
            if (knight->getlevel() >= getlevelO()){
                knight->setlevel(knight->getlevel()+1);
                if (knight->getlevel()>10)
                knight->setlevel(10);
            }
            else if(knight->getKnightType()!= DRAGON){
                knight->setpoisoned(1);
            }
    }
void QueenofCard:: setupfight(BaseKnight * knight,Events * event,int i){
            setlevelO((i+event->Event[i])%10+1);
            if (knight->getlevel() >= getlevelO()){
                knight->setgil((knight->getgil())*2);
            }
            else if (knight->getKnightType()!=PALADIN){
                knight->setgil(knight->getgil()/2);
            }
    }
void Ninadering:: setupfight(BaseKnight *  knight, Events * event){
            if(((knight->getgil()>=50)||(knight->getKnightType()==PALADIN))&&(knight->gethp()<knight->getmaxhp()/3)){
                if (knight->getKnightType()!=PALADIN){
                knight->setgil(knight->getgil()-50);}
                knight ->sethp(knight->gethp()+knight->getmaxhp()/5);
            }
    }
void DurianGarden:: setupfight(BaseKnight *  knight, Events * event){
            knight->sethp(knight->getmaxhp());
    }
void OmegaWeapon:: setupfight(BaseKnight *  knight, Events * & event){
            if(event->killOmega == 0){
            if (((knight->getlevel()==10)&&(knight->gethp()==knight->getmaxhp()))||(knight->getKnightType()==DRAGON)){
                knight->setlevel(10);
                knight->setgil(999);
            event->killOmega = 1;
            }
            else {
                knight->sethp(0);
            }
    }}
 void Hades:: setupfight(BaseKnight *  knight, Events * & event){
          if (event->killHades==0){  
            if ((knight->getlevel() == 10)||((knight->getlevel()>=8)&&(knight->getKnightType() == PALADIN))){
               event->killHades =1;
               event->shield =1;
            }
            else {
                knight->sethp(0);
            }
    }}
BaseKnight * BaseKnight:: create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    // khởi tạo army
       BaseKnight * army = new BaseKnight;
       army->id = id;
       army->hp =maxhp;
       army->maxhp = maxhp;
       army->level = level;
       army->gil = gil;
       army->antidote = antidote;
       army->phoenixdownI = phoenixdownI;
       army->poisoned = 0;
    if (Prime(maxhp)==1){    
        army->knightType = PALADIN;
        }
    else if(maxhp == 888){
        army->knightType = LANCELOT;
        }
    else if(dragonG(maxhp)==1){       
        army->knightType = DRAGON;
       }
    else{        
       army->knightType = NORMAL;
      }
      
      /*if (phoenixdownI > 0){
        for (int i = 0; i< phoenixdownI; i++){
            army->bag->insert(PhoenixI,army);
        }
      }
      if (antidote> 0){
        for (int i = 0; i< antidote; i++){
            army->bag->insert(Antidote,army);
        }
      }*/
    //khởi tạo bag của army
    army->bag = new BaseBag(army);
    return army;}
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
ArmyKnights::ArmyKnights (const string & file_armyknights){
        ifstream ifs;
        ifs.open(file_armyknights);
        ifs >> numbersoilder;
        Army = new BaseKnight*[numbersoilder];
        int hp, level, phoenixdownI, gil, antidote;
        for (int i = 0;i<numbersoilder;i++){
            ifs >> hp >> level >> phoenixdownI >> gil >> antidote;
            Army[i] = BaseKnight::create(i+1, hp, level, gil, antidote, phoenixdownI);
        }
    ifs.close();}
ArmyKnights:: ~ArmyKnights(){
    // delete matrix** phải delete từng thằng ptr trước ròi mới delete ptr của các ptr
        for (int i=0; i<numbersoilder;i++) {
            delete Army[i]->bag;
            delete Army[i];
        }
        delete[] Army;
        Army = nullptr;
    }
bool ArmyKnights:: fight(BaseOpponent * opponent,BaseKnight * knight){
    int hp1 = knight->gethp();
    int gil1 = knight->getgil();
              if ((opponent->event)->Event[opponent->id] == 1){
                    Madbear * a = new Madbear;  
                      a->setupfight(knight,opponent->event,opponent->id);
                      delete a;
                      a = nullptr;
                }
                else if ((opponent->event)->Event[opponent->id] == 2){
                    Bandit * a = new Bandit;  
                      a->setupfight(knight,opponent->event,opponent->id);
                      delete a;
                      a = nullptr;
                }
                else if ((opponent->event)->Event[opponent->id] == 3){
                    LordLupin * a = new LordLupin;  
                      a->setupfight(knight,opponent->event,opponent->id);
                      delete a;
                      a = nullptr;
                }
                else if ((opponent->event)->Event[opponent->id] == 4){
                    Elf * a = new Elf;  
                      a->setupfight(knight,opponent->event,opponent->id);
                      delete a;
                      a = nullptr;
                }
                else if ((opponent->event)->Event[opponent->id] == 5){
                    Troll * a = new Troll;  
                      a->setupfight(knight,opponent->event,opponent->id);
                      delete a;
                      a = nullptr;
                }
                else if ((opponent->event)->Event[opponent->id] == 6){
                    Tornbery * a = new Tornbery;  
                      a->setupfight(knight,opponent->event,opponent->id);
                      delete a;
                      a = nullptr;
                }
                else if ((opponent->event)->Event[opponent->id] == 7){
                    QueenofCard * a = new QueenofCard;  
                      a->setupfight(knight,opponent->event,opponent->id);
                      delete a;
                      a = nullptr;
                }
                else if ((opponent->event)->Event[opponent->id] == 8){
                    Ninadering * a = new Ninadering;  
                      a->setupfight(knight,opponent->event);
                      delete a;
                      a = nullptr;
                      return true;
                }
                else if ((opponent->event)->Event[opponent->id] == 9){
                    DurianGarden * a = new DurianGarden;  
                      a->setupfight(knight,opponent->event);
                      delete a;
                      a = nullptr;
                      return true;
                }
                else if ((opponent->event)->Event[opponent->id] == 10){
                    OmegaWeapon * a = new OmegaWeapon;  
                      a->setupfight(knight,opponent->event);
                      delete a;
                      a = nullptr;
                }
                else if ((opponent->event)->Event[opponent->id] == 11){
                    Hades * a = new Hades;  
                      a->setupfight(knight,opponent->event);
                      delete a;
                      a = nullptr;
                }
                if ((knight->gethp()==hp1)&&(knight->getpoisoned()==0)&&(knight->getgil()>=gil1))
                return true;
                else return false;


}
bool ArmyKnights:: adventure (Events * events){
    if (events->thang == 1)
    return true;
    else return false;
 }
int ArmyKnights:: count() const{
         int coun =0;
         for (int i =0; i< numbersoilder;i++){
             if (Army[i]->gethp()>0)
             coun++;
         }
         return coun;
    }
BaseKnight * ArmyKnights:: lastKnight() const{
        for (int i = numbersoilder-1;i>=0;i--){
            if (Army[i]->gethp()> 0)
            return Army[i];            
        }
        return nullptr;
        
    }
 bool ArmyKnights :: hasPaladinShield() const{
            if (this->shield == 1)
            return true;
            else return false;
    }
    bool ArmyKnights:: hasLancelotSpear() const{
        if (this->spear == 1)
            return true;
            else return false;
    }
    bool ArmyKnights:: hasGuinevereHair() const{
        if (this->hair == 1)
            return true;
            else return false;
    }
    bool ArmyKnights:: hasExcaliburSword() const{
        if (this->sword == 1)
            return true;
            else return false;
    }
void ArmyKnights::printInfo(Events * event) const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}
void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
void ArmyKnights:: set(Events * event){
        this->shield = event->shield;
        this->spear = event->spear;
        this->hair = event->hair;
        this->sword = event->sword;
    }

Events::Events (const string & file_events){
    ifstream ifs;
    ifs.open(file_events);
    ifs >> n;
    Event = new int[n];
    for (int i = 0;i < n;i++){
        ifs >> Event[i];
    }
    ifs.close();}
Events:: ~Events(){
        delete[] Event;
    }
int Events:: count() const {
        return n;
    }
int Events:: get(int i) const  {   return Event[i]; }
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure:: ~KnightAdventure(){
        delete armyKnights;
        delete events;
    }
void KnightAdventure:: loadArmyKnights(const string & a){
    // khởi tạo member armyknight (ptr)
        armyKnights = new ArmyKnights(a);}
    void KnightAdventure:: loadEvents(const string & a){
    // khởi tạo member events (ptr)
        events = new Events(a);
    }
    void KnightAdventure:: run(){
        
          int k = armyKnights->numbersoilder - 1;
        for (int i = k;i >= 0 ;i--){                      
                if ((armyKnights->Army[i])->getKnightType() == DRAGON){
                    int d = (armyKnights->Army[i])->getAntidote();
                    for (int n = 0;n<d;n++){
                        BaseItem * tmp = (armyKnights->Army[i])->bag->get(Antidote);
                    }
                }
        }
        knight = armyKnights->Army[k];
            for (int i = 0;i<(events->n);i++){
                int maucogiamko = knight->gethp();
                if (events->Event[i] == 1){
                    Madbear * a = new Madbear;  
                      a->setupfight(knight,events,i);
                      delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 2){
                     Bandit * a = new Bandit;  
                      a->setupfight(knight,events,i);
                      delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 3){
                     LordLupin * a = new LordLupin;  
                      a->setupfight(knight,events,i);
                       delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 4){
                   Elf * a = new Elf;  
                      a->setupfight(knight,events,i);
                       delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 5){
                    Troll * a = new Troll;  
                      a->setupfight(knight,events,i);
                       delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 6){
                     Tornbery * a = new Tornbery;  
                      a->setupfight(knight,events,i);
                       delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 7){
                       QueenofCard * a = new QueenofCard;  
                      a->setupfight(knight,events,i);
                       delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 8){
                    Ninadering * a = new Ninadering;  
                      a->setupfight(knight,events);
                       delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 9){
                    DurianGarden * a = new DurianGarden;  
                      a->setupfight(knight,events);
                      delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 10){
                    OmegaWeapon * a = new OmegaWeapon;  
                      a->setupfight(knight,events);
                      delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 11){
                    Hades * a = new Hades;  
                      a->setupfight(knight,events);
                       delete a;
                      a = nullptr;
                }
                else if (events->Event[i] == 112){
                    if ((knight->bag->countbag()<knight->bag->maxbag)||(knight->bag->maxbag == -1)){
                    knight->bag->insert(PhoenixII,knight);}
                    else {
                        int f = k -1;
                        while (f >= 0){
                            if (((armyKnights->Army[f])->bag->countbag()<armyKnights->Army[f]->bag->maxbag)||(armyKnights->Army[f]->bag->maxbag==-1)){
                                    (armyKnights->Army[f])->bag->insert(PhoenixII,(armyKnights->Army[f]));
                                    break;
                            }
                            else {
                                f = f -1;
                            }
                        }
                    }
                    armyKnights->printInfo(events);
                    continue;
                }
                else if (events->Event[i] == 113){
                     if ((knight->bag->countbag()<knight->bag->maxbag)||(knight->bag->maxbag == -1)){
                    knight->bag->insert(PhoenixIII,knight);}
                    else {
                        int f = k -1;
                        while (f >= 0){
                            if (((armyKnights->Army[f])->bag->countbag()<armyKnights->Army[f]->bag->maxbag)||(armyKnights->Army[f]->bag->maxbag==-1)){
                                    (armyKnights->Army[f])->bag->insert(PhoenixIII,(armyKnights->Army[f]));
                                    break;
                            }
                            else {
                                f = f -1;
                            }
                        }
                    }
                    armyKnights->printInfo(events);
                    continue;
                }
                else if (events->Event[i] == 114){
                     if ((knight->bag->countbag()<knight->bag->maxbag)||(knight->bag->maxbag == -1)){
                    knight->bag->insert(PhoenixIV,knight);}
                    else {
                        int f = k -1;
                        while (f >= 0){
                            if (((armyKnights->Army[f])->bag->countbag()<armyKnights->Army[f]->bag->maxbag)||(armyKnights->Army[f]->bag->maxbag==-1)){
                                    (armyKnights->Army[f])->bag->insert(PhoenixIV,(armyKnights->Army[f]));
                                    break;
                            }
                            else {
                                f = f -1;
                            }
                        }
                    }
                    armyKnights->printInfo(events);
                    continue;
                }
                else if (events->Event[i] == 95){
                    events->shield =1;
                }
                else if (events->Event[i] == 96){
                    events->spear =1;
                }
                else if (events->Event[i] == 97){
                    events->hair =1;
                }
                else if (events->Event[i] == 98){
                    if ((events->shield == 1)&&(events->spear==1)&&(events->hair==1))
                    events->sword =1;
                }
                if (knight->getgil()>999){
                    int phandu = knight->getgil()-999;
                    knight->setgil(999);
                    int f = k - 1;
                    while (phandu > 0){
                        if (f == -1)
                        break;
                        (armyKnights->Army[f])->setgil((armyKnights->Army[f])->getgil()+phandu);
                        if ((armyKnights->Army[f])->getgil()>999){
                            phandu = (armyKnights->Army[f])->getgil()-999;
                            (armyKnights->Army[f])->setgil(999);
                            f--;
                        }
                        else {phandu =0;}
                    }
                }
                if (knight->getpoisoned()==1){
                    int haveantidote =0;
                    if ((knight->bag)->countbag()>0){
                    BaseItem * p = (knight->bag)->head;
                    
                    for (int i = 0; i< (knight->bag)->countbag();i++){
                        if (p->data == Antidote){
                            BaseItem * tmp = (knight->bag)->get(Antidote);
                            haveantidote =1;
                            knight->setpoisoned(0);
                            break;
                        }
                        p = p->next;
                    }}
                    if (haveantidote == 0){
                        knight->sethp(knight->gethp()-10);
                        knight->setpoisoned(0);
                        if ((knight->bag)->countbag()>=3){
                        BaseItem * f = (knight->bag)->head;
                        for (int i =0;i< 3;i++){
                            f = (knight->bag)->head;
                            (knight->bag)->head = (knight->bag)->head->next;
                            delete f;
                        }
                        f = nullptr;
                        }
                        else {
                            BaseItem * f = (knight->bag)->head;
                        while((knight->bag)->head != nullptr){
                            f = (knight->bag)->head;
                            (knight->bag)->head = (knight->bag)->head->next;
                            delete f;
                        }
                        f = nullptr;}

                    }

                }
                if ((knight->gethp()<maucogiamko)&&(knight->gethp()>0)&&((knight->bag)->countbag()>0)){
                    ItemType t = OFF;
                    BaseItem * p  = (knight->bag)->head;
                        if (p != nullptr)
                            t = p->data;

                    for (int i =0;i <(knight->bag)->countbag();i++){
                        if (p->data != Antidote){
                            t =p->data;
                            if (t == PhoenixI){
                        
                        phoenixI * b = new phoenixI;
                    if (b->canUse(knight)) {
                        b->use(knight);
                        delete b;
                        b =nullptr;
                        BaseItem * tmp = knight->bag->get(t);
                        break;}
                        delete b;
                        b =nullptr;
                        }
                    else if (t == PhoenixII){
                       
                        phoenixII * b = new phoenixII;
                    if (b->canUse(knight)) {
                        b->use(knight);
                         delete b;
                        b =nullptr;
                        BaseItem * tmp = knight->bag->get(t);
                        break;}
                        delete b;
                        b =nullptr;
                    }
                    else if (t == PhoenixIII){
                       
                        phoenixIII * b = new phoenixIII;
                    if (b->canUse(knight)) {
                        b->use(knight);
                        delete b;
                        b =nullptr;
                        BaseItem * tmp = knight->bag->get(t);
                        break;}
                        delete b;
                        b =nullptr;
                        
                     }
                    else if (t == PhoenixIV){
                        
                        phoenixIV * b = new phoenixIV;
                    if (b->canUse(knight)) {
                        b->use(knight);
                        delete b;
                        b =nullptr;
                        BaseItem * tmp = knight->bag->get(t);
                        break;}
                        delete b;
                        b =nullptr;
                    }
                            
                        }
                        p = p->next;
                    }
                
                }
                
                if (knight->gethp()<=0){
                    
                if ((knight->bag)->countbag()>0){
                    
                ItemType t = OFF;
                BaseItem * p = (knight->bag)->head;
                if (p != nullptr)
                t = p->data;
                for (int i =0;i <(knight->bag)->countbag();i++){
                    if (p->data != Antidote){
                        t = p->data;
                        if (t == PhoenixI){
                phoenixI * b = new phoenixI;
                    if (b->canUse(knight)) {
                        BaseItem * tmp = knight->bag->get(t);
                        b->use(knight);}
                delete b;
                b =nullptr;
            }
            else if (t == PhoenixII){
               
                phoenixII * b= new phoenixII;
                    if (b->canUse(knight)) {
                        BaseItem * tmp = knight->bag->get(t);
                        b->use(knight);
                        }
                delete b;
                b = nullptr;        
            }
            else if (t == PhoenixIII){
                
                phoenixIII * b = new phoenixIII;
                    if (b->canUse(knight)) {
                        BaseItem * tmp = knight->bag->get(t);
                        b->use(knight);
                        }
                delete b;
                b = nullptr;
            }
            else if (t == PhoenixIV){
                phoenixIV * b = new phoenixIV;
                    if (b->canUse(knight)) {
                        BaseItem * tmp = knight->bag->get(t);                   
                        b->use(knight);}
                delete b;
                b = nullptr;
            }
                        if (knight->gethp()>0)
                        break;
                    }
               p = p->next;
                }
        
        }     
       }
       if ((knight->getgil()>=100)&&(knight->gethp() <= 0)){
                    knight->sethp(knight->getmaxhp()/2);
                    knight->setgil(knight->getgil()-100);
                } 
        if (knight->gethp()<=0){
                if (k == 0){
                    
                    events->thang = 0;
                    goto endcode;
                }
                else { 
                    
                k--;
                knight = armyKnights->Army[k];
                }
        }
       if (events->Event[i]!=99){
        armyKnights->set(events);
        armyKnights->printInfo(events);}

        if (events->Event[i]== 99){
                
                        if (events->sword == 1){
                            
                            events->thang = 1;
                            goto endcode;
                        }
                        else if ((events->shield == 1)&&(events->spear == 1)&&(events->hair == 1)){
                            int hpboss = 5000;
                            for (int j = k; j>=0;j--){
                                knight = armyKnights->Army[j];
                                if (knight->getKnightType() == NORMAL){
                                    if (j == 0){
                                        for (int m = armyKnights->numbersoilder - 1;m>=0;m--){
                                                armyKnights->Army[m]->sethp(0);
                                                        }
                                               
                                                events->thang = 0;
                                                goto endcode;
                                            }
                                }
                                else if (knight->getKnightType() == DRAGON){
                                        int damage = knight->gethp()*knight->getlevel()*0.075;
                                        hpboss = hpboss - damage;
                                        if (hpboss <= 0){
                                          
                                           events->thang = 1;
                                            goto endcode;
                                        }
                                        else {
                                            knight->sethp(0);
                                            
                                            if (j == 0){
                                                for (int m = armyKnights->numbersoilder - 1;m>=0;m--){
                                                            armyKnights->Army[m]->sethp(0);
                                                            }
                                                
                                                events->thang = 0;
                                                goto endcode;
                                                break;
                                            }
                                        }
                                }
                                else if (knight->getKnightType() == PALADIN){
                                        int damage = knight->gethp()*knight->getlevel()*0.06;
                                        hpboss = hpboss - damage;
                                        if (hpboss <= 0){
                                           
                                           events->thang = 1;
                                                goto endcode;
                                        }
                                        else {
                                            knight->sethp(0);
                                            
                                            if (j == 0){
                                                for (int m = armyKnights->numbersoilder - 1;m>=0;m--){
                                                        armyKnights->Army[m]->sethp(0);
                                                            }
                                                
                                                events->thang = 0;
                                                goto endcode;
                                                break;
                                            }
                                        }
                                }
                                else if (knight->getKnightType() == LANCELOT){
                                        int damage = knight->gethp()*knight->getlevel()*0.05;
                                        hpboss = hpboss - damage;
                                        if (hpboss <= 0){
                                            
                                            events->thang = 1;
                                               goto endcode;
                                        }
                                        else {
                                            knight->sethp(0);
                                            
                                            if (j == 0){
                                                for (int m = armyKnights->numbersoilder - 1;m>=0;m--){
                                                         armyKnights->Army[m]->sethp(0);
                                                                         }   
                                                
                                                events->thang = 0;
                                                goto endcode;
                                                break;
                                            }
                                        }
                                }
                        }}
                        else {
                            for (int m = armyKnights->numbersoilder - 1;m>=0;m--){
                                armyKnights->Army[m]->sethp(0);
                                
                            }
                            
                            events->thang = 0;
                            goto endcode;

                        }                
            }
        }
            if (knight->gethp()>0)
            events->thang = 1;
            else events->thang = 0;
            goto endcode1;


endcode:            armyKnights->printInfo(events);
endcode1:           if (events->thang == 1)
         armyKnights->printResult(1);
         else armyKnights->printResult(0);  
        
        
        
}

/* * * END implementation of class KnightAdventure * * */