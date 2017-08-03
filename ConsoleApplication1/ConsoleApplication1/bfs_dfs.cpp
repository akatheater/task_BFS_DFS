#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int graph[7][7];
bool is_in[7] = { 0 };
vector<int> road;

void store(){
	//¼ÇÂ¼ÁÚ½Ó¾ØÕó
	for (int i = 1; i<7; i++){
		for (int j = 1; j<7; j++){
			cin >> graph[i][j];
		}
	}
}

void bfs(){
	queue<int> temp;
	temp.push(1);
	while (!temp.empty()){
		for (int i = 1; i<7; i++){
			if (is_in[i] == 0 && graph[temp.front()][i] == 1){
				temp.push(i);
				road.push_back(i);
				is_in[i] = 1;
			}
		}
		temp.pop();
	}
}

void dfs(){
	stack<int> temp;
	temp.push(1);
	int i;
	while (!temp.empty()){
		for (i = 1; i<7; i++){
			if (is_in[i] == 1 && graph[temp.top()][i] == 1){
				road.push_back(i);
				temp.push(i);
				is_in[i] = 0;
				break;
			}
		}
		if (i == 7){
			temp.pop();
			if (!temp.empty()) road.push_back(temp.top());
		}
		int j;
		for (j = 1; j<7; j++){
			if (is_in[j] == 1) break;
		}
		if (j == 7) return;
	}
}

int main(){
	store();
	road.push_back(1);
	is_in[1] = 1;
	bfs();
	for (int i = 0; i<road.size(); i++){
		cout << road[i] << endl;
	}
	cout << endl;

	road.clear();
	road.push_back(1);
	is_in[1] = 0;
	dfs();
	for (int i = 0; i<road.size(); i++){
		cout << road[i] << endl;
	}


	return 0;
}