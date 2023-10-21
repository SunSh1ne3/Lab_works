package org.example;

public class Problem3 {
    public static int[] flattenMatrix(int[][] matrix) {
        int Arr[]=new int[matrix.length*matrix[0].length];
        int p=0;
        for(int i=0;i<matrix.length;i++)
            for(int j=0;j<matrix[0].length;j++)
            {
                Arr[p]=matrix[j][i];
                p++;
            }
        return Arr;
    }
}
