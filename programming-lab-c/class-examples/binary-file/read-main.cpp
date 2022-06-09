#include <iostream>
#include <fstream>

using namespace std;

class Student {
  string name;
  int age;
public:
  Student(string name, int age): name(name), age(age) {}
  Student(): name(""), age(0) {}
  Student(const Student &sd) {
    name = sd.name;
    age = sd.age;
  }
  void print() {
    cout << name << " - " << age << endl;
  }
  void getName() {
    cout << name << endl;
  }
  void write_to(ofstream& file) {
    int name_size = name.size();
    file.write((char*) &name_size, sizeof(int));
    file.write(name.c_str(), name_size + 1);
    file.write((char*) &age, sizeof(int));
  }
  static Student read_from(ifstream& file) {
    int name_size;
    int age;
    char* c_str = new char[name_size + 1];
    file.read((char*) &name_size, sizeof(int));
    file.read(c_str, name_size+1);
    file.read((char*) &age, sizeof(int));
    string name(c_str);
    delete[] c_str;
    return Student(name, age);
  }
};

int main() {

  // Student *list;

  // list = new Student[3];

  ifstream ifs("output.bin", ios::in | ios::binary);

  if(!ifs.is_open()) { 
    cout << "Erro" << endl;
    return 1;
  }

  Student sd1 = Student::read_from(ifs);
  Student sd2 = Student::read_from(ifs);
  Student sd3 = Student::read_from(ifs);

  // ifs.read((char *) &list[0], sizeof(Student));
  // ifs.read((char *) &list[1], sizeof(Student));
  // ifs.read((char *) &list[2], sizeof(Student));

  ifs.close();

  // list[0].print();
  // list[1].print();
  // list[2].print();

  sd1.print();
  sd2.print();
  sd3.print();

  return 0;
}