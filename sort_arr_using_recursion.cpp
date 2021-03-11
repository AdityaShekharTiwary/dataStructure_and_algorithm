#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define vll vector<ll>
#define dbl double
#define vi vector<int>
#define pb push_back
#define input_arr for(ll i=0;i<n;i++) cin>>arr[i];
#define f(i,s,e) for(ll i=s;i<e;i++)
#define fo(i,s,e) for(ll i=s;i<=e;i++)
#define mi map<int,int>
#define mp make_pair
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define pb push_back
#define ff first
#define ss second
#define test int t; cin>>t; while(t--)
#define fast_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


void fast()
{
	#ifndef ONLINE_JUDGE
		freopen("input1.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

	fast_IO	
	cout.tie(NULL);
}

void sort_arr(vi &arr,int n){
	if(n==1) return;

	f(i,0,n-1){	
		if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
	}
	sort_arr(arr,n-1);
}

void solve()
{
	int n; cin>>n;
	vi arr(n);
	input_arr
	sort_arr(arr,n);
	cout<<endl;
	f(i,0,n) cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	fast();

	test
	{
		solve();
	}

	return 0;
}
