#include<bits/stdc++.h>

using namespace std;


#define FOR(i,n)     for(int i=0;i<n;i++)
#define mx           1000000

int arr[mx];
int tree[mx*4];

void build(int node,int b,int e)
{
    if(b==e)
    {
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
int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)
        return mx;
    else if(b>=i&&e<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);

}

int main()
{
    int t,i,j,k,a,b,e,q,n,ans;
    cin>>n;
       FOR(i,n)
    {
        cin>>arr[i+1];
    }
    build(1,1,n);
    cin>>a>>b;
    ans=query(1,1,n,a,b);
    cout<<ans<<endl;
}
