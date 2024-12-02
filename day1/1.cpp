#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
using namespace std;


int main() {
  unordered_map<int, int> list2;
  priority_queue<int, vector<int>, greater<int>> pq1;
  priority_queue<int, vector<int>, greater<int>> pq2;
  
  ifstream inFile("input1.txt");

  int l1Val, l2Val;
  int idx = 0;

  while (inFile >> l1Val >> l2Val) {
    if (idx < 10) {
      cout << l1Val << " " << l2Val << "\n";
    }
    list2[l2Val]++;
    pq1.push(l1Val);
    pq2.push(l2Val);
  }
  inFile.close(); 

  long total_distance = 0;
  long similarity_score = 0;
  for (int i = 0; i < 1000; i++) {
    // pop vals
    l1Val = pq1.top();
    l2Val = pq2.top();
    pq1.pop();
    pq2.pop();

    total_distance += abs(l1Val - l2Val);
    similarity_score += list2[l1Val] * l1Val;
  }
  cout << "Total Distance: " << total_distance << "\n";
  cout << "Similarity Score: " << similarity_score << "\n";
}