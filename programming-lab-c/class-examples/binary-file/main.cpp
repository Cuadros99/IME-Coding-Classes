#include <iostream>
#include <fstream>

using namespace std;

class Student {
  string name;
  int age;
public:
  Student(string name, int age): name(name), age(age) {}
  Student(): name(""), age(0) {}
  void print() {
    cout << name << " - " << age << endl;
  }
  void write_to(ofstream& file) {
    int name_size = name.size();
    file.write((char*) &name_size, sizeof(int));
    file.write(name.c_str(), name_size + 1);
    file.write((char*) &age, sizeof(int));
  }
  static Student* read_from(ifstream& file) {
    int name_size;
    int age;
    char* c_str = new char[name_size + 1];
    file.read((char*) &name_size, sizeof(int));
    file.read(c_str, name_size+1);
    file.read((char*) &age, sizeof(int));
    string name(c_str);
    delete[] c_str;
    return new Student(name, age);
  }
};

int main() {

  Student sd1("Cuadros", 23);
  Student sd2("Brectihick", 24);
  Student sd3("Andrade", 19);

  ofstream ofs("output.bin", ios::out | ios::binary);

  if(!ofs.is_open()) { 
    cout << "Erro" << endl;
    return 1;}

  // ofs.write((char *) &sd1, sizeof(Student));
  // ofs.write((char *) &sd2, sizeof(Student));
  // ofs.write((char *) &sd3, sizeof(Student));
  sd1.write_to(ofs);
  sd2.write_to(ofs);
  sd3.write_to(ofs);

  ofs.close();

  sd1.print();
  sd2.print();
  sd3.print();


  return 0;
}