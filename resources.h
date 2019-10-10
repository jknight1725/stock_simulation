#include <iostream>
#include <random>
#ifndef SIMULATION_RESOURCES_H
#define SIMULATION_RESOURCES_H
//RNG resources output -> int: 0 < x < 5
static std::random_device rd;
static std::mt19937 event(rd());
static std::uniform_int_distribution<int> market {1,4};
enum stock_market {bull=1, bear=2};

double money {1000};
double stock_price {100};
double shares_owned {0};
double const interest {0.005};
double const adjustment {.05};

//lambda functions to mutate money, shares_owned, and stock_price variables
auto stock_increase      = [](){ stock_price += stock_price * adjustment; };
auto stock_decrease      = [](){ stock_price -= stock_price * adjustment; };
auto accumulate_interest = [](){ money += money * interest; };
auto sell_stock = [](){
    money += shares_owned * stock_price;
    shares_owned = 0;
};
auto buy_stock = [](){
    shares_owned = money / stock_price;
    money = 0;
};
#endif //SIMULATION_RESOURCES_H
