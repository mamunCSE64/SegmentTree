#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define gcd __gcd
#define int_string to_string
#define string_int stoi
#define mn(v) *min_element(v.begin(), v.end())
#define mx(v) *max_element(v.begin(), v.end())
#define index_character s.find('character')
#define countxchar count(s.begin(), s.end(), 'x')
#define index_ofX_vector find(v.begin(), v.end(), x) - v.begin()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define n1 cout << "-1" << endl
#define sorted is_sorted(v.begin(), v.end())
#define nl << endl
#define sp << " "
#define mp make_pair
#define fi first
#define se second
#define Mx LLONG_MAX
#define Mn LLONG_MIN
const ll N = 2e5+5;
#define mod %1000000007
// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// BesidesDuplicateCharacterEraseInString s.erase(unique(s.begin(), s.end()), s.end());
// Upper/lower-> transform(s.begin(), s.end(), s.begin(), ::toupper/tolower);
using namespace std;
ll i, j, k, n, m;
const ll e=1e+9;
bool comp(pair<ll,ll> a,pair<ll,ll> b){ if(a.fi==b.fi) return (a.se>b.se);
return (a.fi<b.fi); }
// Don't get stuck on a single approach for long, think of multiple ways
// **********************|| Main Code ||********************************
// 
ll tree[4*N],lazy[4*N],aray[N];
void build(ll node,ll b,ll e){
    if(b==e) { tree[node]=aray[b];return; }
    ll mid=(b+e)/2;
    build(2*node,b,mid);
    build(2*node+1,mid+1,e);
    tree[node]=tree[2*node]+tree[2*node+1];
}
ll sum(ll node,ll b,ll e,ll l,ll r){
    if(lazy[node]){
        ll x=lazy[node];
        lazy[node]=0;
        tree[node]+=(e-b+1)*x;
        if(b!=e) lazy[2*node]+=x,lazy[2*node+1]+=x;
    }
    if(r<b or e<l) return 0;
    if(l<=b and e<=r) return tree[node];
    ll mid=(b+e)/2;
    ll x=sum(2*node,b,mid,l,r);
    ll y=sum(2*node+1,mid+1,e,l,r);
    return x+y;
}
void update(ll node,ll b,ll e,ll l,ll r,ll value){
    if(lazy[node]){
        ll x=lazy[node];
        lazy[node]=0;
        tree[node]+=(e-b+1)*x;
        if(b!=e) lazy[2*node]+=x,lazy[2*node+1]+=x;
    }
    if(r<b or e<l) return;
    if(l<=b and e<=r){
        ll x=(e-b+1)*value;
        tree[node]+=x;
        if(b!=e) lazy[2*node]+=value,lazy[2*node+1]+=value;
        return;
    }
    ll mid=(b+e)/2;
    update(2*node,b,mid,l,r,value);
    update(2*node+1,mid+1,e,l,r,value);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll test = 1;  
    // cin >> test;    
    again: 
    while (test--)  
    {
        ll n,q;
        cin>>n>>q;
        for(i=1;i<=n;i++) cin>>aray[i];
        build(1,1,n);
        while(q--){
            ll op,l,r,value;
            cin>>op;
            if(op==1) cin>>l>>r>>value,update(1,1,n,l,r,value);
            else cin>>l>>r,cout << sum(1,1,n,l,r) nl;
        }          
    }                  
}
