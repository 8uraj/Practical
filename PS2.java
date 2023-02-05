class Student2 {
    int rollNo;
    String name;

    void getData(int r, String n) {
        rollNo = r;
        name = n;
    }

    void printData() {
        System.out.println("Roll Number: " + rollNo);
        System.out.println("Name: " + name);
    }

    public int getRollNo() {
        return rollNo;
    }

    public void setRollNo(int rollNo) {
        this.rollNo = rollNo;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public static void main(String[] args) {
        Student2 s1 = new Student2();
        Student2 s2 = new Student2();
        s1.getData(101, "John");
        s2.getData(102, "Jane");
        System.out.println("Student 1");
        s1.printData();
        System.out.println("Student 2");
        s2.printData();
    }
}
