template <typename T>
class Vector{
private:
       int size;
       int capacity;
       T*_data;
public:
      Vector(){
        this->size=0;
        this->capacity=1;
        _data=nullptr;
      }
      
      ~Vector(){
        delete[]_data;
        size=0;
        capacity=0;
        _data=nullptr;
      }

      Vector(const Vector&other){
        size=other.size();
        capacity=other.capacity;
        _data=new T[capacity];
        for(int i=0;i<size;i++){
            _data[i]=other._data[i];
        }
      }

      Vector&operator=(const Vector&vec){
        if(this==&vec){
            return *this;
        }
        T*temp=new T[vec.capacity];
        for(int i=0;i<vec.size;i++){
            temp[i]=vec._data[i];
        }
        delete[]_data;
        _data=temp;
        size=vec.size;
        capacity=vec.capacity;
        return *this;
      }


      T&operator[](int index){
        return _data[index];
      }


      bool operator==(const Vector&vec){
        if(size!=vec.size()){
            return false;
        }
        for(int i=0;i<size;i++){
            if(_data[i]!=vec._data[i]){
                return false;
            }
        }
        return true;
      }
      void push_back(T val){
        if(0==capacity){
            capacity=1;
            _data=new T[1];
        }else if(size+1>capacity){
            capacity*=2;
            T*temp=new T[capacity];
            for(int i=0;i<size;i++){
                temp[i]=_data[i];
            }
            delete[]_data;
            _data=temp;
        }
        _data[size]=val;
        size++;

      }

      void insert(T* it,T val){
        int index=it-_data;
        if(0==capacity){
            capacity=1;
            _data=new T[capacity];
            _data[0]=val;
        }
        else if(size+1>capacity){
            capacity*=2;
            T*temp=new T[capacity];
            for(int i=0;i<index;i++){
                temp[i]=_data[i];
            }
            temp[index]=val;
            for(int i=index+1;i<size;i++){
                temp[i]=_data[i];
            }
            delete[]_data;
            _data=temp;
        }else{
            for(int i=size-1;i>=index;--i){
                _data[i+1]=_data[i];
            }
            _data[index]=val;
        }
        size++;
      }
      void pop_back(){
        size--;
      }
      void erase(T*it){
        int index=it-_data;
        for(int i=index;i<size-1;i++){
            _data[i]=_data[i+1];
        }
        size--;
      }

      T front()const{
        return _data[0];
      }
      T back()const{
        return _data[size-1];
      }
      T*begin(){
        return _data;
      }
      T*end(){
        return _data+size;
      }

}