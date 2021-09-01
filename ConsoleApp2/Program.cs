using System;

namespace BasicClass
{
    class Cat
    {
        public string Name;
        public string Color;
        public string Gender;

        public void Meow()
        {
            Console.WriteLine("{0} : 야옹", Name);
        }
    }
    class MainApp
    {
        static void Main(string[] args)
        {
            Cat kitty = new Cat();
            kitty.Color = "회색";
            kitty.Name = "키티";
            kitty.Gender = "여자";
            Console.WriteLine("{0} : {1} : {2}", kitty.Name, kitty.Gender, kitty.Color);

            Cat nero = new Cat();
            nero.Color = "검은색";
            nero.Name = "네로";
            nero.Gender = "남자";
            Console.WriteLine("{0} : {1} : {2}", nero.Name, nero.Gender, nero.Color);
        }
    }
}