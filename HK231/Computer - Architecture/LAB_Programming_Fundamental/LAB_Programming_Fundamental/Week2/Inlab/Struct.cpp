// Question 1

SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums) {
    SCP tSCP;
    tSCP.id= id;
    tSCP.objClass = objClass;
    tSCP.speConProcedures = speConProcedures;
    tSCP.description = description;
    tSCP.addendums = addendums;
    tSCP.numAddendums = numAddendums;
    return tSCP;
}

/***************************************************************************************************/

// Question 2

string convertToString(SCP obj) {
    string a="Item #: SCP-";
    string b;
    if (obj.id >100)
    b = to_string(obj.id);
    else if (obj.id >10)
    b = "0" + to_string(obj.id);
    else b = "00" + to_string(obj.id);
    string c;
    if (obj.objClass == 0)
    c = "Object Class: Safe";
    else if (obj.objClass == 1)
    c = "Object Class: Euclid";
    else c = "Object Class: Keter";
    string d = "Special Containment Procedures: " + obj.speConProcedures;
    string e ="Description: " + obj.description;
    string final = a  + b +"\n" + c+"\n" + d + "\n" + e + "\n";
    for (int i =0;i<obj.numAddendums;i++){
        final = final + obj.addendums[i] + "\n";
    }
    return final;
}

/***************************************************************************************************/

// Question 3

SCP* cloneSCP(SCP* original) {
    SCP* t =new SCP;
    int a1 = original->id;
    t->id = a1;
    int a2 = original->objClass;
    t->objClass = a2;
    string a3 = original->speConProcedures;
    t->speConProcedures = a3;
    string a4 = original->description;
    t->description = a4;
    string* newArr = new string[original->numAddendums];
    for (int i = 0 ;i<original->numAddendums;i++){
        newArr[i] = original->addendums[i];
    }
    t->addendums =newArr;
    int a5 = original->numAddendums;
    t->numAddendums = a5;
    return t;
}