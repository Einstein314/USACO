//MinStack implementation 
//https://cp-algorithms.com/data_structures/stack_queue_modification.html
#include <bits/stdc++.h>

template<class T> struct minStack{
    stack<pair<T,T>> st;

    void push(T x){
        T min_below = st.empty() ? x : min(x, st.top().second);
        st.push({x, min_below});
    }

    void pop(){
        st.pop();
    }

    T findmin(){
        return st.top().second;
    }
};
