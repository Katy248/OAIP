#include <iostream>
#include "exercise.h"

void get_weight_by_passengers(u32 passengers_count, u32 **items_by_passenger_count, double ***baggages, double **result)
{
    *result = new double[passengers_count];
    double *res = new double[passengers_count];
    for (u32 i = 0; i < passengers_count; i++)
    {
        res[i] = (double)0;

        std::cout << "Here first" << i << std::endl;
    }
    for (u32 i = 0; i < passengers_count; i++)
    {
        std::cout << "Here " << std::endl;
        for (u32 j = 0; j < *items_by_passenger_count[i]; j++)
        {
            std::cout << "Here " << i << " " << j << std::endl;
            // std::cout << "Here " << sizeof(baggages) / sizeof(double) << std::endl;
            // std::cout << "Here " << *baggages[i] << std::endl;
            res[i] += *baggages[i][j];
        }
    }
}

u32 get_index_of_passenger(u32 passengers_count, u32 **items_by_passenger_count, double ***baggages)
{
    int all_items_count = 0;
    double all_weight = 0;
    // std::cout << "Here " << std::endl;
    double *weight_by_passenger = new double[passengers_count];
    for (int i = 0; i < passengers_count; i++)
    {
        weight_by_passenger[i] = 0;
        all_items_count += *items_by_passenger_count[i];
        for (u32 j = 0; j < *items_by_passenger_count[i]; j++)
        {
            weight_by_passenger[i] += *baggages[i][j];
            all_weight += *baggages[i][j];
        }
    }

    double average_weight = all_weight / all_items_count;

    for (u32 i = 0; i < passengers_count; i++)
    {
        if (weight_by_passenger[i] / *items_by_passenger_count[i] - average_weight <= 0.3)
        {
            return i;
        }
    }
    return -1;
}

u32 get_passengers_count_with_items_more_than(u32 passengers_count, u32 **items_by_passenger_count, double ***baggages, u32 value)
{
    u32 counter = 0;
    for (int i = 0; i < passengers_count; i++)
    {
        if (*items_by_passenger_count[i] > value)
        {
            counter++;
        }
    }
    return counter;
}
