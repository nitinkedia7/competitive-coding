/*input
4
5 3 2
5 C
2 A
1 A
2 4 0
1 A
1 C
1 A
1 C
3 2 10
3 C
2 A
6 1 6
4 A
*/
#include "bits/stdc++.h"
using namespace std;
int inf = 1e9;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _T,n,g,m; cin >> _T;
	for(int tc=0; tc++<_T; cout<<'\n'){
		cout<<"Case #"<<tc<<": ";
		cin >> n >> g >> m;

		vector<pair<int,int>> last_seen_a(n,make_pair(0,inf));
		vector<pair<int,int>> last_seen_c(n,make_pair(0,inf));
		map<int,int> a,c;

		map<pair<int,int>,vector<int>> mp;
		for(int i=0,x;i<g;++i){
			char ch;
			cin >> x >> ch; --x;
			if(ch == 'C'){
				++c[x];
			} else {
				++a[x];
			}
			mp[{x,ch=='C'}].push_back(i);
		}
		
		{
		
		map<int,int> tmp;
		for(auto p:c) tmp[(p.first+m)%n] = p.second;
		c = tmp;
		for(int iter=0;iter<=m;++iter){
			if(c.empty()) break;
			vector<int> to_erase;
			for(auto &p:c){
				if(last_seen_c[p.first] != make_pair(0,inf)) {
					to_erase.push_back(p.first);
				} else{
					last_seen_c[p.first] = make_pair(p.second,iter);
				}
			}
			for(auto i:to_erase) c.erase(i);
			map<int,int> tmp;
			for(auto p:c) tmp[(p.first-1+n)%n] = p.second;
			c = tmp;
		}

		}

		{
		map<int,int> tmp;
		for(auto p:a) tmp[(p.first-m%n+n)%n] = p.second;
		a = tmp;
		for(int iter=0;iter<=m;++iter){
			if(a.empty()) break;
			vector<int> to_erase;
			for(auto &p:a){
				if(last_seen_a[p.first] != make_pair(0,inf)) {
					to_erase.push_back(p.first);
				} else{
					last_seen_a[p.first] = make_pair(p.second,iter);
				}
			}
			for(auto i:to_erase) a.erase(i);
			map<int,int> tmp;
			for(auto p:a) tmp[(p.first+1)%n] = p.second;
			a = tmp;
		}

		}


		// for(auto i:last_seen_c)
		// 	cout<<i.first<<' '<<i.second << '\n';
		// cout<<"\n\n";
		// for(auto i:last_seen_a)
		// 	cout<<i.first<<' '<<i.second << '\n';
		// cout<<"\n\n";
		
		vector<int> RES(g);
		map<pair<int,int>,int> lazy;

		auto add = [&](int idx, int dir){
			// cout << idx << '\n';
			assert(mp.count({idx,dir}));
			++lazy[{idx,dir}];
		};

		m%=n;
		for(int i=0;i<n;++i){
			if(last_seen_a[i].second == last_seen_c[i].second){
				if(last_seen_c[i].second > 1e8) continue;
				add((i+m-last_seen_a[i].second+n)%n,0);
				add((i-m+last_seen_c[i].second+n)%n,1);
			}
			else if(last_seen_a[i].second < last_seen_c[i].second){
				if(last_seen_a[i].second > 1e8) continue;
				add((i+m-last_seen_a[i].second+n)%n,0);
			}
			else{
				if(last_seen_c[i].second > 1e8) continue;
				add((i-m+last_seen_c[i].second+n)%n,1);
			}
		}

		for(auto p:lazy)
			for(auto i:mp[p.first])
				RES[i] += p.second;
		for(int i=0;i<g;cout<<RES[i++]<<' ');
	}
}