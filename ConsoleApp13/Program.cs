using System;

namespace Min
{
    class Dog
    {
        public string name;
        public string gender;

        public void Bark()
        {
            Console.WriteLine("{0} : 멍멍!", name);
        }
    }
    class MainApp
    {
        static void Main(string[] args)
        {
            Dog dog = new Dog();
            dog.name = "무무";
            dog.gender = "여자";

            dog.Bark();
            Console.WriteLine("{0} : {1}", dog.name, dog.gender);
        }
    }
}