/*problem: There are N cows on the farm. Each cow has coordinates (x,y) and a happiness value h.

The farmer wants to pick exactly 2 cows for a small party.

The party follows these rules:
The Manhattan distance between the two cows, (|x_1-x_2|+|y_1-y_2|), must be no bigger than D. If they are too far apart, they cannot hold the party.

The total happiness of the party equals the sum of the two cows' happiness values.

If multiple pairs of cows satisfy the distance requirement, choose the pair with the **largest total happiness**.
If several pairs share the same maximum total happiness: pick the pair with the **smaller Manhattan distance**.
If both the total happiness and distance are identical: pick the pair with the smaller cow IDs (cows are numbered starting from 1 in input order).

If no valid pair of cows meets the distance limit, output `NO PAIR`.
Otherwise, output one line with four integers: ID of cow A, ID of cow B, total happiness, Manhattan distance.

## Input Format

Input file: `cowparty.in`
The first line contains two integers (N,D).
The next N lines each contain three integers (x,y,h), representing the coordinates and happiness value of the 1st, 2nd, …, N-th cow in order.

## Output Format

Output file: `cowparty.out`
Output according to the rules above; output `NO PAIR` if there is no valid pair.

## Data Range (Bronze standard)

\(2\le N\le 500\)
\(-1000\le x,y\le 1000\)
\(1\le h\le 1000\)
\(1\le D\le 4000\)

Note: For \(N=500\), enumerating all pairs gives \(500\times499/2=124750\) pairs. A brute-force double loop will work perfectly and will not time out.
*/
//solution:
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

struct Cow
{
	int id, x , y , h ;
};

int main()
{
	freopen("cowparty.in","r",stdin);
    freopen("cowparty.out","w",stdout);
    int N , D ;
    cin >> N >> D ;
    Cow cow[505];
    for (int i = 1 ; i <= N ; i ++)
    {
    	cin >> cow[i].x >> cow[i].y >> cow[i].h;
    	cow[i].id = i;
	}
	
	int h_max = -1;
	int dist_min;
	int a,b;
	for (int i = 1; i <= N ; i ++)
	{
		for (int j = i + 1 ; j <= N ; j ++)
		{
			int dist = abs(cow[i].x - cow [j].x) + abs(cow[i].y -cow[j].y);
			if (dist > D) continue;	
			
			int h_value = cow[i].h + cow[j].h;
			if (h_value > h_max || 
			(h_value == h_max && dist < dist_min)  || 
			(h_value == h_max && dist == dist_min && cow[i].id < a))
			{
                h_max = h_value;
                dist_min = dist;
                a = cow[i].id;
                b = cow[j].id;
			}
		}
	}
	if(h_max == -1)
	{
        cout << "NO PAIR" << endl;
    }
	else
	{
        cout << a << " " << b << " " << h_max << " " << dist_min << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;	
} 
/*
notes:
today was not logged in in the usual manner. This problem was AI generated, but it was I who sloved it. 
I think that this problem is no simpler than any bronze problem.
Infact I found that doing this problem proved more halpful than the first five days of coding
perhaps because I specificlly asked AI to generate a problem that"encompassed all Bronze skills"

*/

