using System;

namespace Animal
{
    class Cat
    {
        public string name;
        public string color;

        public void Meow()
        {
            Console.WriteLine("{0} : 야옹", name);
        }
    }
    class Dog
    {
        public string name;
        public string color;

        public void Bark()
        {
            Console.WriteLine("{0} : 멍멍", name);
        }
    }
    class Tiger
    {
        public string name;
        public string color;

        public void Whoops()
        {
            Console.WriteLine("{0} : 어흥", name);
        }
    }
    class MainApp
    {
        static void Main(string[] args)
        {
            Cat kitty = new Cat();
            kitty.color = "하얀색";
            kitty.name = "키티";
            Console.WriteLine("{0} : {1}", kitty.name, kitty.color);
            kitty.Meow();

            Dog nero = new Dog();
            nero.color = "검은색";
            nero.name = "네로";
            Console.WriteLine("{0} : {1}", nero.name, nero.color);
            nero.Bark();

            Tiger any = new Tiger();
            any.color = "주황색";
            any.name = "애니";
            Console.WriteLine("{0} : {1}", any.name, any.color);
            any.Whoops();
        }
    }
}