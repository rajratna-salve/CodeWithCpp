#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class Stock
{
    int id, qty;
    string name, category, supplier;
    float price;

public:
    void accept()
    {
        cout << "\nID: ";
		cin >> id;
        cout << "Name: "; 
		cin >> name;
        cout << "Category: "; 
		cin >> category;
        cout << "Price: "; 
		cin >> price;
        cout << "Quantity: "; 
		cin >> qty;
        cout << "Supplier: "; 
		cin >> supplier;
    }

    void display()
    {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nCategory: " << category
             << "\nPrice: " << price
             << "\nQuantity: " << qty
             << "\nSupplier: " << supplier << "\n";
    }

    int getId() { return id; }

    void update()
    {
        cout << "Name: "; cin >> name;
        cout << "Category: "; cin >> category;
        cout << "Price: "; cin >> price;
        cout << "Quantity: "; cin >> qty;
        cout << "Supplier: "; cin >> supplier;
    }

    void purchase()
    {
        int n;
        cout << "Purchase Quantity: ";
        cin >> n;
        qty += n;
    }

    bool sell()
    {
        int n;
        cout << "Sell Quantity: ";
        cin >> n;

        if (n > qty)
            return false;

        qty -= n;
        return true;
    }

    float value()
    {
        return price * qty;
    }
};

void add()
{
    Stock s;
    ofstream f("stock.txt", ios::app);
    s.accept();
    f.write((char*)&s, sizeof(s));
    cout << "\nProduct added.";
}

void display()
{
    Stock s;
    ifstream f("stock.txt");

    while (f.read((char*)&s, sizeof(s)))
        s.display();
}

void search()
{
    Stock s;
    int id;
    bool found = false;

    cout << "\nEnter ID: ";
    cin >> id;

    ifstream f("stock.txt");

    while (f.read((char*)&s, sizeof(s)))
    {
        if (s.getId() == id)
        {
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nProduct not found.";
}

void update()
{
    Stock s;
    int id;
    bool found = false;

    cout << "\nEnter ID: ";
    cin >> id;

    ifstream f("stock.txt");
    ofstream t("temp.txt");

    while (f.read((char*)&s, sizeof(s)))
    {
        if (s.getId() == id)
        {
            s.update();
            found = true;
        }
        t.write((char*)&s, sizeof(s));
    }

    f.close();
    t.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    cout << (found ? "\nProduct updated." : "\nProduct not found.");
}

void removeProduct()
{
    Stock s;
    int id;
    bool found = false;

    cout << "\nEnter ID: ";
    cin >> id;

    ifstream f("stock.txt");
    ofstream t("temp.txt");

    while (f.read((char*)&s, sizeof(s)))
    {
        if (s.getId() == id)
            found = true;
        else
            t.write((char*)&s, sizeof(s));
    }

    f.close();
    t.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    cout << (found ? "\nProduct deleted." : "\nProduct not found.");
}

void purchase()
{
    Stock s;
    int id;
    bool found = false;

    cout << "\nEnter ID: ";
    cin >> id;

    ifstream f("stock.txt");
    ofstream t("temp.txt");

    while (f.read((char*)&s, sizeof(s)))
    {
        if (s.getId() == id)
        {
            s.purchase();
            found = true;
            cout << "Stock purchased.";
        }
        t.write((char*)&s, sizeof(s));
    }

    f.close();
    t.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (!found)
        cout << "Product not found.";
}

void sell()
{
    Stock s;
    int id;
    bool found = false;

    cout << "\nEnter ID: ";
    cin >> id;

    ifstream f("stock.txt");
    ofstream t("temp.txt");

    while (f.read((char*)&s, sizeof(s)))
    {
        if (s.getId() == id)
        {
            found = true;

            if (s.sell())
                cout << "Stock sold.";
            else
                cout << "Insufficient stock.";
        }

        t.write((char*)&s, sizeof(s));
    }

    f.close();
    t.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (!found)
        cout << "Product not found.";
}

void stockValue()
{
    Stock s;
    float total = 0;

    ifstream f("stock.txt");

    while (f.read((char*)&s, sizeof(s)))
        total += s.value();

    cout << "\nTotal Stock Value: " << total;
}

int main()
{
    int ch;

    do
    {
        cout << "\n\n1.Add  2.Display  3.Search  4.Update";
        cout << "\n5.Delete  6.Purchase  7.Sell  8.Stock Value  9.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1: add(); break;
        case 2: display(); break;
        case 3: search(); break;
        case 4: update(); break;
        case 5: removeProduct(); break;
        case 6: purchase(); break;
        case 7: sell(); break;
        case 8: stockValue(); break;
        case 9: cout << "\nThank you!"; break;
        default: cout << "\nInvalid choice.";
        }

    } while (ch != 9);

    return 0;
}