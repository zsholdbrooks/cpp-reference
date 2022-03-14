#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
        static int totalNumVehicles;

        string className = "Vehicle";
        string vehicleName;
        int numWheels;
    public:
        string getClassName(void) { return className; }
        int getNumWheels(void) { return numWheels; }

        Vehicle(int numWheels, string vehicleName = "") {
            if (this->totalNumVehicles >= 10) {
                throw "Too many vehicles!";
            }

            this->totalNumVehicles++;
            this->numWheels = numWheels;
            this->vehicleName = vehicleName;
            cout << "There are now " << this->totalNumVehicles << " vehicles." << endl;
        }

        ~Vehicle() {
            this->totalNumVehicles--;
        }

        friend ostream& operator<<(std::ostream& strm, const Vehicle& a); // {
        //    return strm << a.className << " has " << a.numWheels << " wheels";
        //}

};
int Vehicle::totalNumVehicles = 0;

ostream& operator<<(ostream& strm, const Vehicle& a) {
    strm << a.className << " has " << a.numWheels << " wheels";
    return strm;
}

class Bicycle {


    friend ostream& operator<<(std::ostream& strm, const Bicycle& a); // {
        return strm << a.className << " has " << a.numWheels << " wheels";
    }
}

int main() {
    cout << "Hello world!" << endl;
    
    Vehicle x = Vehicle(8);
    cout << x.getNumWheels() << " wheels for " << x.getClassName() << endl;
    
    vector<Vehicle> listVehicles;
    cout << x << endl;
    listVehicles.push_back(x);
    return 0;
}


/* Using this keyword cases
    1. If class argument names are same as class member names (just don't do it)
    2. When having a class inheriting from a template generic type, "this" can be used to attempt
       to reference a member rather than a relevant scoped object.
         e.g. this.name will return the derived class's name rather than attempting to use
              something like a global of name. Same idea with functions.
*/