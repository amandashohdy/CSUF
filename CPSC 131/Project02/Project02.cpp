/****************
 * Amanda Shohdy
 *  Project 02  
 ****************/

#include<iostream>
#include<memory>
#include<vector>
#include<string>

using std::string ;
using std::shared_ptr ;
using std::make_shared ;

template <typename T> class Tab     // Node
{
    public :
        string url ;     // url of website
        string name ;    // name of site
        T memory ;       // memory consumed by site
        shared_ptr<Tab<T>> prev ;
        shared_ptr<Tab<T>> next ;
} ;

template <typename T> class Browser   // LinkedList
{
    public :
        shared_ptr<Tab<T>> head ;
        shared_ptr<Tab<T>> current ;
        shared_ptr<Tab<T>> tail ;

        void addNewTab(string newUrl, string newName, T newMemory)
        {
            auto newNode = make_shared<Tab<T>>() ;
            
            // if linked list is empty
            if (head == nullptr)
            {
                newNode->url = newUrl ;
                newNode->name = newName ;
                newNode->memory = newMemory ;
                newNode->prev = nullptr ;
                newNode->next = nullptr ;
                head = newNode ;
                tail = newNode ;
                current = newNode ;
            }
            else
            {
                newNode->url = newUrl ;
                newNode->name = newName ;
                newNode->memory = newMemory ;

                newNode->prev = tail ;
                tail->next = newNode ;
                tail = newNode ;
                newNode->next = nullptr ;
                current = newNode ;
            }
        }

        void switchToPrevTab()
        {
            if (current->prev == nullptr) { std::cout << "No previous tab." << std::endl << std::endl ; }
            else
            {
                current = current->prev ;
                std::cout << "Current Tab: " << std::endl ;
                std::cout << "  " << current->name << " <" << current->url << ">  Memory: " << current->memory << std::endl << std::endl ;
            } 
        }

        void switchToNextTab()
        {
            if (current->next == nullptr) { std::cout << "No next tab." << std::endl << std::endl ; }
            else
            {
                current = current->next ;
                std::cout << "Current Tab: " << std::endl ;
                std::cout << "  " << current->name << " <" << current->url << ">  Memory: " << current->memory << std::endl << std::endl ;
            }
        }

        void closeCurrentTab()
        {
            shared_ptr<Tab<T>> temp = current ;
            std::cout << std::endl << "Closing Current Tab: " << temp->name << std::endl ;

            // if temp is the head
            if (temp->prev == nullptr)
            {
                current = temp->next ;          // update current
                temp->next = nullptr ;          // temp points to null
                current->prev = nullptr ;       // remove pointer to temp
                head = current ;                // update head to current
            }
            // if temp is tail
            else if (temp->next == nullptr)
            {
                current = temp->prev ;          // update current
                temp->prev = nullptr ;          // temp points to null
                current->next = nullptr ;       // remove pointer to temp
                tail = current ;                // update temp
            }
            else 
            {
                current = temp->next ;              // update current
                (temp->prev)->next = temp->next ;   // previous tab points to next tab
                (temp->next)->prev = temp->prev ;   // next tab points to previous tab
                temp->prev = nullptr ;              // temp points to null
                temp->next = nullptr ;              // temp points to null
            }
            std::cout << "Now the current tab = " << current->name << std::endl << std::endl ;
        }

        void bookmarkCurrent()
        {
            bool found = false ;
            // for elements and favorites vector while element is not found
            for (int i = 0 ; i < favorites.size() && !found ; i++)
            {
                // if element is found in favorites, output message and found = true
                if (current->name == favorites[i].first && current->url == favorites[i].second)
                {
                    std::cout << std::endl << "The bookmark is already added." << std::endl << std::endl ;
                    found = true ;
                }
            }
            // if element is not in favorites, add name and url to favorites
            if (!found) { favorites.push_back(std::make_pair(current->name, current->url)) ; }
        }

        void showBookmarkTab()
        {
            std::cout << std::endl << "Bookmarks: " << std::endl ;
            for (int i = 0 ; i < favorites.size() ; i++)
            {
                std::cout << favorites[i].first << " (" << favorites[i].second << ")" << std::endl ;
            }
            std::cout << std::endl ;
        }

        void moveCurrentToFirst()
        {
            // if current is not head
            if (current->prev != nullptr) 
            { 
                // if current is tail
                if (current->next == nullptr)
                {
                    (current->prev)->next = nullptr ;   // previous points to null
                    tail = current->prev ;              // set tail to previous
                    head->prev = current ;              // head->prev points to current
                    current->next = head ;              // current->next points to head
                    current->prev = nullptr ;           // current->prev points to null
                    head = current ;                    // update head to current
                }
                else
                {
                    (current->prev)->next = current->next ;     // previous points to next
                    (current->next)->prev = current->prev ;     // next points to previous
                    head->prev = current ;                      // head->prev points to current
                    current->next = head ;                      // current->next points to head
                    current->prev = nullptr ;                   // current->prev points to null
                    head = current ;                            // update head to current
                }
            }
        }

        T total_memory()
        {
            T memoryConsumption = 0 ;
            shared_ptr<Tab<T>> currPtr = head ;
            while (currPtr != nullptr) 
            { 
                memoryConsumption += currPtr->memory ; 
                currPtr = currPtr->next ;
            }
            return memoryConsumption ;
        }

        void deleteTab()
        {
            shared_ptr<Tab<T>> highestTab = head ;
            shared_ptr<Tab<T>> currTab = head ;
            while (currTab != nullptr) 
            { 
                if (highestTab->memory < currTab->memory) { highestTab = currTab ; }
                currTab = currTab->next ;
            }
            std::cout << std::endl << "Deleting Tab: " << highestTab->name << " <" << highestTab->url << ">  Memory: " << 
            highestTab->memory << std::endl << std::endl ;

            // if highest tab is head
            if (highestTab->prev == nullptr)
            {
                if (highestTab == current) { current = highestTab->next ; }     // if highest tab is current, update current
                (highestTab->next)->prev = nullptr ;    // next->prev points to null
                head = highestTab->next ;               // update head
                highestTab->next = nullptr ;            // highestTab points to null
            }
            // if highest tab is tail
            else if (highestTab->next == nullptr)
            {
                if (highestTab == current) { current = highestTab->prev ; }     // if highest tab is current, update current
                (highestTab->prev)->next = nullptr ;    // prev->next points to null
                tail = highestTab->prev ;               // update tail
                highestTab->prev = nullptr ;            // highestTab points to null
            }
            else
            {
                if (highestTab == current) { current = highestTab->next ; }     // if highest tab is current, update current
                (highestTab->prev)->next = highestTab->next ;       // prev->next points to highest->next
                (highestTab->next)->prev = highestTab->prev ;       // next->prev points to highest->prev
                highestTab->prev = nullptr ;                        // highestTab points to null
                highestTab->next = nullptr ;                        // highestTab points to null
            }
        }

        void display()
        {
            auto curr = head;
            std::cout<<"Browser tab list = "<<std::endl;
            while(curr){
                std::cout<<"| "<<curr->name<<"  x|-->";
                curr = curr->next;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
    
    private :
        std::vector<std::pair<string, string>> favorites ;
} ; 

int main(){
    
    Browser<double> b1;
    b1.addNewTab("https://www.google.com","Google",23.45);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to Next tab = "<<std::endl;
    b1.switchToNextTab();
    
    b1.addNewTab("https://www.youtube.com","YouTube",56);
    b1.bookmarkCurrent();
    b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
    b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com","ChatGPT",129);
    b1.addNewTab("https://linkedin.com","LinkedIn",410);
    b1.bookmarkCurrent();
    b1.addNewTab("https://github.com","Github",110);
    b1.addNewTab("https://kaggle.com","Kaggle",310);
    b1.bookmarkCurrent();
    b1.display();
    std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.showBookmarkTab();
    
    b1.moveCurrentToFirst();
    b1.display();
    b1.deleteTab();
    b1.display();
    
    std::cout<<"Switch to next tab = "<<std::endl;
    b1.switchToNextTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    
    b1.showBookmarkTab();
    std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
    
    b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.bookmarkCurrent();
    b1.showBookmarkTab();
    std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
    return 0;
}
