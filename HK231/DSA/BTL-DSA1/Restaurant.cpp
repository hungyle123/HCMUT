#include "main.h"
class imp_res : public Restaurant
{
	public:
	class ordertable {
	public:
	string name;
	int energy;
	ordertable * next;

	ordertable(string a, int b){
		name = a;
		energy = b;
		next = nullptr;
		}
	};
	customer *current;
	customer *headwait;
	customer *tailwait;
	customer *headhangchothoigian;
	customer *tailhangchothoigian;
	customer *headtimeline;
	customer *tailtimeline;
	ordertable *headorder;
	int wait;
	int count;
	public:	
		imp_res() {
			current = nullptr;
			headwait= nullptr;
			tailwait = nullptr;
			headorder =nullptr;
			headhangchothoigian =nullptr;
			tailhangchothoigian =nullptr;
			headtimeline = nullptr;
			tailtimeline = nullptr;
			count = 0;
			wait = 0;
		};
		~imp_res(){
			int count2 = count;
			while(count2 != 0){
			ordertable *deltable = headorder;
			headorder=headorder->next;
			deltable->next = nullptr;
			delete deltable;
			count2--;
			}
			headorder = nullptr;

			while(count != 0){
				customer *del = current;
				current = current->next;
				del->next = nullptr;
				del->prev = nullptr;
				delete del;
				removetimeline(del->name);
				count--;
			}
			current = nullptr;

			while (wait != 0){
				customer *del = headwait;
				removehangchothoigian(del->name);
				headwait = headwait->next;
				del->next = nullptr;
				del->prev = nullptr;
				delete del;
				removetimeline(del->name);
				wait--;
			}
			headwait = nullptr;
			tailwait = nullptr;
			headhangchothoigian = nullptr;
			tailhangchothoigian = nullptr;

			//destruc thoigianccho
		}
/***********************************************************************************************************************************************/
		void removeordertable(string &a){
			if (headorder->name == a){
				ordertable * del = headorder;
				headorder = headorder->next;
				delete del;
				return;
			}
			ordertable *temp = headorder;
			while(temp->next->name != a){
				temp = temp->next;
			}
			ordertable *del = temp->next;
			temp->next = temp->next->next;
			delete del;
		}
/***********************************************************************************************************************************************/
		bool iftable(string & a){
			ordertable *temp = headorder;
			while (temp->next != nullptr){
				if (temp->name == a){
					return true;
				}

				temp = temp->next;
			}
			return false;
		}
/***********************************************************************************************************************************************/
		string findname(){
			customer *temp = headtimeline;
			while (!iftable(temp->name)){
				temp = temp->next;
			}
			return temp->name;

		}		
/***********************************************************************************************************************************************/
		void addtimeline(string& a, int b){
			customer * newnode = new customer(a,b,nullptr,nullptr);
			if (headtimeline == nullptr){
				headtimeline = newnode;
				tailtimeline = newnode;
			}
			else {
				tailtimeline->next = newnode;
				newnode->prev = tailtimeline;
				tailtimeline = newnode;
			}
		}
/***********************************************************************************************************************************************/
		void removetimeline(string& a){					
			if (headtimeline->name == a){
				customer * temp = headtimeline;
				headtimeline = headtimeline->next;
				
				if (headtimeline != nullptr)
				headtimeline->prev = nullptr;
				
				delete temp;
				return;
			}
			if (tailtimeline->name == a){
				customer * temp = tailtimeline;
				tailtimeline = tailtimeline->prev;
				
				if (tailtimeline != nullptr)
				tailtimeline->next = nullptr;
				
				delete temp;
				return;
			}
			customer * temp = headtimeline;
			while(temp->next->name != a){
				temp = temp->next;
			}
			customer *del = temp->next;
			temp->next->next->prev = temp;
			temp->next = temp->next->next;
			delete del;
		}
/***********************************************************************************************************************************************/
		void addwait(string& a, int b){
			customer * newnode = new customer(a,b,nullptr,nullptr);
			if (headwait == nullptr){
				headwait = newnode;
				tailwait = newnode;
			}
			else {
				tailwait->next = newnode;
				newnode->prev = tailwait;
				tailwait = newnode;
			}
		}
/***********************************************************************************************************************************************/
		void removewait(string& a){					// cac ham nay ko dung den bien wait rieng !!!
			if (headwait->name == a){
				customer * temp = headwait;
				headwait = headwait->next;
				
				if (headwait != nullptr)
				headwait->prev = nullptr;
				
				delete temp;
				return;
			}
			if (tailwait->name == a){
				customer * temp = tailwait;
				tailwait = tailwait->prev;
				
				if (tailwait != nullptr)
				tailwait->next = nullptr;
				
				delete temp;
				return;
			}
			customer * temp = headwait;
			while(temp->next->name != a){
				temp = temp->next;
			}
			customer *del = temp->next;
			temp->next->next->prev = temp;
			temp->next = temp->next->next;
			delete del;
		}
/***********************************************************************************************************************************************/
		void addhangchothoigian(string& a, int b){
			customer * newnode = new customer(a,b,nullptr,nullptr);
			if (headhangchothoigian == nullptr){
				headhangchothoigian = newnode;
				tailhangchothoigian = newnode;
			}
			else {
				tailhangchothoigian->next = newnode;
				newnode->prev = tailhangchothoigian;
				tailhangchothoigian = newnode;
			}
		}
/***********************************************************************************************************************************************/
		void removehangchothoigian(string& a){
			if (headhangchothoigian->name == a){
				customer * temp = headhangchothoigian;
				headhangchothoigian = headhangchothoigian->next;
				
				if (headhangchothoigian != nullptr)
				headhangchothoigian->prev = nullptr;
				
				delete temp;
				return;
			}
			if (tailhangchothoigian->name == a){
				customer * temp = tailhangchothoigian;
				tailhangchothoigian = tailhangchothoigian->prev;

				if (tailhangchothoigian != nullptr)
				tailhangchothoigian->next = nullptr;

				delete temp;
				return;
			}
			customer * temp = headhangchothoigian;
			while(temp->next->name != a){
				temp = temp->next;
			}
			customer *del = temp->next;
			temp->next->next->prev = temp;
			temp->next = temp->next->next;
			delete del;
		}
/***********************************************************************************************************************************************/
		bool appearfirst(string& a,string& b){
				customer *temp = headhangchothoigian;
				while (temp->name != a && temp->name != b){
					temp = temp->next;
				}
				if (temp->name == a) return true;
				else return false;
		}

/***********************************************************************************************************************************************/
		void REDversion2(string name, int energy,bool redlandau = true)
		{
			if (energy == 0) return;
			//cout<<"RED";
			//cout << name << " " << energy << endl;
			if(energy != 0){
			customer *cus = new customer (name, energy, nullptr, nullptr);
			if (current == nullptr){
				current = cus;
				current->next = current;
				current->prev = current;
				count++;
				
				ordertable *table = new ordertable(name,energy);		//luu thu tu
				headorder = table;
				if(redlandau)
				addtimeline(name,energy);
				return;
			}
			else {
				ordertable *tabletemp = headorder;						//check trung ten
				while (tabletemp != nullptr){
						if (tabletemp->name == name){
							delete cus;
							cus = nullptr;
							return;
						}
						tabletemp = tabletemp->next;
				}
				
				if (wait != 0) {
					customer *temp = headwait;
					while (temp != nullptr){
						if (temp->name == name){
							delete cus;
							cus = nullptr;
							return;
						}
						temp = temp->next;
				}
				}
			}
			
			if (count == MAXSIZE){									//bo vao hang cho
				if (wait == MAXSIZE){
					delete cus;
					cus = nullptr;
					return;
				}
				else {
					delete cus;
					addwait(name,energy);
					wait++;
					addhangchothoigian(name,energy);
					if(redlandau)
					addtimeline(name,energy);	
				}
			}
			else if (count >= MAXSIZE/2){
				
				customer *temp = current;
				customer *store = current;
				int gap = cus->energy - temp->energy;
					temp = temp->next;
					while (temp != current){
						int gaptemp = cus->energy - temp->energy;
						if (abs(gaptemp)>abs(gap)){
							gap = gaptemp;
							store = temp;
						}
						temp= temp->next;
					}
				current = store;
				if (gap >= 0){
					current->next->prev = cus;
					cus->next = current->next;
					cus->prev = current;
					current->next = cus;
					current = cus;
				}
				else {
					current->prev->next = cus;
					cus->prev = current->prev;
					cus->next = current;
					current->prev = cus;
					current = cus;
				}
				count++;
				if(redlandau)
				addtimeline(name,energy);

				ordertable *table = new ordertable(name,energy);		
				ordertable *temptable = headorder;
				while (temptable->next != nullptr){
					temptable = temptable->next;
				}
				temptable->next = table;

			}
			else {
				if (cus->energy >= current->energy){
					current->next->prev = cus;
					cus->next = current->next;
					cus->prev = current;
					current->next = cus;
					current = cus;
				}
				else {
					current->prev->next = cus;
					cus->prev = current->prev;
					cus->next = current;
					current->prev = cus;
					current = cus;
				}
				count++;
				if(redlandau)
				addtimeline(name,energy);

				ordertable *table = new ordertable(name,energy);		
				ordertable *temptable = headorder;
				while (temptable->next != nullptr){
					temptable = temptable->next;
				}
				temptable->next = table;
			}
		}}

/***********************************************************************************************************************************************/
		void RED(string name, int energy)
		{
			REDversion2(name,energy,true);
		}
/***********************************************************************************************************************************************/		
		void BLUE(int num)
		{

			//cout << "blue ****************"<< num << endl;
			if (num < 0) return;
			if (num >= count){
				while(count != 0){
				customer * temp = current;
				current = current->next;
				temp->next = nullptr;
				temp->prev = nullptr;
				count--;
				removetimeline(temp->name);
				delete temp;
				temp = nullptr;

				ordertable *temptable = headorder;
				while (headorder != nullptr){
					headorder = headorder->next;
					delete temptable;
					temptable = headorder;
				}
				}
				current = nullptr;
				headorder = nullptr;
			}
			else {
				while (num != 0){
					string name = findname();
					removeordertable(name);
					removetimeline(name);

					while (name != current->name){
						current=current->next;
					}
					customer * temp = current;
					if(temp->energy > 0){
					current = current->next;
					current->prev = temp->prev;
					temp->prev->next = current;
					temp->next = nullptr;
					temp->prev = nullptr;
					delete temp;
					temp = nullptr;
					count--;}
					else {
						current = current->prev;
						current->next = temp->next;
						temp->next->prev = current;
						temp->next = nullptr;
						temp->prev = nullptr;
						delete temp;
						temp = nullptr;
						count--;
					}
					num--;
				}
			}
			if (count == 0)
			{
				current = nullptr;
			}
			while(wait != 0 && count != MAXSIZE){
				string name = headwait->name;
				int energy = headwait->energy;
				removewait(name);
				wait--;
				removehangchothoigian(name);
				REDversion2(name,energy,false);
				
			}
			if (wait == 0) {
				headwait = nullptr;
				headhangchothoigian = nullptr;
				tailhangchothoigian = nullptr;
			}
			if(wait == 0 && count == 0){
				headtimeline = nullptr;
			}
		}
/***********************************************************************************************************************************************/		
		string findmaxhangchothoigian(){
			customer *tempt = headhangchothoigian;
			int max = abs(tempt->energy);
			string name = tempt->name;
			tempt = tempt->next;
				while (tempt != nullptr){
					if (abs(tempt->energy) >= max){
						max = abs(tempt->energy);
						name = tempt->name;
					}
					tempt = tempt->next;
				}
			return name;
		}
/***********************************************************************************************************************************************/
		int findsize(string a){
			customer *temp = headwait;
			int i = 0;
			while (temp->name != a){
				temp = temp->next;
				i++;
			}
			return i;
		}
/***********************************************************************************************************************************************/		
		void swap(customer * a,customer* b){
			string name = a->name;
			int energy = a->energy;

			a->name = b->name;
			a->energy = b->energy;
			
			b->name = name;
			b->energy = energy;
		}
/***********************************************************************************************************************************************/		
		int insertsort2(customer *begin,int n,int incre){
			int countswap = 0;
			for (int i = incre;i<n;i+=incre){
				for (int j = i;(j>=incre)&&(abs(find(begin,j)->energy) >=  abs(find(begin,j-incre)->energy)); j -= incre)
					{
						if (abs(find(begin,j)->energy) > abs(find(begin,j-incre)->energy)){
						swap(find(begin,j),find(begin,j-incre));
						countswap++;
						}
						else {
							if (appearfirst(find(begin,j)->name,find(begin,j-incre)->name)){
								swap(find(begin,j),find(begin,j-incre));
								countswap++;
							}
							else {break;}
						}
					}
			}
			return countswap;
		}
/***********************************************************************************************************************************************/
		void test(customer * headwait){
			customer *temp = headwait;
			while (temp != nullptr){
				cout<<temp->energy<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}		
/***********************************************************************************************************************************************/		
		int shellsort(int n){
			int counting = 0;
			for (int i=n/2;i>2; i/= 2){
				for (int j =0; j<i; j++){
					counting += insertsort2(find(headwait,j),n-j,i);
				}
			}
			counting += insertsort2(find(headwait,0),n,1);
			return counting;
		}
/***********************************************************************************************************************************************/		
		customer * find(customer *begin,int index){
			customer *tempt = headwait;
			while (tempt != begin){
				tempt =tempt->next;
			}
			int counting = 0;
			while (counting != index){
				tempt = tempt->next;
				counting++;
			}
			return tempt;
		}
/***********************************************************************************************************************************************/		
		void PURPLE()
		{
			//cout << "purple     ***********"<< endl;
			if (headwait == nullptr) return;
			int n = findsize(findmaxhangchothoigian()) + 1;
			int N = shellsort(n);
			//test(headwait);
			BLUE(N % MAXSIZE);
		}
/***********************************************************************************************************************************************/		
		ordertable* findnegative(customer * current){
			customer * temp = current;
			ordertable* negative = nullptr;
			if (temp->energy < 0){
				ordertable* newnegative = new ordertable (temp->name,temp->energy);
				negative = newnegative;
			}
			temp = temp->prev;
			while (temp != current){
				if (temp->energy < 0){
				ordertable* newnegative = new ordertable (temp->name,temp->energy);
				if (negative == nullptr)
					negative = newnegative;
				else{
					newnegative->next = negative;
					negative = newnegative;
				}
			}
			temp = temp->prev;
			}
			return negative;
		}
/***********************************************************************************************************************************************/		
		ordertable* findpositive(customer * current){
			customer * temp = current;
			ordertable* positive = nullptr;
			if (temp->energy > 0){
				ordertable* newpositive = new ordertable (temp->name,temp->energy);
				positive = newpositive;
			}
			temp = temp->prev;
			while (temp != current){
				if (temp->energy > 0){
				ordertable* newpositive = new ordertable (temp->name,temp->energy);
				if (positive == nullptr)
					positive = newpositive;
				else{
					newpositive->next = positive;
					positive = newpositive;
				}
			}
			temp = temp->prev;
			}
			return positive;
		}
/***********************************************************************************************************************************************/
		void REVERSAL()
		{
			//cout << "reversal   ******************" << endl;
			if (headorder == nullptr) return;
			ordertable * positive = findpositive(current);
			ordertable * negative = findnegative(current);
			
			string name = current->name;
			customer *temp = current;
			while (positive != nullptr){
				while (temp->energy < 0){
					temp = temp->prev;
				}
				temp->energy = positive->energy;
				temp->name = positive->name;

				ordertable * del = positive;
				positive = positive->next;
				delete del;
				del = nullptr;
				temp = temp->prev;
			}
			temp = current;
			while (negative != nullptr){
				while (temp->energy > 0){
					temp = temp->prev;
				}
				temp->energy = negative->energy;
				temp->name = negative->name;

				ordertable * del = negative;
				negative = negative->next;
				delete del;
				del = nullptr;
				temp = temp->prev;
			}
			while (current->name != name ){
				current = current->next;
			}
		}
/***********************************************************************************************************************************************/		
		// int findsize(){
		// 	if (current == nullptr) return 0;
		// 	customer* temp = current;
		// 	int counting = 1;
		// 	temp = temp->next;
		// 	while (temp != current){
		// 		temp = temp->next;
		// 		counting++;
		// 	}
		// 	return counting;
		// }
/***********************************************************************************************************************************************/		
		void UNLIMITED_VOID()
		{
			//cout << "unlimited_void    ******************" << endl;
			int n = count;
			if (n < 4 ) return;
			customer *begin = current;
			int minimum;
			customer *end = current;
			int numberofsublist = 4;
			for (int i = 4 ;i<= n;i++){
				customer *begintemp = current;
				customer *endtemp = current;
				int mini = 0;
				for (int f = i;f>0;f--){
					mini += endtemp->energy;
					endtemp = endtemp->next;
				}

				if (i == 4) {
					begin = begintemp;
					minimum = mini;
				}
				else if (mini <= minimum){
					begin = begintemp;
					numberofsublist = i;
					minimum = mini;
				}
				
				begintemp = begintemp->next;
				while (begintemp != current){
					mini = mini - begintemp->prev->energy;
					mini = mini + endtemp->energy;

					if (mini <= minimum){
						begin = begintemp;
						numberofsublist = i;
						minimum = mini;
					}
					begintemp = begintemp->next;
					endtemp = endtemp->next;
				}
			}
			customer *print = new customer(begin->name,begin->energy,nullptr,nullptr);
			customer *tempprint = print;
			
			begin = begin->next;
			
			for (int i = numberofsublist - 1; i>0;i--){
				customer *newprint = new customer(begin->name,begin->energy,nullptr,nullptr);
				tempprint->next = newprint;
				tempprint = tempprint->next;
				begin = begin->next;
			}
			tempprint->next = print;

			tempprint = print->next;
			for (int i = numberofsublist -1; i>0;i--){
				if (tempprint->energy < print->energy)
				print = tempprint;

				tempprint = tempprint->next;
			}
			for (int i = numberofsublist ; i>0;i--){
				print->print();
				customer *del = print;
				print = print->next;
				del->next = nullptr;
				delete del;
				del = nullptr;
			}


			// ordertable *print = new ordertable(begin->name,begin->energy);
			// ordertable *tempprint = print;
			// customer *temp = begin->next;

			// while (numberofsublist-1 != 0){
			// 	ordertable *newprint = new ordertable(temp->name,temp->energy);
			// 	tempprint->next = newprint;
			// 	tempprint = newprint;
			// }
			// tempprint->next = print;

			// tempprint = print->next;
			// ordertable *headprint = print;
			// int firstprintnumber = print->energy;
			// while (tempprint != print){
			// 	if (tempprint->energy < firstprintnumber){
			// 		headprint = tempprint;
			// 		firstprintnumber = tempprint->energy;
			// 	}
			// 	tempprint = tempprint->next;
			// }

			// while (numberofsublist != 0){
			// 	customer *printtemp = current;
			// 	while (printtemp->name != headprint->name){
			// 			printtemp = printtemp->next;
			// 	}
			// 	printtemp->print();

			// 	ordertable *del = headprint;
			// 	headprint =headprint->next;
			// 	del->next = nullptr;
			// 	delete del;
			// 	del = nullptr;
			// 	numberofsublist--;
			// }
			// headprint = nullptr;
		}
/***********************************************************************************************************************************************/
		void printtimeline(int a){
			if (a == 1){
				customer *temp = tailtimeline;
				while(temp != headtimeline){
					if (temp->energy < 0){
						temp->print();
						string name = temp->name;
						temp = temp->prev;					
						removetimeline(name);
					}
					temp = temp->prev;
				}
				if (temp->energy < 0){
						temp->print();
						string name = temp->name;
						headtimeline = headtimeline->next;					
						removetimeline(name);
					}
			}
			else{
				customer *temp = tailtimeline;
				while(temp != headtimeline){
					if (temp->energy > 0){
						temp->print();
						string name = temp->name;
						temp = temp->prev;					
						removetimeline(name);
					}
					temp = temp->prev;
				}
				if (temp->energy > 0){
						temp->print();
						string name = temp->name;
						headtimeline = headtimeline->next;					
						removetimeline(name);
					}
			}
		}
/***********************************************************************************************************************************************/

		int sumpositive(){
			int sum = 0;
			customer *temp = current;
			if (current != nullptr){
			if (temp->energy > 0) sum += temp->energy;
			
			temp = temp->next;
			while (temp != current){
				if (temp->energy > 0) sum += temp->energy;
				temp = temp->next;
			}
			}

			temp = headwait;
			if (headwait != nullptr) {
			if (temp->energy > 0) sum += temp->energy;
			
			temp = temp->next;
			while (temp != nullptr){
				if (temp->energy > 0) sum += temp->energy;
				temp = temp->next;
			}
			}
			
			return sum;
		}
/***********************************************************************************************************************************************/		
		int sumnegative(){
			int sum = 0;
			customer *temp = current;
			if (current != nullptr){
			if (temp->energy < 0) sum += temp->energy;
			
			temp = temp->next;
			while (temp != current){
				if (temp->energy < 0) sum += temp->energy;
				temp = temp->next;
			}
			}

			temp = headwait;
			if (headwait != nullptr) {
			if (temp->energy < 0) sum += temp->energy;
			
			temp = temp->next;
			while (temp != nullptr){
				if (temp->energy < 0) sum += temp->energy;
				temp = temp->next;
			}
			}
			
			return sum;
		}
/***********************************************************************************************************************************************/
		ordertable* erasenegative()
		{
			ordertable* negative = nullptr;
			ordertable* newheadorder = nullptr;
			ordertable* temp;
			while (headorder != nullptr){
				if (headorder->energy < 0){
					ordertable *newnode = new ordertable(headorder->name,headorder->energy);
					if (negative == nullptr){
						negative = newnode;
					}
					else {
						newnode->next = negative;
						negative = newnode;
					}
				}
				else{
					ordertable *newnode = new ordertable(headorder->name,headorder->energy);
					if (newheadorder == nullptr){
						newheadorder = newnode;
						temp = newheadorder;
					}
					else{
						temp->next = newnode;
						temp = temp->next;
					}
				}
				ordertable *del = headorder;
					
					headorder = headorder->next;
					del->next = nullptr;
					delete del;
					del = nullptr;
			}
			headorder = newheadorder;
			return negative;
		
		}
/***********************************************************************************************************************************************/
		ordertable* erasepositive()
		{
			
			ordertable* positive = nullptr;
			ordertable* newheadorder = nullptr;
			ordertable* temp;
			
			while (headorder != nullptr){
				if (headorder->energy > 0){
					ordertable *newnode = new ordertable(headorder->name,headorder->energy);
					if (positive == nullptr){
						positive = newnode;
					}
					else {
						newnode->next = positive;
						positive = newnode;
					}
				}
				else{
					ordertable *newnode = new ordertable(headorder->name,headorder->energy);
					if (newheadorder == nullptr){
						newheadorder = newnode;
						temp = newheadorder;
					}
					else{
						temp->next = newnode;
						temp = temp->next;
					}
				}
				ordertable *del = headorder;
					if (headorder != nullptr)
					headorder = headorder->next;
					del->next = nullptr;
					delete del;
					del = nullptr;
			}
			headorder = newheadorder;
			return positive;
		
		}
/***********************************************************************************************************************************************/
		void DOMAIN_EXPANSION()
		{
			//cout << "domain_expansion  *********************" << endl;
			
			if (current == nullptr && headwait == nullptr) return;
			
			if (sumpositive() >= abs(sumnegative())){
				
				customer * temp = headwait;

				if (headwait != nullptr)
				{
				
					customer * temp = tailhangchothoigian;
					while (temp != headhangchothoigian){
						if (temp->energy < 0){
							string a = temp->name;
							//temp->print();
							removewait(a);
							wait--;
							temp = temp->prev;
							removehangchothoigian(a);
						}
						else{
							temp = temp->prev;
						}
					}
					if (temp->energy < 0){
							string a = temp->name;
							//temp->print();
							removewait(a);
							wait--;
							removehangchothoigian(a);
						}
					if (wait == 0){
						headwait = nullptr;
						tailwait = nullptr;
						headhangchothoigian = nullptr;
						tailhangchothoigian = nullptr;
					}
					
				}			
				if (current == nullptr) return;
				ordertable *temptable = erasenegative();

				temp = current;
				while (temptable != nullptr){
					while(temp->name != temptable->name){
						temp = temp->prev;
					}

					ordertable *deltable = temptable;
					temptable = temptable->next;
					deltable->next = nullptr;
					delete deltable;
					deltable = nullptr;

					customer *del = temp;
					temp = temp->prev;
					del->next->prev = temp;
					temp->next = del->next;

					del->prev = nullptr;
					del->next = nullptr;
					//del->print();
					delete del;
					del = nullptr;
					count--;
					//temptable = temptable->next;
				}
				current = temp;
				printtimeline(1);
			}
			else {
				customer * temp = headwait;
				if (headwait != nullptr)
				 {
					customer * temp = tailhangchothoigian;
					while (temp != headhangchothoigian){
						if (temp->energy > 0){
							string a = temp->name;
							temp->print();
							removewait(a);
							wait--;
							temp = temp->prev;
							removehangchothoigian(a);
						}
						else{
							temp = temp->prev;
						}
					}
					if (temp->energy > 0){
							string a = temp->name;
							temp->print();
							removewait(a);
							wait--;
							removehangchothoigian(a);
						}
					if (wait == 0){
						headwait = nullptr;
						tailwait = nullptr;
						headhangchothoigian = nullptr;
						tailhangchothoigian = nullptr;
					}
					
					}

				if (current == nullptr) return;
				ordertable *temptable = erasepositive();
				
				temp = current;
				while (temptable != nullptr){
					while(temp->name != temptable->name){
						temp = temp->next;
					}

					ordertable *deltable = temptable;
					temptable = temptable->next;
					deltable->next = nullptr;
					delete deltable;
					deltable = nullptr;
					customer *del = temp;
					temp = temp->next;

					temp->prev = del->prev;
					del->prev->next= temp;

					del->prev = nullptr;
					del->next = nullptr;
					del->print();
					delete del;
					del = nullptr;
					count--;
					//temptable = temptable->next;
			}
			current = temp;
				printtimeline(2);
			}
			if (count == 0){
				current = nullptr;
			}
			if (wait == 0){
				headwait = nullptr;
				tailwait = nullptr;
			}
			if(wait == 0 && count == 0){
				headtimeline = nullptr;
			}
			while(wait != 0 && count != MAXSIZE){				//them khach hang vao lai
				string name = headwait->name;
				int energy = headwait->energy;
				customer *temp = headwait;
				headwait = headwait->next;
				if(wait != 1){
				headwait->prev = nullptr;
				temp->next = nullptr;}
				delete temp;
				temp = nullptr;
				removehangchothoigian(name);
				wait--;
				RED(name,energy);
				//cout<<wait<<" "<<count<<endl;
			}
			if (wait == 0) headwait = nullptr;
			
		}
/***********************************************************************************************************************************************/
		void inorderhead(){
			ordertable *temp = headorder;
			cout<<"thu tu ban an: ";
			while(temp != nullptr){
				cout<<temp->energy<<" -> ";
				temp = temp->next;
			}
			cout<<endl;
		}
/***********************************************************************************************************************************************/
		void orderwait(){
			customer *temp = headwait;
			cout<<"thu tu hang cho: ";
			while(temp != nullptr){
				cout<<temp->energy<<" -> ";
				temp = temp->next;
			}
			cout<<endl;

		}
/***********************************************************************************************************************************************/
		void LIGHT(int num)
		{
			//cout << "light " << num << "****************"<< endl;
			if (count == 0 ) return;
			if (num == 0){
				customer * temp = headwait;
				while (temp != nullptr){
					temp->print();
					temp = temp->next;
				}
			}
			else if (num>0){
				customer * temp = current;
				temp->print();
				temp=temp->next;
				while (temp != current){
					temp->print();
					temp = temp->next;
				}
			}
			else {
				customer * temp = current;
				temp->print();
				temp=temp->prev;
				while (temp != current){
					temp->print();
					temp = temp->prev;
				}
			}
		}
};