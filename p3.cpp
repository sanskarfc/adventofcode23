#include <bits/stdc++.h> 

using namespace std; 

bool isNum(char a) {   
  bool num = false;
  if((a - '0' >= 0) && (a - '0' <= 9)) {
    num = true;
  }
  return (!num && (a != '.'));
}

bool isNumber(char a) {
    if((a - '0' >= 0) && (a - '0' <= 9)) {
        return true;
    }
    return false;
}

int main() { 
  string s;
  vector<string> v1;
  while(cin >> s) {
    v1.push_back(s);
  }
  int n = v1.size();
  int m = v1[0].size(); 
  int i = 0;
  int j = 0;
  int sum = 0;
  while(i < n) {
    j = 0;
    while(j < m) {
      bool cool = false;
      string num = "";
      while((j < m) && isNumber(v1[i][j])) {
        if(i - 1 >= 0) {
          if(isNum(v1[i - 1][j])) {
            cool = true;
          }
          if(j - 1 >= 0) {
            if(isNum(v1[i - 1][j - 1])) {
              cool = true;
            }
          }
          if(j + 1 < m) {
            if(isNum(v1[i - 1][j + 1])) {
              cool = true;
            }
          }
        } 
        if(j - 1 >= 0) { 
          if(isNum(v1[i][j - 1])) {
            cool = true;
          }
        }
        if(j + 1 < m) { 
          if(isNum(v1[i][j + 1])) {
            cool = true;
          }
        }
        if(i + 1 < n) { 
          if(j - 1 >= 0) {
            if(isNum(v1[i + 1][j - 1])) {
              cool = true;
            }
          }
          if(isNum(v1[i + 1][j])) {
            cool = true;
          }
          if(j + 1 < m) {
            if(isNum(v1[i + 1][j + 1])) {
              cool = true;
            }
          }
        }
        num += v1[i][j];
        j++;
      }
      if(cool) {
        sum += stoi(num);
      }
      if(!isNumber(v1[i][j])) {
        j++;
      }
    }
    i++;
  }
  cout << "sum --> " << sum << endl;
}
