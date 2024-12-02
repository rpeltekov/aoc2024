#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <sstream>
using namespace std;

int nextValid(int last, int curr) {
  int diff = curr - last;
  if (abs(diff) >= 1 && abs(diff) <= 3) {
    return diff > 0 ? 1 : -1; 
  } 
  return 0;
}

int seqValid(vector<int>& nums, int skip) {
  int inc = -3;
  int ret = 1;
  int last = -1;
  for (int i = 0; i < nums.size(); i++) {
    if (i == skip) continue;
    if (last < 0) {
      last = i; continue;
    } 
    int inc_val = nextValid(nums[last], nums[i]);
    if (inc == -3 && inc_val != 0) {
      inc = inc_val;
    } else if (inc_val != inc) {
      return false;
    }
    last = i;
  }
  return true;
}

int main() {
  ifstream inFile("input2.txt");
  string line;

  int safe1 = 0;
  while(getline(inFile, line)) {
    std::stringstream ss(line);
    vector<int> numbers;
    for(int i = 0; ss >> i; ) {
        numbers.push_back(i);
    }
    safe1 += seqValid(numbers, -1) == 1 ? 1 : 0;
  }
  cout << "1: num safe: " << safe1 << "\n";

  //
  // PART 2
  
  inFile.clear();
  inFile.seekg(0, std::ios::beg);

  int safe2 = 0;
  int count = 0;
  while(getline(inFile, line)) {
    std::stringstream ss(line);
    vector<int> numbers;
    for(int i = 0; ss >> i; ) {
        numbers.push_back(i);
    }

    bool valid = false;
    for (int i = 0; i < numbers.size(); i++) {
      valid |= seqValid(numbers, i);
      if (valid) break;
    }
    safe2 += valid ? 1 : 0;
    count++;
  }

  inFile.close();

  cout << "2: num safe: " << safe2 << "\n";
}