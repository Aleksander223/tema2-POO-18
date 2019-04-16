#include <iostream>
#include <string>
#include <list>

class Person{
protected:
    int id;
    std::string name;
public:
    Person(){
        id = -1;
        name = "\0";
    }

    Person(int i, std::string s){
        id = i;
        name = s;
    }

    // copy
    Person(const Person& p){
        id = p.id;
        name = p.name;
    }

    ~Person(){

    }

    Person& operator=(Person &p){
        if(id == p.id)
            return *this;

        id = p.id;
        name = p.name;

        return *this;
    }

    std::string getName(){
        return name;
    }

    // friend functions
    friend std::istream& operator>>(std::istream&, Person&);
    friend std::ostream& operator<<(std::ostream&, Person);

};

std::istream& operator>>(std::istream& is, Person& p){
    is>>p.id>>p.name;
    return is;
}

std::ostream& operator<<(std::ostream& os, Person p){
    os<<p.id<<" \t"<<p.name;
    return os;
}

class Subscriber:public Person{
protected:
    std::string phoneNumber;
public:
    Subscriber(): Person(){
        phoneNumber = "\0";
    }

    Subscriber(int i, std::string s, std::string nr): Person(i, s){
        phoneNumber = nr;
    }

    // copy constructor
    Subscriber(const Subscriber& s): Person(s){
        phoneNumber = s.phoneNumber;
    }

    ~Subscriber(){

    }

    Subscriber& operator=(Subscriber &p){
        if(id == p.id)
            return *this;

        Person::operator=(p);
        phoneNumber = p.phoneNumber;

        return *this;
    }

    // friend functions
    friend std::istream& operator>>(std::istream&, Subscriber&);
    friend std::ostream& operator<<(std::ostream&, Subscriber);
};

std::istream& operator>>(std::istream& is, Subscriber& s){
    is>>s.id>>s.name>>s.phoneNumber;
    return is;
}

std::ostream& operator<<(std::ostream& os, Subscriber s){
    os<<s.id<<" \t"<<s.name<<" \t"<<s.phoneNumber;
    return os;
}

class SkypeSubscriber:public Subscriber{
protected:
    int skypeID;
public:
    SkypeSubscriber(): Subscriber(){
        skypeID = -1;
    }

    SkypeSubscriber(int i, std::string nm, std::string pn, int sID): Subscriber(i, nm, pn){
        skypeID = sID;
    }

    // copy

    SkypeSubscriber(const SkypeSubscriber& s): Subscriber(s){
        skypeID = s.skypeID;
    }

    ~SkypeSubscriber(){

    }

    SkypeSubscriber& operator=(SkypeSubscriber &p){
        if(id == p.id)
            return *this;

        Subscriber::operator=(p);
        skypeID = p.skypeID;

        return *this;
    }

    // friend functions
    friend std::istream& operator>>(std::istream&, SkypeSubscriber&);
    friend std::ostream& operator<<(std::ostream&, SkypeSubscriber);
};

std::istream& operator>>(std::istream& is, SkypeSubscriber& s){
    is>>s.id>>s.name>>s.phoneNumber>>s.skypeID;
    return is;
}

std::ostream& operator<<(std::ostream& os, SkypeSubscriber s){
    os<<s.id<<" \t"<<s.name<<" \t"<<s.phoneNumber<<" \t"<<s.skypeID;
    return os;
}

class SkypeSubscriber_Romania: public SkypeSubscriber{
private:
    std::string email;
public:
    SkypeSubscriber_Romania(): SkypeSubscriber(){
        email = "\0";
    }

    SkypeSubscriber_Romania(int i, std::string nm, std::string pn, int sID, std::string em): SkypeSubscriber(i, nm, pn, sID){
        email = em;
    }

    // copy
    SkypeSubscriber_Romania(const SkypeSubscriber_Romania& s): SkypeSubscriber(s){
        email = s.email;
    }

    ~SkypeSubscriber_Romania(){

    }

    SkypeSubscriber_Romania& operator=(SkypeSubscriber_Romania &p){
        if(id == p.id)
            return *this;

        SkypeSubscriber::operator=(p);
        email = p.email;

        return *this;
    }

    // friend functions
    friend std::istream& operator>>(std::istream&, SkypeSubscriber_Romania&);
    friend std::ostream& operator<<(std::ostream&, SkypeSubscriber_Romania);
};

std::istream& operator>>(std::istream& is, SkypeSubscriber_Romania& s){
    is>>s.id>>s.name>>s.phoneNumber>>s.skypeID>>s.email;
    return is;
}

std::ostream& operator<<(std::ostream& os, SkypeSubscriber_Romania s){
    os<<s.id<<" \t"<<s.name<<" \t"<<s.phoneNumber<<" \t"<<s.skypeID<<" \t"<<s.email<<" \t";
    return os;
}

class SkypeSubscriber_Extern: public SkypeSubscriber{
private:
    std::string country;
public:
    SkypeSubscriber_Extern(): SkypeSubscriber(){
        country = "\0";
    }

    SkypeSubscriber_Extern(int i, std::string nm, std::string pn, int sID, std::string em): SkypeSubscriber(i, nm, pn, sID){
        country = em;
    }

    // copy
    SkypeSubscriber_Extern(const SkypeSubscriber_Extern& s): SkypeSubscriber(s){
        country = s.country;
    }

    ~SkypeSubscriber_Extern(){

    }

    SkypeSubscriber_Extern& operator=(SkypeSubscriber_Extern &p){
        if(id == p.id)
            return *this;

        SkypeSubscriber::operator=(p);
        country = p.country;

        return *this;
    }

    // friend functions
    friend std::istream& operator>>(std::istream&, SkypeSubscriber_Extern&);
    friend std::ostream& operator<<(std::ostream&, SkypeSubscriber_Extern);
};

std::istream& operator>>(std::istream& is, SkypeSubscriber_Extern& s){
    is>>s.id>>s.name>>s.phoneNumber>>s.skypeID>>s.country;
    return is;
}

std::ostream& operator<<(std::ostream& os, SkypeSubscriber_Extern s){
    os<<s.id<<" \t"<<s.name<<" \t"<<s.phoneNumber<<" \t"<<s.skypeID<<" \t"<<s.country<<" \t";
    return os;
}

class Agenda{
private:
    std::list<Subscriber> contacts;
public:
    Agenda(){

    }

    ~Agenda(){

    }

    void addContact(Subscriber s){
        contacts.push_back(s);
    }

    Subscriber& operator[](std::string search){
        for(auto &it: contacts){
            if(it.getName() == search){
                return it;
            }
        }
    }
};

int main(){
    return 0;
}
