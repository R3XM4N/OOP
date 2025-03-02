#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Person{
    public:
        string name;
        string surname;
        Person(){};
        Person(string usersName,string usersSurname){
            name = usersName;
            surname = usersSurname;
        }
};

class Document{
    public:
        Person sender;
        Person reciever;
        Document(){};
        Document(Person docSender,Person docReciever, string docContent){
            sender = docSender;
            reciever = docReciever;
            content = docContent;
        }
        string GetContent(){
            return content;
        }
    private:
        string content;
};

class Email{
    public:
        Person owner;
        string eName;
        string domain;
        vector<Document> recievedDocs;
        Email(){};
        Email(Person emailOwner,string emailName, string emailDomain){
            owner = emailOwner;
            eName = emailName;
            domain = emailDomain;
        }
        string GetFullName(){
            return eName + "@" + domain;
        }
};

void PrintDocAll(Document doc){
    cout << "Sender: " << doc.sender.name << " " << doc.sender.surname << "\n";
    cout << "Reciever: " << doc.reciever.name << " " << doc.reciever.surname << "\n";
    cout << "Content " << doc.GetContent() << "\n";
}

void SendDoc(Person sender ){
    
}

int main(){
    cout << "\033[2J\033[1;1H";
    cout << "\e[1;32mObject oriented programing Doc/Email/Person class example. \nAlso doubling as a proof of concept of a terminal tool in C++.\e[0m\n";
    string command;
    while(cin >> command){
        if (command == "help"){
            cout << "\033[2J\033[1;1H";
            cout << "\e[1;34m   Basic commands:    \e[0m\n";
            cout << "help - displays this message\n";
            cout << "exit - exits the process\n";
            cout << "cl - clears command line\n";
            cout << "\e[1;34m   Mode commands:    \e[0m\n";
            cout << "msg - sets into message mode enabling to send a 'document'\n";
            cout << "add - sets into add mode enabling to add a user or email\n";
        }
        else if (command == "msg"){

        }
        else if (command == "add"){
            
        }
        else if (command == "cl"){
            cout << "\033[2J\033[1;1H";
        }
        else if (command == "exit"){
            cout << "\033[2J\033[1;1H";
            cout << "\e[1;33mProcess exited via exit command.\e[0m\n";
            break;
        }
        else {
            cout << "\e[1;33mInvalid command: " << command << " \e[0m\n";
        }
    }
    return 0;
}