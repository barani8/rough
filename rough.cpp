#include<bits/stdc++.h>

using namespace std;

int check(vector<int> t, int a){
    for(int z=0;z<t.size();z++){
        if(t.at(z)==a){
            return z;
        }
    }
    return -1;
}

int main(){
    int n=7;
    int k=4;
    int maxVal = 0;
    vector<int> a{1,2,7,7,4,3,6};
    int temp = 0;
    vector<int> v;
    for(int z=0;z<n;z++){
        if(v.size()<k){
            int find = check(v,a.at(z));
            if(find==-1){
                temp+=a.at(z);
                v.push_back(a.at(z));
            }else{
                v.erase(v.begin(),v.begin()+find);
                temp=a.at(z);
            }
        }else{
            int find = check(v,a.at(z));
            if(find==-1){
                temp+=a.at(z);
                temp-=a.at(z-k);
                v.push_back(a.at(z));
                v.erase(v.begin());
            }else{
                v.erase(v.begin(),v.begin()+find);
                temp=a.at(z);
            }
        }
        maxVal = max(maxVal, temp);
    }
    cout << maxVal;
    return 0;
}