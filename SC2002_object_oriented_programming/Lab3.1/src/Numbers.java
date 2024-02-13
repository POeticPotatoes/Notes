import java.util.Scanner;
public class Numbers
{
    // --------------------------------------------
// Reads in an array of integers, sorts them,
// then prints them in sorted order.
// --------------------------------------------
    public static void main (String[] args)
    {
        int[] intList;
        int size;
        Scanner scan = new Scanner(System.in);
        System.out.print ("\nHow many integers do you want to sort? ");
        size = scan.nextInt();
        intList = new int[size];
        System.out.println ("\nEnter the numbers...");
        for (int i = 0; i < size; i++)
            intList[i] = scan.nextInt();
        Integer integerList[] = new Integer[intList.length];
        for (int i = 0; i < intList.length; i++)
            integerList[i] = intList[i];
        Sorting.insertionSort(integerList);
        System.out.println ("\nYour numbers in sorted order...");
        for (int i = 0; i < size; i++)
            System.out.print(integerList[i] + " ");
        System.out.println ();
    }
}