class String{
private:
    char*t;
    int len;
    friend ostream&operator<<(ostream&out,const String&ch)
public:
    String():t(nullptr),len(0){}
    String(const char*ch){
        len=strlen(ch);
        t=new char[len+1];
        strcpy(t,ch);

    }
    String(const String&str){
        len=str.len;
        t=new char[len+1];
        strcpy(t,str.t);
    }
    ～String(){
        delete[]t;
        len=0;
        t=nullptr;
    }
    
    String&operator=(String&st1){
        if(this!=&st1){
            delete[]t;
            len=st1.len;
            t=new char[len+1];
            strcpy(t,st1.t);
        }
        return *this;
    }




}
ostream&operator<<(ostream&out,const String&ch){
    out<<ch;
    return out;
}