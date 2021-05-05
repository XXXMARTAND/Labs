using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArithmeticOps
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter first number");
            
            string sa = Console.ReadLine();
            Console.WriteLine("Enter second number");
            string sb = Console.ReadLine();
            int a, b;
            int.TryParse(sa, out a);
            int.TryParse(sb, out b);

            int sum = a + b;
            int sub = a - b;
            int mul = a * b;
            float div = (float)a / (float)b;
            //int rem = a % b;

            Console.WriteLine("Addition of {0} and {1} is = {2}", a, b, sum);
            Console.WriteLine("Subtraction of {0} and {1} is = {2}", a, b, sub);
            Console.WriteLine("Multiplication of {0} and {1} is = {2}", a, b, mul);
            Console.WriteLine("Division of {0} and {1} is = {2}", a, b, div);
            //Console.WriteLine("Remainder of {0} and {1} is = {2}", a, b, rem);

            //hit ENTER to exit the program
            Console.ReadLine();
        }
    }
}
