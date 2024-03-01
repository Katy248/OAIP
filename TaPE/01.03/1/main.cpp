#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double **get_input(int[]);
double *get_full_weights(double **, int *);
double *get_baggage_with_average_differ_on(double **, double);
int get_passengers_count_with_more_than(double **, double);

int main()
{
    int *sizes;
    double **baggages = get_input(sizes);
    for (size_t i = 0; i < sizeof(sizes) / sizeof(int); i++)
    {
        cout << sizes[i] << endl;
    }
    

    /* 1 task */
    double *full_weights = get_full_weights(baggages, sizes);
    for (size_t i = 0; i < sizeof(full_weights) / sizeof(double); i++)
    {
        cout << i << "th passanger baggage weight = " << full_weights[i] << endl;
    }

    /* 2 task */
    // double *bgs = get_baggage_with_average_differ_on(baggages, 0.3);
    // for (size_t i = 0; i < sizeof(bgs) / sizeof(double); i++)
    // {
    //     cout << bgs[i] << endl;
    // }

    // /* 3 task */
    // cout << "Passengers with more than 3 things in baggage is " << get_passengers_count_with_more_than(baggages, 3);

    return 0;
}

double **get_input(int sizes[])
{
    int baggage_count;
    cout << "Enter baggages count: ";
    cin >> baggage_count;
    cout << endl;
    double **baggages = new double *[baggage_count];
    sizes = new int[baggage_count];

    for (int i = 0; i < baggage_count; i++)
    {
        int passenge_baggages_count;
        cout << "Enter " << i << "th passengers baggages count: ";
        cin >> passenge_baggages_count;
        cout << endl;
        baggages[i] = new double[passenge_baggages_count];
        sizes[i] = passenge_baggages_count;

        for (int j = 0; j < passenge_baggages_count; j++)
        {
            cout << "Enter weight: ";
            cin >> baggages[i][j];
            cout << endl;
        }
    }

    return baggages;
}
double *get_full_weights(double **baggages, int *sizes)
{
    unsigned int length = sizeof(sizes) / sizeof(int);
    
    double *weights = new double[length];
    for (size_t i = 0; i < length; i++)
    {
        double weight = 0;
        for (size_t j = 0; j < sizeof(baggages[i]) / sizeof(double); j++)
        {
            weight += baggages[i][j];
        }
        weights[i] = weight;
    }

    return weights;
}