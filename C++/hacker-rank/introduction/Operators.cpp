/*

Task
Given the meal price (base cost of a meal), tip percent (the percentage of the meal price being added as tip), 
and tax percent (the percentage of the meal price being added as tax) for a meal, find and print the meal's total cost.

There are  lines of numeric input:
The first line has a double, mealCost (the cost of the meal before tax and tip).
The second line has an integer, tipPercent (the percentage of mealCost being added as tip).
The third line has an integer, taxPercent (the percentage of mealCost being added as tax).

Print the total meal cost, where totalCost is the rounded integer result of the entire bill (mealCost with added tax and tip).
*/


#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
void solve(double meal_cost, int tip_percent, int tax_percent) {

    double tipCost = meal_cost * (double(tip_percent) / 100);
    double taxCost = meal_cost * (double(tax_percent) / 100);
    int totalCost = round(meal_cost + tipCost + taxCost);
    cout << totalCost << endl;
    
}

int main()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);


    return 0;
}

