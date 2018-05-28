#include <bits/stdc++.h>
#define F first
#define S second
 
using namespace std;
 
typedef pair<int, int> pii;
const int MAXN=1.1e+3;

int n, m, c;
int vis[MAXN], ft[MAXN], t[MAXN], sub[MAXN];

vector<int> graph[MAXN];
vector<pii> edges;
 
void dfs(int u){
    vis[u]=1;
    t[u]=sub[u]=++c;
    for(int i=0;i<graph[u].size();++i){
 
        int v=graph[u][i];
 		
        if(!vis[v]){
            ft[v]=u;
            dfs(v);
            sub[u]=min(sub[u], sub[v]);
            if(sub[v]>t[u]){
            	int x=u, y=v;
 	    	if(x>y) swap(x, y);
        	
		edges.push_back(pii(x, y));
            }
        }else if(v!=ft[u]){
            sub[u]=min(sub[u], t[v]);
        }
    }
}

bool comp(pii a, pii b){
    if(a.F!=b.F) return a.F<b.F;
    return a.S<b.S;
}

int main(){
    scanf("%d %d", &n, &m);
 
    for(int i=0;i<m;++i){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=n;++i){
        if(!vis[i]) dfs(i);
    }
	
    int s=edges.size();
    if(s!=0){
        
        printf("%d\n", s);
        sort(edges.begin(), edges.end(), comp);
        for(int i=0;i<s;++i){
            printf("%d %d\n", edges[i].F, edges[i].S);
        }
    }else{
        printf("Sem Pontes\n");
    }
	
    return 0;
} 
