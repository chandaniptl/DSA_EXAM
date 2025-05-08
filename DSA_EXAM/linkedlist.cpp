#include <iostream>
#include <vector>
using namespace std;

class LinkedList
{
public:
    vector<int> data;

    void create(int value)
    {
        data.push_back(value);
    }

    void read()
    {
        for (int value : data)
        {
            cout << value << " ";
            cout << endl;
        }
    }

    void update(int oldValue, int newValue)
    {
        for (int &val : data)
        {
            if (val == oldValue)
            {
                val = newValue;
                cout << "Value updated." << endl;
                return;
            }
        }
        cout << "Value not found." << endl;
    }

    void Delete(int Value)
    {
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (*it == Value)
            {
                data.erase(it);
                cout << "Value deleted" << endl;
                return;
            }
        }
        cout << "data not found!" << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, value, NValue;

    do
    {
        cout<<endl;
        cout << "*** MENU ***" << endl;
        cout << "1. Insert Value" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Update Value" << endl;
        cout << "4. Delete Value" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.create(value);
            break;

        case 2:
            cout << "Current List: ";
            list.read();
            break;

        case 3:
            cout << "Enter old value to update: ";
            cin >> value;
            cout << "Enter new value: ";
            cin >> NValue;
            list.update(value, NValue);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.Delete(value);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}