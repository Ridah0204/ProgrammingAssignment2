#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//2 file streams
vector<string> readNames(string fileName) {
    vector<string> nameList;
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        string name;
        while (getline(inputFile, name)) {
            nameList.push_back(name);
        }
        inputFile.close();
    }
    else {
        cout << "Error: Could not open file " << fileName << endl;
    }
    return nameList;
}

//Return a Boolean value
bool searchForStringInVector(string name, vector<string> nameList) {
    for (int i = 0; i < nameList.size(); i++) {
        if (nameList[i] == name) {
            return 1;
        }
    }
    return 0;
}

void bubbleSort(vector<string>& nameList)
{
    int maxElement;
    int index;

    for (maxElement = nameList.size() - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (nameList[index] > nameList[index + 1])
            {
                swap(nameList[index], nameList[index + 1]);
            }
        }
    }
}



void display(vector<string> names) {
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << "\n";

    }
}

//Menu
void menu()
{
    cout << "\nChoose the Name List you want to display\n"
        << "1. Display sorted Girls' Names\n"
        << "2. Search for a girl name from the sorted list\n"
        << "3. Display sorted Boys' Names\n"
        << "4. Search for a boy name from the list\n"
        << "5. Quit\n";
}


int main() {

  
        //call read File (twice)
        vector<string> girlNameList = readNames("GirlNames.txt");
        vector<string> boyNameList = readNames("BoyNames.txt");

        int choice;     
        string boyName, girlName;
        bool again = true, test = true;


        if (again = true) {


            cout << "\nThese are the Girl's names: \n" << endl;
        
            display(girlNameList);

            cout << "\nThese are the Boy's names: \n" << endl;
        
            display(boyNameList);

            do {

                menu();
                cin >> choice;
                while (choice < 1 || choice > 5) {
                    menu();
                    cin >> choice;
                }

                test = searchForStringInVector;



                if (test == true) {

                    switch (choice) {
                    case 1:
                        bubbleSort(girlNameList);
                        display(girlNameList);
                        break;
                    case 2:
                        cout << "\nEnter a girl's name: ";
                        cin >> girlName;
                        if (searchForStringInVector(girlName, girlNameList)) {
                            cout << girlName << " is a popular girl's name." << endl;
                        }
                        else {
                            cout << girlName << " is not a popular girl's name." << endl;
                        }
                        break;
                    case 3:
                        bubbleSort(boyNameList);
                        display(boyNameList);
                        break;
                    case 4:
                        cout << "\nEnter a boy's name: ";
                        cin >> boyName;
                        if (searchForStringInVector(boyName, boyNameList)) {
                            cout << boyName << " is a popular boy's name." << endl;
                        }
                        else {
                            cout << boyName << " is not a popular boy's name." << endl;
                        }
                        break;
                    case 5:
                        cout << "End of Program!\n";
                        break;
                        break;

                    default: cout << "You entered an invalid operation";
                        break;


                    }

                }

            }

            while (choice != 5);

        }

        return 0;
    }

    

     
        


