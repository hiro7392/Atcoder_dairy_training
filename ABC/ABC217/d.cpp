#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

bool cmp(pair<int,int> first,pair<int,int>second){
    return first.first<second.first;
}

int main(){
    long long L,Q;
    cin>>L>>Q;

    map<int,int> woods;
    set<int>tree;
    woods.insert(make_pair(0,L));
    tree.insert(0);
    tree.insert(L);
    vector<int>ans;
    
    rep(i,Q){
        int c,x;
        cin>>c>>x;
        //decltype(woods)::iterator it =lower_bound(woods.begin(),woods.end(),make_pair(x,1),cmp);
        decltype(tree)::iterator it =tree.lower_bound(x);
        
        int nl,nr;
            nr=*it;
            it--;
            nl=*it;
        if(c==1){
            //cout<<it->second-it->first<<endl;

            
            //woods.erase(it->first);
            //it->second=x;
            //woods.insert(make_pair(x,nr));
            tree.insert(x);
        }else if(c==2){
            //ans.push_back(it->second-it->first);
            ans.push_back(nr-nl);
        }
    }
    rep(i,ans.size()){
        cout<<ans[i]<<endl;
    }
}
/*


*/
