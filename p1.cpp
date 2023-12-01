#include <bits/stdc++.h> 

using namespace std;

int main() {
  string s;
  long long int ans = 0;
  while(cin >> s) {
    for(int i = 0; i < s.length(); i++) {
      if(s[i] >= '0' && s[i] <= '9') {
          ans += (long long int)(s[i] - '0') * (long long int)10;
          break;
      }
    }
    for(int i = s.length() - 1; i >= 0; i--) {
      if(s[i] >= '0' && s[i] <= '9') {
          ans += (long long int)(s[i] - '0');
          break;
      }
    }
  }
  cout << "ans: " << ans << endl;
}
