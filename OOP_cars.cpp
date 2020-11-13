#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class vehicle
{
    private:
        char* plate;
        char* brand;
        unsigned int seats;
    public:
    virtual ~vehicle()
    {
        delete[] plate;
        delete[] brand;
    };
    virtual void setPlate(char* Plate)
    {
        int size = strlen(Plate);
        plate = new char[size + 1];
        strcpy(plate, Plate);
    }
    virtual void setBrand(char* Brand)
    {
        int size = strlen(Brand);
        brand = new char[size + 1];
        strcpy(brand, Brand);
    }
    virtual void setSeats(unsigned int Seats)
    {
        seats = Seats;
    }
    virtual char* getPlate()
    {   
        return plate;
    }
    virtual char* getBrand()
    {
        return brand;
    }
    virtual int getSeats()
    {
        return seats;
    }
};

class SUV : public vehicle
{
    public:
    SUV(char* Plate, char* Brand, bool thirdRow)
    {
        setPlate(Plate);
        setBrand(Brand);
        thirdRow? setSeats(7) : setSeats(5);
    }
    bool getthirdRow()
    {
        return thirdrow;
    }
    char* getPlate()
    {
        return vehicle::getPlate();   
    }
    char* getBrand()
    {
        return vehicle::getBrand();
    }
    int getSeats()
    {
        return vehicle::getSeats();
    }
    ~SUV()
    {}
    private:
        bool thirdrow;
};

class Sports: public vehicle
{ 
    public:
    Sports(char* Plate, char* Brand, bool Sport)
    {
        setPlate(Plate);
        setBrand(Brand);
        setSeats(5);
        
        isSport = Sport;
    }
    bool getisSport()
    {
        return isSport;
    }
    char* getPlate()
    {
        return vehicle::getPlate();
    }
    char* getBrand()
    {
        return vehicle::getBrand();
    }
    int getSeats()
    {
        return vehicle::getSeats();
    }
    ~Sports()
    {}
    private:
        bool isSport;
};

int main()
{
    Sports* WSB;
    SUV* YOLOFD;
    
    WSB = new Sports("WSB","TSLA",true);
    YOLOFD = new SUV("YOLOFD","NIO",true);
    
    vehicle** stockpile = new vehicle*[2];
    
    stockpile[0] = WSB;
    stockpile[1] = YOLOFD;
    
    cout<<stockpile[0]->getSeats()<<"\t"<<stockpile[0]->getPlate()<<"\t"<<stockpile[0]->getBrand()<<endl;
    cout<<stockpile[1]->getSeats()<<"\t"<<stockpile[1]->getPlate()<<"\t"<<stockpile[1]->getBrand()<<endl;
    
    delete WSB;
    delete YOLOFD;
    delete [] stockpile;
    return 0;
}
