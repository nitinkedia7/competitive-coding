#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back({a,i+1});
        }
        sort(v.begin(),v.end());
        int sum=0,ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        vector<int> contri(n,0);
        vector<int> bitm(32,0);
        for(int i=n-1;i>=0;i--){
            int p=0,num;
            num=v[i].first;
            for(int j=0; num >0 && j<32;j++){
                if(num%2==1&&bitm[j]==0){
                    contri[i]+=(1<<j);
                    bitm[j]=1;
                }
                num=num/2;
            }
            pq.push({contri[i],v[i].second});
            // cout<<contri[i]<<endl;
            sum+=contri[i];
        }
        ans=sum;
        vector<int> mya;
        while(pq.size()){
            sum-=(pq.top().first);
            mya.push_back(pq.top().second);
            // cout<<pq.top().second<<" ";
            ans+=sum;
            pq.pop();
        }

        cout<<ans<<endl;
        for(auto elem:mya){
            cout<<elem<<" ";
        }
        cout<<endl;

        

    }
    return 0;
}