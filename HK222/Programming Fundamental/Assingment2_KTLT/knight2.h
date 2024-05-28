#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"
class BaseBag;
class BaseOpponent;
class BaseKnight;
class ArmyKnights;
class BaseItem;
class Events;

// #define DEBUG

// Thứ tự class: BaseKnight -> BaseItem -> BaseBag ...
enum ItemType {Antidote,PhoenixI,PhoenixII,PhoenixIII,PhoenixIV,OFF};//Loại OFF dùng để kiểm tra khúc túi còn đồ cần xài hay ko
enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL};
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;  
    KnightType knightType;
    int poisoned; // 1 là có độc 0 là ko độc
public:
    BaseBag * bag;
    int getgil(){return gil;}
    void setgil(int a){gil = a;}
    int getlevel(){return level;}
    void setlevel(int a){level = a;}
    int getphoenixI(){return phoenixdownI;}
    void setphoenixI(int a){phoenixdownI = a;}
    int getAntidote(){return antidote;}
    void setAntidote(int a){antidote = a;}
    int gethp(){return hp;}
    void sethp(int a){hp = a;}
    int getmaxhp(){return maxhp;}
    void setmaxhp(int a){maxhp = a;}
    int getKnightType(){return knightType;}
    void setKnightType(KnightType a){knightType = a;}
    int getpoisoned(){return poisoned;}
    void setpoisoned(int a){poisoned = a;}
   
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;//ko làm
   virtual ~BaseKnight() = default;
};
class Paladin: public BaseKnight{
        public:
        Paladin(){
            setKnightType(PALADIN);
        }
        KnightType get(){
            return PALADIN;
        }
};
class Dragon: public BaseKnight{
        public:
        Dragon(){
            setKnightType(DRAGON);
        }
        KnightType get(){
            return DRAGON;
        }
};
class Lancelot: public BaseKnight{
        public:
        Lancelot(){
        setKnightType(LANCELOT);}
        KnightType get(){
            return LANCELOT;
        }

};
class Normal: public BaseKnight{
        public:
        Normal(){
        setKnightType(NORMAL);}
        KnightType get(){
            return NORMAL;
        }

};

class BaseItem {

public:
    ItemType data;
    BaseItem *next;
    virtual bool canUse ( BaseKnight * knight) = 0 ;
    virtual void use ( BaseKnight * knight ) = 0 ;
};

class antidote : public BaseItem {
    public:
    antidote(){
            data = Antidote;
    }
    bool canUse (BaseKnight * knight);
    void use (BaseKnight * knight);
    ~antidote() = default;
};
class phoenixI: public BaseItem {
    public:
    phoenixI(){
       data = PhoenixI;}
    bool canUse (BaseKnight *  knight);
    void use (BaseKnight *  knight);
};
class phoenixII: public BaseItem {
    public:
    phoenixII(){
        data = PhoenixII;
    }
    bool canUse (BaseKnight * knight);
    void use (BaseKnight *  knight);
};
class phoenixIII: public BaseItem {
    public:
    phoenixIII(){
        data = PhoenixIII;
    }
    bool canUse (BaseKnight * knight);
    void use (BaseKnight *  knight);
};
class phoenixIV: public BaseItem {
    public:
    phoenixIV(){
        data = PhoenixIV;
    }
    bool canUse (BaseKnight * knight);
    void use (BaseKnight *  knight);
};
 class BaseBag {
public:
    int maxbag;
    BaseItem * head;
    BaseBag(BaseKnight * knight);
    virtual bool insertFirst(BaseItem * item);
            void insert(ItemType a,BaseKnight * knight);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
     ~BaseBag(){
       BaseItem *temp = head;
       /*if (head == nullptr){
        temp = head;
        delete temp;
       }*/
       while (head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
       }
       //delete temp;
       temp = nullptr;
     }
     int countbag();
}; 
class paladinbag:public BaseBag {
        bool insertFirst(BaseItem * item);
        BaseItem * get(ItemType itemType);
        string toString() const;
}; 
class lancelotbag:public BaseBag {
        bool insertFirst(BaseItem * item);
        BaseItem * get(ItemType itemType);
        string toString() const;
}; 
class dragonbag:public BaseBag {
        bool insertFirst(BaseItem * item);
        BaseItem * get(ItemType itemType);
        string toString() const;
}; 
class normalbag:public BaseBag {
        bool insertFirst(BaseItem * item);
        BaseItem * get(ItemType itemType);
        string toString() const;
}; 
 class BaseOpponent{
    private:
    int gilnhan;
    int levelO;
    public:
    Events * event;
    int id;
    int getlevelO(){
        return levelO;
    }
    void setlevelO(int a){
        levelO = a;
    }
    int getgilnhan(){
        return gilnhan;
    }
    void setgilnhan(int a){
        gilnhan = a;
    }
    virtual void setupfight(BaseKnight * knight, Events * event);

 };
class Madbear: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * event,int i);
};
class Bandit: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * event,int i);
};
class LordLupin: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * event,int i);
};
class Elf: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * event,int i);
};
class Troll: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * event,int i);
};
class Tornbery: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * event,int i);
};
class QueenofCard: public BaseOpponent {
    public:
    void setupfight(BaseKnight * knight,Events * event,int i);
};
class Ninadering: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * event);
};
class DurianGarden: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * event);
};
class OmegaWeapon: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * & event);
};
class Hades: public BaseOpponent {
    public:
    void setupfight(BaseKnight *  knight, Events * & event);
};



class ArmyKnights {
public:
    int numbersoilder;
    int shield = 0;
    int spear = 0;
    int hair =0;
    int sword =0;
    BaseKnight** Army;
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    void set(Events * event);
    bool fight(BaseOpponent * opponent,BaseKnight * knight);
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void printInfo(Events * event) const;// ko làm
    void printResult(bool win) const;// ko làm
};


class Events {   
    public:
    int n;
    int* Event;
    int killOmega = 0;
    int killHades =0;
    int shield = 0;
    int spear = 0;
    int hair =0;
    int sword =0;
    int thang = 0;
    Events (const string & file_events);
    int count() const ;
    int get(int i) const ;
    ~Events();
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;
    BaseKnight * knight;

public:
    KnightAdventure();// ko làm
    ~KnightAdventure(); 

    void loadArmyKnights(const string & a);
    void loadEvents(const string & a);
    void run();
};
int Prime(int a);
int dragonG(int x);
#endif // __KNIGHT2_H__