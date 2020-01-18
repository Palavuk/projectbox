#pragma once

template <class T>
class Vector{
    private:
        T* data;
        unsigned int s;
    public:
		T* begin() { return data; };
		T* end() { return (data + s); };
		unsigned int size() { return s; };
        
        void push_back(const T &val){
            s++;
            T* new_arr = new T[s];
            if (s != 1) {
                for (unsigned int i = 0; i < s - 2; i++)
                    new_arr[i] = std::move(data[i]);
            };
            new_arr[s - 1] = val;
            delete []data;
            data = new_arr;
        };
        
		void push_back(T &&val) {
			s++;
			T* new_arr = new T[s];
            if (s != 1) {
                for (unsigned int i = 0; i < s - 2; i++)
                    new_arr[i] = std::move(data[i]);
            };
			new_arr[s - 1] = std::move(val);
			delete[]data;
			data = new_arr;
		};

        void pop_back(){
            T* new_arr = new T[size - 1];
            for (unsigned int i = 0; i < s - 1 ; i++)
                new_arr[i] = std::move(data[i]);
            s--;
            delete []data;
            data = new_arr;
        };
        
        void erase(unsigned int position){
            if (position >= s - 1)
                return;
            s--;
            T* new_arr = new T[s];
            for (unsigned int i = 0; i < position; i++)
                new_arr[i] = std::move(data[i]);
            for (unsigned int i = position + 1; i < s; i++)
                new_arr[i] = std::move(data[i]);
            delete []data;
            data = new_arr;
        };
        
        void swap(T &val){
            std::swap(data, val.data);
            std::swap(s, val.s);
        };
        
        Vector(){
            data = nullptr;
            s = 0;
        };
        
        Vector(const Vector<T> &val){
            unsigned int sz = val.s;
            T* copy_vec = new T[sz];
            for (unsigned int i = 0; i < sz; i++)
                copy_vec = val.data[i];
            delete []data;
            data = copy_vec;
        };
        
        Vector<T>& operator = (const Vector<T> &val){ //оператор присваивания копированием
            if (this == &val)
                return *this;
            Vector<T> copy(val);
            swap(copy);
            return *this;
        };

        Vector(Vector<T> &&val) : data(std::move(val.data)), s(std::move(val.s)){};

        Vector<T>& operator = (Vector<T> &&val){ //оператор присваивания перемещением
            if (this == &val)
                return *this;
            swap(val);
            return *this;
        }
        
        ~Vector(){
            delete []data;
        };

        T& operator [] (unsigned int n) { return *(begin() + n); };
};

template <class T> void swap(Vector<T> &val1, Vector<T> &val2){
    std::swap(val1.data, val2.data);
    std::swap(val1.s, val2.s);
}