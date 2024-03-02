#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    bool interactive = argv[1] == "-i";
    if (!interactive)
        cout << "[INFO] NON_INTERACTIVE" << endl;

    int baggage_count;

    if (interactive)
        cout << "Enter baggages count: ";
    cin >> baggage_count;

    double **baggages = new double *[baggage_count];
    double *weight_by_passenger = new double[baggage_count];
    int *items_by_passenger = new int[baggage_count];
    int more_than_3_count = 0;

    for (int i = 0; i < baggage_count; i++)
    {

        baggages[i] = new double[items_by_passenger[i]];

        if (interactive)
            cout << "Enter " << i << "th passengers baggages count: ";
        cin >> items_by_passenger[i];

        if (items_by_passenger[i] > 3)
        {
            more_than_3_count++;
        }

        weight_by_passenger[i] = 0;
        for (int j = 0; j < items_by_passenger[i]; j++)
        {
            if (interactive)
                cout << "Enter weight: ";
            cin >> baggages[i][j];

            weight_by_passenger[i] += baggages[i][j];
        }
    }
    /* 1st */
    cout << "All weights:" << endl;
    for (int i = 0; i < baggage_count; i++)
    {
        cout << "\t" << weight_by_passenger[i] << endl;
    }

    /* 2nd */
    int all_items_count = 0;
    double all_weight = 0;
    for (int i = 0; i < baggage_count; i++)
    {
        all_items_count += items_by_passenger[i];
        all_weight += weight_by_passenger[i];
    }

    double average_weight = all_weight / all_items_count;

    for (int i = 0; i < baggage_count; i++)
    {
        if (weight_by_passenger[i] / items_by_passenger[i] - average_weight <= 0.3)
        {
            cout << "Baggage #" << i << ": baggage avg: " << weight_by_passenger[i] / items_by_passenger[i] << "; all avg: " << average_weight << endl;
            break;
        }
    }

    /* 3rd */
    cout << "Passengers with more than 3 items in baggages\n"
         << "\t" << more_than_3_count;
}
