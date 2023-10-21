package org.example;

public class Problem2 {
    public static int[] segregateEvenAndOddNumbers(int[] array) {
        int left=0;
        int right=array.length/2+1;
        int SortArr[]=new int[array.length];
        for(int i=0;i<array.length;i++)
        {
            if(array[i]%2==0)
            {
                SortArr[left]=array[i];
                left++;
            }
            else
            {
                SortArr[right]=array[i];
                right++;
            }
        }
        return SortArr;
    }
}
