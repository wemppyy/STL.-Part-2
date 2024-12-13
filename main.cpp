#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Car {
private:
    std::string name;
    int year;
    double engineSize;
    double price;

public:
    Car(std::string n, int y, double e, double p) : name(n), year(y), engineSize(e), price(p) {}

    std::string getName() const { return name; }
    int getYear() const { return year; }
    double getEngineSize() const { return engineSize; }
    double getPrice() const { return price; }

    void display() const {
        std::cout << "Name: " << name << ", Year: " << year << ", Engine Size: " << engineSize << "L, Price: $" << price << std::endl;
    }

    bool matchesName(const std::string& searchName) const {
        return name == searchName;
    }

    bool matchesYear(int searchYear) const {
        return year == searchYear;
    }

    bool matchesEngineSize(double searchEngineSize) const {
        return engineSize == searchEngineSize;
    }

    bool matchesPrice(double searchPrice) const {
        return price == searchPrice;
    }
};

class CarDealership {
private:
    std::vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void removeCar(const std::string& name) {
        auto it = std::remove_if(cars.begin(), cars.end(), [&name](const Car& car) {
            return car.getName() == name;
        });
        cars.erase(it, cars.end());
    }

    void displayCars() const {
        for (const auto& car : cars) {
            car.display();
        }
    }

    void sortByName() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.getName() < b.getName();
        });
    }

    void sortByYear() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.getYear() < b.getYear();
        });
    }

    void sortByPrice() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.getPrice() < b.getPrice();
        });
    }

    void searchByName(const std::string& name) const {
        for (const auto& car : cars) {
            if (car.matchesName(name)) {
                car.display();
            }
        }
    }

    void searchByYear(int year) const {
        for (const auto& car : cars) {
            if (car.matchesYear(year)) {
                car.display();
            }
        }
    }

    void searchByEngineSize(double engineSize) const {
        for (const auto& car : cars) {
            if (car.matchesEngineSize(engineSize)) {
                car.display();
            }
        }
    }

    void searchByPrice(double price) const {
        for (const auto& car : cars) {
            if (car.matchesPrice(price)) {
                car.display();
            }
        }
    }
};

int main() {
    CarDealership dealership;

    dealership.addCar(Car("Toyota Corolla", 2020, 1.8, 20000));
    dealership.addCar(Car("Honda Civic", 2022, 2.0, 22000));
    dealership.addCar(Car("Ford Mustang", 2021, 5.0, 35000));
    dealership.addCar(Car("Chevrolet Malibu", 2019, 1.5, 18000));

    std::cout << "All cars in the dealership:\n";
    dealership.displayCars();

    std::cout << "\nSorted by Name:\n";
    dealership.sortByName();
    dealership.displayCars();

    std::cout << "\nSorted by Year:\n";
    dealership.sortByYear();
    dealership.displayCars();

    std::cout << "\nSorted by Price:\n";
    dealership.sortByPrice();
    dealership.displayCars();

    std::cout << "\nSearching for cars from 2020:\n";
    dealership.searchByYear(2020);

    std::cout << "\nSearching for cars with engine size 2.0L:\n";
    dealership.searchByEngineSize(2.0);

    std::cout << "\nRemoving car 'Honda Civic' and displaying all cars:\n";
    dealership.removeCar("Honda Civic");
    dealership.displayCars();

    return 0;
}
