/*
Problem 1
Jasmine Rodriguez, Edwin Rodriguez, Amanda Shohdy
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std; 


int main()
{
    vector<vector<double>> p_1{
                        //{7.0, 8.30}, 
                        {12.0, 13.0},
                        {16.0, 18.0}
    };

    vector<double> p_1_daily_act{9.0, 19.0};

    vector<vector<double>> p_2{
                        {9.0, 10.30}, 
                        {12.20, 13.30},
                        {14.0, 15.0},
                        {16.0, 17.0}
    };

    vector<double> p_2_daily_act{9.0, 18.3};

    int duration = 30;
    
    
    // condense the daily act for both people into one list 
    vector<double> daily_act{0, 0};
    if(p_1_daily_act[0] > p_2_daily_act[0])
    {
        daily_act[0] = p_1_daily_act[0];
    }
    else
    {
        daily_act[0] = p_2_daily_act[0];
    }
    if(p_1_daily_act[1] > p_2_daily_act[1])
    {
        daily_act[1] = p_2_daily_act[1];
    }
    else
    {
        daily_act[1] = p_1_daily_act[1];
    }

    //creating an empty list 
    vector<vector<double>> my_list;

    for (int i = 0; i < p_1.size(); ++i)
    {
        // check if person's one schedule is greater than person's two schedule
        if(p_1[i][0] < p_2[i][0])
        {
            // initializes j and best_time
            int j = i;
            double best_time = 0.0;
            // person's two schedule will go through a while loop 
            // and it will break until person's one schedule is greater than person's two schedule
            while(p_1[i][1] < p_2[j][0])
            {
                if(p_1[i][1] < p_2[j][0])
                {
                    best_time = p_2[j][0];
                }
                ++j;
            }
            my_list.push_back({p_1[i][1], best_time});
        }
        // check if person's one schedule is greater than person's two schedule 
        else if(p_1[i][0] > p_2[i][0])
        {
            // initializes j and best_time
            int j = i;
            double best_time = 0.0;
            //in this while loop, the loop will continue until person's one schedule is less than person's two schedule
            while(p_1[i][0] > p_2[j][1])
            {
                if(p_1[i][0] > p_2[j][1])
                {
                    best_time = p_2[j][1];
                }
                ++j;
            }
            my_list.push_back({best_time, p_1[i][0]});
        }
        // this checks the 2nd position in both person's schedule's list 
        if(p_1[i][1] > p_2[i][1])
        {
            // initializes j and best_time
            int j = i; 
            int best_time = 0;

            while(j < p_2.size())
            {
                if(p_1[i][1] < p_2[j][1])
                {
                    best_time = j;
                }
                ++j;
            }
            if(p_1[i][1] > p_2[best_time][1])
            {
                my_list.push_back({p_1[i][1], p_2[best_time][0]});
            }
        }
    }
    // checks if the last number in the list contains a number that is less than the number in the 0 position
    // if there is a number that is less than the number in the 0 position, then switch it with the daily_act's last number 
    if(my_list[my_list.size()-1][0] > my_list[my_list.size()-1][1])
    {
        my_list[my_list.size()-1][1] = daily_act[1];
    }

    for (int k = 0; k < my_list.size(); k++)
    {
        cout << my_list[k][0]<< " " << my_list[k][1] << endl;
    }

    return 0;
}