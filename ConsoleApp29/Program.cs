using System;

namespace Min
{
    public class Employee
    {
        public int No;
        public string name;

        public Employee DeepCopy()
        {
            Employee employee = new Employee();
            employee.No = No;
            employee.name = name;

            return employee;
        }
    }
    public class MainApp
    {
        static void Main(string[] args)
        {
            Employee source = new Employee();
            source.No = 1;
            source.name = "바비";

            Employee target = source.DeepCopy();
            target.No = 2;
            target.name = "선미";

            Console.WriteLine(source.No + ", " + source.name);
            Console.WriteLine(target.No + ", " + target.name);
        }
    }
}