#include <iostream>
using namespace std;
// namespace std_out = std;
// using std::cout;

int main()
{
    // input
    int range = 300, size, freq[range] = {0};
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // count frequency
    for (int i = 0; i < size; i++)
        freq[arr[i]]++;

    for (int i = 0; i < range; i++)
        if (freq[i] > 0)
            cout << i << " " << freq[i] << endl;
}