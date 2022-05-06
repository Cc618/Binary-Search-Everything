#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        os << setw(2) << arr[i];
        if (i + 1 != arr.size())
            os << ' ';
    }

    return os;
}

// Print cursors for each elements (1 indexed)
void print_cursors(const set<int> &cursors) {
    string s;
    for (auto c : cursors) {
        s += string(3 * c - s.size() - 2, ' ');
        s += '^';
    }
    cout << s << endl;
}

int bin_search(const vector<int> &arr, int val) {
    int l = 0;
    int r = arr.size();
    while (l < r) {
        cout << arr << endl;
        print_cursors({l + 1, r});

        int mid = l + (r - l) / 2;
        if (arr[mid] < val) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return l;
}

int main() {
    vector<int> array{1, 4, 5, 6, 8, 10, 10, 13, 18, 42, 64};

    bin_search(array, 42);

    // cout << array << endl;
    // print_cursors({1, 3, 4, 8});

    return 0;
}
