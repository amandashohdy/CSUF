/*****************
 * Amanda Shohdy *
 *   887333557   *
 *****************/

#include <iostream>
#include <vector>
#include <string>

using std::string ;

// Add class Stack here
class Stack
{
    public :
        // add element to top of the stack (end of the vector)
        void push(char val) { stack.push_back(val) ; }

        // remove first element of the stack (last element of the vector)
        void pop() { stack.pop_back() ; }

        // return element at the top of the stack
        char top() { return stack[stack.size() - 1] ; }

        // empty the stack
        void empty() { while (stack.size() != 0) { pop() ; } ; }

        // determine whether parenthesis are completed
        void validPara(string str)
        {
            empty() ;       // empty the stack 

            bool balanced = true ;
            for (int i = 0 ; i < str.length() && balanced ; i++)    // for each character in the string
            {
                // if the character is an opening symbol, push it to the stack
                if (str[i] == '(' || str[i] == '{' || str[i] == '[') { push(str[i]) ; } 

                else if (str[i] == ')')     // if the current character is a closing parenthesis
                {
                    if (top() != '(') { balanced = false ; }
                    else { pop() ; }
                }

                else if (str[i] == '}')     // if the current character is a closing brace
                {
                    if (top() != '{') { balanced = false ; }
                    else { pop() ; }
                }
                
                else if (str[i] == ']')     // if the current character is a closing bracket
                {
                    if (top() != '[') { balanced = false ; }
                    else { pop() ; }
                }
            }
            // if the end of the string is reached and there are still elements in the stack
            if (stack.size() != 0) { balanced = false ; } 

            if (balanced) { std::cout << std::endl << str << " :  " << "Valid." << std::endl ; }
            else { std::cout << std::endl << str << " :  " << "Invalid." << std::endl ; }
        }

        // find the index of the first error
        int indexError(string str)
        {
            empty() ;       // empty the stack
            
            bool balanced = true ;
            int indexOfError = -1 ;
            for (int i = 0 ; i < str.length() && balanced ; i++)    // for each character in the string
            {
                // if the character is an opening symbol, push it to the stack
                if (str[i] == '(' || str[i] == '{' || str[i] == '[') { push(str[i]) ; }

                else if (str[i] == ')')
                {
                    // if the top of the stack is not an opening parenthesis, the current index is the error
                    if (top() != '(') { indexOfError = i ; balanced = false ; }
                    else { pop() ; }
                }

                else if (str[i] == '}')
                {
                    // if the top of the stack is not an opening brace, the current index is the error
                    if (top() != '{') { indexOfError = i ; balanced = false ; }
                    else { pop() ; }
                }
                
                else if (str[i] == ']') 
                {
                    // if the top of the stack is not an opening bracket, the current index is the error
                    if (top() != '[') { indexOfError = i ; balanced = false ; }
                    else { pop() ; }
                }

                else if (str[i] == ';')     // if we have reached the end of a function 
                {
                    // if the end of the string is reached 
                    if (i + 1 == str.length()) { indexOfError = str.length() ; balanced = false ;}
                    // if the function is not closed with a brace
                    else if (str[i+1] != '}') { indexOfError = i + 1 ; balanced = false ; }
                }
            }
            // if no error is found but the stack is not empty, the error is at the end of the string
            if (indexOfError == -1 && stack.size() != 0) { indexOfError = str.length() ; }

            std::cout << std::endl << "Index of Error in string \"" << str << "\" : " ;
            return indexOfError ;  
        }

        // determine amount of parenthesis needed to make string valid
        void minPara(string str) 
        {
            empty() ;       // empty the stack

            int minNeeded = 0 ; 
            for (int i = 0 ; i < str.length() ; i++)    // for each character in the string
            {
                // if the character is an opening symbol, push it to the stack
                if (str[i] == '(' || str[i] == '{' || str[i] == '[') { push(str[i]) ; }

                else if (str[i] == ')' && top() == '(') { pop() ; }
                else if (str[i] == ')' && top() != '(')     // if the parenthesis do not match
                {
                    // if the incorrect symbol is towards the beginning of the string,
                    // remove the incorrect symbol from the stack and backtrack one index in traversal
                    if ( stack.size() > str.length() - i - 1) { minNeeded++ ; --i ; pop() ; }

                    // else if the incorrect symbol is towards the end of the string,
                    // continue traversal as normal
                }

                else if (str[i] == '}' && top() == '{') { pop() ; }
                else if (str[i] == '}' && top() != '{')
                {
                    if ( stack.size() > str.length() - i - 1) { minNeeded++ ; --i ; pop() ; }
                }

                else if (str[i] == ']' && top() == '[') { pop() ; }
                else if (str[i] == ']' && top() != '[') 
                {
                    if ( stack.size() > str.length() - i - 1) { minNeeded++ ; --i ; pop() ; }
                }
            }

            std::cout << std::endl << "Minimum amount needed to make string \"" << str << "\" valid: " ;
            // if elements remain in the stack,
            //the amount of elements remaining in the stack is the amount necessary to validate the string
            if (stack.size() != 0) { std::cout << stack.size() << std::endl ; } 
            else { std::cout << minNeeded << std::endl ; }
        }

        // calculate amount of valid parenthesis
        void scorePara(string str) 
        {
            empty() ;       // empty the stack

            int score = 0 ;
            for (int i = 0 ; i < str.length() ; i++)    // for each character in the string
            {
                if (str[i] == '(' || str[i] == '{' || str[i] == '[') { push(str[i]) ; }

                else if (str[i] == ')' && top() == '(') { score++ ; pop() ; }
                else if (str[i] == ')' && top() != '(') 
                {
                    // if the incorrect symbol is towards the beginning of the string,
                    // remove the incorrect symbol from the stack and backtrack one index in traversal
                    if ( stack.size() > str.length() - i - 1) { --i ; pop() ; }

                    // else if the incorrect symbol is towards the end of the string,
                    // continue traversal as normal
                }

                else if (str[i] == '}' && top() == '{') { score++ ; pop() ; }
                else if (str[i] == '}' && top() != '{') 
                {
                    if ( stack.size() > str.length() - i - 1) { --i ; pop() ; }
                }

                else if (str[i] == ']' && top() == '[') { score++ ; pop() ; }
                else if (str[i] == ']' && top() != '[') 
                {
                    if ( stack.size() > str.length() - i - 1) { --i ; pop() ; }
                }
            }
            std::cout << std::endl << "Score of string \"" << str << "\" : " << score 
            << std::endl ; 
        }

    private :
        std::vector<char> stack ;
} ;

// Add class Queue here
class Queue
{
    public :
        string reverse(string str) 
        {
            string reversedString = "" ;
            for (int i = str.length() - 1 ; i >= 0 ; i--)
            {
                reversedString += str[i] ; 
            }
            return reversedString ; 
        }

        bool isEmpty()
        {
            if (queue.size() == 0) { return true ; }
            else { return false ; }
        }

        void Insert(string str) { queue.push_back(str) ; }

        void Delete() { if (!isEmpty()) { queue.erase(queue.begin()) ; } }

        void enqueue(string str)
        {
            int i ;
            for (i = 0  ; i <= str.length()-8 ; i+=8)   // for each group of 8 characters 
            {
                // insert the reversed substring of 8 characters into the beginning of the queue
                Insert(reverse(str.substr(i , 8))) ; 
            }
            // if there are characters leftover, insert the reverse of the leftover characters
            if (str.length() - i != 0) { Insert(reverse(str.substr(i, str.length() - i))) ; }
        }

        void processMsg()
        {
            std::cout << std::endl ;
            string message = "" ;

            // while there are characters remaining in the queue
            while (!isEmpty())
            {
                message += reverse(queue.front()) ; // append the reversed (correct order) group to message string
                Delete() ;          // delete the group from the queue
            }
            std::cout << message << std::endl ;
        }

    private :
        std::vector<string> queue ; 
} ;

// Remove comments before testing and do not change anything in main function
int main(){
Stack s1;
s1.validPara("(([]))");
s1.minPara("(([]))");
s1.scorePara("(([]))");
s1.validPara("(([])");
std::cout<<s1.indexError("(([))")<<std::endl;
s1.minPara("(([])");
s1.validPara("(([{}))");
std::cout<<s1.indexError("(([[}])")<<std::endl;
s1.minPara("(([{}))");
s1.scorePara("(([{}))");
std::cout<<s1.indexError("({}[]()[)")<<std::endl;
s1.validPara("(([))");
s1.minPara("(([))");
std::cout<<s1.indexError("[({)]")<<std::endl;
s1.validPara("(([{[{({})}]}]))");
s1.minPara("(([{[{({})}]}]))");
s1.scorePara("(([{[{({})}]}]))");
s1.validPara("(([[{[{({})}]))");
s1.validPara("(([[{[{({})}]}])]))");
s1.scorePara("(([[{[{({})}]}])]))");
std::cout<<s1.indexError("(([[{{({})]}])]))")<<std::endl;
s1.validPara("(())");
s1.validPara("(())");
s1.validPara("void function(){}");
s1.scorePara("void function(){}");
s1.validPara("void function(");
s1.minPara("void function(");
s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
s1.scorePara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}");
s1.validPara("void function(std::string expre){if(expre){return 1;else{return 0;");
s1.minPara("void function(std::string expre){if(expre){return 1;else{return 0;");
std::cout<<s1.indexError("void function(std::string expre){if(expre){return 1;else{return 0;")<<std::endl;
Queue q1;
q1.enqueue("This is a secure message.");
q1.processMsg();
q1.enqueue("The product I received is damaged. What should I do?");
q1.processMsg();
q1.enqueue("I need assistance with setting up my new device");
q1.processMsg();
q1.enqueue("The website is not loading properly on my browser.");
q1.processMsg();
q1.enqueue("I accidentally placed the wrong order. Can it be canceled?");
q1.processMsg();
q1.enqueue("This is your project3. Have a happy thanksgiving!!! Hahaha");
q1.processMsg();
q1.enqueue("I forgot my password and can't reset it. Help, please! Do you provide technical support for mobile devices?");
q1.processMsg();
q1.enqueue("The software update is causing issues on my computer. The response time on your website is very slow.");
q1.processMsg();
return 0;
}