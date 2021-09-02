using System;

namespace My
{
    class Dog
    {
        public string name;
        public string gender;
        public string ownernames;

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
            dog.name = "칸";
            dog.gender = "남";
            dog.ownernames = "민희";

            dog.Bark();

            Console.WriteLine("개의 이름 : {0}, 개의 성별 : {1}, 개의 주인이름 : {2}", dog.name, dog.gender, dog.ownernames);

        }
    }

}