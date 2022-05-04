#include <iostream>
#include <algorithm>
#include "vector"

using namespace std;

template<typename T>
bool predicate(T a){
    return a >= 21;
}

template<typename T>
bool comp(T& a, T& b){
    return a < b;
}

template<typename T, typename P>
bool noneof(T begin, T end, P predicate){
    T iter = begin;
    while(iter != end)
    {
        if (predicate(*iter)){
            return false;
        }
        iter++;
    }
    return true;
}

template<typename T, typename F>
bool issorted(T begin, T end, F comp){
    vector<typeof(*begin)> a;
    auto it_tmp = begin;
    while (it_tmp != end) {
        a.push_back(*it_tmp);
        it_tmp++;
    }
    sort(a.begin(), a.end(), comp);
    it_tmp = begin;
    int index = 0;
    while (it_tmp != end){

        if (*it_tmp != a[index])
            return false;
        it_tmp++;
        index++;
    }
    return true;
}

template<typename T, typename E>
int findnot(T begin, T end, E x){
    auto tmp = begin;
    int count = 0;
    while (tmp != end){
        if (*tmp != x)
            return count;
        count++;
        tmp++;
    }
    return -1;
}

int main() {
    vector<int> a;
    a.resize(6);
    a = {1, 1, 1, 12, 33, 15};
    vector<int> b;
    for (int i = 0; i < a.size(); i++){
        b.push_back(a[i]);
    }
    int x;
    cin >> x;
    cout << "None_of: " << noneof<vector<int>::iterator>(a.begin(), a.end(), predicate<int>) << endl;
    cout << "Is_sorted: " << issorted<vector<int>::iterator>(a.begin(), a.end(), comp<int>) << endl;
    cout << "Find_not: " << findnot<vector<int>::iterator, int>(a.begin(), a.end(), x);
    return 0;
}
