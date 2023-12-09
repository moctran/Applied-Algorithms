#include <iostream>
#include <algorithm> 
#include <vector>
#include <set>
using namespace std;

int arr[100000];
int n; 
int x;
int m;
int cnt;
int sum;
int visited[100000] = {0};
int result[10000];
set<vector<int> > results;

bool check(int v, int k) {
  if (k == x) 
    return sum + arr[v] == m; 
  else 
    return 1;
}

void printConfiguration() {
  vector<int> v;
  for(int i = 1; i <= x; i++) {
    v.push_back(result[i]); 
  }
  sort(v.begin(), v.end());
  
  results.insert(v);
}

void Try(int k) {
  for(int v = 1; v <= n; v++) {
    if (visited[v] == 0 && check(v,k)) {
      visited[v] = 1;
      sum += arr[v];
      result[k] = v;
      
      if (k == x) {
        printConfiguration();
      }
      else 
        Try(k+1);
        
      visited[v] = 0;
      sum -= arr[v];
    }
  }
}

int main(void) {
  cin >> n >> x >> m;
  
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  Try(1);

  
  cout << results.size() << endl; 
}