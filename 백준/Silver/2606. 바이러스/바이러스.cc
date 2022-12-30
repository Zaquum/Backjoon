#include <bits/stdc++.h>
using namespace std;
#define MAX 101

vector<int> network[MAX];
bool visited[MAX];
int cnt = 0;

void dfs(int start) {
	visited[start] = true;
	for (int i = 0; i < network[start].size(); i++) {
		int y = network[start][i];
		if (!visited[y]) {
			cnt++;
			dfs(y);
		}
	}
}
/*
void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start]=true;
	cnt++;
	while(!q.empty()){
	int x=q.front();
	q.pop();
	for(int i=0;i<network[x].size();i++){
		int next=network[x][i];
		if(!visited[y]){
			q.push(y);
			visited[y]=true;
			cnt++;
		}
	}
	}
}
*/
int main() {
	// your code goes here
	int n, m;
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		network[x].push_back(y);
		network[y].push_back(x);
	}
	dfs(1);
	cout << cnt << '\n';
	return 0;
}