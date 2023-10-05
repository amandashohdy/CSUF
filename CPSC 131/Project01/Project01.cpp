/*****************
 * Amanda Shohdy 
 * Project 01
 *****************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::string ;
using std::vector ;
using std::cout ;
using std::endl ;

template <typename T> class Item
{
    public:
        T name ;
        T expiration ;
        T category ;
        int quantity ;

        Item(T n, T e, T c, int q)
        {
            name = n ;
            expiration = e ;
            category = c ;
            quantity = q ;
        }
} ;

template <typename T> class Inventory
{
    public:
        void addNewItem(Item<T> newItem)
        {
            // whether or not item is found in inventory
            bool found = false ; 

            // for each item, if the item is found in the inventory, 
            // output message and change found to true
            for (int i = 0 ; i < items.size() && !found ; i++)
            {
                if (newItem.name == items[i].name)
                {
                    cout << "Item is already present in inventory." << endl << endl ;
                    found = true ;
                }
            }
            
            // if item was not found, add item to the end of the vector
            if (!found) { items.push_back(newItem) ; }
        }

        void increaseQuantity(T itemName, int newQuantity)
        {
            cout << endl << "Increasing quantity for item: " << itemName << endl << endl ;
            // for each item in the inventory
            for (int i = 0 ; i < items.size() ; i++)
            {   
                if (itemName == items[i].name)  // if the item is found 
                { 
                    items[i].quantity = newQuantity ;  // update the quantity
                }
            }
        }

        void updateItem(T itemName, T newExpiration, T newCategory, int newQuantity)
        {
            cout << endl << "Updating item: " << itemName << endl << endl ;

            // whether or not the item is found in inventory
            bool found = false ;

            // for each item in the inventory, if the item is found, 
            // update the item and change found to true
            for (int i = 0 ; i < items.size() && !found ; i++)
            {   
                if (itemName == items[i].name) 
                { 
                    items[i].expiration = newExpiration ; // update expiration
                    items[i].category = newCategory ;     // update category
                    items[i].quantity = newQuantity ;     // update quantity
                    found = true ;
                }
            }

            // if item is not found, throw Item Not Found
            if (!found) { throw "Item Not Found\n" ; }
        }

        void removeItem(T itemName)
        {
            cout << endl << "Removing item: " << itemName << endl << endl ;

            // whether or not the item is found in inventory
            bool found = false ;

            // for each item in the inventory, if the item is found,
            // remove the item from the vector and change found to true
            for (int i = 0 ; i < items.size() && !found ; i++)
            {   
                if (itemName == items[i].name)  
                { 
                    items.erase(items.begin() + i) ;
                    found = true ;
                }
            }
            
            //if item is not found, throw Item Not Found
            if (!found) { throw "Item Not Found.\n" ; }
        }

        int Total()
        {
            // output and return the total items in the vector
            cout << endl << "There are " << items.size() << " total items." << endl << endl ;
            return items.size()  ;
        }

        void searchItem(T itemName)
        {
            cout << endl << "Searching for item: " << itemName << endl << endl ;

            // whether or not the item is found in inventory
            bool found = false ;

            // for each item in the inventory, if the item is found
            // output the item details and change found to true
            for (int i = 0 ; i < items.size() && !found ; i++)
            {   
                if (itemName == items[i].name)  
                { 
                    cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Expiration" << std::setw(15) 
                    << "Category" << std::setw(10) << "Quantity" << endl ;
                    cout << std::left  <<  std::setw(20) << items[i].name << std::setw(15) 
                    << items[i].expiration << std::setw(15) << items[i].category << std::setw(15) 
                    << items[i].quantity << endl << endl ;
                    found = true ;
                }
            }

            // if item not found, throw Item Not Found
            if (!found) { throw "Item Not Found.\n" ; }
        }

        void displayItems()
        {
            cout << "-------Inventory-------" << endl ;
            cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Expiration" << std::setw(15) 
            << "Category" << std::setw(10) << "Quantity" << endl ;

            for(int i=0 ; i<items.size() ;i++)
            {
                cout << std::left  <<  std::setw(20) << items[i].name << std::setw(15) 
                << items[i].expiration << std::setw(15) << items[i].category << std::setw(15) 
                << items[i].quantity << endl ;
            }
        }

    private :
        vector<Item<T>> items ;   // vector containing all Item objects
} ;

template <typename T> class Appointment
{
    public: 
        T c_name ;
        T ap_date ;
        T ap_time ;
        T CWID ;

        Appointment(T n, T d, T t, T cw)
        {
            c_name = n ;
            ap_date = d ;
            ap_time = t ;
            CWID = cw ; 
        }
} ;

template <typename T> class AppointmentSystem
{
    public:
        void schedule(Appointment<T> newAppointment) 
        {
            // whether or not CWID is already scheduled
            bool found = false ;

            // for each appointment, if the CWID is in the vector,
            // a message is output and found is true
            for (int i = 0 ; i < ap.size() && !found ; i++)
            {
                if (newAppointment.CWID == ap[i].CWID)
                {
                    cout << endl << "You have already scheduled an appointment." << endl << endl ;
                    found = true ;
                }
            }
            
            // if CWID is not in the vector, add appointment to the vector
            if (!found) { ap.push_back(newAppointment) ; }
        }

        int Total_appointments(T date, T time)
        {
            int totalAppointments = 0 ;

            // for each appointment in the vector, if the appointment date and time match the target,
            // increment totalAppointments
            for (int i = 0 ; i < ap.size() ; i++)
            {
                if (ap[i].ap_date == date && ap[i].ap_time == time)
                {
                    totalAppointments++ ;
                }
            }
            cout << endl << "There are " << totalAppointments << " appointments on " << date << " at " << time 
            << "." << endl << endl ;
            return totalAppointments ;
        }

        void removeRecent()
        {
            // erase the most recently added appointment
            cout << endl << "Removing most recently added appointment..." << endl << endl ;
            ap.pop_back() ;
        }

        void display()
        {
            cout << "-------Appointments-------" << endl ;
            cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Date" << std::setw(15) 
            << "Time" << std::setw(15) << "CWID" << endl ;

            for(int i=0 ; i<ap.size() ;i++)
            {
                cout << std::left  <<  std::setw(20) << ap[i].c_name << std::setw(15) << ap[i].ap_date 
                << std::setw(15) << ap[i].ap_time << std::setw(15) << ap[i].CWID << endl ;
            }
        }

    private :
        vector<Appointment<T>> ap ;   // vector containing all Appointment objects
} ;

int main()
{
    Inventory<string> i1;

    Item<string> I1("Protein Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    Item<string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    Item<string> I3("Cereals","09/12/2023","Snacks",5);
    i1.addNewItem(I3);

    i1.displayItems();

    i1.updateItem("Milk","09/24/2023","Regular",3);
    
    i1.displayItems();
    
    i1.increaseQuantity("Cereals",10);
    
    i1.displayItems();
    
    try { i1.updateItem("bar","09/12/2023","Snacks",3) ; }
    catch(const char* msg) { cout << msg << endl ; }

    i1.displayItems();
    
    i1.updateItem("Cereals","09/27/2023","Regular",4);
    
    i1.displayItems();
    
    i1.Total();
    
    try { i1.removeItem("Bread") ; }
    catch(const char* msg) { cout << msg << endl ; }

    try { i1.removeItem("Milk") ; }
    catch(const char* msg) { cout << msg << endl ; }

    i1.displayItems();
    
    try { i1.searchItem("Cereals") ; }
    catch(const char* msg) { cout << msg << endl ; }

    Appointment<string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");

    AppointmentSystem<string> s1;

    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);

    s1.display();
    
    s1.Total_appointments("09/12/2023","12:00PM");
    
    s1.schedule(a4);
    
    s1.removeRecent();
    
    s1.display();
}
