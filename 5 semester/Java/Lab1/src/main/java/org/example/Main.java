package org.example;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //Problem1
            System.out.println(Problem1.containsDigitAInHexadecimalRepresentation(9) + "/n");
        //Problem2
            System.out.println(Arrays.toString(Problem2.segregateEvenAndOddNumbers(new int[]{2, 1, 5, 8, 6})) + "/n");
        //Problem3
            System.out.println(Arrays.toString(Problem3.flattenMatrix(new int[][]{{1,2,3},{4,5,6},{7,8,9}}))+"/n");
        //Problem4
            System.out.println(Problem4.isGeometricProgression("16,2,8,1,4"));

        }
    }
