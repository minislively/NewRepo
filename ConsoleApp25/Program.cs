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
    class Cat
    {
        public string name;
        public string gender;
       
        public void Meow()
        {
            Console.WriteLine("{0} : 야옹!", name);
        }
    }
    class MainApp
    {
        static void Main(string[] args)
        {
            Dog dog = new Dog();
            dog.name = "칸";
            dog.gender = "남자";

            dog.Bark();
            Console.WriteLine("{0}은 {1}입니다.", dog.name,dog.gender);
            
            Cat cat = new Cat();
            cat.name = "키티";
            cat.gender = "여자";

            cat.Meow();
            Console.WriteLine("{0}는 {1}입니다.",cat.name,cat.gender);
        }
    }
}