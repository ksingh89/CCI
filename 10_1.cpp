#include <set>
#include <bits/stdc++.h>
#include <iostream>
#include <unistd.h>
#include <algorithm>

using namespace std;
void merge_vector(vector<int>& s1, vector<int>& s2, int , int);
int main() {
    vector <int> set1={12, 5,6,1,2, 20};
    vector <int> set2={10, 15, 9, 8};

    // sorted sub arrays
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());
    // display set1
    auto itr1 = set1.begin();
    while(itr1 != set1.end()) {
        cout << *itr1 << " ";
        itr1++;
    }
    cout << endl;
    // display set2
    auto itr2 = set2.begin();
    while(itr2 != set2.end()) {
        cout << *itr2 << " ";
        itr2++;
    }
    cout << endl;
    int last_set1 = set1.size();
    int last_set2 = set2.size();
    set1.resize(10);

    merge_vector(set1, set2, last_set1, last_set2);
    // display
    auto itr = set1.begin();
    while(itr != set1.end()) {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;
}

void merge_vector(vector<int>& s1, vector<int>& s2, int a, int b) {
    auto itr_s1 = s1.begin();
    auto itr_s2 = s2.rbegin();
    itr_s1 = itr_s1+a-1;      // last element of first vector
    //itr_s2 = itr_s2+b-1;      // last element of second vector
    auto target_vector = s1.rbegin();
    cout << "size s1 : " << s1.size() << endl;
    cout << "size s2 : " << s2.size() << endl;

    while(target_vector != s1.rend()) {
        if(*itr_s1 >= *itr_s2) {
            *target_vector = *itr_s1;
            itr_s1--;            
        } else {
            *target_vector = *itr_s2;
            itr_s2++;            
        }
        target_vector++;
    }
}