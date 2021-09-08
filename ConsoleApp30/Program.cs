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
    class Dog
    {
        public string name;
        public string color;

        public void Bark()
        {
            Console.WriteLine("{0} : 멍멍", name);
        }
    }
    class MainApp
    {
        static void Main(string[] args)
        {
            Cat Kitty = new Cat();
            Kitty.name = "키티";
            Kitty.color = "분홍색";

            Dog Moo = new Dog();
            Moo.name = "무";
            Moo.color = "갈색";

            Console.WriteLine("{0}의 색깔은 {1}입니다.",Kitty.name,Kitty.color);
            Console.WriteLine("{0}의 색깔은 {1}입니다.",Moo.name, Moo.color);
        }
    }
}