import java.util.Arrays;
import java.util.Scanner;
import java.util.Random;

public class Main
{
    public static void Hangman(int Misses)
    {
        if (Misses == 0)
        {
            System.out.println("    ___ ");
            System.out.println("   |   |");
            System.out.println("    --- ");
        }
        else if (Misses == 1)
        {
            System.out.println("     |  ");
        }
        else if (Misses == 2)
        {
            System.out.println("  /--|--\\");
            System.out.println(" /   |   \\");
        }
        else if (Misses == 3)
        {
            System.out.println("    _|_    ");
        }
        else if (Misses == 4)
        {
            System.out.println("   /   \\   ");
            System.out.println("  /     \\   ");
        }
    }

    public static void main(String[] args)
    {
        Scanner Scan = new Scanner(System.in);
        Random Rand = new Random();

        String[] Words = {"apple", "banana", "coconut", "pineapple", "grapes"};
        int Random_Number = Rand.nextInt(Words.length);
        String Guess_Word = Words[Random_Number];
        int Found = 0;
        int Misses = -1;
        boolean Found_Status = true;
        char Guess;

        // Used for assigning values to whole array so it does not count index[0] individually.

        int[] Found_Index = new int[Guess_Word.length()];
        Arrays.fill(Found_Index, -1);

        while(true)
        {
            System.out.print("Guess the " + Guess_Word.length() + " letter fruit (" + Found + " letters found): ");

            // Used for displaying the letters/characters guessed by the user.

            for (int i = 0; i < Guess_Word.length(); i++)
            {
                Found_Status = false;
                if (Found == 0)
                {
                    System.out.print("_");
                }
                else
                {
                    for (int j = 0; j < Found_Index.length; j++)
                    {
                        if (i == Found_Index[j])
                        {
                            System.out.print(Guess_Word.charAt(Found_Index[j]));
                            Found_Status = true;
                            break;
                        }
                    }
                    if (!Found_Status)
                    {
                        System.out.print("_");
                    }
                }
            }

            // Used for exiting the program if certain conditions are met.

            if (Found == Guess_Word.length())
            {
                System.out.println("\nYou won.");
                break;
            }

            System.out.print("\nEnter a letter: ");
            Guess = Scan.next().charAt(0);

            // Used for displaying hangman if user fails to guess any letter/character.

            for (int i = 0; i < Guess_Word.length(); i++)
            {
                Found_Status = false;
                if (Guess == Guess_Word.charAt(i))
                {
                    Found_Status = true;
                    break;
                }
            }

            if (!Found_Status)
            {
                Misses++;
            }

            if (Misses == 0)
            {
                Hangman(0);
            }
            else if (Misses == 1)
            {
                Hangman(0);
                Hangman(1);
            }
            else if (Misses == 2)
            {
                Hangman(0);
                Hangman(1);
                Hangman(2);
            }
            else if (Misses == 3)
            {
                Hangman(0);
                Hangman(1);
                Hangman(2);
                Hangman(3);
            }
            else if (Misses == 4)
            {
                Hangman(0);
                Hangman(1);
                Hangman(2);
                Hangman(3);
                Hangman(4);
            }

            // Used for exiting the program if certain conditions are met.

            if (Misses == 4)
            {
                System.out.println("You lose");
                break;
            }

            // Used for checking whether the guess word isn't being repeated.

            for (int i = 0; i < Guess_Word.length(); i++)
            {
                Found_Status = false;

                if (Guess_Word.charAt(i) == Guess)
                {
                    for (int j = 0; j < Found_Index.length; j++)
                    {
                        if (i == Found_Index[j])
                        {
                            Found_Status = true;
                            break;
                        }
                    }
                    if (!Found_Status)
                    {
                        Found++;
                        Found_Index[Found - 1] = i;
                    }
                }
            }

        }

        Scan.close();
    }
}
