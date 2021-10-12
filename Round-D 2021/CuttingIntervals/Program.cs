using System;
using System.Collections.Generic;
using System.Linq;

namespace Cuttinglongervals
{
    class Program
    {
        static void Main(string[] args)
        {
            Solve();
        }
        static void Solve()
        {
            long t = long.Parse(Console.ReadLine());
            for (long i = 0; i < t; i++)
            {
                var x = Console.ReadLine().Split(' ');
                long N = long.Parse(x[0]);
                long C = long.Parse(x[1]);

                long[] Left = new long[N];
                long[] Right = new long[N];
                for (long j = 0; j < N; j++)
                {
                    x = Console.ReadLine().Split(' ');
                    Left[j] = long.Parse(x[0]);
                    Right[j] = long.Parse(x[1]);
                }

                Array.Sort(Left);
                Array.Sort(Right);

                var result = CalculateCuts(Left, Right, C);
                var res = $"Case #{i + 1}: " + result;
                Console.WriteLine(res);
            }

        }

        public static long CalculateCuts(long[] left, long[] right, long c)
        {
            var longervalsMap = new Dictionary<long, long>();
            for (long i = 0; i < left.Length; i++)
            {
                if (!longervalsMap.ContainsKey(left[i] + 1))
                {
                    longervalsMap.Add(left[i] + 1, 1);
                }
                else
                {
                    longervalsMap[left[i] + 1] += 1;
                }

                if (!longervalsMap.ContainsKey(right[i]))
                {
                    longervalsMap.Add(right[i], -1);
                }
                else
                {
                    longervalsMap[right[i]] -= 1;
                }
            }
            Console.WriteLine();
            var longervalPolongs = longervalsMap.Keys.ToList();
            longervalPolongs.Sort();

            long prefixSum = 0;
            foreach (long x in longervalPolongs)
            {
                longervalsMap[x] += prefixSum;
                prefixSum = longervalsMap[x];
            }

            // Dictionary<{longervals_after_cut},{no_of_polongs_on_cut_can_be_done}>
            var longervalWithNoOfPolongs = new List<long[]>();

            for (long i = 0; i < longervalPolongs.Count; i++)
            {
                if (i + 1 < longervalPolongs.Count)
                {
                    longervalWithNoOfPolongs.Add(
                        new long[]
                        {
                        longervalsMap[longervalPolongs[(int)i]],
                        longervalPolongs[(int)(i + 1)] - longervalPolongs[(int)i]
                        }
                    );
                }
            }
            var res = longervalWithNoOfPolongs.OrderBy(x => x[0]).Reverse().ToList();

            long result = 0;

            foreach (var item in res)
            {
                if (c <= 0)
                    break;

                if (c > item[1])
                {
                    result += item[0] * item[1];
                    c -= item[1];
                }
                else
                {
                    result += item[0] * c;
                    c = 0;
                }
            }

            return result + left.Length;
        }
    }
}
