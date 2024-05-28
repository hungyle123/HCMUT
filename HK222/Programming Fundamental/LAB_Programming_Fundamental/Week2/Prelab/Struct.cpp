// Question 1

struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};

/***********************************************************************************************/

// Question 2

void addAddendum(SCP &obj, string addendum) {
    int a = obj.numAddendums;
    string* addendumsnew = new  string[a+1];
 
   for(int i = 0;i< a ;i++){
       addendumsnew[i] = obj.addendums[i];
   }
   addendumsnew[a]=addendum;
    delete [] obj.addendums;
    obj.addendums = addendumsnew;
    obj.numAddendums = a + 1;
}