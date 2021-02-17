//Function for DFS on Graph

void solve(int root,vector<bool> visited){
	visited[i]=true;
	cout<<root<<" ";

	list<int>:: iterator i;

	for(i=adj[root].begin();i!=adj[root].end();i++){
		if(!visited[*i]) solve(*i,vsited);
	}
}

void dfs(int root){
	vector<bool> visited(V);
	for(int i=0;i<V;i++) visited[i]=false;
		solve(root,visited);
}