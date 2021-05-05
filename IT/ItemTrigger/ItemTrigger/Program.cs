using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ItemTrigger
{
    class Item
    {
        public delegate void priceChangedEvenHandler(int price);
        public event priceChangedEvenHandler PriceChanged;
        private int price;
        private string name;
        public int Price
        {
            get { return price; }
            set
            {
                if (value > 0)
                {
                    price = value;
                    if (PriceChanged != null)
                        PriceChanged(value);
                }
            }
        }

        public string Name { get; set; }
    }
    class Q1
    {
        private static void printNewPrice(int price)
        {
            Console.WriteLine("[Event Handler] Price Changed to : " + price);
        }

        static void Main()
        {
            int price;
            Console.Write("Enter Price: ");
            Item p = new Item();
            p.PriceChanged += printNewPrice;
            int.TryParse(Console.ReadLine(), out price);
            p.Price = price;
            Console.WriteLine("[Main] Price updated");
            Console.Read();
        }
    }
}

