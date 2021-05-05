using System;
namespace TrafficDelegate
{

    public delegate string TrafficDel();
    class Program
    {
        static void Main(string[] args)
        {

            TrafficDel tDel;
            tDel = Red;
            //string temp = "";
            string curr_colour = tDel();
            Console.WriteLine("Signal is " + curr_colour);
            tDel = Yellow;
            curr_colour = tDel();
            Console.WriteLine("Signal is " + curr_colour);
            tDel = Green;
            curr_colour = tDel();
            Console.WriteLine("Signal is " + curr_colour);
            Console.ReadLine();

        }
        private static string Yellow()

        { 
              return "Yellow";
        }

        private static string Red()

        {
            return "Red";
        }

        private static string Green()
        {
            return "Green";
        }

    }

}