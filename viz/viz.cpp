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
    cout << endl;

    for_each(array.begin(), array.end(), [](int &e) { e = e < 42 ? 0 : 1; });

    bin_search(array, 1);
    cout << endl;

    array = vector<int>{0, 0, 0, 1, 1, 1, 2, 2, 2};

    int low =
        distance(array.begin(), lower_bound(array.begin(), array.end(), 1));
    int upp =
        distance(array.begin(), upper_bound(array.begin(), array.end(), 1));

    cout << "Lower bound:" << endl;
    cout << array << endl;
    print_cursors({low});

    cout << "Upper bound:" << endl;
    cout << array << endl;
    print_cursors({upp});

    cout << "Lower bound + 1:" << endl;
    cout << array << endl;
    print_cursors({low + 1});

    cout << "Upper bound + 1:" << endl;
    cout << array << endl;
    print_cursors({upp + 1});
    cout << endl;

    // cout << array << endl;
    // print_cursors({1, 3, 4, 8});

    return 0;
}
