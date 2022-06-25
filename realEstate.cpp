#include <iostream>
#include <string>
using namespace std;
/* AGENT */
class Agent
{
    private:
        string firstName;
        string secondName;
        string emailAddress;
        string phoneNumber;
        string accountName;
    public:
        // input
        void setFirstName(string firstName);
        void setSecondName(string secondName);
        void setEmailAddress(string emailAddress);
        void setPhoneNumber(string phoneNumber);
        void setAccountName(string accountName);
        void setPassword(string password);
        void setAgentDetails();
        // output
        string getFirstName();
        string getSecondName();
        string getEmailAddress();
        string getPhoneNumber();
        string getAccountName();
        void getAgentDetails();
};

/* PROPERTY */
class PropertyOptions
{
    private:
        string TypeArr[2] = {"Land","Housing"};
        string ServiceArr[2] = {"For Rent", "For Sale"};
        string StatusArr[2] = {"Yes", "No"};
    public:
        int len;
        PropertyOptions(){}; // For accessing the items in arrays
        PropertyOptions(int option); // For displaying a list of arrays
        ~PropertyOptions(){}; // Deconstructors
        string getType(int id);
        string getService(int id);
        string getStatus(int id);
};

class Property
{
    private:
        string accountName;
        string county;
        string subCounty;
        int TypeID;
        int ServiceID;
        int StatusID;
        float price;
        float areaSize;
        string description;
    public:
        // input
        Property();
        void setAccountName(string accountName);
        void setCounty(string county);
        void setSubCounty(string subCounty);
        void setTypeID(int TypeID);
        void setServiceID(int ServiceID);
        void setStatusID(int StatusID);
        void setDescription(string description);
        void setPrice(float price);
        void setAreaSize(float areasSize);
        friend class PropertyOptions;
        void setPropertyDetails();
        // output
        string getAccountName();
        string getCounty();
        string getSubCounty();
        int getTypeID();
        int getServiceID();
        int getStatusID();
        string getDescription();
        float getPrice();
        float getAreaSize();
        void getPropertyDetails();

};

class Land:public Property
{
    private:
        string zoning;
    public:
        Land();
        //input
        void setZoning(string zoning);
        void setLandDetails();
        //output
        string getZoning();
        void getLandDetails();
};

class HousingProperties
{
    private:
        string HousingArr[4] = {"Apartments", "Mansion", "Villa", "Cottage"};
    public:
        HousingProperties(int option);
        HousingProperties(){};
        string getHousingArr(int id);
};

class Housing:public Property
{
    private:
        int bedroomCount;
        int bathroomCount;
        int HouseTypeID;
    public:
        Housing();
        friend class HousingProperties;
        void setBedroomCount(int bedroomCount);
        void setBathroomCount(int bathroomCount);
        void setHouseTypeID(int HouseTypeID);
        void setHouseDetails();
        //output
        int getBedroomCount();
        int getBathroomCount();
        int getHouseTypeID();
        void getHouseDetails();
};

class Apartments : public Housing
{
    public:
        Apartments();
};

class Mansion:public Housing
{
    public:
        Mansion();
};

class Villa:public Housing
{
    public:
        Villa();
};

class Cottage:public Housing
{
    public:
        Cottage();
};

void main_menu();
void agent_registration();
void property_listing();
//void property_servicing();
void land_listing();
void housing_listing();
void apartment_listing();
void mansion_listing();
void villa_listing();
void cottage_listing();


int main()
{
    main_menu();
    return 0;
}

void Agent::setFirstName(string firstName)
    { this->firstName = firstName; }

void Agent::setSecondName(string secondName)
    { this->secondName = secondName; }

void Agent::setEmailAddress(string emailAddress)
    { this->emailAddress = emailAddress; }

void Agent::setPhoneNumber(string phoneNumber)
    { this->phoneNumber = phoneNumber; }

void Agent::setAccountName(string accountName)
    { this->accountName = accountName; }

void Agent::setAgentDetails()
{
    string x;
    cout << "FIRST NAME: "; cin >> x; setFirstName(x);
    cout << "SECOND NAME: "; cin >> x; setSecondName(x);
    cout << "EMAIL ADDRESS: "; cin >> x; setEmailAddress(x);
    cout << "PHONE NUMBER: "; cin >> x; setPhoneNumber(x);
    cout << "ACCOUNT NAME: "; cin >> x; setAccountName(x);
}

string Agent::getFirstName()
    { return firstName; }

string Agent::getSecondName()
    { return secondName; }

string Agent::getEmailAddress()
    { return emailAddress; }

string Agent::getPhoneNumber()
    { return phoneNumber; }

string Agent::getAccountName()
    { return accountName; }

void Agent::getAgentDetails()
{
    cout << endl;
    cout << "FIRST NAME: " << getFirstName() << endl;
    cout << "SECOND NAME: " << getSecondName() << endl;
    cout << "EMAIL ADDRESS: " << getEmailAddress() << endl;
    cout << "PHONE NUMBER: " << getPhoneNumber() << endl;
    cout << "--CREATE ACCOUNT:" << endl;
    cout << "ACCOUNT NAME: " << getAccountName() << endl;
}

PropertyOptions::PropertyOptions(int option)
{
    switch(option)
    {
    case 1:
        len = sizeof(TypeArr)/sizeof(TypeArr[0]);
        for(int i = 0; i < len; i++)
        {
            cout << i+1 << ". " <<TypeArr[i] << endl;
        }
        break;
    case 2:
        len = sizeof(ServiceArr)/sizeof(ServiceArr[0]);
        for(int i = 0; i < len; i++)
        {
            cout << i+1 << ". " << ServiceArr[i] << endl;
        }
        break;
    case 3:
        len = sizeof(StatusArr)/sizeof(StatusArr[0]);
        for(int i = 0; i < len; i++)
        {
            cout << i+1 << ". " << StatusArr[i] << endl;
        }
        break;
    default:
        cout << "INVALID!" << endl;
    }
}

string PropertyOptions::getType(int id)
    { return TypeArr[id - 1]; }

string PropertyOptions::getService(int id)
    { return ServiceArr[id - 1]; }

string PropertyOptions::getStatus(int id)
    { return StatusArr[id - 1]; }

Property::Property()
    { StatusID = 1; }

void Property::setAccountName(string accountName)
    { this->accountName = accountName; }

void Property::setCounty(string county)
    { this->county = county; }

void Property::setSubCounty(string subCounty)
    { this->subCounty = subCounty; }

void Property::setTypeID(int TypeID)
    { this->TypeID = TypeID; }

void Property::setServiceID(int ServiceID)
    { this->ServiceID = ServiceID; }

void Property::setStatusID(int StatusID)
    { this->StatusID = StatusID; }

void Property::setDescription(string description)
    { this->description = description; }

void Property::setPrice(float price)
    { this->price = price; }

void Property::setAreaSize(float areaSize)
    { this->areaSize = areaSize; }

void Property::setPropertyDetails()
{
    string x;
    int y;
    float z;
    cin.ignore();
    cout << "ACCOUNT NAME: "; getline(cin,x); setAccountName(x);
    cout << "COUNTY: "; getline(cin,x); setCounty(x);
    cout << "SUBCOUNTY: "; getline(cin,x); setSubCounty(x);
    cout << "PROPERTY SERVICE:" << endl;
    PropertyOptions two(2);
    cout << "ENTER TYPE: ";
    cin >> y;
    while(y < 1 || y > 2) // to ensure id inputs stays in range
    {
        cout << "INVALID INPUT" << endl << "TRY AGAIN:";
        cin >> y;
    }
    setServiceID(y);
    cout << "PRICE(In Kshs): "; cin >> z; setPrice(z);
    cout << "AREA SIZE(sq. meters): "; cin >> z; setAreaSize(z);
    cin.ignore();
    cout << "DESCRIPTION: "; getline(cin,x); setDescription(x);

}

string Property::getAccountName()
    { return accountName; }

string Property::getCounty()
    { return county; }

string Property::getSubCounty()
    { return subCounty; }

int Property::getTypeID()
    { return TypeID; }

int Property::getServiceID()
    { return ServiceID; }

int Property::getStatusID()
    { return StatusID; }

float Property::getPrice()
    { return price; }

float Property::getAreaSize()
    { return areaSize; }

string Property::getDescription()
    { return description; }

void Property::getPropertyDetails()
{
    cout << endl;
    cout << "ACCOUNT NAME: " << getAccountName() << endl;
    cout << "COUNTY: " << getCounty() << endl;
    cout << "SUBCOUNTY: " << getSubCounty() << endl;
    PropertyOptions options;
    cout << "PROPERTY TYPE: " << options.getType(getTypeID()) << endl;
    cout << "PROPERTY SERVICE: " << options.getService(getServiceID()) << endl;
    cout << "AVAILABLE: " << options.getStatus(getStatusID()) << endl;
    cout << "PRICE: Kshs."<< getPrice() << endl;
    cout << "AREA SIZE: " << getAreaSize() << " sq.metres" << endl;
    cout << "DESCRIPTION:" << getDescription() << endl;
}

Land::Land()
    { setTypeID(1); }

void Land::setZoning(string zoning)
    { this->zoning = zoning; }

void Land::setLandDetails()
{
    setPropertyDetails();
    string x;
    cout << "ZONING: "; cin >> x; setZoning(x);
}

string Land::getZoning()
    { return zoning; }

void Land::getLandDetails()
{
    cin.ignore();
    getPropertyDetails();
    cout << "ZONING: " << getZoning() << endl;
}

HousingProperties::HousingProperties(int option)
{
    int len = sizeof(HousingArr)/sizeof(HousingArr[0]);
    for(int i = 0; i < len; i++)
    {
        cout << i+1 << ". " << HousingArr[i] << endl;
    }
}

string HousingProperties::getHousingArr(int id)
    { return HousingArr[id - 1]; }

void Housing::setBedroomCount(int bedroomCount)
    { this->bedroomCount = bedroomCount; }

void Housing::setBathroomCount(int bathroomCount)
    { this->bathroomCount = bathroomCount; }

void Housing::setHouseTypeID(int HouseTypeID)
    { this->HouseTypeID = HouseTypeID; }

void Housing::setHouseDetails()
{
    cin.ignore();
    setPropertyDetails();
    int x;
    cout << "BEDROOM COUNT: "; cin >> x; setBedroomCount(x);
    cout << "BATHROOM COUNT: "; cin >> x; setBathroomCount(x);
}


int Housing::getBedroomCount()
    { return bedroomCount; }

int Housing::getBathroomCount()
    { return bathroomCount; }

int Housing::getHouseTypeID()
    { return HouseTypeID; }

void Housing::getHouseDetails()
{
    getPropertyDetails();
    cout << "BEDROOM COUNT: " << getBedroomCount() << endl;
    cout << "BATHROOM COUNT: " << getBathroomCount() << endl;
    HousingProperties options;
    cout << "HOUSE TYPE: " << options.getHousingArr(getHouseTypeID()) << endl;
}

Housing::Housing()
    { setTypeID(2); }

Apartments::Apartments()
    { setHouseTypeID(1); }

Mansion::Mansion()
    { setHouseTypeID(2); }

Villa::Villa()
    { setHouseTypeID(3); }

Cottage::Cottage()
    { setHouseTypeID(4); }

void main_menu()
{
    cout << endl;
    cout << "---MAIN MENU---" << endl;
    cout << endl;
    cout << "1. Register Agent" << endl;
    cout << "2. List New Property" << endl;
    cout << "3. Sell or Rent Property" << endl;
    cout << "0. EXIT" << endl;
    int x;
    cout << "ENTER CHOICE: ";
    cin >> x;

    while(x < 0 || x > 3)
    {
        cout << endl;
        cout << "!ÏNVALID INPUT. TRY AGAIN!" << endl;
        cout << "ENTER CHOICE: ";
        cin >> x;
    }

    switch(x)
    {
        case 1:
            agent_registration();
            cout << endl <<  "!LISTING SUCCESSFUL!" << endl << endl;
            main_menu();
            break;
        case 2:
            property_listing();
            cout << endl <<  "!LISTING SUCCESSFUL!" << endl << endl;
            main_menu();
            break;
        /*case 3:
            property_servicing();
            break;*/
        case 0:
            cout << endl;
            cout << "!PROGRAM CLOSED!" << endl;
            break;
    }
}

void agent_registration()
{
    cout << endl;
    cout << "--AGENT REGISTRATION--" << endl;
    cout << endl;
    Agent x;
    x.setAgentDetails();
    x.getAgentDetails();
}

void property_listing()
{
    cout << endl;
    cout << "--PROPERTY TYPE--" << endl;
    cout << endl;
    cout << "1. Land" << endl;
    cout << "2. Housing" << endl;
    cout << "0. BACK" << endl;
    int x;
    cout << "ENTER CHOICE: ";
    cin >> x;

    while(x < 0 || x > 2)
    {
        cout << endl;
        cout << "!ÏNVALID INPUT. TRY AGAIN!" << endl;
        cout << "ENTER CHOICE: ";
        cin >> x;
    }

    switch(x)
    {
        case 1:
            land_listing();
            break;
        case 2:
            housing_listing();
            break;
        case 0:
            main_menu();
    }
}

void land_listing()
{
    Land x;
    x.setLandDetails();
    x.getLandDetails();
}

void housing_listing()
{
    cout << endl;
    cout << "-HOUSE TYPE-" << endl;
    cout << endl;
    cout << "1. Apartment" << endl;
    cout << "2. Mansion" << endl;
    cout << "3. Villa" << endl;
    cout << "4. Cottage" << endl;
    cout << "0. BACK" << endl;
    int x;
    cout << "ENTER CHOICE: ";
    cin >> x;
    while(x < 0 || x > 4)
    {
        cout << "!ÏNVALID INPUT. TRY AGAIN!" << endl;
        cout << "ENTER CHOICE: ";
        cin >> x;
    }
    switch(x)
    {
        case 1:
            apartment_listing();
            break;
        case 2:
            mansion_listing();
            break;
        case 3:
            villa_listing();
            break;
        case 4:
            cottage_listing();
            break;
        case 0:
            property_listing();
            break;
    }
}

void apartment_listing()
{
    Apartments x;
    x.setHouseDetails();
    x.getHouseDetails();
}

void mansion_listing()
{
    Mansion x;
    x.setHouseDetails();
    x.getHouseDetails();
}

void villa_listing()
{
    Villa x;
    x.setHouseDetails();
    x.getHouseDetails();
}

void cottage_listing()
{
    Cottage x;
    x.setHouseDetails();
    x.getHouseDetails();
}

