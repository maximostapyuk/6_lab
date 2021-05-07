#include"Property.h"

Property::Property() :name(""), priority(0) {}

Property::Property(string str, int index):name(str),priority(index){}

int Property::getPriority(){
	return this->priority;
}

void Property::setPriority(int index){
	this->priority = index;
}

string Property::getName(){
	return this->name;
}

void Property::setName(string name){
	this->name = name;
}

ostream& operator<<(ostream& out, Property property){
	out << setw(property.name.length()) << property.name << 
		" | " << setw(4) << property.priority << endl;
	return out;	// TODO: вставьте здесь оператор return
}

bool operator<(const Property& prop1, const Property& prop2){
	return prop1.priority< prop2.priority;
}

bool operator>(const Property& prop1, const Property& prop2){
	return prop1.priority > prop2.priority;
}
