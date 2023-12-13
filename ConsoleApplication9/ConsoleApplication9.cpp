#include <iostream>
#include <string>

using namespace std;

// Base class for cars
class Car {
public:
    virtual string startEngine() const = 0;
    virtual string openDoors() const = 0;
    virtual string turnOnLights() const = 0;
    virtual string turnOffLights() const = 0;
    virtual string accelerate() const = 0;
    virtual string brake() const = 0;
    virtual ~Car() {}
};

// Classes for different types of cars
class HondaCar : public Car {
public:
    string startEngine() const override {
        return "Starting Honda engine";
    }

    string openDoors() const override {
        return "Opening Honda doors";
    }

    string turnOnLights() const override {
        return "Turning on Honda lights";
    }

    string turnOffLights() const override {
        return "Turning off Honda lights";
    }

    string accelerate() const override {
        return "Honda accelerating";
    }

    string brake() const override {
        return "Honda braking";
    }
};

class BMWCar : public Car {
public:
    string startEngine() const override {
        return "Starting BMW engine";
    }

    string openDoors() const override {
        return "Opening BMW doors";
    }

    string turnOnLights() const override {
        return "Turning on BMW lights";
    }

    string turnOffLights() const override {
        return "Turning off BMW lights";
    }

    string accelerate() const override {
        return "BMW accelerating";
    }

    string brake() const override {
        return "BMW braking";
    }
};

class MercedesCar : public Car {
public:
    string startEngine() const override {
        return "Starting Mercedes engine";
    }

    string openDoors() const override {
        return "Opening Mercedes doors";
    }

    string turnOnLights() const override {
        return "Turning on Mercedes lights";
    }

    string turnOffLights() const override {
        return "Turning off Mercedes lights";
    }

    string accelerate() const override {
        return "Mercedes accelerating";
    }

    string brake() const override {
        return "Mercedes braking";
    }
};

// Factory methods for creating car objects
class CarFactory {
public:
    virtual Car* createCar() const = 0;
    virtual ~CarFactory() {}
};

class HondaFactory : public CarFactory {
public:
    Car* createCar() const override {
        return new HondaCar();
    }
};

class BMWFactory : public CarFactory {
public:
    Car* createCar() const override {
        return new BMWCar();
    }
};

class MercedesFactory : public CarFactory {
public:
    Car* createCar() const override {
        return new MercedesCar();
    }
};

// Function to print text in a frame
void printInFrame(const string& text) {
    int length = text.length() + 4; // Considering the border
    cout << string(length, '-') << endl;
    cout << "| " << text << " |" << endl;
    cout << string(length, '-') << endl;
}

// Program to choose and use cars
int main() {
    bool exit = false;

    do {
        cout << "Choose a car brand:" << endl;
        cout << "1. Honda" << endl;
        cout << "2. BMW" << endl;
        cout << "3. Mercedes" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 0) {
            exit = true;
        }
        else if (choice >= 1 && choice <= 3) {
            CarFactory* carFactory = nullptr;

            switch (choice) {
            case 1:
                carFactory = new HondaFactory();
                break;
            case 2:
                carFactory = new BMWFactory();
                break;
            case 3:
                carFactory = new MercedesFactory();
                break;
            }

            if (carFactory) {
                Car* car = carFactory->createCar();
                printInFrame(car->startEngine());
                printInFrame(car->openDoors());
                printInFrame(car->turnOnLights());
                printInFrame(car->accelerate());
                printInFrame(car->brake());
                printInFrame(car->turnOffLights());

                delete car;
                delete carFactory;
            }
        }
        else {
            cout << "Invalid choice. Please enter a valid number." << endl;
        }
    } while (!exit);

    return 0;
}
