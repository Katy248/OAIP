#include <iostream>
#include "exercise.h"

using std::cin;
using std::cout;
using std::endl;
static void get_input(u32 *passengers_count, u32 **items_by_passenger_count, double ***baggages, bool interactive);

int main(int argc, char **argv)
{
    bool interactive = argv[1] == "-i";
    u32 passengers_count;
    u32 *items_by_passenger_count;
    double **baggages;

    // get_input(&passengers_count, &items_by_passenger_count, &baggages, interactive);

    if (interactive)
        cout << "Enter passengers count: ";
    cin >> passengers_count;

    baggages = new double *[passengers_count];
    items_by_passenger_count = new u32[passengers_count];

    for (u32 i = 0; i < passengers_count; i++)
    {
        if (interactive)
            cout << "Enter " << i << "th passengers baggages count: ";
        cin >> items_by_passenger_count[i];
        baggages[i] = new double[items_by_passenger_count[i]];

        for (int j = 0; j < items_by_passenger_count[i]; j++)
        {
            if (interactive)
                cout << "Enter weight: ";
            cin >> baggages[i][j];
        }
    }

    /* 1st */
    double *all_weights = new double[passengers_count];
    cout << "All weights:" << endl;
    get_weight_by_passengers(passengers_count, &items_by_passenger_count, &baggages, &all_weights);
    for (int i = 0; i < passengers_count; i++)
    {
        cout << "\t" << all_weights[i] << endl;
    }

    /* 2nd */
    u32 index = get_index_of_passenger(passengers_count, &items_by_passenger_count, &baggages);
    cout << "Index is:\n"
         << "\t" << index << endl;

    /* 3rd */
    cout << "Passengers with more than 3 items in baggages\n"
         << "\t" << get_passengers_count_with_items_more_than(passengers_count, &items_by_passenger_count, &baggages, 3);
}

static void get_input(u32 *passengers_count, u32 **items_by_passenger_count, double ***baggages, bool interactive)
{
    if (interactive)
        cout << "Enter passengers count: ";
    cin >> *passengers_count;

    *baggages = new double *[*passengers_count];
    *items_by_passenger_count = new u32[*passengers_count];

    for (u32 i = 0; i < *passengers_count; i++)
    {
        if (interactive)
            cout << "Enter " << i << "th passengers baggages count: ";
        cin >> *items_by_passenger_count[i];
        *baggages[i] = new double[*items_by_passenger_count[i]];
        // double *bgs = new double[*items_by_passenger_count[i]];

        for (int j = 0; j < *items_by_passenger_count[i]; j++)
        {
            if (interactive)
                cout << "Enter weight: ";
            cin >> *baggages[i][j];
        }
        //*baggages[i] = bgs;
    }
}
