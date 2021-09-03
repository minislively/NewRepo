using System;

namespace Min
{
    public class Employee
    {
        public int No;
        public string Name;

        public Employee DeepCopy()
        {
            Employee employee = new Employee();
            employee.No = No;
            employee.Name = Name;

            return employee;
        }
    }
    public class MainApp
    {
        static void Main(string[] args)
        {
            Employee source = new Employee();
            source.No = 1;
            source.Name = "미미";

            Employee target = source.DeepCopy();
            target.No = 2;
            target.Name = "마마";

            Console.WriteLine(source.No + ", " + source.Name);
            Console.WriteLine(target.No + ", " + target.Name);
        }
    }
}