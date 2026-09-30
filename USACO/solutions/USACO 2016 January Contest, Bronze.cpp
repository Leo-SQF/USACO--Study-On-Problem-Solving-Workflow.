#include <iostream>
using namespace std;
int main()
{
	long long bb, ba, sb, sa, gb, ga, pb, pa;
	cin >> bb >> ba >> 	sb >> sa >> gb >> ga >> pb >> pa;
	long long bout = bb - ba;
	long long sout = sb - sa;
	long long gout = gb - ga;
	long long pout = pb - pa;
	cout << bout << endl << sout << endl << gout << endl << pout << endl;
} 

    int br_b, br_a;
    int si_b, si_a;
    int go_b, go_a;
    int pl_b, pl_a;

    cin >> br_b >> br_a;
    cin >> si_b >> si_a;
    cin >> go_b >> go_a;
    cin >> pl_b >> pl_a;

    int g2p = pl_a - pl_b;
    int s2g = go_a - (go_b - g2p);
    int b2s = si_a - (si_b - s2g);

    cout << b2s << endl;
    cout << s2g << endl;
    cout << g2p << endl;

    return 0;
}

