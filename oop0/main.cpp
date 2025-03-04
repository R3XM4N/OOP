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
        string name;
        Person sender;
        Person reciever;
        Document(){};
        Document(string docName, Person docSender,Person docReciever, string docContent){
            sender = docSender;
            reciever = docReciever;
            content = docContent;
            name= docName;
        }
        string GetContent(){
            return content;
        }
        string GetWhole(){
            string temp;
            temp = "Sender: " + sender.name + " " + sender.surname + "\n";
            temp += "Reciever: " + reciever.name + " " + reciever.surname + "\n";
            temp += "Content " + GetContent() + "\n";
            return temp;
        }
    private:
        string content;
};

class Email{
    public:
        Person owner;
        string eName;
        string domain;
        Email(){};
        Email(Person emailOwner,string emailName, string emailDomain){
            owner = emailOwner;
            eName = emailName;
            domain = emailDomain;
        }
        string GetFullName(){
            return eName + "@" + domain;
        }
        void RecieveDoc(Document recieveDoc){
            this->recievedDocs.push_back(recieveDoc);
        }
    private:
         vector<Document> recievedDocs;
};

void SendDoc(string docName, Person sender, Email recieverEmail, string content ){
    Document tempDoc(docName,sender,recieverEmail.owner,content);
    recieverEmail.RecieveDoc(tempDoc);
}

vector<Email> emails;

void PrintAllMails(){
    for (int i = 0; i < emails.size(); i++)
    {
        cout << "Mail: " << emails[i].GetFullName() << "    User: " << emails[i].owner.name << " "<< emails[i].owner.surname << "\n";
    }
    
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
            cout << "add - sets into add mode enabling to add a email\n";
            cout << "del - sets into delete mode enabling the deletion of a email\n";
            cout << "\e[1;34m   Utility:    \e[0m\n";
            cout << "ls - lists all emails\n";
        }
        else if (command == "msg"){
            cout << "\e[1;33mEnter target mail 'name@domain'.\e[0m\n";
            if (cin >> command)
            {
                for (int i = 0; i < emails.size(); i++)
                {
                    if (emails[i].GetFullName() == command)
                    {
                        
                    }
                    else if (i == emails.size()-1)
                    {
                        /* code */
                    }
                    
                }
            }
            
        }
        else if (command == "add"){
            Person temp;
            cout << "\e[1;33mEnter user and mail info.\e[0m\n";
            cout << "Name:   Surname:\n";
            if (cin >> temp.name >> temp.surname)
            {
                Email tempMail;
                cout << "Mail name:     domain:\n";
                if (cin >> tempMail.eName >> tempMail.domain)
                {
                    tempMail.owner = temp;
                    emails.push_back(tempMail);
                    cout << "\e[1;33mSuccessfully added "<< tempMail.GetFullName() << "\e[0m\n";
                }
            }
        }
        else if (command == "del")
        {
            cout << "\e[1;31mType a mail you wish to delete: as 'emailname@domain' or exit via exit.\e[0m\n";
            if (cin >> command)
            {
                if (command == "exit")
                {
                    cout << "\e[1;31mDelete operation exited.\e[0m\n";
                }
                else                
                {
                    for (int i = 0; i < emails.size(); i++)
                    {
                        if (emails[i].GetFullName() == command)
                        {
                            if (i + 1 == emails.size())
                            {
                                emails.pop_back();
                            }
                            else{
                                emails[i] = emails[emails.size()-1];
                                emails.pop_back();
                            }
                        }
                    }
                }
            }
        }

        else if (command == "ls"){
            PrintAllMails();
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