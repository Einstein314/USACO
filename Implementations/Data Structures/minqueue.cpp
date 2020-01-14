//minQueue implementation
//https://github.com/bqi343/USACO/blob/master/Implementations/content/data-structures/STL%20(5)/MinDeque%20(8.2).cpp
//https://cp-algorithms.com/data_structures/stack_queue_modification.html
#include <bits/stdc++.h>

template<class T> struct minQueue{
    //0-indexed
    int rem = 0, add = -1;
    deque<pair<T,int>> deq;

    void push(T x){
        //Can switch depending on min/max or > or >=
        while (!deq.empty() && deq.back().first > x){
            deq.pop_back();
        }
        deq.push_back({x, ++add});
    }

    void pop(){
        if (!deq.empty() && deq.front().second == rem++){
            deq.pop_front();
        }
    }

    T findmin(){
        //change?
        if (deq.empty()) return -1;
        return deq.front().first;
    }
};
