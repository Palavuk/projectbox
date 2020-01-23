#include <iostream>
#include <vector>
#include <sort_tread.h>

using namespace std::chrono;

int main(){    
    std::cout.fill(' ');

    std::cout<<"Elements:";
    std::cout.width(18); std::cout<<1000;
    std::cout.width(15); std::cout<<2500;
    std::cout.width(15); std::cout<<5000;

    std::cout<<"Normal_Time:";

    std::vector<double> array;
    for(double i = 1000; i>0;i--)
        array.push_back(i);
    steady_clock::time_point start = steady_clock::now();
    merge_sort(array.begin(), array.end());
    steady_clock::time_point end = steady_clock::now();
    std::cout.width(15); 
    std::cout<<duration_cast<milliseconds>(end - start).count();

    array.clear();
    for(double i = 2500; i>0;i--)
        array.push_back(i);
    start = steady_clock::now();
    merge_sort(array.begin(), array.end());
    end = steady_clock::now();
    std::cout.width(15); 
    std::cout<<duration_cast<milliseconds>(end - start).count();

    array.clear();
    for(double i = 5000; i>0;i--)
        array.push_back(i);
    start = steady_clock::now();
    merge_sort(array.begin(), array.end());
    end = steady_clock::now();
    std::cout.width(15); 
    std::cout<<duration_cast<milliseconds>(end - start).count();

    array.clear();
    std::cout<<"Thread_Time:";

    for(double i = 1000; i>0;i--)
        array.push_back(i);
    start = steady_clock::now();
    merge_sort_thread(array.begin(), array.end());
    end = steady_clock::now();
    std::cout.width(15); 
    std::cout<<duration_cast<milliseconds>(end - start).count();

    array.clear();
    for(double i = 2500; i>0;i--)
        array.push_back(i);
    start = steady_clock::now();
    merge_sort_thread(array.begin(), array.end());
    end = steady_clock::now();
    std::cout.width(15); 
    std::cout<<duration_cast<milliseconds>(end - start).count();

    array.clear();
    for(double i = 5000; i>0;i--)
        array.push_back(i);
    start = steady_clock::now();
    merge_sort_thread(array.begin(), array.end());
    end = steady_clock::now();
    std::cout.width(15); 
    std::cout<<duration_cast<milliseconds>(end - start).count();

    return 0;
}