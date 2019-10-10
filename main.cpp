#include "resources.h"
    for(int i = 0; i < 60; ++i) {
        // sample_space: bull: 1/4, bear: 1/4, neutral: 1/2
        switch(market(event)) {
            case(stock_market::bull): //stock prices up, look to sell
                stock_increase();
                if( stock_price > 115 && shares_owned > 0 )
                    sell_stock();
                break;
            case(stock_market::bear): //stock prices down, look to buy
                stock_decrease();
                if( stock_price < 95 && money > 0 )
                    buy_stock();
                break;
            default: // No change in stock prices
                break;
        }
        accumulate_interest();
        std::cout <<i+1<<"\t\t\t"<< money <<"\t\t\t  "<< shares_owned <<"\t\t\t  "<< stock_price << "\n";
    }
    return 0;
}
