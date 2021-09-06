using System;

namespace BasicClass
{
    class Dog
    {
        public string name;
        public string gender;
        public string color;

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
            dog.name = "미미";
            dog.gender = "여자";
            dog.color = "회색";

            dog.Bark();
            Console.WriteLine("개의 이름 : {0}. 개의 성별 : {1}, 개의 색깔 : {2}", dog.name, dog.gender, dog.color);
        }
    }
}