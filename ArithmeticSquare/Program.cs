using System;
using System.Collections.Generic;
using System.Linq;

namespace ArithmeticSquare
{
    class Program
    {
        static void Main(string[] args)
        {
            ReadInput();
        }
        static void ReadInput()
        {
            int n = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                long[,] G = new long[3, 3];
                for (int j = 0; j < 3; j++)
                {
                    var x = Console.ReadLine().Split(' ');
                    if (j == 1)
                    {
                        G[j, 0] = long.Parse(x[0]);
                        G[j, 2] = long.Parse(x[1]);
                    }
                    else
                    {
                        G[j, 0] = long.Parse(x[0]);
                        G[j, 1] = long.Parse(x[1]);
                        G[j, 2] = long.Parse(x[2]);
                    }
                }
                int result = FindBestAM(G);
                System.Console.WriteLine($"Case #{i + 1}: {result}");
            }
        }
        static int FindBestAM(long[,] G)
        {
            int ans = 0;

            List<long> possibleValues = new List<long>();

            //Middle Row
            var middleRow = (G[1, 0] + G[1, 2]) / 2;
            possibleValues.Add(middleRow);

            //Middle Column
            var middleCol = (G[0, 1] + G[2, 1]) / 2;
            possibleValues.Add(middleCol);

            //Left Diagonal
            var leftDiagonal = (G[0, 0] + G[2, 2]) / 2;
            possibleValues.Add(leftDiagonal);

            //Right Diagonal
            var rightDiagonal = (G[2, 0] + G[0, 2]) / 2;
            possibleValues.Add(rightDiagonal);

            possibleValues.ForEach(x =>
            {
                G[1, 1] = x;
                int r = CountAM(G);
                ans = Math.Max(ans, r);
            });

            return ans;
        }
        static int CountAM(long[,] G)
        {
            int res = 0;

            for (int i = 0; i < 3; i++)
            {
                //Check For Rows
                if (2 * G[i, 1] == (G[i, 0] + G[i, 2]))
                {
                    res++;
                }

                //Check For Columns
                if (2 * G[1, i] == (G[0, i] + G[2, i]))
                {
                    res++;
                }
            }

            //Left Diagonal
            if (2 * G[1, 1] == (G[0, 0] + G[2, 2]))
            {
                res++;
            }

            //Right Diagonal
            if (2 * G[1, 1] == (G[2, 0] + G[0, 2]))
            {
                res++;
            }

            return res;
        }
    }
}