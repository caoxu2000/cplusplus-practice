// Xu Cao
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

class Patient {
private:
    string firstName, middleName, lastName;
    string streetAddress, city, state, zip, phone;
    string emergencyContactName, emergencyContactPhone;
public:
    Patient(string, string, string, string, string, string, string, string, string, string);
    void setFirstName(string);
    void setMiddleName(string);
    void setLastName(string);
    void setStreetAddress(string);
    void setCity(string);
    void setState(string);
    void setZip(string);
    void setPhone(string);
    void setEmergencyContactName(string);
    void setEmergencyContactPhone(string);
    
    string getFirstName() const
    { return firstName; }
    string getMiddleName() const
    { return middleName; }
    string getLastName() const
    { return lastName; }
    string getStreetAddress() const
    { return streetAddress; }
    string getCity() const
    { return city; }
    string getState() const
    { return state; }
    string getZip() const
    { return zip; }
    string getPhone() const
    { return phone; }
    string getEmergencyContactName() const
    { return emergencyContactName; }
    string getEmergencyContactPhone() const
    { return emergencyContactPhone; }
};

class Procedure {
private:
    string procName;
    string dateOfProc;
    string drName;
    double charge;
public:
    Procedure(string, string, string, double);
    void setProcName(string);
    void setDateOfProc(char);
    void setDrName(string);
    
    string getProcName() const
    { return procName; }
    string getDateOfProc() const
    { return dateOfProc; }
    string getDrName() const
    { return drName; }
    double getCharge() const
    { return charge; }
    
};

Patient::Patient(string fName, string mName, string lName, string stAddr = "", string aCity = "", string aState = "", string aZip = "", string aPhone = "", string anEmergencyContactName = "", string anEmergencyContactPhone = "") {
    firstName = fName;
    middleName = mName;
    lastName = lName;
    
    streetAddress = stAddr;
    city = aCity;
    state = aState;
    zip = aZip;
    phone = aPhone;
    emergencyContactName = anEmergencyContactName;
    emergencyContactPhone = anEmergencyContactPhone;
}

Procedure::Procedure(string aProcName, string aProcDate, string aDrName, double aCharge) {
    procName = aProcName;
    dateOfProc = aProcDate;
    drName = aDrName;
    charge = aCharge;
}

int main() {
    string fName = "Tom";
    string mName = "Hero";
    string lName = "Hanks";
    string stAddress = "1 main st";
    string city1 = "Dublin";
    string state1 = "California";
    string zip1 = "94568";
    string phone1 = "925-201-1800";
    string emergencyContactName1 = "Taylor Swift";
    string emergencyContactPhone1 = "925-301-9678";
    
    Patient patient1(fName, mName, lName, stAddress, city1, state1, zip1, phone1, emergencyContactName1, emergencyContactPhone1);
    
    string procName1 = "Physical Exam";
    string drName1 = "Dr. Irvine";
    double charge1 = 250.00;
    
    string procName2 = "X-ray";
    string drName2 = "Dr. Jamison";
    double charge2 = 500.00;
    
    string procName3 = "Blood test";
    string drName3 = "Dr. Smith";
    double charge3 = 200.00;
    // get today's date in string
    chrono::system_clock::time_point now = std::chrono::system_clock::now();
    // Convert to time_t
    time_t now_c = std::chrono::system_clock::to_time_t(now);
    // Convert to tm struct
    tm* now_tm = std::localtime(&now_c);
    // Create a stringstream to format the output
    stringstream ss;
    // Format the string using put_time
    ss << put_time(now_tm, "%Y-%m-%d");
    // Get the string from the stringstream
    string todaysDate = ss.str();
    
    Procedure procedure1(procName1, todaysDate, drName1, charge1);
    Procedure procedure2(procName2, todaysDate, drName2, charge2);
    Procedure procedure3(procName3, todaysDate, drName3, charge3);
    
    cout << std::fixed;
    cout << std::setprecision(2);
    
    cout << "Patient1's info: " << endl;
    cout << "First Name: " << patient1.getFirstName() << endl;
    cout << "Middle Name: " << patient1.getMiddleName() << endl;
    cout << "Last Name: " << patient1.getLastName() << endl;
    cout << "Address: " << patient1.getStreetAddress() << endl;
    cout << "City: " << patient1.getCity() << endl;
    cout << "State: " << patient1.getState() << endl;
    cout << "ZIP: " << patient1.getZip() << endl;
    cout << "Phone: " << patient1.getPhone() << endl;
    cout << "Emergency Contact Name: " << patient1.getEmergencyContactName() << endl;
    cout << "Emergency Contact Phone: " << patient1.getEmergencyContactPhone() << endl;
    cout << endl;
    
    cout << "Procedure #1: " << endl;
    cout << "Procedure name: " << procedure1.getProcName() << endl;
    cout << "Date: " << procedure1.getDateOfProc() << endl;
    cout << "Practitioner: " << procedure1.getDrName() << endl;
    cout << "Charge: " << procedure1.getCharge() << endl;
    cout << endl;
    
    cout << "Procedure #2: " << endl;
    cout << "Procedure name: " << procedure2.getProcName() << endl;
    cout << "Date: " << procedure2.getDateOfProc() << endl;
    cout << "Practitioner: " << procedure2.getDrName() << endl;
    cout << "Charge: " << procedure2.getCharge() << endl;
    cout << endl;
    
    cout << "Procedure #3: " << endl;
    cout << "Procedure name: " << procedure3.getProcName() << endl;
    cout << "Date: " << procedure3.getDateOfProc() << endl;
    cout << "Practitioner: " << procedure3.getDrName() << endl;
    cout << "Charge: " << procedure3.getCharge() << endl;
    cout << endl;
    
    return 0;
}
