using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DateTime1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter Date Time");
            string a = Console.ReadLine();
            CultureInfo provider = CultureInfo.InvariantCulture;
            DateTime d1;
            int[] temp = new int[6];
            String[] temp1 = a.Split(':');
            int i = 0;
            foreach(string str in temp1)
            {
                int.TryParse(str,out temp[i++]);
            }

            d1 = new DateTime(temp[2], temp[1], temp[0], temp[3], temp[4], temp[5]);
            Console.WriteLine("Enter the number of ticks");
            string b = Console.ReadLine();
            int n;
            int.TryParse(b, out n);
            TimeSpan t = new TimeSpan(n);
            
            DateTime d2 = d1.Add(t);
            
            Console.WriteLine("The new Date Time is {0}",d2.ToString("hh:mm:ss"));
            Console.Read();


        }
    }
}
