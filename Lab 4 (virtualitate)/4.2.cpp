/* Să se implementeze codul aferent claselor ale căror date membre urmăresc diagrama UML de mai jos. Nu se va folosi mecanismul funcțiilor/claselor friend.

Entity:
# name: std::string

Person (public to Entity):
# age: int

Student (public to Person):
- serie: char

Clasele se vor completa cu funcționalitățile necesare astfel încât codul dat în funcția main să întoarcă următoarea secvență de mesaje:
Ctor Entity
Ctor Entity
Ctor Person
Ctor Entity
Ctor Person
Ctor Student

Entity name: Entity 1
Person name: Person 1
Person age: 34
Student name: Student 1
Student age: 21
Student serie: B */

#include <iostream>
#include <string>
#include <limits>

// TODO: adaugati clasele aici

//Clasa de Baza
class Entity{
    
    //Date membre
    protected:
        std::string name;
    
    //Consctructor
    public:
        
        //Constructor Gol
        Entity(){}
        
        //Constructor cu Lista de Initializare
        Entity(std::string name): name(name){
            //Afiseaza asta la apelarea constructorului
            std::cout<<"Ctor Entity"<<std::endl;
        }
    
    //Functii
    public:
    
        //VIRTUAL o sa fie transmis si la restul si SUPRASCRIE
        virtual void display(){
            std::cout<<"Entity name: "<<name<<std::endl;
        }
    
};


//Clasa Derivata
class Person:public Entity{
    
    //Date membre
    protected:
        int age;
    
    //Consctructor
    public:
        
        //Constructor Gol
        Person(){}
        
        //Constructor cu Lista de Initializare
        Person(std::string name, int age): Entity(name), age(age){
            //Afiseaza asta la apelarea constructorului + ce este in constructor BAZA
            std::cout<<"Ctor Person"<<std::endl;
        }
    
    //Functii
    public:
        void display(){
            std::cout<<"Person name: "<<name<<std::endl;
            std::cout<<"Person age: "<<age<<std::endl;
        }
    
};

//Clasa Derivata din Derivata
class Student:public Person{
    
    //Date membre
    protected:
        char serie;
    
    //Consctructor
    public:
        
        //Constructor Gol
        Student(){}
        
        //Constructor cu Lista de Initializare
        Student(std::string name, int age, char serie): Person(name, age), serie(serie){
            //Afiseaza asta la apelarea constructorului + ce este in constructor BAZA si DERIVATA
            std::cout<<"Ctor Student"<<std::endl;
        }
    
    //Functii
    public:
    
        void display(){
            std::cout<<"Student name: "<<name<<std::endl;
            std::cout<<"Student age: "<<age<<std::endl;
            std::cout<<"Student serie: "<<serie<<std::endl;
        }

    
};


int main(){
    Entity e1("Entity 1");
    Person p1("Person 1", 34);
    Student s1("Student 1", 21, 'B');

    std::cout << std::endl;

    Entity *p_entity[3] = {&e1, &p1, &s1};
    for (int i=0; i<3; i++){
        p_entity[i]->display();
    }
    

    return 0;
}
