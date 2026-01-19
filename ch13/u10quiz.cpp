#include <iostream>

struct Ad
{
    int numWatched{ };
    float percentClicked{ };
    double avgEarnings{ };
};

void setupAd(Ad& ad)
{
    std::cout << "How many ads were watched: ";
    std::cin >> ad.numWatched;
    std::cout << "What percentage of users clicked on an ad: ";
    std::cin >> ad.percentClicked;
    std::cout << "What was the average earnings per clicked ad: ";
    std::cin >> ad.avgEarnings;
}

void printAdRevenue(const Ad& ad)
{
    std::cout << ad.numWatched << " ads were watched\n";
    std::cout << ad.percentClicked << "% of users clicked on an ad.\n";
    std::cout << "$" << ad.avgEarnings << " was made per clicked ad.\n";
    std::cout << "Total daily profit was $"
        << ad.numWatched * 0.01 * ad.percentClicked * ad.avgEarnings << '\n';
}

int main()
{
    Ad ad{ };
    setupAd(ad);

    std::cout << '\n';

    printAdRevenue(ad);

    return 0;
}
