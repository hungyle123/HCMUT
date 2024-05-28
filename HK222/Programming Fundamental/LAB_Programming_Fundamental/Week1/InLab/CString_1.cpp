// Student may implement another function as need
int Validchar(char c) {
    if (('z'>= c && c >= 'a') || ('Z'>= c && c >= 'A'))
    return 1;
    else return 0;
}

void process(const char *name, char *outstr) {
    int a = strlen(name) ;
    int k = 0;
    int space = 1;
    for (int i = 0; i<=a-1;i = i +1){
        
        if ( (Validchar(name[i]) == 1) || ((space == 0)&& (name[i] ==' '))){
        
      
        
        if (space == 0 ) {
        outstr[i-k]= tolower(name[i]);}
        if (space == 1 ) {
            space = 0;
        outstr[i-k] = toupper(name[i]);}
       
        if (name[i]==' '){
        outstr[i-k]= name[i];
        space = 1;
        }
        }
        else k = k + 1;   // Do outstr va name str sẽ có những vị trí khi ta xét name ko có char phù hợp thì 
                        //câu lệnh lúc đó bị trật thứ tự nên ta lấy số các kí tự ko thỏa trừ cho số thứ tự bên
                        // outstr sẽ ra thứ tự trùng với name
    }
    for (int i = a;i >=0;i = i -1){ // ta xét các thứ tự từ dưới lên của outstr, do bản chất là outstr có 
    if ((Validchar(outstr[i]) == 1))//dung lượng nhiều hơn name 1 và thêm nữa là ta chỉ lấy một phần của name gán 
    break;                          // gán qua cho outstr nên outstr sẽ có một số phần tử rổng cuối
    else outstr[i]= '\0';}
}