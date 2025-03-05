#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int id;

public:
    Employee(int id, string name) : id(id), name(name) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    virtual void displayDetails() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    set<string> workSchedule;

public:
    FullTimeEmployee(int id, string name) : Employee(id, name) {}

    void addSchedule(const string& schedule) {
        workSchedule.insert(schedule);
    }

    set<string> getWorkSchedule() const {
        return workSchedule;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Work Schedule: ";
        for (const auto& schedule : workSchedule) {
            cout << schedule << ", ";
        }
        cout << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    set<string> shifts;

public:
    PartTimeEmployee(int id, string name) : Employee(id, name) {}

    void addShift(const string& shift) {
        shifts.insert(shift);
    }

    set<string> getShifts() const {
        return shifts;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Shifts: ";
        for (const auto& shift : shifts) {
            cout << shift << ", ";
        }
        cout << endl;
    }
};

map<int, Employee*> employees;

void addNewEmployee() {
    int employeeId;
    string employeeName;
    string employmentType;
    
    cout << "Please enter the employee ID: ";
    cin >> employeeId;
    cin.ignore();
    cout << "Please enter the employee name: ";
    getline(cin, employeeName);
    cout << "Please specify the employee type:- (F - Full-Time/P - Part-Time):- ";
    cin >> employmentType;

    if (employmentType == "F" || employmentType == "Full-Time") {
        FullTimeEmployee* newEmployee = new FullTimeEmployee(employeeId, employeeName);
        employees[employeeId] = newEmployee;
        cout << "Employee has been added successfully!" << endl;
    } else if (employmentType == "P" || employmentType == "Part-Time") {
        PartTimeEmployee* newEmployee = new PartTimeEmployee(employeeId, employeeName);
        employees[employeeId] = newEmployee;
        cout << "Employee has been added successfully!" << endl;
    }
    else
        cout << "Invalid command!" << endl;
}

void setWorkSchedule() {
    int employeeId;
    string workSchedule;
    
    cout << "Please enter the employee ID: ";
    cin >> employeeId;
    cin.ignore();
    cout << "Please enter the work schedule: ";
    getline(cin, workSchedule);

    if (employees.find(employeeId) != employees.end()) {
        FullTimeEmployee* fullTimeEmp = dynamic_cast<FullTimeEmployee*>(employees[employeeId]);
        if (fullTimeEmp != nullptr) {
            fullTimeEmp->addSchedule(workSchedule);
            cout << "Work schedule has been assigned successfully!" << endl;
        } else {
            cout << "The employee is not a Full-Time Employee!" << endl;
        }
    } else {
        cout << "Employee not found!" << endl;
    }
}

void setShiftTiming() {
    int employeeId;
    string shiftTiming;
    
    cout << "Please enter the employee ID: ";
    cin >> employeeId;
    cin.ignore();
    cout << "Please enter the shift timing: ";
    getline(cin, shiftTiming);

    if (employees.find(employeeId) != employees.end()) {
        PartTimeEmployee* partTimeEmp = dynamic_cast<PartTimeEmployee*>(employees[employeeId]);
        if (partTimeEmp != nullptr) {
            partTimeEmp->addShift(shiftTiming);
            cout << "Shift has been assigned successfully!" << endl;
        } else {
            cout << "The employee is not a Part-Time Employee!" << endl;
        }
    } else {
        cout << "Employee not found!" << endl;
    }
}

void displayEmployeeData() {
    cout << "Full-Time Employees:" << endl;
    for (const auto& emp : employees) {
        FullTimeEmployee* fullTimeEmp = dynamic_cast<FullTimeEmployee*>(emp.second);
        if (fullTimeEmp != nullptr) {
            fullTimeEmp->displayDetails();
        }
    }
    
    cout << "Part-Time Employees:" << endl;
    for (const auto& emp : employees) {
        PartTimeEmployee* partTimeEmp = dynamic_cast<PartTimeEmployee*>(emp.second);
        if (partTimeEmp != nullptr) {
            partTimeEmp->displayDetails();
        }
    }
}

void saveEmployeeData() {
    ofstream fullTimeOutput("fulltime_employees.txt");
    ofstream partTimeOutput("parttime_employees.txt");

    for (const auto& emp : employees) {
        FullTimeEmployee* fullTimeEmp = dynamic_cast<FullTimeEmployee*>(emp.second);
        if (fullTimeEmp != nullptr) {
            fullTimeOutput << fullTimeEmp->getId() << " " << fullTimeEmp->getName() << endl;
            for (const auto& schedule : fullTimeEmp->getWorkSchedule()) {
                fullTimeOutput << schedule << endl;
            }
        }
        
        PartTimeEmployee* partTimeEmp = dynamic_cast<PartTimeEmployee*>(emp.second);
        if (partTimeEmp != nullptr) {
            partTimeOutput << partTimeEmp->getId() << " " << partTimeEmp->getName() << endl;
            for (const auto& shift : partTimeEmp->getShifts()) {
                partTimeOutput << shift << endl;
            }
        }
    }

    fullTimeOutput.close();
    partTimeOutput.close();
    cout << "Data has been successfully saved to files!" << endl;
}

void loadData() {
    ifstream fullTimeFile("fulltime_employees.txt");
    ifstream partTimeFile("parttime_employees.txt");

    if (fullTimeFile.is_open()) {
        int id;
        string name, schedule;
        while (fullTimeFile >> id) {
            fullTimeFile.ignore();
            getline(fullTimeFile, name);
            FullTimeEmployee* emp = new FullTimeEmployee(id, name);
            while (getline(fullTimeFile, schedule) && !schedule.empty()) {
                emp->addSchedule(schedule);
            }
            employees[id] = emp;
        }
        fullTimeFile.close();
    }

    if (partTimeFile.is_open()) {
        int id;
        string name, shift;
        while (partTimeFile >> id) {
            partTimeFile.ignore();
            getline(partTimeFile, name);
            PartTimeEmployee* emp = new PartTimeEmployee(id, name);
            while (getline(partTimeFile, shift) && !shift.empty()) {
                emp->addShift(shift);
            }
            employees[id] = emp;
        }
        partTimeFile.close();
    }

    cout << "Data successfully loaded from files!" << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "1. Add Employee" << endl;
        cout << "2. Assign Work Schedule" << endl;
        cout << "3. Assign Shift" << endl;
        cout << "4. Display Data" << endl;
        cout << "5. Save Data" << endl;
        cout << "6. Load Data" << endl;
        cout << "7. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNewEmployee();
                break;
            case 2:
                setWorkSchedule();
                break;
            case 3:
                setShiftTiming();
                break;
            case 4:
                displayEmployeeData();
                break;
            case 5:
                saveEmployeeData();
                break;
            case 6:
                loadData();
                break;
            case 7:
                cout << "Terminating program..." << endl;
                return 0;
            default:
                cout << "Choice is not valid!" << endl;
        }
    }

    return 0;
}
