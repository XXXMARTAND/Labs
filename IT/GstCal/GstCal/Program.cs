using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GstCal
{
    class Item
    {
        public string Name { get; set; }

        private int cost;
        public int Cost
        {
            get { return cost; }
            set
            {
                if (value > 0)
                    cost = value;
            }
        }

        public double GST()
        {
            return 0.08 * cost;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Item i = new Item();
            int cost;
            Console.WriteLine("Enter Item name");
            i.Name = Console.ReadLine();
            Console.WriteLine("Enter the cost");
            int.TryParse(Console.ReadLine(), out cost);
            i.Cost = cost;
            Console.WriteLine("\nItem Name: " + i.Name +
                "\nCost: " + i.Cost +
                "\nGST(8%): " + i.GST() +
                "\n\nTotal: " + (i.Cost + i.GST()));

            Console.Read();
        }
    }
}
