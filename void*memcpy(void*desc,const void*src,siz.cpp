void*memcpy(void*desc,const void*src,int size){
    char* pr1;
    char* pr2;
    if(desc==nullptr||src==nullptr){
        return nullptr;
    }
    if(src<desc&&(char*)src+size>(char*)desc){
        pr1=(char*)desc+size-1;
        pr2=(char*)src+size-1;
        while(size){
            *pr1=*pr2;
            *pr1--;
            *pr2--;
            size--;
        }
    }
    else{
        pr1=(char*)desc;
        pr2=(char*)src;
        while(size){
            *pr1=*pr2;
            *pr1++;
            *pr2++;
            size--;
        }
    }

    return desc;
}
