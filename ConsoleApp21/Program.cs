using System;

namespace Microsoft
{
    class MainApp
    {
        delegate void TestDelegate<T>(T a, T b);
        static TestDelegate<int> Lamda;

        static void Main(string[] args)
        {
            Lamda += (int a, int b) => Console.WriteLine(a + b);
            Lamda(1, 2);
            Console.ReadKey();
        }
        static public void TLamda(int a, int b)
        {
            Console.WriteLine(a + b);
        }
    }
}