package org.example;

public class Problem1 {
    public static boolean containsDigitAInHexadecimalRepresentation(int number) {
        while(number>0)
        {
            if(number%16==10)
                return true;
            else
                number/=16;
        }
        return false;
    }
}
