#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // For file input/output (USACO standard)
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<string> currentLine;
    int currentTotal = 0; // sum of lengths of words on current line (no spaces)

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        int len = word.size();

        if (currentTotal + len <= K)
        {
            // can add this word to current line
            currentLine.push_back(word);
            currentTotal += len;
        }
        else
        {
            // print out the current line
            for (int j = 0; j < currentLine.size(); j++)
            {
                if (j > 0) cout << " ";
                cout << currentLine[j];
            }
            cout << endl;

            // start new line with this word
            currentLine.clear();
            currentLine.push_back(word);
            currentTotal = len;
        }
    }

    // print the last remaining line
    for (int j = 0; j < currentLine.size(); j++)
    {
        if (j > 0) cout << " ";
        cout << currentLine[j];
    }
    cout << endl;

    return 0;
}

