#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Data {
    string name, address, disease, gender, description;
    int specialRoomNo, age;
};


struct Node {

    Data data;
    Node* next;
};


Node* insertFront(Node* head, Data data)
{
    Node* temp = new Node;
    temp->data = data;

    temp->next = head;
    head = temp;
    return head;

}//end of insertFront Function

//============================================

Node* append(Node* head, Data data) {

    Node* temp = new Node;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return head;
    }

    Node* last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp;

    clog << "Append completed" << endl;

    return head;

}//end of append function


//========================================


void changeNode(Node* head, Data data, Data newData)
{
    while (head != NULL)
    {
        if (head->data.name == data.name)
        {
            head->data = newData;
            break;
        }

        head = head->next;
    }
}//end of changeNode function


void changeNode(Node* head, string data, string newData)
{
    while (head != NULL)
    {
        if (head->data.name == data)
        {
            head->data.name = newData;
            break;
        }

        head = head->next;
    }
}//end of changeNode function



//=======================================


void printLinkedList(Node* head)
{
    if (head == NULL)
    {
        cout << "\n\nThere is no record \n\n" << endl;
        return;
    }

    while (head->next != NULL)
    {
        cout << "Name: " << head->data.name << ", Address: " << head->data.address
            << ", Gender: " << head->data.gender << ", Disease: " << head->data.disease
            << ", Description: " << head->data.description << ", Age: " << head->data.age
            << ", Specialist No: " << head->data.specialRoomNo << endl;
        head = head->next;
    }
    cout << "Name: " << head->data.name << ", Address: " << head->data.address
        << ", Gender: " << head->data.gender << ", Disease: " << head->data.disease
        << ", Description: " << head->data.description << ", Age: " << head->data.age
        << ", Specialist No: " << head->data.specialRoomNo << endl;

}//end of printLinkedList function


//========================================



int listLength(Node* head) {
    int temp = 0;

    if (head == NULL)
    {
        cout << "\n\nNo record found \n\n" << endl;
        return 0;
    }

    while (head->next != NULL)
    {
        ++temp;
        head = head->next;
    }

    return temp + 1;
}//end of the listLength function

//============================================


void delElement(Node* head, int loc)
{
    Node* temp = new Node;

    temp = head;

    if (head == NULL) {

        cout << "\n\nNo record found\n\n" << endl;
        return;
    }


    for (int i = 1; i <= loc; ++i)
    {
        temp = temp->next;
        if (i < loc) {
            head = head->next;
        }//end of if statement

    }//end of for statement

    head->next = temp->next;

}//end of delElement function

//===========================================


Node* searchList(Node* head, Data v) {

    if (head == NULL)
    {
        cout << "\n\nThere is not record for search result\n\n" << endl;
        return NULL;
    }

    int l = 1;

    while (head->next != NULL && head->data.name != v.name)
    {
        head = head->next;
        ++l;
    }

    cout << "\n\nPatient found at location   " << l << endl;

    return head;

}//end of searchList function




//==============================================



Node* searchList(Node* head, string v) {

    if (head == NULL)
    {
        cout << "\n\nThere is not record for search patient\n\n" << endl;
        return NULL;
    }

    int l = 1;

    while (head->next != NULL && head->data.name != v)
    {
        head = head->next;
        ++l;
    }

    cout << "\n\nPatient found at location  \n\n" << l << endl;

    return head;

}//end of searchList function




//=======================================================================


Data inputPatients()
{
    string name, address, disease, gender, description;
    int specialRoomNo, age;
    Data p;

    cout << "Enter Patient Name: ";
    cin.ignore();//clearing buffer
    getline(cin, name);

    cout << "Enter Patient Address: ";
    getline(cin, address);

    cout << "Enter Patient Disease: ";
    getline(cin, disease);

    cout << "Enter Patient Gender: ";
    getline(cin, gender);

    cout << "Enter Disease Description: ";
    getline(cin, description);

    cout << "Enter Patient Special Room No.: ";
    cin >> specialRoomNo;

    cout << "Enter Patient Age: ";
    cin >> age;

    p.name = name;
    p.address = address;
    p.gender = gender;
    p.description = description;
    p.specialRoomNo = specialRoomNo;
    p.age = age;

    clog << "Completed input operation" << endl;

    return p;

}//end of inputPatients function

//============================================================================



    


int main()
{
     cout<<"\n\n           Hospital Management System            \n\n";
    cout<<"         ...............................        \n\n";
    Node* head = NULL;
    Data patient;
    string nameToSearch;
    string oldName, newName;

    int op;

    cout <<  "\nZ..To exit\n\n1..Add New Patient\n\n2..Delete Patient Details \n\n3..Search Patient by Name\n\n4..List of admited Patient"
        << "\n\n5..Print Patient List\n\n6..Modify Patient Name\n\n7..Insert new Patient at 1st Position" << endl;
    while (cin >> op)
    {

        switch (op) {
        case 1:
            cout << "\n\nEnter Patient Details Below\n\n" << endl;
            patient = inputPatients();
            head = append(head, patient);
            break;

        case 2:

            if (listLength(head) < 2)
            {
                cout << "\n\nLength is less then two.\nTerminating program\n\n" << endl;
                exit(1);
            }
            else {
                cout << "\n\nEnter location where you want to delete a patient, at least three patients must be in list? \n\n";
                int l;
                cin >> l;
                delElement(head, l - 1);
            }//end of else of case 2
            break;

        case 3:
            cout << "\n\nEnter name to search patient: \n\n";
            cin.ignore();
            getline(cin, nameToSearch);
            searchList(head, nameToSearch);
            break;

        case 4:

            cout << "\n\nYou have " << listLength(head) << " Patients in your Hospital.\n\n" << endl;

            break;

        case 5:
            printLinkedList(head);
            break;

        case 6:
            cin.ignore();
            cout << "Enter old name ";
            getline(cin, oldName);
            cout << "Enter New Name ";
            getline(cin, newName);

            changeNode(head, oldName, newName);
            break;

        case 7:
            patient = inputPatients();
            head = insertFront(head, patient);
            break;

        default:
            cout << "\n\nWrong option Selected\n\n" << endl;
        }

        cout <<  "\n\nZ..To exit\n1..Add New Patient\n\n2..Delete Patient Details \n\n3..Search Patient by Name\n\n4..List of admited Patient"
        << "\n\n5..Print Patient List\n\n6..Modify Patient Name\n\n7..Insert new Patient at front" << endl;
    }

}