#include <ostream>

template<class T>
class iter{
    private:
        std::ostream* pointer;
        int N;
        int n;
    public:
        iter(std::ostream& str, int N): pointer(&str), N(N){
            n = 1;
        }

        iter& operator*(){
            return *this;
        }

        iter& operator=(T p){
            if(n == N){
                n = 1;
                *pointer << p;
            }
            else
                n++;
            return *this;
        }

        iter& operator++(){
            return *this;
        }

        iter& operator++(int i){
            return *this;
        }

        ~iter() = default;

    };