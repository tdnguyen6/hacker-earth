#include <iostream>
#include <string>
using namespace std;

void seating_arrangement();

int main()
{
    int test_num;
    cin >> test_num;
    while (test_num--)
    {
        seating_arrangement();
    }
    return 0;
}

void seating_arrangement()
{
    int seat_num; // 96
    cin >> seat_num;
    int seat_group = (seat_num - 1) / 12;
    int base_seat_num = seat_num - (seat_group * 12);  // 12
    int base_opposite_seat_num = (13 - base_seat_num); // 1
    int opposite_seat_num = base_opposite_seat_num + 12 * seat_group;
    int seat_type_unit = opposite_seat_num % 6;
    string opposite_seat_type;
    switch (seat_type_unit)
    {
    case 0:
    case 1:
        opposite_seat_type = "WS";
        break;
    case 2:
    case 5:
        opposite_seat_type = "MS";
        break;
    default:
        opposite_seat_type = "AS";
    }

    cout << opposite_seat_num << ' '
         << opposite_seat_type << '\n';
}
