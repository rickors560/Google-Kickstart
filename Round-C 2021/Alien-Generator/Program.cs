using System;

namespace Alien_Generator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Input number of test cases:");
            int t = Int32.Parse(Console.ReadLine());
            for (int i = 1; i <= t; i++)
            {
                long g = long.Parse(Console.ReadLine());
                Console.WriteLine($"Case #{i}: {GoldBarCheck(g)}");
            }
        }

        // G = n*k + n*(n-1)/2
        static long GoldBarCheck(long g)
        {
            long res = 0;
            //Getting factors of G and checking if i is a factor of G           // k = G/n + (n-1)/2  so check for modulus now here
            for (long i = 1; i * i <= g; i++)
            {
                if (g % i == 0)
                {
                    if (i != g / i)             //G will have two factors i.e., i and g/i
                    {
                        if (i % 2 != 0)
                        {
                            res += 1;
                        }
                        if ((g / i) % 2 != 0)
                        {
                            res += 1;
                        }
                    }

                    else
                    {
                        if (i % 2 != 0)
                        {
                            res += 1;
                        }
                    }
                }
            }
            return res;
        }
    }
}
