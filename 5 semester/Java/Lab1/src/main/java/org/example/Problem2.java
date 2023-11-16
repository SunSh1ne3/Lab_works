package org.example;
public class Problem2 {
    public static int[] segregateEvenAndOddNumbers(int[] array) {
        for(int i = 0; i < array.length; i++)
        {
            if(array[i] % 2 == 0)
            {
                int j = i-1;
                while(j >= 0)
                {
                    if(array[j] % 2 == 1)
                    {
                        int tmp = array[j+1];
                        array[j+1] = array[j];
                        array[j] = tmp;
                        j--;
                    }
                    else
                        break;
                }
            }
        }
        return array;
    }
}
