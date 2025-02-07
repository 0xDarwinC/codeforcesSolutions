#include <bits/stdc++.h>

using namespace std;

void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

bool validate(double d, list<int> lanterns, int length){
    vector<int> street(length, 0);
    for(int i = 0; i<length; i++){
        for(int j : lanterns){
            if(i >= j-d && i <= j+d){
                street[i] = 1;
            }
        }
    }
    for(int i = 0; i<length; i++){
        if(street[i] != 1){
            return false;
        }
    }
    return true;
}

//strategy -- binary search to find the right distance, validate distance using array, should be nlgn
int main(){
    int n, num;
    double l;
    cin>>n>>l;
    list<int> lanterns;
    for(int i = 0; i<n; i++){
        cin>>num;
        lanterns.push_back(num);
    }
    showlist(lanterns);
    double left, right;
    left = 0.0;
    right = l;
    double mid;
    double smallest = DBL_MAX;
    bool flag;
    while(left<=right){
        mid=(left+right)/2;
        flag = validate(mid, lanterns, (int)l);
        if(flag){
            if(smallest > mid){
                smallest = mid;
            }
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<smallest;
}

