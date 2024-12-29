#include <iomanip>
#include <iostream>
#include <string>
#include <vector> // Added to avoid compilation errors

#include "utils/Products.cpp"

void WelcomeMessage() {
    system("cls");
    system("color a");
    const int width = 100;
    std::cout << std::setw(50) << std::string(width, '=') << std::endl;
    std::cout << std::setw(50) << "     Products Manager     " << std::endl;
    std::cout << std::setw(50) << std::string(width, '=') << std::endl;
    std::vector<std::string> options = {
        "Add product", "Remove product", "Update product", "Search product",
        "List products", "Get product count", "Clear products", "Delete product"};

    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << std::setw(30) << (i + 1) << ". " << options[i] << std::endl;
    }

    std::cout << std::setw(30) << std::string(width, '=') << std::endl;
}

auto useCode(int code) -> std::string {
    std::string product;
    int price;
    switch (code) {
    case 1:
        std::cout << "Enter product name: ";
        std::cin >> product;
        std::cout << "Enter product price: ";
        std::cin >> price;
        return AddProduct(product, price);
    case 2: 
        std::cout << "Enter product name to remove: ";
        std::cin >> product;
        return RemoveProduct(product);
    case 3: 
        std::cout << "Enter product name to update: ";
        std::cin >> product;
        std::cout << "Enter new product price: ";
        std::cin >> price;
        return UpdateProduct(product, price);
    case 4:
        std::cout << "Enter product name to search: ";
        std::cin >> product;
        return SearchProduct(product);
    case 5:
        return ListProducts();
    case 6: 
        return std::to_string(GetProductCount());
    case 7: 
        return ClearProducts();
    case 8: 
        std::cout << "Enter product name to delete: ";
        std::cin >> product;
        return DeleteProduct(product);
    default:
        return "Invalid option";
    }
}

int main() {
    WelcomeMessage();
    auto choose = 0;
    std::cout << "Choose an option [1-8]: ";
    std::cin >> choose;

    std::vector<int> validOptions = {1, 2, 3, 4, 5, 6, 7, 8};
    if (std::find(validOptions.begin(), validOptions.end(), choose) == validOptions.end()) {
        std::cout << "Invalid option" << std::endl;
    } else {
        std::cout << "Option selected: " << choose << std::endl;
        std::cout << useCode(choose) << std::endl;
    }

    std::string continueChoice = "y";
    while (continueChoice == "y" || continueChoice == "Y") {
        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> continueChoice;
        if (continueChoice == "y" || continueChoice == "Y") {
            main();
        }
    }

    std::cout << "Exiting..." << std::endl;
    system("pause");
    return 0;
}