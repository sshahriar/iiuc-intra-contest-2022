#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll  ;

#define  int ll 
const int maxn   = (int)3e5 + 123 ;

int n , m , k, l, r ;
int a[maxn ]  , b[30]; 
bool checkbit(int x ,int id ) {
    return   (bool)(x&(1<< id))  ;
} 
int get_res() {
    int cnt = 0; 
    // get m maximum elements in array b 
    for(int i= l ; i<=r ;i++ ) b[cnt++  ]  =  a[ i ]  ;
    sort(b, b+cnt ) ;
    reverse(b,b+cnt ) ; 

    // try all possible subset of length m to find any divisible by k
    for(int mask = 1 ; mask < (1<< m); mask++){
        int tot = 0 ; 
        vector<int >v ;
        for(int j=0 ; j<m ; j++ ) {
            if(checkbit(mask ,  j )  ) {
                tot +=  b[ j] ; 
                v.push_back(b[j]) ;        
            }
        } 
        if(tot % k  == 0  ) {
            return 1 ;
        }
    }   

    return  0 ; 
}
void  solve() {      
    int x,y,z ,  ans = 0 , mx = 0 , mn=inf  ;         
    int q ;

    cin >> n  ;
    for( int i=0; i<n ;i++  ) cin >> a[i  ] ;
    
    cin >> q  ; 
    while(q-- ) {
        cin >> l >> r >> m >> k ; 
        l--, r--  ; 
        if( get_res() )  cout <<  "YES" << endl ;
        else cout << "NO"  << endl ;
    }
}                  
signed main() {      
    #ifdef Local            
        freopen("in.txt", "r", stdin);  
    #endif 
    ios :: sync_with_stdio(false);  
    cin.tie(0);  
    cout << fixed << setprecision( 12  ) ; 
    int t = 1 , cs = 0  ; 
    // cin >> t  ;   
    while(t--)   {         
        // cout <<  "Case #"  <<  ++cs<< ": " ;
        solve()  ;   
    }   
    return 0 ;      

}    



// g++ -DLocal -std=c++11 f.cpp -o f.exe
// ./f.exe  

