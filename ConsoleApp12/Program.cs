using System;
using System.IO;

namespace Interface
{
    interface ILooger
    {
        void WriteLog(string message);
    }
    class ConsoleLogger : ILooger
    {
        public void WriteLog(string message)
        {
            Console.WriteLine("{0} {1}", DateTime.Now.ToLocalTime(), message);
        }
    }
    class FileLogger : ILooger
    {
        private StreamWriter writer;

        public FileLogger(string path)
        {
            writer = File.CreateText(path);
            writer.AutoFlush = true;

        }
        public void WriteLog(string message)
        {
            writer.WriteLine("{0} {1}", DateTime.Now.ToShortDateString(), message);
        }
    }
    class ClimateMonitor
    {
        private ILooger looger;
        public ClimateMonitor(ILooger looger)
        {
            this.looger = looger;
        }
        public void start()
        {
            while(true)
            {
                Console.Write("온도를 입력해주세요 : ");
                string temperature = Console.ReadLine();
                if (temperature == "")
                    break;
                looger.WriteLog("현재 온도 : " + temperature);
            }
        }
    }
    class MainApp
    {
        static void Main(string[] args)
        {
            ClimateMonitor monitor = new ClimateMonitor(new FileLogger("MyLog.txt"));
            monitor.start();
        }

    }
}