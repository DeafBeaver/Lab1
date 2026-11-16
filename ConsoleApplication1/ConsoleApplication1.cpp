#include "pch.h"

using namespace System;

void first()
{
    double L, W, C;

    Console::Write("Enter the length of the room (meters): ");
    L = Double::Parse(Console::ReadLine());

    Console::Write("Enter the width of the room (meters): ");
    W = Double::Parse(Console::ReadLine());

    Console::Write("Enter the cost per square meter (UAH): ");
    C = Double::Parse(Console::ReadLine());

    double S = L * W;
    double totalCost = S * C;

    Console::WriteLine("\nResults");
    Console::WriteLine("Room dimensions: {0:F2} m x {1:F2} m", L, W);
    Console::WriteLine("Room area: {0:F2} sq. meters", S);
    Console::WriteLine("Carpet price per sq. meter: {0:F2} UAH", C);
    Console::WriteLine("Total cost of carpet: {0:F2} UAH\n", totalCost);
}

void second()
{
    Console::Write("Enter the first string: ");
    String^ str1 = Console::ReadLine();
    Console::Write("Enter the second string: ");
    String^ str2 = Console::ReadLine();

    String^ result = str1 + str2;
    Console::WriteLine("Concatenated string: {0}\n", result);
}

void third()
{
    Console::Write("Enter the first string: ");
    String^ str1 = Console::ReadLine();
    Console::Write("Enter the second string: ");
    String^ str2 = Console::ReadLine();

    int res = String::Compare(str1, str2);
    if (res < 0)
        Console::WriteLine("First string is smaller than the second");
    else if (res > 0)
        Console::WriteLine("First string is larger than the second");
    else
        Console::WriteLine("Strings are equal");
    Console::WriteLine();
}

void four()
{
    Console::Write("Enter a string: ");
    String^ str = Console::ReadLine();

    String^ result = "begin " + str + " end";

    Console::WriteLine("Resulting string: {0}", result);
    Console::WriteLine("Length of the new string: {0} characters\n", result->Length);
}

void five()
{
    Console::Write("Enter a string to reverse: ");
    String^ str = Console::ReadLine();

    array<Char>^ charArray = str->ToCharArray();
    Array::Reverse(charArray);
    String^ reversed = gcnew String(charArray);

    Console::WriteLine("Reversed string: {0}\n", reversed);
}

void six()
{
    Console::Write("Enter the first string: ");
    String^ str1 = Console::ReadLine();
    Console::Write("Enter the second string: ");
    String^ str2 = Console::ReadLine();

    if (str1->Length > str2->Length)
        Console::WriteLine("First string is longer ({0} > {1})", str1->Length, str2->Length);
    else if (str1->Length < str2->Length)
        Console::WriteLine("Second string is longer ({0} < {1})", str2->Length, str1->Length);
    else
        Console::WriteLine("Strings are of equal length ({0} = {1})", str1->Length, str2->Length);
    Console::WriteLine();
}

int main(array<System::String^>^ args)
{
    int choice = 0;
    do
    {
        Console::WriteLine("\nMENU");
        Console::WriteLine("1. Task 1 (Calculate Carpet Price)");
        Console::WriteLine("2. Task 2 (String Concatenation)");
        Console::WriteLine("3. Task 3 (Compare Strings via Compare)");
        Console::WriteLine("4. Task 4 (Add 'begin' and 'end')");
        Console::WriteLine("5. Task 5 (Reverse String)");
        Console::WriteLine("6. Task 6 (Compare String Lengths)");
        Console::WriteLine("0. Exit");
        Console::Write("Select task number (0-6): ");

        try
        {
            choice = Convert::ToInt32(Console::ReadLine());
            Console::WriteLine();

            switch (choice)
            {
            case 1: first(); break;
            case 2: second(); break;
            case 3: third(); break;
            case 4: four(); break;
            case 5: five(); break;
            case 6: six(); break;
            case 0: Console::WriteLine("Exiting program..."); break;
            default: Console::WriteLine("Invalid choice! Try again.\n"); break;
            }
        }
        catch (Exception^)
        {
            Console::WriteLine("\nInput error! Enter a number from 0 to 6.\n");
            choice = -1;
        }

    } while (choice != 0);

    return 0;
}