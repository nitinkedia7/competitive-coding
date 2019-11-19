#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int min(int a, int b) 
{ 
    return (a < b) ? a : b; 
} 
  
// Function to calculate maximum overlap in two given strings 
int findOverlappingPair(string str1, string str2, string &str) 
{ 
    // max will store maximum overlap i.e maximum 
    // length of the matching prefix and suffix 
    int max = INT_MIN; 
    int len1 = str1.length(); 
    int len2 = str2.length(); 
  
    // check suffix of str1 matches with prefix of str2 
    for (int i = 1; i <= min(len1, len2); i++) 
    { 
        // compare last i characters in str1 with first i 
        // characters in str2 
        if (str1.compare(len1-i, i, str2, 0, i) == 0) 
        { 
            if (max < i) 
            { 
                //update max and str 
                max = i; 
                str = str1 + str2.substr(i); 
            } 
        } 
    } 
  
    // check prefix of str1 matches with suffix of str2 
    for (int i = 1; i <= min(len1, len2); i++) 
    { 
        // compare first i characters in str1 with last i 
        // characters in str2 
        if (str1.compare(0, i, str2, len2-i, i) == 0) 
        { 
            if (max < i) 
            { 
                //update max and str 
                max = i; 
                str = str2 + str1.substr(i); 
            } 
        } 
    } 
  
    return max; 
} 
  
// Function to calculate smallest string that contains 
// each string in the given set as substring. 
string findShortestSuperstring(string arr[], int len) 
{ 
    // run len-1 times to consider every pair 
    while(len != 1) 
    { 
        int max = INT_MIN;  // to store  maximum overlap 
        int l, r;   // to store array index of strings 
        // involved in maximum overlap 
        string resStr;  // to store resultant string after 
        // maximum overlap 
  
        for (int i = 0; i < len; i++) 
        { 
            for (int j = i + 1; j < len; j++) 
            { 
                string str; 
  
                // res will store maximum length of the matching 
                // prefix and suffix str is passed by reference and 
                // will store the resultant string after maximum 
                // overlap of arr[i] and arr[j], if any. 
                int res = findOverlappingPair(arr[i], arr[j], str); 
  
                // check for maximum overlap 
                if (max < res) 
                { 
                    max = res; 
                    resStr.assign(str); 
                    l = i, r = j; 
                } 
            } 
        } 
  
        len--;  //ignore last element in next cycle 
  
        // if no overlap, append arr[len] to arr[0] 
        if (max == INT_MIN) 
            arr[0] += arr[len]; 
        else
        { 
            arr[l] = resStr;   // copy resultant string to index l 
            arr[r] = arr[len];  // copy string at last index to index r 
        } 
    } 
    return arr[0]; 
} 
// string process(string& s) {
//         int n = s.length();
//         string t(2 * n + 3, '#');
//         t[0] = '$'; t[2 * n + 2] = '%';
//         for (int i = 0; i < n; i++)
//             t[2 * (i + 1)] = s[i];
//         return t;
//     }
// string shortestPalindrome(string s) {
//         string t = process(s);
//         int n = t.length(), center = 0, right = 0;
//         int* palin = new int[n];
//         for (int i = 1; i < n - 1; i++) {
//             int i_mirror = 2 * center - i;
//             palin[i] = (right > i) ? min(palin[i_mirror], right - i) : 0;
//             while (t[i + palin[i] + 1] == t[i - palin[i] - 1])
//                 palin[i]++;
//             if (i + palin[i] > right) {
//                 center = i;
//                 right = i + palin[i];
//             }
//         }
//         int pos;
//         for (int i = n - 2; i; i--) {
//             if (i - palin[i] == 1) {
//                 pos = palin[i];
//                 break;
//             }
//         }
//         string tail = s.substr(pos); 
//         reverse(tail.begin(), tail.end());
//         return tail + s;
//     }
string shortestPalindrome(string s)
{
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    string s_new = s + "#" + rev;
    int n_new = s_new.size();
    vector<int> f(n_new, 0);
    for (int i = 1; i < n_new; i++) {
        int t = f[i - 1];
        while (t > 0 && s_new[i] != s_new[t])
            t = f[t - 1];
        if (s_new[i] == s_new[t])
            ++t;
        f[i] = t;
    }
    return rev.substr(0, n - f[n_new - 1]) + s;
}

  // Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(string pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}   
  
// Prints occurrences of txt[] in pat[] 
bool KMPSearch(string pat, string txt) 
{ 
    int M = pat.size(); 
    int N = txt.size(); 
  
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            return true;
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    return false;
} 
  


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s1,s2;
        cin>>s1>>s2;
        int sz1,sz2;
        sz1 = s1.size();
        sz2 = s2.size();
        string pat,txt;
        if(sz1<sz2){
            pat = s1;
            txt = s2;
        }
        else{
            pat = s2;
            txt = s1;
        }
        if(KMPSearch(pat,txt)){
            string r = shortestPalindrome(txt);
            cout<<r.size()<<endl;
        }
        else{
            string arr[] = {s1,s2};
            int len = sizeof(arr)/sizeof(arr[0]); 
            string ans = findShortestSuperstring(arr, len);
            string r = shortestPalindrome(ans);
            // cout<<ans<<endl;
            reverse(ans.begin(),ans.end());
            string r1 = shortestPalindrome(ans);
            // cout<<ans<<endl;
            // cout<<r<<endl;
            // cout<<r1<<endl;
            cout<<min(r.size(),r1.size())<<endl;
            }
   
    }
    
   
  
    return 0; 
}