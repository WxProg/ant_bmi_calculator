#include <iostream>                         // include standard I/O library
#include <iomanip>                          // include IO manipulators
#include <string>                          // include C++ string class
using namespace std;                        // access standard namespace

int main ()
{
    // named constants
    const int	 BASE = 66;                       // base value for player
    const double INCHES_TO_CENTIMETERS = 2.54;    // used to convert to Metric
    const double POUNDS_TO_KILOGRAMS = 0.4536;    // used to convert to Metric
    const double WEIGHT_MULTIPLIER = 13.7;   // used to multiply player's weight
    const double HEIGHT_MULTIPLIER = 5.0;    // used to multiply player's height
    const double AGE_MULTIPLIER = 6.8;       // used to multiply player's age

    // input values
    string  fullName;                     // name of player
    double  weightInPounds;               // weight of player
    double  heightInInches;               // height of player
    int     ageInYears;                   // age of player

    // calculated values
    double weightInKilograms;             // the player's data converted
    double heightInCentimeters;           // to Metric units
    double bmr;                           // calculated BMR for player

    // print the main output heading
    cout << "-------------------------------------" << endl;
    cout << "Welcome to the BMR Calculator Program" << endl;
    cout << "     Basal Metabolic Rate (Men)      " << endl;
    cout << "    Designed for Recreational Use    " << endl;
    cout << "-------------------------------------" << endl << endl;

    // ask the user to enter the player's full name, may contain blanks
    cout << "Please enter the player's full name -> ";
    getline(cin,fullName);

    // ask the user to type in the weight, height and age
    cout << endl << "Please enter the player's weight in pounds," << endl
         << "\tas a whole number or a real number -> ";
    cin >> weightInPounds;
    cout << endl << "Please enter the player's height in inches, " << endl
         << "\tas a whole number or a real number -> ";
    cin >> heightInInches;
    cout << endl << "Please enter the player's age, as a whole number -> ";
    cin >> ageInYears;

    // convert English units to Metric units
    weightInKilograms = weightInPounds * POUNDS_TO_KILOGRAMS;
    heightInCentimeters = heightInInches * INCHES_TO_CENTIMETERS;

    // calculate the player's BMR
    bmr = BASE + (WEIGHT_MULTIPLIER * weightInKilograms)
          + (HEIGHT_MULTIPLIER * heightInCentimeters)
          - (AGE_MULTIPLIER * ageInYears);

    // print the final results
    cout << fixed << showpoint << setprecision(3);
    cout << endl << "Calculated Results" << endl;
    cout << "===============" << endl;
    cout << endl << "For player: " << fullName << endl;
    cout << "  Calculated BMR is: " << bmr << endl;

    // print closing message and signal normal termination
    cout << endl <<  "--------------------------------------";
    cout << endl << "Program Completed." << endl;
    cout <<  "--------------------------------------" << endl << endl;

    return (0);
}

/* ========================================================================== */
/*                   E N D    O F    P R O G R A M                            */
/* ========================================================================== */
