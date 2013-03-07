#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <set>
#include <numeric>
#include <stack>
using namespace std;
class integer
{
    bool sign;
    static const uint base = 1000000000;
    std::vector<uint> nums;
    void operator ++(int){}
    void operator --(int){}
    int relation(const integer& r) const;
public:
    integer(){}
    integer(long long int n)
    {
        sign = n < 0;
        if( n < 0 )
            n = -n;
        while(n)
        {
            nums.push_back(n % base);
            n /= base;
        }
        if( !nums.size() )
            nums.push_back(0);
    }
    
    integer(unsigned long long int n)
    {
        sign = false;
        while(n)
        {
            nums.push_back(n % base);
            n /= base;
        }
        if( !nums.size() )
            nums.push_back(0);
    }
    integer(int n)
    {
        *this = integer(static_cast<long long>(n));
    }
    integer(uint n)
    {
        *this = integer(static_cast<unsigned long long>(n));
    }
    integer(const string& s)
    {
        int start = 0;
        sign = false;
        if( !s.size() )
        {
            nums.push_back(0);
            return;
        }

        if( s[0] == '-' )
        {
            if( (int)s.size() == 1 )
            {
                cerr << "string is not an integer" << endl;
                exit(2);
            }
            sign = true;
            start = 1;
        }

        while( start < (int)s.size() && !(s[start] - '0') )
            ++start;
        if( start == (int)s.size() )
        {
            nums.push_back(0);
            sign = false;
            return;
        }

        for(int i = start ; i < (int)s.size() ; ++i)
            if( s[i] < '0' || s[i] > '9' )
            {
                cerr << "string is not an integer" << endl;
                exit(1);
            }

        for(int i = (int)s.size() - 1 ; i >= start ; i -= 9 )
        {
            uint n = 0;
            for(int j = max(start,i - 9 + 1) ; j <= i ; ++j)
            {
                n = n * 10 + s[j] - '0';
            }
            nums.push_back(n);
        }
    }
    integer(const char* s)
    {
        *this = integer(string(s));
    }

    const integer& operator +() const
    {
        return *this;
    }
    const integer operator -() const
    {
        integer temp(*this);
        temp.sign = !sign;
        return temp;
    }

    bool operator !() const
    {
        if( nums.size() == 1 && nums[0] == 0 )
            return true;
        return false;
    }

    integer* operator &()
    {
        return this;
    }

    integer& operator ++()
    {
        *this += 1;
        return *this;
    }

    integer& operator --()
    {
        *this -= 1;
        return *this;
    }

    integer& operator +=(const integer& r)
    {
        return *this = *this + r;
    }

    integer& operator -=(const integer& r)
    {
        return *this = *this - r;
    }

    integer& operator *=(const integer& r)
    {
        return *this = *this * r;
    }

    integer& operator /=(const integer& r)
    {
        return *this = *this / r;
    }

    integer& operator %=(const integer& r)
    {
        return *this = *this % r;
    }

    integer abs() const
    {
        if( !sign )
            return *this;
        return -*this;
    }

    friend bool operator <(const integer&, const integer&);
    friend bool operator >(const integer&, const integer&);
    friend bool operator ==(const integer&, const integer&);
    friend bool operator <=(const integer&, const integer&);
    friend bool operator >=(const integer&, const integer&);

    friend const integer operator +(const integer&,const integer&);
    friend const integer operator -(const integer&,const integer&);
    friend const integer operator *(const integer&,const integer&);
    friend const integer operator /(const integer&,const integer&);
    friend const integer operator %(const integer&,const integer&);

    friend istream& operator >>(istream&,integer&);
    friend ostream& operator <<(ostream&,const integer&);
};

bool operator <(const integer& l, const integer& r)
{
    if( l.sign != r.sign )
        return l.sign > r.sign;

    if( l.nums.size() != r.nums.size() )
    {
        if( !l.sign )
            return l.nums.size() < r.nums.size();
        else
            return l.nums.size() > r.nums.size();
    }

    int i = l.nums.size() - 1;
    while( i >= 0 && l.nums[i] == r.nums[i] )
        --i;

    if( i < 0 )
        return false;

    if( !l.sign )
        return l.nums[i] < r.nums[i];
    else
        return l.nums[i] > r.nums[i];
}

bool operator >(const integer& l, const integer& r)
{
    return !(l < r);
}

bool operator ==(const integer& l, const integer& r)
{
    if( l.sign != r.sign || l.nums.size() != r.nums.size() )
        return false;
    
    return l.nums == r.nums;
}

bool operator !=(const integer& l, const integer& r)
{
    return !(l == r);
}
bool operator <=(const integer& l, const integer& r)
{
    return l < r || l == r;
}

bool operator >= (const integer& l, const integer& r)
{
    return l > r || l == r;
}

int integer::relation(const integer& r) const
{
    //returns 0 if less than r , 1 if greater than r , 2 if equal to r
    if( nums.size() != r.nums.size() )
        return nums.size() > r.nums.size();

    int i = nums.size() - 1;
    while( i >= 0 && nums[i] == r.nums[i] )
        --i;

    if( i < 0 )
        return 2;
    return nums[i] > r.nums[i];
}

const integer operator +(const integer& l, const integer& r)
{
    integer ans;
    if( l.sign == r.sign )
    {
        ans.sign = l.sign;
        unsigned long long carry = 0;
        for(int i = 0 ; i < (int)l.nums.size() || i < (int)r.nums.size() ; ++i)
        {
            if( i < (int)l.nums.size() )
                carry += l.nums[i];
            if( i < (int)r.nums.size() )
                carry += r.nums[i];
            ans.nums.push_back(carry % l.base);
            carry /= l.base;
        }
        if( carry )
            ans.nums.push_back(carry);
    }
    else
    {
        int rel = l.relation(r);
        int carry = 0;
        if( rel == 2 )
            return integer(0);
        else if( rel == 1 )//l > r
        {
            ans.sign = l.sign;
            for(int i = 0 ; i < (int)r.nums.size() ; ++i)
            {
                if( l.nums[i] - carry >= r.nums[i] )
                {
                    ans.nums.push_back(l.nums[i] - carry - r.nums[i]);
                    carry = 0;
                }
                else
                {
                    ans.nums.push_back( l.base + l.nums[i] - carry - r.nums[i] );
                    carry = 1;
                }
            }
            for(int i = r.nums.size() ; i < (int)l.nums.size() ; ++i)
            {
                ans.nums.push_back(l.nums[i] - carry);
                carry = 0;
            }
        }
        else
        {
            ans.sign = r.sign;
            for(int i = 0 ; i < (int)l.nums.size() ; ++i)
            {
                if( r.nums[i] - carry >= l.nums[i] )
                {
                    ans.nums.push_back(r.nums[i] - carry - l.nums[i]);
                    carry = 0;
                }
                else
                {
                    ans.nums.push_back( l.base + r.nums[i] - carry - l.nums[i] );
                    carry = 1;
                }
            }
            for(int i = l.nums.size() ; i < (int)r.nums.size() ; ++i)
            {
                ans.nums.push_back(r.nums[i] - carry);
                carry = 0;
            }
        }
        while( !ans.nums[ans.nums.size() - 1] )
            ans.nums.pop_back();
    }
    return ans;
}

const integer operator -(const integer& l, const integer& r)
{
    return l + (-r);
}

const integer operator *(const integer& l, const integer& r)
{
    integer ans(0);
    if( l.sign == r.sign )
        ans.sign = false;
    else
        ans.sign = true;
    integer temp;
    temp.sign = ans.sign;
    unsigned long long carry = 0;
    for(int i = 0 ; i < (int)r.nums.size() ; ++i)
    {
        temp.nums.clear();
        for(int j = 0 ; j < i ; ++j)
            temp.nums.push_back(0);
        for(int j = 0 ; j < (int)l.nums.size() ; ++j)
        {
            carry = (unsigned long long)r.nums[i] * l.nums[j] + carry;
            temp.nums.push_back( carry % l.base );
            carry /= l.base;
        }
        while(carry)
        {
            temp.nums.push_back( carry % l.base );
            carry /= l.base;
        }
        ans += temp;
    }
    return ans;
}

const integer operator /(const integer& left,const integer& right)
{
    integer l(left),r(right);
    l.sign = r.sign = false;
    if( r > l )
        return integer(0);
    integer ans;
    if( left.sign == right.sign )
        ans.sign = false;
    else
        ans.sign = true;

    int pos;
    integer rem;
    rem.sign = false;
    for(int i = l.nums.size() - r.nums.size() + 1; i < (int)l.nums.size() && i >= 0 ; ++i)
        rem.nums.push_back(l.nums[i]);
    if( !rem.nums.size() )
        rem = 0;

    uint start,end,mid;
    for(int i = l.nums.size() - r.nums.size() ; i >= 0 ; --i)
    {
        rem = rem * rem.base + l.nums[i];
        start = 0, end = rem.base - 1;
        while( start < end )
        {
            mid = (start + end + 1)/2;
            if( r * mid <= rem )
                start = mid;
            else
                end = mid - 1;
        }
        rem -= start * r;
        if( ans.nums.size() )
            ans.nums[pos--] = start;
        else if( start > 0 )
        {
            ans.nums.resize(i + 1);
            pos = i;
            ans.nums[pos--] = start;
        }
    }
    l.sign = left.sign, r.sign = r.sign;
    return ans;
}

const integer operator %(const integer& l, const integer& r)
{
    return l - (l/r) * r;
}

istream& operator >>(istream& is,integer& Int)
{
    string s;
    is >> s;
    Int = integer(s);
    return is;
}

ostream& operator <<(ostream& os,const integer& Int)
{
    if( !Int.nums.size() )
    {
        cerr << "integer not initialized" << endl;
        exit(4);
    }
    if( Int.sign )
        os << "-";
    os << Int.nums[ Int.nums.size() - 1 ];
    for(int i = (int)Int.nums.size() - 2 ; i >= 0 ; --i)
    {
        int len = 0;
        uint temp = Int.nums[i];
        while(temp)
        {
            ++len;
            temp /= 10;
        }
        for(int j = 0 ; j < 9 - len ; ++j)
            os << '0';
        if( Int.nums[i] )
            os << Int.nums[i];
    }
    return os;
}


using namespace std;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
typedef integer ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

vector<ii> decompose(ii frac) {
    ll ceiling = frac.Y / frac.X;
    if (frac.Y % frac.X > 0) ceiling+=1;

    ii f1 = mp(1, ceiling);
    ii f2;
    f2.X = (-frac.Y) % frac.X;
    f2.Y = ceiling * frac.Y;
    vector<ii> result;
    result.push_back(f1);
    result.push_back(f2);
    return result;
}

vi solve(ii frac) {
    if (frac.X == 1) return vi(1, frac.Y);
    vi result;
    while(1) {
        vector<ii> fractions = decompose(frac);
        result.push_back(fractions[0].Y);
        if (fractions[1].X == 1) {
            result.push_back(fractions[1].Y);
            break;
        }
        else if (fractions[1].X == 0) {
            break;
        }
        else {
            frac = fractions[1];
        }
    }
    return result;
}

void display(vi result) {
    int n = result.size();
    REP(i, n-1) cout << result[i] << " ";
    cout << result[n-1] << endl;
}

int main() {
    ll a = 0, b = 0;
    while(1) {
        cin >> a >> b;
        if (!(a == 1 && b == 1))
            display(solve(mp(a, b)));
        else 
            break;
    }
    return 0;
}