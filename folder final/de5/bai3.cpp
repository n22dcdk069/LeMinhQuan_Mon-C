#include <iostream>
#include <vector>
#include <string>

class Shop {
protected:
    int shopNumber;
    double area;
    static const double rentRate;

public:
    Shop(int number, double shopArea) : shopNumber(number), area(shopArea) {}

    virtual double calculateRent() const {
        return rentRate * area;
    }

    virtual double calculateTax() const = 0;

    virtual double calculateTotalPayment() const {
        return calculateRent() + calculateTax();
    }
};

const double Shop::rentRate = 40000000.0;

class FoodShop : public Shop {
private:
    double coldStorageFee;

public:
    FoodShop(int number, double shopArea, double coldStorageFee) : Shop(number, shopArea), coldStorageFee(coldStorageFee) {}

    double calculateTax() const override {
        return 0.05;
    }

    double calculateTotalPayment() const override {
        return calculateRent() + calculateRent() * calculateTax() + coldStorageFee;
    }
};

class ClothingShop : public Shop {
public:
    ClothingShop(int number, double shopArea) : Shop(number, shopArea) {}

    double calculateTax() const override {
        return 0.1;
    }
};

class JewelryShop : public Shop {
private:
    double revenue;

public:
    JewelryShop(int number, double shopArea, double revenue) : Shop(number, shopArea), revenue(revenue) {}

    double calculateTax() const override {
        if (revenue < 100000000) {
            return 0.2;
        } else {
            return 0.3;
        }
    }
};

int main() {
    std::vector<Shop*> shops;

    // Nhập thông tin sạp từ người dùng
    int shopNumber;
    double area, coldStorageFee, revenue;
    char shopType;

    std::cout << "Enter the number of shops: ";
    int numberOfShops;
    std::cin >> numberOfShops;

    for (int i = 0; i < numberOfShops; ++i) {
        std::cout << "Enter shop type (F for Food, C for Clothing, J for Jewelry): ";
        std::cin >> shopType;

        std::cout << "Enter shop number, area: ";
        std::cin >> shopNumber >> area;

        if (shopType == 'F') {
            std::cout << "Enter cold storage fee: ";
            std::cin >> coldStorageFee;
            shops.push_back(new FoodShop(shopNumber, area, coldStorageFee));
        } else if (shopType == 'C') {
            shops.push_back(new ClothingShop(shopNumber, area));
        } else if (shopType == 'J') {
            std::cout << "Enter annual revenue: ";
            std::cin >> revenue;
            shops.push_back(new JewelryShop(shopNumber, area, revenue));
        }
    }

    // Tính tổng số tiền phải đóng của tất cả các sạp
    double totalPayment = 0.0;
    for (const auto& shop : shops) {
        totalPayment += shop->calculateTotalPayment();
    }

    std::cout << "Total payment for all shops: " << totalPayment << " VND\n";

    // Giải phóng bộ nhớ
    for (auto& shop : shops) {
        delete shop;
    }

    return 0;
}
