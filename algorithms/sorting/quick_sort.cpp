#include <iostream>
#include <vector>

using namespace std;

vector<int> q_sort(vector<int>);

int main() {
    vector<int> arr = { 4, 3, 2, 1, 5 , -4, 8 , 2};
    vector<int> c = q_sort(arr);
    for (int i = 0; i != size(c); ++i)
        cout << c[i] << " ";
    cout << endl;
}

vector<int> q_sort(vector<int> vec) {
    if (size(vec) <= 1) return vec;

    int pivot = vec[size(vec) / 2];  
    vector<int> lower;
    vector<int> equal;   
    vector<int> bigger;

    for (int i = 0; i != size(vec); i++) {
        if (vec[i] < pivot)
            lower.push_back(vec[i]);
        else if (vec[i] > pivot)
            bigger.push_back(vec[i]);
        else
            equal.push_back(vec[i]);  
    }

    vector<int> f1 = q_sort(lower);
    vector<int> f2 = q_sort(bigger);

    vector<int> TOTAL;
    for (int i = 0; i != size(f1); ++i) TOTAL.push_back(f1[i]);
    for (int i = 0; i != size(equal); ++i) TOTAL.push_back(equal[i]);
    for (int i = 0; i != size(f2); ++i) TOTAL.push_back(f2[i]);
    return TOTAL;
}
