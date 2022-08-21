#include <bits/stdc++.h> 
using namespace std; 
#define ff              first
#define ss              second
#define pb(x)           push_back(x)
#define mp              make_pair
#define sz(x)           (int)x.size()
#define mem(x ,y)       memset(x , y , sizeof x )
#define all(a )         a.begin() , a.end()  
#define pii             pair<int,int >
#define endl            "\n"  
#define forn(i,x,y )    for(int i= x; i<=y ; i++ )  
#define ford(i,x,y )    for(int i= x; i>=y ; i-- )  
#define rep(i,n )       for(int i= 0; i<n ; i++ ) 
#define repi(i,n )      for(int i= 1; i<=n ; i++ ) 
#define repit(i, c)     for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )

#ifdef  Local           
    #define dbg(args...)    do {   cout << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
#else 
    #define dbg(args...)   ; 
#endif 

typedef long long ll  ;
typedef unsigned long long ull  ;
ll  mod =  1e9+7, mod2 =     998244353  ;

 
// int setbit(int n, int pos  ) { return n = n|(1LL<< pos) ; }
// int resetbit(int n,int pos ) { return n = n & ~(1LL<<pos ); }
// bool checkbit(int n,int pos) { return (bool ) (n&(1LL<<pos))  ; }

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type , 
    less_equal<T> , rb_tree_tag , tree_order_statistics_node_update> ;   
template<typename T>ostream &operator<<(ostream & os, const ordered_set< T > &Set) {os << "[ "; repit(it , Set )os <<  *it  << ' ' ; return os << " ]\n" ; }  
    // order_of_key (k) : Number of items strictly smaller than k .
    // find_by_order(k) : K-th element in a set (counting from zero).
    // less_equal for  multiset 
   
template<typename T> void print(const T& v) {    cout << v << ' ' ;}
template<typename T1,typename... T2> void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
template<typename T> void dbg_a(T a[] ,int n=10 ) {cerr << "[ "; for(int i=0;i <= n ; i++ )cerr<<a[i]<<' ' ; cerr<< " ]" <<  endl; } 
template<typename F,typename S>ostream& operator<<( ostream& os, const pair< F, S > & p ){return os << "[ " << p.first << ", " << p.second << " ]";}
template<typename T>ostream &operator<<(ostream & os, const vector< T > &v ){os << "[ "; for(int i=0; i<sz(v) ; i++ )  os << v[i] << ' ' ; return os << " ]\n" ; } 
template<typename T>ostream &operator<<(ostream & os, const map< T ,T> &Map ){os << "[ "; repit(it , Map ) os << "[" <<(*it).ff << ' ' << (*it).ss << "] "    ; return os << "]\n" ; } 
template<typename T>ostream &operator<<(ostream & os, const set< T > &Set  ){os << "[ "; repit(it , Set ) os <<  *it  << ' ' ; return os << " ]\n" ; }  
template<typename T>ostream &operator<<(ostream & os, const multiset< T > &Set) {os << "[ "; repit(it , Set )os <<  *it  << ' ' ; return os << " ]\n" ; }  
 
#define  int ll 
const int inf  =    1e9  ;   //0xc0  ;//0x3f ;   
const int maxn   = (int)3e5 + 123 ;

////////////////////////////////////////////////

int n , m , k , flag =   0  ;  
int a[maxn ]  , b[30]; 
int l, r ;
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
                v.pb(b[j]) ;        
            }
        } 

        if(tot % k  == 0  ) {
            cout << v ;
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

 




 
