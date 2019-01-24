/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     LAB6 -
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
*********************************************************************/

#include "menu.hpp"

/*********************************************************************
** Description:     main menu
*********************************************************************/
void Menu::menuStart() {
    cout << "\n WELCOME TO MY LINKED LIST!\n"
            "+--------------------------------------------------+\n";
    cout << "   Choose from the following Options:\n";
    cout << "   1. Add a new node to the head\n";
    cout << "   2. Add a new node to the tail\n";
    cout << "   3. Delete from head\n";
    cout << "   4. Delete from tail\n";
    cout << "   5. Traverse the list reversely\n";
    cout << "   6. Exit\n";
    cout << "   >> ";
}



/*********************************************************************
** Description:     tells user the program has ended
*********************************************************************/
void Menu::menuExit() {
    cout << " Program has ended\n"
            "+--------------------------------------------------+\n";
}

/*********************************************************************
** Description:     tells user the program has ended
*********************************************************************/
void Menu::menuAddNodeHead() {
    cout << "\n Enter an integer to add to the head of the list\n"
            "+--------------------------------------------------+\n";
    cout << ">> ";
}




/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Menu::validateNumber(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (int i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
        }

        // check if characters entered are within range
        notInRange = false;
        if (!isNotDigit && !tooLong) {
            convert.clear();
            convert << choice;
            convert >> validatedChoice;

            if (validatedChoice < min || validatedChoice > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return validatedChoice;
}