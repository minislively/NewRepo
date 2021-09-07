using System;

namespace Min
{
    public class Employee
    {
        public int No;
        public string name;
        public string gender;

        public Employee DeepCopy()
        {
            Employee employee = new Employee();
            employee.No = No;
            employee.name = name;
            employee.gender = gender;

            return employee;
        }
    }
    public class MainApp
    {
        static void Main(string[] args)
        {
            Employee source = new Employee();
            source.No = 1;
            source.name = "나미";
            source.gender = "여자";

            Employee target = source.DeepCopy();
            target.No = 2;
            target.name = "지수";
            target.gender = "남자";

            Console.WriteLine("{0}는 {1}이고, {2}입니다.", source.name, source.No, source.gender);
            Console.WriteLine("{0}는 {1}이고, {2}입니다.",target.name,target.No,target.gender);
        }
    }
}