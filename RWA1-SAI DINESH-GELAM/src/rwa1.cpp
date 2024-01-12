#include <iostream>
int main() // the program starts here

{
    int s;   // small boxes number
    int m;   // medium boxes number
    int l;   // large boxes number
    int n;   // total items
    int max; // maximum items can be kept in all boxes
    int rem; // remainder
    int occupied_small{0}, occupied_medium{0}, occupied_large{0}, remainder_small, remainder_medium, remainder_large, max_iterations, i{0};

    // do execute the cout and cin statements once atleast and checks wheather the entered boxes numbers are positive
    do
    {
        // putting values of boxes numbers of small, medium and large in s, m,l respectively
        std::cout << "Enter how many boxes are available for SMALL <space> MEDIUM <space> LARGE\n";
        std::cin >> s >> m >> l;

        if (s < 0 || m < 0 || l < 0)
        {
            std::cout << "please enter positive numbers for boxes \nenter how many boxes are available for small <space> medium <space> large\n";
            std::cin >> s >> m >> l;
        }

    } while (s < 0 || m < 0 || l < 0); // do untill all the entered boxes numbers are positive

    std::cout << "-----------------------------------------------------------------------------------------\n";

    // do execute the cout and cin statements once atleast and checks wheather the entered items number is positive
    do
    {
        std::cout << "enter number of items avilable\n";
        std::cin >> n; // put items number in n

        if (n < 0)
        {
            std::cout << "please enter positive numbers for items\nenter number of items avilable\n";
            std::cin >> n;
        }

    } while (n < 0); // do untill the item number is positive

    std::cout << "******************************************************************************************\n";

    // if the entered value is too bigger than the available boxes to save compiling time we just allocate the maximum possible case and directly print the combination

    max = (s * 7 + m * 12 + l * 25);

    if (n > max)
    {
        std::cout << max << " items are placed in " << s << " small boxes    " << m << " medium boxes   " << l << " large boxes\n";
        rem = n - max;
        std::cout << "remaining items are " << rem;
    }

    else
    {

        max_iterations = n / 7; // maximum number of iterations will be items divided by least size of the box

        while (i <= max_iterations) // run this loop untill the max possible iterations
        {

            remainder_small = n % 7;   // remainder by divided by 7
            remainder_medium = n % 12; // remainder by divided by 12
            remainder_large = n % 25;  // remainder by divided by 25
            // if particular boxes are all occupied remainder regarding that box becomes maximum-25 so that it is true in all the further cases
            if (occupied_small >= s)
                remainder_small = 25;

            if (occupied_medium >= m)
                remainder_medium = 25;

            if (occupied_large >= l)
                remainder_large = 25;

            // if a number exactly divisible by one of the box number and there are no enough available number of such kind of box remainder is upgraded to maximum value to avoid filng those boxes
            if (n % 25 == 0 && l * 25 < n)
            {
                remainder_large = 25;
            }

            if (n % 12 == 0 && m * 12 < n)
            {
                remainder_medium = 25;
            }

            if (n % 7 == 0 && s * 7 < n)
            {
                remainder_small = 25;
            }

            // the items will be filled in the box with least remainder first and further next

            if (remainder_large <= remainder_medium && remainder_large <= remainder_small && occupied_large < l && n >= 25)
            {
                n = n - 25;       // filoccupied_largeng the box
                occupied_large++; // incrementing the number of boxes occupied
            }

            if (remainder_medium <= remainder_small && remainder_medium <= remainder_large && occupied_medium < m && n >= 12)
            {
                n = n - 12;
                occupied_medium++;
            }

            if (remainder_small <= remainder_large && remainder_small <= remainder_medium && occupied_small < s && n >= 7)
            {

                n = n - 7;
                occupied_small++;
            }

            i++;
        }
        // print the items placement and remaining items
        std::cout << (occupied_small * 7 + occupied_medium * 12 + occupied_large * 25) << " items are placed in " << occupied_small << " small boxes    " << occupied_medium << " medium boxes   " << occupied_large << " large boxes\n";
        std::cout << "remaining items are " << n << "\n";
        std::cout << "******************************************************************************************\n";
    }
}