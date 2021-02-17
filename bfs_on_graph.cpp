// Function for BFS on Graph 


void bfs(int root)
{
	vector<bool> visited(V);
	for(int i=0;i<V;i++) visited[i]=false;

	list<int>q;
	visited[root]=true;
	q.push(root);

	list<int> :: iterator i;
	while(!q.empty()){
		s=q.front();
		cout<<root<<" ";

		for(i=adj[root].begin();i!=adj[root].end();i++){
			if(!visited[*i]) visited[*i]=true,q.push_back(*i);
		}
	}
}