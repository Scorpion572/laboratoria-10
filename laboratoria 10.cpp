//################################### Lab 10 code ###################################

#include <iostream>
#include <stdio.h>
using namespace std;

void insertNode(int key, string data);
void displayList();

struct Node { //kod 10_01
    int key = -1;
    string data = "";
    Node* next = nullptr;
};

Node* head = nullptr; //globalny wskaznik zawsze pokazujacy pierszy wezel
Node* lastAded = nullptr;
void insertNode(int key, string data) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode; //jak nic nie ma, stworzy pierszy wezel
		lastAded = newNode;
    }
    else {
        lastAded->next = newNode;
		lastAded = newNode;
    }
}
    
void displayList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Key: " << temp->key << ", Data: " << temp->data << endl;
        temp = temp->next;
    }
}

void wyswielmenu() {
	cout << "Menu:" << endl;
	cout << "1. Dodaj nowy element" << endl;
	cout << "2. Usun element" << endl;
    cout << "3. Wyswietl liste" << endl;
	cout << "9. Zakoncz program" << endl;
}

int main() {
    bool aktywny = true;
    int key;
    string data;
    while (aktywny == true) {
        system("cls");
        wyswielmenu();
        char wybor;
        cout << "Wybierz opcje: ";
        cin >> wybor;
        switch (wybor) {
        case '1':
            cout << "Enter key and data for node " << endl;
            cout << "Please write integer number: ";
            cin >> key;
            cout << "Please write any string: ";
            cin >> data;
            insertNode(key, data);
            break;
        case '2':

            break;
        case '3':
            cout << "The entire list:" << endl;
            displayList();
            system("pause");
		case '9':
			cout << "wylaczanie programu..." << endl;
			aktywny = false;
            break;
        }



        /*for (int i = 0; i < n; i++) {
            cout << "Enter key and data for node " << i + 1 << ": " << endl;
            cout << "Please write integer number: ";
            cin >> key;
            cout << "Please write any string: ";
            cin >> data;
            insertNode(key, data);
        }

        cout << "The entire list:" << endl;
        displayList();*/
    }
}
