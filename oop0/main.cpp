#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Person{
    public:
        string name;
        string surname;
        string FullName(){
            return name + " "+ surname;
        }
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
            return "Sender: " + sender.FullName() + "\n" + "Reciever: " + reciever.FullName() + "\n" + "Content " + GetContent() + "\n";
        }
        void SetContent(string content_){
            this->content = content_;
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
        vector<Document> recievedDocs;
        /* We ain't making actual sw here ¯\_(ツ)_/¯ acces modifiers who?
    private:
         vector<Document> recievedDocs;
        */
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
    //not good but neither bad, simple app running this is ok.
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
            cout << "ls - lists all email adresses saved in the system\n";
            cout << "hell - Writes all doccuments from each email adress so hell\n";
        }
        //maybe doesn't work? Needs to be tested. Well tested and all seems to work ¯\_(ツ)_/¯
        else if (command == "msg" || command == "send"){
            cout << "\e[1;33mEnter target mail 'name@domain'.\e[0m\n";
            if (cin >> command)
            {
                for (int i = 0; i < emails.size(); i++)
                {
                    if (emails[i].GetFullName() == command)
                    {
                        Document tempdoc;
                        tempdoc.reciever = emails[i].owner;
                        cout << "\e[1;33mSenders name:\e[0m\n";
                        cin >> tempdoc.sender.name;
                        cout << "\e[1;33mSenders surname:\e[0m\n";
                        cin >> tempdoc.sender.surname;
                        cout << "\e[1;33mContent/message header:\e[0m\n";
                        cin >> tempdoc.name;
                        cout << "\e[1;33mContents of message:\e[0m\n";
                        cin >> command; tempdoc.SetContent(command);
                        emails[i].RecieveDoc(tempdoc);
                        break;
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
        else if (command == "del" || command == "delete")
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
                                cout << "\e[1;31mSuccesfully removed " + command + ".\e[0m\n";
                                break;
                            }
                            else{
                                //So apparently .erase is a thing
                                emails[i] = emails[emails.size()-1];
                                emails.pop_back();
                                cout << "\e[1;31mSuccesfully removed " + command + ".\e[0m\n";
                                break;
                            }
                            
                        }
                        cout << "\e[1;31mDidn't find " + command + ".\e[0m\n";
                    }
                }
            }
        }

        else if (command == "ls"){
            PrintAllMails();
        }
        else if (command == "cl" || command == "clear"){
            cout << "\033[2J\033[1;1H";
        }
        else if (command == "hell"){
            for (int i = 0; i < emails.size(); i++)
            {
                for (int y = 0; y < emails[i].recievedDocs.size(); y++)
                {
                    cout << emails[i].recievedDocs[y].GetWhole() << "\n";
                }
            }
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