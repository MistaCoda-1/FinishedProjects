#include<iostream>
#include<string>
using namespace std;

class Product {
    // Privated variables can only be accessed/modified by methods inside its own class.
    // Naka private para di magalaw ng ibang functions ung values ng object/product.
    private:
        string prodName;
        string prodCategory;
        string prodBrand;
        int prodId;
    public:
        // This is what's called an empty constructor.
        // Ginagamit to para pag gumawa ng variable ung user at walang parameters, 
        // naka blank ung values ng variables mo at hindi random values.
        Product() {
            prodName = "";
            prodCategory = "";
            prodBrand = "";
            prodId = 0;
        }
        // Parameterized constructor
        // This is used to create objects quickly.
        // Ex: `Product prod(name, category, brand, id);`

        // Sa mga nag tanong kanina na paano na na change ung values ng variables kahit
        // iba ung naka lagay na `variable name` sa parameter.

        /*
        Constructor v
        Product(string n, string c, string b, int id) {
            prodName = n;
            prodCategory = c;
            prodBrand = b;
            prodId = id;
        }
        
        Calling the constructor v
        Product prod(name, category, brand, id);

        This means `prod(name, category, brand, id);`
        is basically:
        
        Product (name, category, brand, id) {
            prodName = name;
            prodCategory = category;
            prodBrand = brand;
            prodId = id;
        }

        Sana gets.
        */
        
        Product(string n, string c, string b, int id) {
            prodName = n;
            prodCategory = c;
            prodBrand = b;
            prodId = id;
        }

        // Method
        // This method/function inside the class is used to display
        // the specific object's information.

        // See how it calls `prodName`, `prodCategory`, etc.. inside the class.
        // Since those values are inside the scope of the class, it can be accessed,
        // and can be displayed.

        // So when you call `prod.displayInfo();`
        // displays all the thing you `cout`'d

        void displayInfo() {
            cout << "Product Name: " << prodName << endl
                 << "Product Category: " << prodCategory << endl
                 << "Product Brand: " << prodBrand << endl
                 << "Product ID: " << prodId;
        }
};

int main () {
    // These are the variables we input into, to then use in the constructor function.
    string name, category, brand;

    // `prodNo` is for the index/for loop.
    // `id` is for the constructor again.
    int prodNo, id;

    cout << "Lab #1 | Inventory Manager |\n\n";

    // User inputs a name into `prodNo`
    cout << "Enter number of products: ";
    cin >> prodNo;

    cout << "\n+ - - - - - - - - +\n";
    for (int i = 0; i < prodNo; i++) {
        cout << "Product #" << i + 1 << ":\n\n";

        // User inputs a name into `name`
        cout << "Enter Product Name: ";
        cin >> name;

        // User inputs into `category`
        cout << "Enter Product Category: ";
        cin >> category;

        // User inputs into `brand`
        cout << "Enter Product Brand: ";
        cin >> brand;

        // User inputs into `id`
        cout << "Enter Product ID: ";
        cin >> id;

        cout << "+ - - - - - - - - +\n";
        Product prod(name, category, brand, id);    // Parameterized Constructor

        cout << "Product #" << i + 1 << " Information:\n\n";
        prod.displayInfo(); // Display method in `class Product {...};`
        cout << "\n+ - - - - - - - - +\n";
    }

    return 0;
}