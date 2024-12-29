#include <algorithm>
#include <string>
#include <vector>

struct Product {
  std::string name;
  int price;
};

std::vector<Product> products;

auto GetProducts() -> std::vector<Product> { return products; }
auto GetProductCount() -> int { return products.size(); }

auto AddProduct(std::string name, int price) -> std::string {
  if (name.empty() || price <= 0)
    return "Product name cannot be empty";

  if (std::find_if(products.begin(), products.end(), [&name](const Product &p) {
        return p.name == name;
      }) != products.end())
    return "Product already exists";

  products.push_back({name, price});
  return "Product added successfully";
}

auto RemoveProduct(std::string name) -> std::string {
  if (name.empty())
    return "Product name cannot be empty";

  auto it = std::find_if(products.begin(), products.end(),
                         [&name](const Product &p) { return p.name == name; });
  if (it != products.end()) {
    products.erase(it);
    return "Product removed successfully";
  } else
    return "Product not found";
}

auto UpdateProduct(std::string name, int newPrice) -> std::string {
  if (name.empty())
    return "Product name cannot be empty";

  auto it = std::find_if(products.begin(), products.end(),
                         [&name](const Product &p) { return p.name == name; });
  if (it != products.end()) {
    it->price = newPrice;
    return "Product updated successfully";
  } else
    return "Product not found";
}

auto SearchProduct(std::string name) -> std::string {
  if (name.empty())
    return "Product name cannot be empty";

  auto it = std::find_if(products.begin(), products.end(),
                         [&name](const Product &p) { return p.name == name; });
  if (it != products.end())
    return it->name + " - " + std::to_string(it->price);
  else
    return "Product not found";
}

auto ListProducts() -> std::string {
  if (products.empty())
    return "No products found";
  else {
    std::string list;
    for (const auto &p : products) {
      list += p.name + " - " + std::to_string(p.price) + "$" + "\n";
    }
    return list;
  }
}

auto ClearProducts() -> std::string {
  products.clear();
  return "Products cleared successfully";
}

auto DeleteProduct(std::string name) -> std::string {
  if (name.empty())
    return "Product name cannot be empty";

  std::transform(name.begin(), name.end(), name.begin(), ::tolower);

  auto it =
      std::find_if(products.begin(), products.end(), [&name](const Product &p) {
        std::string pNameLower = p.name;
        std::transform(pNameLower.begin(), pNameLower.end(), pNameLower.begin(),
                       ::tolower);
        return pNameLower == name;
      });
  if (it != products.end()) {
    products.erase(it);
    return "Product deleted successfully";
  } else
    return "Product not found";
}