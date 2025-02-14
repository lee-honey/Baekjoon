#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string realStr, compStr;
    cin >> realStr >> compStr;

    vector<char> st;
    int compSize = compStr.size();

    for (char c : realStr) {
        st.push_back(c);

        if (c == compStr[compStr.size() - 1] && st.size() >= compSize) {
            bool isMatch = true;
            for (int i = 0; i < compSize; i++) {
                if (st[st.size() - compSize + i] != compStr[i]) {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {
                for (int i = 0; i < compSize; i++)
                    st.pop_back();
            }
        }
    }

    if (st.empty()) {
        cout << "FRULA\n";
    } else {
        for (char c : st) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}
