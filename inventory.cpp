#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
    int id;
    string name;
    float price;
    int qty;
};

vector<Product> inventory;
void addProduct() {
    Product p;

    cout << "\nEnter Product ID: ";
    cin >> p.id;

    cout << "Enter Product Name: ";
    cin >> p.name;

    cout << "Enter Price: ";
    cin >> p.price;

    cout << "Enter Quantity: ";
    cin >> p.qty;

    inventory.push_back(p);
    cout << "Product added successfully!\n";
}
void viewProducts() {
    if (inventory.empty()) {
        cout << "\nInventory is empty.\n";
        return;
    }

    cout << "\nID\tName\tPrice\tQty\n";
    cout << "\n";

    for (const auto &p : inventory) {
        cout << p.id << "\t"
             << p.name << "\t"
             << p.price << "\t"
             << p.qty << endl;
    }
}
void sellProduct() {
    int id, amt;
    bool found = false;

    cout << "\nEnter Product ID to sell: ";
    cin >> id;

    cout << "Enter Quantity to sell: ";
    cin >> amt;

    for (auto &p : inventory) {
        if (p.id == id) {
            found = true;

            if (p.qty >= amt) {
                p.qty -= amt;
                cout << "Sale successful!\n";
            } else {
                cout << "Not enough stock.\n";
            }
            break; 
        }
    }

    if (!found) {
        cout << "Product not found.\n";
    }
}
void showMenu() {
    cout << "\n====== Inventory Management ======\n";
    cout << "1. Add Product\n";
    cout << "2. View Products\n";
    cout << "3. Sell Product\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: sellProduct(); break;
            case 4: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}