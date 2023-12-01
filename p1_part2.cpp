#include <bits/stdc++.h> 

using namespace std;

int main() {
  string s;
  long long int ans = 0;
  map<string,bool> m1;
  vector<string> v1 = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  while(cin >> s) {
    int n = s.length();
    bool first = false;
    bool second = false;
    for(int i = 0; i < s.length(); i++) { 
      if(s[i] >= '0' && s[i] <= '9') {
          ans += (long long int)(s[i] - '0') * (long long int)10;
          break;
      } 
      for(int j = 0; j < 10; j++) {
        int len = v1[j].length();
        if(i + len - 1 <= n - 1) {
          if(s.substr(i, len) == v1[j]) {
            ans += (long long int)(j * 10);
            first = true;
            break;
          }
        }
      } 
      if(first) break;
    }  

    for(int i = s.length() - 1; i >= 0; i--) {  
      if(s[i] >= '0' && s[i] <= '9') {
          ans += (long long int)(s[i] - '0');
          break;
      }  
      for(int j = 0; j < 10; j++) {
        int len = v1[j].length();
        if(i - len >= 0) {  
          if(s.substr(i - len + 1, len) == v1[j]) {
            ans += (long long int)(j); 
            second = true;
            break;
          }
        }
      }
      if(second) break;
    }
  }
  cout << "ans: " << ans << endl;
}
