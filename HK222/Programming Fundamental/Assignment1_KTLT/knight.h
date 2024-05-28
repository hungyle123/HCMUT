#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
void sukien0 (int & rescue);
void sukien1_5 (int & HP, int & level,int & phoenixdown, int & rescue, int i,int t,int maxHP,int & trangthaitihon,int & trangthaiech,int &levelech,int  specialcharacter);
void sukien6 (int & HP, int & level,int i,int & trangthaitihon, int & laptihon,int &trangthaiech,int specialcharacter);
void sukien7(int & level, int i,int & trangthaiech, int & lapech,int & levelech,int & trangthaitihon,int specialcharacter);
void sukien11 (int & HP, int & level,int & phoenixdown, int maxHP);
void sukien12 (int & HP);
void sukien15_17 (int & remedy, int & maidenkiss, int & phoenixdown,int t);
void sukien19( int & remedy, int & maidenkiss, int & phoenixdown,int & meetasclepius,string  file_asclepius_pack);
void sukien18(int & HP,int  maxHP,int & meetmerlin,string  file_merlin_pack);
void sukien99( int & level, int & rescue,int  specialcharacter);
void sukien13 (int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int t,int maxHP,int & trangthaitihon,int & trangthaiech,int & levelech,string  file_mush_ghost);

#endif // __KNIGHT_H__