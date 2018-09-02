// Disjoint sets: Union-find - Algorithm
// Complexity(find): O(log n)
// Complexity(join): O(log n)
// By Samyra Vitória

#include <bits/stdc++.h>

using namespace std;

int n;
int uf[MAXN], rk[MAXN];

int find(int u){
	if(uf[u]==u) return u;
	return uf[u]=find(uf[u]);
}

void join(int u, int v){

	u=find(u); v=find(v);

	if(u==v) return;
	if(rk[u]>rk[v]) swap(u, v);

	uf[u]=v;
	rk[v]+=(rk[u]==rk[v]);
}

int main(){
	
	for(int i=1;i<=n;++i) uf[i]=i;
	memset(rk, 0, sizeof rk);
	
	return 0;
}
