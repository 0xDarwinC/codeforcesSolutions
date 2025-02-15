#include <bits/stdc++.h>

using namespace std;

// 1. if num lanterns == 1 just return best length from either end, if 0 just return impossible
// 2. sort the list of lanterns in nlgn
// 3. for each lantern in lanterns, first check dist from start to first lantern, then check dist from intermediaries to eaach other
// 4. update best dist with cur dist/2, where dist is r-l+1
// 5. for last lantern, check distance from end
// 6. keep three pointrs at all cases -- curr, left lantern, right lantern, 
// 7. return best distance 

void showVec(vector<int> vec){
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
      }
      cout << std::endl;
}

int main(){
    int n, num, l;
    long double best;
    cin>>n>>l;
    // read in lanterns
    vector<int> lanterns(n);
    for (int i = 0; i < n; ++i) {
        cin >> lanterns[i];
    }

    // sort in nlgn
    sort(lanterns.begin(), lanterns.end());


    best = lanterns[0] / 1.0;
    for(int i = 0; i < lanterns.size(); i++){
        long double curr = -1;
        long double l_lantern = (double)i;
        long double r_lantern = l_lantern+1;
        if(l_lantern == lanterns.size()-1){
            curr = ((double)l) - (double)lanterns[l_lantern];
        }
        else{
            curr = (((double)lanterns[r_lantern]-lanterns[l_lantern])) / 2.0;
        }
        if (curr>best){
            best = curr;
        }
        l_lantern = r_lantern;
    }
    cout << fixed << setprecision(10) << best;
}

