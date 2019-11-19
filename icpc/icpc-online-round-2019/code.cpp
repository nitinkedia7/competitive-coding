#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        unordered_map<string ,pair<int,int>> m;
        int n;
        cin>>n;
        string s;
        int val;
        for(int i=0;i<n;i++){
            cin>>s>>val;
            if(m.find(s)==m.end()){
                if(val==0){
                    m[s].first=1;
                    m[s].second=0;
                }
                else{
                    m[s].first=0;
                    m[s].second=1;
                }
            }
            else{
                if(val==0){
                    m[s].first++;
                }
                else{
                    m[s].second++;
                }
            }
        }
        int ans=0;
        for(auto itr=m.begin();itr!=m.end();itr++){
            ans+=(max(itr->second.first,itr->second.second));
        }
        cout<<ans<<endl;
    }
    return 0;
}