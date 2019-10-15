#include<bits/stdc++.h>

using namespace std;

#define LL           long long
#define ULL          long long unsigned
#define LD           long double
#define ff              first
#define ss              second
#define FOR(i,n)     for(int i=0;i<n;i++)
#define FLR(i,n)     for(LL i=0;i<n;i++)
#define RFOR(i,n)    for(int i=n-1;i>=0;i--)
#define RFLR(i,n)    for(LL i=n-1;i>=0;i--)
#define rep(i,a,b)   for(int i=a;i<=b;i++)
#define repl(i,a,b)  for(LL i=a;i<=b;i++)
#define fast         ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a)       a.begin(),a.end()
#define ABS(x)       ((x)<0?-(x):(x))
#define NL           "\n"
#define pb           push_back
#define mk              make_pair
#define pi           acos(-1.0)
#define prec(n)      fixed << setprecision(n)
#define sq(a)          (a)*(a)
#define mx           1000000

int arr[mx];
int tree[mx*4];

void build(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];
        return;
        }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);

}
int query(int node,int b,int e,int i,int j){
    if(i>e||j<b)return mx;
    else if(b>=i&&e<=j)return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);

}

int main()
{
    fast;
    int t,i,j,k,a,b,e,q,n,kase=1,ans;
    cin>>t;
    while(t--){
        cin>>n>>q;
        FOR(i,n){
            cin>>arr[i+1];
        }
        build(1,1,n);
        //cout<<"Case "<<kase++<<":"<<endl;
        printf("Case %d:\n",kase++);
        FOR(i,q){
            cin>>a>>b;
            ans=query(1,1,n,a,b);
            printf("%d\n",ans);
        }
    }
}
