using System;

namespace BasicClass
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
    class MainApp
    {
        static void Main(string[] args)
        {
            Cat kitty = new Cat();
            kitty.color = "노란색";
            kitty.name = "키티";
            Console.WriteLine("{0}는 {1}이다.", kitty.name, kitty.color);

            Cat nero = new Cat();
            nero.color = "검은색";
            nero.name = "네로";
            Console.WriteLine("{0}는 {1}이다.", nero.name, nero.color);

        }
    }
}