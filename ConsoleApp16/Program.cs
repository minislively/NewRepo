using System;

namespace My
{
    public class Employee
    {
        public int no;
        public string name;

        public Employee DeepCopy()
        {
            Employee employee = new Employee();
            employee.no = no;
            employee.name = name;

            return employee; 
        }
    }
    public class MainApp
    {
        static void Main(string[] args)
        {
            Employee source = new Employee();
            source.no = 1;
            source.name = "미나";

            Employee target = source.DeepCopy();
            target.no = 2;
            target.name = "바다";

            Console.WriteLine(source.no + ", " + source.name);
            Console.WriteLine(target.no + ", " + target.name);
        }
    }
}