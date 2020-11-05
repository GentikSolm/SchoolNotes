using System;

namespace Lab_6_DiceRoller
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();

            int roll = rnd.Next(2, 13);

            int[] myarray = {0,0,0,0,0,0,0,0,0,0,0};
            int timesRolled;

            Console.Write("How many times would you like to roll? ");
            timesRolled = Convert.ToInt32(Console.ReadLine());

            for(int i = 0; i < timesRolled; i++)
            {
                myarray[roll-2]++;
                roll = rnd.next(2,13);
            }
            Console.WriteLine("These are how many times each number came up: " + "\n");
            int total = 0;
            for(int i = 0; i < 11, i++){
                Console.WriteLine((i+2) + ": " + myarray[i]);
                total += myarray[i]*(i + 2);
            }
            Console.Write("\n" + "The Average roll was: ");
            double average = total / (timesRolled * 1.0);
            Console.Write(average);

            Console.ReadKey();
        }
    }
}
