void findAllIndex(string s1, string s2){
        long int a =s1.length();
        long int t;
        t =s1.find(s2);
        if (s1.find(s2) > a) 
        cout <<-1;
        else {
        cout<<s1.find(s2)<<" ";
        
        
        while (t+1 < a) {
            if (s1.find(s2,t+1)>a)
            break;
            cout<<s1.find(s2,t+1)<<" ";
            t =s1.find(s2,t+1);
            
        }
        }  
}
