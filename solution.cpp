#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
	int i = 20;
	char buf[21];
	// buf[10] = 0;
	buf[20] = '\n';

	do
	{
		buf[--i] = x % 10 + '0';
		x/= 10;
	}while(x);
	do
	{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

template <typename T> inline T readInt()
{
	T n=0,s=1;
	char p=getchar();
	if(p=='-')
		s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-')
		p=getchar();
	if(p=='-')
		s=-1,p=getchar();
	while(p>='0'&&p<='9') {
		n = (n<< 3) + (n<< 1) + (p - '0');
		p=getchar();
	}

	return n*s;
}
/************************************/


/******* Debugging Class Template *******/
#define DEBUG

#ifdef DEBUG

    #define debug(args...)     (Debugger()) , args

    class Debugger
    {
        public:
        Debugger(const std::string& _separator = " - ") :
        first(true), separator(_separator){}

        template<typename ObjectType> Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std:cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std:cerr << endl;}

        private:
        bool first;
        std::string separator;
    };

#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

/**************************************/

/******** User-defined Function *******/


/**************************************/

struct contributor
{
	string name;
	int types;
	vector<pair<string,int> > v;
};
struct project{
	string name;
	int duration;
	int score;
	int days;
	int no;
	vector<pair<string,int> > v;
	vector<string> ans;
};

struct Skills{
	string name;
	vector<pair<string,int> > people;
};

void ans(int p,project a[],Skills skill[],int n){
	cout<<p<<endl;
	set<string> s;
	REP(i,p){
		cout<<a[i].name<<endl;
		int k=a[i].no;
		REP(j,k){
			REP(l,n){
				if(skill[l].name==a[i].v[j].first){
					int size=skill[l].people.size();
					REP(m,size){
						if(skill[l].people[m].second+1>=a[i].v[j].second){
							s.insert(skill[l].people[m].first);
							break;
						}
					}
					break;
				}
			}
		}
		vector<string> v(s.begin(), s.end());
		REP(i,v.size()){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
}

void searchSkill(int c,string s,contributor arr[],Skills skill){
	int i=0;
	while(i<c){
		int k=arr[i].types;
		REP(j,k){
			if(arr[i].v[j].first==s){
				skill.people.push_back({arr[i].name,arr[i].v[j].second});
				break;
			}
		}
		i++;
	}
}
void Input()
{
set<string> se;
	int c,p;
	cin>>c>>p;
	struct contributor arr[c]; 
	REP(i,c){
		cin>>arr[i].name;
		int n;
		cin>>n;
		arr[i].types=n;
		REP(j,n){
			string s;
			int val;
			cin>>s>>val;
			se.insert(s);
			arr[i].v.push_back({s,val});
		}
	}
	struct project a[p];
	REP(i,c){
		cin>>a[i].name;
		int n;
		cin>>n;
		a[i].duration=n;
		int sc;
		cin>>sc;
		a[i].score=sc;
		int d;
		cin>>d;
		a[i].days=d;
		cin>>n;
		a[i].no=n;
		REP(j,n){
			string s;
			int val;
			cin>>s>>val;
			a[i].v.push_back({s,val});
		}
	}
	vector<string> ve(se.begin(), se.end());
	Skills skill[ve.size()];
	REP(i,ve.size()){
		skill[i].name=ve[i];
		searchSkill(c,ve[i],arr,skill[i]);
	}
	ans(p,a,skill,ve.size());
	}

/********** Main()  function **********/
int main()
{

	// #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	// #endif

	Input();
	return 0;
}