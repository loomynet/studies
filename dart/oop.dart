void main() {

  Address guyAddress = Address("123 Main St", "City", 12345);
  Person guy = Person("John", 25, address: guyAddress);
  
  Address studentAddress = Address("456 Elm St", "City", 54321);
  Student student = Student("Jane", 20, 84816, address: studentAddress);

  Address teacherAddress = Address("789 Oak St", "City", 98765);
  Teacher teacher = Teacher("Mr. Smith", 35, "Math", address: teacherAddress);
  
  Circle circle = Circle(5);
  Rectangle rectangle = Rectangle(5, 10);

  guy.introduce();
  guy.celebrateBirthday(2);
  print(guy._age);
  guy.age = -1;
  guy.age = 30;
  print(guy._age);

  student.introduce();
  teacher.introduce();

  print(circle.area());
  print(circle.perimeter());

  print(rectangle.area());
  print(rectangle.perimeter());

}

abstract class Shape {
  area();
  perimeter();
}

class Circle implements Shape {
  double pi = 3.14;
  double radius;
  
  Circle(this.radius);

  @override
  double area() {
    return pi * radius * radius;
  }
  
  @override
  double perimeter() {
    return 2 * pi * radius;
  }

}

class Rectangle implements Shape {
  double width;
  double length;

  Rectangle(this.width, this.length);
  
  @override
  double area() {
    return width * length;
  }
  @override
  double perimeter() {
    return 2 * (width + length);
  }
}

class Person {
  String name;
  int _age;
  Address address;

  Person(this.name, this._age, {required this.address});

  int get age => _age;

  set age(int age) {
    if(age > 0){
      _age = age;
    }
    else {
      print("Age must be greater than 0");
    }
  }

  void introduce() {
    print("Hello, i am a person!My name is $name and i am $_age years old, I live at $address.");
  }

  void celebrateBirthday(int number) {
    _age += number;
  }
}

class Address {
  String street;
  String city;
  int zipCode;

  Address(this.street, this.city, this.zipCode);

  @override
  String toString() {
    return "$street, $city, $zipCode";
  }
}

class Student extends Person {
  Student(String name, int age, this.studentID, {required Address address}) : super(name, age, address: address);

  int studentID;

  @override
  void introduce() {
    print("Hello, i am a student! My student ID is $studentID");
  }
}

class Teacher extends Person {
  Teacher(String name, int age, this.subject, {required Address address}) : super(name, age, address: address);

  String subject;

  @override
  void introduce() {
    print("Hello, i am a teacher! My subject is $subject");
  }
}