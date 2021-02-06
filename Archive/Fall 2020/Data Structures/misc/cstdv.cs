using System;

namespace StandardDeviation
{
    class Program
    {
        static void Main(string[] args)
        {
            /* INITIALIZING THE SET */
            Console.Write("How many numbers are in the set?: ");
            int setlengthinput = Convert.ToInt32(Console.ReadLine());
            double[] numSet = new double[setlengthinput];

            for (int i = 0; i < numSet.Length; i++)
            {
                Console.Write("Enter a number: ");
                numSet[i] = Convert.ToInt32(Console.ReadLine());
            }

            /* CALCULATES THE MEAN */
            double sumofset = 0;
            foreach(int x in numSet)
            {
                sumofset += x;
            }
            double mean = sumofset / numSet.Length;
            Console.WriteLine("Mean = {0}", mean);

            /* FIND DISTANCE TO MEAN AND SQUARE IT */
            double[] distToMean = new double[numSet.Length];
            double[] distToMeanSQRD = new double[numSet.Length];
            for (int i = 0; i < numSet.Length; i++)
            {
                if (numSet[i] > mean)
                {
                    double dist = (Convert.ToDouble(numSet[i]) - mean);
                    distToMean[i] = dist;
                    distToMeanSQRD[i] = distToMean[i] * distToMean[i];
                }
                else if (numSet[i] < mean) {
                    double dist = (Convert.ToDouble(mean - numSet[i]));
                    distToMean[i] = dist;
                    distToMeanSQRD[i] = distToMean[i] * distToMean[i];

                }
                Console.WriteLine("Dist from {2} to mean = {0}, squared = {1}", distToMean[i], distToMeanSQRD[i], numSet[i]);
            }

            /* SUM THE DISTANCES and finally SQRT IT OUT BABY*/
            double sumofdistssqr = 0;
            foreach(int x in distToMeanSQRD)
            {
                sumofdistssqr += x;
            }
            double STANDARDDEVIATION = Math.Sqrt(sumofdistssqr);
            Console.WriteLine("Sum of distances squared = {0}, Standard Deviation of the Set = {1}",sumofdistssqr, STANDARDDEVIATION);

            Console.ReadKey();
        }
    }
}
